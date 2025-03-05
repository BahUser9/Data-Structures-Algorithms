#include<stdio.h>
#include<stdlib.h>
#include "utils.h"
//implement traversal function, that traverse untill the last node, for adding and printing(modify the printing code in this case)


struct doubly_node *head=NULL;
struct doubly_node *new_node=NULL;
struct doubly_node *temp=NULL, *prev=NULL;
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

        temp=head; //*temp pointing to the 1st node if it exist, if not *temp=null
        new_node->next=head; //linking the new one to the existing list, if there is one
        head = new_node;//actualise the head, so that it now points to the new one

        if (temp!=NULL) //is there a 2nd node ? 
        {
            temp=new_node->next; //then move temp to the 2nd
            temp->previous=new_node; //link 2nd element to the new one by actualising its preview
        }

        printf("you enterred : %d\n", new_node->value);
       i++;
    } while (i<3);

    
    printf("\nlets now implement adding at the end\n");
    while (i<6)
    {
        createNode();
        
        //traversal funktion
        temp = head;
        while (temp->next!=NULL) //move the *temp untill the last node of the list
        {
            temp = temp->next;
        }
        temp->next=new_node; //link the new element to the end
        new_node->previous = temp;
        i++;
    }
    printf("\nlets now implement adding at a Position\n");

    while (i<8)
    {
        createNode();

        printf("at which Position : ?");
        int position; scanf("%d", &position);
        //traversal funktion(untill position-1)
        //if position = 1? call insertAtStart
        
        temp=head;
        int count=1;

        while (count<(position-1))
        {
            temp=temp->next; //the temp* to the next element
            count++;
        }

        //now we are at the given Position
        new_node->next=temp->next;//link the new node to the next element
        new_node->previous=temp;

        temp->next=new_node;

        temp=new_node->next;//move the temp* to the next
        temp->previous=new_node;//link the next to newly added
        
        i++;
    }
    

    //lets now print the list, using traversal
    printf("\n");
    temp = head;
    while (temp!=NULL)
    {
        //traversal funktion
        printf("%d --> ", temp->value);
        temp = temp->next;


    }
    printf("NULL\n");

    //deletion_PART
    printf("\n\n lets implement delete at Start\n\n");
    temp=head;
    head=head->next; //point head to the next element
    head->previous=NULL;//
    free(temp);
    length--;

    printf("\n\n lets implement delete at End\n\n");
    temp=head;
    int count=1;
    while (temp->next!=NULL)
    {
        temp=temp->next;
        count++;

        if (count == (length-1))
        {
            prev=temp;
        }
        
    }
    prev->next = NULL;
    free(temp);
    length--;

    printf("\n\n lets implement delete at Position\n\n");

    temp = head;
    count=1;
    printf("at which Position? : ");
    int position; scanf("%d", &position);

    while (count<position)
    {
        temp=temp->next;
        count++;

        if (count == (position-1))
        {
            prev=temp;
        } 
    }
    prev->next = temp->next;//change the name of the variable : could be temp statt previous, and change temp to (toDelete)
    prev=temp->next;
    prev->previous = temp->previous;
    free(temp);
    length--;
    
    
        //lets now print the list, using traversal
        printf("\n");
        temp = head;
        while (temp!=NULL)
        {
            //traversal funktion
            printf("%d --> ", temp->value);
            temp = temp->next;
    
    
        }
        printf("NULL\n");
    
    
    return 0;
}
