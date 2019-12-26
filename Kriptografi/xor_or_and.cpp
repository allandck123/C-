//ALLAND CHANDRA KESUMA (20170801011)
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

int main(){
	char T[100],k[100], ch;
	int i,c,j,o,bin,b[9], choice;
	cout<<"Input Message : ";
	cin.getline(T,100);
	cout<<"Input key : ";
	cin.clear();
	cin.getline(k,100);
	cout<<endl;
	
    
    cout<<"Desimal : ";
    for(int i=0; T[i] != '\0'; ++i){
    	int des=T[i];
      	cout<<des<<" ";
	}
	cout<<endl;
	cout<<"XOR :"<<endl;
	for(int i=0; k[i] != '\0'; ++i){
		for(int y=0; T[y] !='\0'; ++y){
    	int des=T[y];
    	int key=k[i];
    	c=des^key;
      	cout<<c<<" ";
      }
      cout<<endl;
	}
	cout<<endl;
	cout<<"OR :"<<endl;
	for(int i=0; k[i] != '\0'; ++i){
		for(int y=0; T[y] !='\0'; ++y){
    	int des=T[y];
    	int key=k[i];
    	c=des | key;
      	cout<<c<<" ";
      }
      cout<<endl;
	}
	cout<<endl;
	cout<<"AND :"<<endl;
	for(int i=0; k[i] != '\0'; ++i){
		for(int y=0; T[y] !='\0'; ++y){
    	int des=T[y];
    	int key=k[i];
    	c=des & key;
      	cout<<c<<" ";
      }
      cout<<endl;
	}
	  
   
   	cout<<endl;
   	system("PAUSE");

}
