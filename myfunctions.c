#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIM 100

void partitionR(int [], int, int, int);
int maximumR(int [], int, int);
long factorialR(int);
long fibonacciR(int);
long product(int [], int, int, int [], int, int, int);
void matrixMinor(int [][MAX_DIM], int, int, int, int [][MAX_DIM]);
int determinant(int [][MAX_DIM], int, int);
int binSearchR(int [], int, int, int);
void revPrint(char *);
typedef struct node node;
struct node {
        int key;
        node *next;
};

node * newNode(node *);
int count(node *);
void traverse(node *);
void traverseRev(node *);
node * delete(node *, int);
int polishEval(char [], int *);

typedef struct binTreeNode *binTreeNode;
struct binTreeNode {
        int key;
        binTreeNode lChild;
        binTreeNode rChild;
};

void binTreeVisitPre(binTreeNode, binTreeNode);
void binTreeVisitIn(binTreeNode, binTreeNode);
void binTreeVisitPost(binTreeNode, binTreeNode);
int binTreeSize(binTreeNode, binTreeNode);
int binTreeHeight(binTreeNode, binTreeNode);
void ruler(int [], int, int, int);
long factorialTR(int);
long factorial(int);
long fibonacci(int);
int binSearch(int [], int, int, int);


int main(void) {
	return 0;
}

void partitionR(int x[], int l, int r, int a) {

	int d[a+1], i;

	if(l <= r) {
		for(i = l; i <= r; i++) {
			printf("%d ", x[i]);
		}
		printf("\n");
	}

	if(l < r) {
		for(i = 0; i < a; i++) {
			d[i] = l + i*(r-l+1)/a;
		}
		d[i] = r+1;

		for(i = 0; i < a; i++) {
			partitionR(x, d[i], d[i+1]-1, a);
		}
	}

	return;
}

int maximumR(int x[], int l, int r) {

	int c, maxL, maxR;

	if(l == r) {
		return x[l];
	}

	c = (l + r)/2;
	maxL = maximumR(x, l, c);
	maxR = maximumR(x, c+1, r);
	if(maxL > maxR) {
		return maxL;
	}
	return maxR;
}

long factorialR(int n) {

	if(n <= 1) {
		return 1;
	}

	return n * factorialR(n-1);
}

long fibonacciR(int n) {

	if(n == 1 || n == 0) {
		return n;
	}

	return fibonacciR(n-1) + fibonacciR(n-2);
}

long product(int x[], int xl, int xr, int y[], int yl, int yr, int n) {

	int p1, p2, p3, p4;

	if(n == 1) {
		return x[xl]*y[yl];
	}

	p1 = product(x, xl, (xl+xr)/2, y, yl, (yl+yr)/2, n/2);
	p2 = product(x, xl, (xl+xr)/2, y, yl+n/2, yr, n/2);
	p3 = product(x, xl+n/2, xr, y, yl, (yl+yr)/2, n/2);
	p4 = product(x, xl+n/2, xr, y, yl+n/2, yr, n/2);

	return pow(10,n)*p1 + pow(10,n/2)*(p2+p3) + p4;
}

void matrixMinor(int M[][MAX_DIM], int i, int j, int n, int m[][MAX_DIM]) {

	int r, c, rm = 0, cm = 0;

	for(r = 0; r < n; r++) {
		if(r != i) {
			for(c = 0; c < n; c++) {
				if(c != j) {
					m[rm][cm] = M[r][c];
					printf("%d ", m[rm][cm]);
					cm++;
				}
			}
			printf("\n");
			rm++;
			cm = 0;
		}
	}
	printf("\n");
	return;
}

int determinant(int M[][MAX_DIM], int i, int n) {

	int j, det = 0, m[MAX_DIM][MAX_DIM];

	if(n == 1) {
		return M[0][0];
	}

	for(j = 0; j < n; j++) {
		printf("m%d =\n", j+1);
		matrixMinor(M, i, j, n, m);
		det += M[i][j]*pow(-1,i+j)*determinant(m,0,n-1);
	}

	return det;
}

int binSearchR(int x[], int l, int r, int k) {

	int m;

	if(l == r) {
		if(k == x[l]) {
			return 1;
		}
		return 0;
	}

	m = (l + r)/2;
	if(k == x[m]) {
		return 1;
	}
	if(k < x[m]) {
		return binSearchR(x, l, m, k);
	}
	return binSearchR(x, m+1, r, k);
}

void revPrint(char *c) {

	if(*c != '\0') {
		revPrint(c+1);
		putchar(*c);
	}

	return;
}

node * newNode(node *first) {

	int key;
	node *new;

	new = malloc(sizeof(node));
	scanf("%d", &(new->key));
	new->next = first;

	return new;
}

int count(node *temp) {

	if(temp == NULL) {
		return 0;
	}

	return 1 + count(temp->next);
}

void traverse(node *temp) {

	if(temp == NULL) {
		printf("NULL");
		return;
	}

	printf("%d -> ", temp->key);
	traverse(temp->next);
}

void traverseRev(node *temp) {

	if(temp == NULL) {
		printf("NULL ");
		return;
	}
	traverseRev(temp->next);
	printf("<- %d ", temp->key);
}

node * delete(node *temp, int key) {

	if(temp == NULL) {
		return NULL;
	}

	if(temp->key == key) {
		node *tempNext = temp->next;
		free(temp);
		return tempNext;
	}

	temp->next = delete(temp->next, key);
}

int binTreeSize(binTreeNode root, binTreeNode dummy) {

	if(root == dummy) {
		return 0;
	}

	return 1 + binTreeSize(root->lChild, dummy) + binTreeSize(root->rChild, dummy);
}

int binTreeHeight(binTreeNode root, binTreeNode dummy) {

	int lHeight, rHeight;

	if(root == dummy) {
		return 0;
	}

	lHeight = 1 + binTreeHeight(root->lChild, dummy);
	rHeight = 1 + binTreeHeight(root->rChild, dummy);
	if(lHeight > rHeight) {
		return lHeight;
	}
	return rHeight;

}

void binTreeVisitPre(binTreeNode root, binTreeNode dummy) {

	if(root == dummy) {
		return;
	}

	printf("%d ", root->key);
	binTreeVisitPre(root->lChild, dummy);
	binTreeVisitPre(root->rChild, dummy);
}

void binTreeVisitIn(binTreeNode root, binTreeNode dummy) {

        if(root == dummy) {
                return;
        }

        binTreeVisitIn(root->lChild, dummy);
        printf("%d ", root->key);
        binTreeVisitIn(root->rChild, dummy);
}

void binTreeVisitPost(binTreeNode root, binTreeNode dummy) {

        if(root == dummy) {
                return;
        }

        binTreeVisitPost(root->lChild, dummy);
        binTreeVisitPost(root->rChild, dummy);
        printf("%d ", root->key);
}

int polishEval(char exp[], int *i) {

	int x = 0;

	while(exp[*i] == '_') {
		printf("exp[%d] = %c\n", *i, exp[*i]);
		(*i)++;
	}

	if(exp[*i] == '+') {
		printf("exp[%d] = %c\n", *i, exp[*i]);
		(*i)++;
		return polishEval(exp, i) + polishEval(exp, i);
	}
	if(exp[*i] == '*') {
                printf("exp[%d] = %c\n", *i, exp[*i]);
		(*i)++;
		return polishEval(exp, i) * polishEval(exp, i);
	}

	while((exp[*i] >= '0') && (exp[*i] <= '9')) {
                printf("exp[%d] = %c\n", *i, exp[*i]);
		x = 10*x + (exp[*i] - '0');
		(*i)++;
	}
	return x;
}
void hanoi(int, int, int, int);

void hanoi(int disks, int pegs, int src, int dest) {

	int aux;

	aux = pegs - (src + dest);

	if(disks == 1) {
		printf("%d -> %d\n", src, dest);
		return;
	}

	hanoi(disks-1, pegs, src, aux);
	printf("%d -> %d\n", src, dest);
	hanoi(disks-1, pegs, aux, dest);
}

void ruler(int segment[], int l, int r, int h) {

        int m;

        if(h >= 0) {
                m = (l + r)/2;
                ruler(segment, l, m, h-1);
                segment[m] = h;
                ruler(segment, m+1, r, h-1);
        }
}

long factorialTR(int n) {

	static int f = 1;

	if(n == 0) {
		return f;
	}

	f *= n;

	return factorialTR(n-1);
}
long factorial(int n) {

	int nFact = 1, i;

	for(i = 2; i <= n; i++) {
		nFact *= i;
	}

	return nFact;
}
long fibonacci(int n) {

	long fib1 = 0, fib2 = 1, fibt;
	int i;

	if(n == 0) {
		return fib1;
	}

	for(i = 1; i < n; i++) {
		fibt = fib2;
		fib2 += fib1;
		fib1 = fibt;
	}

	return fib2;
}
int binSearch(int x[], int l, int r, int k) {

	int m, lnew, rnew;

	lnew = l; rnew = r;

	while(lnew <= rnew) {
		m = (lnew + rnew)/2;
		if(k == x[m]) {
			return 1;
		}
		if(k < x[m]) {
			rnew = m;
		} else {
			lnew = m + 1;
		}
	}

	return -1;
}
