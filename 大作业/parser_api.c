#include "ast.h"
#include "parser.h"
#include "lexer.h"

extern int yyparse(yyscan_t scanner, parser_mode *pm);

term *parse_term(char *input_filename, FILE *input_file, int verbose_debug, int debug)
{
    term *tm = NULL;
    lexer_mode lm = {START_TERM, debug, 0, input_filename};
    parser_mode pm = {.tm = &tm, debug, 0, input_filename};

    yyscan_t scanner;
    yylex_init(&scanner);
    yyset_in(input_file, scanner);
    yyset_extra(&lm, scanner);
    if (yydebug == verbose_debug)
        yyset_debug(verbose_debug, scanner);

    int parse_result = yyparse(scanner, &pm);
    yylex_destroy(scanner);
    if (parse_result != 0)
    {
        fprintf(stderr, "Parsing failed with code %d.\n", parse_result);
        exit(1);
    }
    else
        fprintf(stderr, "Parsing succeeded.\n");
    return tm;
}

term *parse_term_from_str(char *src, int verbose_debug, int debug) {
    term *tm = NULL;
    lexer_mode lm = {START_TERM, debug, 1, src};
    parser_mode pm = {.tm = &tm, debug, 1, src};

    yyscan_t scanner;
    yylex_init(&scanner);
    yyset_extra(&lm, scanner);
    YY_BUFFER_STATE buffer = yy_scan_string(src, scanner);
    if (yydebug == verbose_debug)
        yyset_debug(verbose_debug, scanner);

    int parse_result = yyparse(scanner, &pm);
    yylex_destroy(scanner);
    if (parse_result != 0)
    {
        fprintf(stderr, "Parsing failed with code %d.\n", parse_result);
        exit(1);
    }
    else
        fprintf(stderr, "Parsing succeeded.\n");
    return tm;
}

program *parse_program(char *input_filename, FILE *input_file, int verbose_debug, int debug)
{
    program *pr = NULL;
    lexer_mode lm = {START_PROGRAM, debug, 0, input_filename};
    parser_mode pm = {.pr = &pr, debug, 0, input_filename};

    yyscan_t scanner;
    yylex_init(&scanner);
    yyset_in(input_file, scanner);
    yyset_extra(&lm, scanner);
    if (yydebug == verbose_debug)
        yyset_debug(verbose_debug, scanner);

    int parse_result = yyparse(scanner, &pm);
    yylex_destroy(scanner);

    if (parse_result != 0)
    {
        fprintf(stderr, "Parsing failed with code %d.\n", parse_result);
        FILE *result_file = fopen("parse_result.txt", "w");
        fprintf(result_file, "0");
        fclose(result_file);
        exit(1);
    }
    else{
        fprintf(stderr, "Parsing succeeded.\n");
        FILE *result_file = fopen("parse_result.txt", "w");
        fprintf(result_file, "1");
        fclose(result_file);
    }
    return pr;
}

program *parse_program_from_str(char *src, int verbose_debug, int debug)
{
    program *pr = NULL;
    lexer_mode lm = {START_PROGRAM, debug, 1, src};
    parser_mode pm = {.pr = &pr, debug, 1, src};

    yyscan_t scanner;
    yylex_init(&scanner);
    yyset_extra(&lm, scanner);
    YY_BUFFER_STATE buffer = yy_scan_string(src, scanner);
    if (yydebug == verbose_debug)
        yyset_debug(verbose_debug, scanner);

    int parse_result = yyparse(scanner, &pm);
    yylex_destroy(scanner);
    if (parse_result != 0)
    {
        fprintf(stderr, "Parsing failed with code %d.\n", parse_result);
        exit(1);
    }
    else
        fprintf(stderr, "Parsing succeeded.\n");
    return pr;
}
