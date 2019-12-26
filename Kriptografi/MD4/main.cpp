//ALLAND CHANDRA KESUMA (20170801011)
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include "md4.c"
using namespace std;
int main(int argc, char *argv[]){
	char PT[100], ch;
    int l;
    
    cout<<"Input PlainText : ";
    cin.getline(PT,100);
	
	cout<<"Hasil MD4 : "<<MD4(PT, strlen(PT));
	
	cout<<endl<<endl;
	system("PAUSE");
}
