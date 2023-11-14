#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string toDollarNumber(int value){
    string a = "";
    int tmp = -1;
    while(value > 0){
        a += (value % 10) + '0';
        value /= 10;
        tmp = (tmp + 1) % 3;
        if(tmp == 2){
            a += ',';
        }
    }
    if(a[a.length() - 1] == ','){
        a = a.substr(0, a.length() - 1);
    }
    a += "$";

    reverse(a.begin(), a.end());
    return a;
}

int main(){
    int n;
    cin >> n;

    cout << toDollarNumber(n) << endl;
}