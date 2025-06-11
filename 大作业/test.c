#include "parser_api.h"
#include "ast.h"

//你必须实现如下的接口函数
// int solver_poly(term* t);
// int solver_rational(term* t);

int main(){
    
    FILE* file = fopen("../test_example/s1/test1.txt", "r");
    char line[256];
    fgets(line, sizeof(line), file);
    line[strcspn(line, "\n")] = '\0';
    term* t = parse_term_from_str(line, 0, 0);
    print_term(t, stdout);
    printf("\n");
    
}