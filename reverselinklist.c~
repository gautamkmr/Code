#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* Function to reverse the linked list */
static void reverseIterative(struct node** head_ref)
{
  if(*head_ref==NULL|| (*head_ref)->next==NULL)
   return;
  
  struct node *curr = *head_ref;
  struct node *prev =  NULL;
  struct node *next;
  while(curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head_ref = prev;
}
 
static void reverseRecursive(struct node** head_ref)
{
  if(*head_ref==NULL|| (*head_ref)->next==NULL)
   return;

  struct node *first = *head_ref;
  struct node *last = (*head_ref)->next;
  reverseRecursive(&last);
  first->next->next = first;
  first->next = NULL;
  *head_ref = last;
}
/* Function to push a node */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
            
    /* put in the data  */
    new_node->data  = new_data;
                
    /* link the old list off the new node */
    new_node->next = (*head_ref);   
        
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);   
        temp = temp->next; 
    }
    printf("\n");
}   
 
/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
   
     push(&head, 20);
     push(&head, 4);
     push(&head, 15);
     push(&head, 85);     
     
/*
     printList(head);   
     reverseRecursive(&head);                     
     printf("\n Reversed Linked list \n"); */
     printList(head);   
     struct node *tmp =head;
     int i=0;
     while(i<2)
     {
       tmp =tmp->next;
       i++;
     }
     tmp->next = NULL;
     printList(head);
     getchar();
}
