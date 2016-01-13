#ifndef B_H
#define B_H

#include "a.h"

struct TYPE_A;
typedef struct {
    int  b;
    char c;
    struct TYPE_A *a;
} TYPE_B_T;

#endif
