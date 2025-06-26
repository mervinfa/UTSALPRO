#include <iostream>
#include <string>
using namespace std;

typedef string Data;
const int MAX = 4; 

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
        cout << "Tab dibuka: " << data << " | Alamat: " << newnode << endl;
        return newnode;
    }

    void inserthead(Data data) {
        if (size >= MAX) {
            cout << "Maksimum tab terbuka (" << MAX << ")!" << endl;
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
            cout << "Maksimum tab terbuka (" << MAX << ")!" << endl;
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
            cout << "Maksimum tab terbuka (" << MAX << ")!" << endl;
            return;
        }
        Node* cur = head;
        while (cur != nullptr && cur->data != value) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            cout << "Tab '" << value << "' tidak ditemukan." << endl;
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
            cout << "Tidak ada tab yang terbuka." << endl;
            return;
        }
        Node* cur = head;
        cout << "Menutup tab: " << cur->data << endl;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete cur;
        size--;
    }

    void deletetail() {
        if (head == nullptr) {
            cout << "Tidak ada tab yang terbuka." << endl;
            return;
        }
        if (head->next == nullptr) {
            cout << "Menutup tab: " << head->data << endl;
            delete head;
            head = nullptr;
            size--;
            return;
        }
        Node* cur = head;
        while (cur->next->next != nullptr) {
            cur = cur->next;
        }
        Node* temp = cur->next;
        cout << "Menutup tab: " << temp->data << endl;
        cur->next = nullptr;
        delete temp;
        size--;
    }

    void deleteafter(Data value) {
        Node* cur = head;
        while (cur != nullptr && cur->data != value) {
            cur = cur->next;
        }
        if (cur == nullptr || cur->next == nullptr) {
            cout << "Tidak ada tab setelah '" << value << "'." << endl;
            return;
        }
        Node* temp = cur->next;
        cout << "Menutup tab: " << temp->data << endl;
        cur->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = cur;
        }
        delete temp;
        size--;
    }

    void display() {
        Node* cur = head;
        cout << "Tab terbuka: ";
        while (cur != nullptr) {
            cout << "[" << cur->data << "] <-> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    linkedlist browserTabs;
    int pilihan;
    Data data, target;
    cout << "=============================================================" << endl;
    cout << " SELAMAT DATANG DI KASUS DOUBLE LINKED LIST: TAB BROWSER" << endl;
    cout << "=============================================================" << endl;
    cout << "Panduan simulasi:" << endl;
    cout << "1. Buka tab di depan          -> Masukkan string 'YouTube'" << endl;
    cout << "2. Buka tab di belakang       -> Masukkan string 'Kulino'" << endl;
    cout << "3. Buka tab setelah tertentu  -> Masukkan string 'Canva' setelah 'YouTube'" << endl;
    cout << "4. Tutup tab di depan         -> Menghapus tab pertama (YouTube)" << endl;
    cout << "5. Tutup tab di belakang      -> Menghapus tab terakhir (Kulino)" << endl;
    cout << "6. Tutup tab setelah tertentu -> Hapus tab setelah 'YouTube'" << endl;
    cout << "7. Tampilkan semua tab yang terbuka" << endl;
    cout << "0. Keluar dari program" << endl;
    cout << "=============================================================" << endl;

    do {
        cout << "\n=== MENU TAB BROWSER ===\n";
        cout << "1. Buka Tab di Depan\n";
        cout << "2. Buka Tab di Belakang\n";
        cout << "3. Buka Tab Setelah Tab Tertentu\n";
        cout << "4. Tutup Tab Paling Depan\n";
        cout << "5. Tutup Tab Paling Belakang\n";
        cout << "6. Tutup Tab Setelah Tab Tertentu\n";
        cout << "7. Lihat Semua Tab\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) {
        case 1:
            cout << "Masukkan nama tab (misal: Google): ";
            getline(cin, data);
            browserTabs.inserthead(data);
            break;
        case 2:
            cout << "Masukkan nama tab (misal: YouTube): ";
            getline(cin, data);
            browserTabs.inserttail(data);
            break;
        case 3:
            cout << "Masukkan nama tab baru: ";
            getline(cin, data);
            cout << "Buka setelah tab: ";
            getline(cin, target);
            browserTabs.insertafter(data, target);
            break;
        case 4:
            browserTabs.deletehead();
            break;
        case 5:
            browserTabs.deletetail();
            break;
        case 6:
            cout << "Tutup tab setelah: ";
            getline(cin, target);
            browserTabs.deleteafter(target);
            break;
        case 7:
            browserTabs.display();
            break;
        case 0:
            cout << "Menutup semua tab. Sampai jumpa!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);

    return 0;
}
