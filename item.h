void itemPrint(ITEM);
ITEM itemScan(void);
int itemVoid(ITEM);
ITEM itemInit(void);
void itemFree(ITEM);

int itemEqual(ITEM, ITEM);
int itemGreater(ITEM, ITEM);
int itemLess(ITEM, ITEM);
int itemGreaterEqual(ITEM, ITEM);
int itemLessEqual(ITEM, ITEM);
ITEM itemMin(ITEM, ITEM);
ITEM itemMax(ITEM, ITEM);
void itemSwap(ITEM, ITEM);

KEY itemKey(ITEM);
KEY keyScan(void);
int keyCompare(KEY, KEY);
int getIndex(KEY);

#include "item.c"
