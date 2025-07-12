#include <bits/stdc++.h>
using namespace std;

class List{
    public:
    int data;
    List* prev;
    List* next;

    public:
    // constructor with an initializer‑list
    List(int val, List* nextNode = nullptr, List* prevNode = nullptr)
        : data(val), prev(prevNode), next(nextNode) {}
};

List* convertArrToDLL(vector<int> &arr){
    if(arr.empty()) return nullptr;
    
    List* head = new List(arr[0]);
    List* current = head;

    for(int i = 1; i < arr.size(); i++){
        List* newNode = new List(arr[i]);
        current -> next = newNode;
        newNode -> prev = current;
        current = newNode;
    }

    return head;
}

void traversDLL(List* head){
    if(head == nullptr){
        cout << "List is Empty! "<< endl;
        return;
    }

    List* current = head;
    while(current != nullptr){
        cout<< current -> data << " ";
        current = current -> next;
    }

    cout << endl;
}

List* insertATStart(List* head, int val){
    if(head == nullptr){
        head = new List(val);
        return head;
    }

    List* temp = new List(val, head);
    head = temp;

    return head;
}

void insertAtMid(List* head, int val, int pos){
    if(head == nullptr){
        cout << "List is Empty! "<< endl;
        return;
    }

    List* current = head;
    for(int i = 1; i < pos -1; i++){
        current = current -> next;
    }

    if (current == nullptr) {
        cout << "Position exceeds list length!" << endl;
        return;
    }

    List* newNode = new List(val, current -> next, current);

    if(current -> next != nullptr)  // if current is not last node
        current -> next -> prev = newNode;

    current -> next = newNode;
}

void insertAtEnd(List* head, int val){

    List* current = head;
    while(current -> next != nullptr){
        current = current -> next;
    }

    List* newNode = new List(val);
    newNode -> prev = current;
    current -> next = newNode;
}

List* delFromStart(List* head){
    if(head == nullptr){
        cout << "List is Empty!" <<endl;
        return nullptr;
    }

    List* temp = head;
    head = head -> next;
    head->prev = nullptr;
    delete temp;

    return head;
}

void delFromMid(List* head, int pos){
    if(head == nullptr){
        cout << "List is Empty!" <<endl;
        return;
    }

    List* current = head;
    for(int i = 1; i < pos-1; i++){
        current = current -> next;
    }

    if (current == nullptr) {
        cout << "Position exceeds list length!" << endl;
        return;
    }

    List* temp = current -> next;
    temp -> next -> prev = current;
    current -> next = temp -> next;
    delete temp; 

}

void delFromEnd(List* head){
    if(head == nullptr){
        cout << "List is Empty!" <<endl;
        return;
    }

    List* current = head;
    while(current -> next != nullptr){
        current = current -> next;
    }

    List* temp = current;
    current -> prev -> next = nullptr;
    delete temp; 
}


int main(){

    vector<int> arr = {2, 5, 65, 64, 43, 543, 66};
    List* head = convertArrToDLL(arr);
    traversDLL(head);

    head = insertATStart(head, 11);
    traversDLL(head);

    insertAtMid(head, 88, 3);
    traversDLL(head);

    insertAtEnd(head, 55);
    traversDLL(head);

    head = delFromStart(head);
    traversDLL(head);

    delFromMid(head, 4);
    traversDLL(head);

    delFromEnd(head);
    traversDLL(head);

    return 0;
}