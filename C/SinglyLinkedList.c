#include <stdio.h>
#include <stdlib.h>

struct Node* head = NULL;    
struct Node* tail = NULL;

void addNode(int data);
void display();

int main() {
    //Represent the head and tail of the singly linked list    
        
    //Add nodes to the list    
    addNode(1);    
    addNode(2);    
    addNode(3);    
    addNode(4);    
        
    //Displays the nodes present in the list    
    display();      

    return 0;
}

    //Represent a node of the singly linked list    
    struct Node{    
        int data;    
        struct Node* next;   
    };
     
    struct Node* makeNewNode(int data) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
    }

    //addNode() will add a new node to the list    
    void addNode(int data) {    
        //Create a new node    
        struct Node* newNode;// = makeNewNode(data);    
            newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        //Checks if the list is empty    
        if(head == NULL) {    
            //If list is empty, both head and tail will point to new node  
            head = newNode;
            tail = newNode;
        }    
        else {    
            //newNode will be added after tail such that tail's next will point to newNode  
            tail->next = newNode; 
            //newNode will become new tail of the list    
            tail = newNode;
        }    
    }    
        
    //display() will display all the nodes present in the list    
    void display() {    
        //Node current will point to head    
        struct Node* current = head;   //How to get access to head? do Local variables work lik this in C? 
            
        if(head == NULL) {    
            printf("List is empty\n");    
            return;    
        }    
        printf("Nodes of singly linked list: \n");    
        while(current != NULL) {    
            //Prints each node by incrementing pointer    
            printf("%d", current->data);    
            current = current->next;    
        }    
        printf("\n");    
    }    
     
