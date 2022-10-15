#include <iostream>
#include <stdio.h>

struct Time {
  int hours;
  int minutes;
};

int sleep_time(); 
void shut_down();

int main() {
  using namespace std;

  int arr = sleep_time();

  cout << arr << endl;

  return 0;
};

int sleep_time() {
  // this function is getting time from user
  
  using namespace std;

  int digits[10];

  for(int i = 0; i < 10; i++) {
    digits[i] = i;  
  };

  // how function can return the list?
  return 0;
};

void shut_down() {
  //code
};
