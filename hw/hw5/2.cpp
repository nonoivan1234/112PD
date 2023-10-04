#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 1e5 + 10;

signed main(){
    nono_is_handsome

    char c[N];
    cin.getline(c, N);

    char num[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int ans[N], ind = 0, j = 0;
    int n = strlen(c);

    char tmp[N];
    for(int i = 0; i < n; i++){
        if(c[i] == ','){
            for(int k = 0; k < 10; k++){
                if(strcmp(tmp, num[k]) == 0){
                    ans[ind++] = k;
                    break;
                }
            }
            for(int k = 0; k < j; k++){
                tmp[k] = '\0';
            }
            j = 0;
        }
        else{
            tmp[j++] = c[i];
        }
    }

    for(int k = 0; k < 10; k++){
        if(strcmp(tmp, num[k]) == 0){
            ans[ind++] = k;
            break;
        }
    }


    cout << ans[0];
    for(int i = 1; i < ind; i++){
        cout << "," << ans[i];
    }
    cout << "\n";
}