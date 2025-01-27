#include <stdio.h>

void print_sol(int x[], int n) {

    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }

    printf("\n");
}

void subset2(int x[], int l, int n) {

    print_sol(x, l);

       int j;
    if (l == 0) 
	j = 1; 
    else 
        j = x[l] + 1;

    for (int i = j; i <= n; i++) {
        x[l + 1] = i;
        subset2(x, l + 1, n);
    }
}

int main() {
    int n = 3; 	// Number of elements
    int x[n + 1];	 // Array to store subset

   subset2(x, 0, n);

    return 0;
}
