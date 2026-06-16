//Write a program to Write function for Fibonacci.
#include<stdio.h>
void fibonacci(int a,int b,int n){
   int sum=0;
   printf("The fibonacci series:");
   for(int i=1;i<=n;i++){
    sum=a+b;
    printf("%d ",a);
    a=b;
    b=sum;
   }
   return ;
}
int main(){
    int a=0;
    int b=1;
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    fibonacci(a,b,n);
    return 0;
}