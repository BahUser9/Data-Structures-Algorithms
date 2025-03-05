#include<stdio.h>
#include<stdlib.h>
#include "utils.h"

struct doubly_node *head=NULL;
struct doubly_node *new_node=NULL;
struct doubly_node *temp=NULL;
int length=0;

void createNode(){
    new_node = (struct doubly_node*) malloc(sizeof(struct doubly_node));


    if (new_node == NULL) //memory allocation failed 
    {
        printf("failed to create the node\n");
    }
    else
    {
        printf("enter the value [int] : \n");
        scanf("%d",&new_node->value); //could also access it using (*new_node.value);

        new_node->next=NULL;
        new_node->previous=NULL;
        length++; //will count successful created nodes
    }

}

int main(int argc, char const *argv[])
{
    
    //lets test the insertion at start
    int i=0;
    do
    {
        createNode(); //will create a node

        temp=head; //*temp pointing to the 1st node, just like the head pointer
        new_node->next=head; //linking the new one to the existing list, if there is one
        head = new_node;//actualise the head, so that it now points to the new one

        if (temp!=NULL) //is there a 2nd node ? then move temp to the 2nd and link it to the new one by actualising its preview 
        {
            temp=new_node->next;
            temp->previous=new_node;
        }

        printf("you enterred : %d\n", new_node->value);
       i++;
    } while (i<3);

    //lets now print the list, 1st without using length
    printf("\n");
    temp = head;
    while (temp!=NULL)
    {
        printf("%d --> ", temp->value);
        temp = temp->next;


    }
    printf("NULL\n");


    



    
    
    return 0;
}
