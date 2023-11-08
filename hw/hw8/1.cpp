#include<iostream>
#include<cstring>
using namespace std;

class Item{
private:
    char* name;
    int materialCost;
public:
    Item(char* n, int mc);
    ~Item();
    int getMaterialCost();
    bool isThisItem(char* n);
};

class Product{
private:
    char* name;
    int price;
    int cost;
    int salesQty;
    int itemCnt;
    Item** itemList;
public:
    Product(char* n, int p, int c, int sq, int ic);
    ~Product();
    bool isInFrontOf(const Product& prod, int criterion);
    int profit() const; // 1. 
    void addItem(Item* itemPtr);
    bool isThisProduct(char* n);
    int getCost() const;    // 2.
};

int Item::getMaterialCost(){
    return materialCost;
}

bool Item::isThisItem(char* n){
    return strcmp(name, n) == 0;
}

Item::Item(char* n, int mc){
    name = n;
    materialCost = mc;
}

Item::~Item(){
    delete [] name;
    name = nullptr;
}

bool Product::isThisProduct(char* n){
    return strcmp(name, n) == 0;
}

Product::Product(char* n, int p, int c, int sq, int ic){
    name = n;
    price = p;
    cost = c;
    salesQty = sq;
    itemCnt = ic;
    itemList = new Item*[itemCnt];
}

void Product::addItem(Item* itemPtr){
    for(int i = 0; i < itemCnt; i++){
        if(itemList[i] == nullptr){
            itemList[i] = itemPtr;
            return;
        }
    }
}

Product::~Product(){
    delete [] name;
    name = nullptr;

    for(int i = 0; i < itemCnt; i++){
        itemList[i] = nullptr;
    }
    delete [] itemList;
    itemList = nullptr;
}

bool Product::isInFrontOf(const Product& prod, int criterion){
    if(criterion == 1){
        if(price == prod.price)
            return strcmp(name, prod.name) > 0;
        return price < prod.price;
    }
    else if(criterion == 2){
        if(getCost() == prod.getCost())
            return strcmp(name, prod.name) > 0;
        return getCost() < prod.getCost();
    }
    else if(criterion == 3){
        if(price - getCost() == prod.price - prod.getCost())
            return strcmp(name, prod.name) > 0;
        return price - getCost() < prod.price - prod.getCost();
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
        if(profit() == prod.profit())
            return strcmp(name, prod.name) > 0;
        return profit() < prod.profit();
    }
}

int Product::profit() const{
    return (price - getCost()) * salesQty;
}

int Product::getCost() const{
    int totalCost = cost;
    for(int i = 0; i < itemCnt; i++){
        totalCost += itemList[i]->getMaterialCost();
    }

    return totalCost;
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
    int productCnt = 0, itemTotalCnt = 0, relationships = 0;
    cin >> productCnt >> itemTotalCnt >> relationships; cin.ignore();
    Product** products = new Product*[productCnt];
    Item** items = new Item*[itemTotalCnt];

    for(int i = 0; i < productCnt; i++){
        char* name = new char[500];
        cin.getline(name, 500, ',');

        int price, cost, salesQty, itemCnt;
        cin  >> price >> cost >> salesQty >> itemCnt;   cin.ignore();
        products[i] = new Product(name, price, cost, salesQty, itemCnt);

        name = nullptr;
    }

    for(int i = 0; i < itemTotalCnt; i++){
        char* name = new char[500];
        cin.getline(name, 500, ',');

        int materialCost;
        cin >> materialCost;    cin.ignore();
        items[i] = new Item(name, materialCost);

        name = nullptr;
    }

    for(int i = 0; i < relationships; i++){
        char *name = new char[500];
        cin.getline(name, 500, ',');

        char *itemName = new char[500];
        cin.getline(itemName, 500, '\n');
        
        for(int j = 0; j < productCnt; j++){
            if(products[j]->isThisProduct(name)){
                for(int k = 0; k < itemTotalCnt; k++){
                    if(items[k]->isThisItem(itemName)){
                        products[j]->addItem(items[k]);
                        break;
                    }
                }
                break;
            }
        }

        name = nullptr;
        itemName = nullptr;
    }

    int criterion, num;
    cin >> criterion >> num;
    MySort(products, productCnt, criterion);

    int ans = 0;
    for(int i = 0; i < num; i++){
        ans += products[i]->profit();
    }

    cout << ans << '\n';

    for(int i = 0; i < productCnt; i++){
        products[i]->~Product();
    }
    delete [] products;
    products = nullptr;

    for(int i = 0; i < itemTotalCnt; i++){
        delete items[i];
        items[i] = nullptr;
    }
    delete [] items;
    items = nullptr;
}