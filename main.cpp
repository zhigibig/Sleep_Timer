#include <iostream>
#include <stdio.h>
#include <unistd.h>



struct Time {
  int hours;
  int minutes;
};

#define Time sleep_time



int sleep_time(); 

void shut_down();

void clear_terminal();

void show_timer();



int main() {
  using namespace std;

  int arr = sleep_time();

  cout << arr << endl;

  return 0;
};



int sleep_time() {
  // this function is getting time from user 
  using namespace std;

  unsigned int minutes;
  
  bool key = true;
  while (key == true) {
  cout << "Введите количество минут после которых компьютер будет выключен в диапазоне от 1 минуты до 90 минут." << endl << "Компьютер будет выключен через - ";
  cin >> minutes;
  cout << " мин" << endl;
  
  if (minutes >= 1 && minutes <= 90) {
    key == false;
    };
  };

  

  return 0;
};

void shut_down() {
  system("shutdown -h now");
};

void clear_terminal() {
  for (int i = 0; i < 100; i++) {
    printf("\n");
  };
};

void show_timer() {
  // code
};

