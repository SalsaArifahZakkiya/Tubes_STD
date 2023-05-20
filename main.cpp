#include <iostream>
#include "MLL_DLL.h"
using namespace std;

int main()
{
    mll_pembeli List_pembeli;
    mll_cafe List_cafe;
    adrPembeli P;
    adrCafe C;
    Pembeli x;
    createPembeli(List_pembeli);
    createCafe(List_cafe);
    string Nama_pembeli;
    string namaCafe;
    int kouta;
    string jawab;
    int opsi = 0;
    opsi = SelectMenu();
    cout << endl;
    while ( opsi != 0){
        if (opsi == 1){
             cout << "========== SELAMAT DATANG<3 =========="<< endl;
             cout << "apakah anda memesan untuk sendiri?(iya/tidak):";
             cin >> jawab;
             int i = 1;
             if ( jawab == "iya"){
                cout << "===== Masukkan Data "<< "[" <<i<< "] "<< "Anda =====" << endl;
                cout << "Masukkan nama anda : ";
                cin >> x.Nama_pembeli;
                cout << "Masukkan budget anda :Rp. ";
                cin >> x.budget;
                cout << "Makan apa hari ini? : ";
                cin >> x.Makanan;
                cout << "Minum apa hari ini? : ";
                cin >> x.Minuman;
                cout << "dine_in/take_away? : ";
                cin >> x.tempat;
                P = newElmPembeli(x);
                insertPembeli(List_pembeli, P);
                i++;
                cout << endl;
                cout << "Data Berhasil ditambahkan! "<< endl;
             } else {
                 int n,j = 0;
                 int i = 1;
                 cout << "berapa data yang ingin anda masukkan?: ";
                 cin >> n;
                 while (j<n) {
                        cout << "===== Masukkan Data "<< "[" <<i<< "] "<< "Anda =====" << endl;
                        cout << "Masukkan nama anda : ";
                        cin >> x.Nama_pembeli;
                        cout << "Masukkan budget anda :Rp. ";
                        cin >> x.budget;
                        cout << "Makan apa hari ini? : ";
                        cin >> x.Makanan;
                        cout << "Minum apa hari ini? : ";
                        cin >> x.Minuman;
                        cout << "dine_in/take_away? : ";
                        cin >> x.tempat;
                        P = newElmPembeli(x);
                        insertPembeli(List_pembeli, P);
                        j++;
                        i++;
                        cout<<endl;
                        cout << "Data Berhasil ditambahkan! "<<endl;
                    }
             }
        }else if (opsi == 2) {
           //menghapus data pembeli
           cout << "========== Menghapus data Pembeli ==========" <<endl;
           cout << "masukkan nama anda terlebih dahulu : ";
           cin >> Nama_pembeli;
           deletePembeli(List_pembeli,Nama_pembeli);
           cout << endl;
        }else if (opsi == 3){
            //insert child of parent X
            cout << "=========== Menambahkan Cafe ==========="<< endl;
            cout << "masukkan nama anda terlebih dahulu : ";
            cin >> Nama_pembeli;
            adrPembeli P = findPembeli(List_pembeli,Nama_pembeli);
            cout << endl;
            if (P->info_Pembeli.tempat != "take_away"){
                cout << "Anda telah memilih dine_in"<< endl;
                DaftarNama_Cafe();
                cout << endl;
                cout << ">Masukkan nama cafe : ";
                cin >> namaCafe;
                cout << ">Masukkan kouta cafe : ";
                cin >> kouta;
                C = newElmCafe(namaCafe,kouta);
                insertCafe(List_cafe,C);
                add_cafeToPembeli(List_pembeli,List_cafe,Nama_pembeli,namaCafe);
                cout << endl;
            }else {
                cout << "============= Anda memilih take_away ====================" << endl;
                cout << "mohon di isi ulang dengan menghapus (2) dan mengisi (1)" << endl;
            }
            cout << "Data Berhasil di upgrade! "<< endl;
        } else if (opsi == 4){
            //find nama pembeli
            cout << "========== Temukan Data Pembeli yang ingin anda cari =========="<< endl;
            string Nama_pembeli;
            cout << "masukkan nama anda yang anda cari :";
            cin >> Nama_pembeli;
            cout << endl;
            bool found;
            found = findPembeliandShow(List_pembeli, Nama_pembeli);
            if (found == 1) {
                cout << "data ketemu" << endl;
            } else {
                cout << "data tidak ketemu" <<endl;
            }
            cout << endl;

        } else if (opsi == 5){
            //deletecafeofnamapembeli
            cout << "========= Menghapus data Pembeli============="<< endl;
            cout << "masukkan nama anda terlebih dahulu : ";
            cin >> Nama_pembeli;
            cout << "Masukkan nama cafe yang ingin dihapus : ";
            cin >> namaCafe;
            deleteCafeofPembeli(List_pembeli,List_cafe,Nama_pembeli,namaCafe);
            cout << "data sudah dihapus"<< endl;
        } else if (opsi == 6){
            //find and show child
            cout << "============= Temukan cafe yang ingin anda cari ============="<< endl;
            cout << "masukkan nama cafe yang anda cari :";
            cin >> namaCafe;
            bool ketemu;
            cout<<"Hasil\t: " << endl;
            ketemu = findCafeandshow(List_cafe, namaCafe);
            if (ketemu == 1) {
                cout << "seseorang telah memilh cafe tersebut" << endl;
            } else {
                cout << "tidak ada yang memilih cafe tersebut" << endl;
            }
        } else if (opsi == 7){
            //show all parent and child
            Show(List_pembeli);
            cout << endl;
        } else if (opsi == 8){
            //mencari max budget pembeli
             MaxBudgetPembeli(List_pembeli);
             cout << endl;
        } else if (opsi == 9){
            //mencari min budget pembeli
            MinBudgetPembeli(List_pembeli);
            cout << endl;
        } else if (opsi == 10){
            //mencari max kouta cafe
            MaxKoutaCafe(List_cafe);
            cout << endl;
        }
        opsi = SelectMenu();
        cout<<endl;

    }
    cout << "====== Anda sudah keluar dari program ====== "<<endl;
    cout << "========== Sampai Jumpa ^^ ==========="<<endl;
    return 0;
}
