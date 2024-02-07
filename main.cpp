#include <iostream>
#include <iomanip> // untuk setw
#include <list>
#include <string>
using namespace std;

class dpr {
private:
    int Id;
    string Name;
    string namaBidang;
    string Partai;

public:
    dpr() {}
    dpr(int id, string name, string bidang, string partai)
        : Id(id), Name(name), namaBidang(bidang), Partai(partai) {}

    // Setter
    void set_Id(int id) { Id = id; }
    void set_Name(string name) { Name = name; }
    void set_namaBidang(string bidang) { namaBidang = bidang; }
    void set_Partai(string partai) { Partai = partai; }

    // Getter
    int get_Id() { return Id; }
    string get_Name() { return Name; }
    string get_namaBidang() { return namaBidang; }
    string get_Partai() { return Partai; }
};

int main() {
    dpr anggota;

    int i, n = 0;
    int id;
    string name;
    string namaBidang;
    string partai;

    list<dpr> llist;

    cin >> n;

    for (i = 0; i < n; i++) {
        dpr temp;

        cin >> id >> name >> namaBidang >> partai;

        temp.set_Id(id);
        temp.set_Name(name);
        temp.set_namaBidang(namaBidang);
        temp.set_Partai(partai);

        llist.push_back(temp);
    }

    i = 0;
    cout << setw(5) << "No." << setw(10) << "ID" << setw(20) << "Nama" << setw(20) << "Nama Bidang" << setw(20) << "Partai" << endl;
    for (list<dpr>::iterator it = llist.begin(); it != llist.end(); it++) {
        cout << setw(5) << (i + 1) << setw(10) << it->get_Id() << setw(20) << it->get_Name() << setw(20) << it->get_namaBidang() << setw(20) << it->get_Partai() << '\n';
        i++;
    }

    char operasi;
    cout << "pilih operasi yang diinginkan [t/u/h/k] : \n";
    //t untuk tambah
    //u untuk ubah
    //h untuk hapus
    //k untuk keluar

    cin >> operasi;

    while (operasi != 'k' && operasi != 'K') {
        if (operasi == 't' || operasi == 'T') {
            cin >> id >> name >> namaBidang >> partai;

            dpr temp(id, name, namaBidang, partai);
            llist.push_back(temp);

            cout << "anggota berhasil ditambahkan\n"
                 << endl;
        } else if (operasi == 'u' || operasi == 'U') {
            cout << "Masukkan ID anggota yang ingin diubah: \n";

            cin >> id;

            bool ditemukan = false;
            for (auto &anggota : llist) {
                if (anggota.get_Id() == id) {
                    string name, namaBidang, partai;

                    cout << "Masukkan data baru untuk anggota dengan ID " << id << ":" << endl;
                    cin>> name >> namaBidang >> partai;

                    anggota.set_Name(name);
                    anggota.set_namaBidang(namaBidang);
                    anggota.set_Partai(partai);

                    cout << "Anggota dengan ID " << id << " berhasil diubah.\n"
                         << endl;
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan) {
                cout << "Anggota dengan ID " << id << " tidak ditemukan." << endl;
            }
        } else if (operasi == 'h' || operasi == 'H') {
            cout << "Masukkan ID anggota yang ingin dihapus: \n";

            cin >> id;

            bool ditemukan = false;
            for (auto it = llist.begin(); it != llist.end(); ++it) {
                if (it->get_Id() == id) {
                    llist.erase(it);
                    cout << "Anggota dengan ID " << id << " berhasil dihapus.\n"
                         << endl;
                    ditemukan = true;
                    break;
                }
            }

            if (!ditemukan) {
                cout << "Anggota dengan ID " << id << " tidak ditemukan.\n"
                     << endl;
            }
        } else {
            cout << "operasi tidak valid.\n"
                 << endl;
        }

        cout << "pilih operasi yang diinginkan [t/u/h/k] : \n";
        cin >> operasi;
    }

    cout << "program selesai.\n"
         << endl;

    i = 0;
    cout << setw(5) << "No." << setw(10) << "ID" << setw(20) << "Nama" << setw(20) << "Nama Bidang" << setw(20) << "Partai" << endl;
    for (list<dpr>::iterator it = llist.begin(); it != llist.end(); it++) {
        cout << setw(5) << (i + 1) << setw(10) << it->get_Id() << setw(20) << it->get_Name() << setw(20) << it->get_namaBidang() << setw(20) << it->get_Partai() << '\n';
        i++;
    }

    return 0;
}