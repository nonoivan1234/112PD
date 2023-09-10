#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

int highGradeCnt(int threshold, int gradeCnt, int grades[ ]);

int highGradeCnt(int threshold, int gradeCnt, int grades[ ]){
    int cnt = 0;
    for(int i = 0; i < gradeCnt; i++){
        if(grades[i] >= threshold){
            cnt++;
        }
    }
    return cnt;
}

signed main(){
    nono_is_handsome

    int n, t;
    cin >> n >> t;

    int grades[n];
    for(int i = 0; i < n; i++){
        cin >> grades[i];
    }

    cout << highGradeCnt(t, n, grades) << '\n';

    return 0;
}