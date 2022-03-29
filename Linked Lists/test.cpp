#include <iostream>

using namespace std;

//Node is a standard reference to an element in a linked list

class Node {
    public: 
    int Value;
    Node* Next;
};

void printList(Node* n) {
    //while node is not null print the current value and then move to next node
    while (n != NULL){
        cout << n->Value << endl;
        n = n->Next;
    }
}

int main () {

    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->Value = 1;
    head->Next = second;

    // the next value of the current node is the next node class pointer in the linked list
    second->Value = 2;
    second->Next = third;

    third->Value = 3;
    third->Next = NULL;

    printList(head);

    //delete memory used
    delete head;
    delete second;
    delete third;

    
}