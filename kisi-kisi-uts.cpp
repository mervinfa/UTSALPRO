#include <iostream>
#include <string>

using namespace std;

// 3. menggunakan typedef
typedef string DataType;
typedef struct node{
 int data;
 node* next;
};

// Node untuk Double Linked List
class Node {
public:
    DataType data;
    Node* next;
    Node* prev;

    Node(DataType data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// 5. menerapkan class (public/private/protected)
class Queue {
private:
    Node* head;
    Node* tail;
    int size;
    const int MAX = 10; // 2. maksimum antrian 10

public:
    Queue() {
        head = tail = nullptr;
        size = 0;
    }

    // Menambahkan ke belakang antrian
    void enqueue(DataType data) {
        if (size >= MAX) {
            cout << "Antrian penuh!" << endl;
            return;
        }

        Node* newNode = new Node(data);
        cout << "Enqueue: " << data << " | Alamat: " << newNode << endl;

        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Menyisipkan setelah node tertentu
    void insertAfter(DataType afterData, DataType newData) {
        Node* current = head;
        while (current != nullptr && current->data != afterData) {
            current = current->next;
        }

        if (current == nullptr || size >= MAX) {
            cout << "Insert gagal!" << endl;
            return;
        }

        Node* newNode = new Node(newData);
        cout << "Insert " << newData << " setelah " << afterData << " | Alamat: " << newNode << endl;

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != nullptr) {
            current->next->prev = newNode;
        }

        current->next = newNode;

        if (current == tail) {
            tail = newNode;
        }

        size++;
    }

    // Menghapus elemen dari depan
    void dequeue() {
        if (head == nullptr) {
            cout << "Antrian kosong!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr){

            head->prev = nullptr;
        }
        else{

            tail = nullptr;
        }

        cout << "Dequeue: " << temp->data << " | Alamat: " << temp << endl;
        delete temp;
        size--;
    }

    void display() {
        Node* current = head;
        cout << "Isi antrian: ";
        while (current != nullptr) {
            cout << current->data << "(" << current << ") -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Queue q;

    // 1. menampilkan hasil sesuai
    q.enqueue("a");
    q.enqueue("b");
    q.enqueue("c");
    q.display();

    q.insertAfter("a", "d"); // Menyisipkan 'd' setelah 'a'
    q.display();

    q.dequeue(); // Hapus 'a'
    q.display();

    return 0;
}