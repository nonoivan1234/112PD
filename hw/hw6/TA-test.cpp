#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
const int N = 25;
const int M = 505;
int n, m, R[N], A[N], B[M], D[M][M], ans[N][M];
vector<int> S[M][4];
double Q[4], U[N][M];

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void init(){
    cin >> n >> m;
    for(int i = 0; i < 4; i++)  cin >> Q[i];

    for(int i = 0; i < n; i++)  cin >> R[i];
    for(int i = 0; i < n; i++)  cin >> A[i];
    for(int i = 0; i < m; i++)  cin >> B[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> U[i][j];
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            int tmp;
            cin >> tmp;
            if(tmp == 0)    D[i][j] = 0;
            else if(tmp <= 300) D[i][j] = 1;
            else if(tmp <= 500) D[i][j] = 2;
            else if(tmp <= 1000)    D[i][j] = 3;

            S[i][D[i][j]].push_back(j);
        }
    }
}

double getVal(){
    double ret = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            double tmp = U[i][j] + Q[0];
            for(int k = 0; k < 4; k++){
                for(auto l : S[j][k]){
                    for(int t = 0; t < n; t++){
                        tmp -= Q[k] * ans[t][l];
                    }
                }
            }

            ret += tmp * R[i] * ans[i][j] * 24;
        }
    }

    return ret;
}

void solve1(){
    int now = 0;
    while(1){
        int tmp, x = -1, y = -1;
        for(int i = 0; i < n; i++){
            if(A[i] == 0)   continue;
            for(int j = 0; j < m; j++){
                if(B[j] == 0)   continue;
                ans[i][j]++;
                tmp = getVal();
                if(tmp > now){
                    now = tmp;
                    x = i, y = j;
                }
                ans[i][j]--;
            }
        }

        if(x == -1) break;
    
        ans[x][y]++;
        A[x]--;
        B[y]--;
    }
}

void solve2(){
    vector<int> v;
    vector<int> x(M, 0);

    for(int k = 0; k < n; k++){
        int Sum = 0;
        v.clear();
        x.clear();

        for(int i = 0; i < m; i++){
            int tmp = 0;
            for(int j = k; j < n; j++){
                tmp += U[j][i] * R[j];
            }

            v.push_back(tmp);
            Sum += tmp;
        }

        // find max value
        int Max = 0, ind = -1;
        for(int i = 0; i < m; i++){
            if(v[i] > Max){
                Max = v[i];
                ind = i;
            }
        }

        // for(int i = 0; i < m; i++){
        //     x.push_back(v[i] * B[i] / Sum);
        // }

        ans[k][ind] = min(A[k], B[ind]);
        A[k] -= ans[k][ind];
        B[ind] -= ans[k][ind];
        // for(int i = 0; i < m; i++){
        //     ans[k][i] = min(x[i], A[k]);
        //     A[k] -= ans[k][i];
        //     B[i] -= ans[k][i];
        // }
    }
}

int main(){
    nono_is_handsome
    
    init();

    if(n < 25 && m < 300)   solve1();
    else    solve2();
    // solve2();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j];
            if(j != m - 1)  cout << ",";
        }
        cout << "\n";
    }

    // cout << getVal() << "\n";
}