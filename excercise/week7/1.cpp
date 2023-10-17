#include<iostream>
using namespace std;

struct Time
{
    int hour;
    int minute;
    int second;
    void setTime(int h, int m, int s);
    void print();
    bool isEarlierThan(Time t);
};

int main()
{
    Time t[3];
    for(int i = 0; i < 3; i++){
        int h, m, s;
        cin >> h >> m >> s;
        t[i].setTime(h, m, s);
    }

    int ind = 0;
    for(int i = 1; i < 3; i++){
        if(!t[i].isEarlierThan(t[ind])){
            ind = i;
        }
    }

    cout << ind + 1 <<"\n";
  
  return 0;
}


void Time::setTime(int h, int m, int s)
{
  hour = h;
  minute = m;
  second = s;
}

void Time::print()
{
  cout << hour << ":" 
       << minute << ":" 
       << second;
}

bool Time::isEarlierThan(Time t){
    if(hour != t.hour)  return hour < t.hour;
    if(minute != t.minute)  return minute < t.minute;
    return second < t.second;
}
