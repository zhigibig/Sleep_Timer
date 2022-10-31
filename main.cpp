#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iomanip>



struct Time {
  int hours;
  int minutes;
  int seconds;
};



unsigned long int get_time(); 

void shut_down();

void clear_terminal();

void show_timer();

void print_time(unsigned int t);



int main() {
  using namespace std;
  unsigned long int sleeping_time = get_time();
  unsigned long int sec = 1000000;

  for (unsigned long int i = sleeping_time; i > 0; i -= sec) {
    clear_terminal();
    print_time(i);
    sleeping_time -= sec;
    usleep(sec);
  };
  
  if (sleeping_time <= 0) {
    shut_down();
  };

  return 0;
};



unsigned long int get_time() {
  // this function is getting time from user 
  using namespace std;

  unsigned long int time;
  
  bool key = true;
  while (key == true) {
    cout << "Введите количество минут после которых компьютер будет выключен в диапазоне от 1 минуты до 90 минут." << endl << "Компьютер будет выключен через - ";
    cin >> time;
    cout << " мин" << endl;
  
    if (time >= 1 && time <= 90) {
      key = false;
    };

    time = time * 60 * 1000000;
  };
  return time;
};

void shut_down() {
  system("shutdown -h now");
};

void clear_terminal() {
  for (int i = 0; i < 100; i++) {
    printf("\n");
  };
};

void print_time(unsigned int t) {
  using namespace std;

  unsigned long int hours = t / 3600000000;
  unsigned long int minutes = t / 60000000;
  unsigned long int seconds = (t  % 60000000) / 1000000;

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
