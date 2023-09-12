#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

int mostHighGrades(int threshold, int assignmentCnt, int gradeCnt, int grades[ ][50]);

int highGradeCnt(int threshold, int gradeCnt, int grades[ ]){
    int cnt = 0;
    for(int i = 0; i < gradeCnt; i++){
        if(grades[i] >= threshold){
            cnt++;
        }
    }
    return cnt;
}

int mostHighGrades(int threshold, int assignmentCnt, int gradeCnt, int grades[ ][50]){
    int hgc = -1;

    int ID=-1;
    for(int i = 0; i < gradeCnt; i++){
        int cnt = highGradeCnt(threshold, assignmentCnt, grades[i]);
        if (cnt > hgc){
            hgc = cnt;
            ID = i+1;
        }
    }

    return ID;
}

signed main(){
    nono_is_handsome

    int m, n, t;
    cin >> m >> n >> t;

    int grades[m][50];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grades[i][j];
        }
    }

    cout << mostHighGrades(t, n, m, grades) << '\n';

    return 0;
}