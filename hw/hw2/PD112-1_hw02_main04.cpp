#include <iostream>
using namespace std;
const int MAX_STATION_NUM = 20;

// This is the prototype of the function you need to complete.
void checkCorrectness(int stationNum, int initPass, int maxPass, const int passenger[][MAX_STATION_NUM], int ret[]);

int main(){
    int stationNum = 0, initPass = 0, maxPass = 0;
    int passenger[2][MAX_STATION_NUM] = {0};
    int ret[2] = {0};
    cin >> stationNum >> initPass >> maxPass;
    // Please note that in the two loops below,
    // the boarding and alighting counts for the first stop are placed in the array's first element rather than the zeroth element.
    // The same applies to the subsequent stops.
    for(int i = 1; i < stationNum; i++){
        cin >> passenger[0][i];
    }
    for(int i = 1; i < stationNum; i++){
        cin >> passenger[1][i];
    }

    checkCorrectness(stationNum, initPass, maxPass, passenger, ret);

    if(ret[0] == 0){
        cout << ret[0];
    }
    else{
        if(ret[1] == 1){
            cout << ret[0] << ",N";
        }
        else if(ret[1] == 2){
            cout << ret[0] << ",C";
        }
        else if(ret[1] == 3){
            cout << ret[0] << ",B";
        }
    }

    return 0;
}

// After you upload the function you've written, PDOGS will paste the code you uploaded HERE and then compile it.
