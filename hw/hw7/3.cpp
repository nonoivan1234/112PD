#include<iostream>
#include<cstring>
using namespace std;

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
    bool updateSalesQty(char* productName, int currentSale);
};

Product::Product(char* n, int p, int c, int sq){
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    price = p;
    cost = c;
    salesQty = sq;
}

Product::~Product(){
    delete [] name;
    name = nullptr;
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

bool Product::updateSalesQty(char* productname, int currentSale){
    if(strcmp(name, productname) == 0){
        salesQty += currentSale;
        return true;
    }
    return false;
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

int main(){
    int productCnt = 0, saleCnt = 0, searchCnt = 0;
    cin >> productCnt >> saleCnt >> searchCnt;  cin.ignore();

    Product** products = new Product* [productCnt];
    int ansList[searchCnt] = {0}, ansIdx = 0;


    for(int i = 0; i < productCnt; i++){
        char* name = new char[500];
        cin.getline(name, 500, ',');

        int price, cost, salesQty;
        cin  >> price >> cost >> salesQty;  cin.ignore();
        products[i] = new Product(name, price, cost, salesQty);

        delete [] name;
        name = nullptr;
    }

    for(int i = 0; i < saleCnt + searchCnt; i++){
        char oper;
        cin >> oper;
        if(oper == 'S'){
            cin.ignore();
            char* productName = new char[500];
            int currentSale = 0;

            cin.getline(productName, 500, ',');
            cin >> currentSale; cin.ignore();

            for(int i = 0; i < productCnt; i++){
                if(products[i]->updateSalesQty(productName, currentSale))
                    break;
            }

            delete [] productName;
            productName = nullptr;
        }
        else{
            int criterion, num;
            cin >> criterion >> num;    cin.ignore();

            MySort(products, productCnt, criterion);

            int cur = 0;
            for(int i = 0; i < num; i++){
                cur += products[i]->profit();
            }
            ansList[ansIdx++] = cur;
        }
    }

    cout << ansList[0];
    for(int i = 1; i < ansIdx; i++)
        cout << "," << ansList[i];
    cout << '\n';

    for(int i = 0; i < productCnt; i++){
        products[i]->~Product();
    }
    delete [] products;
    products = nullptr;
    
    return 0;
}