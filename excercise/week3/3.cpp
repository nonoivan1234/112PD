#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

bool BinarySearch(int arr[], int n, int t){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(arr[mid] == t) return true;
        else if(arr[mid] > t) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}

signed main(){
    nono_is_handsome

    int n, t;
    cin >> n >> t;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << BinarySearch(arr, n, t) << '\n';
}