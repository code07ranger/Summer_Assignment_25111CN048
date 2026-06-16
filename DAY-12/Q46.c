//Write a program to Write function for Armstrong.
#include<stdio.h>
void armstrong(int a){
   int og=a;
   int result=0;
    for (int i=1;og!=0;i++){
       int r=og%10;
        result+=r*r*r;
        og/=10;
    }
    if (result==a){
        printf("%d is an Armstrong number.\n",a);
    }
    else{
        printf("%d is not an Armstrong number.\n",a);
    }
}
int main(){
    int n;
    printf("Enter a three-digit number: ");
    scanf("%d", &n);
    armstrong(n);
    return 0;
}