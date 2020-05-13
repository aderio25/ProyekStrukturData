/*
 PROYEK
 STRUKTUR DATA & ALGORITMA
 GAMES PASIEN CORONA
 RPL UPI 2020
 VERSI 0.2
 RABU, 11 MEI 2020
*/

/* Test Build */

#include <iostream>
#include <time.h>

using namespace std;

const int limit = 10;
struct Stack
{
    int top;
    string tmp[limit];

    void initialize()
    {
        top = -1;
    }

    bool isEmpty()
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

    bool isFull()
    {
        if(top==limit)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void pushPasien(string jenis)
    {
        if(isFull()==true)
        {
            cout<<"Maksimum it cannot be "<<endl;
        }
        else
        {
            top++;
            tmp[top] = jenis;
        }
    }

    string popPasien()
    {
        if(isEmpty()==false)
        {
            return tmp[top--];
        }
        else
        {
            cout<<"Cannot"<<endl;
        }
    }

    void tampilkan()
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
            cout<<"Cannot";
        }
    }
};

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
            ICU.pushPasien(get);

            if(get=="Positif Parah")
            {
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
            Isolasi.pushPasien(get);

            if(get=="Positif Ringan")
            {
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
            Pulang.pushPasien(get);

            if(get=="Negatif")
            {
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

     cout<<"Total Poin = "<<poin<<endl;
}

int main()
{
    bool going = true;
    int n;

    srand(time(NULL));

    cout<<"Masukan level : ";
    cin>>n;

    masukan(&n);

    return 0;

}


