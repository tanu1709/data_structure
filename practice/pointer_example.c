// WAP to accept integer value and print its addresses using pointers:

#include<stdio.h>
int main() {
  int a;
  int *p;
  p = &a;
  printf("Enter a:");
  scanf("%d", &a);
  printf("Address of %d: %p", a, p);
}
