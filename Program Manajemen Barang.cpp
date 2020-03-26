/*
 PROYEK
 STRUKTUR DATA & ALGORITMA
 MANAJEMEN BARANG
 RPL UPI 2020
 VERSI 1.02
 KAMIS, 26 MARET 2020
*/

/*
 JIka anda ingin mengunduh atau berkontribusi
 pada program ini anda dapat menuju link berikut
 http://gg.gg/gzg1v
*/

/*
 Jika anda ingin mengetahui bagaimana penggunaan
 program ini anda dapat menuju link berikut
 http://gg.gg/gzfzu
*/

/* Library yang diperlukan */
#include <iostream> /* Standar C++ */
#include <iomanip> /* Buat setw() */
#include <stdlib.h> /* Buat System("clear") */
#include <time.h> /* Buat Generate Waktu */

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
    cout<<"*  Versi 1.02                            *"<<endl;
    cout<<"*  Program Ini Dapat Diandalkan Untuk    *"<<endl;
    cout<<"*  Menambah Data Barang, Mengubah Data   *"<<endl;
    cout<<"*  Barang, Serta Mencari Data Barang     *"<<endl;
    cout<<"*                                        *"<<endl;
    cout<<"******************************************"<<endl;
    cout<<" Unduh Source Code : http://gg.gg/gzg1v   "<<endl;
    cout<<" Unduh Manual      : http://gg.gg/gzfzu   "<<endl;
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
    if((head->next==NULL)&&(head->nama==cari))
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
                system("clear");
                cout<<cari<<" tidak ditemukan"<<endl<<endl;
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

/* Prosedur Buat Menampilkan Output Keluar Program */
void credits()
{
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Program Ini Dibuat Dalam Rangka Memenuhi Tugas Mata"<<endl;
    cout<<"Kuliah Struktur Data dan Algoritma RPL UPI 2020"<<endl;
    cout<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<setw(24)<<" Credits : "<<endl;
    cout<<endl;
    cout<<setw(30)<<"Muhammad Raihan S.P.P."<<endl;
    cout<<endl;
    cout<<setw(30)<<"Muhammad Daffa Satrio D."<<endl;
    cout<<endl;
    cout<<setw(30)<<"Mujtahidul Haq Mahyunda"<<endl;
    cout<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
}

int main()
{
    /* Deklarasi yang Dibutuhkan */
    Node data;
    string namaBenda, cariBenda, bendaHapus;
    string teks[3] = {"Program Ini Dibuat Menggunakan Bahasa Pemrograman C++",
                      "Menggunakan Program Ini, Berarti Anda Mengurangi Penggunaan Kertas",
                      "Pada tahun 2017, Terdapat 5.76 Juta Ton Sampah Kertas, Mari Kita Digitalisasi"
                     };
    int jumlahBenda;
    int *ans = nullptr; /* Deklarasi Pointer */
    bool jalan = true;

    /* Tampilan Header Program */
    intro();

    /* Program Berjalan */
    while(jalan)
    {
        /* Alokasi Memori  */
        ans = new int;

        cout<<"Masukan Nama Barang : ";
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
        cin>>*ans;

        cout<<endl;

        /* Hasil Pilihannya */
        if(*ans==1)
            jalan = true;
        else if(*ans==2)
        {
            cout<<"Masukan nama yang ingin dihapus"<<endl;
            cin>>bendaHapus;
            hapusElemen(bendaHapus);
            goto menu;
        }
        else if(*ans==3)
        {
            cout<<"Masukan nama yang ingin dicari "<<endl;
            cin>>cariBenda;
            cariElemen(cariBenda);
            goto menu;
        }
        else if(*ans==4)
        {
            system("clear"); /* Membersihkan Teks */
            srand(time(NULL)); /* Random Seed */
            int random = rand()%3; /* Deklarasi Random */

            cout<<setw(22)<<"Fakta :"<<endl;
            cout<<endl;
            cout<<teks[random]<<endl;

            credits();

            cout<<setw(24)<<"Terima Kasih"<<endl;

            return 0;
        }

        /* Delete Memori */
        delete ans;

    }

}
