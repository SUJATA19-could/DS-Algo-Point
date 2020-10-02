/*The C program to reverse a linked list
  
  The Time Complexity of this program is O(n)
  
  The Space Complexity of this program is O(1)

*/
 
#include <stdio.h> 
#include <stdlib.h> 
  
/* Link list node */
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
/* Function to reverse the linked list */
static void reverse(struct Node** head_ref) 
{ 
    struct Node* prev = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next = NULL; 
    while (current != NULL) { 
        // Store next 
        next = current->next; 
  
        // Reverse current node's pointer 
        current->next = prev; 
  
        // Move pointers one position ahead. 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
  
/* Function to push a node */
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
  
/* Function to print linked list */
void printList(struct Node* head) 
{ struct Node* temp = head; 
    while (temp != NULL) { 
        printf("%d  ", temp->data); 
        temp = temp->next; 
    } 
} 
  
/* Driver program to test above function*/
int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    push(&head, 10); 
    push(&head, 20); 
    push(&head, 30); 
    push(&head, 40);
	push(&head, 50);
	push(&head, 60); 
  
    printf("Given linked list\n"); 
    printList(head); 
    reverse(&head); 
    printf("\nReversed Linked list \n"); 
    printList(head); 
    getchar(); 
} 