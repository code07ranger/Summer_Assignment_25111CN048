//write a program to check if a number is prime or not
#include<stdio.h>
#include<stdbool.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    bool flag=false;
        for (int i=2;i<=n-1;i++){
        if(n%i==0)
        {
             flag=true;
             break;
        }
    }
        if (n==1)
        {
           printf("1 is neither composite nor prime");
        }
        else if (flag==false)
        {
          printf("Entered number is prime");
        }
        else
        {
            printf("Entered number is composite");
        }
    return 0;
}