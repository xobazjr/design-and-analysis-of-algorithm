#include <stdio.h>
#define MAX_ITEMS 4

int max_value = 0;  

void knapsack(int values[], int weights[], int n, int index, int current_weight, int current_value, int max_weight) {
    if (current_weight > max_weight) return;

    if (current_value > max_value) {
        max_value = current_value;
    }

    if (index == n) return;

    knapsack(values, weights, n, index + 1, current_weight + weights[index], current_value + values[index], max_weight);

    knapsack(values, weights, n, index + 1, current_weight, current_value, max_weight);
}

int main() {
    int k;  
    int values[MAX_ITEMS];  
    int weights[MAX_ITEMS];  

    scanf("%d", &k);

    for (int i = 0; i < MAX_ITEMS; i++) {
        scanf("%d", &values[i]);
    }

    for (int i = 0; i < MAX_ITEMS; i++) {
        scanf("%d", &weights[i]);
    }

    knapsack(values, weights, MAX_ITEMS, 0, 0, 0, k);

    printf("%d\n", max_value);

    return 0;
}

