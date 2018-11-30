#include<stdio.h>

int fib_array[51];

int fibo(int n) {
    if(fib_array[n] != - 1) {
        return fib_array[n];
    }
    else {
        fib_array[n] = fibo(n - 1) + fibo(n - 2);
        return fib_array[n];
    }
}

int main()
{
    int n, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    fib_array[0] = 0;
    fib_array[1] = 1;

    for(i=2; i<51; i++) {
        fib_array[i] = - 1;
    }

    int res = fibo(n);
    printf("%dth fibonacci number = %d\n", n, res);

    return 0;
}
