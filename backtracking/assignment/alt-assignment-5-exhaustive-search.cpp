#include <stdio.h>
#include <limits.h>
#define MAX_TYPES 3  

int min_count = INT_MAX;  

void cutWire(int lengths[], int n, int count) {
    if (n == 0) {
        if (count < min_count) {
            min_count = count;
        }
        return;
    }
    
    if (n < 0) {
        return; 
    }

    for (int i = 0; i < MAX_TYPES; i++) {
        cutWire(lengths, n - lengths[i], count + 1);
    }
}

int main() {
    int n;  
    int lengths[MAX_TYPES];  

    scanf("%d", &n);
    for (int i = 0; i < MAX_TYPES; i++) {
        scanf("%d", &lengths[i]);
    }

    cutWire(lengths, n, 0);

    printf("%d\n", (min_count == INT_MAX) ? -1 : min_count);

    return 0;
}
