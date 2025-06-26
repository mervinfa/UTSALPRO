#include <iostream>
#include <string>
using namespace std;

typedef string Event;
const int MAX = 10; 

struct Node {
    Event event;
    Node* next;
    Node* prev;
};
class Calendar {
private:
    Node* head;
    int size;

public:
    Calendar() {
        head = nullptr;
        size = 0;
    }
    Node* createNode(Event event) {
        Node* newNode = new Node{event, nullptr, nullptr};
        cout << "Acara dibuat: " << event << " | Alamat: " << newNode << endl;
        return newNode;
    }
    void addMorning(Event event) {
        if (size >= MAX) {
            cout << "Jadwal penuh!" << endl;
            return;
        }

        Node* newNode = createNode(event);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    void addEvening(Event event) {
        if (size >= MAX) {
            cout << "Jadwal penuh!" << endl;
            return;
        }

        Node* newNode = createNode(event);
        if (!head) {
            head = newNode;
        } else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = newNode;
            newNode->prev = cur;
        }
        size++;
    }

    void addAfter(Event event, Event afterEvent) {
        if (size >= MAX) {
            cout << "Jadwal penuh!" << endl;
            return;
        }

        Node* cur = head;
        while (cur && cur->event != afterEvent) {
            cur = cur->next;
        }

        if (!cur) {
            cout << "Acara \"" << afterEvent << "\" tidak ditemukan." << endl;
            return;
        }

        Node* newNode = createNode(event);
        newNode->next = cur->next;
        newNode->prev = cur;

        if (cur->next) cur->next->prev = newNode;
        cur->next = newNode;
        size++;
    }

    void deleteMorning() {
        if (!head) {
            cout << "Jadwal kosong!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        cout << "Acara dihapus: " << temp->event << endl;
        delete temp;
        size--;
    }
    void deleteEvening() {
        if (!head) {
            cout << "Jadwal kosong!" << endl;
            return;
        }

        if (!head->next) {
            cout << "Acara dihapus: " << head->event << endl;
            delete head;
            head = nullptr;
            size--;
            return;
        }

        Node* cur = head;
        while (cur->next->next) cur = cur->next;

        Node* temp = cur->next;
        cur->next = nullptr;
        cout << "Acara dihapus: " << temp->event << endl;
        delete temp;
        size--;
    }
    void display() {
        Node* cur = head;
        cout << endl << "Jadwal Hari Ini:" << endl;
        while (cur) {
            cout << cur->event << " (" << cur << ") <-> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Calendar kalender;
    int pilihan;
    Event acara, target;

    cout << "=============================================================" << endl;
    cout << "     SELAMAT DATANG DI PROGRAM DOUBLE LINKED LIST: JADWAL HARIAN" << endl;
    cout << "=============================================================" << endl;
    cout << "Panduan simulasi jadwal harian (maksimal 10 jadwal pagi & malam):" << endl;
    cout << "1. Tambah Acara pagi di awal         -> Masukkan Kuliah Alpro" << endl;
    cout << "2. Tambah Acara Malam di akhir       -> Masukkan Makan dengan teman-teman" << endl;
    cout << "3. Tambah Acara setelah Acara        -> Masukkan beli bensin setelah kuliah Alpro" << endl;
    cout << "4. Hapus Acara pertama               -> Menghapus Acara dari depan" << endl;
    cout << "5. Tampilkan semua jadwal " << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "0. Keluar dari program" << endl;
    cout << "=============================================================" << endl;
    do {
        cout << endl;
        cout << "===== MENU JADWAL =====" << endl;
        cout << "1. Tambah Acara Pagi (Depan)" << endl;
        cout << "2. Tambah Acara Malam (Belakang)" << endl;
        cout << "3. Tambah Acara Setelah Acara Tertentu" << endl;
        cout << "4. Hapus Acara Pagi" << endl;
        cout << "5. Hapus Acara Malam" << endl;
        cout << "6. Lihat Semua Jadwal" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama acara pagi: ";
                getline(cin, acara);
                kalender.addMorning(acara);
                break;
            case 2:
                cout << "Masukkan nama acara malam: ";
                getline(cin, acara);
                kalender.addEvening(acara);
                break;
            case 3:
                cout << "Masukkan nama acara baru: ";
                getline(cin, acara);
                cout << "Setelah acara apa?: ";
                getline(cin, target);
                kalender.addAfter(acara, target);
                break;
            case 4:
                kalender.deleteMorning();
                break;
            case 5:
                kalender.deleteEvening();
                break;
            case 6:
                kalender.display();
                break;
            case 0:
                cout << "Terima kasih! Semoga harimu terorganisir." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
