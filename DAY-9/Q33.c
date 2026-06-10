// Write a program to Print reverse star pattern.
// *****
// ****
// ***
// **
// *
#include<stdio.h>
int main(){
    int nst=5;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=nst;j++){
            printf("*");
        }
        printf("\n");
        nst--;
    }
    return 0;
}