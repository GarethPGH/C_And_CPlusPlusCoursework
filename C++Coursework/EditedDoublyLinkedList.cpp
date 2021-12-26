/*Name: Gareth Warren
Date: 11/16/2021
Class: CIT-245 Z01
IDE: Visual Studio Code with C++ task runner extension using mingw compiler 
to fix "It works on my machine" error: https://www.onlinegdb.com/online_c++_compiler

Chapter 17
Take the code I have written here and change it into a doubly linked list. You cannot write the doubly linked list 
without understanding the singly linked list presented. There are tons of good tutorials on singly and doubly 
linked lists online.

 Written by Professor Kenneth L Moore
 For CIT245 Data Structures and Programming C++
 Edited by Gareth Warren into a Doubly Linked List
*/
#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;
// define a node for storage and linking
class node{ 
public:
    string name; 
    node *next;
    node *prev; 
};
class linkedList{
public:
    linkedList():top(NULL){}
    bool empty(){return top == NULL;}
    node *getTop(){return top;}
    node *getEnd(){return end;}
    void setTop(node *n){top = n;}
    void setEnd(node *n){end = n;}
    void add(string);
    void remove(string, linkedList &list);
    void reversePrint(node *n);
    int menu();
    ~linkedList();
    friend ostream& operator << (ostream&, const linkedList&); // default output is in-order print.
private:
    node *top;
    node *end; 
};

int main(){
    linkedList list;
    cout << list.empty() << endl;
    int option = 0;
    string s;
    bool go = true;
    
    while(go){
        option = list.menu();
        
        switch(option){
            case 1:
            {
                cout << "enter a name: ";
                cin >> s; 
                list.add(s); 
                break;
            }
            case 2:
            { 
                cout << "enter name to be deleted: ";
                cin >> s; 
                list.remove(s, list);
                break;
            }
            case 3:{ 
                cout << list; 
                break;
            }
            case 4:
            {
                node *n = list.getEnd();
                list.reversePrint(n);
                break;
            }
            default:
            { 
                cout << "exiting" << endl; 
                go = false; 
                break;
            }
        }
    }
 // list goes out of scope and calls ~linkedList()
    system("pause");
    return 0;
}

// can not call this method "delete" - "delete" is a reserved keyword.
void linkedList::remove(string s, linkedList &list){
    bool found = false;
    //Passed list by reference to be sure that this does not create a false copy
    node* curr = list.getTop();
       
    while(found == false && &curr != NULL){
        // not found, advance pointers
        if(strcmp(curr->name.c_str(), s.c_str()) != 0){
            curr = curr->next;
        }else{
            //match found
            found = true;    
               
            // Is head, no other nodes
            if(curr->prev == NULL && curr->next == NULL){
                setTop(NULL);
                //At Top of list, but other nodes
            }else if(curr->prev == NULL && curr->next != NULL){
                setTop(curr->next);
                curr->next->prev = NULL;
                // found in list - not top
            }else if(curr->next != NULL && curr->prev != NULL){  
                curr->next->prev = curr->prev;
                curr->prev->next = curr->next;
                //If curr is End, Reset End
            }else if(curr->next == NULL && curr->prev != NULL){
                curr->prev->next = NULL;
                setEnd(curr->prev);
            }
            delete(curr);
        }
    } 
    if(found == true){
        cout << "Deleted " << s << endl;
    }else{ 
        cout << s << " Not Found "<< endl;
    }
}

//Add Values to List in Sorted order, assign Top and End as Needed to preserve links
void linkedList::add(string s){
    node *n = new node();
    n->name = s;
    n->next = NULL;
    n->prev = NULL;
    // take care of empty list case
    if(empty()){
        setTop(n);
    // take care of node belongs at beginning case: value > 0 if n->name is less than curr->name
    }else if( getTop() != NULL && strcmp( getTop()->name.c_str(), s.c_str() ) >= 0 ){
        n->next = getTop();
        n->next->prev = n;
        setTop(n);
    // take care of` inorder and end insert
    }else{
        node *curr = getTop();
        // insert in order case after head: value > 0 if curr->name < n->name, name belongs lower on list
        while( curr->next != NULL &&  strcmp( curr->next->name.c_str(), s.c_str() ) < 0){
            curr = curr->next;
        }

        //Put N after curr
        //N next points to curr next
        n->next = curr->next;
        //If curr next is not NULL, then whatever next prev will point to N
        if( curr->next != NULL ){ 
            curr->next->prev = n;
        }
        //Curr next now points to N
        curr->next = n;
        //N will be after Curr, so N prev points to curr
        n->prev = curr;
        
        //If N next is Null, N is end of list
        if( n->next == NULL ){
            setEnd(n);
        }
    } 
}

//Print the List in Reverse
void linkedList::reversePrint(node *n){
    if(getTop() != NULL){
        n = getEnd();
        while(n != NULL){
            std::cout << n->name << endl; 
            n = n->prev;
        }
        std::cout << std::endl;
    }else{
        cout << "List is Empty" << endl;
    }
}
 
ostream& operator << (ostream& os,const linkedList& ll){
    //linkedList x = ll; // put this in and the code blows up - why?

    /*This is a normal assignment operator, that is assigning the same address of the linked list to a separate linked list variable.
    *It only recieves a copy of the address in the first node, just like in normal reference variable assignment. 
    *Without using a proper copy constructor, the variable is not actually a copy of the linked list
    *And there is no guarantee that the next or prev pointers will point to anything.
    *When they are read, they only return garbage data, or try to access memory locations that they are not assigned to.*/
   
    node *n = ll.top;
    if(n == NULL)cout << "List is empty." << endl;
    else
    while(n != NULL){
        os << n->name << endl;
        n = n->next;
    }
    cout << endl;
    return os;
}

// return memory to heap
linkedList::~linkedList(){
    cout << "~linkedList called." << endl;
    node *curr = getTop(), *del;
    while(curr != NULL){
        del = curr;
        curr = curr->next;
    delete(del);
    }
}

int linkedList::menu(){
    int choice = 0;
    char selection[10];
        cout << "\nEnter your choice" << endl;
        cout << " 1. Add a name." << endl;
        cout << " 2. Delete a name." << endl;
        cout << " 3. Show list." << endl;
        cout << " 4. Show reverse list. " << endl; 
        cout << " 5. EXIT " << endl;
    while(choice <= 0){
        fgets(selection, 9, stdin);
        
        if(isdigit(selection[0])){
            choice = atoi(selection);
            if(choice < 1 || choice > 5){
                cout << "Invalid selection, Try Again" << endl;
                choice = -1;
            }
        }
    }
    return choice;
}
