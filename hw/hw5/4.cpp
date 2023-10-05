#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 2005;

signed main(){
    nono_is_handsome

    int n;
    cin>>n;

    char s[N];
    cin.ignore();
    cin.getline(s, N);

    vector<int> v;

    int ind = 0, len = strlen(s);

    while(ind < len){
        int tmp = 0;
        while(ind < len && s[ind] != ','){
            tmp = tmp*10 + s[ind]-'0';
            ind++;
        }

        ind++;
        v.push_back(tmp);
    }

    sort(v.rbegin(), v.rend());

    cout << v[1] << "\n";
}