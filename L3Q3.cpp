#include <iostream>
#include <conio.h>
#define MAX_SIZE 50

using namespace std;

class stack {
  int s[MAX_SIZE];
  int top[5], bottom[6];
public:
  stack() {
    top[0] = bottom[0] = -1;
    for(int i=1; i<5; i++)
      top[i] = bottom[i] = (MAX_SIZE/5)*i - 1;
    bottom[6] = MAX_SIZE -1;
  }

  void push(int n, int data) {
    if(top[n] == bottom[n+1]) {
      cout<<"Overflow!";
      return;
    }
    s[++top[n]] = data;
  }

  int pop(int n) {
    if(top[n] == bottom[n]) {
      cout<<"Underflow!";
      return -999;
    }
    return s[top[n]--];
  }

  void display(int n) {
    for(int i=bottom[n]+1; i<=top[n]; i++)
      cout << s[top[n]] << " ";
    cout<<"\n";
  }

};

int main() {
  stack s;
  int c, n, x;
  while(1) {
    cout<<"1.Push 2.Pop 3.Display: ";
    cin>>c;
    switch(c) {
      case 1: cin>>n; cin>>x; s.push(n,x); break;
      case 2: cin>>n; cout<< s.pop(n); break;
      case 3: cin>>n; s.display(n); break;
      case 4: return 0; break;
    }
  }
}
