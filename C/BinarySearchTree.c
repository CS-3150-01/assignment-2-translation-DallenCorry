#include <stdio.h>
#include <stdlib.h>

int numOfBST(int);
int factorial(int);
struct Node* createNewNode(int data);

//Represent the node of binary tree 
struct Node {    
    int data;    
    struct Node* left;    
    struct Node* right;       
};



int main() {
    //Represent the root of binary tree. Currently points to nothing
    struct Node* root = createNewNode(0);

    //Display total number of possible binary search tree with key 5    
    int ans = numOfBST(5);
    printf("Total number of possible Binary Search Trees with given key: %d", ans);    
    return 0;
}

//Create the Constructor
struct Node* createNewNode(int data) {
    struct Node* myNode = (struct Node*)malloc(sizeof(struct Node));
    myNode->data = data;
    myNode->left = NULL;
    myNode->right = NULL;
    return myNode;
}

//numOfBST() will calculate the total number of possible BST by calculating Catalan Number for given key
int numOfBST(int key) {    
    int catalanNumber = factorial(2 * key)/(factorial(key + 1) * factorial(key));    
    return catalanNumber;    
}    

//factorial() will calculate the factorial of given number 
int factorial(int num) {    
    int fact = 1;    
    if(num == 0)    
        return 1;    
    else {    
        while(num > 1) {    
            fact = fact * num;    
            num--;    
        }    
        return fact;    
    }    
}   