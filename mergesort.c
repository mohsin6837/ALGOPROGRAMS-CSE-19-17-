#include <stdio.h>

/* Function to merge the subarrays of a[] */
void merge(int a[], int lb, int mid, int ub)
{
  int i, j, k;
  int n1 = mid - lb + 1;
  int n2 = ub - mid;

  int LeftArray[n1], RightArray[n2]; // temporary arrays

  /* copy data to temp arrays */
  for (int i = 0; i < n1; i++)
    LeftArray[i] = a[lb + i];
  for (int j = 0; j < n2; j++)
    RightArray[j] = a[mid + 1 + j];

  i = 0;   /* initial index of first sub-array */
  j = 0;   /* initial index of second sub-array */
  k = lb; /* initial index of merged sub-array */

  while (i < n1 && j < n2)
  {
    if (LeftArray[i] <= RightArray[j])
    {
      a[k] = LeftArray[i];
      i++;
    }
    else
    {
      a[k] = RightArray[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    a[k] = LeftArray[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    a[k] = RightArray[j];
    j++;
    k++;
  }
}

void mergeSort(int a[], int lb, int ub)
{
  if (lb < ub)
  {
    int mid = (lb + ub) / 2;
    mergeSort(a, lb, mid);
    mergeSort(a, mid + 1, ub);
    merge(a, lb, mid, ub);
  }
}

/* Function to print the array */
void printArray(int a[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main()
{
  int a[] = {12,10,8,5};
  int n = sizeof(a) / sizeof(a[0]);
  printf("Before sorting array elements are - \n");
  printArray(a, n);
  mergeSort(a, 0, n - 1);
  printf("After sorting array elements are - \n");
  printArray(a, n);
  return 0;
}
