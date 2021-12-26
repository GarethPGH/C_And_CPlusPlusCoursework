/*Name: Gareth Warren
Date: 11/17/2021
Class: CIT-145 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 

Doubly Linked List using Singly Linked List Code and several tutorials
including Hackerrank, GeeksForGeeks, Blue Tree Code, and Programiz
*/

#pragma warning(disable: 4996)
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

//Modify the linked list example in the book so that it is a doubly linked list

struct listNode { 
    char data; 
    struct listNode *nextPtr; 
    struct listNode *prevPtr;
};

//Prototypes
void Insert(struct listNode** sPtr, char value );
char DeleteNode(struct listNode** sPtr, char value );
int isEmpty(struct listNode** sPtr );
void PrintList(struct listNode* currentPtr );
void PrintListBackwards(struct listNode* currentPtr);
void Instructions( void );

int main( void ){ 
    struct listNode* startPtr = NULL;
    int choice; 
    char item; 
    
    Instructions(); 
    printf( "? " );
    scanf( "%d", &choice );
    
    while ( choice >= 1 && choice <= 4 ) { 
        switch ( choice ) { 
            case 1://Insert an item into the list
                printf( "Enter a character: \n" );
                scanf( "\n%c", &item );
                Insert(&startPtr, item ); 
                break;
            case 2://Remove an item
                if ( !isEmpty(&startPtr ) ) { 
                    printf( "Enter character to be deleted: " );
                    scanf( "\n%c", &item );
                    if ( DeleteNode( &startPtr, item ) ) { 
                        printf( "%c deleted.\n", item );
                    } else {
                        printf( "%c not found.\n\n", item );
                    } 
                }else {
                    printf( "List is empty.\n\n" );
                }
                break;
            case 3: //Print list
                PrintList(startPtr);
                break;
            case 4: //Print List Backwards
                PrintListBackwards(startPtr);
                break;
            default:
                printf( "Invalid choice.\n\n" );
                Instructions();
                break;
        } 
            
        printf( "? " );
        scanf( "%d", &choice );
    } 
    printf( "End of run.\n" );
    return 0;
}

//display program Instructions to user 
void Instructions( void ){ 
    printf( "Enter your choice:\n"
    " 1 to Insert an element into the list.\n"
    " 2 to Delete an element from the list.\n"
    " 3 to Print List.\n"
    " 4 to Print List Backwards\n" 
    " 5 to End");
}

//Insert a new value into the list in sorted order 
void Insert( struct listNode **sPtr, char value ){ 
    struct listNode* newPtr = (struct listNode*)malloc(sizeof(struct listNode));
    struct listNode* currentPtr;
    
    //If malloc succeeds
    if(newPtr != NULL){
        //assign data
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        newPtr->prevPtr = NULL;
        
        //If head is NULL
        if((*sPtr) == NULL){
            //newPtr next is the head previous is NULL
            (*sPtr) = newPtr;

        }else if( (*sPtr) != NULL && (*sPtr)->data >= newPtr->data ){
            //Put node at beginning of list if it's data is less than start
            newPtr->nextPtr = (*sPtr);
            newPtr->nextPtr->prevPtr = newPtr;
            (*sPtr) = newPtr; 

        }else{
            //Put node between two nodes in sorted order
            currentPtr = (*sPtr);
            
            //if current exists, and value of current is less than data, current is next
            while ( currentPtr->nextPtr != NULL && currentPtr->nextPtr->data < newPtr->data) { 
                currentPtr = currentPtr->nextPtr; 
            } 
            //New's next is current next
            newPtr->nextPtr = currentPtr->nextPtr;

            //if next exists, then what next is pointing to prev is newPtr
            if(currentPtr->nextPtr != NULL){
                currentPtr->nextPtr->prevPtr = newPtr;
            }
            //newPtr previous points to current
            currentPtr->nextPtr = newPtr;
            newPtr->prevPtr = currentPtr;
        }
    } else {
        printf( "%c not inserted. No memory available.\n", value );
        return;
    } 
} 

//Delete a list element 
char DeleteNode( struct listNode** sPtr, char value )
{ 
    struct listNode* currentPtr = (*sPtr); 
    while(currentPtr != NULL){
        // not found, advance pointers
        if(currentPtr->data != value){
            currentPtr = currentPtr->nextPtr;
        }
        
        //If Value is Head of List   
        if (currentPtr->prevPtr == NULL && currentPtr->nextPtr == NULL){
            //Empty the List if there is no next pointer
            *sPtr = NULL;
        
        }else if(currentPtr->prevPtr == NULL && currentPtr->nextPtr != NULL){ 
            //Set head to next node
            currentPtr->nextPtr->prevPtr = NULL;
            *sPtr = currentPtr->nextPtr; 
        
        //If Value is not Head of List
        }else if(currentPtr->nextPtr != NULL && currentPtr->prevPtr != NULL) {
            currentPtr->nextPtr->prevPtr = currentPtr->prevPtr;
            currentPtr->prevPtr->nextPtr = currentPtr->nextPtr;
        
        //If Value is at End of List
        }else if(currentPtr->nextPtr == NULL && currentPtr->prevPtr != NULL){
            currentPtr->nextPtr->prevPtr = NULL;
        }
        free(currentPtr);
        currentPtr = NULL;
        return value;
    }
    return '\0';
} 

//Return 1 if the list is empty, 0 otherwise 
int isEmpty( struct listNode** sPtr ){ 
    return (*sPtr) == NULL;
} 

//Print the list 
void PrintList( struct listNode* currentPtr ){
    struct listNode* nxtPtr = NULL;

    if ( currentPtr == NULL ) {
        //If list is empty 
        printf( "List is empty.\n\n" );
    } else { 
        //Print list
        printf( "The list is:\n" );

        while ( currentPtr != NULL ) { 
            printf( "%c --> ", currentPtr->data );
            
            currentPtr = currentPtr->nextPtr; 
        } 
        printf( "NULL\n\n" );
    } 
} 

//Print list backwards
void PrintListBackwards(struct listNode* currentPtr){
    bool run = true;
    if ( currentPtr == NULL ) {
        //If list is empty 
        printf( "List is empty.\n\n" );
    } else { 
        //Print list
        printf( "The list is:\n" );

        //Walk to the end of the list 
        while ( currentPtr->nextPtr != NULL){ 
            currentPtr = currentPtr->nextPtr; // ... next node 
        }

        //While current is not null, print current-> data, current is prev
        while (run){ 
            if(currentPtr->prevPtr == NULL && currentPtr->data != NULL){
                printf( "%c --> NULL \n\n", currentPtr->data); 
                run = false; 
            }else{
                printf( "%c --> ", currentPtr->data ); 
                currentPtr = currentPtr->prevPtr;
            }
        }
    } 
}
 