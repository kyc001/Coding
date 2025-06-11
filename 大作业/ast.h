#ifndef AST_H
#define AST_H

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum const_type
{
    Num = 0,
    Infty,
    Pos_Infty,
    Neg_Infty,
    E,
    Pi,
    I,
    EmptySet,
    NatSet,
    Ellipsis
};

typedef enum const_type const_type;

typedef enum oper_type
{
    Comma = Ellipsis + 1,
    Plus,
    Neg,
    Minus,
    Mult,
    Div,
    Mod,
    Index,
    Frac,
    Power,
    Sqrt,
    Sqrt_n,
    Abs,
    SetSize,
    Max,
    Min,
    Sup,
    Inf,
    Ceil,
    Floor,
    Sin,
    Cos,
    Ln,

    //set related: unary
    PowerSet,
    GeneralUnion,
    GeneralIntersection,
    IdentityBinRel,
    InverseBinRel,
    InverseFunc,
    SetSum,
    //set related: binary
    SetMinus,
    BinRelComp,
    EquivClass,
    PartialFunction,
    //set related: list
    CartesianProd,

    Deri,
    Lim,
    SetConstruction,
    SetUnion,
    SetIntersection,
    SetComplement,
    Composition,
    Bar,
    Vec,
    Colon,
    BigSum,
    BigSum_only_index,
    BigSum_limits,
    BigProd,
    BigProd_only_index,
    BigProd_limits,
    Set_enum,
    Set_build,
    Set_replace,
    Tuple,
    Interval_lopen_ropen,
    Interval_lclosed_ropen,
    Interval_lopen_rclosed,
    Interval_lclosed_rclosed
} oper_type;

typedef enum oper_type oper_type;

enum binder_type
{
    Lambda = Interval_lclosed_rclosed + 1,
    Limit
};

typedef enum binder_type binder_type;

enum pred_type
{
    Eq = Limit + 1,
    Neq,
    Le,
    Ge,
    Lt,
    Gt,
    Continue,
    UContinue,
    ContinueOn,
    UContinueOn,
    Bounded,
    BoundedAbove,
    BoundedBelow,
    BoundedAboveBy,
    BoundedBelowBy,
    MonoInc,
    MonoDec,
    SMonoInc,
    SMonoDec,
    Convergent,
    Divergent,
    SeqHasLimit,

    //logic related: binary
    ExistsUnique,
    ExistsInf,
    ExistsN,


    //set related: unary
    CountableSet,
    UncountableSet,
    ReflexiveBinRel,
    SymmetricBinRel,
    AntisymmetricBinRel,
    TransitiveBinRel,
    EquivalenceBinRel,
    PreOrderBinRel,
    PartialOrderBinRel,
    IsFunction,
    IsInjection,
    IsSurjection,
    IsBijection,

    //set related: binary
    Belong,
    Subset,
    SubsetNeq,
    Equinumerous,
    RelTransClosure,
    TransitiveClosure,
    SetPartition,
    PartitionRefine,
    HasInjection,

    TendsTo
};

typedef enum pred_type pred_type;

enum connect_type
{
    Not = TendsTo + 1,
    And,
    Or,
    Impl,
    Iff
};

typedef enum connect_type connect_type;

enum quant_type
{
    Forall = Iff + 1,
    Exists,
};

typedef enum quant_type quant_type;

enum pattern_type
{
    PatternWildCard = Exists + 1,
    PatternVar,
    PatternConst,
    PatternOper,
    PatternPred,
    PatternTermList,
    PatternIgnore,
};

typedef enum pattern_type pattern_type;

enum term_type
{
    Var = Exists + 1,
    TermVar,
    Const,
    Oper,
    Apply,
    Binder,
    Pred,
    Connect,
    Quant,
    RawQuant,
    TermList,
    Pattern,
};

typedef enum term_type term_type;

typedef struct term_list term_list;

enum notation_abs_type
{
    abs_set = TermList + 1,
    abs_num,
    abs_ow,
    /* set, number, or otherwise */
};
typedef enum notation_abs_type notation_abs_type;

struct term
{
    term_type type;
    int abs_type_checked;
    notation_abs_type abs_type;

    union {
        char *Var;
        struct
        {
            const_type type;
            int content;
        } Const;
        oper_type Oper;
        struct
        {
            struct term *left;
            struct term *right;
        } Apply;
        struct
        {
            binder_type binder_type;
            char *binder_var;
            struct term *body;
        } Binder;
        pred_type Pred;
        connect_type Connect;
        struct
        {
            quant_type type;
            char *var;
            struct term *body;
        } Quant;
        struct
        {
            quant_type type;
            struct term *raw_var;
            struct term *body;
        } RawQuant;
        term_list *TermList;
        pattern_type Pattern;
    } content;
};

typedef struct term term;

struct named_term
{
    int *name;
    term *t;
};

typedef struct named_term named_term;

struct int_list
{
    int element;
    struct int_list *next;
};

typedef struct int_list int_list;

struct var_list
{
    char *element;
    struct var_list *next;
};

typedef struct var_list var_list;

struct term_list
{
    term *element;
    struct term_list *next;
};

enum forward_type
{
    FNoHint = TermList + 1,
    Knowledge,
    Inference,
    Same,
    AddEqn,
    SubEqn,
    EquTrans,
    DeriBothTerms,
    TakeLimOnBothTerms,
    SquareBothTerms
};

typedef enum forward_type forward_type;

struct forward
{
    forward_type type;
    union {
        char *knowledge;
        term *evidence;
        int equ;
        char *var;
        int_list *equ_list;
    } content;
};

typedef struct forward forward;

enum backward_type
{
    BNoHint = SquareBothTerms + 1,
    Contra
};

typedef enum backward_type backward_type;

struct backward
{
    backward_type type;
};

typedef struct backward backward;

enum action_type
{
    IntroVar = Contra + 1,
    IntroTerm,
    IntroTermWithProp,
    Suppose,
    Set,
    ExistsVar
};

typedef enum action_type action_type;

struct action
{
    action_type type;
    union {
        char *intro_var;
        char *exists_var;
        term *intro_term;
        term *intro_term_with_prop[2];
        term *suppose_term;
        term *set_term;
    } content;
};

typedef struct action action;

enum proof_type
{
    PoseWithoutProof = ExistsVar + 1,
    PoseAndProve,
    PoseInduction,
    ConclWithoutProof,
    ConclAndProve,
    ClaimSuffice,
    ProveSuffice,
    Action,
    PosePartialProof,
    EndPartialProof
};

typedef enum proof_type proof_type;

struct proof
{
    proof_type type;
    union {
        struct
        {
            forward *fwd;
            term *curr_term;
            struct proof *next_proof;
        } PoseWithoutProof;
        struct
        {
            forward *fwd;
            term *curr_term;
            struct proof *curr_proof;
            struct proof *next_proof;
        } PoseAndProve;
        struct
        {
            forward *fwd;
            char *induct_var;
            term *curr_term;
            struct proof *curr_proof;
            struct proof *next_proof;
        } PoseInduction;
        struct
        {
            forward *fwd;
        } ConclWithoutProof;
        struct
        {
            forward *fwd;
            struct proof *curr_proof;
        } ConclAndProve;
        struct
        {
            backward *bwd;
            term *curr_term;
            struct proof *next_proof;
        } ClaimSuffice;
        struct
        {
            backward *bwd;
            term *curr_term;
            struct proof *curr_proof;
            struct proof *next_proof;
        } ProveSuffice;
        struct
        {
            action *act;
            struct proof *next_proof;
        } Action;
        struct
        {
            action *act;
            struct proof *curr_proof;
            struct proof *next_proof;
        } PosePartialProof;
    } content;
    int *remember;
};

typedef struct proof proof;

struct assu_list
{
    char *hypname;
    term *assu;
    struct assu_list *next;
};

typedef struct assu_list assu_list;

struct proof_goal
{
    assu_list *assus;
    term *concl;
};

typedef struct proof_goal proof_goal;

struct program
{
    proof_goal *pg;
    proof *pr;
};

typedef struct program program;

struct lexer_mode
{
    int start_token;
    int debug;
    int from_string;
    char *data; // data is filename if from_string = 0, data is input string if from_string = 1
};

typedef struct lexer_mode lexer_mode;

struct parser_mode
{
    union {
        program **pr;
        term **tm;
    };
    int debug;
    int from_string;
    char *data; // data is filename if from_string = 0, data is input string if from_string = 1
};

typedef struct parser_mode parser_mode;

forward *copy_fwd(forward *fwd);
backward *copy_bwd(backward *bwd);
term *copy_term(term *t);
int_list *copy_int_list(int_list *list);
var_list *copy_var_list(var_list *list);
var_list* reverse_var_list(var_list* head);
term_list *copy_term_list(term_list *list);
void concat_var_list(var_list *dest, var_list *src);
void elim_var_list(var_list **list, const char *var);
void free_fwd(forward *fwd);
void free_bwd(backward *bwd);
void free_act(action *act);
void free_term(term *t);
void free_proof(proof *pr);
void free_proof_goal(proof_goal *pg);
void free_program(program *pr);
void free_int_list(int_list *list);
void free_var_list(var_list *list);
void free_term_list(term_list *list);
void free_assu_list(assu_list *list);

term *substr_var(char *den, char *src, term *t);
term* substr_term(term* den, char* src, term* t);
bool term_eqb(term *t1, term *t2);
term_list* split_and(term* t);

void print_term(term *t, FILE *fp);
void print_term_internal(term *tm, FILE *fp);
void print_term_list(term *t, FILE *fp);
void print_termlist(term_list* list, FILE* fp);
void print_term_list_internal(term *t, FILE *fp);
void print_forward(forward *fwd, FILE *fp);
void print_forward_internal(forward *fwd, FILE *fp);
void print_backward(backward *bwd, FILE *fp);
void print_backward_internal(backward *bwd, FILE *fp);
void print_action(action *act, FILE *fp);
void print_action_internal(action *act, FILE *fp);
void print_proof(proof *p, FILE *fp);
void print_proof_internal(proof *pr, FILE *fp);
void print_proof_goal(proof_goal *pg, FILE *fp);
void print_proof_goal_internal(proof_goal *pg, FILE *fp);
void print_program(program *pr, FILE *fp);
void print_program_internal(program *pr, FILE *fp);

#endif
