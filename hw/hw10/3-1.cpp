#include<iostream>
#include<string>
using namespace std;
const int ZOO_CAP = 100;

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
    // read time in format "hh:mm:ss"

    Time t;
    char H[3], M[3], S[3];
    cin.getline(H, 3, ':');
    cin.getline(M, 3, ':');
    cin >> S;   cin.ignore();

    t = {atoi(H), atoi(M), atoi(S)};
    return t;
}

Date readDate(){
    // read date in format "yyyy/mm/dd"

    Date d;
    char Y[5], M[3], D[3];
    cin.getline(Y, 5, '/');
    cin.getline(M, 3, '/');
    cin >> D;   cin.ignore();

    d = {atoi(Y), atoi(M), atoi(D)};
    return d;
}

void printTimeNicely(const Time& t) {
    // print time in format "hh:mm:ss"

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
    // print date in format "yyyy/mm/dd"

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
    // return true if a == b

    if (a.year == b.year && a.month == b.month && a.day == b.day) {
        return true;
    }
    return false;
}

bool DateisEarlier(const Date& a, const Date& b) {
    // return true if a < b

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
    // return true if t is a valid time

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
    // return true if a < b

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
    void setName(string n);
    void print() const;
    int getID() const {return this->id;};
    bool isShow() const {return this->isShowAnimal;};
    bool isThisID(int id) const {return this->id == id;};
    bool isThisName(string n) const {return this->name == n;};
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
    // Set current date to 2023/11/21 and get the age of the animal

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

// Always initialize the start.hour to -1 for determine whether the time is valid
DisplayAnimal::DisplayAnimal(int id, Date b, string n) : Animal(id, b, n, false) {
    this->start = {-1, 0, 0};
    this->end = {0, 0, 0};
}

DisplayAnimal::DisplayAnimal(int id, Date b) : Animal(id, b, "", false) {
    this->start = {-1, 0, 0};
    this->end = {0, 0, 0};
}

void DisplayAnimal::setDisplayTime(const Time& start , const Time& end) {
    if (!validTime(start) || !validTime(end) || !cmpTime(start, end)) {
        // If the time is invalid or start >= end, do nothing
        return;
    }

    // Otherwise, set the time
    this->start = start;
    this->end = end;
}

void DisplayAnimal::getDisplayTime(Time& start , Time& end) const {
    start = this->start;
    end = this->end;
}

bool DisplayAnimal::isValid() const {
    // If the start.hour is -1, the time is invalid

    if (this->start.hour == -1) {
        return false;
    }
    return true;
}

void DisplayAnimal::print() const {
    this->Animal::print();
    cout << ",";
    if(this->isValid() == false){
        cout << "none" << endl;
    }
    else{
        printTimeNicely(this->start);
        cout << ",";
        printTimeNicely(this->end);
        cout << endl;
    }
}
const int N = 2e4;
class ShowAnimal : public Animal {
private:
    Date showDates[N];
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
    // this->showDates = nullptr;
    // for(int i = 0; i < N; i++)  this->showDates[i] = nullptr;
    this->showCnt = 0;
}

ShowAnimal::ShowAnimal(int id, Date b) : Animal(id, b, "", true) {
    // this->showDates = nullptr;
    // for(int i = 0; i < N; i++)  this->showDates[i] = nullptr;
    this->showCnt = 0;
}

ShowAnimal::ShowAnimal(const ShowAnimal& sa) : Animal(sa) {
    // Copy constructor for ShowAnimal

    this->showCnt = sa.showCnt;
    for(int i = 0; i < sa.showCnt; i++){
        this->showDates[i] = sa.showDates[i];
    }
}

ShowAnimal::~ShowAnimal() {
    // for (int i = 0; i < this->showCnt; i++) {
    //     delete this->showDates[i];
    //     showDates[i] = nullptr;
    // }
}

void ShowAnimal::addShowDate(const Date& d) {
    // If the date is earlier than the birthday, do nothing
    if(DateisEarlier(d, this->birthday))  return;

    // cout << "123\n";
    for (int i = 0; i < this->showCnt; i++) {
        if(DateisEqual(d, (this->showDates[i]))) {
            // If the date is already in the array, do nothing
            return;
        }
    }

    // cout << this->showCnt << endl;
    // this->showDates[this->showCnt] = new Date;
    (this->showDates[this->showCnt]) = d;
    this->showCnt++;
}

int ShowAnimal::getShowCnt(const Date& start, const Date& end) const {
    // Return the number of shows between start and end

    int cnt = 0;
    for (int i = 0; i < this->showCnt; i++) {
        if ((DateisEarlier(start, (this->showDates[i])) || DateisEqual(start, (this->showDates[i]))) && (DateisEarlier((this->showDates[i]), end) || DateisEqual((this->showDates[i]), end))) {
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

class Zoo {
private:
    int displayAnimalCnt;
    int showAnimalCnt;
    Animal* animals[ZOO_CAP];
public:
    Zoo();
    ~Zoo();
    bool isFull() const;
    bool addAnimal(const Animal* a, bool isShowAnimal);
    void ChangeAnimalName(int id, string name);
    void SetDisplayTime(string name, const Time& start, const Time& end);
    void AddShowDate(string name, const Date& d);
    void print() const;
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
        if (this->animals[i] == nullptr)    break;

        delete this->animals[i];
        this->animals[i] = nullptr;
    }
}

bool Zoo::isFull() const {
    // If the zoo is full, return true

    if (this->displayAnimalCnt + this->showAnimalCnt >= ZOO_CAP) {
        return true;
    }
    return false;
}

bool Zoo::addAnimal(const Animal* a, bool isShowAnimal) {
    // If the zoo is full, return false and do nothing
    if(this->isFull())  return false;

    for(int i = 0; i < ZOO_CAP; i++){
        if(this->animals[i] == nullptr){
            if (isShowAnimal) {
                this->animals[i] = new ShowAnimal(*(ShowAnimal*)a);
                this->showAnimalCnt++;
                return true;
            }
            else{
                this->animals[i] = new DisplayAnimal(*(DisplayAnimal*)a);
                this->displayAnimalCnt++;
                return true;
            }
        }
    }
    return false;
}

void Zoo::ChangeAnimalName(int id, string name) {
    // Change the name of the animal with the given id

    for(int i = 0; i < ZOO_CAP; i++){
        if(this->animals[i] == nullptr)    break;

        if(this->animals[i]->isThisID(id)){
            this->animals[i]->setName(name);
            break;
        }
    }
}

void Zoo::SetDisplayTime(string name, const Time& start, const Time& end) {
    // Set the display time of the animal with the given name

    for(int i = 0; i < ZOO_CAP; i++){
        if(this->animals[i] == nullptr)    break;

        if(this->animals[i]->isThisName(name)){
            // If the animal is a show animal, do nothing
            if(this->animals[i]->isShow() == true)    break;

            ((DisplayAnimal*)this->animals[i])->setDisplayTime(start, end);
            break;
        }
    }
}

void Zoo::AddShowDate(string name, const Date& d) {
    // Add the show date of the animal with the given name

    for(int i = 0; i < ZOO_CAP; i++){
        if(this->animals[i] == nullptr)    break;

        if(this->animals[i]->isThisName(name)){
            // If the animal is a display animal, do nothing
            if(this->animals[i]->isShow() == false)    break;

            ((ShowAnimal*)this->animals[i])->addShowDate(d);
            break;
        }
    }
}

void Zoo::print() const {
    int len = this->displayAnimalCnt + this->showAnimalCnt;
    cout << len << endl;

    for(int i = 0; i < len; i++){
        if(this->animals[i]->isShow() == true){
            ((ShowAnimal*)this->animals[i])->print();
        }
        else{
            ((DisplayAnimal*)this->animals[i])->print();
        }
    }
}

Animal* Zoo::findMostBusyShowAnimal() {
    int max = -1;
    int maxID = 1000000;
    int maxIndex = -1;
    for (int i = 0; i < ZOO_CAP; i++) {
        if (this->animals[i] == nullptr)    break;

        if (this->animals[i]->isShow()) {
            int CntNow = ((ShowAnimal*) this->animals[i])->getShowCnt();
            if(CntNow > max){
                max = CntNow;
                maxIndex = i;
                maxID = this->animals[i]->getID();
            } else if(CntNow == max){
                if(this->animals[i]->getID() < maxID){
                    maxID = this->animals[i]->getID();
                    maxIndex = i;
                }
            }
        }

    }

    return this->animals[maxIndex];
}


int main(){
    Zoo zoo;

    int testNum;
    cin >> testNum; cin.ignore();

    for(int t = 0; t < testNum; t++){
        char type;
        cin >> type;    cin.ignore();

        if(type == 'C'){    // Create animal
            int id;
            string name, action;
            cin >> action >> id >> name;  cin.ignore();

            Date birthday = readDate();

            if(name == "Unknown"){
                if(action == "Show"){
                    zoo.addAnimal(new ShowAnimal(id, birthday), true);
                }
                else{
                    zoo.addAnimal(new DisplayAnimal(id, birthday), false);
                }
            }
            else{
                if(action == "Show"){
                    zoo.addAnimal(new ShowAnimal(id, birthday, name), true);
                }
                else{
                    zoo.addAnimal(new DisplayAnimal(id, birthday, name), false);
                }
            }
        }
        else if(type == 'S'){   // Set display time
            string name;
            cin >> name;    cin.ignore();
            Time start = readTime();
            Time end = readTime();

            zoo.SetDisplayTime(name, start, end);
        }
        else if(type == 'N'){   // Change animal name
            int id;
            string name;
            cin >> id >> name;  cin.ignore();

            zoo.ChangeAnimalName(id, name);
        }
        else if(type == 'A'){   // Add show date
            string name;
            cin >> name;    cin.ignore();
            Date d = readDate();

            zoo.AddShowDate(name, d);
        }
    }

    zoo.print();

    Animal* mostBusy = zoo.findMostBusyShowAnimal();

    if(mostBusy->isShow() == true)  ((ShowAnimal*)mostBusy)->print();
    else    ((DisplayAnimal*)mostBusy)->print();

    return 0;
}