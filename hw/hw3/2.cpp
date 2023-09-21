#include <iostream>
using namespace std;
const int MAX_ITEM_CNT = 105;

// This is the prototype of the function that you should complete
void knapsack(int itemCnt, int capacity, const int weight[], const int value[], const int bring[], int ret[]);

int main()
{
    int itemCnt = 0, capacity = 0, testCase = 0, cnt = 0, mx = 0;
    cin >> itemCnt >> capacity >> testCase;

    int weight[MAX_ITEM_CNT] = {0};
    int value[MAX_ITEM_CNT] = {0};
    
    for(int i = 0; i < itemCnt; i++)
        cin >> weight[i];
    for(int i = 0; i < itemCnt; i++)
        cin >> value[i];

    while(testCase--){
        int bring[MAX_ITEM_CNT] = {0};
        int ret[2] = {0};
        int n = 0, tmp = 0;
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> tmp;
            bring[i] = tmp-1;
        }
        
        knapsack(n, capacity, weight, value, bring, ret);
        
        if(ret[0] != -1){
            cnt++;
            mx = max(mx, ret[1]);
        }
    }

    cout << cnt << "," << mx;
    
    return 0;
}

// PDOGS will copy and paste your codes here before compilation
void knapsack(int itemCnt, int capacity, const int weight[], const int value[], const int bring[], int ret[]){
    int w=0, v=0;
    for(int i=0;i<itemCnt;i++){
        w += weight[bring[i]];
        v += value[bring[i]];
    }

    if(w>capacity){
        ret[0]=-1;
        return;
    }
    ret[0]=w;
    ret[1]=v;

    return;
}