// WAP to accept n size of an array and print the value and address of each element:

#include<stdio.h>
#include<stdlib.h>
int main() {
  int size;
  printf("Enter size : ");
  scanf("%d", &size);
  int *a = (int *)malloc(size * sizeof(int));

  for(int i = 0; i < size; i++) {
    printf("Enter value at %d location:", i);
    scanf("%d", (a+i));
  }

  for(int i = 0; i < size; i++) {
    printf("\n Value at %d location is %d and its address is %p", i, *(a+i), (a+i));
  }
}
