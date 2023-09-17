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