//Verman Cipher

#include<bits/stdc++.h>
using namespace std;

string encrypt(string m,string key){
    int i,j,k,sum=0;
    string ans="";
	int mod = key.size();
    j=0;
    for(i=key.size();i<m.size();i++){
        key+=key[j%mod];
        j++;
    }
    for(i=0;i<m.size();i++){
        ans += (key[i]-'A'+m[i]-'A')%26+'A';
    }
    return ans;
}

string decrypt(string m,string key){
	int i,j,k,sum=0;
	int mod = key.size();
    j=0;
    for(i=key.size();i<m.size();i++){
        key+=key[j%mod];
        j++;
    }
    string ans="";
    for(i=0;i<m.size();i++){
        ans += (m[i]-key[i]+26)%26+'A';
    }
    return ans;
	
}

int main(){
    string m,key,ans="";
    cout<<"Enter the message"<<'\n';
    cin>>m;
    cout<<"Enter the key"<<'\n';
    cin>>key;
    ans = encrypt(m,key);
    cout<<"Encrypted message: "<<ans<<'\n';
    ans = decrypt(ans,key);
    cout<<"Decrypted message: "<<ans<<'\n';
    return 0;
}

