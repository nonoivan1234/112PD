#include <iostream>
#include <cstring>
using namespace std;

void printTwoDigits(int n);

class Time
{
private:
  static bool Hour12;
  int hour;
  int minute;
  int second;
public:
  Time(); 
  Time(int h, int m, int s);
  void setTime(int h, int m, int s); 
  bool isEarlierThan(Time t);
  void print();
  void printNicely();
  int secUntilNow();
  static void print12Hour(bool ok);
};

class Event
{
  private:
    char* name;
    Time start;
    Time end;
  public:
    Event(char* n, Time s, Time e);
    Event(const Event& e);
    ~Event();
    void printNicely();
    bool conflictsWith(Event e);
    void setName(char* n);
};

Event::Event(const Event& e)
{
  int nameLen = strlen(e.name);
  name = new char[nameLen + 1];
  strcpy(name, e.name);
  start = e.start;
  end = e.end;
}

Event::Event(char* n, Time s, Time e)
{
  int nameLen = strlen(n);
  name = new char[nameLen + 1];
  strcpy(name, n);
  start = s;
  end = e;
}

Event::~Event()
{
  delete [] name;
}

void Event::printNicely()
{
  cout << name << "\n";
  cout << "Starts:\t";
  start.printNicely();
  cout << "Ends:\t";
  end.printNicely();
}

bool Event::conflictsWith(Event e)
{
  int myStart = start.secUntilNow();
  int myEnd = end.secUntilNow();
  int itsStart = e.start.secUntilNow();
  int itsEnd = e.end.secUntilNow();

  if(myStart < itsEnd)  return true;
  return false;
}

void Event::setName(char* n)
{
  int nameLen = strlen(n);
  name = new char[nameLen + 1];
  strcpy(name, n);
}

Time::Time()
{
  hour = 0;
  minute = 0;
  second = 0; 
} 

Time::Time(int h, int m, int s)
{
  hour = h;
  minute = m;
  second = s;
}

void Time::setTime(int h, int m, int s)
{
  hour = h;
  minute = m;
  second = s; 
} 

bool Time::Hour12 = false;

void Time::print12Hour(bool ok){
  Time::Hour12 = ok;
}

bool Time::isEarlierThan(Time t)
{
  int numSecSelf = secUntilNow();
  int numSecT = t.secUntilNow();
  if(numSecSelf < numSecT)
    return true;
  else
    return false;
}

void Time::print()
{
  cout << hour << ":" << minute << ":" << second;
}

void Time::printNicely()
{
  if(Hour12){
    if(hour > 12){
      printTwoDigits(hour - 12);
      cout << ":";
      printTwoDigits(minute);
      cout << ":";
      printTwoDigits(second);
      cout << " PM\n";
    }
    else{
      printTwoDigits(hour);
      cout << ":";
      printTwoDigits(minute);
      cout << ":";
      printTwoDigits(second);
      cout << " AM\n";
    }
  }
  else{
    printTwoDigits(hour);
    cout << ":";
    printTwoDigits(minute);
    cout << ":";
    printTwoDigits(second);
    cout << "\n";
  }
}

int Time::secUntilNow()
{
  int numSec = 3600 * hour + 60 * minute + second;
  return numSec;
}




int main()
{
  char n1[] = "PD";
  // Time::print12Hour(true);
  Event e1(n1, Time(14, 20, 0), Time(17, 20, 0));
  // e1.printNicely();

  Event e2(e1);
  char n2[] = "Calculus";
  e2.setName(n2);

  e2.printNicely();
  e1.printNicely();
  return 0;
}





void printTwoDigits(int n)
{
  cout << (n < 10 ? "0" : "");
  cout << n; 
}