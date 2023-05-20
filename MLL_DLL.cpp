#include "MLL_DLL.h"
//membuat list pembeli(Parent)
void createPembeli(mll_pembeli &List_pembeli){
    List_pembeli.first_Pembeli = NULL;
    List_pembeli.last_Pembeli = NULL;
}
//membuat list cafe(Child)
void createCafe(mll_cafe &List_cafe){
    List_cafe.first_Cafe = NULL;
    List_cafe.last_Cafe = NULL;
}

//membuat element terbaru Pembeli(Parent)
adrPembeli newElmPembeli(Pembeli x){
    adrPembeli P;
    P = new elm_Pembeli;
    P ->info_Pembeli = x;
    P ->nextPembeli = NULL;
    P ->prevPembeli = NULL;
    P ->first_Pointer.first = NULL;
    return P;
}
//menambahkan data Pembeli(Parent)
void insertPembeli(mll_pembeli &List_pembeli ,adrPembeli P){
    //insert last double linked list
    if (List_pembeli.first_Pembeli == NULL && List_pembeli.last_Pembeli == NULL){
        List_pembeli.first_Pembeli = P;
        List_pembeli.last_Pembeli = P;
    } else{
        List_pembeli.last_Pembeli->nextPembeli = P;
        P->prevPembeli = List_pembeli.last_Pembeli;
        List_pembeli.last_Pembeli = P;
    }
}



//membuat element terbaru Cafe(child)
adrCafe newElmCafe(string namaCafe, int kouta){
    adrCafe C = new elm_Cafe;
    C ->info_cafe.namaCafe = namaCafe;
    C ->info_cafe.kouta = kouta;
    C ->nextCafe = NULL;
    C ->prevCafe = NULL;
    return C;
}


//menambahkan data Cafe(Child)
void insertCafe(mll_cafe &List_cafe, adrCafe C){
    //insert last double linked list
    if (List_cafe.first_Cafe == NULL && List_cafe.last_Cafe == NULL){
        List_cafe.first_Cafe = C;
        List_cafe.last_Cafe = C;
    } else {
        List_cafe.last_Cafe->nextCafe = C;
        C->prevCafe = List_cafe.last_Cafe;
        List_cafe.last_Cafe = C;
    }

}

//insert cafe to pembeli (relasikan antara child dan parent)
void add_cafeToPembeli(mll_pembeli &List_pembeli, mll_cafe &List_cafe, string Nama_pembeli, string namaCafe){
    adrPembeli P;
    adrCafe C;
    adrPointer R;
    P = findPembeli(List_pembeli,Nama_pembeli);
    C = findCafe(List_cafe,namaCafe);
    if (P != NULL && C != NULL){
        //relasi ke pointer
        R = new Pointer;
        R->nextPointer = NULL;
        R->nextCafe = C;
        if (P ->first_Pointer.first == NULL){
            P ->first_Pointer.first = R;
        }else{
            adrPointer J = P ->first_Pointer.first;
            while(J ->nextPointer != NULL){
                J = J ->nextPointer;
            }
            J ->nextPointer = R;
        }
        //setiap cafe ditambahkan, maka kouta dari cafe tersebut akan terus berkurang
        C->info_cafe.kouta--;

    }else{
        cout<<"gagal menambahkan cafe"<<endl;
    }

}
//mencari data Cafe(Child) berdasarkan nama
adrCafe findCafe(mll_cafe &List_cafe, string namaCafe){
    adrCafe C;
    C = List_cafe.first_Cafe;
    while(C != NULL){
        if(C ->info_cafe.namaCafe == namaCafe){
            return C;
        }
        C = C->nextCafe;
    }
    return NULL;
}

//delete Parent
void deletePembeli(mll_pembeli &List_pembeli, string Nama_pembeli) {
    adrPointer F;
    adrPembeli P;
    adrPointer q;
    P = findPembeli(List_pembeli,Nama_pembeli);
    if(List_pembeli.first_Pembeli == NULL && List_pembeli.last_Pembeli == NULL){
        cout<<"data masih kosong, tidak ada yang dihapus"<<endl;
    }else if(List_pembeli.first_Pembeli->nextPembeli == NULL){
        P = List_pembeli.first_Pembeli;
        List_pembeli.first_Pembeli = NULL;
        List_pembeli.last_Pembeli = NULL;
        q = P ->first_Pointer.first;
        while(q != NULL){
            F = q;
            q = q ->nextPointer;
            F = NULL;
        }
        cout<<"data telah terhapus"<<endl;
    }else{
        //jika data berada di depan, maka menggunakan delete first
        if (List_pembeli.first_Pembeli->info_Pembeli.Nama_pembeli == Nama_pembeli){
            P = List_pembeli.first_Pembeli;
            List_pembeli.first_Pembeli= List_pembeli.first_Pembeli->nextPembeli;
            P->prevPembeli = NULL;
            P->nextPembeli = NULL;
            q = P->first_Pointer.first;
            while(q != NULL){
                F = q;
                q = q->nextPointer;
                F = NULL;
            }
            cout<<"data telah terhapus"<<endl;
        //jika data berada di akhir, maka menggunakan delete last
        } else if (List_pembeli.last_Pembeli->info_Pembeli.Nama_pembeli == Nama_pembeli) {
            P = List_pembeli.last_Pembeli;
            List_pembeli.last_Pembeli = List_pembeli.last_Pembeli->prevPembeli;
            P->prevPembeli = NULL;
            List_pembeli.last_Pembeli->nextPembeli = NULL;
            q = P->first_Pointer.first;
            while(q != NULL){
                F = q;
                q = q->nextPointer;
                F = NULL;
            }
            cout<<"data telah terhapus"<<endl;
        } else {
            //jika data berada di tengah tengah, maka menggunakan delete afrer
            adrPembeli H = List_pembeli.first_Pembeli;
            while (H->info_Pembeli.Nama_pembeli != Nama_pembeli){
                    H = H->nextPembeli;
                }
                //variabel A dan B perantara untuk menghapus address H
                adrPembeli A = H->prevPembeli;
                adrPembeli B = H->nextPembeli;
                A->nextPembeli = B;
                B->prevPembeli = A;
                H->prevPembeli = NULL;
                H->nextPembeli = NULL;
                H = NULL;
                cout<<"data telah terhapus"<<endl;
            }
        }
}

//delete child of parent x
void deleteCafeofPembeli(mll_pembeli &List_pembeli,mll_cafe &List_cafe, string Nama_pembeli, string namaCafe) {
    adrPointer R;
    adrPembeli Q;
    adrCafe C;
    Q = findPembeli(List_pembeli,Nama_pembeli);
    R = Q->first_Pointer.first;
    while (R != NULL && R->nextCafe->info_cafe.namaCafe != namaCafe){
        R = R->nextPointer;
    }
    //jika data cafe berada di depan maka menggunakan delete first
    if (R == Q->first_Pointer.first){
        adrPointer K;
        K = Q->first_Pointer.first;
        K = R->nextPointer;
        Q->first_Pointer.first = K;
        R->nextCafe = NULL;
        R->nextPointer = NULL;
    //jika data cafe berada di akhir maka menggunakan delete last
    } else if (R->nextPointer == NULL){
        adrPointer K;
        K = Q->first_Pointer.first;
        while (K->nextPointer != R){
            K = K->nextPointer;
        }
        K->nextPointer = NULL;
        R->nextCafe = NULL;
    //jika data cafe berada di tengah maka menggunakan delete after
    } else {
        adrPointer K;
        K = Q->first_Pointer.first;
        while (K->nextPointer != R){
            K = K->nextPointer;
        }
        K->nextPointer = R->nextPointer;
        R->nextPointer = NULL;
        R->nextCafe = NULL;
    }


}

//mencari data pembeli(Parent) berdasarkan nama
adrPembeli findPembeli(mll_pembeli &List_pembeli,string Nama_pembeli){
    adrPembeli P;
    P = List_pembeli.first_Pembeli;
    while(P != NULL){
        if(P ->info_Pembeli.Nama_pembeli == Nama_pembeli){
            return P;
        }
        P = P ->nextPembeli;
    }
    return NULL;

}

//mencari apakah data pembeli ditemukan atau tidak
bool findPembeliandShow(mll_pembeli &List_pembeli, string Nama_pembeli){
    adrPembeli P;
    if (List_pembeli.first_Pembeli == NULL && List_pembeli.last_Pembeli == NULL) {
        return false;
    } else {
        P = List_pembeli.first_Pembeli;
        while (P != NULL) {
            if (P->info_Pembeli.Nama_pembeli == Nama_pembeli ) {
                return true;
            }
            P = P ->nextPembeli;
        }
        return false;
    }

}

//mencari apakah data cafe ditemukan atau tidak
bool findCafeandshow(mll_cafe &List_cafe, string namaCafe){
    adrCafe C;
    if (List_cafe.first_Cafe == NULL && List_cafe.last_Cafe == NULL) {
        return false;
    } else {
        C = List_cafe.first_Cafe;
        while (C != NULL) {
            if (C->info_cafe.namaCafe == namaCafe) {
                return true;
            }
            C = C ->nextCafe;
        }
        return false;
    }

}

//menampilkan semua data Pembeli(Parent) dan Cafe(Child)
void Show(mll_pembeli &List_pembeli){
    adrPembeli P;
    if (List_pembeli.first_Pembeli != NULL && List_pembeli.last_Pembeli != NULL){
        int i = 1;
        P = List_pembeli.first_Pembeli;
        while (P != NULL){
            cout << "======= DATA PEMBELI SAAT INI ======="<<endl;
            cout << "[" << i << "]" << endl;
            cout << "Nama anda               : " <<P->info_Pembeli.Nama_pembeli << endl;
            cout << "Budget                  :Rp. "<< P->info_Pembeli.budget << endl;
            cout << "Mau makan apa hari ini? :"<<P->info_Pembeli.Makanan << endl;
            cout << "Mau Minum apa hari ini? :" << P->info_Pembeli.Minuman << endl;
            cout << "status                  :" << P->info_Pembeli.tempat << endl;
            adrPointer J = P ->first_Pointer.first;
            if(P ->first_Pointer.first != NULL){
                int k = 1;
                while(J != NULL){
                    adrCafe X = J ->nextCafe;
                    cout << "======= DATA CAFE SAAT INI ======= "<<endl;
                    cout << "[" << k << "]" << endl;
                    cout<<"Nama kafe : "<<X->info_cafe.namaCafe<<endl;
                    cout<<"kouta kafe :"<<X->info_cafe.kouta<<endl;
                    J = J ->nextPointer;
                    k++;
                }
            }
            P = P->nextPembeli;
            i++;
        }
        cout << endl;
    } else {
        cout << "======= DATA PEMBELI SAAT INI ======="<<endl;
        cout << "Nama anda                : kosong~" << endl;
        cout << "Budget                   :Rp. kosong~ "<< endl;
        cout << "Mau makan apa hari ini?  : kosong~"<< endl;
        cout << "Mau Minum apa hari ini?  : kosong~" << endl;
        cout << "status                   : kosong~" << endl;
        cout << "List Masih Kosong, Mohon masukkan data" << endl;
    }

}

//mencari max budget dari pembeli(Parent)
void MaxBudgetPembeli(mll_pembeli &List_pembeli){
    adrPembeli Max,P;
    P = List_pembeli.first_Pembeli;
    Max = List_pembeli.first_Pembeli->nextPembeli;
	while(P != NULL)
	{
		if(Max->info_Pembeli.budget < P->info_Pembeli.budget){
			Max = P;
		}
		P = P->nextPembeli;
	}
	cout << "==========Data Pembeli dengan budget terbesar=========="<<endl;
	cout << "\nBudget terbanyak adalah : Rp. "<< Max->info_Pembeli.budget;
	cout << endl;
	cout << ">Dengan Atas Nama         : " << Max->info_Pembeli.Nama_pembeli;
	cout << endl;

}

//mencari minimum budget dari pembeli(Parent)
void MinBudgetPembeli(mll_pembeli &List_pembeli){
    adrPembeli Min,P;
    P = List_pembeli.first_Pembeli;
    Min = List_pembeli.first_Pembeli->nextPembeli;
	while(P != NULL)
	{
		if(Min->info_Pembeli.budget > P->info_Pembeli.budget){
            Min = P;
		}
		P = P->nextPembeli;
	}
	cout << "==========Data Pembeli dengan budget terkecil=========="<<endl;
	cout << "\nBudget terkecil adalah : Rp. "<< Min->info_Pembeli.budget;
	cout << endl;
	cout << ">Dengan Atas Nama        : " << Min->info_Pembeli.Nama_pembeli;
	cout << endl;
}

//mencari max kouta dari cafe yang telah di inputkan oleh pembeli
void MaxKoutaCafe(mll_cafe &List_cafe){
    adrCafe Max,C;
    C = List_cafe.first_Cafe;
    Max = List_cafe.first_Cafe->nextCafe;
    while(C != NULL)
	{
		if(Max->info_cafe.kouta < C->info_cafe.kouta){
            Max = C;
		}
		C = C->nextCafe;
	}
	cout << "==========Data Cafe dengan kouta Cafe terbesar=========="<<endl;
	cout << "\nKouta Cafe terbesar adalah : "<< Max->info_cafe.kouta;
	cout << endl;
	cout << ">Dengan Nama Cafe            :" << Max->info_cafe.namaCafe;
	cout << endl;
}

//menu utama
int SelectMenu(){
    cout << "Selamat datang^^ berikut adalah pilihan menu"<<endl;
    cout << " ============ MENU =========== " << endl;
    cout << ">1. Memasukkan data Pembeli " << endl;
    cout << ">2. Menghapus data Pembeli " << endl;
    cout << ">3. Menambahkan data cafe ke pembeli " << endl;
    cout << ">4. Mencari data pembeli" << endl;
    cout << ">5. Menghapus data cafe dari pembeli" << endl;
    cout << ">6. Mencari list cafe dari data pembeli" << endl;
    cout << ">7. Menampilkan semua data" << endl;
    cout << ">8. Mencari Budget terbesar" << endl;
    cout << ">9. Mencari Budget terkecil" << endl;
    cout << ">10. Mencari kouta cafe terbesar" << endl;
    cout << ">0. Exit" << endl;
    cout << "Silahkan Pilih Menu : ";
    int input = 0;
    cin >> input;
    return input;
}

//daftar nama cafe yang ingin di inputkan oleh user
void DaftarNama_Cafe(){
    cout << "=====List Data Cafe Dekat kos-kosan====="<<endl;
    cout << "=====Pilih bedasarkan yang anda inginkan====="<<endl;
    cout << ">Daftar nama Cafe terdekat kos-kosan: "<<endl;
    cout << ">1.cafe_mentari(kouta max 30)" <<endl;
    cout << ">2.cafe_cempaka(kouta max 25)" <<endl;
    cout << ">3.cafe_kuta(kouta max 30)" <<endl;
    cout << ">4.cafe_elit(kouta max 25)" <<endl;
    cout << ">5.cafe_juara(kouta max 30)" <<endl;
    cout << ">6.cafe_upnormal(kouta 25)" <<endl;
    cout <<endl;
}
