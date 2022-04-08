#include <stdio.h>
int main()
{
    int a[100];
    int i,n;
    printf("Enter the size of array");
    scanf("%d",&n);
    printf("\nEnter the elements of array:");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nArray in unsorted order:");
    for ( i = 0; i < n; i++)
    {
         printf("%d ",a[i]);
    }
    int x=binarysearch(a,0,n-1,3);
    if(x==-1){
        printf("Not found");
    }
    else{
        printf("Element is found at %d position",x);
    }
    return 0;
}
int binarysearch(int a[], int lb, int ub, int x)
{

    if (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] < x)
        {
            binarysearch(a, mid + 1, ub, x);
        }
        else
        {
            binarysearch(a, lb, mid - 1, x);
        }
    }
    return -1;
}