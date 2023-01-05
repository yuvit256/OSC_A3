#include <stdio.h>
#include <limits.h>

#define N 50

void shift_element(int *arr, int i);

void insertion_sort(int *arr, int n);

int main()
{
    int arr[N] = { 0 };
    for (int i = 0; i < N; ++i){scanf("%d", &(*(arr+i)));}
    insertion_sort(arr, N);
    for(int i=0; i<N-1; i++){printf("%d,", *(arr+i));}
    printf("%d", *(arr+N-1));
    printf("\n");
    return 0;
}

void shift_element(int *arr, int i) {
    for (int j=i; j>0; --j){*(arr+j) = *(arr+j-1);}
}

void insertion_sort(int *arr, int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = *(arr + i), j = (i - 1);

        while (j >= 0 && *(arr + j) > key)
            --j;

        shift_element((arr + j), (i - j));

        *(arr + j + 1) = key;
    }
}
