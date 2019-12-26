//ALLAND CHANDRA KESUMA (20170801011)
#include <iostream>
#include <conio.h>
using namespace std;

char A[100], karakter, k, k1,k2,choice;
int i, dif,key;
void encrypt();	
void decrypt();

int main(){
	prompt:
	system("cls");
	cout<<"1. Enkripsi"<<endl;
	cout<<"2. Dekripsi"<<endl;
	cout<<"3. Keluar"<<endl;	
	cout<<"Pilihan : ";
	cin>>choice;
	switch (choice)
    {	case '1': encrypt(); goto prompt;
    	case '2': decrypt(); goto prompt;
		case '3': cout<<endl<<"-------Terima Kasih telah menggunakan program ini!-------"<<endl; break;
    	default : cout<<"Pilihan Anda Salah!!"<<endl; getch(); goto prompt;
	}
	getch();
	
}

void encrypt(){
	system("cls");
	cout<<"INPUT PLAINTEXT    : ";
	cin.ignore();
	cin.getline(A,100);
	cout<<"INPUT HURUF ASAL   : ";
	cin>>k1;
	cout<<"INPUT HURUF CHIPER : ";
	cin>>k2;
	dif=k2-k1+26;

	for(i=0; A[i] !='\0'; i++){
		key=A[i];	
	k=dif;
	if(key>=65 && key<=90){
		key+=k;
		if(key>90)
		key-=26;
	}else if(key>=97 && key<=122){
		key+=k;
		if(key>122)
		key-=26;
	}else{
	}
		karakter= key;
		A[i]=karakter;
	}
	cout<<"HASIL ENKRIPSI PLAINTEXT : "<<A<<endl;
	system("PAUSE");
}

void decrypt(){
	system("cls");
	cout<<"INPUT CHIPERTEXT   : ";
	cin.ignore();
	cin.getline(A,100);
	cout<<"INPUT HURUF ASAL   : ";
	cin>>k1;
	cout<<"INPUT HURUF CHIPER : ";
	cin>>k2;
	dif=k2-k1+26;
	
	for(i=0; A[i] !='\0'; i++){
		key=A[i];	
	k=dif;
	if(key>=65 && key<=90){
		key-=k;
		if(key>90 || key <65)
		key+=26;
	}else if(key>=97 && key<=122){
		key-=k;
		if(key>122 || key <97)
		key+=26;
	}else{
	}
		karakter= key;
		A[i]=karakter;
	}
	cout<<"HASIL DEKRIPSI PLAINTEXT : "<<A<<endl;
	system("PAUSE");
}

