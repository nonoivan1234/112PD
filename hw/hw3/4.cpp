#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int INF = 1e18;

signed main(){
    nono_is_handsome

    int n, m, W=0, V=0;
    cin >> n >> m;
    int w[n + 1], v[n + 1];
    bool used[n + 1] = {0};
    for(int i = 1; i <= n; i++) cin >> w[i], W += w[i];
    for(int i = 1; i <= n; i++) cin >> v[i], V += v[i];

    while(W>m){
        int valMin=INF, indMin=-1;
        for(int i=1;i<=n;i++){
            if ((W-w[i]) <= m && !used[i] && v[i] < valMin){
                valMin = v[i];
                indMin = i;
            }
        }

        if (indMin!=-1){
            W -= w[indMin];
            V -= v[indMin];
            used[indMin] = 1;
            break;
        }

        valMin = INF, indMin = -1;
        for(int i = 1; i <= n; i++){
            if(!used[i] && v[i] < valMin){
                valMin = v[i];
                indMin = i;
            }
        }

        if(indMin == -1) break;

        W -= w[indMin];
        V -= v[indMin];
        used[indMin] = 1;

        // cout<<indMin<<" "<< W <<" "<<V <<endl;
    }

    bool ok=1;
    vector<int> ans;
    for(int i=1;i<=n;i++)   if(!used[i])    ans.push_back(i), ok=0;

    if(ok)  cout << ";0";
    else{
        for(int i=0;i<ans.size();i++){
            cout << ans[i];
            if(i!=ans.size()-1) cout << ",";
        }
        cout << ";" << V;
    }
}