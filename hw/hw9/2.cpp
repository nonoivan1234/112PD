#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class CurrencyString
{
private:
    int num;
public:
    CurrencyString() : num(0) {}
    CurrencyString(int n) : num(n) {}
    string getFormattedStr(bool commaSep, bool minusSign);
};

string CurrencyString::getFormattedStr(bool commaSep, bool minusSign)
{
    string str = "";
    if(!minusSign && num < 0) str += ")";

    char c = commaSep ? ',' : '.';

    string numStr = to_string(abs(num));
    reverse(numStr.begin(), numStr.end());

    int cnt = 0;
    for(int i = 0; i < numStr.size(); i++){
        if(cnt == 3){
            str += c;
            cnt = 0;
        }
        str += numStr[i];
        cnt++;
    }

    str += "$";
    if(!minusSign && num < 0) str += "(";
    else if(minusSign && num < 0) str += "-";
    reverse(str.begin(), str.end());


    return str;
}

int main(){
    int n;  cin >> n;
    CurrencyString ans(n);

    bool commaSep, minusSign;
    cin >> commaSep >> minusSign;

    cout << ans.getFormattedStr(commaSep, minusSign) << endl;
}