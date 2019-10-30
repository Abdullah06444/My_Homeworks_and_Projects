#include <stdio.h>
int main(void)
{
	
    int arr[] = {10, 20};
    int *p = arr;
    ++*p;
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n", arr[0], arr[1], *p);
    
    int arr2[] = {10, 20};
    int *p2 = arr2;
    *p2++;
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n", arr2[0], arr2[1], *p2);
    
    int arr3[] = {10, 20};
    int *p3 = arr3;
    *++p3;
    printf("arr[0] = %d, arr[1] = %d, *p = %d\n", arr3[0], arr3[1], *p3);
    return 0;
}
