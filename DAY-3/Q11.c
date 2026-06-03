//Write a program to Find GCD of two numbers.
#include<stdio.h>
int min(int a,int b){
    if (a>b) return b;
    else  return a;
}
int main(){
    int a;
    printf("Enter first number: ");
    scanf("%d",&a);
    int b;
    printf("Enter second number: ");
    scanf("%d",&b);
    int n=min(a,b);
    int hcf=0;
    for(int i=1;i<=n;i++){
        if(a%i==0 && b%i==0){
           hcf=i;
      }
    }
    printf("The GCD of %d and %d is %d",a,b,hcf);
    return 0;
}