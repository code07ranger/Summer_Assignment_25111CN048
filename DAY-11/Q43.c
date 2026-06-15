//Write a program to Write function to check prime.
#include<stdio.h>
#include<stdbool.h>
void prime(int a){
   bool f=false;
   for(int i=2;i<a;i++){
    if(a%i==0){
        f=true;
        break;
    }
   }
   if(a==1) printf("Neither prime nor composite");
   else if(f==false) printf("prime");
   else printf("composite");
   return ;
}
int main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    prime(n);
    return 0;
}