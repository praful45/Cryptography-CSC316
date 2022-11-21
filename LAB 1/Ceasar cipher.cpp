//lab 1.1 Ceasar Cipher

#include<iostream>
#include<cctype>
#include<string>

using namespace std;

string encrypt(string inp){
	for(int i=0;i<inp.length();i++){
		if(!isspace(inp[i]))
			inp[i]=inp[i]+3;
	}
	return inp;
}

string decrypt(string inp){
	for(int i=0;i<inp.length();i++){
		if(!isspace(inp[i]))
			inp[i]=inp[i]-3;
	}
	return inp;
}

int main(){
	string plain,cipher;
	cout<<"Enter the plain text: ";
	getline(cin,plain);
	cout<<endl<<"After Encryption: ";
	cipher = encrypt(plain);
	cout<<cipher;
	cout<<endl<<"After Decryption: ";
	plain = decrypt(cipher);
	cout<<plain;
}
