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

struct Node* insert_between(struct Node *head, int item, int index) {
  struct Node* new_node;
  new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node -> data = item;
  struct Node* current_node = head;

  int i = 1;
  while(current_node != NULL) {
    if(i == index) {
      new_node -> next = current_node -> next;
      current_node -> next = new_node;
      break;
    }
    current_node = current_node -> next;
    i++;
  }

  return head;
}

int main() {
  int item, new_item, index;
  struct Node* head;
  head = (struct Node *)malloc(sizeof(struct Node*));

  printf("Enter first Item to insert");
  scanf("%d", &item);
  insert_first_node(head, item);

  printf("Enter item to insert at first node");
  scanf("%d", &new_item);
  head = insert_at_first(head, new_item);
  printf("Enter item to insert at first node");
  scanf("%d", &new_item);
  head = insert_at_first(head, new_item);
  printf("Enter item to insert at first node");
  scanf("%d", &new_item);
  head = insert_at_first(head, new_item);

  // printData(head);


  printf("Enter index to insert after node");
  scanf("%d", &index);
  printf("Enter item to insert in between");
  scanf("%d", &new_item);
  head = insert_between(head, new_item, index);

  printData(head);
}
