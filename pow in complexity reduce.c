#include<stdio.h>

long int power(long int x, long int n) {
    static long int y;

    if(n == 0) {
        return 1;
    }
    else if(n%2==0) {
        y = power(x, n/2);   //for even pow = x^(n/2) * x^(n/2)
        return y*y;
    }
    else {
        return x * power(x, n-1); //for odd pow = x * x^(n-1)
    }
}

long int main()
{
    long int n, x, res;
    printf("Enter base and expo: ");

    while(scanf("%ld%ld", &x, &n) != EOF)
    {
        res = power(x, n);
        printf("%ld^%ld = %ld\n\n", x, n, res);

        printf("Enter base and expo: ");
    }

    return 0;
}
