void checkCorrectness(int stationNum, int initPass, int maxPass, const int passenger[][MAX_STATION_NUM], int ret[]){
    int now = initPass;
    
    for(int i=1;i<stationNum;i++){
        bool ok1=0, ok2=0;
        if (now<passenger[1][i])   ok1=1;

        now += passenger[0][i]-passenger[1][i];
        if (now>maxPass)  ok2=1;

        if (ok1 && ok2) {
            ret[0] = i;
            ret[1] = 3;
            return;
        }
        if (ok1)    {
            ret[0] = i;
            ret[1] = 1;
            return;
        }
        if (ok2)    {
            ret[0] = i;
            ret[1] = 2;
            return;
        }
    }
}