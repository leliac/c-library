#define VOID_KEY -1

typedef int Key;

typedef struct {
	int low;
	int high;
} *Item;

#include "item.h"

int itemHigh(Item);
int itemLow(Item);
int itemOverlap(Item, Item);
int itemLessInt(Item, int);

#include "item-intInterval.c"
