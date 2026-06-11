// Write a program to Print reverse pyramid.
// *********
//  *******
//   *****
//    ***
//     *
#include<stdio.h>
int main(){
    int nst=9;
    int nsp=0;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=nsp;j++){
            printf(" ");
        }
        for(int k=1;k<=nst;k++){
            printf("*");
        }
        printf("\n");
        nsp++;
        nst-=2;
    }
    return 0;
}