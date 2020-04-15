#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getIndex(KEY key) {

	if(key == NULL) {
		return -1;
	}
	return key[0] - 'A';
}

ITEM itemScan() {

	char name[NAME_MAX+1];
	int value;
	ITEM item;

	item = malloc(sizeof(*item));

	printf("name = ");
	scanf("%s", name);
	item->name = strdup(name);

	printf("value = ");
	scanf("%d", &value);
	item->value = value;

	return item;
}

void itemPrint(ITEM item) {
	printf("name = %s\n", item->name);
	printf("value = %d\n", item->value);
}

ITEM itemInit(void) {
	ITEM item = malloc(sizeof(*item));
	item->name = strdup(VOID_KEY);
	item->value = -1;
	return item;
}

void itemFree(ITEM item) {
	if(item == NULL) {
		return;
	}
	if(item->name != NULL) {
		free(item->name);
	}
	free(item);
}

KEY keyScan() {

	char name[NAME_MAX+1];
	KEY key;

	scanf("%s", name);
	key = strdup(name);
	return key;
}

int keyCompare(KEY key1, KEY key2) {
	return strcmp(key1, key2);
}

KEY itemKey(ITEM item) {
	return item->name;
}
