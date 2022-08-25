/*
  WAP to
    1. create a LL from an array
    2. Display a LL
    3. count number of nodes
    4. sum of the values in LL
    5. max element in a LL
    6. Search an element
    7. Insert a node at any position
    8. Sort an LL using selection technique
    9. Delete a node from LL at any position
    10. check if a LL is sorted
    11. remove duplicates from a sorted LL
    12. remove duplicates from a LL
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
  int data;
  struct Node *next;
};

//1. create a LL from an array
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

//2. Display a LL
void display(struct Node *head) {
  struct Node* node = head ;
  printf("\nLinked list elements are : ");
  while(node != NULL) {
    printf("%d \n", node->data);
    node = node->next;
  }
}


//3. count number of nodes
void count(struct Node *head) {
  int c = 0;
  struct Node* node = head ;

  while(node != NULL) {
    c++;
    node = node->next;
  }
  printf("\nCount : %d", c);
}

//4. sum of the values in LL
void sum(struct Node *head) {
  int s = 0;
  struct Node* node = head ;

  while(node != NULL) {
    s += node -> data;
    node = node->next;
  }
  printf("\nSum : %d", s);
}

//5. max element in a LL
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

//6. Search an element
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

//7. Insert a node at any position
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

//10. Delete a node from LL at any position
struct Node* delete_at_nth_pos(struct Node *head, int pos) {
  struct Node *curr_node = head;
  struct Node *prev_node = NULL;
  int curr_pos = 1;

  while(curr_node != NULL) {
    if(pos == 1) {
      head = curr_node -> next;
      free(curr_node);
      return head;
    }
    if(curr_pos == pos) {
      prev_node -> next = curr_node -> next;
      free(curr_node);
      return head;
    }
    curr_pos++;
    prev_node = curr_node;
    curr_node = curr_node -> next;
  }

  return head;
}

//11. check if a LL is sorted
void check_sorted(struct Node *head) {
  printf("\nEnter order to check the LL:");
  char order[4];
  scanf("%s", order);

  struct Node *curr_node = head;
  struct Node *prev_node = NULL;
  int flag = 0;

  while(curr_node) {
    if(curr_node -> next == NULL) {
      break;
    }
    prev_node = curr_node;
    curr_node = curr_node -> next;

    if(strcmp(order, "asc") == 0) {
      if(curr_node -> data > prev_node -> data) {
        flag = 1;
        continue;
      }
      flag = 0;
      break;
    } else if(strcmp(order, "desc") == 0) {
      if(curr_node -> data < prev_node -> data) {
        flag = 1;
        continue;
      }
      flag = 0;
      break;
    }
  }
  if(flag == 0){
    printf("\nNot sorted");
  } else {
    printf("\nSorted");
  }
}

//12. remove duplicates from a sorted LL
void remove_duplicates_from_sorted_ll(struct Node *head) {
  struct Node *curr_node = head;
  struct Node *prev_node = NULL;

  while(curr_node) {

    if(prev_node && (prev_node -> data == curr_node -> data)) {
      prev_node -> next = curr_node -> next;
      free(curr_node);
      curr_node = prev_node -> next;
    } else {
      prev_node = curr_node;
      curr_node = curr_node -> next;
    }
  }
}

//13. remove duplicates from a LL
void remove_duplicates_from_unsorted_ll(struct Node *head) {
  struct Node *curr_node = head;
  struct Node *curr_node_next = NULL;
  struct Node *prev_node = NULL;

  while(curr_node) {
    curr_node_next = curr_node -> next;
    prev_node = curr_node;

    while(curr_node_next) {

      if(curr_node -> data == curr_node_next -> data) {
        prev_node -> next = curr_node_next -> next;
        free(curr_node_next);
        curr_node_next = prev_node -> next;
      } else {
        prev_node = curr_node_next;
        curr_node_next = curr_node_next -> next;
      }
    }
    curr_node = curr_node -> next;
  }
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
  printf("\nEnter new node value");
  scanf("%d", &new_node_val);
  head = insert_at_nth_pos(head, pos, new_node_val);
  display(head);

  int del_pos;
  printf("\n Enter aposition to delete node from:");
  scanf("%d", &del_pos);
  head = delete_at_nth_pos(head, del_pos);
  display(head);

  check_sorted(head);

  remove_duplicates_from_sorted_ll(head);
  display(head);

  remove_duplicates_from_unsorted_ll(head);
  display(head);

}
