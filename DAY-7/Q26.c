//Write a program to Recursive Fibonacci term.
#include<stdio.h>
int fibo(int a){
    if(a==0) return 0;
    if(a==1) return 1;
    int x=fibo(a-1)+fibo(a-2);
    return x;
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    int x=fibo(n-1);
    printf("The %dth fibonacci term is:%d",n,x);
    return 0;
}