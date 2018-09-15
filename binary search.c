#include<stdio.h>
int binary_search(int array[], int search_num, int size);

int main()
{
    int size, i, search_num;
    printf("Enter array size: ");
    scanf("%d", &size);

    int array[size];
    for(i=0; i<size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the number that you want to find: ");
    scanf("%d", &search_num);

    int goal_index = binary_search(array, search_num, size);
    if(goal_index >= 0) {
        printf("Your searched value found at index %d\n", goal_index+1);
    }
    else {
        printf("Your searched value not found\n");
    }
}

int binary_search(int array[], int search_num, int size)
{
    int left=0, right=size-1, mid;

    while(left <= right) {
        mid = (left + right) / 2;

        if(array[mid] == search_num) {
            return mid;
        }
        else if(array[mid] > search_num) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

