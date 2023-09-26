#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

void insertionSort(int *arr, int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

signed main(){
    nono_is_handsome

    int nodeCnt = 0;
    int** neighbors = nullptr;
    int* degrees = nullptr;
    cin >> nodeCnt;

    neighbors = new int*[nodeCnt];
    degrees = new int[nodeCnt];
    for(int i = 0; i < nodeCnt; i++){
        cin >> degrees[i];
        neighbors[i] = new int[degrees[i]];
        for(int j = 0; j < degrees[i]; j++){
            cin >> neighbors[i][j];
        }
    }

    for(int i = 0; i < nodeCnt; i++){
        int ind = 0;
        insertionSort(neighbors[i], degrees[i]);
        for(int j = 0;j < degrees[i]; j++){
            while(ind < neighbors[i][j]){
                cout << "0";
                ind++;
                if(ind < nodeCnt) cout << " ";
            }
            cout << "1";
            ind++;
            if(ind < nodeCnt) cout << " ";
        }
        while(ind < nodeCnt){
            cout << "0";
            ind++;
            if(ind < nodeCnt) cout << " ";
        }
        cout << "\n";
    }

    for(int i = 0; i < nodeCnt; i++){
        delete[] neighbors[i];
    }
    delete[] neighbors;
    delete[] degrees;

    return 0;
}