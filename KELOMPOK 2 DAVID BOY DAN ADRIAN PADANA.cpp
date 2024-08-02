#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
#include <cstring>

using namespace std;

struct Barang {
    char nama[50];
    int id, jumlah;
    double harga;
};

int menu() {
    int input;
    cout << "===== PROGRAM CRUD BARANG =====" << endl;
    cout << "===============================" << endl;
    cout << "[1]. Menambah data barang" << endl;
    cout << "[2]. Menghapus data barang" << endl;
    cout << "[3]. Mencari barang berdasarkan Id" << endl;
    cout << "[4]. Mengedit atau memperbarui data barang" << endl;
    cout << "[5]. Menampilkan data barang" << endl;
    cout << "[6]. Selesai" << endl;
    cout << "===============================" << endl;
    cout << "Masukkan nomor yang ingin dipilih = ";
    cin >> input;
    return input;
}

int AmbilData(fstream &data) {
    data.open("data.bin", ios::in | ios::binary);
    if (!data.is_open()) {
        return 0;
    }
    data.seekg(0, ios::end);
    int size = data.tellg() / sizeof(Barang);
    data.close();
    return size;
}

void MenambahData(fstream &data) {
    Barang barang;
    int size = AmbilData(data);

    cout << "Ukuran data = " << size << endl;

    data.open("data.bin", ios::in | ios::out | ios::binary | ios::app);
    if (!data.is_open()) {
        data.clear();
        data.open("data.bin", ios::out | ios::binary);
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "===============================" << endl;
    cout << "Nama Barang = ";
    cin.getline(barang.nama, 50);

    cout << "ID Barang = ";
    while (!(cin >> barang.id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Masukkan ID Barang (angka): ";
    }
    cout << "Jumlah barang = ";
    while (!(cin >> barang.jumlah)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Masukkan Jumlah Barang (angka): ";
    }
    cout << "Harga barang = ";
    while (!(cin >> barang.harga)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid. Masukkan Harga Barang (angka): ";
    }
    cout << "===============================" << endl;

    if (data.is_open()) {
        data.seekp(0, ios::end);
        data.write(reinterpret_cast<char*>(&barang), sizeof(Barang));
        data.close();
        cout << "Barang berhasil ditambahkan :)" << endl;
    } else {
        cout << "Gagal membuka file untuk menambah data." << endl;
    }
}

void HapusData(fstream &data, int id) {
    fstream tempFile;
    tempFile.open("temp.bin", ios::out | ios::binary);
    if (!tempFile.is_open()) {
        cout << "Gagal membuka file sementara untuk menghapus data." << endl;
        return;
    }

    data.open("data.bin", ios::in | ios::binary);
    if (!data.is_open()) {
        cout << "Gagal membuka file data." << endl;
        tempFile.close();
        return;
    }

    Barang barang;
    bool found = false;
    while (data.read(reinterpret_cast<char*>(&barang), sizeof(Barang))) {
        if (barang.id != id) {
            tempFile.write(reinterpret_cast<char*>(&barang), sizeof(Barang));
        } else {
            found = true;
        }
    }

    data.close();
    tempFile.close();
    remove("data.bin");
    rename("temp.bin", "data.bin");

    if (found) {
        cout << "Barang dengan ID " << id << " berhasil dihapus." << endl;
    } else {
        cout << "Barang dengan ID " << id << " tidak ditemukan." << endl;
    }
}

void CariData(fstream &data, int id) {
    data.open("data.bin", ios::in | ios::binary);
    if (!data.is_open()) {
        cout << "Gagal membuka file data." << endl;
        return;
    }

    Barang barang;
    bool found = false;
    while (data.read(reinterpret_cast<char*>(&barang), sizeof(Barang))) {
        if (barang.id == id) {
            cout << "Data Barang ditemukan:" << endl;
            cout << "Nama: " << barang.nama << endl;
            cout << "ID: " << barang.id << endl;
            cout << "Jumlah: " << barang.jumlah << endl;
            cout << "Harga: Rp " << fixed << setprecision(2) << barang.harga << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Barang dengan ID " << id << " tidak ditemukan." << endl;
    }

    data.close();
}

void EditData(fstream &data, int id) {
    fstream tempFile;
    tempFile.open("temp.bin", ios::out | ios::binary);
    if (!tempFile.is_open()) {
        cout << "Gagal membuka file sementara untuk mengedit data." << endl;
        return;
    }

    data.open("data.bin", ios::in | ios::binary);
    if (!data.is_open()) {
        cout << "Gagal membuka file data." << endl;
        tempFile.close();
        return;
    }

    Barang barang;
    bool found = false;
    while (data.read(reinterpret_cast<char*>(&barang), sizeof(Barang))) {
        if (barang.id == id) {
            cout << "Edit data Barang:" << endl;
            cout << "Nama Barang = ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(barang.nama, 50);
            cout << "Jumlah barang = ";
            while (!(cin >> barang.jumlah)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Masukkan Jumlah Barang (angka): ";
            }
            cout << "Harga barang = ";
            while (!(cin >> barang.harga)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Masukkan Harga Barang (angka): ";
            }
            found = true;
        }
        tempFile.write(reinterpret_cast<char*>(&barang), sizeof(Barang));
    }

    data.close();
    tempFile.close();
    remove("data.bin");
    rename("temp.bin", "data.bin");

    if (found) {
        cout << "Barang dengan ID " << id << " berhasil diperbarui." << endl;
    } else {
        cout << "Barang dengan ID " << id << " tidak ditemukan." << endl;
    }
}

void TampilData(fstream &data) {
    data.open("data.bin", ios::in | ios::binary);
    if (!data.is_open()) {
        cout << "Gagal membuka file data." << endl;
        return;
    }

    Barang barang;
    int index = 1;
    cout << "===============================" << endl;
    cout << "Daftar Barang:" << endl;
    cout << "===============================" << endl;
    cout << setw(5) << "No" << setw(20) << "Nama" << setw(10) << "ID" << setw(15) << "Harga" << endl;
    cout << "===============================" << endl;
    while (data.read(reinterpret_cast<char*>(&barang), sizeof(Barang))) {
        cout << setw(5) << index++ 
             << setw(20) << barang.nama 
             << setw(10) << barang.id 
             << setw(15) << fixed << setprecision(2) << barang.harga << endl;
    }
    cout << "===============================" << endl;

    data.close();
}

int main() {
    fstream data;
    char lanjut;
    int pilihan, id;

    enum optin { menambah = 1, menghapus, mencari, edit, menampilkan, selesai };

    do {
        pilihan = menu();
        cout << endl;

        switch (pilihan) {
            case menambah:
                cout << "Menambah data barang" << endl;
                MenambahData(data);
                break;
            case menghapus:
                cout << "Menghapus data barang" << endl;
                cout << "Masukkan ID Barang yang ingin dihapus: ";
                cin >> id;
                HapusData(data, id);
                break;
            case mencari:
                cout << "Mencari barang berdasarkan Id" << endl;
                cout << "Masukkan ID Barang yang ingin dicari: ";
                cin >> id;
                CariData(data, id);
                break;
            case edit:
                cout << "Mengedit atau memperbarui data barang" << endl;
                cout << "Masukkan ID Barang yang ingin diedit: ";
                cin >> id;
                EditData(data, id);
                break;
            case menampilkan:
                cout << "Menampilkan data barang" << endl;
                TampilData(data);
                break;
            case selesai:
                cout << "Selesai" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
        cout << endl;

        cout << "Lanjutkan [Y/N]: ";
        cin >> lanjut;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (lanjut == 'Y' || lanjut == 'y');

    return 0;
}