#include <stdlib.h>

Node nodeNew(Item item, Node next) {

        Node node;

        node = malloc(sizeof(*node));
        node->item = item;
        node->next = next;
        return node;
}

Node nodeNewEmpty(void) {

	Node node;

	node = malloc(sizeof(*node));
	node->item = itemSetVoid();
	node->next = NULL;
	return node;
}

void nodeFree(Node node) {
	if(node != NULL) {
		itemFree(node->item);
		free(node);
	}
	return;
}

void listFree(Node node, Node z) {

	if(node == z || node->next == z) {
		return;
	}

	listFree(node->next, z);
	nodeFree(node->next);
	return;
}

void listPrint(Node node, Node z) {

	if(node == z) {
		return;
	}

	itemPrint(node->item);
	listPrint(node->next, z);
	return;
}


int listDelete(Node head, Key key, Node z) {

	int hit;

	hit = 0;
	head = listDeleteR(head, key, z, &hit);
	return hit;
}

Node listDeleteR(Node node, Key key, Node z, int *hit) {

	Node next;

	if(node == z) {
		return z;
	}

	if(keyCompare(key, keyGet(node->item)) == 0) {
		*hit++;
		next = node->next;
		nodeFree(node);
		return next;
	}

	node->next = listDeleteR(node->next, key, z, hit);
	return node;
}
