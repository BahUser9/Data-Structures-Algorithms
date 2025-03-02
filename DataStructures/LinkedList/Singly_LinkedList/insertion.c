#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


void insertAtPosition(){
    /*position > length? error
    position == 1 ? insertAtStart() abrufen
*/
    //printf("Position: \n");
    if (head == NULL)
    {
        insertAtStart();
    }
    
    int position = choiceControll(length);
    //scanf("%d",&position);

    if (position == 1)
    {
        insertAtStart();
    }
    

    createNode();
    temp = head;
    int count=1;

    while (count < (position-1)) //until one node before the Position to insert
    {
        temp = temp->next_node;
        count++;
    }
    new_node->next_node = temp->next_node; //right link the new node to the given index
    temp->next_node = new_node;//left link the new node to the list 
    
    printf("success ! inserted at Position %d\n",position);
    
}


void insertAtStart(){

    createNode(); //a node will be created and address given to new_node(which is Global)

    new_node->next_node = head;//linking the new node to the list
    head = new_node; //update head, so that it now points to the new beginning

    printf("success ! insert atStart\n");
}



void insertAtEnd(){//create a node at the end


    if (head == NULL)//the list is empty, 1st adding
    {
        insertAtStart;
    }
                    
    else//list is not empty
    {
        createNode();
        temp = head; 

        while (temp->next_node!=NULL)//starting from head, temp will traverse all the list untill it reaches NULL
        {
            temp = temp->next_node; 
        }
                        
        temp->next_node = new_node; //link the new node to the existing list
        //temp = new_node; //update the address of temp, so that it points to the new one
    }


    printf("success ! inserted atEnd\n");
              
}

void insertion(){
    


    while (1)
    {
        system("cls");

        printf("1- insertAtStart\n");
        printf("2- insertAtPosition\n");
        printf("3- insertAtEnd\n");
        printf("4- Print the List\n");
        printf("5- Back\n");;
        int choice = choiceControll(5);


        switch (choice)
        {
            system("cls");

            case 1:
                insertAtStart();
                break;
            case 2:
                insertAtPosition();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                printList();
            default:
                break;
        }
        if (choice==5)
        {
            break;
        }
        system("pause");
    }


    
}