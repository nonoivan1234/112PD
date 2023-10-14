#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
const int N = 25;
const int M = 505;
int n, m, R[N], A[N], B[M], D[M][M], ans[N][M], SumOfStation[M];
double SumOfVal[M]; // SumOfVal[j] = sum_{i} R[i] * ans[i][j]
vector<int> S[M][5];    // S[i][k] = {j | D[i][j] = k}
double Q[4], U[N][M];
double MAX = 0;
int ansBest[N][M];
const double DIFF = 200;

void solve1(double now, int i, int j);
void solve2();

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
            else D[i][j] = 4;

            S[i][D[i][j]].push_back(j);
        }
    }

    solve1(0, -1, -1);
}

double val(double now, int i, int j){   // getVal in optimized way
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

void solve1(double now, int i, int j){
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    double mx = now;
    int x = -1, y = -1;
    for(int k = 0; k < n; k++){
        if(A[k] == 0)   continue;
        for(int l = 0; l < m; l++){
            if(B[l] == 0)   continue;
            SumOfStation[l]++;
            double tmp = val(now, k, l);
            if(tmp > mx){
                mx = tmp;
                x = k, y = l;
            }
            SumOfStation[l]--;
        }
    }
    if(mx > MAX){
        MAX = mx;
        ans[x][y]++;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ansBest[i][j] = ans[i][j];
            }
        }
        ans[x][y]--;
    }

    if(x == -1) return;

    for(int k = 0; k < n; k++){
        if(A[k] == 0)   continue;
        for(int l = 0; l < m; l++){
            if(B[l] == 0)   continue;
            SumOfStation[l]++;
            double tmp = val(now, k, l);
            if(mx - tmp < DIFF){
                A[k]--, B[l]--;
                ans[k][l]++;
                SumOfVal[l] += R[k];

                solve1(tmp, k, l);

                A[k]++, B[l]++;
                ans[k][l]--;
                SumOfVal[l] -= R[k];
            }
            SumOfStation[l]--;
        }
    }
}

double getVal(int ansBest[][M]){    // getVal in stupid way i.e. for debug
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

            ret += tmp * 24.0 * R[i] * ansBest[i][j];
        }
    }

    return ret;
}


int main(){
    nono_is_handsome
    
    init();

    solve1(0, -1, -1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ansBest[i][j];
            if(j != m - 1)  cout << ",";
        }
        cout << "\n";
    }

    // cout << MAX << "\n";
    cout << getVal(ansBest) << "\n";
}