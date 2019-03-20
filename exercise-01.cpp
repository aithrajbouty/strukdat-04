/*
Author      : Aithra Junia Bouty
NPM         : 140810180054
Deskripsi   : program lengkap semua primitive list dengan list pegawai
Tahun       : 2019
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Pegawai{
    char nama[30];
    char bidang[15];
    int gaji;
    Pegawai* next;
};
typedef Pegawai* pointer;
typedef pointer List;
void createList(List& First);
void createPegawai(pointer& pBaru);
void insertFirst(List& First, pointer pBaru);
void insertLast(List& First, pointer pBaru);
void deleteFirst(List& First, pointer& pHapus);
void deleteLast(List& First, pointer& pHapus);
void traversal(List First);

int main()
{
    pointer p;
    List first;
    int pilih;

    createList(first);

    while(1){
        system("cls");
        cout << "Pilih salah satu menu :\n";
        cout << "1. Masukkan data pegawai di awal\n";
        cout << "2. Masukkan data pegawai di akhir\n";
        cout << "3. Hapus data pegawai di awal\n";
        cout << "4. Hapus data pegawai di akhir\n";
        cout << "5. Tampilkan data pegawai\n";
        cout << "6. Selesai\n";

        cout << "\nMasukkan pilihan menu : "; cin >> pilih;
        cout << endl;

        switch(pilih){
            case 1:
                createPegawai(p);
                insertFirst(first,p);
                break;
            case 2:
                createPegawai(p);
                insertLast(first,p);
                break;
            case 3:
                deleteFirst(first,p);
                break;
            case 4:
                deleteLast(first,p);
                break;
            case 5:
                traversal(first);
                break;
            case 6:
                return 0;
                break;
        }
        system("pause");
    }
}

void createList(List& First){
    First = NULL;
}

void createPegawai(pointer& pBaru){
    pBaru = new Pegawai;
    cout << "Masukkan Nama Pegawai  : "; cin.ignore(); cin.getline(pBaru->nama,30);
    cout << "Masukkan Bidang        : "; cin.getline(pBaru->bidang,15);
    cout << "Masukkan gaji          : Rp "; cin >> pBaru->gaji;
    pBaru->next = NULL;
}

void insertFirst(List& First, pointer pBaru){
    if(First==NULL){
        First = pBaru;
    }
    else{
        pBaru->next = First;
        First = pBaru;
    }
}

void insertLast(List& First, pointer pBaru){
    pointer last;
    if(First==NULL){
        First = pBaru;
    }
    else{
        last = First;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = pBaru;
    }
}

void deleteFirst(List& First, pointer& pHapus){
    if(First==NULL){
        pHapus = NULL;
        cout << "List kosong\n";
    }
    else if(First->next==NULL){
        pHapus = First;
        First = NULL;
    }
    else{
        pHapus = First;
        First = First->next;
        pHapus->next = NULL;
    }
    cout << "Pegawai yang dihapus  : " << pHapus->nama << endl;
}

void deleteLast(List& First, pointer& pHapus){
    pointer last, preclast;
    if(First==NULL){
        pHapus = NULL;
        cout << "List kosong\n";
    }
    else if(First->next==NULL){
        pHapus = First;
        First = NULL;
    }
    else{
        last = First;
        preclast = NULL;
        while (last->next != NULL){
            preclast = last;
            last = last->next;
        }
        pHapus = last;
        preclast->next = NULL;
    }
    cout << "Pegawai yang dihapus   : " << pHapus->nama << endl;
}

void traversal(List First){
    pointer pBantu;
    if(First==NULL){
        cout << "List kosong\n";
    }
    else{
        pBantu = First;
        cout << "----------------------------------------------\n";
        cout << "Nama\t\t" << "Bidang\t\t" << "Gaji\t\n";
        cout << "----------------------------------------------\n";
        while(pBantu != NULL){
            cout << pBantu->nama << "\t" << pBantu->bidang << "\tRp " << pBantu->gaji << endl;
            pBantu = pBantu->next;
        }
        cout << endl;
    }
}
