//Write a program to Transpose matrix.
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
    printf("Transpose matrix:\n");
    for(int i=0;i<c1;i++){
        for(int j=0;j<r1;j++){
            printf("%d ",arr[j][i]);
        }
        printf("\n");
    }
    return 0;
}