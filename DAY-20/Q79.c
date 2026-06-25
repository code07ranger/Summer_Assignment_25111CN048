//Write a program to Find row-wise sum.
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
    for(int i=0;i<r1;i++){
        int sum=0;
        for(int j=0;j<c1;j++){
            sum+=arr[i][j];
        }
        printf("The sum of row%d is %d\n",i+1,sum);
    }

    return 0;
}