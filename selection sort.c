#include<stdio.h>
void selection_sort(int array[], int size);

int main()
{
    int size, i;
    printf("Enter the array size: ");
    scanf("%d", &size);

    int array[size];
    for(i=0; i<size; i++)
    {
        scanf("%d", &array[i]);
    }

    selection_sort(array, size);

    /* print the sorted array*/
    for(i=0; i<size; i++)
    {
        printf("%d ", array[i]);
    }
}


void selection_sort(int array[], int size)
{
    int iMin, temp, i, j, loc;

    for(i=0; i<size-1; i++) {
        iMin = i;

        for(j=i+1; j<size; j++) {
            if(array[j] < array[iMin]) {
                iMin = j;
            }
        }

        if(iMin != i) {  //if the first value is min then no need to swap
            temp = array[i];
            array[i] = array[iMin];
            array[iMin] = temp;
        }
    }
}
