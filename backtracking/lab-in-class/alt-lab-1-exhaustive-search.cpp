#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int X[], int start, int end, int *count) {
    if (start == end) {
        for (int i = 1; i <= end; i++) {
            if((X[i] == 1 && X[i+1] == 2) || (X[i] == 2 && X[i+1] == 1)){
            	(*count)++;
            	break;
			}
        }
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&X[start], &X[i]);
        permute(X, start + 1, end,count);
        swap(&X[start], &X[i]);
    }
}

int main() { 
    int n;
    int count = 0;
    
    while(true){
    	scanf("%d",&n);
    	if(n >= 2 && n <= 10){
    		break;
		}
	}
	
	int X[n+1];
	
	for(int i=1;i<=n;i++){
		X[i] = i;
//		printf("%d",X[i]);
	}
	
	permute(X, 1, n,&count);
    printf("%d",count);

    return 0;
}
