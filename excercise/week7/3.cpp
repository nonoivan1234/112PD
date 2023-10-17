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
    void printNicely();
};
void timeSort(const Time unsorted[], int sortedIndices[], int len);

int main()
{
    int n;
    cin >> n;
    Time t[n];
    for(int i = 0; i < n; i++)  cin >> t[i].hour;
    for(int i = 0; i < n; i++)  cin >> t[i].minute;
    for(int i = 0; i < n; i++)  cin >> t[i].second;

    int sortedIndices[n];
    timeSort(t, sortedIndices, n);
  
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

void Time::printNicely(){
    if(hour < 10)   cout << "0";
    cout << hour << ":";
    if(minute < 10) cout << "0";
    cout << minute << ":";
    if(second < 10) cout << "0";
    cout << second << "\n";
}

void timeSort(const Time unsorted[], int sortedIndices[], int len){
    Time sorted[len];
    for(int i = 0; i < len; i++){
        sortedIndices[i] = i;
        sorted[i] = unsorted[i];
    }

    for(int i = 0; i < len; i++){
        for(int j = i; j > 0; j--){
            if(sorted[j].isEarlierThan(sorted[j-1])){
                swap(sorted[j], sorted[j-1]);
                swap(sortedIndices[j], sortedIndices[j-1]);
            }
            else    break;
        }
    }

    for(int i = 0; i < len; i++)    cout << sortedIndices[i] + 1 << " \n"[i == len-1];
}