/*
 PROYEK
 STRUKTUR DATA & ALGORITMA
 GAMES PASIEN CORONA
 RPL UPI 2020
 VERSI 0.35
 SABTU, 16 MEI 2020
*/

/* Test Build */

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

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
        cout<<"Ruangan Kosong"<<endl;
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
    int poin = 0;

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

int rawatPasien()
{
    int pilihan;

    cout<<"Pilih ruang yang ingin dirawat ";
    if(pilihan == 1)
    {
        cout<<"Anda telah merawat ruangan ICU";
        return 1;
    }
    else if(pilihan == 2)
    {
        cout<<"Anda telah merawat ruangan Isolasi";
        return 1;
    }
}

void baseLogic()
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

void baseLogic2()
{

}

void resetGame()
{

}

int main()
{
    bool going = true;
    int n;

    srand(time(NULL));

    cout<<"Masukan level : ";
    cin>>n;

    masukan(&n);
    baseLogic();



    return 0;

}


