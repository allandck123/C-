//ALLAND CHANDRA KESUMA (20170801011)
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<limits>
using namespace std;
struct Data{
	string nama,alamat,status,kelompok,ins;
	string gaji, tunjang, bonus, thr, lembur, awal;
	long long int ikelompok, igaji, itunjang, ibonus, ithr, ilembur, iawal, ilama;
	long long int jkk,jk,bj,jht,ip,bruto,netto,ptkp,pkp,tarif,pkpb,pph,pphm;
	long long int natura,nettoy;
	Data *next, *prev;
};Data *head=NULL, *tail=NULL, *newdata, *temp;
Data data;
void math();
void addnew();
void NewData();
void conv();
void math();
void display();
void ins();
void addins();
void menu();

int main()
{	
	NewData();
	conv();
	menu();
}

void addnew()			// Untuk menambah node baru di akhir list
{	
	if(head==NULL)
	{
		head=newdata;
		tail=newdata;
	}
	else
	{
		tail->next=newdata;
		newdata->prev=tail;
		tail=newdata;
	}
}
void NewData()			// Untuk membaca data list.csv dan membuat double linked list baru
{	
	ifstream load("data list.csv");
	while(load.good())
	{
	 newdata=new(Data);
		getline(load,newdata->nama,',');
    	getline(load,newdata->alamat,',');
   		getline(load,newdata->status,',');
   		getline(load,newdata->kelompok,',');
		getline(load,newdata->gaji,',');
		getline(load,newdata->tunjang,',');
		getline(load,newdata->bonus,',');
		getline(load,newdata->thr,',');
		getline(load,newdata->lembur,',');
		getline(load,newdata->awal,'\n');
	 newdata->prev=NULL;
	 newdata->next=NULL;
	 addnew();
	}
	load.close();
	tail=newdata->prev;
	tail->next=NULL;
}
void conv()				// Untuk mengkonversikan data variabel string menjadi int menggunakan atoi(variabel.c_str());
{	
	temp=head->next;
	while(temp!=NULL)
	{
		temp->ikelompok=atoi(temp->kelompok.c_str());
   		temp->igaji=atoi(temp->gaji.c_str());
   		temp->itunjang=atoi(temp->tunjang.c_str());
   		temp->ibonus=atoi(temp->bonus.c_str());
   		temp->ithr=atoi(temp->thr.c_str());
   		temp->ilembur=atoi(temp->lembur.c_str());
   		temp->iawal=atoi(temp->awal.c_str());
	 temp=temp->next;
	}
	math();
}
void math()				// Berisi seluruh perhitungan pph 21 yang akan digunakan
{	
	temp=head->next;
	while(temp!=NULL)
	{
	 temp->ilama=12-temp->iawal+1;						// Menentukan masa kerja berdasarkan awal masuk sampai bulan desember tahun itu
		if(temp->ikelompok==1)							// Menentukan jumlah jaminan kecelakaan kerja
			{temp->jkk=temp->igaji*24/10000;}
		else if(temp->ikelompok==2)
			{temp->jkk=temp->igaji*54/10000;}
		else if(temp->ikelompok==3)
			{temp->jkk=temp->igaji*89/10000;}
		else if(temp->ikelompok==4)
			{temp->jkk=temp->igaji*127/10000;}
		else if(temp->ikelompok==5)
			{temp->jkk=temp->igaji*174/10000;}
	 temp->jk=temp->igaji*3/1000;							// Menghitung jumlah jaminan kematian per bulan
	 temp->jht=temp->igaji*2/100;							// Menghitung jumlah jaminan hari tua per bulan
	 temp->ip=temp->igaji*1/100;							// Menghitung jumlah iuran pensiun per bulan
	 temp->natura=temp->ibonus+temp->ilembur+temp->ithr;	// Menghitung jumlah penghasilan tidak teratur
	 	if(temp->status=="tk0" || temp->status=="TK0")		// Seleksi untuk menentukan PTKP per bulan berdasarkan status perkawinan
			{temp->ptkp=54000000;}
		else if(temp->status=="tk1" || temp->status=="TK1")		// tk0-3 = Belum kawin dengan tanggungan 0-3
			{temp->ptkp=58500000;}
		else if(temp->status=="tk2" || temp->status=="TK2")
			{temp->ptkp=63000000;}
		else if(temp->status=="tk3" || temp->status=="TK3")
			{temp->ptkp=67500000;}
		else if(temp->status=="k0" || temp->status=="K0")
			{temp->ptkp=58500000;}
		else if(temp->status=="k1" || temp->status=="K1")
			{temp->ptkp=63000000;}
		else if(temp->status=="k2" || temp->status=="K2")
			{temp->ptkp=67500000;}
		else if(temp->status=="k3" || temp->status=="K3")
			{temp->ptkp=72000000;}
	 temp->bruto=temp->igaji+temp->jkk+temp->jk+temp->itunjang+temp->natura;		// Menghitung Bruto satu bulan
	 temp->bj=temp->bruto*5/100;													// Menentukan biaya jabatan, max. 500000 per bulan
	 	if(temp->bj>500000)
			{temp->bj=500000;}		
	 temp->netto=temp->bruto-temp->bj-temp->ip-temp->jht;			// Mnghitung Netto
	 temp->nettoy=temp->netto*12;									// Menghitung Netto disetahunkan
	 temp->pkp=temp->nettoy-temp->ptkp;								// Menghitung PKP
	 	if(temp->pkp<0)
	 		{temp->pkp=0;}
     temp->pkpb=(temp->pkp/=1000)*1000;						// Pembulatan PKP ke bawah hingga nominal ribuan penuh
     	if(temp->pkpb<=50000000)								// Seleksi untuk menentukan tarif pajak progresif
			{temp->tarif=5;}
		else if(temp->pkpb>50000000 && temp->pkpb<=250000000)
			{temp->tarif=15;}
		else if(temp->pkpb>250000000 && temp->pkpb<=500000000)
			{temp->tarif=25;}
		else if(temp->pkpb>500000000)
			{temp->tarif=30;}
	 temp->pph=temp->pkpb*temp->tarif/100;				// Jumlah PPH Pasal 21 disetahunkan
     temp->pphm=temp->pph/12;							// Jumlah PPH 21 per bulan
     
	 temp=temp->next;
	}
}
void display()						// Untuk menampilkan data dalam bentuk tabel di cmd sekaligus membuat file output berupa txt
{	
	temp=head->next;
	system("cls");
	ofstream save("result.txt");
	 cout<<"                                                                             HASIL PERHITUNGAN PPH 21                                                                                     "<<endl;
	 cout<<"+========================================================================================================================================================================================+"<<endl;
	 cout<<"|             Nama             |               Alamat               | Status | Kelompok | Masa Kerja |   Bruto   |   Netto   |    PTKP    |    PKP    | PPH Disetahunkan | PPH Per Bulan |"<<endl;
	 cout<<"|========================================================================================================================================================================================|"<<endl;
	 save<<"                                                                             HASIL PERHITUNGAN PPH 21                                                                                     "<<endl;
	 save<<"+========================================================================================================================================================================================+"<<endl;
	 save<<"|             Nama             |               Alamat               | Status | Kelompok | Masa Kerja |   Bruto   |   Netto   |    PTKP    |    PKP    | PPH Disetahunkan | PPH Per Bulan |"<<endl;
	 save<<"|========================================================================================================================================================================================|"<<endl;
	while(temp!=NULL)
	{
   	 cout<<"| "<<setiosflags(ios::left)<<setw(28)<<temp->nama<<" |";				// setiosflag dan setw berguna untuk merapikan
   	 	save<<"| "<<setiosflags(ios::left)<<setw(28)<<temp->nama<<" |";				// tampilan dalam tabel
   	 cout<<" "<<setiosflags(ios::left)<<setw(35)<<temp->alamat<<"|";
   	 	save<<" "<<setiosflags(ios::left)<<setw(35)<<temp->alamat<<"|";
   	 cout<<" "<<setiosflags(ios::left)<<setw(7)<<temp->status<<"|";
   	 	save<<" "<<setiosflags(ios::left)<<setw(7)<<temp->status<<"|";
   	 cout<<" "<<setiosflags(ios::left)<<setw(9)<<temp->kelompok<<"|";
   	 	save<<" "<<setiosflags(ios::left)<<setw(9)<<temp->kelompok<<"|";
     cout<<" "<<setiosflags(ios::left)<<setw(11)<<temp->ilama<<"|";
   	 	save<<" "<<setiosflags(ios::left)<<setw(11)<<temp->ilama<<"|";  	 	
	 cout<<" "<<setiosflags(ios::left)<<setw(10)<<temp->bruto<<"|";
	 	save<<" "<<setiosflags(ios::left)<<setw(10)<<temp->bruto<<"|";
	 cout<<" "<<setiosflags(ios::left)<<setw(10)<<temp->nettoy<<"|";
	 	save<<" "<<setiosflags(ios::left)<<setw(10)<<temp->nettoy<<"|";
	 cout<<" "<<setiosflags(ios::left)<<setw(11)<<temp->ptkp<<"|";
	 	save<<" "<<setiosflags(ios::left)<<setw(11)<<temp->ptkp<<"|";
	 cout<<" "<<setiosflags(ios::left)<<setw(10)<<temp->pkpb<<"|";
	 	save<<" "<<setiosflags(ios::left)<<setw(10)<<temp->pkpb<<"|";
	 cout<<" "<<setiosflags(ios::left)<<setw(17)<<temp->pph<<"|";
	 	save<<" "<<setiosflags(ios::left)<<setw(17)<<temp->pph<<"|";
	 cout<<" "<<setiosflags(ios::left)<<setw(14)<<temp->pphm<<"|"<<endl;
	 	save<<" "<<setiosflags(ios::left)<<setw(14)<<temp->pphm<<"|"<<endl;
	 temp=temp->next;
	}
	 cout<<"+========================================================================================================================================================================================+"<<endl;
	 save<<"+========================================================================================================================================================================================+"<<endl;
	cout<<endl<<endl<<"Silahkan fullscreen window cmd untuk melihat tabel secara jelas."<<endl;
	cout<<endl<<"Hasil perhitungan ini juga bisa dilihat di result.txt setelah memilih menu display."<<endl;
	cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	system("PAUSE");
}
void ins()				// Menampilkan tata cara penggunaan program
{
	cout<<endl<<endl;
	system("cls");
	ifstream open("readme.txt");
	while(open.good())
	{
	 getline(open,data.ins,'_');
	 cout<<data.ins;
	}
	open.close();
	system("PAUSE");
}
void addins()		// Untuk menambahkan data karyawan baru
{
	cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	cout<<endl;
	ofstream ow("data list.csv", ios::app | ios::out);
	newdata=new(Data);
	 cout<<"Nama                            : ";
	 	cin.ignore();
		getline(cin,newdata->nama);
		ow<<newdata->nama<<",";
	 cout<<"Alamat                          : ";
		getline(cin,newdata->alamat);
	 	cin.ignore();
	 	ow<<newdata->alamat<<",";
	 cout<<"Status Perkawinan               : ";
	 	cin>>newdata->status;
	 	ow<<newdata->status<<",";
	 cout<<"Kelompok JKK                    : ";
	 	cin>>newdata->kelompok;
	 	ow<<newdata->kelompok<<",";
	 cout<<"Gaji Pokok                      : ";
	 	cin>>newdata->gaji;
	 	ow<<newdata->gaji<<",";
	 cout<<"Tunjangan                       : ";
	 	cin>>newdata->tunjang;
	 	ow<<newdata->tunjang<<",";
	 cout<<"Bonus                           : ";
	 	cin>>newdata->bonus;
	 	ow<<newdata->bonus<<",";
	 cout<<"Tunjangan Hari raya (THR)       : ";
	 	cin>>newdata->thr;
	 	ow<<newdata->thr<<",";
	 cout<<"Uang Lembur                     : ";
	 	cin>>newdata->lembur;
	 	ow<<newdata->lembur<<",";
	 cout<<"Mulai Bekerja pada bulan ke-    : ";
	 	cin>>newdata->awal;
	 	ow<<newdata->awal<<"\n";
	addnew();
	conv();
	ow.close();
	cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	system("PAUSE");
}
	void update()
	{	
		system("cls");
		ofstream up("data list.csv", ios::out);
		string search;
		cout<<"----------JANGAN TUTUP RUNNING CMD SAAT MENGEDIT, KARENA AKAN MERUSAK data list.csv !!!----------"<<endl;
		{temp=head->next;
		 cout<<"Daftar Karyawan : "<<endl;
		 while (temp!=NULL)
		 {
			cout<<"-"<<temp->nama<<endl;
			temp=temp->next;
		 }
		}
		cout<<"Masukkan nama karyawan yang datanya ingin diupdate : ";
		cin.ignore();
		getline(cin,search);
		cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		temp=head;
		while(temp!=NULL)
		{
			if(temp->nama==search)
			{
			 cout<<"Nama                            : ";
				getline(cin,temp->nama);
				up<<temp->nama<<",";
			 cout<<"Alamat                          : ";
				getline(cin,temp->alamat);
				cin.ignore();
		 		up<<temp->alamat<<",";
			 cout<<"Status Perkawinan               : ";
		 		cin>>temp->status;
			 	up<<temp->status<<",";
			 cout<<"Kelompok JKK                    : ";
			 	cin>>temp->kelompok;
			 	up<<temp->kelompok<<",";
			 cout<<"Gaji Pokok                      : ";
			 	cin>>temp->gaji;
			 	up<<temp->gaji<<",";
			 cout<<"Tunjangan                       : ";
			 	cin>>temp->tunjang;
			 	up<<temp->tunjang<<",";
			 cout<<"Bonus                           : ";
			 	cin>>temp->bonus;
			 	up<<temp->bonus<<",";
			 cout<<"Tunjangan Hari raya (THR)       : ";
			 	cin>>temp->thr;
			 	up<<temp->thr<<",";
			 cout<<"Uang Lembur                     : ";
			 	cin>>temp->lembur;
			 	up<<temp->lembur<<",";
			 cout<<"Mulai Bekerja pada bulan ke-    : ";
			 	cin>>temp->awal;
			 	up<<temp->awal<<"\n";
			}
			else {
				 	up<<temp->nama<<",";
				 	up<<temp->alamat<<",";
				 	up<<temp->status<<",";
				 	up<<temp->kelompok<<",";
				 	up<<temp->gaji<<",";
				 	up<<temp->tunjang<<",";
				 	up<<temp->bonus<<",";
				 	up<<temp->thr<<",";
				 	up<<temp->lembur<<",";
				 	up<<temp->awal<<"\n";
				 }			
		 temp=temp->next;
		}
		conv();
		up.close();
	cout<<"--------------------------------------------------------------------------------------------------"<<endl;
	system("PAUSE");
}
void menu()			
{	
	prompt:
	char choice;
	system("cls");
	cout<<"=================================================="<<endl;    
	cout<<"|         Nama   : Alland Chandra Kesuma         |"<<endl;
	cout<<"|         NIM    : 20170801011                   |"<<endl;
	cout<<"=================================================="<<endl;
	cout<<"            Program Perhitungan PPH 21            "<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cout<<"Silahkan pilih menu yang Anda inginkan :"<<endl;
	cout<<"1. Tata Cara Penggunaan Program"<<endl;
	cout<<"2. Tambah Data"<<endl;
	cout<<"3. Edit Data"<<endl;
	cout<<"4. Display Hasil"<<endl;
	cout<<"5. Keluar"<<endl;
	cout<<"Masukkkan pilihan Anda [1/2/3/4/5]: ";
	cin>>choice;
	switch (choice)
    {	case '1': ins(); goto prompt;
    	case '2': addins(); goto prompt;
    	case '3': update(); goto prompt;
		case '4': display(); goto prompt;
		case '5': cout<<endl<<endl<<"-------Terima Kasih telah menggunakan program ini!-------"<<endl; break;
    	default : cout<<"Pilihan Anda Salah!!"<<endl; getch(); goto prompt;
	}
	getch();
}
