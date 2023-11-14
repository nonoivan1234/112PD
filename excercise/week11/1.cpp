#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    char pun[] = {'.', ',', '!', '?', ':', ';'};
    int cnt = 0;
    while(cin >> s){
        int n = s.length();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 6; j++){
                if(s[i] == pun[j]){
                    cnt++;
                    break;
                }
            }
        }

    }
    cout << cnt << endl;
}