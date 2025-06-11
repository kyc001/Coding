%option warn debug yylineno noyywrap
%option reentrant bison-bridge bison-locations
%option header-file="lexer.h"
%option outfile="lexer.c"
%option extra-type="lexer_mode *"

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "ast.h"
    #include "parser.h"

    #define YY_USER_ACTION                                                 \
        yylloc->first_line = yylloc->last_line;                            \
        yylloc->first_column = yylloc->last_column;                        \
        if (yylloc->last_line == yylineno)                                 \
        yylloc->last_column += yyleng;                                     \
        else {                                                             \
            yylloc->last_line = yylineno;                                  \
            yylloc->last_column = yytext + yyleng - strrchr(yytext, '\n'); \
        }
    
    /*
        We need to declare parser_mode here because flex won't include the header file "ast.h" in lexer.h.
    */
    struct parser_mode;
%}

%%

%{
    if (yyextra->start_token) {
        int y = yyextra->start_token;
        yyextra->start_token = 0;
        return y;
    }
%}

"Goal"|"要证" {
    yylval->n = yylineno;
    return GOAL;
}

"Proof"|"证明" {
    yylval->n = yylineno;
    return PROVE;
}

"证毕"[。.]*|"原命题得证"[。.]* {
    yylval->n = yylineno;
    return CONCLUDE;
}

"假设"|"设" {
    yylval->n = yylineno;
    return SUPPOSE;
}

"由"|"根据"|"因为" {
    yylval->n = yylineno;
    return SINCE;
}

"变形"|"等价变形" {
    yylval->n = yylineno;
    return TRANS;
}

"使用" {
    yylval->n = yylineno;
    return USE;
}

"同理"|"同理可得"|"以此类推" {
    yylval->n = yylineno;
    return SAME;
}

"那么"|"则"|"so"|"then"|"thus"|"得"|"可知"|"可证"|"可得"|"所以" {
    yylval->n = yylineno;
    return THEN;
}

"取" {
    yylval->n = yylineno;
    return INTROS;
}

"对于任意" {
    yylval->n = yylineno;
    return FIX;
}

"令" {
    yylval->n = yylineno;
    return SET;    
}

"给定" {
    yylval->n = yylineno;
    return EXISTSVAR;    
}

"满足"|"使得" {
    yylval->n = yylineno;
    return SUCH_THAT;
}

"等式两边同时" {
    yylval->n = yylineno;
    return BOTH;
}

"用归纳法证明" {
    yylval->n = yylineno;
    return POSE_INDUCTION;
}

"求导" {
    yylval->n = yylineno;
    return DERI;
}

"平方" {
    yylval->n = yylineno;
    return SQUARE;
}

"对" {
    yylval->n = yylineno;
    return FOR;
}

"if"|"如果" {
    yylval->n = yylineno;
    return IF;
}

"下面证明" {
    yylval->n = yylineno;
    return POSE_NOHINT;
}

"记作" {
    yylval->n = yylineno;
    return REMEMBER;
}

"式相加" {
    yylval->n = yylineno;
    return EQU_ADD;
}

"综上可知" {
    yylval->n = yylineno;
    return CONCL_NOHINT;
}

"易知"|"自然"|"自然可知"|"因此"|"我们有"|"显然有"|"同样地"|"我们知道" {
    yylval->n = yylineno;
    return FWD_NOHINT;
}

"即证"|"只需证" {
    yylval->n = yylineno;
    return BWD_NOHINT;
}

\"([^\\"]|\\.)*\" {
    char *tmp = (char *) calloc(1, (yyleng + 1) * sizeof(char));
    for(int i = 0; i < yyleng - 2; i++){
        tmp[i] = yytext[i + 1];
    }
    yylval->s = tmp;
    return CUSTOMIZE;
}

"∈"|"in" {
    yylval->n = yylineno;
    return BELONG;
}

[0-9]+ {
    int num = atoi(yytext);
    yylval->n = num;
    return NUM;
}

"," {
    yylval->n = yylineno;
    return COMMA;    
}

"+" {
    yylval->n = yylineno;
    return PLUS;
}

"-" {
    yylval->n = yylineno;
    return MINUS;
}

"*" {
    yylval->n = yylineno;
    return MULT;
}

"/" {
    yylval->n = yylineno;
    return DIV;
}

"_" {
    yylval->n = yylineno;
    return UNDERSCORE;
}

"~" {
    yylval->n = yylineno;
    return NOT;
}

"∧"|"/\\" {
    yylval->n = yylineno;
    return CONJ;
}

"∨"|"\\/" {
    yylval->n = yylineno;
    return DISJ;
}

"->" {
    yylval->n = yylineno;
    return ARROW;
}

"<==>" {
    yylval->n = yylineno;
    return EQUIV;
}

"frac" {
    yylval->n = yylineno;
    return FRAC;
}

"sqrt" {
    yylval->n = yylineno;
    return SQRT;
}

"ln" {
    yylval->oper = Ln;
    return UNARYFUNC;
}

"sin" {
    yylval->oper = Sin;
    return UNARYFUNC;
}

"cos" {
    yylval->oper = Cos;
    return UNARYFUNC;
}

"ReflexiveBinRel" {
    yylval->oper = ReflexiveBinRel;
    return UNARYPRED;
}

"SymmetricBinRel" {
    yylval->oper = SymmetricBinRel;
    return UNARYPRED;
}

"AntisymmetricBinRel" {
    yylval->oper = AntisymmetricBinRel;
    return UNARYPRED;
}

"TransitiveBinRel" {
    yylval->oper = TransitiveBinRel;
    return UNARYPRED;
}

"EquivalenceBinRel" {
    yylval->oper = EquivalenceBinRel;
    return UNARYPRED;
}

"PreOrderBinRel" {
    yylval->oper = PreOrderBinRel;
    return UNARYPRED;
}

"PartialOrderBinRel" {
    yylval->oper = PartialOrderBinRel;
    return UNARYPRED;
}

"IsFunction" {
    yylval->oper = IsFunction;
    return UNARYPRED;
}

"IsInjection" {
    yylval->oper = IsInjection;
    return UNARYPRED;
}

"IsSurjection" {
    yylval->oper = IsSurjection;
    return UNARYPRED;
}

"IsBijection" {
    yylval->oper = IsBijection;
    return UNARYPRED;
}

"CountableSet" {
    yylval->oper = CountableSet;
    return UNARYPRED;
}

"UncountableSet" {
    yylval->oper = UncountableSet;
    return UNARYPRED;
}

"SetPartition" {
    yylval->oper = SetPartition;
    return BINARYPRED;
}


"PartitionRefine" {
    yylval->oper = PartitionRefine;
    return BINARYPRED;
}

"TransitiveClosure" {
    yylval->oper = TransitiveClosure;
    return BINARYPRED;
}

"RelTransClosure" {
    yylval->oper = RelTransClosure;
    return BINARYPRED;
}

"Equinumerous" {
    yylval->oper = Equinumerous;
    return BINARYPRED;
}

"HasInjection" {
    yylval->oper = HasInjection;
    return BINARYPRED;
}

"ExistsUnique" {
    yylval->oper = ExistsUnique;
    return BINARYPRED;
}

"ExistsInf" {
    yylval->oper = ExistsInf;
    return BINARYPRED;
}

"ExistsN" {
    yylval->oper = ExistsN;
    return BINARYPRED;
}


"PowerSet" {
    yylval->oper = PowerSet;
    return UNARYFUNC;
}

"GeneralUnion" {
    yylval->oper = GeneralUnion;
    return UNARYFUNC;
}

"GeneralIntersection" {
    yylval->oper = GeneralIntersection;
    return UNARYFUNC;
}

"IdentityBinRel" {
    yylval->oper = IdentityBinRel;
    return UNARYFUNC;
}

"SetSum" {
    yylval->oper = SetSum;
    return UNARYFUNC;
}

"InverseBinRel" {
    yylval->oper = InverseBinRel;
    return UNARYFUNC;
}

"InverseFunc" {
    yylval->oper = InverseFunc;
    return UNARYFUNC;
}

"SetMinus" {
    yylval->oper = SetMinus;
    return BINARYFUNC;
}

"BinRelComp" {
    yylval->oper = BinRelComp;
    return BINARYFUNC;
}

"SetComplement" {
    yylval->oper = SetComplement;
    return BINARYFUNC;
}

"EquivClass" {
    yylval->oper = EquivClass;
    return BINARYFUNC;
}

"PartialFunction" {
    yylval->oper = PartialFunction;
    return BINARYFUNC;
}

"CartesianProd" {
    yylval->oper = CartesianProd;
    return CARTESIANPROD;
}

"'" {
    yylval->n = yylineno;
    return DERI;
}

"=" {
    yylval->n = yylineno;
    return EQ;
}

"<="|"≤" {
    yylval->n = yylineno;
    return LE;
}

">="|"≥" {
    yylval->n = yylineno;
    return GE;
}

"<" {
    yylval->n = yylineno;
    return LT;
}

">" {
    yylval->n = yylineno;
    return GT;
}

"!=" {
    yylval->n = yylineno;
    return NEQ;
}

"lim" {
    yylval->n = yylineno;
    return LIM;
}

"infty" {
    yylval->n = yylineno;
    return INFTY;
}

"+infty" {
    yylval->n = yylineno;
    return POS_INFTY;
}

"-infty" {
    yylval->n = yylineno;
    return NEG_INFTY;
}

"forall" {
    yylval->n = yylineno;
    return FORALL;
}

"exists" {
    yylval->n = yylineno;
    return EXISTS;
}

"^" {
    yylval->n = yylineno;
    return CARET;
}

"(" {
    yylval->n = yylineno;
    return LPAREN;
}

")" {
    yylval->n = yylineno;
    return RPAREN;
}

"[" {
    yylval->n = yylineno;
    return LBRACKET;
}

"]" {
    yylval->n = yylineno;
    return RBRACKET;
}

"{" {
    yylval->n = yylineno;
    return LBRACE;
}

"}" {
    yylval->n = yylineno;
    return RBRACE;
}

"|" {
    yylval->n = yylineno;
    return VERTICAL_BAR;
}

"max" {
    yylval->n = yylineno;
    return MAX;
}

"min" {
    yylval->n = yylineno;
    return MIN;
}

"sup" {
    yylval->n = yylineno;
    return SUP;
}

"inf" {
    yylval->n = yylineno;
    return INF;
}

"⊆" {
    yylval->n = yylineno;
    return SUBSET;
}

"⊊" {
    yylval->n = yylineno;
    return SUBSETNEQ;
}

"∩" {
    yylval->n = yylineno;
    return INTERSECTION;
}

"∪" {
    yylval->n = yylineno;
    return UNION;
}

"∘" {
    yylval->n = yylineno;
    return COMPOSITION;
}

"bar" {
    yylval->n = yylineno;
    return BAR;
}

"vec" {
    yylval->n = yylineno;
    return VEC;
}

"mod" {
    yylval->n = yylineno;
    return MOD;
}

":"|"：" {
    yylval->n = yylineno;
    return COLON;
}

"..." {
    yylval->n = yylineno;
    return ELLIPSIS;
}

"sum" {
    yylval->n = yylineno;
    return SUM;
}

"prod" {
    yylval->n = yylineno;
    return PROD;
}

"∅" {
    yylval->n = yylineno;
    return EMPTYSET;
}

"?Var" {
    yylval->n = yylineno;
    return PATTERN_VAR;
}

"?Const" {
    yylval->n = yylineno;
    return PATTERN_CONST;
}

"?UnaryOper" {
    yylval->n = yylineno;
    return PATTERN_UNARY_OPER;
}

"?BinaryOper" {
    yylval->n = yylineno;
    return PATTERN_BINARY_OPER;
}

"?UnaryPred" {
    yylval->n = yylineno;
    return PATTERN_UNARY_PRED;
}

"?BinaryPred" {
    yylval->n = yylineno;
    return PATTERN_BINARY_PRED;
}

"?TermList" {
    yylval->n = yylineno;
    return PATTERN_TERMLIST;
}

"?" {
    yylval->n = yylineno;
    return QUESTION_MARK;
}

[A-Za-z][A-Za-z0-9]*[']*|"α"|"β"|"Γ"|"γ"|"Δ"|"δ"|"ε"|"ɛ"|"ζ"|"η"|"Θ"|"θ"|"ι"|"κ"|"Λ"|"λ"|"μ"|"ν"|"Ξ"|"ξ"|"Π"|"π"|"ρ"|"Σ"|"σ"|"ς"|"τ"|"υ"|"Φ"|"φ"|"χ"|"Ψ"|"ψ"|"Ω"|"ω" {
    char *tmp = (char *) calloc(1, (yyleng + 1) * sizeof(char));
    for(int i = 0; i < yyleng; i++){
        tmp[i] = yytext[i];
    }
    yylval->s = tmp;
    return VAR;
}

[ \t\n:：；。\r] { };

. {
    if (yyextra->from_string) {
        char *tmp = malloc((yylloc->last_column - yylloc->first_column + 2) * sizeof(char));
        strncpy(tmp, yyextra->data + yylloc->first_column, (yylloc->last_column - yylloc->first_column + 1));
        fprintf(stderr, "\n%s: unexpected characters '%s'.\n", tmp, yytext);
        free(tmp);
    }
    else fprintf(stderr, "\n%s:%d.%d-%d.%d: unexpected characters '%s'.\n", yyextra->data,
        yylloc->first_line, yylloc->first_column, yylloc->last_line, yylloc->last_column, yytext);
    exit(1);
}
%%
