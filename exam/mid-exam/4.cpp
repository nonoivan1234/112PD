#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome
    
    int n;
    cin >> n;
    int arr[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> arr[i][j];
    }

    int cnt = 0, save = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            bool ok = 0;
            int tmp = 0;
            for(int k = 0; k < n; k++){
                if(k == i || k == j) continue;
                if(arr[i][k] + arr[k][j] < arr[i][j]){
                    ok = 1;
                    tmp = max(tmp, arr[i][j] - arr[i][k] - arr[k][j]);
                }
            }

            if(ok){
                cnt++;
                save += tmp;
            }
        }
    }

    cout << cnt << ',' << save << '\n';
}