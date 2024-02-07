/*
    Saya Septiani Eka Putri NIM 2206000 mengerjakan Latihan Praktikum 1 dalam mata 
    kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya 
    tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <iostream>
#include <string>

using namespace std;

class dpr
{
    private:
        int id;             //atribut ID untuk menyimpan ID anggota DPR
        string name;        //atribut name untuk menyimpan nama anggota DPR
        string namaBidang;  //atribut nama bidang untuk menyimpan bidang anggota DPR
        string partai;      //atribut partai untuk menyimpan partai anggota DPR
    
    public:
        dpr()
        {
            //inisialisasi nilai untuk setiap atribut
            this->id = '-';         //nilai ID diatur sebagai karakter '-'
            this->name = "";        //nilai name diatur sebagai string kosong
            this->namaBidang = "";	//nilai nama bidang diatur sebagai string kosong
            this->partai = "";      //nilai partai diatur sebagai string kosong
        }

        //parameter untuk kelas dpr
        dpr(int id, string name, string namaBidang, string partai)
        {
            //inisialisasi atribut dengan nilai yang diberikan saat pembuatan objek
            this->id = id;
            this->name = name;
            this->namaBidang = namaBidang;
            this->partai = partai;
        }

        //untuk akses nilai atribut ID
        int get_Id()
        {
            return this->id;
        }

        //untuk mengubah nilai atribut ID
        void set_Id(int id)
        {
            this->id = id;
        }

        //untuk akses nilai atribut name
        string get_Name()
        {
            return this->name;
        }

        //untuk mengubah nilai atribut name
        void set_Name(string name)
        {
            this->name = name;
        }

        //untuk akses nilai atribut nama bidang
        string get_namaBidang()
        {
            return this->namaBidang;
        }

        //untuk mengubah nilai atribut nama bidang
        void set_namaBidang(string namaBidang)
        {
            this->namaBidang = namaBidang;
        }

        //untuk akses nilai atribut partai
        string get_Partai()
        {
            return this->partai;
        }

        //untuk mengubah nilai atribut partai
        void set_Partai(string partai)
        {
            this->partai = partai;
        }

        
        ~dpr()
        {

        }

};