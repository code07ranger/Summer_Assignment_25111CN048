//Write a program to Check strong number.
#include<stdio.h>
int factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int og=n;
    int r=0;
    int sum=0;
    while(n!=0){
       r=n%10;
       sum+=factorial(r);
       n/=10;
    }
    if(og==sum){
        printf("%d is a strong number",og);
    }
    else{
        printf("%d is not a strong number",og);
    }
   return 0;
}
