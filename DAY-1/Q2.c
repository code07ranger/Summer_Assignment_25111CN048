//write a code to find table of the number n, such that n is input from user
#include<stdio.h>
int main (){
    int i,n;
    printf("Enter a number: ");
    scanf("%d",&n);
    for( i=n; i<=n*10; i=i+n)
    {
        printf("%d\n",i);
    }
    return 0;
}