#include<iostream>
#include<string>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

struct Time {
    int hour;
    int minute;
    int second;
};

Time readTime(){
    Time t;
    char H[33], M[33], S[33];
    cin.getline(H, 33, ':');
    cin.getline(M, 33, ':');
    cin >> S;   cin.ignore();

    t = {atoi(H), atoi(M), atoi(S)};
    return t;
}

Date readDate(){
    // read date in format "yyyy/mm/dd"

    Date d;
    char Y[55], M[33], D[33];
    cin.getline(Y, 55, '/');
    cin.getline(M, 33, '/');
    cin >> D;   cin.ignore();

    d = {atoi(Y), atoi(M), atoi(D)};
    return d;
}

void printTimeNicely(const Time& t) {
    if (t.hour < 10) {
        cout << "0";
    }
    cout << t.hour << ":";
    if (t.minute < 10) {
        cout << "0";
    }
    cout << t.minute << ":";
    if (t.second < 10) {
        cout << "0";
    }
    cout << t.second;
}

void printDateNicely(const Date& d) {
    cout << d.year << "/";
    if (d.month < 10) {
        cout << "0";
    }
    cout << d.month << "/";
    if (d.day < 10) {
        cout << "0";
    }
    cout << d.day;
}

bool DateisEqual(const Date& a, const Date& b) {
    if (a.year == b.year && a.month == b.month && a.day == b.day) {
        return true;
    }
    return false;
}

bool DateisLess(const Date& a, const Date& b) {
    if (a.year < b.year) {
        return true;
    } else if (a.year == b.year) {
        if (a.month < b.month) {
            return true;
        } else if (a.month == b.month) {
            if (a.day < b.day) {
                return true;
            }
        }
    }
    return false;
}

bool validTime(const Time& t) {
    if (t.hour < 0 || t.hour > 23) {
        return false;
    } else if (t.minute < 0 || t.minute > 59) {
        return false;
    } else if (t.second < 0 || t.second > 59) {
        return false;
    }
    return true;
}

bool cmpTime(const Time& a, const Time& b) {
    if (a.hour < b.hour) {
        return true;
    } else if (a.hour == b.hour) {
        if (a.minute < b.minute) {
            return true;
        } else if (a.minute == b.minute) {
            if (a.second < b.second) {
                return true;
            }
        }
    }
    return false;
}

class Animal {
protected:
    int id;
    Date birthday;
    string name;
    bool isShowAnimal;
public:
    Animal(int id, Date b, string n);
    Animal(int id, Date b);
    Animal(int id, Date b, string n, bool isShowAnimal);
    ~Animal(){};
    int getAge() const;
    string getName() const;
    void setName(string n);
    void print() const;
    bool isShow() const {return this->isShowAnimal;};
    bool isThisID(int id) const {return this->id == id;};
};

Animal::Animal(int id, Date b, string n) {
    this->id = id;
    this->birthday = b;
    this->name = n;
}

Animal::Animal(int id, Date b) {
    this->id = id;
    this->birthday = b;
    this->name = "";
}

Animal::Animal(int id, Date b, string n, bool isShowAnimal) {
    this->id = id;
    this->birthday = b;
    this->name = n;
    this->isShowAnimal = isShowAnimal;
}

int Animal::getAge() const {
    // Set current date to 2023/11/21
    Date current = {2023, 11, 21};
    int age = current.year - this->birthday.year;
    if (current.month < this->birthday.month) {
        age--;
    } else if (current.month == this->birthday.month) {
        if (current.day < this->birthday.day) {
            age--;
        }
    }
    return age;
}

string Animal::getName() const {
    return this->name;
}

void Animal::setName(string n) {
    this->name = n;
}

void Animal::print() const {
    cout << this->name << ",";
    printDateNicely(this->birthday);
    cout << "," << this->getAge();
}

class DisplayAnimal : public Animal {
private:
    Time start;
    Time end;
public:
    DisplayAnimal(int id, Date b, string n);
    DisplayAnimal(int id, Date b);
    ~DisplayAnimal(){};
    void setDisplayTime(const Time& start , const Time& end);
    void getDisplayTime(Time& start , Time& end) const;
    void print() const;
    bool isValid() const;
};

DisplayAnimal::DisplayAnimal(int id, Date b, string n) : Animal(id, b, n, false) {
    this->id = id;
    this->birthday = b;
    this->name = n;
    this->isShowAnimal = false;
    this->start = {-1, 0, 0};
    this->end = {0, 0, 0};
}

DisplayAnimal::DisplayAnimal(int id, Date b) : Animal(id, b, "", false) {
    this->id = id;
    this->birthday = b;
    this->name = "";
    this->isShowAnimal = false;
    this->start = {-1, 0, 0};
    this->end = {0, 0, 0};
}

void DisplayAnimal::setDisplayTime(const Time& start , const Time& end) {
    if (!validTime(start) || !validTime(end) || !cmpTime(start, end)) {
        return;
    }
    this->start = start;
    this->end = end;
}

void DisplayAnimal::getDisplayTime(Time& start , Time& end) const {
    start = this->start;
    end = this->end;
}

bool DisplayAnimal::isValid() const {
    if (this->start.hour == -1) {
        return false;
    }
    return true;
}

void DisplayAnimal::print() const {
    this->Animal::print();
    cout << ",";
    if(this->start.hour == -1){
        cout << "none" << endl;
    }
    else{
        printTimeNicely(this->start);
        cout << ",";
        printTimeNicely(this->end);
        cout << endl;
    }
}

class ShowAnimal : public Animal {
private:
    Date** showDates;
    int showCnt;
public:
    ShowAnimal(int id, Date b, string n);
    ShowAnimal(int id, Date b);
    ShowAnimal(const ShowAnimal& sa);
    ~ShowAnimal();
    void addShowDate(const Date& d);
    int getShowCnt(const Date& start, const Date& end) const;
    int getShowCnt() const {return this->showCnt;};
    void print(const Date& start, const Date& end) const;
    void print() const;
};

ShowAnimal::ShowAnimal(int id, Date b, string n) : Animal(id, b, n, true) {
    this->id = id;
    this->birthday = b;
    this->name = n;
    this->isShowAnimal = true;
    this->showDates = nullptr;
    this->showCnt = 0;
}

ShowAnimal::ShowAnimal(int id, Date b) : Animal(id, b, "", true) {
    this->id = id;
    this->birthday = b;
    this->name = "";
    this->isShowAnimal = true;
    this->showDates = nullptr;
    this->showCnt = 0;
}

ShowAnimal::ShowAnimal(const ShowAnimal& sa) : Animal(sa) {
    this->showCnt = sa.showCnt;

    // delete original showDates
    for (int i = 0; i < this->showCnt; i++) {
        delete this->showDates[i];
    }
    this->showDates = new Date*[this->showCnt];
    for (int i = 0; i < this->showCnt; i++) {
        this->showDates[i] = new Date;
        *(this->showDates[i]) = *(sa.showDates[i]);
    }
}

ShowAnimal::~ShowAnimal() {
    for (int i = 0; i < this->showCnt; i++) {
        delete this->showDates[i];
    }
    delete [] this->showDates;
}

void ShowAnimal::addShowDate(const Date& d) {
    if(DateisLess(d, this->birthday)) {
        return;
    }
    Date** tmp = new Date*[this->showCnt + 1];
    for (int i = 0; i < this->showCnt; i++) {
        tmp[i] = this->showDates[i];
        if(DateisEqual(d, *(this->showDates[i]))) {
            delete [] tmp;
            return;
        }
    }
    tmp[this->showCnt] = new Date;
    *(tmp[this->showCnt]) = d;
    this->showCnt++;
    delete [] this->showDates;
    this->showDates = tmp;
}

int ShowAnimal::getShowCnt(const Date& start, const Date& end) const {
    int cnt = 0;
    for (int i = 0; i < this->showCnt; i++) {
        if ((DateisLess(start, *(this->showDates[i])) || DateisEqual(start, *(this->showDates[i]))) && (DateisLess(*(this->showDates[i]), end) || DateisEqual(*(this->showDates[i]), end))) {
            cnt++;
        }
    }
    return cnt;
}

void ShowAnimal::print(const Date& start, const Date& end) const {
    this->Animal::print();
    cout << "," << this->getShowCnt(start, end) << endl;
}

void ShowAnimal::print() const {
    this->Animal::print();
    cout << "," << this->showCnt << endl;
}

const int ZOO_CAP = 205;
class Zoo {
private:
    int displayAnimalCnt;
    int showAnimalCnt;
    Animal* animals[ZOO_CAP];
public:
    Zoo();
    ~Zoo();
    bool addAnimal(const Animal* a, bool isShowAnimal);
    void ChangeAnimalName(int id, string name);
    void SetDisplayTime(string name, const Time& start, const Time& end);
    void AddShowDate(string name, const Date& d);
    void print() const;
    Animal* findAnimal(string name) const;
    Animal* findMostBusyShowAnimal();
};

Zoo::Zoo() {
    this->displayAnimalCnt = 0;
    this->showAnimalCnt = 0;
    for (int i = 0; i < ZOO_CAP; i++) {
        this->animals[i] = nullptr;
    }
}

Zoo::~Zoo() {
    for (int i = 0; i < ZOO_CAP; i++) {
        delete this->animals[i];
        this->animals[i] = nullptr;
    }
}

bool Zoo::addAnimal(const Animal* a, bool isShowAnimal) {
    if (this->showAnimalCnt + this->displayAnimalCnt == ZOO_CAP - 1) {
        return false;
    }

    if (isShowAnimal) {
        for(int i = 0; i < ZOO_CAP; i++){
            if(this->animals[i] == NULL){
                this->animals[i] = new ShowAnimal(*(ShowAnimal*)a);
                break;
            }
        }
        this->showAnimalCnt++;
    } else {
        for(int i = 0; i < ZOO_CAP; i++){
            if(this->animals[i] == NULL){
                this->animals[i] = new DisplayAnimal(*(DisplayAnimal*)a);
                break;
            }
        }
        this->displayAnimalCnt++;
    }
    return true;
}

void Zoo::ChangeAnimalName(int id, string name) {
    for(int i = 0; i < ZOO_CAP; i++){
        if(this->animals[i] == NULL)    break;
        if(this->animals[i]->isThisID(id)){
            this->animals[i]->setName(name);
            break;
        }
    }
}

void Zoo::SetDisplayTime(string name, const Time& start, const Time& end) {
    for(int i = 0; i < ZOO_CAP; i++){
        if(this->animals[i] == NULL)    break;
        if(this->animals[i]->getName() == name){
            if(this->animals[i]->isShow() == true)    break;

            ((DisplayAnimal*)this->animals[i])->setDisplayTime(start, end);
            break;
        }
    }
}

void Zoo::AddShowDate(string name, const Date& d) {
    for(int i = 0; i < ZOO_CAP; i++){
        if(this->animals[i] == NULL)    break;
        if(this->animals[i]->getName() == name){
            if(this->animals[i]->isShow() == false)    break;

            ((ShowAnimal*)this->animals[i])->addShowDate(d);
            break;
        }
    }
}

void Zoo::print() const {
    cout << this->displayAnimalCnt << "," << this->showAnimalCnt << endl;
}

Animal* Zoo::findAnimal(string name) const {
    for(int i = 0; i < ZOO_CAP; i++){
        if(this->animals[i] == NULL)    break;
        if(this->animals[i]->getName() == name){
            return this->animals[i];
        }
    }
    return NULL;
}

Animal* Zoo::findMostBusyShowAnimal() {
    int max = 0;
    int maxIndex = -1;
    for (int i = 0; i < ZOO_CAP; i++) {
        if(this->animals[i] == NULL)    break;
        if (this->animals[i]->isShow()) {
            int CntNow = ((ShowAnimal*) this->animals[i])->getShowCnt();
            if(CntNow > max){
                max = CntNow;
                maxIndex = i;
            }
        }

    }
    if (maxIndex == -1) {
        return NULL;
    }
    return this->animals[maxIndex];
}


int main(){
    Zoo zoo;

    int testNum;
    cin >> testNum;

    for(int t = 0; t < testNum; t++){
        char type;
        cin >> type;

        if(type == 'C'){
            int id;
            string name, action;
            cin >> action >> id >> name;  cin.ignore();

            if(name == "Unknown"){
                Date birthday = readDate();
                if(action == "Show"){
                    zoo.addAnimal(new ShowAnimal(id, birthday), true);
                }
                else{
                    zoo.addAnimal(new DisplayAnimal(id, birthday), false);
                }
            }
            else{
                Date birthday = readDate();
                if(action == "Show"){
                    zoo.addAnimal(new ShowAnimal(id, birthday, name), true);
                }
                else{
                    zoo.addAnimal(new DisplayAnimal(id, birthday, name), false);
                }
            }
        }
        else if(type == 'S'){
            string name;
            cin >> name;    cin.ignore();
            Time start = readTime();
            Time end = readTime();

            zoo.SetDisplayTime(name, start, end);
        }
        else if(type == 'N'){
            int id;
            string name;
            cin >> id >> name;  cin.ignore();

            zoo.ChangeAnimalName(id, name);
        }
        else if(type == 'A'){
            string name;
            cin >> name;    cin.ignore();
            Date d = readDate();

            zoo.AddShowDate(name, d);
        }
    }

    char action;
    cin >> action;

    if(action == 'Q'){
        string name;
        cin >> name;    cin.ignore();
        Date start = readDate();
        Date end = readDate();

        Animal* animal = zoo.findAnimal(name);
        
        zoo.print();
        ((ShowAnimal*)animal)->print(start, end);
    }


    return 0;
}