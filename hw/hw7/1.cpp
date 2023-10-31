#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

class Product{
private:
    char* name;
    int price;
    int cost;
    int salesQty;
public:
    Product(char* n, int p, int c, int sq);
    ~Product();
    bool isInFrontOf(const Product& prod, int criterion);
    int profit();
};

Product::Product(char* n, int p, int c, int sq){
    name = n;
    price = p;
    cost = c;
    salesQty = sq;
}

Product::~Product(){
    delete name;
}

bool Product::isInFrontOf(const Product& prod, int criterion){
    if(criterion == 1){
        if(price == prod.price)
            return strcmp(name, prod.name) > 0;
        return price < prod.price;
    }
    else if(criterion == 2){
        if(cost == prod.cost)
            return strcmp(name, prod.name) > 0;
        return cost < prod.cost;
    }
    else if(criterion == 3){
        if(price - cost == prod.price - prod.cost)
            return strcmp(name, prod.name) > 0;
        return price - cost < prod.price - prod.cost;
    }
    else if(criterion == 4){
        if(salesQty == prod.salesQty)
            return strcmp(name, prod.name) > 0;
        return salesQty < prod.salesQty;
    }
    else if(criterion == 5){
        if(salesQty * price == prod.salesQty * prod.price)
            return strcmp(name, prod.name) > 0;
        return salesQty * price < prod.salesQty * prod.price;
    }
    else if(criterion == 6){
        if(salesQty * (price - cost) == prod.salesQty * (prod.price - prod.cost))
            return strcmp(name, prod.name) > 0;
        return salesQty * (price - cost) < prod.salesQty * (prod.price - prod.cost);
    }
}

int Product::profit(){
    return salesQty * (price - cost);
}

void MySort(Product** products, int productCnt, int criterion){
    for(int i = 0; i < productCnt; i++){
        for(int j = i + 1; j < productCnt; j++){
            if(products[i]->isInFrontOf(*products[j], criterion)){
                Product* temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
}

signed main(){
    nono_is_handsome
    
    int productCnt = 0;
    cin >> productCnt;
    Product** products = new Product*[productCnt];

    for(int i = 0; i < productCnt; i++){
        char* name = new char[100];
        char c;
        while(cin >> c && c != ',')
            name[strlen(name)] = c;
        name[strlen(name)] = '\0';

        int price, cost, salesQty;
        cin  >> price >> cost >> salesQty;
        products[i] = new Product(name, price, cost, salesQty);
    }

    int criterion, num;
    cin >> criterion >> num;
    MySort(products, productCnt, criterion);

    int ans = 0;
    for(int i = 0; i < num; i++){
        ans += products[i]->profit();
        // cout << products[i]->price << " " << products[i]->cost << '\n';
        // cout << products[i]->salesQty * products[i]->price << "\n";
    }

    cout << ans << '\n';
}