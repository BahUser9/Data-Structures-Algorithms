#include<stdio.h>
#include<stdlib.h>
#include"utils.h"


void deleteFromEnd(){
    if (length == 1) //only one node created? that is like deleting from the Start
    {
        deleteFromStart();
    }
    else{deleteFromPosition(length);}
    //printf("last element deleted\n");
    
}

void deleteFromPosition(int position){
    
    
    if (position == 1)
    {
        deleteFromStart();
    }

    temp = head;
    int count=1;

    
    while (count<position)
    {
        if (count == (position-1))
        {
            previous=temp;
        }
        temp=temp->next_node;
        count++;
    }
    previous->next_node = temp->next_node;
    free(temp);
    length--;

    if(position!=length){printf("element at Position %d deleted\n", position);}
    
    
}


void deleteFromStart(){
    
    temp = head;
    head=head->next_node;
    free(temp);
    length--;
    printf("1st element deleted\n");

}

void deletion(){


    while (1)
    {
        system("cls");

        printf("1 - deleteFromStart\n");
        printf("2 - deleteFromPosition\n");
        printf("3 - deleteFromEnd\n");
        printf("4 - Back\n");

        int choice = choiceControll(4);
        if (choice !=4 && head == NULL)
        {
            printf("list is empty !\n");
            return;
        }

        switch (choice)
        {
            case 1:
                deleteFromStart();
                break;
            case 2:
                //printf("enter position to delete: \n");
                int position = choiceControll(length);
                //scanf("%d",&position);
                deleteFromPosition(position);
                break;
            case 3:
                deleteFromEnd();
                break;
            default:
                break;
        }
        
        if(choice == 4){break;}
        system("pause");
        
    }
    
    
    
}