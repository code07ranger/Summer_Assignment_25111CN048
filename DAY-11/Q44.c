//Write a program to Write function to find factorial.
#include<stdio.h>
void factorial(int a){
    int fact=1;
    for(int i=1;i<=a;i++){
        fact*=i;
    }
    printf("Factorial of %d is %d",a,fact);
    return ;
}
int main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    factorial(n);
    return 0;
}