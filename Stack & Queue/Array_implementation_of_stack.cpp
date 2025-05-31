#include<iostream>
#include<vector>
using namespace std;

class Stack{
    public:
    int top = -1;
    vector<int> stc;

    void push(int x){
        stc.push_back(x);
        top++;
    }

    void pop(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return;
        }
        stc.pop_back();
        top--;
    }

    int peek(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stc[top];
    }
    void display(){
        if(top == -1){
            cout << "Stack is empty" << endl;
            return;
        }
        for(int i = top; i >= 0; i--){
            cout << stc[i] << " ";
        }
        cout << endl;
    }

    bool isEmpty(){
        return top == -1;
    }

    int size(){
        return top + 1;
    }
};

int main(){
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "Top element: " << s1.peek() << endl;
    s1.pop();
    cout << "Top element after pop: " << s1.peek() << endl;
    s1.pop();
    s1.display();

}