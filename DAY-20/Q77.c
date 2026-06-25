//Write a program to Multiply matrices.
#include<stdio.h>
int main(){
    int r1,c1,r2,c2;
    printf("Enter row of 1st matrix: ");
    scanf("%d",&r1);
     printf("Enter column of 1st matrix: ");
    scanf("%d",&c1);
    printf("Enter row of 2nd matrix: ");
    scanf("%d",&r2);
     printf("Enter column of 2nd matrix: ");
    scanf("%d",&c2);
    int arr[r1][c1];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",&arr[i][j]);
        }
    }
     int brr[r2][c2];
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d",&brr[i][j]);
        }
    }
    int crr[r1][c2];
     for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            crr[i][j]=0;
            if(c1==r2){
                for(int k=0;k<c1;k++){
                    crr[i][j]+=arr[i][k]*brr[k][j];
                }
            }
            else{
                printf("multiplication not possible");
                break;
            }
        }
    }
     for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            printf("%d ",crr[i][j]);
        }
        printf("\n");
    }
    return 0;
}