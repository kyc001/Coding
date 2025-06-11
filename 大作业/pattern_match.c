#include <assert.h>
#include <stdarg.h>

#include "ast.h"
#include "hashtable.h"
#include "parser_api.h"
#include "pattern_match.h"

struct plist
{
    term **element;
    struct plist *next;
};

typedef struct plist plist;

Hash_Table *htable = NULL;

void match_init() {
    htable = creat_hash_table();
}

int match_ast (term *tm, term *pattern_ast, plist *list) {
    int res;
    switch (pattern_ast->type) {
    case Pattern:
        switch (pattern_ast->content.Pattern) {
        case PatternWildCard:
            *list->element = tm;
            return 1;
        case PatternVar:
            if (tm->type != Var) return MATCH_FAILURE;
            *list->element = tm;
            return 1;
        case PatternConst:
            if (tm->type != Const) return MATCH_FAILURE;
            *list->element = tm;
            return 1;
        case PatternOper:
            if (tm->type != Oper) return MATCH_FAILURE;
            *list->element = tm;
            return 1;
        case PatternPred:
            if (tm->type != Pred) return MATCH_FAILURE;
            *list->element = tm;
            return 1;
        case PatternTermList:
            if (tm->type != TermList) return MATCH_FAILURE;
            *list->element = tm;
            return 1;
        case PatternIgnore:
            return 0;
        }
    case Var:
    case Const:
    case Oper:
    case Pred:
    case Connect:
        if (term_eqb(tm, pattern_ast) == false) return MATCH_FAILURE;
        return 0;
    case Apply:
        if (tm->type != Apply) return MATCH_FAILURE;
        if ((res = match_ast(tm->content.Apply.left, pattern_ast->content.Apply.left, list)) == MATCH_FAILURE) return MATCH_FAILURE;
        for (int i = 0; i < res; ++i) list = list->next;
        return res + match_ast(tm->content.Apply.right, pattern_ast->content.Apply.right, list);
    case Binder:
        if (tm->type != Binder || tm->content.Binder.binder_type != pattern_ast->content.Binder.binder_type) return MATCH_FAILURE;
        if (strcmp (tm->content.Binder.binder_var, pattern_ast->content.Binder.binder_var) != 0) substr_var(tm->content.Binder.binder_var, pattern_ast->content.Binder.binder_var, pattern_ast);
        return match_ast(tm->content.Binder.body, pattern_ast->content.Binder.body, list);
    case Quant:
        if (tm->type != Quant || tm->content.Quant.type != pattern_ast->content.Quant.type) return MATCH_FAILURE;
        if (strcmp (tm->content.Quant.var, pattern_ast->content.Quant.var) != 0) substr_var(tm->content.Quant.var, pattern_ast->content.Quant.var, pattern_ast);
        return match_ast(tm->content.Quant.body, pattern_ast->content.Quant.body, list);
    case RawQuant:
        assert(false);
    case TermList:
        if (tm->type != TermList) return MATCH_FAILURE;
        term_list *l1 = tm->content.TermList;
        term_list *l2 = pattern_ast->content.TermList;
        int cnt = 0;
        while (l1 != NULL && l2 != NULL) {
            res = match_ast(l1->element, l2->element, list);
            cnt += res;
            while (res--) list = list->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 != NULL || l2 != NULL) return MATCH_FAILURE;
        return cnt;
    }
}

int match(term *tm, char *pattern, ...) {
    term *pattern_ast = get_value_from_hstable(htable, pattern, strlen(pattern));
    if (pattern_ast == NULL) {
        pattern_ast = parse_term_from_str(pattern, 0, 0);
        if (pattern_ast == NULL) assert(false);
        add_node2HashTable(htable, pattern, strlen(pattern), pattern_ast);
    }

    int count = 0;
    for (int i = 0; i < strlen(pattern); ++i)
        if (pattern[i] == '?') count += 1;
    
    va_list list;
    va_start(list, pattern);
    plist *plist = NULL, *tmp = NULL;
    while (count --) {
        if (tmp == NULL) {
            plist = (struct plist *) malloc(sizeof(struct plist));
            plist->element = va_arg(list, term **);
            plist->next = NULL;
            tmp = plist;
        }
        else {
            tmp->next = (struct plist *) malloc(sizeof(struct plist));
            tmp->next->element = va_arg(list, term **);
            tmp->next->next = NULL;
            tmp = tmp->next;
        }
    }
    va_end(list);
    return match_ast(tm, pattern_ast, plist);;
}
