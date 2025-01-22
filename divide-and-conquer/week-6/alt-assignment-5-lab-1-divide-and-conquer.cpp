#include <stdio.h>

int arr[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
int k = 4;
int n = sizeof(arr) / sizeof(arr[0]);

int partition(int l, int r)
{
    int pivot = arr[l]; // pivot left
    int i = l; // pivot left
    int j = r + 1; // pivot right + 1

    while(true)
    {
        do
        {
            i++;
        }while (i <= r && arr[i] <= pivot);

        do
        {
            j--;
        }while (arr[j] > pivot);

        if (i >= j){
            break;
        }

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;

    return j; 
}

int quickSelect(int low, int high, int k)
{
    if (low == high)
    {
        return arr[low];
    }

    int p = partition(low, high);
    printf("%d ",p);

    if (p == k)
    {
        return arr[p];
    }
    else if (p > k)
    {
        return quickSelect(low, p - 1, k); 
    }
    else
    {
        return quickSelect(p + 1, high, k); 
    }
}

int main()
{
    printf("%d", quickSelect(0, n - 1, k-1)); 
    return 0;
}