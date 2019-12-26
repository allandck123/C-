//ALLAND CHANDRA KESUMA (20170801011)
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
#include<string.h>
using namespace std;
struct DataSiswa{
	float UTS, UAS, TUGAS[100], TAVG;
	char nama[60];
	long long int nim;
};   DataSiswa ds[5000][100];
struct Data{
 int jt,jm[100],bt[100],buts[100],buas[100],jk,susun;
};	Data dn;
struct MK{
	int mk;
	const char* matkul;
	char dosen [60];
}; MK dmk[100];
int _1011NA(int a, int n)
{
 int NA;
   NA = ((ds[a][n].TAVG*dn.bt[n]/100)+(ds[a][n].UTS*dn.buts[n]/100)+(ds[a][n].UAS*dn.buas[n]/100));
   return NA;
}
int _1011max(int n, int x)
{	int max;
	for(n=0;n<dn.jm[x];n++){
	if(_1011NA(n,x)>max){
	max=_1011NA(n,x);}}
	cout<<"Nilai Akhir Tertinggi : "<<max<<endl;
}
int _1011avg(int u, int v)
{	int sum=0, NAVG;
	for(u=0;u<dn.jm[v];u++){
	sum=sum+_1011NA(u,v);}
	NAVG=sum/dn.jm[v];
}
int _1011min(int e, int q)
{	int min=1000;
	for(e=0;e<dn.jm[q];e++){
	if(min>_1011NA(e,q)){
	min=_1011NA(e,q);}}
	cout<<"Nilai Akhir Terendah  : "<<min<<endl<<endl;
}
int _1011dat()
{	int i;
	cout<<"============================================================"<<endl;
   	cout<<"            PROGRAM INPUT DAFTAR NILAI MAHASISWA"<<endl;
   	cout<<"============================================================"<<endl;
	cout<<"Jumlah Kelas                              : ";
	   	cin>>dn.jk;	
	for(i=0;i<dn.jk;i++){
	cout<<"Kode Mata Kuliah Kelas ke-"<<i+1<<" (351/724/562) : ";
	   	cin>>dmk[i].mk;
	cout<<"Dosen Pengajar Kelas ke-"<<i+1<<"                 : ";
		scanf(" %[^\n]s",dmk[i].dosen);
	cout<<"Jumlah Mahasiswa Kelas Ke-"<<(i+1)<<"               : ";
	   	cin>>dn.jm[i];
	if(dmk[i].mk == 351){
		dmk[i].matkul = "Struktur Data";}
	else if(dmk[i].mk == 724){
		dmk[i].matkul = "Desain dan Analisis Algoritma";}
	else if(dmk[i].mk == 562){
		dmk[i].matkul = "Bahasa Pemrograman";}}
	cout<<"Jumlah Tugas                              : ";
	   	cin>>dn.jt;
}
int _1011head(int b)
{	pop:
	cout<<endl;
	cout<<"============================================================"<<endl;
	for(b=0;b<dn.jk;b++){
	cout<<"Masukkan Bobot Nilai Kelas ke-"<<b+1<<endl;
	cout<<"Masukkan Persentase TUGAS     : ";
		cin>>dn.bt[b];
	cout<<"Masukkan Persentase UTS       : ";
		cin>>dn.buts[b];
	cout<<"Masukkan Persentase UAS       : ";
		cin>>dn.buas[b];}
   	cout<<"============================================================"<<endl;
}
int _1011in(int d, int p)
{	int i,sum=0;
    cout<<"Kelas ke-"<<(p+1)<<endl;
 	cout<<"Mahasiswa ke-"<<(d + 1)<<endl;
	printf("Nama             : ");
		scanf(" %[^\n]s",ds[d][p].nama);
   	cout<<"NIM              : ";
	   	cin>>ds[d][p].nim;
	for(i=0; i<dn.jt; i++){
	cout<<"Nilai Tugas ke-"<<i+1<<" : ";
	   	cin>>ds[d][p].TUGAS[i];	
	sum=ds[d][p].TUGAS[i]+sum;}
	ds[d][p].TAVG=sum/dn.jt;
	cout<<"Nilai UTS        : ";
	   	cin>>ds[d][p].UTS;
   	cout<<"Nilai UAS        : ";
	   cin>>ds[d][p].UAS;
	cout<<endl;
}
void _1011tabel()
{	int i;
	cout<<"|=========================================";
	for(i=0; i<dn.jt; i++)
	{cout<<"==========";}
	cout<<"========================|"<<endl;
	cout<<"|     NIM     |      Nama Mahasiswa      |";
	for(i=0; i<dn.jt; i++)
	cout<<" Tugas "<<i+1<<" |";
	cout<<"  UTS  |  UAS  |   NA   |"<<endl;
	cout<<"|=========================================";
	for(i=0; i<dn.jt; i++)
	{cout<<"==========";}
	cout<<"========================|"<<endl;
}
int _1011footer(int i, int j)
{ 	
	cout<<"==========================================";
	for(i=0; i<dn.jt; i++)
	{cout<<"==========";}
	cout<<"========================="<<endl<<endl;
	_1011max(i,j);
	cout<<"Nilai Rata - Rata     : "<<_1011avg(i,j)<<endl;
	_1011min(i,j);
}	
void _1011isi(int c,int t)
{
	int i;
   	cout<<"| "<<setiosflags(ios::left)<<setw(11)<<ds[c][t].nim<<" |";
   	cout<<setiosflags(ios::left)<<setw(26)<<ds[c][t].nama<<"|";
   	for(i=0; i<dn.jt; i++){
   	cout<<"  "<<setw(6)<<ds[c][t].TUGAS[i]<<" |";}
   	cout<<"  "<<setw(5)<<ds[c][t].UTS<<"|  ";
   	cout<<setw(5)<<ds[c][t].UAS<<"|   ";
   	cout<<setw(5)<<_1011NA(c,t)<<"|"<<endl;
}
void _1011insort()
{
	system("cls");
	cout<<"Tentukan Metode Pengurutan !!"<<endl<<endl;
	cout<<"1. Berdasarkan Nama Mata Kuliah."<<endl;
	cout<<"2. Berdasarkan Nama Dosen."<<endl;
	cout<<"Pilihan Anda (1/2): ";
	cin>>dn.susun;
	system("cls");
}
void _1011sort(int i, int f)
{	int j, x, s;
	if(dn.susun==1){	
	for (i=0; i<dn.jk; i++){
	j=i;
	for (i=0; i<dn.jk; i++){
		j=i;
		for(x=i+1; x<dn.jk; x++){
			s=strcmp(dmk[j].matkul,dmk[x].matkul);
				if(s>0) {
 				j=x;}}
  		if (j!=i){
   			swap(dmk[j],dmk[i]);
   			for(f=0;f<dn.jm[i];f++){
				swap(ds[f][j],ds[f][i]);}}}}}
   	else if(dn.susun==2){
		for (i=0; i<dn.jk; i++){
		j=i;
		for(x=i+1; x<dn.jk; x++){
			s=strcmp(dmk[j].dosen,dmk[x].dosen);
				if(s>0) {
 				j=x;}}
  		if (j!=i){
   			swap(dmk[j],dmk[i]);
   			for(f=0;f<dn.jm[i];f++){
				swap(ds[f][j],ds[f][i]);}}}}
   	else{
	   	cout<<"Pilihan Anda Invalid, Masukkan Input yang Benar!!";getch();}
	for (i=0; i<dn.jm[f]; i++){
	j=i;
	for(x=i+1; x<dn.jm[f]; x++){
		if(ds[j][f].nim>ds[x][f].nim){
			j=x;}}
		if(j!=i){
			swap(ds[j][f],ds[i][f]);}}
}
char _1011display(int j)
{	int i;
	
	for(j=0;j<dn.jk;j++){

	_1011sort(i,j);
	cout<<"Mata Kuliah      : "<<dmk[j].matkul<<endl;
	cout<<"Kode Mata Kuliah : "<<dmk[j].mk<<endl;
	cout<<"Dosen Pengajar   : "<<dmk[j].dosen<<endl;
	_1011tabel();
   	for(i=0; i<dn.jm[j]; i++)
    	{_1011isi(i,j);}
   	_1011footer(i,j);}
}
int main(){
	int i,j;
	char YN;
	start:
	system("cls");
		_1011dat();
		_1011head(i);
	system("cls");
	for (int j=0; j<dn.jk; j++){
   		for(int i=0; i<dn.jm[j]; i++)
    		{_1011in(i,j);}}
	
	system("cls");
	_1011insort();
	system("cls");
	cout<<"                        	   DAFTAR NILAI MAHASISWA        	                   "<<endl;
	_1011display(i);

	prompt:	
	cout<<"\nApakah anda ingin mengulangi program ? [Y/T] : ";
	cin>>YN;
	cout<<endl;
	if(YN=='Y' || YN=='y')
		{goto start;}
	if(YN =='T' || YN =='t')
		{goto end;}
	else {cout<<"Masukkan jawaban yang benar!!!";goto prompt;}
	end:
	cout<<("Terima Kasih telah menggunakan program ini");	
}
