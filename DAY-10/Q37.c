// Write a program to Print star pyramid.
//     *
//    ***
//   *****
//  *******
// *********
#include<stdio.h>
int main(){
int nsp=4;
int nst=1;
for(int i=1;i<=5;i++){
    for(int j=1;j<=nsp;j++){
        printf(" ");
    }
    for(int k=1;k<=nst;k++){
        printf("*");
    }
    printf("\n");
    nsp--;
    nst+=2;
}
return 0;
}