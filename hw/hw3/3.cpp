#include<iostream>
using namespace std;
const int MAX_ITEM_CNT = 105;

int main(){
    int itemCnt = 0, capacity = 0;
    cin >> itemCnt >> capacity;

    int weight[MAX_ITEM_CNT] = {0};
    int value[MAX_ITEM_CNT] = {0};
    int bring[MAX_ITEM_CNT] = {0};  // bring: the array of the index of the items that we bring
    bool brought[MAX_ITEM_CNT] = {0};   // brought: the array of the items that wether we bring or not
                                        // 0: we don't bring
                                        // 1: we bring

    // input the weight and value
    for(int i = 1; i <= itemCnt; i++)    cin >> weight[i];
    for(int i = 1; i <= itemCnt; i++)    cin >> value[i];

    int W = 0, V = 0, indBring = 0; // W: the total weight of the items that we bring
                                    // V: the total value of the items that we bring
                                    // indBring: the current index of the array bring
    
    while(true){
        int valMax = 0, indMax = -1;    // valMax: the maximum value of the items that we can take
                                    // indMax: the index of the item that we can take to get the maximum value (init as -1 to check if we can find any item that we can take)
        
        // find the item that we can take to get the maximum value iteratively
        for(int i = 1; i <= itemCnt; i++){
            if(brought[i] == 0 && W+weight[i] <= capacity && value[i] > valMax){
                valMax = value[i];
                indMax = i;
            }
        }

        // if we cannot find any item that we can take, then we stop the loop
        if(indMax == -1)  break;

        // take the item that we can take to get the maximum value
        bring[indBring++] = indMax;
        W += weight[indMax];
        V += value[indMax];

        // set the value of the item that we take to 1 so that we won't take it again
        brought[indMax] = 1;
    }

    if(indBring == 0) cout << ";0";
    else{
        for(int i = 0; i < indBring; i++){
            cout << bring[i];
            if(i != indBring-1)   cout << ",";
        }
        cout << ";" << V;
    }

    return 0;
}