#ifndef PARSER_API_H
#define PARSER_API_H

#include "ast.h"

term *parse_term(char *inpufile_name, FILE *input_file, int verbose_debug, int debug);
term *parse_term_from_str(char *src, int verbose_debug, int debug);

#endif
