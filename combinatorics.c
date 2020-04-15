//Prototypes
int repet_arrang_func_r(int items[], int n, int k, int sol[], int pos, int (*func)(int [], int, args_t), args_t args);
int repet_arrang_func(int items[], int n, int k, int (*func)(int [], int, args_t), args_t args);

int simple_perm_func_r(int items[], int n, int sol[], int pos, int mark[], int (*func)(int [], int, args_t), args_t args);
int simple_perm_func(int items[], int n, int (*func)(int [], int, args_t), args_t args);

int powerset_func(int n, int (*func)(int [], int, args_t), args_t args);

//Arrangements with repetitions with function
int repet_arrang_func_r(int items[], int n, int k, int sol[], int pos, int (*func)(int [], int, args_t), args_t args) {

        int num_sols, i;

        num_sols = 0;

        if(pos == k) {
                return func(sol, k, args);
        }

        for(i = 0; i < n; i++) {
                sol[pos] = items[i];
                num_sols += repet_arrang_func_r(items, n, k, sol, pos+1, func, args);
        }
        return num_sols;
}

int repet_arrang_func(int items[], int n, int k, int (*func)(int [], int, args_t), args_t args) {

        int *sol;
        int num_sols;

        sol = malloc(k*sizeof(int));
        num_sols = repet_arrang_func_r(items, n, k, sol, 0, func, args);
        free(sol);
        return num_sols;
}

//Simple permutations with function
int simple_perm_func_r(int items[], int n, int sol[], int pos, int mark[], int (*func)(int [], int, args_t), args_t args) {

	int num_sols, i;

	num_sols = 0;

	if(pos == n) {
		return func(sol, n, args);
	}

	for(i = 0; i < n; i++) {
		if(mark[i] == 0) {
			sol[pos] = items[i];
			mark[i] = 1;
			num_sols += simple_perm_func_r(items, n, sol, pos+1, mark, func, args);
			mark[i] = 0;
		}
	}
	return num_sols;
}

int simple_perm_func(int items[], int n, int (*func)(int [], int, args_t), args_t args) {

	int *sol;
	int num_sols, *mark, i;

	sol = malloc(n*sizeof(int));
	mark = malloc(n*sizeof(int));
	for(i = 0; i < n; i++) {
		mark[i] = 0;
	}

	num_sols = simple_perm_func_r(items, n, sol, 0, mark, func, args);
	free(sol);
	free(mark);
	return num_sols;
}

//Powerset with function
int powerset_func(int n, int (*func)(int [], int, args_t), args_t args) {

	int items[] = {0, 1}, num_sols;

	num_sols = repet_arrang_func(items, 2, n, func, args);
	return num_sols;
}
