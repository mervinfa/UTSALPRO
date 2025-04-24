#include <iostream>
#include <string>
using namespace std;

// 1. Node menggunakan struct
typedef string DataType;

struct Node {
    DataType data;
    Node* next;
};

// 2. Linked List dengan operasi lengkap
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert di awal
    void insertHead(DataType data) {
        Node* newNode = new Node{data, head};
        head = newNode;
        cout << "Insert Head: " << data << " | Alamat: " << newNode << endl;
    }

    // Insert di akhir
    void insertTail(DataType data) {
        Node* newNode = new Node{data, nullptr};
        cout << "Insert Tail: " << data << " | Alamat: " << newNode << endl;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Insert setelah node tertentu
    void insertAfter(DataType afterData, DataType newData) {
        Node* temp = head;
        while (temp != nullptr && temp->data != afterData) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Data " << afterData << " tidak ditemukan!" << endl;
            return;
        }

        Node* newNode = new Node{newData, temp->next};
        temp->next = newNode;
        cout << "Insert After " << afterData << ": " << newData << " | Alamat: " << newNode << endl;
    }

    // Delete dari head
    void deleteHead() {
        if (head == nullptr) {
            cout << "List kosong!\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        cout << "Delete Head: " << temp->data << " | Alamat: " << temp << endl;
        delete temp;
    }

    // Delete dari tail
    void deleteTail() {
        if (head == nullptr) {
            cout << "List kosong!\n";
            return;
        }

        if (head->next == nullptr) {
            cout << "Delete Tail: " << head->data << " | Alamat: " << head << endl;
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        cout << "Delete Tail: " << temp->next->data << " | Alamat: " << temp->next << endl;
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete setelah node tertentu
    void deleteAfter(DataType afterData) {
        Node* temp = head;
        while (temp != nullptr && temp->data != afterData) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Tidak bisa delete setelah " << afterData << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        cout << "Delete After " << afterData << ": " << toDelete->data << " | Alamat: " << toDelete << endl;
        delete toDelete;
    }

    // Tampilkan semua node
    void display() {
        Node* temp = head;
        cout << "Isi List: ";
        while (temp != nullptr) {
            cout << temp->data << "(" << temp << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// 3. Program utama
int main() {
    LinkedList list;

    list.insertHead("C");
    list.insertHead("B");
    list.insertHead("A");
    list.display();

    list.insertTail("D");
    list.insertTail("E");
    list.display();

    list.insertAfter("C", "X");
    list.display();

    list.deleteHead();
    list.display();

    list.deleteTail();
    list.display();

    list.deleteAfter("C");
    list.display();

    return 0;
}
