#ifndef PATTERN_MATCH_H
#define PATTERN_MATCH_H

#include "ast.h"

#define MATCH_FAILURE -1

void match_init();

int match(term *tm, char *pattern, ...);

#endif
