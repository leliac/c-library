#include "items.c"

void mergeSortCombine(item *, item *, int, int, int);
void mergeSortSolve(item *, item *, int, int);
void mergeSort(item *, int);
void bottomUpMergeSort(item *, int, int);
int quickSortPartition(item *, int, int);
void quickSort(item *, int, int);

void mergeSortCombine(item *A, item *B, int l, int m, int r) {

	int jl = l, jr = m+1, i;

	for(i = l; i <= r; i++) {
		if(jr > r) {
			B[i] = A[jl++];
		} else if(jl > m) {
			B[i] = A[jr++];
		} else if(itemLessEqual(A[jl], A[jr])) {
			B[i] = A[jl++];
		} else {
			B[i] = A[jr++];
		}
	}

	for(i = l; i <= r; i++) {
		A[i] = B[i];
	}

	return;
}

void mergeSortSolve(item *A, item *B, int l, int r) {

	int m;

	if(l >= r) {
		return;
	}

	m = (l + r)/2;
	mergeSortSolve(A, B, l, m);
	mergeSortSolve(A, B, m+1, r);
	mergeSortCombine(A, B, l, m, r);

	return;
}

void mergeSort(item *A, int n) {

	item *B = malloc(n*sizeof(item));

	mergeSortSolve(A, B, 0, n-1);

	return;
}

void bottomUpMergeSort(item *A, int l, int r) {

        item *B = malloc((r-l+1)*sizeof(item));
	int s, i;

	for(s = 1; s <= r-l; s *= 2) {
		for(i = l; i <= r - s ; i += 2*s) {
		mergeSortCombine(A, B, i, i+s-1, itemMin(i+2*s-1, r));
		}
	}

	return;
}

int quickSortPartition(item *A, int l, int r) {

	item x, t;
	int i, j;

	x = A[r];
	i = l-1;
	j = r;

	while(i < j) {
		while(itemLess(A[++i], x));
		while(i < --j && itemGreater(A[j], x));

		if(i < j) {
			itemSwap(A, i, j);
		}
	}
	itemSwap(A, i, r);

	return i;
}

void quickSort(item *A, int l, int r) {

	int ix;

	if(l >= r) {
		return;
	}

	ix = quickSortPartition(A, l, r);
	quickSort(A, l, ix-1);
	quickSort(A, ix+1, r);
	return;

}
