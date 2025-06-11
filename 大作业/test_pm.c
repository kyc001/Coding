
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"

#include "parser_api.h"
#include "pattern_match.h"

#include <stdarg.h>

//pattern match的match函数使用前需要初始化执行match init
// match函数是一个可变参数函数，第一函数是待匹配的term，第二个参数是匹配的模式，后面的参数存储匹配的结果
//在匹配模式中，用？来代表term，用?BinPred表示二元谓词，诸如此类还有?UnaryPred
//下面是一个使用示例

int main(int argc, char *argv[])
{
    match_init();
    term *tm = parse_term_from_str("C ∈ A ∩ B", 0, 0);
    term* a, *b, *c;
    if (match(tm, "?BinaryPred(?, ?)", &a, &b, &c) == MATCH_FAILURE) {
        exit(1);
    }
    //这里a会匹配上二元谓词∈，b会匹配上C， c会匹配上A ∩ B
    print_term_internal(a, stdout);
    print_term_internal(b, stdout);
    print_term_internal(c, stdout);
    //print_term_internal(d, stdout);
    return 0;
}
