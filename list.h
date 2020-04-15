#include ITEM_TYPE_H

typedef struct Node *Node;

struct Node {
	Item item;
	Node next;
};

Node nodeNew(Item, Node);

void listPrint(Node, Node);
Node listDeleteR(Node, Key, Node, int *);
int listDelete(Node, Key, Node);

#include "list.c"
