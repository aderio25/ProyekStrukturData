/*
 PROYEK
 STRUKTUR DATA & ALGORITMA
 GAMES PASIEN CORONA
 RPL UPI 2020
 VERSI 0.85
 SELASA, 16 JUNI 2020
*/

/* Test Build */

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int poin = 0;
bool rawat = false;
const int limit = 10;

struct pasien_behaviour
{
    // Metode Stack
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
    bool cek_ruangan_kosong();
};

struct teks
{
    void header_version();
    void intro();
    void cara();
    void credits();
    void about();
    void tips();
    void lvl();
   
};

struct game_save
{

};

void pasien_behaviour:: initialize()
{
    top = -1;
}

bool pasien_behaviour:: is_empty()
{
    if(top==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool pasien_behaviour:: is_full()
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

void pasien_behaviour:: push_pasien(string jenis)
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

string pasien_behaviour:: pop_pasien()
{
    if(is_empty()==true)
    {
        cout<<"Kosong"<<endl;
    }
    else
    {
        string pop = tmp[top];
        tmp[top] = "";
        tmp[top--];
        return pop;
    }
}

void pasien_behaviour:: tampilkan()
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

pasien_behaviour ICU;
pasien_behaviour Isolasi;
pasien_behaviour Pulang;

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

    cout<<"+-------------------------------------------+"<<endl;
    cout<<"| 2. Game akan Secara Acak memberikan Jenis |"<<endl;
    cout<<"|    Pasien Kepada Pemain mengenai kondisi  |"<<endl;
    cout<<"|    pasien yang terjangkit Covid-19 Mulai  |"<<endl;
    cout<<"|    dari 'Parah-Biasa-Negatif' dan banyak- |"<<endl;
    cout<<"|    nya pasien tergantung level yang pemain|"<<endl;
    cout<<"|    Pilih.                                 |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"|               Pilihan Jawaban             |"<<endl;
    cout<<"|              1 = Positif Parah            |"<<endl;
    cout<<"|              2 = Positif Ringan           |"<<endl;
    cout<<"|              3 = negatif                  |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
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
     cout<<endl;
    cout<<endl;
}

void base:: rawat_pasien(int pilihan)
{
    if(pilihan == 1)
    {
        cout<<"Anda telah merawat ruangan ICU"<<endl;
        ICU_done = true;
    }
    else if(pilihan == 2)
    {
        cout<<"Anda telah merawat ruangan Isolasi"<<endl;
        isolasi_done = true;
    }

}


void base:: show_pasien()
{
                cout<<endl;
                cout<<endl;
                cout<<"+-----------------------------------------------------+"<<endl;
                cout<<"|    3. Pemain Harus memilih ruangan yang di          |"<<endl;
                cout<<"|        sesuaikan dengan jenis dan kondisi           |"<<endl;
                cout<<"|        pasien (pilih 1-3)                           |"<<endl;
                cout<<"|        1. Kiri   = Ruang ICU                        |"<<endl;
                cout<<"|        2. Tengan = Ruang Isolasai                   |"<<endl;
                cout<<"|        3. Kanan  = Ruang keluar                     |"<<endl;
                cout<<"+-----------------------------------------------------+"<<endl;
                cout<<"|=====================================================|"<<endl;
                cout<<"|                        RUANGAN                      |"<<endl;
                cout<<"|=====================================================|"<<endl;
                cout<<"|        1        |         2        |        3       |"<<endl;
                cout<<"|=====================================================|"<<endl;
    for(int j=0;j<1;j++)
    {
        if((ICU.top > Isolasi.top) && (ICU.top > Pulang.top))
        {
            for(int i=ICU.top;i>=0;i--)
            {
                cout<<"|"<<setw(16)<<ICU.tmp[i]<<" |"<<setw(18)<<Isolasi.tmp[i]<<"|"<<setw(16)<<Pulang.tmp[i]<<"| "<<endl;
            }
        }
        else if((Isolasi.top > ICU.top) && (Isolasi.top > Pulang.top))
        {
            for(int i=Isolasi.top;i>=0;i--)
            { 
                cout<<"|"<<setw(16)<<ICU.tmp[i]<<" |"<<setw(18)<<Isolasi.tmp[i]<<"|"<<setw(16)<<Pulang.tmp[i]<<"| "<<endl;
            }
        }
        else if((Pulang.top > ICU.top) && (Pulang.top > Isolasi.top))
        {
            for(int i=Pulang.top;i>=0;i--)
            {
                cout<<"|"<<setw(16)<<ICU.tmp[i]<<" |"<<setw(18)<<Isolasi.tmp[i]<<"|"<<setw(16)<<Pulang.tmp[i]<<"| "<<endl;
            }
        }
        else if((ICU.top == Isolasi.top) || (ICU.top == Pulang.top))
        {
            for(int i=ICU.top;i>=0;i--)
            {
                cout<<"|"<<setw(16)<<ICU.tmp[i]<<" |"<<setw(18)<<Isolasi.tmp[i]<<"|"<<setw(16)<<Pulang.tmp[i]<<"| "<<endl;
            }
        }
        else if((Isolasi.top == ICU.top ) || (Isolasi.top == Pulang.top))
        {
            for(int i=Isolasi.top;i>=0;i--)
            {
                cout<<"|"<<setw(16)<<ICU.tmp[i]<<" |"<<setw(18)<<Isolasi.tmp[i]<<"|"<<setw(16)<<Pulang.tmp[i]<<"| "<<endl;
            }
        }
        else if((Pulang.top == ICU.top) || (Pulang.top == Isolasi.top))
        {
            for(int i=Pulang.top;i>=0;i--)
            {
                cout<<"|"<<setw(16)<<ICU.tmp[i]<<" |"<<setw(18)<<Isolasi.tmp[i]<<"|"<<setw(16)<<Pulang.tmp[i]<<"| "<<endl;
            }
        }

    }
                cout<<"|=====================================================|"<<endl;
}


string base:: ambil_pasien()
{
    int ans;

    cout<<"Silakan pilih ruangan yang akan dipindah : ";
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
        cout<<"Anda tidak dapat memilih, sebelum merawat pasiennya terlebih dahulu "<<endl;
    }
}

void base:: tujuan_pasien()
{
    int ans;

    cout<<"Silakan pilih tujuan Ruangan : ";
    cin>>ans;

    if(ans==1)
    {
        ICU.push_pasien(ambil_pasien());
        poin = poin - 5;
        cout<<"Salah, 5 poin dikurangi"<<endl;
        cout<<endl;
    }
    else if(ans==2)
    {
        Isolasi.push_pasien(ambil_pasien());
        poin = poin - 5;
        cout<<"Salah, 5 poin dikurangi"<<endl;
        cout<<endl;
    }
    else if(ans==3)
    {
        Pulang.push_pasien(ambil_pasien());
        poin = poin + 5;
        cout<<"Benar, 5 poin ditambahkan"<<endl;
        cout<<endl;
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

bool base:: cek_ruangan_kosong()
{
    if((ICU.is_empty()==false) && (Isolasi.is_empty()==false))   
    {
        if((ICU.tmp[1]=="") && (Isolasi.tmp[1]==""))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(ICU.is_empty()==true)
    {
        if(Isolasi.tmp[1]=="")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(Isolasi.is_empty()==true)
    {
        if(ICU.tmp[1]=="")
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
}

void teks:: header_version()
{
                cout<<"+-------------------+"<<endl;
                cout<<"|      Co-Games     |"<<endl;
                cout<<"|     Versi 0.85    |"<<endl;
                cout<<"|  Work In Progress |"<<endl;
                cout<<"|       Alpha       |"<<endl;
                cout<<"+-------------------+"<<endl;
                cout<<endl;
}

void teks:: intro()
{
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"|   Selamat Datang di Permainan Co-Games    |"<<endl;
    cout<<"|        Sebelum Dimulai Permainan          |"<<endl;
    cout<<"|   Baca Tata cara permain Telebih Dahulu   |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
}


void teks:: cara()
{
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"|             Tata Cara Bermain             |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"| 1. Inputkan Angka 1-10 untuk menentukan   |"<<endl;
    cout<<"|    Level yang User Inginkan !             |"<<endl;
    cout<<"|    1 = Mudah                              |"<<endl;
    cout<<"|    10= Sulit                              |"<<endl;
    cout<<"|                                           |"<<endl;
    cout<<"| 2. Game akan Secara Acak memberikan Jenis |"<<endl;
    cout<<"|    Pasien Kepada User mengenai kondisi    |"<<endl;
    cout<<"|    pasien yang terjangkit Covid-19 Mulai  |"<<endl;
    cout<<"|    dari Parah-Biasa-Negatif dan banyaknya |"<<endl;
    cout<<"|    pasien tergantung level yang user      |"<<endl;
    cout<<"|    Pilih.                                 |"<<endl;
    cout<<"|                                           |"<<endl;
    cout<<"| 3. User Harus memilih ruangan yang di     |"<<endl;
    cout<<"|    sesuaikan dengan jenis dan kondisi     |"<<endl;
    cout<<"|    pasien (pilih 1-3)                     |"<<endl;
    cout<<"|    1. Kiri   = Ruang ICU                  |"<<endl;
    cout<<"|    2. Tengan = Ruang Isolasai             |"<<endl;
    cout<<"|    3. Kanan  = Ruang keluar               |"<<endl;
    cout<<"|                                           |"<<endl;
    cout<<"| 4. Jika pasien Salah masuk ruangan, maka  |"<<endl;
    cout<<"|    poin yang telah didapat akan berkurang |"<<endl;
    cout<<"|    10 point, jika benar maka bertambah 10 |"<<endl;
    cout<<"|    point                                  |"<<endl;
    cout<<"|                                           |"<<endl;
    cout<<"|  5. User harus merawat pasien yang berada |"<<endl;
    cout<<"|     diruangan ICU dan ruangan Isolasi     |"<<endl;
    cout<<"|                                           |"<<endl;
    cout<<"|  6. User harus memasukan tujuan pemindahan|"<<endl;
    cout<<"|     pasien jika pasien sudah berhasil di  |"<<endl;
    cout<<"|     rawat                                 |"<<endl;
    cout<<"|                                           |"<<endl;
    cout<<"|  7. Jika User salah memasukan ruangan tuju|"<<endl;
    cout<<"|     an pasien maka, point yang telah di   |"<<endl;
    cout<<"|     peroleh akan berkurang 5 point, berla |"<<endl;
    cout<<"|     ku juga sebaliknya                    |"<<endl;
    cout<<"|                                           |"<<endl;
    cout<<"|  8. Game akan otomatis Selesai, Jika      |"<<endl;
    cout<<"|     pasien di  Ruang ICU dan Isolasi      |"<<endl;
    cout<<"|     sudah Kosong                          |"<<endl;
    cout<<"|                                           |"<<endl;
    cout<<"|  9. Nama User akan Tertera pada           |"<<endl;
    cout<<"|     LeaderBoard                           |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"|                 Peraturan                 |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"|   1. Terdapat dua penilaian skor          |"<<endl;
    cout<<"|     -ketika memilih ruangan pasien diawal |"<<endl;
    cout<<"|     -Ketika memilih ruangan pasien diakhir|"<<endl;
    cout<<"|                                           |"<<endl;
    cout<<"|   2. Sisitem skor memilih ruangan diawal  |"<<endl;
    cout<<"|     - Benar = 10 point bertambah          |"<<endl;
    cout<<"|     - Salah = 10 point berkurang          |"<<endl;
    cout<<"|                                           |"<<endl;
    cout<<"|   3. Sistem skor memilih ruangan diakhir  |"<<endl;
    cout<<"|     - Benar = 5 point bertambah           |"<<endl;
    cout<<"|     - Salah = 5 point berkurang           |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
    cout<<endl;
    cout<<endl;
    
    
    
    
    
    
    
}

void teks:: lvl()
{
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"| 1. Inputkan Angka 1-10 untuk menentukan   |"<<endl;
    cout<<"|    Level yang Pemain Inginkan !           |"<<endl;
    cout<<"|    1 = Mudah                              |"<<endl;
    cout<<"|    10= Sulit                              |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
}

void teks:: credits()
{
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"|                 Credits                   |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"|        Struktur Data dan Algoritma        |"<<endl;
    cout<<"|                Kelompok 3                 |"<<endl;
    cout<<"|                  RPL 2A                   |"<<endl;
    cout<<"|                 Anggota                   |"<<endl;
    cout<<"|        Muhammad Raihan Satrio P.P         |"<<endl;
    cout<<"|        Muhammad Daffa Satrio Dradjat      |"<<endl;
    cout<<"|        Mujtahidul Haq Mahyunda            |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
    
}

void teks:: about()
{
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"|                  About                    |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
    cout<<"|  Nama Program : Co-Games (Covid-19 Games) |"<<endl;
    cout<<"|  Versi        : Versi 0.85                |"<<endl;
    cout<<"|  Update       : 16/06/2020                |"<<endl;
    cout<<"+-------------------------------------------+"<<endl;
    
}



int main()
{
    base game;
    teks deskripsi;

    bool going = true;
    int n,a;
    string get_ambil_pasien;

    srand(time(NULL));

    deskripsi.header_version();
    deskripsi.intro();
    deskripsi.cara();
    deskripsi.lvl();
    cout<<"Masukan level : ";
    cin>>n;

    masukan(&n);
    // First Step
    game.show_pasien();

    // Second Step
    
    while((game.ICU_done==false) || (game.isolasi_done==false))
    {
        if((Isolasi.is_empty()==false) && (ICU.is_empty()==false))
        {
          
            cout<<"Masukan pilihan yang ingin dirawat : ";
            cin>>a;
            game.rawat_pasien(a);
        }
        else if((Isolasi.is_empty()==true) || (ICU.is_empty()==true))
        {
            
            cout<<"Masukan pilihan yang ingin dirawat : ";
            cin>>a;
            game.rawat_pasien(a);
            break;
        }
        
    }

    while(going)
    {

        /* Third Step
        get_ambil_pasien = game.ambil_pasien();
        cout<<"anda memilih pasien : "<<get_ambil_pasien;
        */

        // Fourth Step
        game.tujuan_pasien();

        game.show_pasien();

        cout<<"Poin : "<<poin<<endl;

        going = !game.cek_ruangan_kosong();

    }
    deskripsi.credits();
    deskripsi.about();
    


    return 0;

}
