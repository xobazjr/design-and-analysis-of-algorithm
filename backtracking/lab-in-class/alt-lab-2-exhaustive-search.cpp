#include <stdio.h>

void print_sol(int A[] ,int x[], int n, int k) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if(x[i] == 1){
            sum += A[i];
            // printf("sum = %d",sum);
        }
        //printf("\n");
    }
    
    if(sum == k){
        for(int i=0;i<n;i++){
            if(x[i] == 1){
                printf("%d ",A[i]);
            }
        }printf("\n");
    }
}

void subset1(int A[],int x[], int l, int n, int k) {
    if (l == n) {
        print_sol(A, x, n, k);
    } else {
        x[l] = 1;
        subset1(A, x, l + 1, n, k);
        x[l] = 0;
        subset1(A, x, l + 1, n, k);
    }
}

int main() {
    int n = 5;            // Number of elements
    int A[n];
    int x[] = {0};        // Array to store subset
    
    int k;
    scanf("%d",&k);
    
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    
    subset1(A,x, 0, n, k);

    return 0;
}
