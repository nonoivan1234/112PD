#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 1e5;

void to_lower(char *s){
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        s[i] = tolower(s[i]);
    }
}

signed main(){
    nono_is_handsome

    char c[N], tar[N];
    cin.getline(c, N);
    cin.getline(tar, N);
    to_lower(c);
    to_lower(tar);

    int cnt = 0;
    int n = strlen(c), m = strlen(tar);
    for(int i = 0; i + n <= m; i++){
        bool ok = 1;
        for(int j = 0; j < n; j++){
            if(c[j] != tar[i + j]){
                ok = 0;
                break;
            }
        }
        if(ok){
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}