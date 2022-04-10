#include <stdio.h>

// function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to find the partition position
int partition(int A[], int lb, int ub)
{

    // select the rightmost element as pivot
    int pivot = A[ub];

    // pointer for greater element
    int i = (lb - 1);

    // traverse each element of the A
    // compare them with the pivot
    for (int j = lb; j < ub; j++)
    {
        if (A[j] <= pivot)
        {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&A[i], &A[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&A[i + 1], &A[ub]);
    return (i + 1);
}

void quickSort(int A[], int lb, int ub)
{
    if (lb < ub)
    {
        int pi = partition(A, lb, ub);
        quickSort(A, lb, pi - 1);
        quickSort(A, pi + 1, ub);
    }
}
void printA(int A[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {8, 7, 2, 1, 0, 9, 6};

    int n = sizeof(A) / sizeof(A[0]);

    printf("Unsorted A\n");
    printA(A,n);
    quickSort(A, 0, n - 1);

    printf("Sorted A in ascending order: \n");
    printA(A, n);
}
