#include <bits/stdc++.h>
#include "dpr.cpp"

using namespace std;

int main()
{
    dpr anggota;

    int i, n = 0;
    int id;
    string name;
    string namaBidang;
    string partai;

    list<dpr>llist;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        dpr temp;

        cin >> id >> name >> namaBidang >> partai;

        temp.set_Id(id);
        temp.set_Name(name);
        temp.set_namaBidang(namaBidang);
        temp.set_Partai(partai);

        llist.push_back(temp);
    }

    i = 0;
    for(list<dpr>::iterator it = llist.begin(); it != llist.end(); it++) 
    {
        cout << (i + 1) << "." << it->get_Id() << " | " << it->get_Name() << " | " << it->get_namaBidang() << " | " << it->get_Partai() << '\n';
        i++;
    }

    char operasi;
    cout << "pilih operasi yang diinginkan [t/u/h/k] : \n";
    //t untuk tambah
    //u untuk ubah
    //h untuk hapus
    //k untuk keluar
    cin >> operasi;

    if(operasi == 't' || operasi == 'T')
    {
        cin >> id >> name >> namaBidang >> partai;

        dpr temp(id, name, namaBidang, partai);
        
        llist.push_back(temp);

        cout << "anggota berhasil ditambahkan\n" << endl;
    } 
    else if(operasi == 'u' || operasi == 'U')
    {
        cout << "Masukkan ID anggota yang ingin diubah: \n" ;
        cin >> id;

        bool ditemukan = false;
        for (auto& anggota : llist) {
            if (anggota.get_Id() == id) {
                string name, namaBidang, partai;

                cout << "Masukkan data baru untuk anggota dengan ID " << id << ":" << endl;
                cout << "Nama: "; cin >> name;
                cout << "Nama Bidang: "; cin >> namaBidang;
                cout << "Partai: "; cin >> partai;

                anggota.set_Name(name);
                anggota.set_namaBidang(namaBidang);
                anggota.set_Partai(partai);

                cout << "Anggota dengan ID " << id << " berhasil diubah.\n" << endl;
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            cout << "Anggota dengan ID " << id << " tidak ditemukan." << endl;
        }
    }
    else if (operasi == 'h' || operasi == 'H')
    {
        cout << "Masukkan ID anggota yang ingin dihapus: \n";
        cin >> id;

        bool ditemukan = false;
        for (auto it = llist.begin(); it != llist.end(); ++it) {
            if (it->get_Id() == id) {
                llist.erase(it);
                cout << "Anggota dengan ID " << id << " berhasil dihapus.\n" << endl;
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan) {
            cout << "Anggota dengan ID " << id << " tidak ditemukan.\n" << endl;
        }
    }
    else if (operasi == 'k' || operasi == 'K')
    {
        cout << "program selesai.\n" << endl;
    }
    else 
    {
        cout << "operasi tidak valid.\n" << endl;
    }

    i = 0;
    for(list<dpr>::iterator it = llist.begin(); it != llist.end(); it++) 
    {
        cout << (i + 1) << "." << it->get_Id() << " | " << it->get_Name() << " | " << it->get_namaBidang() << " | " << it->get_Partai() << '\n';
        i++;
    }

    return 0;
}