#include "ast.h"

term *copy_term(term *t)
{
    if (t == NULL)
        return NULL;
    term *new_term = (term *)malloc(sizeof(term));
    memset(new_term, 0, sizeof(term));
    new_term->type = t->type;
    new_term->abs_type = t->abs_type;
    new_term->abs_type_checked = t->abs_type_checked;
    // 根据类型进行深拷贝
    switch (t->type)
    {
    case TermVar:
    case Var: {
        if (t->content.Var)
        {
            new_term->content.Var = strdup(t->content.Var);
        }
        else
        {
            new_term->content.Var = NULL;
        }
        break;
    }
    case Const: {
        new_term->content.Const.type = t->content.Const.type;
        new_term->content.Const.content = t->content.Const.content;
        break;
    }
    case Oper: {
        new_term->content.Oper = t->content.Oper;
        break;
    }
    case Apply: {
        new_term->content.Apply.left = copy_term(t->content.Apply.left);
        new_term->content.Apply.right = copy_term(t->content.Apply.right);
        break;
    }
    case Binder:
        new_term->content.Binder.binder_type = t->content.Binder.binder_type;
        if (t->content.Binder.binder_var)
        {
            new_term->content.Binder.binder_var = strdup(t->content.Binder.binder_var);
        }
        else
        {
            new_term->content.Binder.binder_var = NULL;
        }
        new_term->content.Binder.body = copy_term(t->content.Binder.body);
        break;

    case Pred: {
        new_term->content.Pred = t->content.Pred;
        break;
    }
    case Connect: {
        new_term->content.Connect = t->content.Connect;
        break;
    }
    case Quant: {
        new_term->content.Quant.type = t->content.Quant.type;
        if (t->content.Quant.var)
        {
            new_term->content.Quant.var = strdup(t->content.Quant.var);
        }
        else
        {
            new_term->content.Quant.var = NULL;
        }
        new_term->content.Quant.body = copy_term(t->content.Quant.body);
        break;
    }
    case RawQuant: {
        new_term->content.RawQuant.type = t->content.RawQuant.type;
        new_term->content.RawQuant.raw_var = copy_term(t->content.RawQuant.raw_var);
        new_term->content.RawQuant.body = copy_term(t->content.RawQuant.body);
        break;
    }
    case TermList: {
        new_term->content.TermList = copy_term_list(t->content.TermList);
        break;
    }
    default: {
        // 如果有其他未处理的类型，确保添加相应的逻辑
        printf("error, unknown term type, id : %d\n", t->type);
        break;
    }
    }
    return new_term;
}

// 假设 term_list 的深拷贝实现
term_list *copy_term_list(term_list *list)
{
    if (list == NULL)
    {
        return NULL;
    }
    // 创建新节点
    term_list *new_list = (term_list *)malloc(sizeof(term_list));
    memset(new_list, 0, sizeof(term_list));
    // 复制当前节点的 element
    new_list->element = copy_term(list->element);
    // 递归复制后续节点
    new_list->next = copy_term_list(list->next);
    return new_list;
}

int_list *copy_int_list(int_list *list)
{
    if (list == NULL)
        return NULL;
    int_list *new_list = (int_list *)malloc(sizeof(int_list));
    new_list->element = list->element;
    new_list->next = copy_int_list(list->next);
    return new_list;
}

var_list *copy_var_list(var_list *list)
{
    if (list == NULL)
        return NULL;
    var_list *new_list = (var_list *)malloc(sizeof(var_list));
    strcpy(new_list->element, list->element);
    new_list->next = copy_var_list(list->next);
    return new_list;
}

var_list* reverse_var_list(var_list* head) {
    var_list* prev = NULL;
    var_list* current = head;
    while (current != NULL) {
        var_list* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void concat_var_list(var_list *dest, var_list *src)
{
    if (dest == NULL)
    {
        printf("Error in concat_var_list.\n");
        exit(1);
    }
    var_list *tmp = dest;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = src;
}

void elim_var_list(var_list **list, const char *var)
{
    if (list == NULL || *list == NULL)
        return;
    var_list *current = *list;
    var_list *previous = NULL;
    while (current != NULL)
    {
        if (strcmp(current->element, var) == 0)
        {
            if (previous == NULL)
                *list = current->next;
            else
                previous->next = current->next;
            var_list *tmp = current;
            current = current->next;
            free(tmp->element);
            free(tmp);
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}

forward *copy_fwd(forward *fwd)
{
    if (fwd == NULL)
        return NULL;
    forward *res = (forward *)malloc(sizeof(forward));
    res->type = fwd->type;
    switch (fwd->type)
    {
    case FNoHint:
    case Same:
    case TakeLimOnBothTerms:
    case SquareBothTerms: {
        break;
    }
    case Knowledge: {
        res->content.knowledge = strdup(fwd->content.knowledge);
        break;
    }
    case Inference: {
        res->content.evidence = copy_term(fwd->content.evidence);
        break;
    }
    case DeriBothTerms: {
        res->content.var = strdup(fwd->content.var);
        break;
    }
    case SubEqn:
    case AddEqn: {
        res->content.equ_list = copy_int_list(fwd->content.equ_list);
        break;
    }
    case EquTrans: {
        res->content.equ = fwd->content.equ;
        break;
    }
    default: {
        // 如果有其他未处理的类型，确保添加相应的逻辑
        printf("error, unknown fwd type, id : %d\n", fwd->type);
        break;
    }
    }
    return res;
}

void free_fwd(forward *fwd)
{
    if (fwd == NULL)
        return;
    switch (fwd->type)
    {
    case FNoHint:
        break;
    case Knowledge:
        free(fwd->content.knowledge);
        break;
    case Inference:
        free_term(fwd->content.evidence);
        break;
    case Same:
        break;
    case AddEqn:
        free_int_list(fwd->content.equ_list);
        break;
    case SubEqn:
        free_int_list(fwd->content.equ_list);
        break;
    case EquTrans:
        break;
    case DeriBothTerms:
        free(fwd->content.var);
        break;
    case TakeLimOnBothTerms:
        free(fwd->content.var);
        break;
    case SquareBothTerms:
        break;
    default:
        break;
    }
    free(fwd);
}

void free_bwd(backward *bwd)
{
    if (bwd == NULL)
        return;
    switch (bwd->type)
    {
    case BNoHint:
        break;
    case Contra:
        break;
    default:
        break;
    }
    free(bwd);
}

void free_act(action *act)
{
    if (act == NULL)
        return;
    switch (act->type)
    {
    case IntroVar:
        free(act->content.intro_var);
        break;
    case IntroTerm:
        free_term(act->content.intro_term);
        break;
    case IntroTermWithProp:
        free_term(act->content.intro_term_with_prop[0]);
        free_term(act->content.intro_term_with_prop[1]);
        break;
    case Suppose:
        free_term(act->content.suppose_term);
        break;
    case Set:
        free_term(act->content.set_term);
        break;
    case ExistsVar:
        free(act->content.exists_var);
        break;
    default:
        break;
    }
    free(act);
}

void free_term(term *t)
{
    if (t == NULL)
        return;
    switch (t->type)
    {
    case Var:
        free(t->content.Var);
        break;
    case Const:
        break;
    case Oper:
        break;
    case Apply:
        free_term(t->content.Apply.left);
        free_term(t->content.Apply.right);
        break;
    case Binder:
        free(t->content.Binder.binder_var);
        free_term(t->content.Binder.body);
        break;
    case Pred:
        break;
    case Connect:
        break;
    case Quant:
        free(t->content.Quant.var);
        free_term(t->content.Quant.body);
        break;
    case RawQuant:
        free_term(t->content.RawQuant.raw_var);
        free_term(t->content.RawQuant.body);
        break;
    case TermList:
        free_term_list(t->content.TermList);
        break;
    default:
        break;
    }
    free(t);
}

void free_proof(proof *pr)
{
    if (pr == NULL)
        return;
    switch (pr->type)
    {
    case PoseWithoutProof:
        free_fwd(pr->content.PoseWithoutProof.fwd);
        free_term(pr->content.PoseWithoutProof.curr_term);
        free_proof(pr->content.PoseWithoutProof.next_proof);
        break;
    case PoseAndProve:
        free_fwd(pr->content.PoseAndProve.fwd);
        free_term(pr->content.PoseAndProve.curr_term);
        free_proof(pr->content.PoseAndProve.curr_proof);
        free_proof(pr->content.PoseAndProve.next_proof);
        break;
    case ConclWithoutProof:
        free_fwd(pr->content.ConclWithoutProof.fwd);
        break;
    case ConclAndProve:
        free_fwd(pr->content.ConclAndProve.fwd);
        free_proof(pr->content.ConclAndProve.curr_proof);
        break;
    case ClaimSuffice:
        free_bwd(pr->content.ClaimSuffice.bwd);
        free_term(pr->content.ClaimSuffice.curr_term);
        free_proof(pr->content.ClaimSuffice.next_proof);
        break;
    case ProveSuffice:
        free_bwd(pr->content.ProveSuffice.bwd);
        free_term(pr->content.ProveSuffice.curr_term);
        free_proof(pr->content.ProveSuffice.curr_proof);
        free_proof(pr->content.ProveSuffice.next_proof);
        break;
    case Action:
        free_act(pr->content.Action.act);
        free_proof(pr->content.Action.next_proof);
        break;
    case PosePartialProof:
        free_act(pr->content.PosePartialProof.act);
        free_proof(pr->content.PosePartialProof.curr_proof);
        free_proof(pr->content.PosePartialProof.next_proof);
        break;
    default:
        break;
    }
    free(pr->remember);
    free(pr);
}

void free_proof_goal(proof_goal *pg)
{
    if (pg == NULL)
        return;
    free_assu_list(pg->assus);
    free_term(pg->concl);
    free(pg);
}

void free_program(program *pr)
{
    if (pr == NULL)
        return;
    free_proof_goal(pr->pg);
    free_proof(pr->pr);
    free(pr);
}

void free_int_list(int_list *list)
{
    if (list == NULL)
        return;
    free_int_list(list->next);
    free(list);
}

void free_var_list(var_list *list)
{
    if (list == NULL)
        return;
    free_var_list(list->next);
    free(list->element);
    free(list);
}

void free_term_list(term_list *list)
{
    while (list != NULL)
    {
        struct term_list *next = list->next;
        free_term(list->element);
        free(list);
        list = next;
    }
}

void free_assu_list(assu_list *list)
{
    while (list != NULL)
    {
        struct assu_list *next = list->next;
        free_term(list->assu);
        free(list->hypname);
        free(list);
        list = next;
    }
}

backward *copy_bwd(backward *bwd)
{
    backward *res = (backward *)malloc(sizeof(backward));
    res->type = bwd->type;
    return res;
}

term *substr_var(char *den, char *src, term *t)
{
    switch (t->type)
    {
    case Var: {
        if (!strcmp(t->content.Var, src))
        {
            free(t->content.Var);
            t->content.Var = strdup(den);
        }
        break;
    }
    case Const:
    case Oper:
    case Pred:
    case Connect: {
        break;
    }
    case Apply: {
        t->content.Apply.left = substr_var(den, src, t->content.Apply.left);
        t->content.Apply.right = substr_var(den, src, t->content.Apply.right);
        break;
    }
    case Binder: {
        if (strcmp(t->content.Binder.binder_var, src))
        {
            t->content.Binder.body = substr_var(den, src, t->content.Binder.body);
        }
        break;
    }
    case Quant: {
        if (strcmp(t->content.Quant.var, src))
        {
            t->content.Quant.body = substr_var(den, src, t->content.Quant.body);
        }
        break;
    }
    case RawQuant: {
        break;
    }
    case TermList: {
        term_list *list = t->content.TermList;
        while (list != NULL)
        {
            list->element = substr_var(den, src, list->element);
            list = list->next;
        }
    }
    default:{
        break;
    }
    }
    return t;
}

term* substr_term(term* den, char* src, term* t){
    switch(t->type){
        case Var:{
            if(!strcmp(t->content.Var, src)){
                free_term(t);
                t = copy_term(den);
            }
            break;
        }
        case Const:
        case Oper:
        case Pred:
        case Connect:{
            break;
        }
        case Apply:{
            t->content.Apply.left = substr_term(den, src, t->content.Apply.left);
            t->content.Apply.right = substr_term(den, src, t->content.Apply.right);
            break;
        }
        case Binder:{
            if(strcmp(t->content.Binder.binder_var,src)){
                t->content.Binder.body = substr_term(den, src, t->content.Binder.body);
            }
            break;
        }
        case Quant:{
            if(strcmp(t->content.Quant.var,src)){
                t->content.Quant.body = substr_term(den, src, t->content.Quant.body);
            }
            break;
        }
        case RawQuant:{
            break;
        }
        case TermList:{
            term_list* list = t->content.TermList;
            while(list != NULL){
                list->element = substr_term(den, src, list->element);
                list = list->next;
            }
            break;
        }
        default:{
            break;
        }
    }
    return t;
}

bool term_eqb(term *t1, term *t2)
{
    if (t1 == NULL || t2 == NULL)
        return false;
    if (t1->type != t2->type)
        return false;
    switch (t1->type)
    {
    case Var: {
        return strcmp(t1->content.Var, t2->content.Var) == 0;
    }
    case Const: {
        if (t1->content.Const.type != t2->content.Const.type)
            return false;
        if (t1->content.Const.type == Num)
        {
            return t1->content.Const.content == t2->content.Const.content;
        }
        return true;
    }
    case Oper: {
        return t1->content.Oper == t2->content.Oper;
    }
    case Connect: {
        return t1->content.Connect == t2->content.Connect;
    }
    case Pred: {
        return t1->content.Pred == t2->content.Pred;
    }
    case Apply: {
        return term_eqb(t1->content.Apply.left, t2->content.Apply.left) &&
               term_eqb(t1->content.Apply.right, t2->content.Apply.right);
    }
    case Binder: {
        if (t1->content.Binder.binder_type != t2->content.Binder.binder_type)
            return false;
        if (strcmp(t1->content.Binder.binder_var, t2->content.Binder.binder_var) != 0)
            return false;
        return term_eqb(t1->content.Binder.body, t2->content.Binder.body);
    }
    case Quant: {
        if (t1->content.Quant.type != t2->content.Quant.type)
            return false;
        if (strcmp(t1->content.Quant.var, t2->content.Quant.var) != 0)
            return false;
        return term_eqb(t1->content.Quant.body, t2->content.Quant.body);
    }
    case TermList: {
        term_list *list1 = t1->content.TermList;
        term_list *list2 = t2->content.TermList;
        while (list1 != NULL && list2 != NULL)
        {
            if (!term_eqb(list1->element, list2->element))
                return false;
            list1 = list1->next;
            list2 = list2->next;
        }
        if (list1 != list2)
            return false;
        else
            return true;
    }
    case RawQuant: {
        if (t1->content.RawQuant.type != t2->content.RawQuant.type)
            return false;
        return term_eqb(t1->content.RawQuant.raw_var, t2->content.RawQuant.raw_var) &&
               term_eqb(t1->content.RawQuant.body, t2->content.RawQuant.body);
    }
    default: {
        printf("undefined term type: %d", t1->type);
        break;
    }
    }
    return false;
}

bool term_imply (term *p, term *g) {
    term *premise = copy_term(p);
    term *goal = copy_term(g);
    
    while (premise->type == Quant) {
        if (premise->content.Quant.type == Forall) {
            char *var = premise->content.Quant.var;
            premise = premise->content.Quant.body;
            substr_var("", var, premise);
        }
        else {

        }
    }
    return false;
}

//会对t做深拷贝
term_list* split_and(term* t){
    if(t->type == Apply && t->content.Apply.left->type == Apply 
    && t->content.Apply.left->content.Apply.left->type == Connect && t->content.Apply.left->content.Apply.left->content.Connect == And){
        term_list* l1 = split_and(t->content.Apply.left->content.Apply.right);
        term_list* l2 = split_and(t->content.Apply.right);
        if (l1 == NULL) return l2;
        term_list *current = l1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = l2;
        return l1;
    }
    else {
        term_list* res = (term_list*)malloc(sizeof(term_list));
        res->element = copy_term(t);
        res->next = NULL;
        return res;
    }
}

void print_term_list(term *t, FILE *fp)
{   
    if(t == NULL) return;
    if (t->type == TermList)
    {
        term_list *l = t->content.TermList;
        while (l->element != NULL)
        {
            if (l->next == NULL)
            {
                print_term(l->element, fp);
                break;
            }
            print_term(l->element, fp);
            fprintf(fp, ", ");
            l = l->next;
        }
    }
    else
    {
        print_term(t, fp);
    }
}

void print_termlist(term_list* list, FILE* fp){
    if(list == NULL) return;
    term_list *l = list;
    while (l->element != NULL)
    {
        if (l->next == NULL)
        {
            print_term(l->element, fp);
            break;
        }
        print_term(l->element, fp);
        fprintf(fp, ", ");
        l = l->next;
    }
}

void print_term_list_internal(term *t, FILE *fp)
{
    if (t->type == TermList)
    {
        term_list *l = t->content.TermList;
        while (l->element != NULL)
        {
            if (l->next == NULL)
            {
                print_term_internal(l->element, fp);
                break;
            }
            print_term_internal(l->element, fp);
            fprintf(fp, " , ");
            l = l->next;
        }
    }
    else
        print_term_internal(t, fp);
}

void print_term(term *t, FILE *fp)
{
    if (t == NULL)
    {
        printf("Error: print_term visiting NULL.\n");
        return;
    }
    if (t->type == Var)
    {
        fprintf(fp, "%s", t->content.Var);
    }
    else if (t->type == Const)
    {
        if (t->content.Const.type == Num)
        {
            fprintf(fp, "%d", t->content.Const.content);
        }
        else if (t->content.Const.type == Infty)
        {
            fprintf(fp, "infty");
        }
        else if (t->content.Const.type == Pos_Infty)
        {
            fprintf(fp, "+infty");
        }
        else if (t->content.Const.type == Neg_Infty)
        {
            fprintf(fp, "-infty");
        }
        else if (t->content.Const.type == E)
        {
            fprintf(fp, "e");
        }
        else if (t->content.Const.type == Pi)
        {
            fprintf(fp, "π");
        }
        else if (t->content.Const.type == I)
        {
            fprintf(fp, "i");
        }
        else if (t->content.Const.type == EmptySet)
        {
            fprintf(fp, "∅");
        }
        else if (t->content.Const.type == I)
        {
            fprintf(fp, "...");
        }
    }
    else if (t->type == Apply)
    {
        if (t->content.Apply.left == NULL)
            return;
        term *cur_l = t->content.Apply.left;
        term *cur_r = t->content.Apply.right;
        /* apply () () */
        if (cur_l->type == Oper)
        {
            int cur_oper = cur_l->content.Oper;
            if (cur_oper == Neg)
            {
                fprintf(fp, "-");
                print_term(cur_r, fp);
            }
            else if (cur_oper == Abs)
            {
                fprintf(fp, "|");
                print_term(cur_r, fp);
                fprintf(fp, "|");
            }
            else if (cur_oper == SetSize)
            {
                fprintf(fp, "|");
                print_term(cur_r, fp);
                fprintf(fp, "|");
            }
            else if (cur_oper == Sqrt)
            {
                fprintf(fp, "sqrt(");
                print_term(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == Sup)
            {
                fprintf(fp, "sup(");
                print_term(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == Inf)
            {
                fprintf(fp, "inf(");
                print_term(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == Vec)
            {
                fprintf(fp, "vec{");
                print_term(cur_r, fp);
                fprintf(fp, "}");
            }
            else if (cur_oper == Bar)
            {
                fprintf(fp, "bar{");
                print_term(cur_r, fp);
                fprintf(fp, "}");
            }
            else if (cur_oper == Tuple)
            {
                fprintf(fp, "(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == Sin)
            {
                fprintf(fp, "sin(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == Cos)
            {
                fprintf(fp, "cos(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == Ln)
            {
                fprintf(fp, "ln(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == PowerSet)
            {
                fprintf(fp, "PowerSet(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == GeneralUnion)
            {
                fprintf(fp, "GeneralUnion(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == GeneralIntersection)
            {
                fprintf(fp, "GeneralIntersection(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == IdentityBinRel)
            {
                fprintf(fp, "IdentityBinRel(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == InverseBinRel)
            {
                fprintf(fp, "InverseBinRel(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == InverseFunc)
            {
                fprintf(fp, "InverseFunc(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == SetSum)
            {
                fprintf(fp, "SetSum(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == CartesianProd)
            {
                fprintf(fp, "CartesianProd(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == Deri)
            {
                print_term(cur_r, fp);
                fprintf(fp, "'");
            }
            else if (cur_oper == Max)
            {
                fprintf(fp, "max(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == Min)
            {
                fprintf(fp, "min(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_oper == Set_enum)
            {
                fprintf(fp, "{");
                print_term_list(cur_r, fp);
                fprintf(fp, "}");
            }
        }
        else if(cur_l->type == Pred)
        {
            int cur_pred = cur_l->content.Pred;
            if (cur_pred == CountableSet)
            {
                fprintf(fp, "CountableSet(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_pred == UncountableSet)
            {
                fprintf(fp, "UncountableSet(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_pred == ReflexiveBinRel)
            {
                fprintf(fp, "ReflexiveBinRel(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_pred == SymmetricBinRel)
            {
                fprintf(fp, "SymmetricBinRel(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_pred == AntisymmetricBinRel)
            {
                fprintf(fp, "AntisymmetricBinRel(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_pred == TransitiveBinRel)
            {
                fprintf(fp, "TransitiveBinRel(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_pred == EquivalenceBinRel)
            {
                fprintf(fp, "EquivalenceBinRel(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_pred == PreOrderBinRel)
            {
                fprintf(fp, "PreOrderBinRel(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_pred == PartialOrderBinRel)
            {
                fprintf(fp, "PartialOrderBinRel(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
            else if (cur_pred == IsFunction)
            {
                fprintf(fp, "IsFunction(");
                print_term_list(cur_r, fp);
                fprintf(fp, ")");
            }
        }
        else if (cur_l->type == Connect)
        {
            int cur_connect = cur_l->content.Connect;
            if (cur_connect == Not)
            {
                fprintf(fp, "~(");
                print_term(cur_r, fp);
                fprintf(fp, ")");
            }
        }
        else if (cur_l->type == Var)
        {
            print_term(cur_l, fp);
            fprintf(fp, "(");
            print_term(cur_r, fp);
            fprintf(fp, ")");
        }
        /* apply ( apply () () ) () */
        else if (t->content.Apply.left->type == Apply)
        {
            term *cur_l_l = t->content.Apply.left->content.Apply.left;
            term *cur_l_r = t->content.Apply.left->content.Apply.right;
            if (cur_l_l->type == Oper)
            {
                int l_oper = cur_l_l->content.Oper;
                if (l_oper == Plus)
                {
                    fprintf(fp, "(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, " + ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == Minus)
                {
                    fprintf(fp, "(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, " - ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == Mult)
                {
                    print_term(cur_l_r, fp);
                    fprintf(fp, " * ");
                    print_term(cur_r, fp);
                }
                else if (l_oper == Div)
                {
                    fprintf(fp, "(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, " / ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == Mod)
                {
                    fprintf(fp, "(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, " mod ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == Index)
                {
                    print_term(cur_l_r, fp);
                    fprintf(fp, "_");
                    print_term(cur_r, fp);
                }
                else if (l_oper == Power)
                {
                    print_term(cur_l_r, fp);
                    fprintf(fp, " ^ ");
                    print_term(cur_r, fp);
                }
                else if (l_oper == Frac)
                {
                    fprintf(fp, "frac(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == Sqrt_n)
                {
                    fprintf(fp, "sqrt(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == SetUnion)
                {
                    fprintf(fp, "(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, " ∪ ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == SetIntersection)
                {
                    fprintf(fp, "(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, " ∩ ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == Composition)
                {
                    fprintf(fp, "(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, " ∘ ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == BigSum_only_index)
                {
                    fprintf(fp, "sum_{");
                    print_term(cur_l_r, fp);
                    fprintf(fp, "} (");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == BigProd_only_index)
                {
                    fprintf(fp, "prod_{");
                    print_term(cur_l_r, fp);
                    fprintf(fp, "} (");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == Interval_lclosed_ropen)
                {
                    fprintf(fp, "[");
                    print_term(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == Interval_lopen_rclosed)
                {
                    fprintf(fp, "(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, "]");
                }
                else if (l_oper == Interval_lclosed_rclosed)
                {
                    fprintf(fp, "[");
                    print_term(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, "]");
                }
                else if (l_oper == Interval_lopen_ropen)
                {
                    fprintf(fp, "(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == Set_build)
                {
                    fprintf(fp, "{");
                    print_term(cur_l_r, fp);
                    fprintf(fp, " | ");
                    print_term_list(cur_r, fp);
                    fprintf(fp, "}");
                }
                else if (l_oper == Colon)
                {
                    fprintf(fp, "(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, " : ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == SetMinus)
                {
                    fprintf(fp, "SetMinus(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == BinRelComp)
                {
                    fprintf(fp, "BinRelComp(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == EquivClass)
                {
                    fprintf(fp, "EquivClass(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_oper == PartialFunction)
                {
                    fprintf(fp, "PartialFunction(");
                    print_term(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
            }
            else if (cur_l_l->type == Pred)
            {
                int l_pred = cur_l_l->content.Pred;
                if (l_pred == Eq)
                {
                    print_term(cur_l_r, fp);
                    fprintf(fp, " = ");
                    print_term(cur_r, fp);
                }
                else if (l_pred == Neq)
                {
                    print_term(cur_l_r, fp);
                    fprintf(fp, " != ");
                    print_term(cur_r, fp);
                }
                else if (l_pred == Le)
                {
                    print_term(cur_l_r, fp);
                    fprintf(fp, " <= ");
                    print_term(cur_r, fp);
                }
                else if (l_pred == Ge)
                {
                    print_term(cur_l_r, fp);
                    fprintf(fp, " >= ");
                    print_term(cur_r, fp);
                }
                else if (l_pred == Lt)
                {
                    print_term(cur_l_r, fp);
                    fprintf(fp, " < ");
                    print_term(cur_r, fp);
                }
                else if (l_pred == Gt)
                {
                    print_term(cur_l_r, fp);
                    fprintf(fp, " > ");
                    print_term(cur_r, fp);
                }
                else if (l_pred == TendsTo)
                {
                    print_term(cur_l_r, fp);
                    fprintf(fp, " -> ");
                    print_term(cur_r, fp);
                }
                else if (l_pred == Subset)
                {
                    print_term_list(cur_l_r, fp);
                    fprintf(fp, " ⊆ ");
                    print_term(cur_r, fp);
                }
                else if (l_pred == SubsetNeq)
                {
                    print_term_list(cur_l_r, fp);
                    fprintf(fp, " ⊊ ");
                    print_term(cur_r, fp);
                }
                else if (l_pred == Belong)
                {
                    print_term_list(cur_l_r, fp);
                    fprintf(fp, " ∈ ");
                    print_term(cur_r, fp);
                }
                else if (l_pred == Equinumerous)
                {
                    fprintf(fp, "Equinumerous(");
                    print_term_list(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_pred == RelTransClosure)
                {
                    fprintf(fp, "RelTransClosure(");
                    print_term_list(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_pred == TransitiveClosure)
                {
                    fprintf(fp, "TransitiveClosure(");
                    print_term_list(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_pred == SetPartition)
                {
                    fprintf(fp, "SetPartition(");
                    print_term_list(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_pred == PartitionRefine)
                {
                    fprintf(fp, "PartitionRefine(");
                    print_term_list(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_pred == HasInjection)
                {
                    fprintf(fp, "HasInjection(");
                    print_term_list(cur_l_r, fp);
                    fprintf(fp, ", ");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
            }
            else if (cur_l_l->type == Connect)
            {
                int l_connect = cur_l_l->content.Connect;
                if (l_connect == And)
                {
                    print_term(cur_l_r, fp);
                    fprintf(fp, " /\\ ");
                    print_term(cur_r, fp);
                }
                else if (l_connect == Or)
                {
                    print_term(cur_l_r, fp);
                    fprintf(fp, " \\/ ");
                    print_term(cur_r, fp);
                }
                else if (l_connect == Impl)
                {
                    if (cur_l_r->type == TermList)
                    {
                        fprintf(fp, "if ");
                        term_list *list_cur = cur_l_r->content.TermList;
                        while (list_cur->element != NULL)
                        {
                            if (list_cur->next == NULL)
                            {
                                fprintf(fp, "(");
                                print_term(list_cur->element, fp);
                                fprintf(fp, ") ");
                                break;
                            }
                            fprintf(fp, "(");
                            print_term(list_cur->element, fp);
                            fprintf(fp, ") ");
                            list_cur = list_cur->next;
                        }
                        fprintf(fp, ", then (");
                        print_term(cur_r, fp);
                        fprintf(fp, ")");
                    }
                    else
                    {
                        print_term(cur_l_r, fp);
                        fprintf(fp, " -> ");
                        print_term(cur_r, fp);
                    }
                }
                else if (l_connect == Iff)
                {
                    print_term(cur_l_r, fp);
                    fprintf(fp, " <==> ");
                    print_term(cur_r, fp);
                }
            }
            /* apply (apply (apply () ()) ()) () */
            else if (cur_l_l->type == Apply)
            {
                term *cur_l_l_l = cur_l_l->content.Apply.left;
                term *cur_l_l_r = cur_l_l->content.Apply.right;
                int l_l_oper = cur_l_l_l->content.Oper;
                if (l_l_oper == Lim)
                {
                    fprintf(fp, "lim_{");
                    print_term(cur_l_l_r, fp);
                    fprintf(fp, " -> ");
                    print_term(cur_l_r, fp);
                    fprintf(fp, "} (");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_l_oper == BigSum_limits)
                {
                    fprintf(fp, "sum_{");
                    print_term(cur_l_l_r, fp);
                    fprintf(fp, "}^{");
                    print_term(cur_l_r, fp);
                    fprintf(fp, "} (");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
                else if (l_l_oper == BigProd_limits)
                {
                    fprintf(fp, "prod_{");
                    print_term(cur_l_l_r, fp);
                    fprintf(fp, "}^{");
                    print_term(cur_l_r, fp);
                    fprintf(fp, "} (");
                    print_term(cur_r, fp);
                    fprintf(fp, ")");
                }
            }
        }
    }
    else if (t->type == RawQuant)
    {
        fprintf(fp, "(");
        if (t->content.RawQuant.type == Forall)
        {
            fprintf(fp, "forall");
        }
        else
        {
            fprintf(fp, "exists");
        }
        term_list *list_cur = t->content.RawQuant.raw_var->content.TermList;
        while (list_cur->element != NULL)
        {
            fprintf(fp, " (");
            print_term(list_cur->element, fp);
            fprintf(fp, ")");
            list_cur = list_cur->next;
            if (list_cur == NULL)
                break;
        }
        fprintf(fp, ", ");
        fprintf(fp, "(");
        print_term(t->content.RawQuant.body, fp);
        fprintf(fp, "))");
    }
    else if (t->type == Quant)
    {
        fprintf(fp, "(");
        if (t->content.Quant.type == Forall)
        {
            fprintf(fp, "forall");
        }
        else
        {
            fprintf(fp, "exists");
        }
        fprintf(fp, " (%s)", t->content.Quant.var);
        fprintf(fp, ", ");
        fprintf(fp, "(");
        print_term(t->content.Quant.body, fp);
        fprintf(fp, "))");
    }
}

char *const_type_internal(const_type ty)
{
    switch (ty)
    {
    case Num:
        return "Num";
    case Infty:
        return "Infty";
    case Pos_Infty:
        return "Pos_Infty";
    case Neg_Infty:
        return "Neg_infty";
    case E:
        return "E";
    case Pi:
        return "Pi";
    case I:
        return "I";
    case EmptySet:
        return "Empty_Set";
    case Ellipsis:
        return "Ellipsis";
    default:
        fprintf(stderr, "Error: unknown const_type (id : %d).\n", ty);
    }
    return "Unknown_const_type";
}

char *oper_type_internal(oper_type op)
{
    switch (op)
    {
    case Comma:
        return "Comma";
    case Plus:
        return "Plus";
    case Neg:
        return "Neg";
    case Minus:
        return "Minus";
    case Mult:
        return "Mult";
    case Div:
        return "Div";
    case Mod:
        return "Mod";
    case Index:
        return "Index";
    case Frac:
        return "Frac";
    case Power:
        return "Power";
    case Sqrt:
        return "Sqrt";
    case Sqrt_n:
        return "Sqrt_n";
    case Abs:
        return "Abs";
    case SetSize:
        return "SetSize";
    case Max:
        return "Max";
    case Min:
        return "Min";
    case Sup:
        return "Sup";
    case Inf:
        return "Inf";
    case Ceil:
        return "Ceil";
    case Floor:
        return "Floor";
    case Sin:
        return "Sin";
    case Cos:
        return "Cos";
    case Ln:
        return "Ln";
    case PowerSet:
        return "PowerSet";
    case SetSum:
        return "SetSum";
    case InverseBinRel:
        return "InverseBinRel";
    case GeneralIntersection:
        return "GeneralIntersection";
    case GeneralUnion:
        return "GeneralUnion";
    case IdentityBinRel:
        return "IdentityBinRel";
    case InverseFunc:
        return "InverseFunc";
    case SetMinus:
        return "SetMinus";
    case BinRelComp:
        return "BinRelComp";
    case EquivClass:
        return "EquivClass";
    case PartialFunction:
        return "PartialFunction";
    case CartesianProd:
        return "CartesianProd";
    case Deri:
        return "Deri";
    case Lim:
        return "Lim";
    case SetConstruction:
        return "SetConstruction";
    case SetUnion:
        return "SetUnion";
    case SetIntersection:
        return "SetIntersection";
    case SetComplement:
        return "SetComplement";
    case Composition:
        return "Composition";
    case Bar:
        return "Bar";
    case Vec:
        return "Vec";
    case Colon:
        return "Colon";
    case BigSum:
        return "BigSum";
    case BigSum_only_index:
        return "BigSum_only_index";
    case BigSum_limits:
        return "BigSum_limits";
    case BigProd:
        return "BigProd";
    case BigProd_only_index:
        return "BigProd_only_index";
    case BigProd_limits:
        return "BigProd_limits";
    case Set_enum:
        return "Set_enum";
    case Set_build:
        return "Set_build";
    case Set_replace:
        return "Set_replace";
    case Tuple:
        return "Tuple";
    case Interval_lopen_ropen:
        return "Interval_lopen_ropen";
    case Interval_lclosed_ropen:
        return "Interval_lclosed_ropen";
    case Interval_lopen_rclosed:
        return "Interval_lopen_rclosed";
    case Interval_lclosed_rclosed:
        return "Interval_lclosed_rclosed";
    default:
        fprintf(stderr, "Error: unknown oper_type (id : %d).\n", op);
    }
    return "Unknown_oper_type";
}

char *binder_type_internal(binder_type bt)
{
    switch (bt)
    {
    case Lambda:
        return "Lambda";
    case Limit:
        return "Limit";
    default:
        fprintf(stderr, "Error: unknown binder_type (id : %d).\n", bt);
    }
    return "Unknown_binder_type";
}

char *pred_type_internal(pred_type pt)
{
    switch (pt)
    {
    case Eq:
        return "Eq";
    case Neq:
        return "Neq";
    case Le:
        return "Le";
    case Ge:
        return "Ge";
    case Lt:
        return "Lt";
    case Gt:
        return "Gt";
    case Belong:
        return "Belong";
    case Subset:
        return "Subset";
    case SubsetNeq:
        return "SubsetNeq";
    case Continue:
        return "Continue";
    case UContinue:
        return "UContinue";
    case ContinueOn:
        return "ContinueOn";
    case UContinueOn:
        return "UContinueOn";
    case Bounded:
        return "Bounded";
    case BoundedAbove:
        return "BoundedAbove";
    case BoundedBelow:
        return "BoundedBelow";
    case BoundedAboveBy:
        return "BoundedAboveBy";
    case BoundedBelowBy:
        return "BoundedBelowBy";
    case CountableSet:
        return "CountableSet";
    case UncountableSet:
        return "UncountableSet";
    case ReflexiveBinRel:
        return "ReflexiveBinRel";
    case SymmetricBinRel:
        return "SymmetricBinRel";
    case AntisymmetricBinRel:
        return "AntisymmetricBinRel";
    case TransitiveBinRel:
        return "TransitiveBinRel";
    case EquivalenceBinRel:
        return "EquivalenceBinRel";
    case PreOrderBinRel:
        return "PreOrderBinRel";
    case PartialOrderBinRel:
        return "PartialOrderBinRel";
    case IsFunction:
        return "IsFunction";
    case SetPartition:
        return "SetPartition";
    case Equinumerous:
        return "Equinumerous";
    case RelTransClosure:
        return "RelTransClosure";
    case TransitiveClosure:
        return "TransitiveClosure";
    case PartitionRefine:
        return "PartitionRefine";
    case HasInjection:
        return "HasInjection";
    case MonoInc:
        return "MonoInc";
    case MonoDec:
        return "MonoDec";
    case SMonoInc:
        return "SMonoInc";
    case SMonoDec:
        return "SMonoDec";
    case Convergent:
        return "Convergent";
    case Divergent:
        return "Divergent";
    case SeqHasLimit:
        return "SeqHasLimit";
    case TendsTo:
        return "TendsTo";
    default:
        fprintf(stderr, "Error: unknown pred_type (id : %d).\n", pt);
    }
    return "Unknown_pred_type";
}

char *connect_type_internal(connect_type ct)
{
    switch (ct)
    {
    case Not:
        return "Not";
    case And:
        return "And";
    case Or:
        return "Or";
    case Impl:
        return "Impl";
    case Iff:
        return "Iff";
    default:
        fprintf(stderr, "Error, unknown connect_type (id : %d).\n", ct);
    }
    return "Unknown_connect_type";
}

char *quant_type_internal(quant_type qt)
{
    switch (qt)
    {
    case Forall:
        return "Forall";
    case Exists:
        return "Exists";
    default:
        fprintf(stderr, "Error: unknown quant_type (id : %d).\n", qt);
    }
    return "Unknown_quant_type";
}

void print_term_internal(term *tm, FILE *fp)
{
    if (tm == NULL)
    {
        fprintf(stderr, "%s:%d: error: print_term_internal visiting NULL.\n", __FILE__, __LINE__);
        exit(1);
    }

    switch (tm->type)
    {
    case Var:
        fprintf(fp, "(Var %s)", tm->content.Var);
        break;
    case TermVar:
        fprintf(fp, "(TermVar %s)", tm->content.Var);
        break;
    case Const:
        fprintf(fp, "(Const %s", const_type_internal(tm->content.Const.type));
        if (tm->content.Const.type == Num)
            fprintf(fp, " %d", tm->content.Const.content);
        fprintf(fp, ")");
        break;
    case Oper:
        fprintf(fp, "(Oper %s)", oper_type_internal(tm->content.Oper));
        break;
    case Apply:
        fprintf(fp, "(Apply ");
        print_term_internal(tm->content.Apply.left, fp);
        fprintf(fp, " ");
        print_term_internal(tm->content.Apply.right, fp);
        fprintf(fp, ")");
        break;
    case Binder:
        fprintf(fp, "(Binder %s %s ", binder_type_internal(tm->content.Binder.binder_type),
                tm->content.Binder.binder_var);
        print_term_internal(tm->content.Binder.body, fp);
        fprintf(fp, ")");
        break;
    case Pred:
        fprintf(fp, "(Pred %s)", pred_type_internal(tm->content.Pred));
        break;
    case Connect:
        fprintf(fp, "(Connect %s)", connect_type_internal(tm->content.Connect));
        break;
    case Quant:
        fprintf(fp, "(Quant %s %s ", quant_type_internal(tm->content.Quant.type), tm->content.Quant.var);
        print_term_internal(tm->content.Quant.body, fp);
        fprintf(fp, ")");
        break;
    case RawQuant:
        fprintf(fp, "(RawQuant %s ", quant_type_internal(tm->content.RawQuant.type));
        print_term_internal(tm->content.RawQuant.raw_var, fp);
        fprintf(fp, " ");
        print_term_internal(tm->content.RawQuant.body, fp);
        fprintf(fp, ")");
        break;
    case TermList:
        if (tm->content.TermList == NULL)
            fprintf(fp, "TermList ()");
        else
        {
            fprintf(fp, "(TermList (");
            print_term_list_internal(tm, fp);
            fprintf(fp, "))");
        }
        break;
    }
}

void print_forward(forward *fwd, FILE *fp)
{
    if (fwd == NULL)
    {
        fprintf(stderr, "Error: print_forward visiting NULL.\n");
        exit(1);
    }

    int_list *tmp;
    switch (fwd->type)
    {
    case FNoHint:
        fprintf(fp, "FNoHint");
        break;
    case Knowledge:
        fprintf(fp, "(Knowledge \"%s\")", fwd->content.knowledge);
        break;
    case Inference:
        fprintf(fp, "(Inference ");
        print_term(fwd->content.evidence, fp);
        fprintf(fp, ")");
        break;
    case Same:
        fprintf(fp, "Same");
        break;
    case AddEqn:
        fprintf(fp, "(AddEqn");
        if (fwd->content.equ_list == NULL || fwd->content.equ_list->next == NULL)
        {
            fprintf(stderr, "Error: print_forward visiting bad equ_list length in AddEqn.\n");
            exit(1);
        }
        tmp = fwd->content.equ_list;
        while (tmp != NULL)
        {
            fprintf(fp, " [%d]", tmp->element);
            tmp = tmp->next;
        }
        fprintf(fp, ")");
        break;
    case SubEqn:
        fprintf(fp, "(SubEqn");
        if (fwd->content.equ_list == NULL || fwd->content.equ_list->next == NULL ||
            fwd->content.equ_list->next->next != NULL)
        {
            fprintf(stderr, "Error: print_forward visiting bad equ_list length in SubEqn.\n");
            exit(1);
        }
        tmp = fwd->content.equ_list;
        while (tmp != NULL)
        {
            fprintf(fp, " [%d]", tmp->element);
            tmp = tmp->next;
        }
        fprintf(fp, ")");
        break;
    case EquTrans:
        fprintf(fp, "(EqnTrans [%d])", fwd->content.equ);
        break;
    case DeriBothTerms:
        if (fwd->content.var != NULL)
            fprintf(fp, "(DeriBothTerms %s)", fwd->content.var);
        else
            fprintf(fp, "DeriBothTerms");
        break;
    case TakeLimOnBothTerms:
        if (fwd->content.var != NULL)
            fprintf(fp, "(TakeLimOnBothTerms %s)", fwd->content.var);
        else
            fprintf(fp, "TakeLimOnBothTerms");
        break;
    case SquareBothTerms:
        fprintf(fp, "SquareBothTerms");
        break;
    }
}

void print_forward_internal(forward *fwd, FILE *fp)
{
    if (fwd == NULL)
    {
        fprintf(stderr, "Error: print_forward_internal visiting NULL.\n");
        exit(1);
    }

    int_list *tmp;
    switch (fwd->type)
    {
    case FNoHint:
        fprintf(fp, "FNoHint");
        break;
    case Knowledge:
        fprintf(fp, "(Knowledge \"%s\")", fwd->content.knowledge);
        break;
    case Inference:
        fprintf(fp, "(Inference ");
        print_term_internal(fwd->content.evidence, fp);
        fprintf(fp, ")");
        break;
    case Same:
        fprintf(fp, "Same");
        break;
    case AddEqn:
        fprintf(fp, "(AddEqn");
        if (fwd->content.equ_list == NULL || fwd->content.equ_list->next == NULL)
        {
            fprintf(stderr, "Error: print_forward_internal visiting bad equ_list length in AddEqn.\n");
            exit(1);
        }
        tmp = fwd->content.equ_list;
        while (tmp != NULL)
        {
            fprintf(fp, " [%d]", tmp->element);
            tmp = tmp->next;
        }
        fprintf(fp, ")");
        break;
    case SubEqn:
        fprintf(fp, "(SubEqn");
        if (fwd->content.equ_list == NULL || fwd->content.equ_list->next == NULL ||
            fwd->content.equ_list->next->next != NULL)
        {
            fprintf(stderr, "Error: print_forward_internal visiting bad equ_list length in SubEqn.\n");
            exit(1);
        }
        tmp = fwd->content.equ_list;
        while (tmp != NULL)
        {
            fprintf(fp, " [%d]", tmp->element);
            tmp = tmp->next;
        }
        fprintf(fp, ")");
        break;
    case EquTrans:
        fprintf(fp, "(EqnTrans [%d])", fwd->content.equ);
        break;
    case DeriBothTerms:
        if (fwd->content.var != NULL)
            fprintf(fp, "(DeriBothTerms %s)", fwd->content.var);
        else
            fprintf(fp, "DeriBothTerms");
        break;
    case TakeLimOnBothTerms:
        if (fwd->content.var != NULL)
            fprintf(fp, "(TakeLimOnBothTerms %s)", fwd->content.var);
        else
            fprintf(fp, "TakeLimOnBothTerms");
        break;
    case SquareBothTerms:
        fprintf(fp, "SquareBothTerms");
        break;
    }
}

void print_backward(backward *bwd, FILE *fp)
{
    if (bwd == NULL)
    {
        fprintf(stderr, "Error: print_backward visiting NULL.\n");
        exit(1);
    }

    switch (bwd->type)
    {
    case BNoHint:
        fprintf(fp, "BNoHint");
        break;
    case Contra:
        fprintf(fp, "Contra");
        break;
    }
}

void print_backward_internal(backward *bwd, FILE *fp)
{
    if (bwd == NULL)
    {
        fprintf(stderr, "Error: print_backward_internal visiting NULL.\n");
        exit(1);
    }

    switch (bwd->type)
    {
    case BNoHint:
        fprintf(fp, "BNoHint");
        break;
    case Contra:
        fprintf(fp, "Contra");
        break;
    }
}

void print_action(action *act, FILE *fp)
{
    if (act == NULL)
    {
        fprintf(stderr, "Error: print_action visiting NULL.\n");
        exit(1);
    }

    switch (act->type)
    {
    case IntroVar:
        if (act->content.intro_var == NULL)
        {
            fprintf(stderr, "Error: print_action visiting NULL in IntroVar.\n");
            exit(1);
        }
        fprintf(fp, "(IntroVar %s)", act->content.intro_var);
        break;
    case IntroTerm:
        if (act->content.intro_term == NULL)
        {
            fprintf(stderr, "Error: print_action visiting NULL in IntroTerm.\n");
            exit(1);
        }
        fprintf(fp, "(IntroTerm ");
        print_term(act->content.intro_term, fp);
        fprintf(fp, ")");
        break;
    case IntroTermWithProp:
        if (act->content.intro_term_with_prop == NULL)
        {
            fprintf(stderr, "Error: print_action visiting NULL in IntroTermWithProp.\n");
            exit(1);
        }
        fprintf(fp, "(IntroTermWithProp ");
        print_term(act->content.intro_term_with_prop[0], fp);
        fprintf(fp, " ");
        print_term(act->content.intro_term_with_prop[1], fp);
        fprintf(fp, ")");
        break;
    case Suppose:
        if (act->content.suppose_term == NULL)
        {
            fprintf(stderr, "Error: print_action visiting NULL in Suppose.\n");
            exit(1);
        }
        fprintf(fp, "(Suppose ");
        print_term(act->content.suppose_term, fp);
        fprintf(fp, ")");
        break;
    case Set:
        if (act->content.set_term == NULL)
        {
            fprintf(stderr, "Error: print_action visiting NULL in Set.\n");
            exit(1);
        }
        fprintf(fp, "(Set ");
        print_term(act->content.set_term, fp);
        fprintf(fp, ")");
        break;
    case ExistsVar:
        if (act->content.exists_var == NULL)
        {
            fprintf(stderr, "Error: print_action visiting NULL in ExistsVar.\n");
            exit(1);
        }
        fprintf(fp, "(ExistsVar %s)", act->content.exists_var);
        break;
    }
}

void print_action_internal(action *act, FILE *fp)
{
    if (act == NULL)
    {
        fprintf(stderr, "Error: print_action visiting NULL.\n");
        exit(1);
    }

    switch (act->type)
    {
    case IntroVar:
        if (act->content.intro_var == NULL)
        {
            fprintf(stderr, "Error: print_action visiting NULL in IntroVar.\n");
            exit(1);
        }
        fprintf(fp, "(IntroVar %s)", act->content.intro_var);
        break;
    case IntroTerm:
        if (act->content.intro_term == NULL)
        {
            fprintf(stderr, "Error: print_action visiting NULL in IntroTerm.\n");
            exit(1);
        }
        fprintf(fp, "(IntroTerm ");
        print_term_internal(act->content.intro_term, fp);
        fprintf(fp, ")");
        break;
    case IntroTermWithProp:
        if (act->content.intro_term_with_prop == NULL)
        {
            fprintf(stderr, "Error: print_action visiting NULL in IntroTermWithProp.\n");
            exit(1);
        }
        fprintf(fp, "(IntroTermWithProp ");
        print_term_internal(act->content.intro_term_with_prop[0], fp);
        fprintf(fp, " ");
        print_term_internal(act->content.intro_term_with_prop[1], fp);
        fprintf(fp, ")");
        break;
    case Suppose:
        if (act->content.suppose_term == NULL)
        {
            fprintf(stderr, "Error: print_action visiting NULL in Suppose.\n");
            exit(1);
        }
        fprintf(fp, "(Suppose ");
        print_term_internal(act->content.suppose_term, fp);
        fprintf(fp, ")");
        break;
    case Set:
        if (act->content.set_term == NULL)
        {
            fprintf(stderr, "Error: print_action visiting NULL in Set.\n");
            exit(1);
        }
        fprintf(fp, "(Set ");
        print_term_internal(act->content.set_term, fp);
        fprintf(fp, ")");
        break;
    case ExistsVar:
        if (act->content.exists_var == NULL)
        {
            fprintf(stderr, "Error: print_action visiting NULL in ExistsVar.\n");
            exit(1);
        }
        fprintf(fp, "(ExistsVar %s)", act->content.exists_var);
        break;
    }
}

void print_proof_indent(proof *p, FILE *fp, int idt)
{
    struct term *t = NULL;
    if (p == NULL)
    {
        printf("Error: print_proof_indent visiting NULL\n");
        return;
    }
    for(int i = 0; i < idt; ++i) fprintf(fp, "\t");
    if (p->type == PoseWithoutProof)
    {
        if (p->content.PoseWithoutProof.fwd->type == FNoHint)
        {
            fprintf(fp, "我们有 ");
        }
        else if (p->content.PoseWithoutProof.fwd->type == Inference)
        {
            t = p->content.PoseWithoutProof.fwd->content.evidence;
            fprintf(fp, "根据 (");
            print_term(t, fp);
            fprintf(fp, ") 可知 ");
        }
        else if (p->content.PoseWithoutProof.fwd->type == Knowledge)
        {
            fprintf(fp, "根据 \"%s\" 可知 ", p->content.PoseWithoutProof.fwd->content.knowledge);
        }
        else if (p->content.PoseWithoutProof.fwd->type == Same)
        {
            fprintf(fp, "同理 可得 ");
        }
        else if (p->content.PoseWithoutProof.fwd->type == EquTrans)
        {
            fprintf(fp, "根据 [%d] 变形 可得 ", p->content.PoseWithoutProof.fwd->content.equ);
        }
        else if (p->content.PoseWithoutProof.fwd->type == SquareBothTerms)
        {
            fprintf(fp, "等式两边同时 平方 可得 ");
        }
        else if (p->content.PoseWithoutProof.fwd->type == DeriBothTerms)
        {
            fprintf(fp, "等式两边同时 ");
            if (strlen(p->content.PoseWithoutProof.fwd->content.var) > 0)
            {
                fprintf(fp, "对 %s ", p->content.PoseWithoutProof.fwd->content.var);
            }
            fprintf(fp, "求导 可得 ");
        }
        else if (p->content.PoseWithoutProof.fwd->type == AddEqn)
        {
            int_list *tmp = p->content.PoseWithoutProof.fwd->content.equ_list;
            while (tmp != NULL)
            {
                fprintf(fp, "[%d] ", tmp->element);
                tmp = tmp->next;
            }
            fprintf(fp, "式相加 可得 ");
        }

        t = p->content.PoseWithoutProof.curr_term;
        print_term(t, fp);
        fprintf(fp, " ,\n");
        print_proof_indent(p->content.PoseWithoutProof.next_proof, fp, idt);
        return;
    }
    else if (p->type == PoseAndProve)
    {
        if (p->content.PoseAndProve.fwd->type == FNoHint)
        {
            t = p->content.PoseAndProve.curr_term;
            fprintf(fp, "下面证明 (");
            print_term(t, fp);
            fprintf(fp, ")\n");
        }
        else if (p->content.PoseAndProve.fwd->type == Knowledge)
        {
            t = p->content.PoseAndProve.curr_term;
            fprintf(fp, "使用 \"%s\" 证明 ", p->content.PoseAndProve.fwd->content.knowledge);
            fprintf(fp, "(");
            print_term(t, fp);
            fprintf(fp, ")\n");
        }
        for(int i = 0; i < idt; ++i) fprintf(fp, "\t");
        fprintf(fp, "{\n");
        print_proof_indent(p->content.PoseAndProve.curr_proof, fp, idt+1);
        fprintf(fp, "\b");
        for(int i = 0; i < idt; ++i) fprintf(fp, "\t");
        fprintf(fp, "}\n");
        print_proof_indent(p->content.PoseAndProve.next_proof, fp, idt);
        return;
    }
    
    else if (p->type == PoseInduction)
    {
        if (p->content.PoseInduction.fwd->type == FNoHint)
        {
            t = p->content.PoseInduction.curr_term;
            fprintf(fp, "对 %s 用归纳法证明 (", p->content.PoseInduction.induct_var);
            print_term(p->content.PoseInduction.curr_term, fp);
            fprintf(fp, ")\n");
        }
        for(int i = 0; i < idt; ++i) fprintf(fp, "\t");
        fprintf(fp, "{\n");
        print_proof_indent(p->content.PoseInduction.curr_proof, fp, idt+1);
        fprintf(fp, "\b");
        for(int i = 0; i < idt; ++i) fprintf(fp, "\t");
        fprintf(fp, "}\n");
        print_proof_indent(p->content.PoseInduction.next_proof, fp, idt);
        return;
    }
    else if (p->type == ConclWithoutProof)
    {
        if (p->content.ConclWithoutProof.fwd->type == FNoHint)
        {
            fprintf(fp, "证毕.\n");
        }
        else if (p->content.ConclWithoutProof.fwd->type == Inference)
        {
            t = p->content.ConclWithoutProof.fwd->content.evidence;
            fprintf(fp, "根据 \n");
            print_term(t, fp);
            fprintf(fp, ", 证毕.\n");
        }
    }
    else if (p->type == ConclAndProve)
    {
        fprintf(fp, "使用 %s 证明 ,\n", p->content.PoseAndProve.fwd->content.knowledge);
        print_proof_indent(p->content.ConclAndProve.curr_proof, fp, idt);
    }
    else if (p->type == ClaimSuffice)
    {
        t = p->content.ClaimSuffice.curr_term;
        fprintf(fp, "只需证 (");
        print_term(t, fp);
        fprintf(fp, ") ,\n");
        print_proof_indent(p->content.ClaimSuffice.next_proof, fp, idt);
    }
    else if (p->type == ProveSuffice)
    {
        t = p->content.ClaimSuffice.curr_term;
        fprintf(fp, "只需证 (");
        print_term(t, fp);
        fprintf(fp, ")\n");
        for(int i = 0; i < idt; ++i) fprintf(fp, "\t");
        fprintf(fp, "{\n");
        print_proof_indent(p->content.ProveSuffice.curr_proof, fp, idt+1);
        fprintf(fp, "\r");
        for(int i = 0; i < idt; ++i) fprintf(fp, "\t");
        fprintf(fp, "}\n");
        print_proof_indent(p->content.ProveSuffice.next_proof, fp, idt);
    }
    else if (p->type == Action)
    {
        int cur_action = p->content.Action.act->type;
        if (cur_action == IntroVar)
        {
            fprintf(fp, "取 (%s),\n", p->content.Action.act->content.intro_var);
        }
        else if (cur_action == IntroTerm)
        {
            t = p->content.Action.act->content.intro_term;
            fprintf(fp, "取 ");
            print_term_list(t, fp);
            fprintf(fp, " ,\n");
        }
        else if (cur_action == IntroTermWithProp)
        {
            fprintf(fp, "对于任意 ");
            print_term_list(p->content.Action.act->content.intro_term_with_prop[0], fp);
            fprintf(fp, " 满足 (");
            print_term(p->content.Action.act->content.intro_term_with_prop[1], fp);
            fprintf(fp, ") ,\n");
        }
        else if (cur_action == Suppose)
        {
            t = p->content.Action.act->content.suppose_term;
            fprintf(fp, "设 (");
            print_term(t, fp);
            fprintf(fp, ") ,\n");
        }
        else if (cur_action == Set)
        {
            t = p->content.Action.act->content.suppose_term;
            fprintf(fp, "令 (");
            print_term(t, fp);
            fprintf(fp, ") ,\n");
        }
        else if (cur_action == ExistsVar)
        {
            fprintf(fp, "给定 (%s) ,\n", p->content.Action.act->content.exists_var);
        }
        print_proof_indent(p->content.Action.next_proof, fp, idt);
    }
    else if (p->type == PosePartialProof)
    {
        int cur_type = p->content.PosePartialProof.act->type;
        if (cur_type == IntroVar)
        {
            fprintf(fp, "取 (%s)\n", p->content.Action.act->content.intro_var);
        }
        else if (cur_type == IntroTerm)
        {
            t = p->content.Action.act->content.intro_term;
            fprintf(fp, "取 ");
            print_term_list(t, fp);
            fprintf(fp, "\n");
        }
        else if (cur_type == IntroTermWithProp)
        {
            fprintf(fp, "对于任意 ");
            print_term_list(p->content.Action.act->content.intro_term_with_prop[0], fp);
            fprintf(fp, " 满足 (");
            print_term(p->content.Action.act->content.intro_term_with_prop[1], fp);
            fprintf(fp, ")\n");
        }
        else if (cur_type == Suppose)
        {
            t = p->content.Action.act->content.suppose_term;
            fprintf(fp, "设 (");
            print_term(t, fp);
            fprintf(fp, ")\n");
        }
        else if (cur_type == Set)
        {
            t = p->content.Action.act->content.suppose_term;
            fprintf(fp, "令 (");
            print_term(t, fp);
            fprintf(fp, ")\n");
        }
        // fprintf(fp,"idt = %d\n",idt);
        for(int i = 0; i < idt; ++i) fprintf(fp, "\t");
        fprintf(fp, "{\n");
        print_proof_indent(p->content.PosePartialProof.curr_proof, fp, idt+1);
        fprintf(fp, "\r");
        for(int i = 0; i < idt; ++i) fprintf(fp, "\t");
        fprintf(fp, "}\n");
        print_proof_indent(p->content.PosePartialProof.next_proof, fp, idt);
    }
}

void print_proof(proof *p, FILE *fp)
{
    print_proof_indent(p, fp, 0);
}

void print_proof_internal(proof *pr, FILE *fp)
{
    if (pr == NULL)
    {
        printf("Error: print_proof_internal visiting NULL.\n");
        exit(1);
    }

    switch (pr->type)
    {
    case PoseWithoutProof:
        fprintf(fp, "(PoseWithoutProof ");
        print_forward_internal(pr->content.PoseWithoutProof.fwd, fp);
        fprintf(fp, "\n\t");
        print_term_internal(pr->content.PoseWithoutProof.curr_term, fp);
        fprintf(fp, "\n");
        print_proof_internal(pr->content.PoseWithoutProof.next_proof, fp);
        fprintf(fp, ")");
        break;
    case PoseAndProve:
        fprintf(fp, "(PoseAndProve ");
        print_forward_internal(pr->content.PoseAndProve.fwd, fp);
        fprintf(fp, "\n\t");
        print_term_internal(pr->content.PoseAndProve.curr_term, fp);
        fprintf(fp, "\n");
        print_proof_internal(pr->content.PoseAndProve.curr_proof, fp);
        fprintf(fp, "\n");
        print_proof_internal(pr->content.PoseAndProve.next_proof, fp);
        fprintf(fp, ")");
        break;
    case PoseInduction:
        fprintf(fp, "(PoseInduction ");
        print_forward_internal(pr->content.PoseInduction.fwd, fp);
        fprintf(fp, "\n\t%s\n",pr->content.PoseInduction.induct_var);
        print_term_internal(pr->content.PoseInduction.curr_term, fp);
        fprintf(fp, "\n");
        print_proof_internal(pr->content.PoseInduction.curr_proof, fp);
        fprintf(fp, "\n");
        print_proof_internal(pr->content.PoseInduction.next_proof, fp);
        fprintf(fp, ")");
        break;
    case ConclWithoutProof:
        fprintf(fp, "(ConclWithoutProof ");
        print_forward_internal(pr->content.ConclWithoutProof.fwd, fp);
        fprintf(fp, ")");
        break;
    case ConclAndProve:
        fprintf(fp, "(ConclAndProve ");
        print_forward_internal(pr->content.ConclWithoutProof.fwd, fp);
        fprintf(fp, "\n");
        print_proof_internal(pr->content.ConclAndProve.curr_proof, fp);
        fprintf(fp, ")");
        break;
    case ClaimSuffice:
        fprintf(fp, "(ClaimSuffice ");
        print_backward_internal(pr->content.ClaimSuffice.bwd, fp);
        fprintf(fp, "\n\t");
        print_term_internal(pr->content.ClaimSuffice.curr_term, fp);
        fprintf(fp, "\n");
        print_proof_internal(pr->content.ClaimSuffice.next_proof, fp);
        fprintf(fp, ")");
        break;
    case ProveSuffice:
        fprintf(fp, "(ProveSuffice ");
        print_backward_internal(pr->content.ProveSuffice.bwd, fp);
        fprintf(fp, "\n\t");
        print_term_internal(pr->content.ProveSuffice.curr_term, fp);
        fprintf(fp, "\n");
        print_proof_internal(pr->content.ProveSuffice.curr_proof, fp);
        fprintf(fp, "\n");
        print_proof_internal(pr->content.ProveSuffice.next_proof, fp);
        fprintf(fp, ")");
    case Action:
        fprintf(fp, "(Action ");
        print_action_internal(pr->content.Action.act, fp);
        fprintf(fp, "\n");
        print_proof_internal(pr->content.Action.next_proof, fp);
        fprintf(fp, ")");
        break;
    case PosePartialProof:
        fprintf(fp, "(PosePartialProof ");
        print_action_internal(pr->content.PosePartialProof.act, fp);
        fprintf(fp, "\n");
        print_proof_internal(pr->content.PosePartialProof.curr_proof, fp);
        fprintf(fp, "\n");
        print_proof_internal(pr->content.PosePartialProof.next_proof, fp);
        fprintf(fp, ")");
        break;
    case EndPartialProof:
        fprintf(fp, "EndPartialProof");
        break;
    }
}

term *combine_assus_concl(assu_list *assus, term *concl)
{
    if (assus == NULL)
        return copy_term(concl);
    term *tmp1 = (term *)calloc(1, sizeof(term));
    term *tmp2 = (term *)calloc(1, sizeof(term));
    term *tmp3 = (term *)calloc(1, sizeof(term));
    term *tmp4 = combine_assus_concl(assus->next, concl);
    tmp3->type = Connect;
    tmp3->content.Connect = Impl;
    tmp2->type = Apply;
    tmp2->content.Apply.left = tmp3;
    tmp2->content.Apply.right = copy_term(assus->assu);
    tmp1->type = Apply;
    tmp1->content.Apply.left = tmp2;
    tmp1->content.Apply.right = tmp4;
    return tmp1;
}

void print_proof_goal(proof_goal *pg, FILE *fp)
{
    if (pg == NULL)
    {
        fprintf(stderr, "Error: print_proof_goal visiting NULL.\n");
        exit(1);
    }

    fprintf(fp, "要证:\n");
    term *combined = combine_assus_concl(pg->assus, pg->concl);
    print_term(combined, fp);
    fprintf(fp, "\n");
    free_term(combined);
}

void print_proof_goal_internal(proof_goal *pg, FILE *fp)
{
    if (pg == NULL)
    {
        fprintf(stderr, "Error: print_proof_goal_internal visiting NULL.\n");
        exit(1);
    }

    fprintf(fp, "GOAL:\n");
    term *combined = combine_assus_concl(pg->assus, pg->concl);
    print_term_internal(combined, fp);
    fprintf(fp, "\n");
    free_term(combined);
}

void print_program(program *pr, FILE *fp)
{
    if (pr == NULL)
    {
        fprintf(stderr, "Error: print_program visiting NULL.\n");
        exit(1);
    }

    print_proof_goal(pr->pg, fp);
    fprintf(fp, "\n证明:\n");
    print_proof(pr->pr, fp);
    fprintf(fp, "\n");
}

void print_program_internal(program *pr, FILE *fp)
{
    if (pr == NULL)
    {
        fprintf(stderr, "Error: print_program_internal visiting NULL.\n");
        exit(1);
    }

    print_proof_goal_internal(pr->pg, fp);
    fprintf(fp, "\nPROOF:\n");
    print_proof_internal(pr->pr, fp);
    fprintf(fp, "\n");
}
