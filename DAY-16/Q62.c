//Write a program to Find maximum frequency element.
#include<stdio.h>
int main(){
    int n, i, j, max_freq = 0, freq_element;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n; i++){
        int count = 1;
        for(j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > max_freq){
            max_freq = count;
            freq_element = arr[i];
        }
    }
    printf("The maximum frequency element is: %d with frequency: %d\n", freq_element, max_freq);
    return 0;
}