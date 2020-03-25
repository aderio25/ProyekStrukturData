/*
 PROYEK
 STRUKTUR DATA & ALGORITMA
 MANAJEMEN BARANG
 VERSI 0.92
*/

/* Library yang diperlukan */
#include <iostream> /* Standar C++ */
#include <iomanip> /* Buat setw() */
#include <stdlib.h> /* Buat System("clear") */

using namespace std;

/*  Buat Struct Nyimpen Node
    Ada Nama Barang, dan
    Jumlah Barang */
struct Node
{
    string nama;
    int jumlah;

    struct Node* next;
};

/* Nandain head jadi null */
struct Node *head = NULL;

/* Prosedur Untuk Header AWal Program */
void intro()
{
    cout<<endl;
    cout<<"            PROGRAM MANAJEMEN             "<<endl;
    cout<<"                 BARANG                   "<<endl;
    cout<<"                                          "<<endl;
    cout<<"=========================================="<<endl;
    cout<<"******************************************"<<endl;
    cout<<"*                                        *"<<endl;
    cout<<"*  Selamat Datang !                      *"<<endl;
    cout<<"*  Versi 0.9                             *"<<endl;
    cout<<"*  Program Ini Dapat Diandalkan Untuk    *"<<endl;
    cout<<"*  Menambah Data Barang, Mengubah Data   *"<<endl;
    cout<<"*  Barang, Serta Mencari Data Barang     *"<<endl;
    cout<<"*                                        *"<<endl;
    cout<<"******************************************"<<endl;
    cout<<"=========================================="<<endl;
    cout<<"         Silakan Memulai Program          "<<endl;
    cout<<"         Dengan Input Data Barang         "<<endl;
    cout<<"              Terlebih Dahulu             "<<endl;
    cout<<"=========================================="<<endl;
    cout<<endl;
}

/* Prosedur Buat Nambah Data */
void tambahBelakang(string b, int c)
{
    struct Node *temp = new Node;
    struct Node *addBaru = new Node;
    addBaru->nama = b;
    addBaru->jumlah = c;
    addBaru->next = NULL;

    if(head==NULL)
    {
        head = addBaru;
        head->next = NULL;
    }
    else
    {
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = addBaru;

    }

}

/* Prosedur Buat Hapus Data */
void hapusElemen(string cari)
{
    struct Node *ptr1;
    struct Node *ptr2;

    /* Kalau Satu-Satunya */
    if(head->next==NULL)
        head=NULL;
    else
    {
         /* Kalau Head sama Dengan yang dicari */
         if(head->nama==cari)
         {
            ptr1 = head;
            head = head->next;
            ptr1->next = NULL;
            delete ptr1;
         }
         /* Kalau Head Tidak Sama Dengan Yang Dicari */
         else
         {
            ptr1 = head;
            while((ptr1->next!=NULL)&&(ptr1->nama!=cari))
            {
                ptr2 = ptr1;
                ptr1 = ptr1->next;
            }
            if(ptr1->nama==cari)
            {
                ptr2->next = ptr1->next;
                delete ptr1;
                system("clear");
                cout<<"-> "<<cari<<" Terhapus "<<endl;
                cout<<endl;
            }
            else
            {
                cout<<"Data tidak ditemukan"<<endl;
            }
        }
    }

}

/* Prosedut Untuk Menampilkan Data*/
void tampilkan()
{
    /* Ketika Data Kosong */
    if(head==NULL)
        return;
    struct Node *temp = head;

    cout<<setw(14)<<"DATA BARANG"<<endl;
    cout<<"================="<<endl;
    cout<<setw(9)<<"Nama"<<setw(8)<<"Qty"<<endl;
    cout<<"================="<<endl;

    /* Looping Menampilkan */
    while(temp!=NULL)
    {

        cout<<setw(10)<<temp->nama<<setw(5)<<temp->jumlah<<endl;
        cout<<"-----------------"<<endl;
        temp = temp->next;
    }
}

/* Prosedur Untuk Mencari Elemen */
void cariElemen(string cari)
{
    /* Ketika Data Kosong */
    if(head==NULL)
        return;
    struct Node *temp = head;

    /* Looping */
    while((temp!=NULL)&&(temp->nama!=cari))
    {
        temp = temp->next;
    }

    /* Ketika Sesuai Dengan yang Dicari */
    if(temp->nama==cari)
    {
        system("clear");
        cout<<"Data Ditemukan"<<endl;
        cout<<"Nama Barang : "<<temp->nama<<endl;
        cout<<"Jumlah : "<<temp->jumlah<<endl;
        cout<<endl;
    }
    /* Ketika Tidak Sesuai */
    else
    {
        cout<<"Data Tidak Ditemukan"<<endl;
    }

}

int main()
{
    /* Deklarasi yang Dibutuhkan */
    Node data;
    string namaBenda, cariBenda, bendaHapus;
    int ans,jumlahBenda;
    int urut = 1;
    int patokan = 0;
    bool jalan = true;

    /* Tampilan Header Program */
    intro();

    /* Program Berjalan */
    while(jalan)
    {
        cout<<"Masukan Nama Benda : ";
        cin>>namaBenda;

        cout<<"Masukan Jumlah : ";
        cin>>jumlahBenda;

        /* Memanggil Fungsi dengan Parameter */
        tambahBelakang(namaBenda,jumlahBenda);
        cout<<endl;

        /* Clear Teks di CMD */
        system("clear");

        /* Tempat Kembali Goto */
        menu:

        /* Menampilkan Data */
        tampilkan();
        cout<<endl;

        /* List Pilihan */
        cout<<"-----------------------------------"<<endl;
        cout<<"Silakan Pilih : "<<endl;
        cout<<setw(1)<<"[1] Tambah Data "<<setw(15)<<"[3] Cari Data"<<endl;
        cout<<setw(1)<<"[2] Hapus Data"<<setw(12)<<"[4] Exit"<<endl;
        cout<<"-----------------------------------"<<endl;
        cin>>ans;

        cout<<endl;

        /* Hasil Pilihannya */
        if(ans==1)
            jalan = true;
        else if(ans==2)
        {
            cout<<"Masukan nama yang ingin dihapus"<<endl;
            cin>>bendaHapus;
            hapusElemen(bendaHapus);
            goto menu;
        }
        else if(ans==3)
        {
            cout<<"Masukan nama yang ingin dicari "<<endl;
            cin>>cariBenda;
            cariElemen(cariBenda);
            goto menu;
        }
        else if(ans==4)
        {
            return 0;
        }
    }
}
