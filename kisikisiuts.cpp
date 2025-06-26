#include <iostream>
#include <string>
using namespace std;

typedef float Data;
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
    void deletehead(){
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
    void deletetail(){
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
    void deleteafter(Data value){
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
            cout << cur->data << "("<< cur << ")" << " <-> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }

};

int main() {
    linkedlist list;
    int pilihan;
    Data data, target;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Insert Head\n";
        cout << "2. Insert Tail\n";
        cout << "3. Insert After\n";
        cout << "4. Delete Head\n";
        cout << "5. Delete Tail\n";
        cout << "6. Delete After\n";
        cout << "7. Tampilkan Antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan data: ";
            cin >> data;
            list.inserthead(data);
            break;
        case 2:
            cout << "Masukkan data: ";
            cin >> data;
            list.inserttail(data);
            break;
        case 3:
            cout << "Masukkan data baru: ";
            cin >> data;
            cout << "Setelah data: ";
            cin >> target;
            list.insertafter(data, target);
            break;
        case 4:
        
            list.deletehead();
            break;
        case 5:
            list.deletetail();
            break;
        case 6:
            cout << "Hapus setelah data: ";
            cin >> target;
            list.deleteafter(target);
            break;
        case 7:
            list.display();
            break;
        case 0:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);

    return 0;
}


