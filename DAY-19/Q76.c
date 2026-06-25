//Write a program to Find diagonal sum.
#include<stdio.h>
int main(){
    //first matrix
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
    int sum=0;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            if(i==j){
                sum+=arr[i][j];
            }
        }
    }
    printf("The diagonal sum is:%d",sum);
    return 0;
}