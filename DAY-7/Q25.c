//Write a program to Recursive factorial.
#include<stdio.h>
int factorial(int x){
    if(x==1 || x==0) return 1;
    int h=x*factorial(x-1);
    return h;
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    int x=factorial(n);
    printf("The factorial of %d is %d",n,x);
    return 0;
}