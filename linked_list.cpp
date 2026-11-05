#include<iostream>
using namespace std;

struct  Student{
    string name;
    int ID;
     Student *next;
};  Student *head = NULL;

void add_Student_to_end(){
     Student *temp=new  Student;
    cout<<"Enter name: ";
    cin>>temp-> name;
    cout<<"Enter ID: ";
    cin>>temp-> ID;
    temp ->next = NULL;

    if (head == NULL){
        head = temp;
    }
    else{
         Student *current = head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = temp;
    }
}

void add_Student_to_beginning(){
     Student *temp=new  Student;
    cout<<"Enter name: ";
    cin>>temp-> name;
    cout<<"Enter ID: ";
    cin>>temp-> ID;
    temp ->next = head;
    head = temp;

}


void add_Student_at_position(int position){
    Student *temp=new  Student;
    cout<<"Enter name: ";
    cin>>temp-> name;
    cout<<"Enter ID: ";
    cin>>temp-> ID;

    if (position == 0) {
        temp->next = head;
        head = temp;
        return;
    }

     Student *current = head;
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds." << endl;
        delete temp; // Free the allocated memory
        return;
    }

    temp->next = current->next;
    current->next = temp;
}


void printList( Student* head) { //display forward
    
     Student* current = head;
    while (current != nullptr) {
        cout <<"Linked_List: " << current->name << " " << current->ID << " " << endl;
        current = current->next;
    }
}

int main(){


    add_Student_to_end();
    cout<<" Student added to end: ";
    printList(head);

    add_Student_to_beginning();
    cout<<" Student added to the beginning";
    printList(head);


    int pos;
    cout<<"Enter a position: ";
    cin>>pos;
    add_Student_at_position(pos);
    cout<<"Student added at a position: ";
    printList(head);
    

    return 0;

}
