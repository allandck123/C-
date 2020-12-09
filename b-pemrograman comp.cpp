//ALLAND CHANDRA KESUMA (20170801011)
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
using namespace std;
struct datdat
{	char nama[50];
	int nim;
	int umur;
	float ipk;
}; datdat mhs;
struct mahasiswa
{	char nama [30];
}; mahasiswa ueu; 
char Input1[15],Input2[15],Input3[15];
int i,j,a,b,x;
void id();
int garis();
int menu();
int input();
int add();
int read();
int merge();
int LuasPersegi();
void bintang();
void fstr();
void seleksi();
void iktp();
void luaspp();
void huge();
void lup();
void lcir();
void grade();
void fuct();
void sstru();
void cang();

int main(){
	int choice;
	prompt:
	system("cls");
	id();
	cout<<"----PRAKTIKUM BAHASA PEMROGRAMAN----"<<endl;
	cout<<"1. Input Data KTP (IO)"<<endl;
	cout<<"2. Luas Persegi Panjang (Operasi)"<<endl;
	cout<<"3. Luas Lingkaran (Operasi)"<<endl;
	cout<<"4. Nilai Terbesar (Selection)"<<endl;
	cout<<"5. Kelulusan (Selection)"<<endl;
	cout<<"6. Kelas Bela Diri(Selection)"<<endl;
	cout<<"7. Cetak Angka (Loop)"<<endl;
	cout<<"8. Bilangan Genap(Loop)"<<endl;
	cout<<"9. Bintang (Loop)"<<endl;
	cout<<"10. Luas Persegi Panjang (Function)"<<endl;
	cout<<"11. Input Data Mahasiswa (Struct)"<<endl;
	cout<<"12. Filestream"<<endl;
	cout<<"13. Keluar"<<endl;
	cout<<"Pilihan anda? [1-13] : ";
	cin>>choice; 
	cin.ignore(); 
	system("cls");
    switch (choice)
    {	case 1: iktp(); goto prompt;
    	case 2: luaspp(); goto prompt;
    	case 3: lcir(); goto prompt;
    	case 4: huge(); goto prompt;
    	case 5: grade(); goto prompt;
    	case 6: seleksi(); goto prompt;
    	case 7: cang(); goto prompt;
    	case 8: lup(); goto prompt;
    	case 9: bintang(); goto prompt;
    	case 10: fuct(); goto prompt;
    	case 11: sstru(); goto prompt;
    	case 12: fstr(); goto prompt;
		case 13: cout<<"\n\nTerima kasih telah menggunakan program ini !"<<endl; break;
    default : cout<<"\n\nMasukkan Pilihan yang Benar !!!\n\n"<<endl; 
 	system("PAUSE"); goto prompt;
 	}
}
void id()
{
	cout<<"=================================================="<<endl;    
	cout<<"|         Nama   : Alland Chandra Kesuma         |"<<endl;
	cout<<"|         NIM    : 20170801011                   |"<<endl;
	cout<<"=================================================="<<endl;	
}
void cang()
{
	cout<<"Masukan jumlah angka yang ingin dicetak : ";
		cin>>a;	
	for(int i=1; i<=a;i++){
	cout<<i<<" ";
	}
	getch();
}
void tam()
{
	cout<<endl<<endl;
	cout<<"Output"<<endl;
	cout<<"NIM  = "<<mhs.nim<<endl;
	cout<<"Nama = "<<mhs.nama<<endl;
	cout<<"Umur = "<<mhs.umur<<endl;
	cout<<"IPK  = "<<mhs.ipk;
}

void innn()
{
	cout<<"Input"<<endl;
	cout<<"Masukan NIM   : "; 
		cin>>mhs.nim;
	cout<<"Masukan Nama  : "; 
		scanf(" %[^\n]s",mhs.nama);
	cout<<"Masukan Umur  : "; 
		cin>>mhs.umur;
	cout<<"Masykan Ipk   : "; 
		cin>>mhs.ipk;
}

void sstru(){
	cout<<"Selamat Datang"<<endl<<endl;
	innn();
	tam();
	getch();
}
int LuasPersegi(int p, int l){
	int luas;
	luas = p * l;
	return luas;
}
void fuct()
{
	int a,b;
	cout << "Masukan Panjang : ";
	cin >> a;
	cout << "Masukan Lebar   : ";
	cin >> b;
	cout << "Luas Persegi    : "<<LuasPersegi(a,b);
	getch();
}
void grade()
{
	int nilai;
	cout<<"Input Nilai Matakuliah\t:";
	cin>>nilai;
	
	if(nilai>=60){
		cout<<"Anda LULUS"<<endl;
	}
	else {
		cout<<"Maaf, Anda tidak lulus"<<endl;	
}
	getch();
}
void lcir()
{
	int jari;
	float luas,keliling;
	
	cout<<"Input jari-jari lingkaran"<<endl;
	cin>>jari;
	
	luas=3.14*jari*jari;
	keliling=2*3.14*jari;
	
	cout<<"\nLuas dan Keliling Lingkaran";
	cout<<"\nJari-Jari : "<<jari;
	cout<<"\nLuas	  : "<<luas;
	cout<<"\nKeliling  : "<<keliling;	
	
	getch();
}
void lup()
{
	cout<<"Masukkan range bilangan genap : ";
	cin>>b;
	while (i<=b)
	{
		if(i%2==0)
		cout<<i<<" "; 
		i++;
	}
	getch();
}
void huge()
{
		int nilai1,nilai2,max;
	cout<<"\t\t\tMencari Nilai Terbesar"<<endl;
	cout<<"Input Nilai 1\t:";
	cin>>nilai1;
	
	cout<<"Input Nilai 2\t:";
	cin>>nilai2;
	
	if(nilai1>nilai2){
		max=nilai1;
}
	else {
		max=nilai2;
}
	cout<<"Nilai Terbesar adalah\t:"<<max<<endl;
	getch();
}
void luaspp()
{
		int panjang, lebar;
	float luas;
	
	cout<<"Input Panjang persegi panjang\t:";
	cin>>panjang;
	
	cout<<"Input Lebar persegi panjang\t:";
	cin>>lebar;
	
	luas=panjang*lebar;
	
	cout<<"\nLuas dan Keliling Persegi Panjang";
	cout<<"\nPanjang   : "<<panjang;
	cout<<"\nLebar	  : "<<lebar;
	cout<<"\nLuas	  : "<<luas;
		
	getch();
}
void iktp()
{
	char nik[20];
	char nama[30];	
	char ttl[30];
	char gender[10];
	char alamat[50];
	char RT_RW[10];
	char Kel[20];
	char Kecamatan[20];
	char Agama[10];
	char married[15];
	char job[20];
	char WN[5];
	char exp[15];
	
	cout<<"\t\t\tSilahkan Input Data Kependudukan Anda\n";

	cout<<"NIK :";
	cin.getline(nik,20);
	cout<<"Nama :";
	cin.getline(nama,30);
	cout<<"Tempat/Tgl Lahir :";
	cin.getline(ttl,30);
	cout<<"Jenis Kelamin :";
	cin.getline(gender,10);
	cout<<"Alamat :";
	cin.getline(alamat,50);
	cout<<" RT/RW :";
	cin.getline(RT_RW,10);
	cout<<" Kel/Desa :";
	cin.getline(Kel,20);
	cout<<" Kecamatan :";
	cin.getline(Kecamatan,20);
	cout<<"Agama :";
	cin.getline(Agama,10);
	cout<<"Status Perkawinan :";
	cin.getline(married,15);
	cout<<"Pekerjaan :";
	cin.getline(job,20);
	cout<<"Kewarganegaraan :";
	cin.getline(WN,5);
	cout<<"Berlaku Hingga :";
	cin.getline(exp,15);
	cout<<"\t\t\tTerima kasih Atas Partisipasi Anda";
	
	getch();
}
void seleksi()
{
	int usia, berat;
	char YN;
	start:
	system("cls");
	cout<<("\t\t\tPengelompokkan kelas bela diri berdasarkan usia dan berat badan")<<endl;
	cout<<("Masukkan Usia :\t");
	cin>>usia;
	cout<<("Masukkan Berat Badan :\t");
	cin>>berat;
	
	if(usia>=35)
		if(berat>75)
			cout<<("Anda termasuk kelas dewasa berat");
		else
			cout<<("Anda termasuk kelas dewasa ringan");
	else
		if(berat>65)
			cout<<("Anda termasuk kelas muda berat");
		else
			cout<<("Anda termasuk kelas muda ringan");
	prompt:
	cout<<"\nApakah anda ingin melanjutkan program ? [Y/T] : ";
	cin>>YN;
	cout<<endl;
	if(YN=='Y' || YN=='y')
		{goto start;}
	else{
		if(YN =='T' || YN =='t')
			{goto end;}
	else
		{cout<<("Masukkan jawaban yang benar!!\n");goto prompt;}
	}
	end:
	cout<<("Terima Kasih telah menggunakan program ini");	
	getch();
}
void bintang()
{
	system("cls");	//membersihkan layar ketika melakukan pengulangan program
	cout<<("=======Program Menampilkan Bentuk dari Bilangan=======")<<endl;	//judul
	cout<<("Masukan Angka\t:"); cin>>a; //variabel b untuk input jumlah baris dari bintang
	for (i=a; i>=1; i--){		//pengulangan utk baris dan spasi pada sisi atas
		for (j=0; j<i; j++){	//pengulangan utk tampilan bintang di kiri atas
			cout<<(" *");}
		for (x=1; x<=a-i; x++){		//display ruang kosong
			cout<<(" ");}
		for (x=1; x<=a-i; x++){		//display ruang kosong
			cout<<(" ");}
		for (x=1; x<=a-i; x++){		//display ruang kosong
			cout<<(" ");}
		for (x=1; x<=a-i; x++){		//displau ruang kosong
			cout<<(" ");}
		for (j=0; j<i; j++){	//pengulangan utk menampilkan bintang di kanan atas
			cout<<(" *");}
			cout<<("\n");}		//new line


	for (i=1; i<=a; i++){		//pengulangan utk baris dan spasi pada sisi bawah
		for (j=0; j<i; j++){	//pengulangan utk menapilkan bintang di kiri bawah
			cout<<(" *");}
		for (x=1; x<=a-i; x++){		//display ruang kosong
			cout<<(" ");}
		for (x=1; x<=a-i; x++){		//display ruang kosong
			cout<<(" ");}
		for (x=1; x<=a-i; x++){		//display ruang kosong
			cout<<(" ");}
		for (x=1; x<=a-i; x++){		//display ruang kosong
			cout<<(" ");}
		for (j=0; j<i; j++){	//pengulangan untuk menampilkan bintang di kanan bawah
			cout<<(" *");}
			cout<<("\n");}		//new line
	getch();
}
void fstr()
{char kode;
	data_aku:
	system("cls");
	id();
	menu(); 
	cin>>kode; 
	cin.ignore(); 
	system("cls");
    switch (kode)
    {	case '1': input(); goto data_aku;
    	case '2': add(); goto data_aku;
		case '3': read(); goto data_aku;
		case '4': cout<<"\n\n\tBYE!!!"<<endl; break;
    default : cout<<"\n\n\tKODE SALAH!!!\n\n"<<endl; 
 	system("PAUSE"); goto data_aku;
    }
    getch();
}
int garis()
{
	for(int i=0; i<70; i++)
	{cout<<"-";}
	cout<<endl;
}
int menu()
{
	cout<<"\t    ===DATA MAHASISWA==="<<endl;
	cout<<"------------------------------------------"<<endl;
	cout<<"Silahkan pilih kode yang Anda inginkan:"<<endl;
	cout<<"1. Input Data"<<endl;
	cout<<"2. Tambah Data"<<endl;
	cout<<"3. Baca Data"<<endl;
	cout<<"4. Kembali ke menu utama"<<endl;
	cout<<"Masukkkan kode yang Anda pilih [1/2/3/4]: ";
}
int input()
{
	cout<<"Masukkan nama file (.txt): ";
		cin.getline(Input1,15);
	ofstream simpan (Input1);
	system("cls");
	cout<<"\nNama\t    : ";
		cin.getline(ueu.nama,30);
	simpan<<ueu.nama<<endl;
	cout<<"\n\n\n"; system("PAUSE");
}
int add()
{
	cout<<"Masukkan nama file (.txt): ";
		cin.getline(Input1,15);
	ofstream simpan (Input1, ios::app);
	system("cls");
	cout<<"\nNama\t    : ";
		cin.getline(ueu.nama,30);
	simpan<<ueu.nama<<endl;
	cout<<"\n\n\n"; system("PAUSE");
}
int read()
{
	cout<<"Masukkan nama file (.txt): ";
		cin>>Input1;
	ifstream buka (Input1);
	if(buka.good())
	{while(!buka.eof())
	{	system("cls");
	while(buka)
	{ 	buka.getline(ueu.nama,30); 
	cout<<ueu.nama<<endl;}
	}
		cout<<"\n\n\n"; system("PAUSE");}
		else cout<<"file tidak ada"<<endl;
		getch();
}

