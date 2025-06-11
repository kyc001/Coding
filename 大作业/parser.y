%require "3.8.2"
%debug
%glr-parser

%locations
%define api.pure
%define parse.error detailed
%param { yyscan_t scanner }
%parse-param { parser_mode *pm }

%code top {
    #include <stdio.h>
    #include <stdlib.h>
    #include "ast.h"
}

%code requires {
    typedef void *yyscan_t;
}

%code {
    int yylex(YYSTYPE *yylvalp, YYLTYPE *yyllocp, yyscan_t scanner);
    void yyerror(YYLTYPE *yyllocp, yyscan_t unused, parser_mode *pm, const char *msg);
}

%union {
    struct program *r; 
    int n;
    struct int_list *nl;
    char *s;
    struct term *t;
    struct named_term *nt;
    struct term_list *tl;
    struct proof *p;
    enum oper_type oper;
    void *none;
}

// Start Symbols
%token <none> START_PROGRAM START_TERM

// Basics
%token <n> NUM
%token <s> VAR

// Symbols
%token <n> COMMA COLON ELLIPSIS UNDERSCORE CARET VERTICAL_BAR QUESTION_MARK LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE

// Keywords
%token <n> GOAL PROVE CONCLUDE FWD_NOHINT BWD_NOHINT POSE_NOHINT CONCL_NOHINT USE INTROS FIX EXISTSVAR SUCH_THAT SUPPOSE SET SINCE IF THEN SAME TRANS BOTH SQUARE FOR EQU_ADD REMEMBER POSE_INDUCTION
%token <s> CUSTOMIZE

// Terms
%token <n> PLUS MINUS MULT DIV FRAC SQRT MAX MIN SUP INF DERI INTERSECTION UNION COMPOSITION MOD SUM PROD EMPTYSET LIM INFTY POS_INFTY NEG_INFTY FORALL EXISTS NOT CONJ DISJ ARROW EQUIV EQ LE GE NEQ LT GT BELONG SUBSET SUBSETNEQ BAR VEC

// FuncName
%token <oper> UNARYFUNC BINARYFUNC CARTESIANPROD

// PredName
%token <oper> UNARYPRED BINARYPRED

// Patterns
%token <n> PATTERN_VAR PATTERN_CONST PATTERN_UNARY_OPER PATTERN_BINARY_OPER PATTERN_UNARY_PRED PATTERN_BINARY_PRED PATTERN_TERMLIST

//low
%left COLON

%precedence IF_THEN
%precedence FORALL EXISTS
%precedence NOT
%right CONJ DISJ ARROW EQUIV
%left EQ NEQ GE LE GT LT
%left SUBSET SUBSETNEQ
%nonassoc BELONG
%precedence TERM_COMMA
%precedence OPER_HEAD
%left UNION INTERSECTION
%nonassoc COMPOSITION
%left PLUS MINUS
%left MULT DIV MOD
%precedence UMINUS
%precedence LPAREN
%left CARET UNDERSCORE
%precedence DERI
//high

// Nonterminals for proof
%type <none> start
%type <r> program
%type <t> goal_statement
%type <p> proof_statement
%type <p> proof partial_proof forward_clause backward_clause pose_clause pose_induction conclude_clause method_clause action_clause since_clause
%type <n> memory
%type <nl> memory_list
%type <nt> memory_term
%type <s> knowledge

// Nonterminals for term
%type <t> term lim_head oper_head interval infty
%type <tl> term_comma_list term_paren_list

%%
start: START_PROGRAM program
    {
        if (pm->debug) fprintf(stderr, "start: START_PROGRAM program\n");
        if (*(pm->pr) != NULL) {
            if (pm->debug) fprintf(stderr, "Something very wrong happends.\n");
            free(*(pm->pr));
        }
        *(pm->pr) = $2;
    }
    | START_TERM term
    {
        if (pm->debug) fprintf(stderr, "start: START_TERM term\n");
        if (*(pm->tm) != NULL) {
            if (pm->debug) fprintf(stderr, "Something very wrong happends.\n");
            free(*(pm->tm));
        }
        *(pm->tm) = $2;
    }
;

program: goal_statement proof_statement
    {
        if (pm->debug) fprintf(stderr, "program: goal_statement proof_statement\n");
        program *tmp1 = (program *) calloc(1, sizeof(program));
        proof_goal *tmp2 = (proof_goal *) calloc(1, sizeof(proof_goal));
        tmp2->assus = NULL;
        tmp2->concl = $1;
        tmp1->pg = tmp2;
        tmp1->pr = $2;
        $$ = tmp1;
    }
;

goal_statement: GOAL COLON term
    {
        if (pm->debug) fprintf(stderr, "goal_statement: GOAL COLON term\n");
        $$ = $3;
    }
;

proof_statement: PROVE COLON proof
    {
        if (pm->debug) fprintf(stderr, "proof_statement: PROVE COLON proof\n");
        $$ = $3;
    }
;

proof: forward_clause COMMA proof
    {
        if (pm->debug) fprintf(stderr, "proof: forward_clause COMMA proof\n");
        proof *tmp = $1;
        tmp->content.PoseWithoutProof.next_proof = $3;
        $$ = tmp;
    }
    | backward_clause COMMA proof
    {
        if (pm->debug) fprintf(stderr, "proof: backward_clause COMMA proof\n");
        proof *tmp = $1;
        tmp->content.ClaimSuffice.next_proof = $3;
        $$ = tmp;
    }
    | pose_clause LBRACE proof RBRACE proof
    {
        if (pm->debug) fprintf(stderr, "proof: pose_clause LBRACE proof RBRACE proof\n");
        proof *tmp = $1;
        tmp->content.PoseAndProve.curr_proof = $3;
        tmp->content.PoseAndProve.next_proof = $5;
        $$ = tmp;
    }
    | pose_induction LBRACE proof RBRACE proof
    {
        if (pm->debug) fprintf(stderr, "proof: pose_clause LBRACE proof RBRACE proof\n");
        proof *tmp = $1;
        tmp->content.PoseInduction.curr_proof = $3;
        tmp->content.PoseInduction.next_proof = $5;
        $$ = tmp;
    }
    | CONCLUDE
    {
        if (pm->debug) fprintf(stderr, "proof: CONCLUDE\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = FNoHint;
        tmp1->type = ConclWithoutProof;
        tmp1->content.ConclWithoutProof.fwd = tmp2;
        $$ = tmp1;
    }
    | conclude_clause COMMA CONCLUDE
    {
        if (pm->debug) fprintf(stderr, "proof: conclude_clause COMMA CONCLUDE\n");
        proof *tmp = $1;
        $$ = tmp;
    }
    | method_clause COMMA proof
    {
        if (pm->debug) fprintf(stderr, "proof: method_clause COMMA proof\n");
        proof *tmp = $1;
        tmp->content.ConclAndProve.curr_proof = $3;
        $$ = tmp;
    }
    | action_clause COMMA proof
    {
        if (pm->debug) fprintf(stderr, "proof: action_clause COMMA proof\n");
        proof *tmp = $1;
        tmp->content.Action.next_proof = $3;
        $$ = tmp;
    }
    | action_clause LBRACE partial_proof RBRACE proof
    {
        if (pm->debug) fprintf(stderr, "proof: action_clause LBRACE partial_proof RBRACE proof\n");
        proof *tmp = (proof *) calloc(1, sizeof(proof));
        tmp->type = PosePartialProof;
        tmp->content.PosePartialProof.act = $1->content.Action.act;
        tmp->content.PosePartialProof.curr_proof = $3;
        tmp->content.PosePartialProof.next_proof = $5;
        free($1);
        $$ = tmp;
    }
;

partial_proof: %empty
    {
        if (pm->debug) fprintf(stderr, "partial_proof: %%empty\n");
        proof *tmp = (proof *) calloc(1, sizeof(proof));
        tmp->type = EndPartialProof;
        $$ = tmp;
    }
    | forward_clause COMMA partial_proof
    {
        if (pm->debug) fprintf(stderr, "partial_proof: forward_clause COMMA partial_proof\n");
        proof *tmp = $1;
        tmp->content.PoseWithoutProof.next_proof = $3;
        $$ = tmp;
    }
    | pose_clause LBRACE proof RBRACE partial_proof
    {
        if (pm->debug) fprintf(stderr, "partial_proof: pose_clause LBRACE proof RBRACE partial_proof\n");
        proof *tmp = $1;
        tmp->content.PoseAndProve.curr_proof = $3;
        tmp->content.PoseAndProve.next_proof = $5;
        $$ = tmp;
    }
    | action_clause COMMA partial_proof
    {
        if (pm->debug) fprintf(stderr, "partial_proof: action_clause COMMA partial_proof\n");
        proof *tmp = $1;
        tmp->content.Action.next_proof = $3;
        $$ = tmp;
    }
    | action_clause LBRACE partial_proof RBRACE partial_proof
    {
        if (pm->debug) fprintf(stderr, "partial_proof: action_clause LBRACE partial_proof RBRACE partial_proof\n");
        proof *tmp = (proof *) calloc(1, sizeof(proof));
        tmp->type = PosePartialProof;
        tmp->content.PosePartialProof.act = $1->content.Action.act;
        tmp->content.PosePartialProof.curr_proof = $3;
        tmp->content.PosePartialProof.next_proof = $5;
        free($1);
        $$ = tmp;
    }
;

forward_clause: FWD_NOHINT memory_term
    {
        if (pm->debug) fprintf(stderr, "forward_clause: FWD_NOHINT memory_term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = FNoHint;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = $2->t;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        tmp1->remember = $2->name;
        free($2);
        $$ = tmp1;
    }
    | since_clause THEN memory_term
    {
        if (pm->debug) fprintf(stderr, "forward_clause: since_clause THEN memory_term\n");
        proof *tmp = $1;
        tmp->content.PoseWithoutProof.curr_term = $3->t;
        tmp->remember = $3->name;
        free($3);
        $$ = tmp;
    }
;

backward_clause: BWD_NOHINT term
    {
        if (pm->debug) fprintf(stderr, "backward_clause: BWD_NOHINT term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        backward *tmp2 = (backward *) calloc(1, sizeof(backward));
        tmp2->type = BNoHint;
        tmp1->type = ClaimSuffice;
        tmp1->content.ClaimSuffice.bwd = tmp2;
        tmp1->content.ClaimSuffice.curr_term = $2;
        tmp1->content.ClaimSuffice.next_proof = NULL;
        $$ = tmp1;
    }
;

pose_clause: POSE_NOHINT memory_term
    {
        if (pm->debug) fprintf(stderr, "pose_clause: POSE_NOHINT memory_term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = FNoHint;
        tmp1->type = PoseAndProve;
        tmp1->content.PoseAndProve.fwd = tmp2;
        tmp1->content.PoseAndProve.curr_term = $2->t;
        tmp1->content.PoseAndProve.curr_proof = NULL;
        tmp1->content.PoseAndProve.next_proof = NULL;
        tmp1->remember = $2->name;
        free($2);
        $$ = tmp1;
    }
    | method_clause memory_term
    {
        if (pm->debug) fprintf(stderr, "pose_clause: method_clause memory_term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        proof *tmp2 = $1;
        tmp1->type = PoseAndProve;
        tmp1->content.PoseAndProve.fwd = tmp2->content.ConclAndProve.fwd;
        tmp1->content.PoseAndProve.curr_term = $2->t;
        tmp1->content.PoseAndProve.curr_proof = NULL;
        tmp1->content.PoseAndProve.next_proof = NULL;
        tmp1->remember = $2->name;
        free($2);
        free(tmp2);
        $$ = tmp1;
    }
;

pose_induction: FOR VAR POSE_INDUCTION memory_term
    {
        if (pm->debug) fprintf(stderr, "pose_induction: FOR VAR POSE_INDUCTION memory_term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = FNoHint;
        tmp1->type = PoseInduction;
        tmp1->content.PoseInduction.fwd = tmp2;
        tmp1->content.PoseInduction.induct_var = $2;
        tmp1->content.PoseInduction.curr_term = $4->t;
        tmp1->content.PoseInduction.curr_proof = NULL;
        tmp1->content.PoseInduction.next_proof = NULL;
        tmp1->remember = $4->name;
        $$ = tmp1;
    }
;

conclude_clause: CONCL_NOHINT
    {
        if (pm->debug) fprintf(stderr, "conclude_clause: CONCL_NOHINT\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = FNoHint;
        tmp1->type = ConclWithoutProof;
        tmp1->content.ConclWithoutProof.fwd = tmp2;
        $$ = tmp1;
    }
    | since_clause
    {
        if (pm->debug) fprintf(stderr, "conclude_clause: since_clause\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        proof *tmp2 = $1;
        tmp1->type = ConclWithoutProof;
        tmp1->content.ConclWithoutProof.fwd = tmp2->content.PoseWithoutProof.fwd;
        free(tmp2);
        $$ = tmp1;
    }
;

method_clause: USE knowledge PROVE
    {
        if (pm->debug) fprintf(stderr, "method_clause: USE knowledge PROVE\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = Knowledge;
        tmp2->content.knowledge = $2;
        tmp1->type = ConclAndProve;
        tmp1->content.ConclAndProve.fwd = tmp2;
        tmp1->content.ConclAndProve.curr_proof = NULL;
        $$ = tmp1;
    }
;

action_clause: INTROS term
    {
        if (pm->debug) fprintf(stderr, "action_clause: INTROS term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action));
        tmp2->type = IntroTerm;
        tmp2->content.intro_term = $2;
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        $$ = tmp1;
    }
    | INTROS term_comma_list
    {
        if (pm->debug) fprintf(stderr, "action_clause: INTROS term_comma_list\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = $2;
        tmp2->type = IntroTerm;
        tmp2->content.intro_term = tmp3;
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        $$ = tmp1;
    }
    | EXISTSVAR VAR
    {
        if (pm->debug) fprintf(stderr, "action_clause: EXISTSVAR VAR\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action));
        tmp2->type = ExistsVar;
        tmp2->content.exists_var = $2;
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        $$ = tmp1;
    }
    | FIX term SUCH_THAT term
    {
        if (pm->debug) fprintf(stderr, "action_clause: FIX term SUCH_THAT term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action)); 
        tmp2->type = IntroTermWithProp;
        tmp2->content.intro_term_with_prop[0] = $2;
        tmp2->content.intro_term_with_prop[1] = $4;
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        $$ = tmp1;
    }
    | FIX term_comma_list SUCH_THAT term
    {
        if (pm->debug) fprintf(stderr, "action_clause: FIX term_comma_list SUCH_THAT term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action)); 
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = $2;
        tmp2->type = IntroTermWithProp;
        tmp2->content.intro_term_with_prop[0] = tmp3;
        tmp2->content.intro_term_with_prop[1] = $4;
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        $$ = tmp1;
    }
    | SUPPOSE term
    {
        if (pm->debug) fprintf(stderr, "action_clause: SUPPOSE term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action));
        tmp2->type = Suppose;
        tmp2->content.suppose_term = $2;
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        $$ = tmp1;
    }
    | SET term
    {
        if (pm->debug) fprintf(stderr, "action_clause: SET term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        action *tmp2 = (action *) calloc(1, sizeof(action));
        tmp2->type = Set;
        tmp2->content.set_term = $2;
        tmp1->type = Action;
        tmp1->content.Action.act = tmp2;
        tmp1->content.Action.next_proof = NULL;
        $$ = tmp1;
    }
;

since_clause: SINCE knowledge
    {
        if (pm->debug) fprintf(stderr, "since_clause: SINCE knowledge\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = Knowledge;
        tmp2->content.knowledge = $2;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        $$ = tmp1;
    }
    | SINCE term
    {
        if (pm->debug) fprintf(stderr, "since_clause: SINCE term\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = Inference;
        tmp2->content.evidence = $2;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        $$ = tmp1;
    }
    | SINCE memory
    {
        if (pm->debug) fprintf(stderr, "since_clause: SINCE memory\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = Inference;
        tmp2->content.equ = $2;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        $$ = tmp1;
    }
    | SAME
    {
        if (pm->debug) fprintf(stderr, "since_clause: SAME\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = Same;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        $$ = tmp1;
    }
    | SINCE memory TRANS
    {
        if (pm->debug) fprintf(stderr, "since_clause: SINCE memory TRANS\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = EquTrans;
        tmp2->content.equ = $2;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        $$ = tmp1;
    }
    | BOTH SQUARE
    {
        if (pm->debug) fprintf(stderr, "since_clause: BOTH SQUARE\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = SquareBothTerms;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        $$ = tmp1;
    }
    | BOTH DERI
    {
        if (pm->debug) fprintf(stderr, "since_clause: BOTH DERI\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = DeriBothTerms;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        $$ = tmp1;
    }
    | BOTH FOR VAR DERI
    {
        if (pm->debug) fprintf(stderr, "since_clause: BOTH FOR VAR DERI\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = DeriBothTerms;
        tmp2->content.var = $3;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        $$ = tmp1;
    }
    | memory_list EQU_ADD
    {
        if (pm->debug) fprintf(stderr, "since_clause: memory_list EQU_ADD\n");
        proof *tmp1 = (proof *) calloc(1, sizeof(proof));
        forward *tmp2 = (forward *) calloc(1, sizeof(forward));
        tmp2->type = AddEqn;
        tmp2->content.equ_list = $1;
        tmp1->type = PoseWithoutProof;
        tmp1->content.PoseWithoutProof.fwd = tmp2;
        tmp1->content.PoseWithoutProof.curr_term = NULL;
        tmp1->content.PoseWithoutProof.next_proof = NULL;
        $$ = tmp1;
    }
;

memory_list: memory
    {
        if (pm->debug) fprintf(stderr, "memory_list: memory\n");
        int_list *tmp = (int_list *) calloc(1, sizeof(int_list));
        tmp->element = $1;
        tmp->next = NULL;
        $$ = tmp;
    }
    | memory memory_list
    {
        if (pm->debug) fprintf(stderr, "memory_list: memory memory_list\n");
        int_list *tmp = (int_list *) calloc(1, sizeof(int_list));
        tmp->element = $1;
        tmp->next = $2;
        $$ = tmp;
    }
;

memory_term: term
    {
        if (pm->debug) fprintf(stderr, "memory_term: term\n");
        named_term *tmp = (named_term *) calloc(1, sizeof(named_term));
        tmp->name = NULL;
        tmp->t = $1;
        $$ = tmp;
    }
    | term REMEMBER memory
    {
        if (pm->debug) fprintf(stderr, "memory_term: term REMEMBER memory\n");
        named_term *tmp = (named_term *) calloc(1, sizeof(named_term));
        tmp->name = (int *) calloc(1, sizeof(int));
        *(tmp->name) = $3;
        tmp->t = $1;
        $$ = tmp;
    }
;

knowledge: CUSTOMIZE
    {
        if (pm->debug) fprintf(stderr, "knowledge: CUSTOMIZE\n");
        $$ = $1;
    }
;

memory: LBRACKET NUM RBRACKET
    {
        if (pm->debug) fprintf(stderr, "memory: LBRACKET NUM RBRACKET\n");
        $$ = $2;
    }
;

term: QUESTION_MARK
    {
        if (pm->debug) fprintf(stderr, "term: QUESTION_MARK\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Pattern;
        tmp->content.Pattern = PatternWildCard;
        $$ = tmp;
    }
    | PATTERN_VAR
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_VAR\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Pattern;
        tmp->content.Pattern = PatternVar;
        $$ = tmp;
    }
    | PATTERN_CONST
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_CONST\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Pattern;
        tmp->content.Pattern = PatternConst;
        $$ = tmp;
    }
    | PATTERN_UNARY_OPER LPAREN term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_UNARY_OPER LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Pattern;
        tmp2->content.Pattern = PatternOper;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | PATTERN_BINARY_OPER LPAREN term_comma_list RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_BINARY_OPER LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pattern;
        tmp3->content.Pattern = PatternOper;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = ($3)->element;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = ($3)->next->element;
        $$ = tmp1;
    }
    | PATTERN_UNARY_PRED LPAREN term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_UNARY_PRED LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Pattern;
        tmp2->content.Pattern = PatternPred;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | PATTERN_BINARY_PRED LPAREN term_comma_list RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_BINARY_PRED LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pattern;
        tmp3->content.Pattern = PatternPred;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = ($3)->element;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = ($3)->next->element;
        $$ = tmp1;
    }
    | PATTERN_TERMLIST
    {
        if (pm->debug) fprintf(stderr, "term: PATTERN_TERMLIST\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Pattern;
        tmp->content.Pattern = PatternTermList;
        $$ = tmp;
    }
    | UNDERSCORE
    {
        if (pm->debug) fprintf(stderr, "term: UNDERSCORE\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Pattern;
        tmp->content.Pattern = PatternIgnore;
        $$ = tmp;
    }
    | VAR
    {
        if (pm->debug) fprintf(stderr, "term: VAR(\"%s\")\n", $1);
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Var;
        tmp->content.Var = $1;
        $$ = tmp;
    }
    | NUM
    {
        if (pm->debug) fprintf(stderr, "term: NUM\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Const;
        tmp->content.Const.type = Num;
        tmp->content.Const.content = $1;
        $$ = tmp;
    }
    | LPAREN term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: LPAREN term RPAREN\n");
        $$ = $2;
    }
    | term LPAREN term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: term LPAREN term RPAREN\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Apply;
        tmp->content.Apply.left = $1;
        tmp->content.Apply.right = $3;
        $$ = tmp;
    }
    | term LPAREN term_comma_list RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: term LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = TermList;
        tmp2->content.TermList = $3;
        tmp1->type = Apply;
        tmp1->content.Apply.left = $1;
        tmp1->content.Apply.right = tmp2;
        $$ = tmp1;
    }
    | term PLUS term
    {
        if (pm->debug) fprintf(stderr, "term: term PLUS term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Plus;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | MINUS term %prec UMINUS
    {
        if (pm->debug) fprintf(stderr, "term: MINUS term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Neg;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $2;
        $$ = tmp1;
    }
    | term MINUS term
    {
        if (pm->debug) fprintf(stderr, "term: term MINUS term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Minus;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term MULT term
    {
        if (pm->debug) fprintf(stderr, "term: term MULT term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Mult;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term DIV term
    {
        if (pm->debug) fprintf(stderr, "term: term DIV term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Div;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term CARET term
    {
        if (pm->debug) fprintf(stderr, "term: term CARET term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Power;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term UNDERSCORE term
    {
        if (pm->debug) fprintf(stderr, "term: term UNDERSCORE term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Index;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | VERTICAL_BAR term VERTICAL_BAR
    {
        if (pm->debug) fprintf(stderr, "term: VERTICAL_BAR term VERTICAL_BAR\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Abs;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $2;
        $$ = tmp1;
    }
    | FRAC LPAREN term COMMA term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: FRAC LPAREN term COMMA term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Div;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $3;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $5;
        $$ = tmp1;
    }
    | SQRT LPAREN term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: SQRT LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Sqrt;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | SQRT LPAREN term COMMA term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: SQRT LPAREN term COMMA term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Sqrt_n;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $3;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $5;
        $$ = tmp1;
    }
    | UNARYFUNC LPAREN term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: UNARYFUNC LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | BINARYFUNC LPAREN term_comma_list RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: BINARYFUNC LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = $1;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = ($3)->element;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = ($3)->next->element;
        $$ = tmp1;
    }
    | UNARYPRED LPAREN term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: UNARYPRED LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Pred;
        tmp2->content.Pred = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | BINARYPRED LPAREN term_comma_list RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: BINARYPRED LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = $1;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = ($3)->element;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = ($3)->next->element;
        $$ = tmp1;
    }
    | MAX LPAREN term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: MAX LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Max;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | MAX LPAREN term_comma_list RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: MAX LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = $3;
        tmp2->type = Oper;
        tmp2->content.Oper = Max;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = tmp3;
        $$ = tmp1;
    }
    | MIN LPAREN term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: MIN LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Min;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | MIN LPAREN term_comma_list RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: MIN LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = $3;
        tmp2->type = Oper;
        tmp2->content.Oper = Min;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = tmp3;
        $$ = tmp1;
    }
    | SUP LPAREN term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: SUP LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Sup;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | INF LPAREN term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: INF LPAREN term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Inf;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term DERI
    {
        if (pm->debug) fprintf(stderr, "term: term DERI\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Deri;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $1;
        $$ = tmp1;
    }
    | lim_head LPAREN term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: lim_head LPAREN term RPAREN\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Apply;
        tmp->content.Apply.left = $1;
        tmp->content.Apply.right = $3;
        $$ = tmp;
    }
    | interval
    {
        if (pm->debug) fprintf(stderr, "term: interval\n");
        $$ = $1;
    }
    | infty
    {
        if (pm->debug) fprintf(stderr, "term: infty\n");
        $$ = $1;
    }
    | EMPTYSET
    {
        if (pm->debug) fprintf(stderr, "term: EMPTYSET\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Const;
        tmp->content.Const.type = EmptySet;
        $$ = tmp;
    }
    | term UNION term
    {
        if (pm->debug) fprintf(stderr, "term: term UNION term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = SetUnion;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term INTERSECTION term
    {
        if (pm->debug) fprintf(stderr, "term: term INTERSECTION term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = SetIntersection;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term COMPOSITION term
    {
        if (pm->debug) fprintf(stderr, "term: term COMPOSITION term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Composition;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | LBRACE term RBRACE
    {
        if (pm->debug) fprintf(stderr, "term: LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term_list *tmp4 = (term_list *) calloc(1, sizeof(term_list));
        tmp4->element = $2;
        tmp4->next = NULL;
        tmp3->type = TermList;
        tmp3->content.TermList = tmp4;
        tmp2->type = Oper;
        tmp2->content.Oper = Set_enum;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = tmp3;
        $$ = tmp1;
    }
    | LBRACE term_comma_list RBRACE
    {
        if (pm->debug) fprintf(stderr, "term: LBRACE term_comma_list RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = $2;
        tmp2->type = Oper;
        tmp2->content.Oper = Set_enum;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = tmp3;
        $$ = tmp1;
    }
    | LBRACE term VERTICAL_BAR term RBRACE
    {
        if (pm->debug) fprintf(stderr, "term: LBRACE term VERTICAL_BAR term RBRACE\n");
        term *tmp0 = (term *) calloc(1, sizeof(term));
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term_list *tmp4 = (term_list *) calloc(1, sizeof(term_list));
        tmp4->element = $4;
        tmp4->next = NULL;
        tmp3->type = TermList;
        tmp3->content.TermList = tmp4;
        tmp2->type = Oper;
        tmp2->content.Oper = Set_build;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $2;
        tmp0->type = Apply;
        tmp0->content.Apply.left = tmp1;
        tmp0->content.Apply.right = tmp3;
        $$ = tmp0;
    }
    | LBRACE term VERTICAL_BAR term_comma_list RBRACE
    {
        if (pm->debug) fprintf(stderr, "term: LBRACE term VERTICAL_BAR term_comma_list RBRACE\n");
        term *tmp0 = (term *) calloc(1, sizeof(term));
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = $4;
        tmp2->type = Oper;
        tmp2->content.Oper = Set_build;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $2;
        tmp0->type = Apply;
        tmp0->content.Apply.left = tmp1;
        tmp0->content.Apply.right = tmp3;
        $$ = tmp0;
    }
    | BAR LBRACE term RBRACE
    {
        if (pm->debug) fprintf(stderr, "term: BAR LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Bar;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | VEC LBRACE term RBRACE
    {
        if (pm->debug) fprintf(stderr, "term: VEC LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = Vec;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term MOD term
    {
        if (pm->debug) fprintf(stderr, "term: term MOD term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Mod;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term COLON term
    {
        if (pm->debug) fprintf(stderr, "term: term COLON term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Colon;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | ELLIPSIS
    {
        if (pm->debug) fprintf(stderr, "term: ELLIPSIS\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Const;
        tmp->content.Const.type = Ellipsis;
        $$ = tmp;
    }
    | LPAREN term_comma_list RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = $2;
        tmp2->type = Oper;
        tmp2->content.Oper = Tuple;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = tmp3;
        $$ = tmp1;
    }
    | CARTESIANPROD LPAREN term_comma_list RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: CARTESIANPROD LPAREN term_comma_list RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = TermList;
        tmp3->content.TermList = $3;
        tmp2->type = Oper;
        tmp2->content.Oper = CartesianProd;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = tmp3;
        $$ = tmp1;
    }
    | oper_head term %prec OPER_HEAD
    {
        if (pm->debug) fprintf(stderr, "term: oper_head term\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Apply;
        tmp->content.Apply.left = $1;
        tmp->content.Apply.right = $2;
        $$ = tmp;
    }
    | term EQ term
    {
        if (pm->debug) fprintf(stderr, "term: term EQ term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Eq;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term NEQ term
    {
        if (pm->debug) fprintf(stderr, "term: term NEQ term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Neq;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term GE term
    {
        if (pm->debug) fprintf(stderr, "term: term GE term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Ge;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term LE term
    {
        if (pm->debug) fprintf(stderr, "term: term LE term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Le;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term GT term
    {
        if (pm->debug) fprintf(stderr, "term: term GT term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Gt;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term LT term
    {
        if (pm->debug) fprintf(stderr, "term: term LT term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Lt;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | FORALL term_paren_list COMMA term %prec FORALL
    {
        if (pm->debug) fprintf(stderr, "term: FORALL term_paren_list COMMA term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = TermList;
        tmp2->content.TermList = $2;
        tmp1->type = RawQuant;
        tmp1->content.RawQuant.type = Forall;
        tmp1->content.RawQuant.raw_var = tmp2;
        tmp1->content.RawQuant.body = $4;
        $$ = tmp1;
    }
    | EXISTS term_paren_list COMMA term %prec EXISTS
    {
        if (pm->debug) fprintf(stderr, "term: EXISTS term_paren_list COMMA term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = TermList;
        tmp2->content.TermList = $2;
        tmp1->type = RawQuant;
        tmp1->content.RawQuant.type = Exists;
        tmp1->content.RawQuant.raw_var = tmp2;
        tmp1->content.RawQuant.body = $4;
        $$ = tmp1;
    }
    | NOT term
    {
        if (pm->debug) fprintf(stderr, "term: NOT term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Connect;
        tmp2->content.Connect = Not;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $2;
        $$ = tmp1;
    }
    | term CONJ term
    {
        if (pm->debug) fprintf(stderr, "term: term CONJ term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Connect;
        tmp3->content.Connect = And;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term DISJ term
    {
        if (pm->debug) fprintf(stderr, "term: term DISJ term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Connect;
        tmp3->content.Connect = Or;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term ARROW term
    {
        if (pm->debug) fprintf(stderr, "term: term ARROW term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Connect;
        tmp3->content.Connect = Impl;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term EQUIV term
    {
        if (pm->debug) fprintf(stderr, "term: term EQUIV term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Connect;
        tmp3->content.Connect = Iff;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | IF term_paren_list COMMA THEN term %prec IF_THEN
    {
        if (pm->debug) fprintf(stderr, "term: IF term_paren_list COMMA THEN term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term *tmp4 = (term *) calloc(1, sizeof(term));
        tmp4->type = TermList;
        tmp4->content.TermList = $2;
        tmp3->type = Connect;
        tmp3->content.Connect = Impl;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = tmp4;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $5;
        $$ = tmp1;
    }
    | term BELONG term
    {
        if (pm->debug) fprintf(stderr, "term: term BELONG term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Belong;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term_comma_list BELONG term
    {
        if (pm->debug) fprintf(stderr, "term: term_comma_list BELONG term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term *tmp4 = (term *) calloc(1, sizeof(term));
        tmp4->type = TermList;
        tmp4->content.TermList = $1;
        tmp3->type = Pred;
        tmp3->content.Pred = Belong;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = tmp4;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term SUBSET term
    {
        if (pm->debug) fprintf(stderr, "term: term SUBSET term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = Subset;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term_comma_list SUBSET term
    {
        if (pm->debug) fprintf(stderr, "term: term_comma_list SUBSET term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term *tmp4 = (term *) calloc(1, sizeof(term));
        tmp4->type = TermList;
        tmp4->content.TermList = $1;
        tmp3->type = Pred;
        tmp3->content.Pred = Subset;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = tmp4;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term SUBSETNEQ term
    {
        if (pm->debug) fprintf(stderr, "term: term SUBSETNEQ term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Pred;
        tmp3->content.Pred = SubsetNeq;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $1;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
    | term_comma_list SUBSETNEQ term
    {
        if (pm->debug) fprintf(stderr, "term: term_comma_list SUBSETNEQ term\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term *tmp4 = (term *) calloc(1, sizeof(term));
        tmp4->type = TermList;
        tmp4->content.TermList = $1;
        tmp3->type = Pred;
        tmp3->content.Pred = SubsetNeq;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = tmp4;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $3;
        $$ = tmp1;
    }
;

lim_head: LIM UNDERSCORE LBRACE VAR ARROW term RBRACE
   {
        if (pm->debug) fprintf(stderr, "lim_head: LIM UNDERSCORE LBRACE VAR ARROW term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        term *tmp4 = (term *) calloc(1, sizeof(term));
        tmp4->type = Oper;
        tmp4->content.Oper = Lim;
        tmp3->type = Var;
        tmp3->content.Var = $4;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp4;
        tmp2->content.Apply.right = tmp3;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $6;
        $$ = tmp1;
   }
;

oper_head: SUM UNDERSCORE LBRACE term RBRACE CARET LBRACE term RBRACE
    {
        if (pm->debug) fprintf(stderr, "oper_head: SUM UNDERSCORE LBRACE term RBRACE CARET LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = BigSum_limits;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $4;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $8;
        $$ = tmp1;
    }
    | PROD UNDERSCORE LBRACE term RBRACE CARET LBRACE term RBRACE
    {
        if (pm->debug) fprintf(stderr, "oper_head: PROD UNDERSCORE LBRACE term RBRACE CARET LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = BigProd_limits;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $4;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $8;
        $$ = tmp1;
    }
    | PROD UNDERSCORE LBRACE term RBRACE CARET LBRACE term RBRACE
    {
        if (pm->debug) fprintf(stderr, "oper_head: PROD UNDERSCORE LBRACE term RBRACE CARET LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = BigProd_limits;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $4;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $8;
        $$ = tmp1;
    }
    | SUM UNDERSCORE LBRACE term RBRACE
    {
        if (pm->debug) fprintf(stderr, "oper_head: SUM UNDERSCORE LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = BigSum_only_index;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $4;
        $$ = tmp1;
    }
    | PROD UNDERSCORE LBRACE term RBRACE
    {
        if (pm->debug) fprintf(stderr, "oper_head: PROD UNDERSCORE LBRACE term RBRACE\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        tmp2->type = Oper;
        tmp2->content.Oper = BigProd_only_index;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $4;
        $$ = tmp1;
    }
;

interval: LBRACKET term COMMA term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term: LBRACKET term COMMA term RPAREN\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Interval_lclosed_ropen;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $2;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $4;
        $$ = tmp1;
    }
    | LPAREN term COMMA term RBRACKET
    {
        if (pm->debug) fprintf(stderr, "term: LPAREN term COMMA term RBRACKET\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Interval_lopen_rclosed;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $2;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $4;
        $$ = tmp1;
    }
    | LBRACKET term COMMA term RBRACKET
    {
        if (pm->debug) fprintf(stderr, "term: LBRACKET term COMMA term RBRACKET\n");
        term *tmp1 = (term *) calloc(1, sizeof(term));
        term *tmp2 = (term *) calloc(1, sizeof(term));
        term *tmp3 = (term *) calloc(1, sizeof(term));
        tmp3->type = Oper;
        tmp3->content.Oper = Interval_lclosed_rclosed;
        tmp2->type = Apply;
        tmp2->content.Apply.left = tmp3;
        tmp2->content.Apply.right = $2;
        tmp1->type = Apply;
        tmp1->content.Apply.left = tmp2;
        tmp1->content.Apply.right = $4;
        $$ = tmp1;
    }
;

infty: INFTY
    {
        if (pm->debug) fprintf(stderr, "infty: INFTY\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Const;
        tmp->content.Const.type = Infty;
        $$ = tmp;
    }
    | POS_INFTY
    {
        if (pm->debug) fprintf(stderr, "infty: POS_INFTY\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Const;
        tmp->content.Const.type = Pos_Infty;
        $$ = tmp;
    }
    | NEG_INFTY
    {
        if (pm->debug) fprintf(stderr, "infty: POS_INFTY\n");
        term *tmp = (term *) calloc(1, sizeof(term));
        tmp->type = Const;
        tmp->content.Const.type = Neg_Infty;
        $$ = tmp;
    }
;

term_comma_list: term COMMA term %prec TERM_COMMA
    {
        if (pm->debug) fprintf(stderr, "term_comma_list: term COMMA term\n");
        term_list *tmp1 = (term_list *) calloc(1, sizeof(term_list));
        term_list *tmp2 = (term_list *) calloc(1, sizeof(term_list));
        tmp1->element = $1;
        tmp1->next = tmp2;
        tmp2->element = $3;
        tmp2->next = NULL;
        $$ = tmp1;
    }
    | term COMMA term_comma_list %prec TERM_COMMA
    {
        if (pm->debug) fprintf(stderr, "term_comma_list: term COMMA term_comma_list\n");
        term_list *tmp = (term_list *) malloc(sizeof(term_list));
        tmp->element = $1;
        tmp->next = $3;
        $$ = tmp;
        
        /* term_list *tmp = $1;
        while (tmp->next != NULL) tmp = tmp->next;
        tmp.next = (term_list *) malloc(sizeof(term_list));
        tmp.next->element = $3;
        tmp.next->next = NULL;
        $$ = $1; */
    }
;

term_paren_list: LPAREN term RPAREN
    {
        if (pm->debug) fprintf(stderr, "term_paren_list: LPAREN term RPAREN\n");
        term_list *tmp = (term_list *) calloc(1, sizeof(term_list));
        tmp->element = $2;
        tmp->next = NULL;
        $$ = tmp;
    }
    | LPAREN term RPAREN term_paren_list
    {
        if (pm->debug) fprintf(stderr, "term_paren_list: LPAREN term RPAREN term_paren_list\n");
        term_list *tmp = (term_list *) calloc(1, sizeof(term_list));
        tmp->element = $2;
        tmp->next = $4;
        $$ = tmp;
    }
;

%%

void yyerror(YYLTYPE *yyllocp, yyscan_t unused, parser_mode *pm, const char *msg) {
    if (pm->from_string) {
        char *tmp = malloc((yyllocp->last_column - yyllocp->first_column + 2) * sizeof(char));
        strncpy(tmp, pm->data + yyllocp->first_column, (yyllocp->last_column - yyllocp->first_column + 1));
        fprintf(stderr, "\n%s: %s.\n", tmp, msg);
        
        FILE *msg_file = fopen("error_msg.txt", "w");
        fprintf(msg_file, "-1");
        fclose(msg_file);

        free(tmp);
    }
    else{
        fprintf(stderr, "\n%s:%d.%d-%d.%d: %s.\n", pm->data,
        yyllocp->first_line, yyllocp->first_column, yyllocp->last_line, yyllocp->last_column, msg);

        FILE *msg_file = fopen("error_msg.txt", "w");
        fprintf(msg_file, "%d",yyllocp->first_line);
        fclose(msg_file);
    } 
}
