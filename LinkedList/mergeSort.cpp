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

Node* merge(Node* head1, Node* head2){
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
    return head3;
}

Node* findMid(Node* head){
    if(!head || !head->next) return head;

    Node* fast = head;
    Node* slow = head;

    while(!fast->next && !fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    Node* mid = slow->next;
    slow->next = nullptr;

    return mid;
}

Node* mergeSort(Node* head){
    if(!head || !head->next) return head;

    Node* mid = findMid(head);

    Node* sorted1 = mergeSort(head);
    Node* sorted2 = mergeSort(mid);

    return merge(sorted1, sorted2);
}

int main(){
    vector<int> arr = { 7,8,4,5,6,1,2,3 };
    Node* head = createLL(arr);

    Node* sorted = mergeSort(head);

    printLL(sorted);

    return 0;
}