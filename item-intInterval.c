#include <stdio.h>
#include <stdlib.h>

Item itemScan(void) {
	Item item = malloc(sizeof(*item));
	printf("low = ");
	scanf("%d", &item->low);
	printf("high = ");
	scanf("%d", &item->high);
	return item;
}

void itemPrint(Item item) {
	printf("[%d, %d] ", item->low, item->high);
}

Item itemSetVoid(void) {
	Item item = malloc(sizeof(*item));
	item->low = -1;
	item->high = -1;
	return item;
}

int itemLow(Item item) {
	return item->low;
}

int itemHigh(Item item) {
	return item->high;
}

int itemOverlap(Item item1, Item item2) {
	if(item1->low <= item2->high && item1->high >= item2->low) {
		return 1;
	}
	return 0;
}

int intvEqual(Item item1, Item item2) {
	if(item1->low == item2->low && item1->high == item2->high) {
		return 1;
	}
	return 0;
}

int intvCheckVoid(Item item) {
	if(item->low = -1 && item->high == -1) {
		return 1;
	}
	return 0;
}

int keyGet(Item item) {
	return item->low;
}

int keyCompare(int low1, int low2) {
	if(low1 == low2) {
		return 0;
	}
	if(low1 < low2) {
		return -1;
	}
	return 1;
}

void itemFree(Item item) {
	free(item);
	return;
}
