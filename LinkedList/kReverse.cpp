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

Node* kReverse(Node* head, int k){
    if(!head || !head->next) return head;

    Node* prev = nullptr;
    Node* cur = head;
    Node* next = head->next;
    int count = 0;

    while(count < k && cur){
        cur->next = prev;
        prev = cur;
        cur = next;
        if(cur){
            next = next->next;
        }
        count++;
    }
    Node* rh = kReverse(cur, k);
    head->next = rh;
    return prev;
}

int main(){
    vector<int> arr = { 8,7,6,5,4,3,2,1 };
    Node* head = createLL(arr);
    // printLL(head);

    int k=3;

    Node* rhead = kReverse(head, k);
    printLL(rhead);
    return 0;
}