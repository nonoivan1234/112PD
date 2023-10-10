#include<iostream>
#include<vector>
#include<random>
#include<chrono>
using namespace std;
const int N = 500;
const int M = 1000;
int TypeNum, StationNum;
vector<int> A(N), B(M);
vector<double> R(N);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
    double DecreseRate[4];
    cin >> TypeNum >> StationNum;
    for(int i = 0; i < 4; i++)    cin >> DecreseRate[i];

    double tmp;
    for(int i = 0; i < TypeNum; i++)    cin >> tmp, R[i] = tmp * 24;
    for(int i = 0; i < TypeNum; i++)    cin >> A[i];
    for(int i = 0; i < StationNum; i++) cin >> B[i];


    double U[N][M];
    for(int i = 0; i < TypeNum; i++){
        for(int j = 0; j < StationNum; j++){
            cin >> U[i][j];
        }
    }
        

    int D[M][M];
    for(int i = 0; i < StationNum; i++){
        for(int j = 0; j < StationNum; j++){
            int dis;
            cin >> dis;
            if(dis > 500)   D[i][j] = D[j][i] = 3;
            else if(dis > 300)  D[i][j] = D[j][i] = 2;
            else if(dis > 1)  D[i][j] = D[j][i] = 1;
            else    D[i][j] = D[j][i] = 0;
        }
    }

    // if(TypeNum > 15 || StationNum > 30) throw(1);

    vector<vector<vector<int>>> S(StationNum, vector<vector<int>>(4));
    for(int i = 0; i < StationNum; i++){
        for(int j = 0; j < StationNum; j++){
            S[i][D[i][j]].push_back(j);
        }
    }

    vector<vector<int>> ans(N, vector<int>(M));
    vector<int> v;
    vector<int> x(M, 0);

    for(int k = 0; k < TypeNum; k++){
        int Sum = 0;
        v.clear();
        x.clear();

        for(int i = 0; i < StationNum; i++){
            int tmp = 0;
            for(int j = k; j < TypeNum; j++){
                tmp += U[j][i] * R[j];
            }

            v.push_back(tmp);
            Sum += tmp;
        }

        // find max value
        // int Max = 0, ind = -1;
        // for(int i = 0; i < StationNum; i++){
        //     if(v[i] > Max){
        //         Max = v[i];
        //         ind = i;
        //     }
        // }

        for(int i = 0; i < StationNum; i++){
            x.push_back(v[i] * B[i] / Sum);
        }

        // ans[k][ind] = min(A[k], B[ind]);
        // A[k] -= ans[k][ind];
        // B[ind] -= ans[k][ind];
        for(int i = 0; i < StationNum; i++){
            ans[k][i] = min(x[i], A[k]);
            A[k] -= ans[k][i];
            B[i] -= ans[k][i];
        }
    }

    // randomly distribute the rest
    for(int i = TypeNum - 1; i >= 0; i--){
        for(int j = StationNum - 1; j >= 0; j--){
            if(ans[i][j] != 0)  continue;
            int tmp = rng() % (A[i] + 1);
            int tmp1 = rng() % (B[j] + 1);
            ans[i][j] = min(tmp, tmp1);

            A[i] -= ans[i][j];
            B[j] -= ans[i][j];
        }
    }

    for(int i = 0; i < TypeNum; i++){
        int tmp = min(A[i], B[0]);
        ans[i][0] += tmp;
        A[i] -= tmp;
        B[0] -= tmp;
    }

    // ans = {{5, 3, 1}, {1, 3, 1}};
    // int val = 0;
    // for(int i = 0; i < TypeNum; i++){
    //     for(int j = 0; j < StationNum; j++){
    //         if(ans[i][j] == 0)  continue;
    //         double tmp = U[i][j] + DecreseRate[0];
    //         for(int k = 0; k < 4; k++){
    //             for(int l = 0; l < S[j][k].size(); l++){
    //                 if(S[j][k][l] == j) continue;
    //                 tmp -= ans[i][S[j][k][l]] * DecreseRate[k];
    //             }
    //         }
    //         val += tmp * ans[i][j] * R[i];
    //     }
    // }
    // cout << val << "\n";
    // if(val < 0) throw(1);

    for(int i = 0; i < TypeNum; i++){
        for(int j = 0; j < StationNum; j++){
            cout << ans[i][j];
            if(j != StationNum - 1) cout << ",";
        }
        cout << "\n";
    }
}

int main(){
    
    try{
        solve();
    }catch(int e){
        for(int i = 0; i < TypeNum; i++){
            for(int j = 0; j < StationNum; j++){
                int tmp = rng() % (A[i] + 1);
                int tmp1 = rng() % (B[j] + 1);
                cout << min(tmp, tmp1);

                A[i] -= tmp;
                B[j] -= tmp;
                if(j != StationNum - 1) cout << ",";
            }
            cout << "\n";
        }
        // for(int i = 0; i < TypeNum; i++){
        //     for(int j = 0; j < StationNum; j++){
        //         cout << 0;
        //         if(j != StationNum - 1) cout << ",";
        //     }
        //     cout << "\n";
        // }
    }
    

    return 0;
}