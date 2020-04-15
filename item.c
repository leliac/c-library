ITEM itemMin(ITEM item1, ITEM item2) {
        if(itemLess(item1, item2)) {
                return item1;
        }
        return item2;
}

ITEM itemMax(ITEM item1, ITEM item2) {
        if(itemGreater(item1, item2)) {
                return item1;
        }
        return item2;
}

void itemSwap(ITEM item1, ITEM item2) {

        ITEM temp;

        temp = item1;
        item1 = item2;
        item2 = temp;

        return;
}
int itemEqual(ITEM item1, ITEM item2) {

	KEY key1, key2;

	key1 = itemKey(item1);
	key2 = itemKey(item2);

	if(keyCompare(key1, key2) == 0) {
		return 1;
	}
	return 0;
}

int itemLess(ITEM item1, ITEM item2) {

	KEY key1, key2;

	key1 = itemKey(item1);
	key2 = itemKey(item2);
	if(keyCompare(key1, key2) == -1) {
		return 1;
	}
	return 0;
}

int itemGreater(ITEM item1, ITEM item2) {

	KEY key1, key2;

	key1 = itemKey(item1);
	key2 = itemKey(item2);
	if(keyCompare(key1, key2) == 1) {
		return 1;
	}
	return 0;
}

int itemGreaterEqual(ITEM item1, ITEM item2) {

        if(itemGreater(item1, item2) || itemEqual(item1, item2)) {
                return 1;
        }

        return 0;
}

int itemLessEqual(ITEM item1, ITEM item2) {

        if(itemLess(item1, item2) || itemEqual(item1, item2)) {
                return 1;
        }

        return 0;
}

int itemVoid(ITEM item) {

        KEY key;

        key = itemKey(item);
        if(keyCompare(key, VOID_KEY) == 0) {
                return 1;
        }
        return 0;
}
