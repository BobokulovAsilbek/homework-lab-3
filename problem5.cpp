#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int value;
    Node *next;
    Node(){
        value = 0;
        next = NULL;
    }
    Node(int val){
        value = val;
        next = NULL;
    }
};
class LinkedList{
    Node *head;
public:
    LinkedList(){
        head = NULL;
    }
    LinkedList(int val){
        Node *newNode = new Node(val);
        head = newNode;
    }
    void insertNode(int val){
        Node *newNode = new Node(val);
        if(head == NULL) head = newNode;
        else{
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    vector<int> func(){
        vector<int> vec = {0, 0, 0, 0};
        Node *tmp = head;
        if(head != NULL) vec[1] = head->value;
        while(tmp != NULL){
            vec[0] = max(vec[0], tmp->value);
            vec[2] ++; vec[3] = min(vec[3], tmp->value);
            //cout << tmp->value << ' ';
            tmp = tmp->next;
        }
        return vec;
    }
    void add(int v, int i){
        Node *newNode = new Node(v);
        int cnt = 1;
        Node *tmp = head;
        while(tmp != NULL){
            if(cnt == i){
                newNode->next = tmp->next;
                newNode->value = tmp->value;
                tmp->value = v;
                tmp->next = newNode;
            }
            tmp = tmp->next;
            cnt ++;
        }
    }
    void deletePosition(int i){
        if(i == 1){
            if(head != NULL) head = head->next;
        }
        else{
            Node *tmp = head;
            int cnt = 2;
            while(cnt <= i){
                if(cnt == i){
                    if(tmp->next->next != NULL) tmp->next = tmp->next->next;
                    else tmp->next = NULL;
                }
                tmp = tmp->next;
                cnt ++;
            }
        }
    }
    void answer(){
        Node *tmp = head;
        while(tmp != NULL){
            int mn = INT_MIN;
            Node *jmp = tmp -> next;
            while(jmp != NULL){
                mn = max(jmp->value, mn);
                jmp = jmp->next;
            }
            cout << (mn == INT_MIN ? -1 : mn) << ' ';
            tmp = tmp->next;
        }
    }
    void printAll(){
        Node *tmp = head;
        while(tmp != NULL){
            cout << tmp->value << ' ';
            tmp = tmp->next;
        }
    }
};
void pr1()
{
    LinkedList List;
    int n; vector<int> ans;
    while(cin >> n)
        ans.push_back(n);
    for(auto x:ans) List.insertNode(x);
    vector<int> vec = List.func();
    //List.printAll();
    for(auto x:vec) cout << x << ' ';
}
void pr2()
{
    int n; cin >> n;
    LinkedList List;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        List.insertNode(x);
    }
    int v, i; cin >> v >> i;
    List.add(v, i);
    List.printAll();
}
void pr3(){
    int n; cin >> n;
    LinkedList List;
    for(int i = 0; i < n; i++){
        int x; cin >> x; List.insertNode(x);
    }
    int i; cin >> i;
    List.deletePosition(i);
    List.printAll();
}
void pr5()
{
    int n; cin >> n;
    LinkedList List;
    for(int i = 0; i < n; i++){
        int x; cin >> x; List.insertNode(x);
    }
    List.answer();
}
int main()
{
    pr5();
}
