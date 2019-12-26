//ALLAND CHANDRA KESUMA (20170801011)
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include "sha1.h"
#include "sha1.cpp"
using namespace std;
int main(int argc, char *argv[]){
	char PT[100], ch;
    int i, bin, key;
    
    cout<<"Input PlainText : ";
    cin.getline(PT,100);
    cout<<"Input Key : ";
    cin>>key;
    
    for (i=0; PT[i] != '\0'; i++){
    	ch=PT[i];
    	if(ch>= 'a' && ch<='z'){
    		ch=ch+key;
    		if(ch > 'z'){
    			ch = ch - 'z' + 'a' -1;
			}
			PT[i] = ch;
		}else if (ch>= 'A' && ch<='Z'){
    		ch=ch+key;
    		if(ch > 'Z'){
    			ch = ch - 'Z' + 'A' -1;
			}
			PT[i] = ch;
		}
	}
	cout<<"Hasil Enkripsi : "<<PT;
	cout<<endl<<endl;
	
	cout<<"Hasil Hash : "<<sha1(PT);

	cout<<endl<<endl;
	system("PAUSE");
}
