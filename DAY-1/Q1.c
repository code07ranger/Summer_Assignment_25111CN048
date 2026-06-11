//Write a program to Calculate sum of first n natural numbers.
#include<stdio.h>
int main(){
    int n;
    printf("Enter no of terms: ");
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+i;
    }
    printf("The sum of first %d natural no:%d",n,sum);
    return 0;
}