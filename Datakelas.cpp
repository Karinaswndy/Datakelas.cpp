#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
using namespace std;

struct mahasiswa {
    string nim;
    string nama;
    string alamat;
    float ipk;
};

mahasiswa sikc[30];
int pos = -1;

void tampilkanHeaderTabel() {
    cout << left 
         << setw(5)  << "No" 
         << setw(15) << "NIM" 
         << setw(20) << "Nama" 
         << setw(30) << "Alamat" 
         << setw(10) << "IPK" << endl;
    cout << string(80, '-') << endl;
}

void tampilkanSemuaData() {
    system("cls");
    if (pos == -1) {
        cout << "Tidak ada data." << endl;
    } else {
        tampilkanHeaderTabel();

        for (int i = 0; i <= pos; i++) {
            cout << left 
                 << setw(5)  << i + 1 
                 << setw(15) << sikc[i].nim 
                 << setw(20) << sikc[i].nama 
                 << setw(30) << sikc[i].alamat 
                 << setw(10) << fixed << setprecision(2) << sikc[i].ipk 
                 << endl;
        }
    }
    cout << "\nTekan Enter agar kembali ";
    getch();
}

void masukanData() {
    system("cls");
    if (pos >= 29) {
        cout << "\nData sudah penuh." << endl;
        cin.get();
        return;    
    }

    pos++;
    cout << "\nMasukan Data Mahasiswa\n";
    cout << "-----------------\n";

    cout << "Masukan NIM: ";
    getline(cin, sikc[pos].nim);
    cout << "Masukan Nama: ";
    getline(cin, sikc[pos].nama);
    cout << "Masukan Alamat: ";
    getline(cin, sikc[pos].alamat);
    cout << "Masukan IPK: ";
    cin >> sikc[pos].ipk;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nData Berhasil Disimpan!\n";
    cout << "\nTekan Enter untuk kembali ke Menu\n";
    cin.get();
}

void updateData() {
    system("cls");
    if (pos == -1) {
        cout << "Tidak ada data untuk diupdate." << endl;
        cout << "\nTekan Enter untuk kembali ke menu...";
        cin.get();
        return;
    }

    string cariNIM;
    cout << "Masukkan NIM mahasiswa yang ingin diupdate: ";
    getline(cin, cariNIM);

    bool ditemukan = false;
    for (int i = 0; i <= pos; i++) {
        if (sikc[i].nim == cariNIM) {
            ditemukan = true;
            cout << "\nData ditemukan!" << endl;
            tampilkanHeaderTabel();
            cout << left
                 << setw(15) << sikc[i].nim
                 << setw(20) << sikc[i].nama
                 << setw(30) << sikc[i].alamat
                 << setw(10) << sikc[i].ipk
                 << endl;

            cout << "\nMasukkan data baru:\n";
            cout << "Masukkan Nama: ";
            getline(cin, sikc[i].nama);
            cout << "Masukkan Alamat: ";
            getline(cin, sikc[i].alamat);
            cout << "Masukkan IPK: ";
            cin >> sikc[i].ipk;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nData berhasil diperbarui!" << endl;
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.get();
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nData dengan NIM \"" << cariNIM << "\" tidak ditemukan." << endl;
        cout << "\nTekan Enter untuk kembali ke menu...";
        cin.get();
    }
}

void hapusData() {
    system("cls");
    if (pos == -1) {
        cout << "Tidak ada data untuk dihapus." << endl;
        cout << "\nTekan Enter untuk kembali ke menu...";
        cin.get();
        return;
    }

    cout << "Data Mahasiswa Saat Ini:" << endl;
    tampilkanHeaderTabel();

    for (int i = 0; i <= pos; i++) {
        cout << left
             << setw(5)  << i + 1
             << setw(15) << sikc[i].nim
             << setw(20) << sikc[i].nama
             << setw(30) << sikc[i].alamat
             << setw(10) << fixed << setprecision(2) << sikc[i].ipk
             << endl;
    }

    string cariNIM;
    cout << "\nMasukkan NIM mahasiswa yang ingin dihapus: ";
    getline(cin, cariNIM);

    bool ditemukan = false;
    for (int i = 0; i <= pos; i++) {
        if (sikc[i].nim == cariNIM) {
            ditemukan = true;
            char konfirmasi;
            cout << "\nData ditemukan!" << endl;
            cout << "Apakah Anda yakin ingin menghapus data ini? (y/n): ";
            cin >> konfirmasi;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                for (int j = i; j < pos; j++) {
                    sikc[j] = sikc[j + 1];
                }
                pos--;

                cout << "\nData berhasil dihapus!" << endl;
            } else {
                cout << "\nBatal Menghapus Data." << endl;
            }

            cout << "\nTekan Enter kembali ke menu...";
            cin.get();
            return;
        }
    }

    if (!ditemukan) {
        cout << "\nData dengan NIM \"" << cariNIM << "\" tidak ditemukan." << endl;
        cout << "\nTekan Enter untuk kembali ke menu...";
        cin.get();
    }
}

void dMenu() {
    system("cls");
    cout << "Aplikasi Pencatatan Data" << "\n";       
    cout << "1. Masukan Data" << "\n";            
    cout << "2. Tampilkan Data" << "\n";            
    cout << "3. Update Data" << "\n";           
    cout << "4. Hapus Data" << "\n";            
    cout << "5. Exit" << "\n";           
    cout << "Masukan angka :";        
}

int main() {
    char pl;
    do {
        dMenu();
        pl = getch();
        switch (pl) {
            case '1':
                masukanData();
                break;
            case '2':
                tampilkanSemuaData();
                break;  
            case '3':
                updateData();
                break;  
            case '4':
                hapusData();
                break;  
            case '5':
                break;
            default:
                system("cls");
                cout << "Pilihan Tidak Tersedia";
                getch();
                break;
        }
    } while (pl != '5');
    return 0;
}
