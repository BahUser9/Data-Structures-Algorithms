void createNode();
int choiceControll(int UP);

void printList();

void insertion();
void insertAtStart();//done
void insertAtPosition();//done
void insertAtEnd();//done

void deletion();
void deleteFromStart();
void deleteFromPosition();
void deleteFromEnd();

struct node
{
    int value;
    struct node *next_node;
};

struct node *head, *new_node, *temp;//head = null
struct node *previous;
int length;//muss 0 
