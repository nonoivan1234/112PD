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

class Animal {
protected:
    int id;
    Date birthday;
    string name;
public:
    Animal(int id, Date b, string n);
    Animal(int id, Date b);
    ~Animal(){};
    int getAge() const;
    string getName() const;
    void setName(string n);
    void print() const;
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
    cout << "," << this->getAge() << endl;
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

class DisplayAnimal : public Animal {
private:
    Time start;
    Time end;
public:
    DisplayAnimal(int id, Date b, string n);
    DisplayAnimal(int id, Date b);
    DisplayAnimal(const Animal& ani);
    ~DisplayAnimal(){};
    void setDisplayTime(const Time& start , const Time& end);
    void getDisplayTime(Time& start , Time& end) const;
    void print() const;
};

DisplayAnimal::DisplayAnimal(int id, Date b, string n) : Animal(id, b, n) {
    this->start = {-1, 0, 0};
    this->end = {0, 0, 0};
}

DisplayAnimal::DisplayAnimal(int id, Date b) : Animal(id, b) {
    this->start = {-1, 0, 0};
    this->end = {0, 0, 0};
}

DisplayAnimal::DisplayAnimal(const Animal& ani) : Animal(ani) {
    this->start = {-1, 0, 0};
    this->end = {0, 0, 0};
}

void DisplayAnimal::setDisplayTime(const Time& start , const Time& end) {
    this->start = start;
    this->end = end;
}

void DisplayAnimal::getDisplayTime(Time& start , Time& end) const {
    start = this->start;
    end = this->end;
}


void DisplayAnimal::print() const {
    cout << this->getName() << "," ;
    printDateNicely(this->birthday);
    cout << "," << this->getAge() << ",";
    if(this->start.hour == -1){
        cout << "none" << endl;
    }
    else{
        printTimeNicely(this->start);
        cout << ",";
        printTimeNicely(this->end);
    }
    cout << endl;
}

int main(){
    Animal* ani[105];
    DisplayAnimal* dis[105];
    for(int i = 0; i < 105; i++){
        ani[i] = NULL;
        dis[i] = NULL;
    }

    int numOfAction;
    cin >> numOfAction;

    for(int i = 0; i < numOfAction; i++){
        char type;
        cin >> type;
        if(type == 'C'){
            int id;
            string name;
            cin >> id >> name;  cin.ignore();

            // input date in format of YYYY/MM/DD
            char Y[55], M[33], D[33];
            cin.getline(Y, 55, '/');
            cin.getline(M, 33, '/');
            cin >> D;

            if(name == "Unknown"){
                Date birthday = {atoi(Y), atoi(M), atoi(D)};
                ani[id] = new Animal(id, birthday);
                dis[id] = new DisplayAnimal(id, birthday);
            }
            else{
                Date birthday = {atoi(Y), atoi(M), atoi(D)};
                ani[id] = new Animal(id, birthday, name);
                dis[id] = new DisplayAnimal(id, birthday, name);
            }
        }
        else if(type == 'S'){
            string name;
            char H[33], M[33], S[33];
            cin >> name;    cin.ignore();
            cin.getline(H, 33, ':');
            cin.getline(M, 33, ':');
            cin >> S;   cin.ignore();
            Time start = {atoi(H), atoi(M), atoi(S)};

            cin.getline(H, 33, ':');
            cin.getline(M, 33, ':');
            cin >> S;
            Time end = {atoi(H), atoi(M), atoi(S)};


            for(int j = 0; j < 105; j++){
                if(ani[j] != NULL && ani[j]->getName() == name){
                    if(dis[j] == NULL)
                        dis[j] = new DisplayAnimal(*ani[j]);

                    if(!validTime(start) || !validTime(end) || !cmpTime(start, end)){
                        continue;
                    }
                    dis[j]->setDisplayTime(start, end);
                    break;
                }
            }
        }
        else if(type == 'N'){
            int id;
            string name;
            cin >> id >> name;

            if(ani[id] != NULL)
                ani[id]->setName(name);
            if(dis[id] != NULL)
                dis[id]->setName(name);
        }
    }

    char type;
    cin >> type;

    int cnt = 0;
    for(int i = 0; i < 105; i++){
        if(dis[i] != NULL){
            cnt++;
        }
    }
    cout << cnt << endl;

    if(type == 'Q'){
        string name;
        cin >> name;
        for(int i = 0; i < 105; i++){
            if(ani[i] != NULL && ani[i]->getName() == name){
                dis[i]->print();
                break;
            }
        }
    }
}