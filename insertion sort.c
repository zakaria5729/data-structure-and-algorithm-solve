#include<stdio.h>

int main()
{
    int size, i;

    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d number array elements\n", size);
    for(i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, size);

    printf("after sorted of the array\n");
    for(i=0; i<size-1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[i]);

    return 0;
}

void insertion_sort(int arr[], int size)
{
    int i, j, temp;

    for(i=1; i<size; i++) {
        temp = arr[i];
        j = i - 1;

        while(j>=0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
    }
}
