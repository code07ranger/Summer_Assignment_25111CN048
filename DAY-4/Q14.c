//Write a program to Find nth Fibonacci term.
#include<stdio.h>
int main(){
    int n;
    printf("Enter desired term: ");
    scanf("%d",&n);
    int a=0;
    int b=1;
    int sum=0;
    printf("The fibonacci series: ");
    for(int i=1;i<=n-1;i++){
     sum=a+b;
     a=b;
     b=sum;
    }
    printf("The %dth fibonacci term is %d",n,a);
    return 0;
}