//Write a program to Subtract matrices.
#include<stdio.h>
int main(){
    //first matrix
    int r1;
    printf("Enter rows of first matrix: ");
    scanf("%d",&r1);
     int c1;
    printf("Enter columns of first matrix: ");
    scanf("%d",&c1);
    int arr[r1][c1];
    printf("Enter element of first matrix:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    //second matrix
    int r2;
    printf("Enter rows of second matrix: ");
    scanf("%d",&r2);
     int c2;
    printf("Enter columns of second matrix: ");
    scanf("%d",&c2);
    int brr[r2][c2];
    printf("Enter element of second matrix:\n");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d",&brr[i][j]);
        }
    }
    int crr[r1][c1];
    printf("THe resultant matrix:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            crr[i][j]=0;
            if(r1==r2 && c1==c2){
                crr[i][j]=arr[i][j]-brr[i][j];
                printf("%d ",crr[i][j]);
            }
            else{
                printf("Subtraction not possible");
                break;
            }
        }
        printf("\n");
    }
    return 0;
}