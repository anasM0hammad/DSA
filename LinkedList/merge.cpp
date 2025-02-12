#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

Node* createLL(vector<int> arr){
    Node* head = nullptr;

    for(auto i: arr){
        if(!head){
            Node* node = new Node(i);
            head = node;
        }
        else{
            Node* node = new Node(i);
            node->next = head;
            head = node;
        }
    }
    return head;
}

void printLL(Node* head){
    while(head){
        cout<<head->data<<"->";
        head = head->next;
    }
}

int main(){
    vector<int> arr1 = { 10,7,5,1 };
    vector<int> arr2 = { 6,3,2 };
    Node* head1 = createLL(arr1); 
    Node* head2 = createLL(arr2);

    Node* head3 = nullptr;
    Node* tail = nullptr;

    while(head1 && head2){
        Node* temp = nullptr;
        if(head1->data < head2->data){
            temp = head1;
            head1 = head1->next;
            temp->next = nullptr;
        }
        else{
            temp = head2;
            head2 = head2->next;
            temp->next = nullptr;
        }

        if(head3){
            tail->next = temp;
            tail = temp;
        }
        else{
            head3 = temp;
            tail = temp;
        }
    }

    if(head1 == nullptr){
        tail->next = head2;
    }

    if(head2 == nullptr){
        tail->next = head1;
    }

    printLL(head3);

    return 0;
}