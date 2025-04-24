#include <iostream>
#include <string>
using namespace std;

typedef string Data;

const int MAX = 4; // Maksimum antrian

struct Node {
    Data data;
    Node* next;
    Node* prev;
};

class linkedlist {
private:
    Node* head;
    int size;

public:
    linkedlist() {
        head = nullptr;
        size = 0;
    }

    Node* createnode(Data data, Node* next = nullptr, Node* prev = nullptr) {
        Node* newnode = new Node{data, next, prev};
        cout << "Node dibuat: " << data << " | Alamat: " << newnode << endl;
        return newnode;
    }

    void inserthead(Data data) {
        if (size >= MAX) {
            cout << "Antrian penuh (max " << MAX << ")!" << endl;
            return;
        }
        Node* newnode = createnode(data);
        if (head == nullptr) {
            head = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        size++;
    }

    void inserttail(Data data) {
        if (size >= MAX) {
            cout << "Antrian penuh (max " << MAX << ")!" << endl;
            return;
        }
        Node* newnode = createnode(data);
        if (head == nullptr) {
            head = newnode;
        } else {
            Node* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = newnode;
            newnode->prev = cur;
        }
        size++;
    }

    void insertafter(Data data, Data value) {
        if (size >= MAX) {
            cout << "Antrian penuh (max " << MAX << ")!" << endl;
            return;
        }
        Node* cur = head;
        while (cur != nullptr && cur->data != value) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            cout << "Data " << value << " tidak ditemukan!" << endl;
            return;
        }
        Node* newnode = createnode(data);
        newnode->next = cur->next;
        newnode->prev = cur;
        if (cur->next != nullptr) {
            cur->next->prev = newnode;
        }
        cur->next = newnode;
        size++;
    }

    void deletehead() {
        if (head == nullptr) {
            cout << "Antrian kosong!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        cout << "Delete head: " << temp->data << " | Alamat: " << temp << endl;
        delete temp;
        size--;
    }

    void display() {
        Node* cur = head;
        cout << "Antrian (" << size << "/" << MAX << "): ";
        while (cur != nullptr) {
            cout << cur->data << "(" << cur << ") <-> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    linkedlist list;

    // Menambahkan A, B, C
    list.inserthead("C");
    list.inserthead("B");
    list.inserthead("A");
    list.display();
    cout << endl;

    // Menambahkan D setelah A
    list.insertafter("D", "A");
    list.display();
    cout << endl;

    // Menghapus A dari head
    list.deletehead();
    list.display();
    cout << endl;

    return 0;
}
