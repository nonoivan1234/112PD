void knapsack(int itemCnt, int capacity, const int weight[], const int value[], const bool bring[], int ret[]){
    int w=0, v=0;
    for(int i=0;i<itemCnt;i++){
        if(bring[i]){
            w+=weight[i];
            v+=value[i];
        }
    }

    if(w>capacity){
        ret[0]=-1;
        return;
    }
    ret[0]=w;
    ret[1]=v;

    return;
}