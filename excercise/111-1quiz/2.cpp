#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)  cin >> arr[i];

    int increasing = -1, decreasing = -1;
    for(int i = 1; i < n; i++){
        if(arr[i] <= arr[i - 1]){
            increasing = i - 1;
            break;
        }
    }

    for(int i = 1; i < n; i++){
        if(arr[i] >= arr[i - 1]){
            decreasing = i;
            break;
        }
    }

    // cout << increasing << " " << decreasing << endl;

    if(increasing == -1){
        cout << 1 << "\n";
    }
    else if(decreasing == -1){
        cout << 2 << "\n";
    }
    else{
        decreasing = -1;
        for(int i = n-1; i > 1 ; i--){
            if(arr[i] >= arr[i - 1]){
                decreasing = i;
                break;
            }
        }
        // cout << increasing << " " << decreasing << endl;

        if(increasing != decreasing)    cout << 4 << "\n";
        else cout << 3 << "\n";
    }

}