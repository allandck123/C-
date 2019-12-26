//ALLAND CHANDRA KESUMA (20170801011)
#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
struct DataNilai{											//struct yang berisi variabel nilai yang akan di input
	int jsem;
	float bindo[50], bing[50], mtk[50], fis[50], kim[50], bio[50];
	float rbindo, rbing, rmtk, rfis, rkim, rbio;
	float usbindo, usbing, usmtk, usfis, uskim, usbio;
	float nsbindo, nsbing, nsmtk, nsfis, nskim, nsbio;
	float unbindo, unbing, unmtk, unfis, unkim, unbio;
	float nabindo, nabing, namtk, nafis, nakim, nabio;
};	DataNilai nil;
void id(){													//Fungsi untuk menampilkan identitas pembuat program
	cout<<"=================================================="<<endl;    
	cout<<"|         Nama   : Alland Chandra Kesuma         |"<<endl;
	cout<<"|         NIM    : 20170801011                   |"<<endl;
	cout<<"=================================================="<<endl;	
}
void input(int n){											//Fungsi untuk Input
	float sbi=0,sbg=0,sm=0,sf=0,sk=0,sb=0;
	cout<<"------------------------Program Perhitungan Nilai Akhir----------------------------"<<endl;
	cout<<"Masukkan Jumlah Semester : ";
		cin>>nil.jsem;
	cout<<"Nilai Pelajaran Bahasa Indonesia : "<<endl;
	for(n=0;n<nil.jsem;n++){
		cout<<"Nilai Raport Semester ke-"<<n+1<<" : ";
			cin>>nil.bindo[n];
			sbi=sbi+nil.bindo[n];}
			nil.rbindo=sbi/nil.jsem;
		cout<<"Nilai US                   : ";
			cin>>nil.usbindo;
		cout<<"Nilai UN                   : ";
			cin>>nil.unbindo;
	cout<<"Nilai Pelajaran Bahasa Inggris   : "<<endl;
	for(n=0;n<nil.jsem;n++){
		cout<<"Nilai Raport Semester ke-"<<n+1<<" : ";
			cin>>nil.bing[n];
			sbg=sbg+nil.bing[n];}
			nil.rbing=sbg/nil.jsem;
		cout<<"Nilai US                   : ";
			cin>>nil.usbing;
		cout<<"Nilai UN                   : ";
			cin>>nil.unbing;
	cout<<"Nilai Pelajaran Matematika       : "<<endl;
	for(n=0;n<nil.jsem;n++){
		cout<<"Nilai Raport Semester ke-"<<n+1<<" : ";
			cin>>nil.mtk[n];
			sm=sm+nil.mtk[n];}
			nil.rmtk=sm/nil.jsem;
		cout<<"Nilai US                   : ";
			cin>>nil.usmtk;
		cout<<"Nilai UN                   : ";
			cin>>nil.unmtk;	
	cout<<"Nilai Pelajaran Fisika           : "<<endl;
	for(n=0;n<nil.jsem;n++){
		cout<<"Nilai Raport Semester ke-"<<n+1<<" : ";
			cin>>nil.fis[n];
			sf=sf+nil.fis[n];}
			nil.rfis=sf/nil.jsem;
		cout<<"Nilai US                   : ";
			cin>>nil.usfis;
		cout<<"Nilai UN                   : ";
			cin>>nil.unfis;
	cout<<"Nilai Pelajaran Kimia            : "<<endl;
	for(n=0;n<nil.jsem;n++){
		cout<<"Nilai Raport Semester ke-"<<n+1<<" : ";
			cin>>nil.kim[n];
			sk=sk+nil.kim[n];}
			nil.rkim=sk/nil.jsem;
		cout<<"Nilai US                   : ";
			cin>>nil.uskim;
		cout<<"Nilai UN                   : ";
			cin>>nil.unkim;
	cout<<"Nilai Pelajaran Biologi          : "<<endl;
	for(n=0;n<nil.jsem;n++){
		cout<<"Nilai Raport Semester ke-"<<n+1<<" : ";
			cin>>nil.bio[n];
			sb=sb+nil.bio[n];}
			nil.rbio=sb/nil.jsem;												
		cout<<"Nilai US                   : ";
			cin>>nil.usbio;
		cout<<"Nilai UN                   : ";
			cin>>nil.unbio;
}
void calculate(){											//Fungsi untuk menghitung NS dan NA
	nil.nsbindo=(0.7*nil.rbindo)+(0.3*nil.usbindo);
	nil.nsbing=(0.7*nil.rbing)+(0.3*nil.usbing);
	nil.nsmtk=(0.7*nil.rmtk)+(0.3*nil.usmtk);
	nil.nsfis=(0.7*nil.rfis)+(0.3*nil.usfis);
	nil.nskim=(0.7*nil.rkim)+(0.3*nil.uskim);
	nil.nsbio=(0.7*nil.rbio)+(0.3*nil.usbio);
	
	nil.nabindo=(0.6*nil.unbindo)+(0.4*nil.nsbindo);
	nil.nabing=(0.6*nil.unbing)+(0.4*nil.nsbing);
	nil.namtk=(0.6*nil.unmtk)+(0.4*nil.nsmtk);
	nil.nafis=(0.6*nil.unfis)+(0.4*nil.nsfis);
	nil.nakim=(0.6*nil.unkim)+(0.4*nil.nskim);
	nil.nabio=(0.6*nil.unbio)+(0.4*nil.nsbio);
}
void evaluation(){											//Fungsi untuk menghitung rata-rata NA dan menentukan kelulusan siswa
	int e=0, avg;
	e=nil.nabindo+nil.nabing+nil.namtk+nil.nafis+nil.nakim+nil.nabio;
	avg=e/6;
	if(avg>=5.5 && nil.nabindo>=4.0 && nil.nabing>=4.0 && nil.namtk>=4.0 && nil.nafis>=4.0 && nil.nakim>=4.0 && nil.nabio>=4.0)
		{cout<<"Siswa dinyatakan Lulus"<<endl;}
	else
		{cout<<"Siswa dinyatakan Tidak Lulus"<<endl;}
}
void disp(){												//Fungsi untuk Display/Output
	calculate();
	id();
	cout<<"Keterangan : "<<endl;
	cout<<"1. NR = Nilai rata-rata dari setiap semester"<<endl;
	cout<<"2. NS = 70% NR + 30% US"<<endl;
	cout<<"3. Nilai Akhir(NA) = 40% NS + 60% Nilai UN"<<endl;
	cout<<"4. Siswa dinyatakan lulus UN, bila NA setiap mata pelajaran >= 4.0 dan rata-rata"<<endl;
	cout<<"   NA semua mata pelajaran >= 5.5"<<endl<<endl;
	cout<<"Pelajaran Bahasa Indonesia :"<<endl;
		printf("NR          : %.1f\n",nil.rbindo);     		//%.1f artinya hanya menampilkan 1 angka dibelakang koma
		printf("Nilai US    : %.1f\n",nil.usbindo);
		printf("NS          : %.1f\n",nil.nsbindo);
		printf("Nilai UN    : %.1f\n",nil.unbindo);
		printf("Nilai AKhir : %.1f\n\n",nil.nabindo);
	cout<<"Pelajaran Bahasa Ingris    :"<<endl;
		printf("NR          : %.1f\n",nil.rbing);
		printf("Nilai US    : %.1f\n",nil.usbing);
		printf("NS          : %.1f\n",nil.nsbing);
		printf("Nilai UN    : %.1f\n",nil.unbing);
		printf("Nilai AKhir : %.1f\n\n",nil.nabing);
	cout<<"Pelajaran Matematika       :"<<endl;
		printf("NR          : %.1f\n",nil.rmtk);
		printf("Nilai US    : %.1f\n",nil.usmtk);
		printf("NS          : %.1f\n",nil.nsmtk);
		printf("Nilai UN    : %.1f\n",nil.unmtk);
		printf("Nilai AKhir : %.1f\n\n",nil.namtk);	
	cout<<"Pelajaran Fisika           :"<<endl;
		printf("NR          : %.1f\n",nil.rfis);
		printf("Nilai US    : %.1f\n",nil.usfis);
		printf("NS          : %.1f\n",nil.nsfis);
		printf("Nilai UN    : %.1f\n",nil.unfis);
		printf("Nilai AKhir : %.1f\n\n",nil.nafis);		
	cout<<"Pelajaran Kimia            :"<<endl;
		printf("NR          : %.1f\n",nil.rkim);
		printf("Nilai US    : %.1f\n",nil.uskim);
		printf("NS          : %.1f\n",nil.nskim);
		printf("Nilai UN    : %.1f\n",nil.unkim);
		printf("Nilai AKhir : %.1f\n\n",nil.nakim);		
	cout<<"Pelajaran Biologi          :"<<endl;
		printf("NR          : %.1f\n",nil.rbio);
		printf("Nilai US    : %.1f\n",nil.usbio);
		printf("NS          : %.1f\n",nil.nsbio);
		printf("Nilai UN    : %.1f\n",nil.unbio);
		printf("Nilai AKhir : %.1f\n\n",nil.nabio);		
	evaluation();
}
int main(){
	int i;
	id();
	input(i);
	system("cls");										//Berfungsi untuk membersihkan layar cmd
	disp();
	getch();
}
