// WAP to accept 2 nos and swap the values using pass by reference:

#include<stdio.h>
void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int x, y;
  printf("Enter x & y:");
  scanf("%d %d", &x, &y);

  swap(&x, &y);
  printf("Value of x and y respectively are %d and %d\n", x, y);
  return 0;
}
