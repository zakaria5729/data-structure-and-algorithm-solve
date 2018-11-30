#include <stdio.h>

int divide(int arr[], int start, int end)
{
    int pivot;
    if(start>=end)
    {
        return;
    }
    else
    {
        pivot = sort(arr, start, end);
        divide(arr, start, pivot-1);
        divide(arr, pivot+1, end);
    }
}

int sort(int arr[], int start, int end)
{
    int i, j, pivot;
    int moveptr_right = 1;

    pivot = arr[start];
    i = start;
    j = end;

    while(i<j)
    {
        if(moveptr_right)
        {
            if(arr[j] < pivot)
            {
                arr[i] = arr[j];
                i++;
                moveptr_right = 0;
            }
            else
            {
                j--;
            }
        }
        else
        {
            if(arr[i] > pivot)
            {
                arr[j] = arr[i];
                j--;
                moveptr_right = 1;
            }
            else
            {
                i++;
            }
        }
    }
    //i==j
    arr[i] = pivot;
    return i;
}

int main()
{
    int arr[100],i,n,j,temp;

    printf("Enter the number of elements to be sorted: ");
    scanf("%d",&n);

    printf("Enter array of elements element: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    divide(arr, 0, n-1);

    printf("In ascending order: ");
    for(i=0; i<n; ++i)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
