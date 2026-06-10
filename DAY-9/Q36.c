// Write a program to Print hollow square pattern.
// *****
// *   *
// *   *
// *   *
// *****
#include<stdio.h>
int main(){
    int nsp=1;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            if(i==1 || i==5){
            printf("*");
            }
            else if(j==1 || j==5){
            printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}