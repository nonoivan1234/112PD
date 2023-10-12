#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
const int N = 25;
const int M = 505;
int n, m, R[N], A[N], B[M], D[M][M], ans[N][M], SumOfStation[M];
double SumOfVal[M];
vector<int> S[M][4];
double Q[4], U[N][M];
const double TRY = 500;
int valBest = 0;
int ansBest[N][M];
vector<pair<int, int>> v;

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

double val(double now, int i, int j){
    double ret = now, tmp = U[i][j] + Q[0];
    for(int k = 0; k < 4; k++){
        for(auto l : S[j][k]){
            tmp -= Q[k] * SumOfStation[l];
        }
    }
    ret += tmp * R[i] * 24;
    for(int k = 0; k < 4; k++){
        for(auto l : S[j][k]){
            ret -= Q[k] * 24 * SumOfVal[l];
        }
    }

    return ret;
}

double getVal(){
    double ret = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            double tmp = U[i][j] + Q[0];
            for(int k = 0; k < 4; k++){
                for(auto l : S[j][k]){
                    for(int t = 0; t < n; t++){
                        tmp -= Q[k] * ansBest[t][l];
                    }
                }
            }

            ret += tmp * R[i] * ansBest[i][j] * 24;
        }
    }

    return ret;
}

void solve1(){
    double now = 0;
    while(1){
        double tmp;
        int x = -1, y = -1;
        double tp = now;
        for(int i = 0; i < n; i++){
            if(A[i] == 0)   continue;
            for(int j = 0; j < m; j++){
                if(B[j] == 0)   continue;
                SumOfStation[j]++;
                tmp = val(tp, i, j);
                if(tmp >= now){
                    now = tmp;
                    x = i, y = j;
                }
                SumOfStation[j]--;
            }
        }

        if(x == -1) break;
    
        ans[x][y]++;
        A[x]--;
        B[y]--;
        SumOfStation[y]++;
        SumOfVal[y] += R[x];
        
        if(now > valBest){
            valBest = now;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    ansBest[i][j] = ans[i][j];
        }
    }
    
    // cout << now << "\n";
}


int main(){
    nono_is_handsome
    
    init();

    solve1();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ansBest[i][j];
            if(j != m - 1)  cout << ",";
        }
        cout << "\n";
    }

    // cout << getVal() << "\n";
}