void checkCorrectness(int stationNum, int initPass, int maxPass, const int** passenger, int& wrongStationID, int& wrongType){
    int currentPass = initPass;
    for(int i = 0; i < stationNum - 1; i++){
        bool flag1 = 0, flag2 = 0;
        currentPass -= passenger[1][i];
        if(currentPass < 0)        flag2 = 1;
        currentPass += passenger[0][i];
        if(currentPass > maxPass)   flag1 = 1;

        if(flag1 && flag2){
            wrongStationID = i + 1;
            wrongType = 3;
            return;
        }
        else if(flag1){
            wrongStationID = i + 1;
            wrongType = 2;
            return;
        }
        else if(flag2){
            wrongStationID = i + 1;
            wrongType = 1;
            return;
        }
    }
    wrongStationID = 0;
    wrongType = 0;
    return;
}