#include <iostream>
#include <stdio.h>
#include <iomanip>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif



long int get_time(); 
void shut_down();
void clear_terminal();
void print_time(long int);
void do_sleep(long int);



int main() {
  using namespace std;
  long int sleeping_time = get_time();
  int sec = 1000000;

  for (unsigned long int i = sleeping_time; i > 0; i -= sec) {
    clear_terminal();
    print_time(i);
    
    sleeping_time -= sec;
    
    do_sleep(sec);
  };
  
  if (sleeping_time <= 0) {
    shut_down();
  };

  return 0;
};



long int get_time() {
  // this function is getting time from user 
  using namespace std;

  long int time;
  
  bool key = true;
  while (key == true) {
    cout << "Введите количество минут после которых компьютер будет выключен в диапазоне от 1 минуты до 90 минут." << endl << "Компьютер будет выключен через - ";
    cin >> time;
    cout << " мин" << endl;
  
    if (time >= 1 && time <= 90) {
      key = false;
    };
  };
  
  return time * 60 * 1000000;
};

void shut_down() {
  #ifdef _WIN32
    system("shutdown -s -t 0");
  #else
    system("shutdown -h now");
  #endif
};

void clear_terminal() {
  for (int i = 0; i < 100; i++) {
    printf("\n");
  };
};

void print_time(long int t) {
  using namespace std;

  long int hours = t / 3600000000;
  long int minutes = t / 60000000;
  long int seconds = (t  % 60000000) / 1000000;

  string stars = "**************************************";
  string timer_txt = "**              TIMER               **";
  string hms = "**  hours  **  minutes  **  seconds **";

  cout << stars << endl;
  cout << timer_txt << endl;
  cout << stars << endl;
  cout << hms << endl;
  cout << stars << endl;
  cout << "**" << "   " << setw(3) << hours << "   " << "**" << "   " << setw(3) << minutes << "     " << "**" << "   " << setw(3) << seconds << "    " << "**" << endl;
  cout << stars << endl;
};

void do_sleep(long int time) {
  #ifdef _WIN32
    Sleep(((double) time));
  #else
    usleep(time);
  #endif
};
