#include <stdio.h>
int main(){

    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: \n", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    arr[n-1] = 0;
    printf("Array after deleting the last element: \n");
    for(i=0; i<n; i++){
        printf("%d ->",arr[i]);
    }
    return 0;

}