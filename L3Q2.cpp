#include <iostream>
#include <conio.h>
#define MAX_SIZE 20

using namespace std;

class stack {
  int s[MAX_SIZE];
  int top;
public:
  stack() {
    top = -1;
  }
  void push(int data) {
    if(top==MAX_SIZE - 1)
      return;
    s[++top] = data;
  }

  void display() {
    for(int i=top; i>-1; i--) {
      switch(s[i]) {
        case 10: cout<<'A'; break;
        case 11: cout<<'B'; break;
        case 12: cout<<'C'; break;
        case 13: cout<<'D'; break;
        case 14: cout<<'E'; break;
        case 15: cout<<'F'; break;
        default: cout<<s[i];
      }
    }
  }

};

int main() {
  stack s;
  int num, base;
  cin>> num >> base;
  while(num!=0) {
    s.push(num%base);
    num = num/base;
  }
  s.display();
  getch();
  return 0;
}
