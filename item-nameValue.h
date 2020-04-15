#define NAME_MAX 3
#define VOID_KEY ""

typedef char * KEY;

typedef struct {
        KEY name;
        int value;
} * ITEM;

#include "item.h"
#include "item-nameValue.c"
