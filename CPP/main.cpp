/*
    Saya Septiani Eka Putri NIM 2206000 mengerjakan Latihan Praktikum 1 dalam mata 
    kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya 
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <bits/stdc++.h>
#include <iomanip> // untuk setw
#include "dpr.cpp"  //include file header berisi class dpr
using namespace std;

int main() 
{
    dpr anggota; // membuat objek dari class dpr

    int i, n = 0;   //deklarasi variable integer i dan n
    int id; 	    //deklarasi variable integer id
    string name;    //deklarasi variable string name
    string namaBidang;  //deklarasi variable string nama bidang
    string partai;      //deklarasi variable string partai

    list<dpr> llist;    //membuat list dengan tipe data dpr

    cin >> n; //masukan untuk banyaknya list

    //loop untuk input data anggota dpr ke list
    for (i = 0; i < n; i++) 
    {
        dpr temp;   //membuat objek temp dari class dpr

        cin >> id >> name >> namaBidang >> partai; //input data dpr

        //set nilai atribut objek temp sesuai dengan input
        temp.set_Id(id);
        temp.set_Name(name);
        temp.set_namaBidang(namaBidang);
        temp.set_Partai(partai);

        //memasukan objek temp ke dalam list 
        llist.push_back(temp);
    }

    i = 0;  //iniasilisai nilai i
    //menampilkan header tabel untuk list
    cout << setw(5) << "No." << setw(10) << "ID" << setw(20) << "Nama" << setw(20) << "Nama Bidang" << setw(20) << "Partai" << endl;
    //loop untuk output data anggota dpr dari list
    for (list<dpr>::iterator it = llist.begin(); it != llist.end(); it++) 
    {
        //menampilkan data anggota dpr dalam format tabel
        cout << setw(5) << (i + 1) << setw(10) << it->get_Id() << setw(20) << it->get_Name() << setw(20) << it->get_namaBidang() << setw(20) << it->get_Partai() << '\n';
        i++;
    }

    char operasi;   //deklarasi valiabel karakter operasi
    cout << "pilih operasi yang diinginkan [t/u/h/k] : \n";
    /*
        t untuk tambah
        u untuk ubah
        h untuk hapus
        k untuk keluar
    */

    cin >> operasi; //input operasi yang ingin digunakan

    //loop untuk melakukan operasi tambah, ubah, dan hapus data anggota dpr
    while (operasi != 'k' && operasi != 'K') 
    {   //jika operasi yang dimasukan tambah data
        if (operasi == 't' || operasi == 'T') 
        {
            //input data anggota baru
            cin >> id >> name >> namaBidang >> partai;

            //membuat objek baru dari kelas dpr dan dimasukan ke list
            dpr temp(id, name, namaBidang, partai);
            llist.push_back(temp);

            cout << "anggota berhasil ditambahkan\n" << endl;
        } 
        else if (operasi == 'u' || operasi == 'U')  //jika operasi adalah ubah
        {
            cout << "Masukkan ID anggota yang ingin diubah: \n";

            cin >> id;  //input id anggota yang ingin diubah

            bool ditemukan = false; //inisialisasi variable boolean ditemukan dengan nilai false
            //loop untuk mencari anggota dengan ID yang sesuai
            for (auto &anggota : llist) 
            {
                if (anggota.get_Id() == id) 
                {
                    string name, namaBidang, partai;
                    
                    //input data baru untuk anggota yang akan diubah
                    cout << "Masukkan data baru untuk anggota dengan ID " << id << ":" << endl;
                    cin>> name >> namaBidang >> partai;

                    //mengubah data anggota dengan Id yang sesuai
                    anggota.set_Name(name);
                    anggota.set_namaBidang(namaBidang);
                    anggota.set_Partai(partai);

                    cout << "Anggota dengan ID " << id << " berhasil diubah.\n" << endl;
                    ditemukan = true;   //set ditemukan menjadi true karena anggota ditemukan
                    break;
                }
            }

            //output jika anggota tidak ditemukan
            if (!ditemukan) 
            {
                cout << "Anggota dengan ID " << id << " tidak ditemukan." << endl;
            }
        } 
        else if (operasi == 'h' || operasi == 'H') //jika operasi adalah hapus
        {
            cout << "Masukkan ID anggota yang ingin dihapus: \n";

            cin >> id;  //input id anggota yang ingin dihapus

            bool ditemukan = false; //inisialisasi variable boolean ditemukan dengan nilai false
            //loop untuk mencari anggota dengan ID yang sesuai
            for (auto it = llist.begin(); it != llist.end(); ++it) 
            {
                if (it->get_Id() == id) 
                {
                    llist.erase(it);    //menghaoys anggota dengan ID yang sesuai dari list
                    cout << "Anggota dengan ID " << id << " berhasil dihapus.\n" << endl;
                    ditemukan = true; //set ditemukan menjadi true karena nggota ditemukan
                    break;
                }
            }

            //output jika data tidak ditemukan
            if (!ditemukan) 
            {
                cout << "Anggota dengan ID " << id << " tidak ditemukan.\n" << endl;
            }
        } else {
            cout << "operasi tidak valid.\n" << endl;
        }

        cout << "pilih operasi yang diinginkan [t/u/h/k] : \n";
        cin >> operasi; //input operasi selanjutnya
    }

    cout << "program selesai.\n" << endl;

    i = 0; //inisialisasi nilai i

    //menampilkan header tabel
    cout << setw(5) << "No." << setw(10) << "ID" << setw(20) << "Nama" << setw(20) << "Nama Bidang" << setw(20) << "Partai" << endl;
    //loop untuk menampilkan data anggota dpr yang baru
    for (list<dpr>::iterator it = llist.begin(); it != llist.end(); it++) 
    {
        //output data anggota dpr dengan format tabel
        cout << setw(5) << (i + 1) << setw(10) << it->get_Id() << setw(20) << it->get_Name() << setw(20) << it->get_namaBidang() << setw(20) << it->get_Partai() << '\n';
        i++;
    }

    return 0;
}