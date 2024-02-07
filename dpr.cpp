#include <iostream>
#include <string>

using namespace std;

class dpr
{
    private:
        int id;
        string name;
        string namaBidang;
        string partai;
    
    public:
        dpr()
        {
            this->id = '-';
            this->name = "";
            this->namaBidang = "";	
            this->partai = "";
        }

        dpr(int id, string name, string namaBidang, string partai)
        {
            this->id = id;
            this->name = name;
            this->namaBidang = namaBidang;
            this->partai = partai;
        }

        int get_Id()
        {
            return this->id;
        }

        void set_Id(int id)
        {
            this->id = id;
        }

        string get_Name()
        {
            return this->name;
        }

        void set_Name(string name)
        {
            this->name = name;
        }

        string get_namaBidang()
        {
            return this->namaBidang;
        }

        void set_namaBidang(string namaBidang)
        {
            this->namaBidang = namaBidang;
        }

        string get_Partai()
        {
            return this->partai;
        }

        void set_Partai(string partai)
        {
            this->partai = partai;
        }

        
        ~dpr()
        {

        }

};