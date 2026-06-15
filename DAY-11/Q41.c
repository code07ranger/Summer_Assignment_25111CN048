// Write a program to Write function to find sum of two numbers.
#include<stdio.h>
int sum(int a,int b){
    int x=a+b;
    return x;
}
int main(){
    int a;
    printf("Enter first number: ");
    scanf("%d",&a);
    int b;
    printf("Enter second number: ");
    scanf("%d",&b);
    int s=sum(a,b);
    printf("The sum of %d and %d is %d",a,b,s);
    return 0;
}