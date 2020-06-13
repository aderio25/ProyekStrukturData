/*
 PROYEK
 STRUKTUR DATA & ALGORITMA
 GAMES PASIEN CORONA
 RPL UPI 2020
 VERSI 0.65
 SABTU, 13 JUNI 2020
*/

/* Test Build */

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int poin = 0;
bool rawat = false;
const int limit = 10;

struct Stack
{
    int top;
    string tmp[limit];

    void initialize();
    void tampilkan();
    void push_pasien(string jenis);
    string pop_pasien();
    bool is_empty();
    bool is_full();

};

struct base
{
    bool ICU_done = false;
    bool isolasi_done = false;

    void show_pasien();
    void tujuan_pasien();
    void reset_game();
    void rawat_pasien(int a);
    string ambil_pasien();
};

void Stack:: initialize()
{
    top = -1;
}

bool Stack:: is_empty()
{
    if(top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack:: is_full()
{
    if(top==limit-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack:: push_pasien(string jenis)
{
    if(is_full()==true)
    {
        cout<<"Ruangan Penuh"<<endl;
    }
    else
    {
        top++;
        tmp[top] = jenis;
    }
}

string Stack:: pop_pasien()
{
    if(is_empty()==true)
    {
        cout<<"Kosong"<<endl;
    }
    else
    {
        string pop = tmp[top--];
        return pop;
    }
}

void Stack:: tampilkan()
{
    if(is_empty()==false)
    {
        for(int i=top;i>=0;i--)
        {
            cout<<tmp[i]<<endl;
        }
    }
    else
    {
        cout<<"Eror"<<endl;
    }
}

Stack ICU;
Stack Isolasi;
Stack Pulang;

string random_pasien()
{

    string tipe[3] = {"Positif Parah","Positif Ringan","Negatif"};
    string random;
    for(auto i(0);i<3;i++)
    {
        random = tipe[rand()%3];
    }

    return random;

}

void masukan(int *level)
{
    string get;
    int ans;
    int hati = 3;


    for(auto i(0);i<*(level)*2;i++)
    {
        get = random_pasien();
        cout<<get<<endl;

        cout<<"Pilih : "<<endl;
        cin>>ans;

        if(ans==1)
        {

            if(get=="Positif Parah")
            {
                ICU.push_pasien(get);
                poin = poin + 10;
                cout<<"Benar"<<endl;
            }
            else
            {
                poin = poin - 10;
                cout<<"Salah"<<endl;
                hati--;
            }
        }
        else if(ans==2)
        {

            if(get=="Positif Ringan")
            {
                Isolasi.push_pasien(get);
                poin = poin + 10;
                cout<<"Benar"<<endl;
            }
            else
            {
                poin = poin - 10;
                cout<<"salah"<<endl;
                hati--;
            }
        }
        else if(ans==3)
        {

            if(get=="Negatif")
            {
                Pulang.push_pasien(get);
                poin = poin + 10;
                cout<<"Benar"<<endl;
            }
            else
            {
                poin = poin - 10;
                cout<<"Salah"<<endl;
                hati--;
            }
        }

        cout<<"----------------"<<endl;
    }

     cout<<"Total Poin = "<<poin<<endl<<endl;
}

void base:: rawat_pasien(int pilihan)
{
    if(pilihan == 1)
    {
        cout<<"Anda telah merawat ruangan ICU";
        ICU_done = true;
    }
    else if(pilihan == 2)
    {
        cout<<"Anda telah merawat ruangan Isolasi";
        isolasi_done = true;
    }

}

void base:: show_pasien()
{
    for(int j=0;j<1;j++)
    {
        if((ICU.top > Isolasi.top) && (ICU.top > Pulang.top))
        {
            for(int i=ICU.top;i>=0;i--)
            {
                cout<<setw(15)<<ICU.tmp[i]<<setw(20)<<Isolasi.tmp[i]<<setw(15)<<Pulang.tmp[i]<<endl;
            }
        }
        else if((Isolasi.top > ICU.top) && (Isolasi.top > Pulang.top))
        {
            for(int i=Isolasi.top;i>=0;i--)
            {
                cout<<setw(15)<<ICU.tmp[i]<<setw(20)<<Isolasi.tmp[i]<<setw(15)<<Pulang.tmp[i]<<endl;
            }
        }
        else if((Pulang.top > ICU.top) && (Pulang.top > Isolasi.top))
        {
            for(int i=Pulang.top;i>=0;i--)
            {
                cout<<setw(15)<<ICU.tmp[i]<<setw(20)<<Isolasi.tmp[i]<<setw(15)<<Pulang.tmp[i]<<endl;
            }
        }
        else if((ICU.top == Isolasi.top) || (ICU.top == Pulang.top))
        {
            for(int i=ICU.top;i>=0;i--)
            {
                cout<<setw(15)<<ICU.tmp[i]<<setw(20)<<Isolasi.tmp[i]<<setw(15)<<Pulang.tmp[i]<<endl;
            }
        }
        else if((Isolasi.top == ICU.top ) || (Isolasi.top == Pulang.top))
        {
            for(int i=Isolasi.top;i>=0;i--)
            {
                cout<<setw(15)<<ICU.tmp[i]<<setw(20)<<Isolasi.tmp[i]<<setw(15)<<Pulang.tmp[i]<<endl;
            }
        }
        else if((Pulang.top == ICU.top) || (Pulang.top == Isolasi.top))
        {
            for(int i=Pulang.top;i>=0;i--)
            {
                cout<<setw(15)<<ICU.tmp[i]<<setw(20)<<Isolasi.tmp[i]<<setw(15)<<Pulang.tmp[i]<<endl;
            }
        }

    }
}

string base:: ambil_pasien()
{
    int ans;

    cout<<"Silakan pilih ";
    cin>>ans;

    if((ICU_done==true) || (isolasi_done==true))
    {
        if((ans==1) && (ICU_done==true))
        {
            return ICU.pop_pasien();
        }
        else if((ans==2) && (isolasi_done==true))
        {
            return Isolasi.pop_pasien();
        }
    }
    else
    {
        poin = poin - 10;
        cout<<"Anda tidak dapat memilih, sebelum merawat pasiennya terlebih dahulu ";
    }
}

void base:: tujuan_pasien()
{
    int ans;

    cout<<"Silakan pilih tujuan ";
    cin>>ans;

    if(ans==1)
    {
        ICU.push_pasien(ambil_pasien());
    }
    else if(ans==2)
    {
        Isolasi.push_pasien(ambil_pasien());
    }
    else if(ans==3)
    {
        Pulang.push_pasien(ambil_pasien());
    }

}

void base:: reset_game()
{
    while(ICU.pop_pasien() != "Kosong")
    {
        ICU.pop_pasien();
    }

    while(Isolasi.pop_pasien() == "Kosong")
    {
        Isolasi.pop_pasien();
    }

    while(Pulang.pop_pasien() == "Kosong")
    {
        Pulang.pop_pasien();
    }
}

int main()
{
    base game;

    bool going = true;
    int n,a;
    string get_ambil_pasien;

    srand(time(NULL));

    cout<<"Masukan level : ";
    cin>>n;

    masukan(&n);
    // First Step
    game.show_pasien();

    // Second Step
    cout<<"Masukan pilihan yang ingin dirawat : ";
    cin>>a;
    game.rawat_pasien(a);

    while(going)
    {

        /* Third Step
        get_ambil_pasien = game.ambil_pasien();
        cout<<"anda memilih pasien : "<<get_ambil_pasien;
        */

        // Fourth Step
        game.tujuan_pasien();

        game.show_pasien();

    }


    return 0;

}


