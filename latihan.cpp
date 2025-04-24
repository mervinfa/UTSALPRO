#include <iostream>
#include <string>
using namespace std;

typedef string Data;
const int MAX = 4; 

struct Node
{
    Data data;
    Node* next;
    Node* prev;
};

class linkedlist{
    private:
    Node* head;
    int size;
    public:
    linkedlist() {
        head = nullptr;
        size = 0;
    }

    Node* createnode(Data data, Node* next = nullptr, Node* prev = nullptr){
        Node* newnode = new Node{data, next, prev};
        cout << "Node dibuat: " << data << " | Alamat: " << newnode << endl;
        return newnode;
    }
    void inserthead(Data data){
        if (size >= MAX) {
            cout << "Antrian penuh (max " << MAX << ")!" << endl;
            return;
        }
        Node* newnode = createnode(data);
        if (head==nullptr){
            head = newnode;
        }else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        size++;
    }
    void inserttail(Data data){
        if (size >= MAX) {
            cout << "Antrian penuh (max " << MAX << ")!" << endl;
            return;
        }
        Node* newnode = createnode(data);
        if (head == nullptr){
            head = newnode;
        }else{
            Node* cur = head;
            while(cur->next!=nullptr){
                cur=cur->next;
            }
            cur->next=newnode;
            newnode->prev=cur;
            }
            size++;
    }
    void insertafter(Data data, Data value){
        if (size >= MAX) {
            cout << "Antrian penuh (max " << MAX << ")!" << endl;
            return;
        }
        Node* cur = head;
        while(cur!= nullptr && cur->data != value){
            cur = cur ->next;
        }
        if(cur==nullptr){
            cout << "tidak ditemukan" << endl;
            return;
        }
        Node* newnode = createnode(data);
        newnode->next = cur->next;
        newnode->prev = cur;
        cur->next= newnode ;
        if (newnode->next != nullptr) {
            newnode->next->prev = newnode;
        }
        cur->next=newnode;
        size++;
    }
    void deletehead(Data data){
        if (size >= MAX) {
            cout << "Antrian penuh (max " << MAX << ")!" << endl;
            return;
        }
        if (head == nullptr) {
            cout << "kosong" << endl;
            return;
        }
        Node* cur = head;
        head = head->next;
        if(head!=nullptr){
            head->prev=nullptr;
        }
        delete cur;
        size--;
    }
    void deletetail(Data data){
        if(head == nullptr){
            cout << "kosong" << endl;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* cur = head;
        while (cur->next->next != nullptr){
            cur = cur ->next;
        }

        Node* temp = cur ->next;
        cur -> next = nullptr;
        delete temp;
        size--;

    }
    void deleteafter(Data data, Data value){
        Node* cur = head;
        while(cur != nullptr && cur->data != value){
        cur = cur->next;
        }
        if(cur==nullptr||cur->next==nullptr){
            cout << "kosong" << endl;
            return;
        }
        Node* temp = cur->next;
        cur->next = temp->next;
        if(temp->next != nullptr){
            temp->next->prev=cur;
        }
        delete temp;
        size--;
    }
    void display() {
        Node* cur = head;
        cout << "Antrian : ";
        while (cur != nullptr) {
            cout << cur->data << " <-> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }

};

int main() {
    linkedlist list; 

    list.inserthead("C");
    list.inserthead("B");
    list.inserthead("A");
    list.display();

    list.insertafter("D", "A");
    list.display();

    list.deletehead("A");
    list.display();

    return 0;
}


