#include <iostream>
using namespace std;
const int MAX_STATION_NUM = 20;

// This is the prototype of the function you need to complete.
int checkCorrectness(int stationNum, int initPass, int maxPass, const int getInPass[], const int getOutPass[]);

int main(){
    int stationNum = 0, initPass = 0, maxPass = 0;
    int getInPass[MAX_STATION_NUM] = {0};
    int getOutPass[MAX_STATION_NUM] = {0};

    cin >> stationNum >> initPass >> maxPass;
    // Please note that in the two loops below,
    // the boarding and alighting counts for the first stop are placed in the array's first element rather than the zeroth element.
    // The same applies to the subsequent stops.
    for(int i = 1; i < stationNum; i++){
        cin >> getInPass[i];
    }
    for(int i = 1; i < stationNum; i++){
        cin >> getOutPass[i];
    }

    int ret = checkCorrectness(stationNum, initPass, maxPass, getInPass, getOutPass);

    if(ret == 0){
        cout << ret;
    }
    else
    {
        if(ret - 3 * stationNum > 0){
            cout << ret - 3 * stationNum << ",B";
        }
        else if(ret - 2 * stationNum > 0){
            cout << ret - 2 * stationNum << ",C";
        }
        else{
            cout << ret - stationNum << ",N";
        }
    }

    return 0;
}

// After you upload the function you've written, PDOGS will paste the code you uploaded HERE and then compile it.

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