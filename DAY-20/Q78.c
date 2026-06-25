//Write a program to Check symmetric matrix.
#include<stdio.h>
int main(){
    int r1;
    printf("Enter rows of matrix: ");
    scanf("%d",&r1);
     int c1;
    printf("Enter columns of matrix: ");
    scanf("%d",&c1);
    int arr[r1][c1];
    printf("Enter element of matrix:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int brr[r1][c1];
    for(int i=0;i<c1;i++){
        for(int j=0;j<r1;j++){
            brr[i][j]=arr[j][i];
            }
        }
        int e=0;
 for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            if(brr[i][j]==arr[i][j]){
                e++;
            }
        }
    }
    if(e==(r1*c1)){
        printf("symmetric matrix");
    }
    else{
        printf("not symmetric matrix");
    }
return 0;
}