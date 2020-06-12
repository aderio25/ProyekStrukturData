/*
 PROYEK
 STRUKTUR DATA & ALGORITMA
 GAMES PASIEN CORONA
 RPL UPI 2020
 VERSI 0.48
 JUMAT, 12 JUNI 2020
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
    bool isEmpty();
    bool isFull();
    void pushPasien(string jenis);
    string popPasien();
    void tampilkan();

};

struct base
{
    void baseLogic();
};

void Stack ::initialize()
{
    top = -1;
}

bool Stack ::isEmpty()
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

bool Stack ::isFull()
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

void Stack ::pushPasien(string jenis)
{
    if(isFull()==true)
    {
        cout<<"Ruangan Penuh"<<endl;
    }
    else
    {
        top++;
        tmp[top] = jenis;
    }
}

string Stack ::popPasien()
{
    if(isEmpty()==true)
    {
        cout<<"Kosong"<<endl;
    }
    else
    {
        return tmp[top--];
    }
}

void Stack ::tampilkan()
{
    if(isEmpty()==false)
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

string randomPasien()
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
        get = randomPasien();
        cout<<get<<endl;

        cout<<"Pilih : "<<endl;
        cin>>ans;

        if(ans==1)
        {

            if(get=="Positif Parah")
            {
                ICU.pushPasien(get);
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
                Isolasi.pushPasien(get);
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
                Pulang.pushPasien(get);
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

bool rawatPasien(int pilihan)
{
    if(pilihan == 1)
    {
        cout<<"Anda telah merawat ruangan ICU";
        return true;
    }
    else if(pilihan == 2)
    {
        cout<<"Anda telah merawat ruangan Isolasi";
        return true;
    }

    return false;
}

void base:: baseLogic()
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

string ambilPasien()
{
    int a;

    cout<<"Silakan pilih ";
    cin>>a;

    if(rawat==true)
    {
        if(a==1)
        {
            return ICU.popPasien();
        }
        else if(a==2)
        {
            return Isolasi.popPasien();
        }
    }
    else
    {
        poin = poin - 10;
        cout<<"Salah ";
    }
}

void tujuanPasien()
{
    int a;

    cout<<"Silakan pilih tujuan ";
    cin>>a;

    if(a==1)
    {
        ICU.pushPasien(ambilPasien());
    }
    else if(a==2)
    {
        Isolasi.pushPasien(ambilPasien());
    }
    else if(a==3)
    {
        Pulang.pushPasien(ambilPasien());
    }

}

void resetGame()
{
    while(ICU.popPasien() != "Kosong")
    {
        ICU.popPasien();
    }

    while(Isolasi.popPasien() == "Kosong")
    {
        Isolasi.popPasien();
    }

    while(Pulang.popPasien() == "Kosong")
    {
        Pulang.popPasien();
    }
}

int main()
{
    base game;

    bool going = true;
    int n;

    srand(time(NULL));

    cout<<"Masukan level : ";
    cin>>n;

    masukan(&n);
    game.baseLogic();



    return 0;

}


