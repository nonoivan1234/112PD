#include<iostream>
using namespace std;

int main(){
    int StopNum=0, TotalPeople=0;   // 站數、總人數
    cin>>StopNum>>TotalPeople;  //  輸入站數、總人數

    int GettingOn[StopNum-1]={0}, GettingOff[StopNum-1]={0};    //  每站上下車人數

    // 輸入每站上下車人數
    for(int i=0;i<StopNum-1;i++)    cin>>GettingOn[i];
    for(int i=0;i<StopNum-1;i++)    cin>>GettingOff[i];

    int CurrentPeople = TotalPeople;    //  一開始車上的人數
    
    //  MaxDiff 為每站上下車人數最大差值，又 0 <= GettingOff[i], GettingOn[i] <= 50
    //  所以最大差值之最小值為 -50，故將其初始化為 -50
    int MaxDiff = -50;

    for(int i=0;i<StopNum-1;i++){
        CurrentPeople += GettingOn[i];  //  每站上車人數
        CurrentPeople -= GettingOff[i]; //  每站下車人數
    
        int Diff = GettingOn[i] - GettingOff[i];    // 此站上下車人數差值
        if (Diff > MaxDiff) MaxDiff = Diff; //  若此站差值大於最大差值，則更新最大差值
    }

    cout<<CurrentPeople<<','<<MaxDiff<<'\n';   //  輸出最後車上的人數與最大差值

    return 0;   //  結束程式
}