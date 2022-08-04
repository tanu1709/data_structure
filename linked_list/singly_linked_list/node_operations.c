/*
  WAP to
    1. create a LL from an array
    2. count number of nodes
    3. sum of the values in LL
    4. max element in a LL
    5. Search an element
    6. Insert a node at any position
    7. Insert in a sorted LL
    8. Delete a node from LL at any position
    9. check if a LL is sorted
    10. remove duplicates from a sorted LL
*/

#include<stdio.h>
#include<stdlib.h>j

struct Node {
  int data;
  struct Node *next;
};

struct Node* create(int a[], struct Node *head, int size) {
  struct Node *current_node;
  head -> data = a[0];
  current_node = head;

  for(int i = 1; i < size; i++) {
    struct Node *node;
    node = (struct Node*)malloc(sizeof(struct Node));
    node -> data = a[i];
    current_node -> next = node;
    current_node = node;
  }
  return head;
}

void display(struct Node *head) {
  struct Node* node = head ;
  printf("Linked list elements are : ");
  while(node != NULL) {
    printf("%d \n", node->data);
    node = node->next;
  }
}

void count(struct Node *head) {
  int c = 0;
  struct Node* node = head ;

  while(node != NULL) {
    c++;
    node = node->next;
  }
  printf("\nCount : %d", c);
}

void sum(struct Node *head) {
  int s = 0;
  struct Node* node = head ;

  while(node != NULL) {
    s += node -> data;
    node = node->next;
  }
  printf("\nSum : %d", s);
}

void max(struct Node *head) {
  int m = 0;
  struct Node *node = head;

  while(node != NULL) {
    if(node -> data > m) {
      m = node -> data;
    }
    node = node -> next;
  }
  printf("\nMax : %d", m);
}

void search(struct Node *head, int target) {
  struct Node *node = head;
  while(node != NULL) {
    if(node -> data == target) {
      printf("\nElement %d is found in LL", target);
      return;
    }
    node = node -> next;
  }
  printf("\nElement %d is not found in LL", target);
}

struct Node* insert_at_nth_pos(struct Node *head, int pos, int node_value) {
  struct Node *curr_node = head;
  struct Node *prev_node = NULL;
  int curr_pos = 1;
  while(curr_node) {
    if(curr_pos == pos) {
      struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
      new_node -> data = node_value;

      if(pos == 1) {
        new_node -> next = head;
        head = new_node ;
      } else {
        new_node -> next = curr_node;
        prev_node -> next = new_node;
      }
      return head;
    }
    prev_node = curr_node;
    curr_node = curr_node -> next;
    curr_pos++;
  }

  if(curr_pos == pos) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = node_value;
    prev_node -> next = new_node;
    new_node -> next = NULL;
    return head;
  }
  return head;
}


int main() {
  int size;
  printf("\nEnter array size: ");
  scanf("%d", &size);
  int a[size];

  printf("\nEnter array element:");
  for(int i = 0; i < size; i++) {
    scanf("%d", &a[i]);
  }

  struct Node *head;
  head = (struct Node*)malloc(sizeof(struct Node));
  head = create(a, head, size);
  display(head);
  count(head);
  sum(head);
  max(head);

  int target;
  printf("\nEnter the element to be searched from linked list :");
  scanf("%d", &target);
  search(head, target);

  int pos, new_node_val;
  printf("\nEnter pos for new node");
  scanf("%d", &pos);
  printf("Enter new node value");
  scanf("%d", &new_node_val);
  head = insert_at_nth_pos(head, pos, new_node_val);
  display(head);
}
