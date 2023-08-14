#include<stdio.h>

/*	same computation-> not more than once
	Memoised Version/ Top-down approach --> Dynamic Programming/ Recursive approach
	Bottom-Up Approach --> Iterative Approach
	if there is overlaps in the subproblems, we use Dynamic Programming approach
	Won't work for Divide and Conquer algos, rather it will use more memories giving us no advantage in runtime
	Divide and Conquer --> no overlaps in the subproblems
*/
long int fibNum[100];

int fib(int n);
long int  fibonacci(int n);

int main(){
    
    for(int i = 0; i < 100;++i) fibNum[i] = -1;
    
	printf("Fibonacci using normal recusive approach: %d\n", fib(4));
	printf("Fibonacci using dynamic approach: %ld\n", fibonacci(50));
}

// 0 1 1 2 3 5 8 13

int fib(int n){

	if(n == 0) return 0;
	if(n == 1) return 1;
	
	return fib(n-2) + fib(n-1);
}

long int  fibonacci(int n){
	if(n<=1){
		fibNum[n] = n;
		return fibNum[n];
	}
	
	if(fibNum[n] < 0){
		fibNum[n] = fibonacci(n-2) + fibonacci(n-1);
	}
	
	return fibNum[n];	
}
