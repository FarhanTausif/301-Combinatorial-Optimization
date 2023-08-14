#include <stdio.h>

int fib(int n){
    if( n == 0 ) return 0;
    if( n == 1) return 1;

    // n == 2, -> fib(2) = fib(1) + fib(0)
    return fib(n-1) + fib(n-2);
}

// 0 1 1 2 3 5 8 13 21

int main(){

    printf("%d", fib(2));

    return 0;
}