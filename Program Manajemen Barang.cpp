/*
 PROYEK
 STRUKTUR DATA & ALGORITMA
 MANAJEMEN BARANG
 VERSI 0.85
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct Node
{
    string nama;
    int jumlah;

    struct Node* next;
};

struct Node *head = NULL;

void intro()
{
    cout<<endl;
    cout<<"            PROGRAM MANAJEMEN             "<<endl;
    cout<<"                 BARANG                   "<<endl;
    cout<<"=========================================="<<endl;
    cout<<"******************************************"<<endl;
    cout<<"** Selamat Datang !                     **"<<endl;
    cout<<"** Versi 0.8                            **"<<endl;
    cout<<"** Program Ini Dapat Diandalkan Untuk   **"<<endl;
    cout<<"** Menambah Data Barang, Mengubah Data  **"<<endl;
    cout<<"** Barang, Serta Mencari Data Barang    **"<<endl;
    cout<<"******************************************"<<endl;
    cout<<"=========================================="<<endl;
    cout<<"         Silakan Memulai Program          "<<endl;
    cout<<"         Dengan Input Data Barang         "<<endl;
    cout<<"              Terlebih Dahulu             "<<endl;
    cout<<"=========================================="<<endl;
    cout<<endl;
}

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

void hapusElemen(string cari)
{
    struct Node *ptr1;
    struct Node *ptr2;

    if(head->next==NULL)
        cout<<"Error";
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
            cout<<"Deleted";
         }
         else
         {
            cout<<"Data tidak ditemukan";
         }
    }

}

void tampilkan()
{
    if(head==NULL)
        return;
    struct Node *temp = head;

    cout<<setw(14)<<"DATA BARANG"<<endl;
    cout<<"================="<<endl;
    cout<<setw(9)<<"Nama"<<setw(8)<<"Qty"<<endl;
    cout<<"================="<<endl;

    while(temp!=NULL)
    {

        cout<<setw(10)<<temp->nama<<setw(5)<<temp->jumlah<<endl;
        cout<<"-----------------"<<endl;
        temp = temp->next;
    }
}

void cariElemen(string cari)
{
    if(head==NULL)
        return;
    struct Node *temp = head;

    while((temp!=NULL)&&(temp->nama!=cari))
    {
        temp = temp->next;
    }
    if(temp->nama==cari)
    {
        cout<<"Data Ditemukan"<<endl;
        cout<<setw(10)<<temp->nama<<setw(5)<<temp->jumlah<<endl;
    }
    else
    {
        cout<<"Data Tidak Ditemukan"<<endl;
    }

}

int main()
{
    Node data;
    string namaBenda, cariBenda, bendaHapus;
    int ans,jumlahBenda;
    int urut = 1;
    int patokan = 0;
    bool jalan = true;

    intro();

    while(jalan)
    {
        cout<<"Masukan Nama Benda : ";
        cin>>namaBenda;

        cout<<"Masukan Jumlah : ";
        cin>>jumlahBenda;

        tambahBelakang(namaBenda,jumlahBenda);

        cout<<endl;

        system("clear");

        menu:

        tampilkan();

        cout<<endl;

        cout<<"---------------------------------------------"<<endl;
        cout<<"Silakan Pilih : "<<endl;
        cout<<setw(1)<<"[1]Tambah Data "<<setw(15)<<"[2]Hapus Data"<<setw(15)<<"[3]Cari Data"<<endl;
        cout<<"---------------------------------------------"<<endl;
        cin>>ans;

        cout<<endl;

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
    }
}
