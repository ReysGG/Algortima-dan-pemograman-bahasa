//Program login David boy

#include <iostream>
using namespace std;

string akun, akunbaru;
string password, passwordbaru;
string y,yes,benar;
char menu;
int salah = 0;

int main (){
    while (true){
        cout << "Masukan akun anda = ";
        cin >> akun;
        
        cout << "Masukan password anda = ";
        cin >> password;
        
        if ((akun == akunbaru && password == passwordbaru)||(akun == "aw" && password == "aw")){
           cout << "welcome " << akun << endl;
           
           while (true){
            cout << "Silakah Pilih Menu Yang Tersedia! \n";
            cout << "[A] Membuat buku Perpustakaan [A] \n";
            cout << "[B] Belum tersedia [B] \n";
            cout << "[C] Belum tersedia [C] \n";
            cout << "[D] Belum tersedia [D] \n";
            cout << "[E] Belum tersedia [E] \n";
            cout << "[X]       EXIT     [x] \n";
            cout << "Masukan menu yang mau dipilih = ";
            cin >> menu;
            
            switch (menu){
                case 'A': {
                    struct buku {
                                    int tahun,harga;
                                     string judul,penulis,penerbit;
    };
    
                                       string jawaban;
                                       int jumlahbuku;

                    cout << "Berapa banyak buku yang mau di buat? = ";
        cin >> jumlahbuku;
        cin.ignore();
        
        buku* bukubaru = new buku [jumlahbuku];
        cout << "Silakan di isi dengan teliti ya, Terima kasih! \n";
        cout << endl;
        for (int a= 0; a < jumlahbuku; a++){
            cout << "Masukan data buku ke - " << (a+1) << endl;
           
            cout << "Masukan judul buku = ";
            
            getline(cin, bukubaru[a].judul);
            
            cout << "Masukan Nama Penulis Buku = ";
            
            getline (cin, bukubaru[a].penulis);
            
            cout << "Masukan Nama Penerbit = ";
            
            getline (cin, bukubaru[a].penerbit);
            
            cout << "Masukan Harga Buku = Rp.";
            cin >> bukubaru[a].harga;
            cin.ignore();
            
            cout << "Masukan Tahun Buku = ";
            cin >> bukubaru[a].tahun;
            cin.ignore();
            
            cout << endl;
            
            }
            
            for (int a = 0; a < jumlahbuku; a++){
                cout << "Informasi buku ke -" << (a+1) << endl;
                cout << "Judul buku = " << bukubaru[a].judul << endl;
                cout << "Penulis buku = " << bukubaru[a].penulis << endl;
                cout << "Penerbit buku = " << bukubaru[a].penerbit << endl;
                cout << "Harga buku = Rp." << bukubaru[a].harga << endl;
                cout << "Tanggal Tahun buku = " << bukubaru[a].tahun << endl;
                
                }
                
                delete [] bukubaru;
                    break;
                    }
                case 'B' : {
                    cout << "Menu Belum Tersedia !"; 
                    break;}
                case 'C' : {
                    cout << "Menu Belum Tersedia !"; 
                    break;}
                case 'D' : {
                    cout << "Menu Belum Tersedia !"; 
                    break;}
                case 'E' : {
                    cout << "Menu Belum Tersedia !";
                    break;} 
                  default : {
                    cout << "input tidak valid" << endl;
                    break;
                    }
                }
          
        }
        
    

}
else {
            cout << "Password / akun salah, coba lagi? [Y/N]";
            cin >> y;
            
            if (y == "Y" || y == "y"){
                cout << "Coba lagi ";
                cout << endl;
                }
                
                else {
                    cout << "Ingin mendaftar akun? [Y/N]";
                    cin >> yes;
                    
                    while (true){
                    if (yes == "y" || yes == "Y"){
                        cout << "Masukan nama akun anda = ";
                        cin >> akunbaru;
                        cout << "Masukan password anda = ";
                        cin >> passwordbaru;
                        cout << "Apakah sudah bener? = " << endl;
                        cout << "Akun nama = " << akunbaru << " Password = " << passwordbaru << endl;
                        cout << "Apakah sudah benar? [Y/N] = ";
                        cin >> benar;
                        
                        if (benar == "Y" ||benar == "y"){
                            cout << "akun sudah selesai di daftar";
                            cout << endl;
                            break;}
                            
                            else {
                                cout << "Silakan di cek ulang" << endl;
                                }
                        
                        }
                        else {
                            return 0; }
                    }
                        
                    }
                
            }
}
}
