#include <bits/stdc++.h>
using namespace std;


// A simple implementation of a singly linked list using a struct Node.
// struct Node {
//     int data;
//     Node* next;

//     public:
//     Node(int val, Node* nextNode = nullptr){
//         data = val;
//         next = nextNode;
//     }
// };

class List {
    public:
    int data;
    List* next;

    public:
    List(int val, List* nextNode = nullptr){
        data = val;
        next = nextNode;
    }
};

List* convertArrToLL(vector<int> &arr){
    List* head = new List(arr[0]);
    List* current = head;

    for(int i = 1; i < arr.size(); i++){
        List* newNode = new List(arr[i]);
        current->next = newNode;
        current = newNode;
    }

    return head;
}

void traversLL(List* head){
    List* current = head;

    while(current != nullptr){
        cout << current -> data << " ";
        current = current -> next;
    }

    cout << endl;
}

List* insertATStart(List * head, int val){
    List* newNode = new List(val);
    newNode -> next = head;

    head = newNode;

    return head;
}

void insertAtMid(List *head, int val, int pos){
    List* newNode = new List(val);
    List* current = head;

    for(int i = 1; i < pos-1; i++){
        current = current -> next;
    }

    newNode -> next = current -> next;
    current -> next = newNode;
}

void insertAtEnd(List *head, int val){
    List* newNode = new List(val);
    List* current = head;

    while(current -> next != nullptr){
        current = current -> next;
    }

    current -> next = newNode;
}

List* delFromStart(List* head){

    if(head == nullptr){
        cout << "List is empty!" << endl;
        return head;
    }
    List* temp = head;
    head = head -> next;
    delete temp;

    return head;
}


void delFromMid(List* head, int pos){
    if(head == nullptr){
        cout << "List is empty!" << endl;
        return;
    }

    List* current = head;
    for(int i = 1; i < pos - 1; i++){
        current = current -> next;
    }
    List* temp = current;
    current -> next = current -> next -> next;
    delete temp;
}

void delFromEnd(List *head){
    if(head == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    
    List* current = head;
    
    while(current -> next != nullptr){
        current = current -> next;
    }

    List* temp = current;
    current -> next = nullptr;
    delete temp;
}


int main(){
    vector<int> arr = {22, 34, 43, 1, 23, 5};
    
    List* head = convertArrToLL(arr);
    traversLL(head);

    head = insertATStart(head, 12);
    head = insertATStart(head, 99);
    traversLL(head);

    insertAtMid(head, 66, 4);
    insertAtMid(head, 21, 8);

    insertAtEnd(head, 10);

    traversLL(head);

    head = delFromStart(head);
    traversLL(head);

    delFromMid(head, 4);
    traversLL(head);
 
    delFromEnd(head);
    traversLL(head);
}