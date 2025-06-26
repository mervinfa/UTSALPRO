#include <iostream>
#include <string>
using namespace std;

typedef string Lagu;
const int MAX = 4; 

struct Node {
    Lagu data;
    Node* next;
    Node* prev;
};

class Playlist {
private:
    Node* head;
    int size;

public:
    Playlist() {
        head = nullptr;
        size = 0;
    }
    Node* buatNode(Lagu data, Node* next = nullptr, Node* prev = nullptr) {
        Node* baru = new Node{data, next, prev};
        cout << "Lagu ditambahkan: " << data << " | Alamat: " << baru << endl;
        return baru;
    }
    void tambahDepan(Lagu data) {
        if (size >= MAX) {
            cout << "Playlist penuh (max " << MAX << " lagu)!" << endl;
            return;
        }
        Node* baru = buatNode(data);
        if (head == nullptr) {
            head = baru;
        } else {
            baru->next = head;
            head->prev = baru;
            head = baru;
        }
        size++;
    }
    void tambahBelakang(Lagu data) {
        if (size >= MAX) {
            cout << "Playlist penuh (max " << MAX << " lagu)!" << endl;
            return;
        }
        Node* baru = buatNode(data);
        if (head == nullptr) {
            head = baru;
        } else {
            Node* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = baru;
            baru->prev = cur;
        }
        size++;
    }
    void tambahSetelah(Lagu data, Lagu target) {
        if (size >= MAX) {
            cout << "Playlist penuh (max " << MAX << " lagu)!" << endl;
            return;
        }
        Node* cur = head;
        while (cur != nullptr && cur->data != target) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            cout << "Lagu '" << target << "' tidak ditemukan!" << endl;
            return;
        }
        Node* baru = buatNode(data);
        baru->next = cur->next;
        baru->prev = cur;
        if (cur->next != nullptr) {
            cur->next->prev = baru;
        }
        cur->next = baru;
        size++;
    }
    void hapusDepan() {
        if (head == nullptr) {
            cout << "Playlist kosong!" << endl;
            return;
        }
        Node* hapus = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        cout << "Lagu dihapus: " << hapus->data << endl;
        delete hapus;
        size--;
    }
    void hapusBelakang() {
        if (head == nullptr) {
            cout << "Playlist kosong!" << endl;
            return;
        }
        if (head->next == nullptr) {
            cout << "Lagu dihapus: " << head->data << endl;
            delete head;
            head = nullptr;
            size--;
            return;
        }
        Node* cur = head;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cout << "Lagu dihapus: " << cur->data << endl;
        cur->prev->next = nullptr;
        delete cur;
        size--;
    }
    void hapusSetelah(Lagu target) {
        Node* cur = head;
        while (cur != nullptr && cur->data != target) {
            cur = cur->next;
        }
        if (cur == nullptr || cur->next == nullptr) {
            cout << "Lagu setelah '" << target << "' tidak ditemukan atau kosong." << endl;
            return;
        }
        Node* hapus = cur->next;
        cur->next = hapus->next;
        if (hapus->next != nullptr) {
            hapus->next->prev = cur;
        }
        cout << "Lagu dihapus: " << hapus->data << endl;
        delete hapus;
        size--;
    }
    void tampilkan() {
        Node* cur = head;
        cout << "Playlist sekarang: ";
        while (cur != nullptr) {
            cout << "[" << cur->data << "] <-> ";
            cur = cur->next;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    Playlist playlist;
    int pilihan;
    Lagu data, target;

    cout << "=============================================================" << endl;
    cout << " SELAMAT DATANG DI KASUS DOUBLE LINKED LIST: QUEUE LAGU" << endl;
    cout << "=============================================================" << endl;
    cout << "Panduan simulasi playlist lagu:" << endl;
    cout << "1. Tambah lagu di depan          -> Masukkan 'Perfect'" << endl;
    cout << "2. Tambah lagu di belakang       -> Masukkan 'Asmalibrasi'" << endl;
    cout << "3. Tambah lagu setelah tertentu  -> Masukkan 'Peaches' setelah 'Perfect'" << endl;
    cout << "4. Hapus lagu paling depan       -> Menghapus 'Perfect'" << endl;
    cout << "5. Hapus lagu paling belakang    -> Menghapus 'Asmalibrasi'" << endl;
    cout << "6. Hapus lagu setelah tertentu   -> Menghapus lagu setelah 'Perfect'" << endl;
    cout << "7. Lihat seluruh daftar lagu" << endl;
    cout << "0. Keluar dari program" << endl;
    cout << "=============================================================" << endl;

    do {
        cout << endl << "=== MENU PLAYLIST ===" << endl;
        cout << "1. Tambah Lagu di Depan" << endl;
        cout << "2. Tambah Lagu di Belakang" << endl;
        cout << "3. Tambah Lagu Setelah Tertentu" << endl;
        cout << "4. Hapus Lagu Depan" << endl;
        cout << "5. Hapus Lagu Belakang" << endl;
        cout << "6. Hapus Lagu Setelah Tertentu" << endl;
        cout << "7. Tampilkan Playlist" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) {
            case 1:
                cout << "Masukkan judul lagu: ";
                getline(cin, data);
                playlist.tambahDepan(data);
                break;
            case 2:
                cout << "Masukkan judul lagu: ";
                getline(cin, data);
                playlist.tambahBelakang(data);
                break;
            case 3:
                cout << "Masukkan lagu baru: ";
                getline(cin, data);
                cout << "Setelah lagu: ";
                getline(cin, target);
                playlist.tambahSetelah(data, target);
                break;
            case 4:
                playlist.hapusDepan();
                break;
            case 5:
                playlist.hapusBelakang();
                break;
            case 6:
                cout << "Hapus lagu setelah: ";
                getline(cin, target);
                playlist.hapusSetelah(target);
                break;
            case 7:
                playlist.tampilkan();
                break;
            case 0:
                cout << "Program selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);

    return 0;
}
