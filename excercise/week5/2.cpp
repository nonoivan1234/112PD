#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    string s;
    while(cin>>s){
        if(s[0]>='a' && s[0]<='z'){
            s[0] = s[0] - 'a' + 'A';
        }

        for(int i = 1; i < s.size(); i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = s[i] - 'A' + 'a';
            }
        }

        cout<<s<<' ';
    }
}