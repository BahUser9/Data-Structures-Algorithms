/*
-eine struktur für mein LinkedList
-Eine add() um ein Node zu addieren
-eine see_list() um alle Elmente der Liste auszugeben
*/

#include<stdio.h>
#include<stdlib.h>

#include"utils.h"

struct node *head=NULL, *new_node, *temp; 
struct node *previous;
int length = 0;


int choiceControll(int UP){

    int choice;
    do
    {
        printf("\nenter a choice [1-%d]\n", UP);
        scanf("%d", &choice);
        getchar();
        
    }while (choice<=0 || choice>UP);

    return choice;
    
}
void createNode(){
    new_node = (struct node*) malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("node creation failed !\n");
    }
    else
    {
        printf("enter the value : \n");
        scanf("%d", &new_node->value);
        new_node->next_node = NULL;
        length++;
    } 

    //printf("value added to List\n");

}

void printList(){
    temp = head;

    if (head == NULL)
    {
        printf("list is empty!\n\n");
        //system("pause");
        return;
    }
    else{
        printf("-------------- THE LIST -----------------\n");
        while (temp!=NULL)
        {
            printf("%d -> ", temp->value);
            temp = temp->next_node;
        }
        if (temp == NULL){printf("NULL\n");}  
    }

    //system("pause");
}




int main(int argc, char const *argv[])
{

    while (1)
    {
        system("cls");

        printf("1- printList\n");
        printf("2- insertion\n");
        printf("3- deletion\n");
        printf("4- end\n");
        int choice = choiceControll(4);

        switch (choice)
        {
            system("cls");

            case 1:
                printList();
                //system("pause");
                break;
            case 2:
                insertion();
                break;
            case 3:
            deletion();
                break;    
            default:
                break; //break only switch
        }

        if (choice==4)
        {
            break; //will break while(1)
        }
        if(choice == 1){system("pause");}
        
        
    }
    



    return 0;
}
