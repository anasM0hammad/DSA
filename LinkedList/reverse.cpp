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

Node* reverseLL(Node* head){
    if(!head) return nullptr;

    if(!head->next){
        return head;
    }

    Node* rhead = reverseLL(head->next);
    head->next->next = head;
    head->next = nullptr;

    return rhead;
}

int main(){
    vector<int> arr = { 1,2,3,4,5 };
    Node* head = createLL(arr);   // LL = 5->4->3->2->1

    Node* rhead = reverseLL(head);

    printLL(rhead);

    return 0;
}