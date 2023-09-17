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

    int NumOfType1=0, NumOfType2=0, NumOfType3=0;

    for(int i=0;i<busNum;i++){
        cin>>initPass[i];

        // Please note that in the two loops below,
        // the boarding and alighting counts for the first stop are placed in the array's first element rather than the zeroth element.
        // The same applies to the subsequent stops.
        for(int j=1;j<stationNum;j++)   cin>>getInPass[i][j];
        for(int j=1;j<stationNum;j++)   cin>>getOutPass[i][j];

        int ret = checkCorrectness(stationNum, initPass[i], maxPass, getInPass[i], getOutPass[i]);


        if(ret != 0)
        {
            if(ret - 3 * stationNum > 0){
                NumOfType3++;
            }
            else if(ret - 2 * stationNum > 0){
                NumOfType2++;
            }
            else{
                NumOfType1++;
            }
        }
    }

    cout << NumOfType1 << "," << NumOfType2 << "," << NumOfType3;


    return 0;
}

int checkCorrectness(int stationNum , int initPass , int maxPass , const int getInPass[], const int getOutPass[]){
    int CurrentPeople = initPass;
    
    for(int i=1;i<stationNum;i++){
        bool CheckType1=0, CheckType2=0;
        if (CurrentPeople < getOutPass[i])   CheckType1=1;

        CurrentPeople += getInPass[i]-getOutPass[i];
        if (CurrentPeople > maxPass)  CheckType2=1;

        bool CheckType3 = CheckType1&&CheckType2;   // Both CheckType1 and CheckType2 are true

        if (CheckType1 && !CheckType2)     return i+stationNum; // Return when only CheckType1 is true
        if (CheckType2 && !CheckType1)     return i+2*stationNum;   // Return when only CheckType2 is true
        if (CheckType3)     return i+3*stationNum;  // Return when both CheckType1 and CheckType2 are true
    }

    return 0;
}