#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    int n;
    cin>>n;
    cin.ignore();

    while(n--){
        string s;
        getline(cin, s);
        if(s.size() > 2)
            cout << s.substr(2, s.size()-2) << "\n";
        else
            cout << "\n";
    }
}