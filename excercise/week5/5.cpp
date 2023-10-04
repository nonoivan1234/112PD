#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

bool ioslate(char c){
    if(c>='a' && c<='z')    return 0;
    if(c>='A' && c<='Z')    return 0;
    if(c>='0' && c<='9')    return 0;
    return 1;
}

signed main(){
    nono_is_handsome

    char s[1000];
    cin.getline(s, 1000);

    for(int i=0; i<strlen(s); i++){
        if(s[i]=='0'){
            if(i==strlen(s)-1 && ioslate(s[i-1])){
                cout<<"zero";
            }
            else if(i==0 && ioslate(s[i+1])){
                cout<<"zero";
            }
            else if(ioslate(s[i-1]) && ioslate(s[i+1])){
                cout<<"zero";
            }
            else{
                cout<<s[i];
            }
        }
        else{
            cout<<s[i];
        }
    }
}