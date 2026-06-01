//print factorial of given number n
#include<stdio.h>
int main(){
    int n;
    printf("enter a number: ");
    scanf("%d",&n);
    int r=1;
    for (int i=1;i<n+1;i++){
        r=r*i;
          }
    printf("factorial of %d is: %d",n,r);
    return 0;
}