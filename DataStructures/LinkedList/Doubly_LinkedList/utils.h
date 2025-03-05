struct doubly_node{
    int value;
    struct doubly_node *next;
    struct doubly_node *previous;
};
extern struct doubly_node *temp, *head, *new_node, *prev;
extern int length;

void createNode();//done
void printList();
//auch die funktion um die eingabe zu kontrollieren

void insertion();
void insertAtStart();
void insertAtPosition();
void insertAtEnd();

void deletion();
void deleteFromStart();
void deleteFromPosition();
void deleteFromEnd();

