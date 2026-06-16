//Write a program to Write function for perfect number.
#include<stdio.h>
int perfect(int a){
    int sum=0;
    for(int i=1;i<a;i++){
        if(a%i==0){
          sum+=i;
        }
    }
    return sum;
}
int main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int x=perfect(n);
    if(x==n) printf("%d is perfect number",n);
    else printf("%d is not perfect number",n);
    return 0;
}