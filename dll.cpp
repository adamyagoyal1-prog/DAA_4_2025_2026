#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int findLength(Node* &head){
    Node* temp = head;
    int len = 0;

    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    //LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
    Node* newNode = new Node(data);
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    }
}

// void insertAtTail(Node* &head, Node* &tail, int data){
//     if(head == NULL){
//         Node* newNode = new Node(data);
//         head = newNode;
//         tail = newNode;
//     }
//     else{
//         Node* newNode = new Node(data);
//         tail->next = newNode;
//         newNode->prev = tail;
//         tail = newNode;
//     }
// }
// void insertAtPos(Node* &head, Node* &tail, int pos, int data){
//     if(head == NULL){
//         Node* newNode = new Node(data);
//         head = newNode;
//         tail = newNode;
//     }
//     else if(pos == 1){
//         insertAtHead(head, tail, data);
//     }
//     int len = findLength(head);
    
//     if(pos == len + 1){
//         insertAtTail(head, tail, data);
//     }
//    else{
//     Node* newNode = new Node(data);
//     Node* prev = NULL;
//     Node* curr = head;
   
//     while(pos != 1){
//         pos--;
//         prev = curr;
//         curr = curr->next;
//     }
//     prev->next = newNode;
//     newNode->prev = prev;
//     newNode->next = curr;
//     curr->prev = newNode;
// }
// }

void deleteNode(Node* &head, Node* &tail, int pos){
    int len = findLength(head);
    if(head == NULL){
        //corner case
        cout << "Cannot delete since LL is empty" << endl;
        return;
    }
     
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    else if(pos == 1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
    
    else if(pos == len){
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;
        while(pos != 1){
            pos--;
            prev = curr;
            curr = curr->next;
        }
        Node* nextNode = curr->next;
        prev->next = nextNode;
        nextNode->prev = prev;
        curr->prev = NULL;
        curr->next = NULL;
       
        delete curr;
        
    }
}

int main(){

   Node* head = NULL;
   Node* tail = NULL;
   insertAtHead(head, tail, 40);
   insertAtHead(head, tail, 30);
   insertAtHead(head, tail, 20);
   insertAtHead(head, tail, 10);
   cout << "Original list: \n";
   print(head);
   cout << endl;
//    cout << endl;
//    insertAtTail(head, tail, 50);
//    print(head);
//    cout << endl;
//    insertAtPos(head, tail, 2, 25);
//    print(head);
   deleteNode(head, tail, 3);
   cout << "After Deleting Head. \n";
   print(head);
    return 0;
}