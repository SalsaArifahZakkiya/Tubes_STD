#ifndef MLL_DLL_H_INCLUDED
#define MLL_DLL_H_INCLUDED
#include <iostream>
using namespace std;
typedef struct Pointer *adrPointer;
typedef struct elm_Pembeli *adrPembeli;
typedef struct elm_Cafe *adrCafe;


//parent
struct Pembeli{
    string Nama_pembeli;
    int budget;
    string Makanan;
    string Minuman;
    string tempat;
};
struct elm_Pembeli{
   Pembeli info_Pembeli;
   adrPembeli nextPembeli;
   adrPembeli prevPembeli;
   list_pointer first_Pointer;
};
struct Cafe{
    string namaCafe;
    int kouta;
};
struct elm_Cafe{
    Cafe info_cafe;
    adrCafe prevCafe;
    adrCafe nextCafe;
};
//pointer yang menghubungkan antara parent dan child
struct Pointer{
    adrCafe nextCafe;
    adrPointer nextPointer;
};

struct list_pointer{
    adrPointer first;
};


//child
struct mll_cafe{
    adrCafe first_Cafe;
    adrCafe last_Cafe;
};

struct mll_pembeli{
    adrPembeli first_Pembeli;
    adrPembeli last_Pembeli;
};

void createPembeli(mll_pembeli &List_pembeli);
void createCafe(mll_cafe &List_cafe);
adrPembeli newElmPembeli(Pembeli x);
adrCafe newElmCafe(string namaCafe, int kouta);
void insertPembeli(mll_pembeli &List_pembeli ,adrPembeli P);
void insertCafe(mll_cafe &List_cafe, adrCafe C);
void add_cafeToPembeli(mll_pembeli &List_pembeli, mll_cafe &List_cafe, string Nama_pembeli, string cafe);
void deletePembeli(mll_pembeli &List_pembeli,string Nama_pembeli);
void deleteCafeofPembeli(mll_pembeli &List_pembeli,mll_cafe &List_cafe, string Nama_pembeli, string namaCafe);
void Show(mll_pembeli &List_pembeli);
int SelectMenu();
void DaftarNama_Cafe();
adrPembeli findPembeli(mll_pembeli &List_pembeli,string Nama_pembeli);
adrCafe findCafe(mll_cafe &List_cafe, string cafe);
bool findPembeliandShow(mll_pembeli &List_pembeli, string Nama_pembeli);
bool findCafeandshow(mll_cafe &List_cafe, string namaCafe);
void MaxBudgetPembeli(mll_pembeli &List_pembeli);
void MinBudgetPembeli(mll_pembeli &List_pembeli);
void MaxKoutaCafe(mll_cafe &List_cafe);

#endif // MLL_DLL_H_INCLUDED
