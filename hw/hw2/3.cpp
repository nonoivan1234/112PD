#include <iostream>
using namespace std;
const int MAX_STATION_NUM = 20;
const int MAX_BUS_NUM = 50;

int checkCorrectness(int stationNum, int initPass, int maxPass, const int getInPass[], const int getOutPass[]);

int main(){
    int stationNum = 0, busNum = 0, maxPass = 0;
    cin >> stationNum >> busNum >> maxPass;

    int initPass[MAX_BUS_NUM] = {0};
    int getInPass[MAX_BUS_NUM][MAX_STATION_NUM] = {0};
    int getOutPass[MAX_BUS_NUM][MAX_STATION_NUM] = {0};

    int Cnt1=0, Cnt2=0, Cnt3=0;

    for(int i=0;i<busNum;i++){
        cin>>initPass[i];
        for(int j=1;j<stationNum;j++)   cin>>getInPass[i][j];
        for(int j=1;j<stationNum;j++)   cin>>getOutPass[i][j];

        int ret = checkCorrectness(stationNum, initPass[i], maxPass, getInPass[i], getOutPass[i]);


        if(ret != 0)
        {
            if(ret - 3 * stationNum > 0){
                Cnt3++;
            }
            else if(ret - 2 * stationNum > 0){
                Cnt2++;
            }
            else{
                Cnt1++;
            }
        }
    }

    cout << Cnt1 << "," << Cnt2 << "," << Cnt3;


    return 0;
}

int checkCorrectness(int stationNum , int initPass , int maxPass , const int getInPass[], const int getOutPass[]){
    int now = initPass;
    
    for(int i=1;i<stationNum;i++){
        bool ok1=0, ok2=0;
        if (now<getOutPass[i])   ok1=1;

        now += getInPass[i]-getOutPass[i];
        if (now>maxPass)  ok2=1;

        if (ok1 && ok2) return i+3*stationNum;
        if (ok1)    return i+stationNum;
        if (ok2)    return i+2*stationNum;
    }

    return 0;
}