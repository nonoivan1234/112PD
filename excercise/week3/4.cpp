#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

void insertionSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int key = arr[i];
        // int j = i - 1;
        // while(j >= 0 && arr[j] > key){
        //     arr[j + 1] = arr[j];
        //     j--;
        // }
        // arr[j + 1] = key;

        for(int j = i-1; j >= 0 && arr[j] > key; j--)   swap(arr[j + 1], arr[j]);
    }

    return;
}

signed main(){
    nono_is_handsome

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    insertionSort(arr, n);

    cout<<arr[0];
    for(int i = 1; i < n; i++) cout << ',' << arr[i];
}