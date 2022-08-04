#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void insert_first_node(struct Node *head, int item) {
  head->data = item;
  head->next = NULL;
}

struct Node* insert_at_first(struct Node *head, int item) {
  struct Node *new_node;
  new_node = (struct Node*)malloc(sizeof(struct Node*));
  new_node -> data = item;
  new_node -> next = head;
  return new_node;
}

void printData(struct Node* head) {
  struct Node* node = head ;
  while(node != NULL) {
    printf("%d \n", node->data);
    node = node->next;
  }
}

int main() {
  int item, new_item;
  struct Node* head;
  head = (struct Node *)malloc(sizeof(struct Node*));

  printf("Enter first Item to insert");
  scanf("%d", &item);
  printf("Enter item to insert at first node");
  scanf("%d", &new_item);

  insert_first_node(head, item);
  head = insert_at_first(head, new_item);
  printData(head);
}
