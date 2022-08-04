// WAP to create 2 nodes in a Linkd List
#include<stdio.h>
#include<stdlib.h>

struct Node {
  int value;
  struct Node* next;
};


void create(struct Node* head, struct Node* second) {
  head = (struct Node*)malloc(sizeof (struct Node));
  second = (struct Node*)malloc(sizeof (struct Node));
}

void insertData(struct Node* head, struct Node* second) {
  head -> value = 1;
  head -> next = second;
  second -> value = 2;
  second -> next = NULL;
}

void printData(struct Node* head) {
  struct Node* node = head ;
  while(node != NULL) {
    printf("%d \n", node->value);
    node = node->next;
  }
}

int main() {
  struct Node *head;
  struct Node *second;
  create(head, second);
  insertData(head, second);
  printData(head);
}
