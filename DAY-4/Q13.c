//Write a program to Generate Fibonacci series.
#include<stdio.h>
int main(){
    int n;
    printf("Enter limit of Fibonacci series: ");
    scanf("%d",&n);
    int a=0;
    int b=1;
    int sum=0;
    printf("The fibonacci series: ");
    for(int i=1;i<=n;i++){
     sum=a+b;
     printf("%d ",a);
     a=b;
     b=sum;
    }
    return 0;
}