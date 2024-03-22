#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int value;
    Node *next;
    Node *previous;

    Node(){
        value = 0;
        next = NULL;
        previous = NULL;
    }
    Node(int val){
        value = val;
        next = NULL;
        previous = NULL;
    }
};
class LinkedList{
    Node *head;
    Node *tail;
public:
    LinkedList(){
        tail = NULL;
    }
    LinkedList(int val){
        Node *newNode = new Node(val);
        tail = newNode;
    }
    void insertNode(int val){
        Node *newNode = new Node(val);
        if(tail == NULL){ tail = newNode; head = newNode; }
        else{
            Node *tmp = tail;
            while(tmp->previous != NULL){
                tmp = tmp->previous;
            }
            newNode->next = tmp;
            tmp->previous = newNode;
            head = tmp->previous;
        }
    }
    void printAll(){
        Node *tmp = head;
        while(tmp != NULL){ cout << tmp->value << ' '; tmp = tmp->next; } //{ tmp = tmp->next; }
        //while(tmp != NULL) tmp = tmp->next;
        //while(tmp != NULL){ cout << tmp->value << ' '; tmp = tmp->previous; }
    }
};
int main()
{
    LinkedList List;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x; List.insertNode(x);
    }
    List.printAll();
}
