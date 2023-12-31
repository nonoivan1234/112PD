#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
const int N = 25;
const int M = 505;
int n, m, D[M][M], ans[N][M], R[N], A[N], B[M], SumOfStation[M];
double SumOfVal[M]; // SumOfVal[j] = sum_{i} R[i] * ans[i][j]
vector<int> S[M][5];    // S[i][k] = {j | D[i][j] = k}
double Q[4], U[N][M];

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
}

double getVal(){    // getVal in stupid way i.e. for debug
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

            ret += tmp * 24.0 * R[i] * ans[i][j];
        }
    }

    return ret;
}

void solve1(){
    double mx = 0;
    while(1){
        double tmp;
        int x = -1, y = -1;
        double now = mx;
        for(int i = 0; i < n; i++){
            if(A[i] == 0)   continue;
            for(int j = 0; j < m; j++){
                if(B[j] == 0)   continue;
                ans[i][j]++;
                tmp = getVal();
                if(tmp > mx){
                    mx = tmp;
                    x = i, y = j;
                }
                ans[i][j]--;
            }
        }

        if(x == -1) break;  // if no station can provide more value
    
        ans[x][y]++;
        A[x]--;
        B[y]--;
        SumOfStation[y]++;
        SumOfVal[y] += R[x];
    }
    
    // cout << mx << "\n";
}


int main(){
    nono_is_handsome
    
    init();

    solve1();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j];
            if(j != m - 1)  cout << ",";
        }
        cout << "\n";
    }

    // cout << getVal() << "\n";
}