#include<stdio.h>

int main(){

    int arr[4], sum=0;

    printf("ENter 4 Values: ");

    for(int i=0; i<4; i++){
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    printf("Sum of Elements: %d", sum);
    return 0;
}