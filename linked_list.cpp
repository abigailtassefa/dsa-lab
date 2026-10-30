#include<iostream>
using namespace std;

struct Node{
    string name;
    int age;
    float height;
    Node *next;
}; Node *head = NULL;

void add_node(){
    Node *temp=new Node;
    cout<<"Enter name: ";
    cin>>temp-> name;
    cout<<"Enter age: ";
    cin>>temp-> age;
    cout<<"Enter height: ";
    cin>>temp-> height;
    temp ->next = NULL;

    if (head == NULL){
        head = temp;
    }
    else{
        Node *current = head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = temp;
    }
}

int main(){

    add_node();
    //print all of the linked list 


    return 0;

}
