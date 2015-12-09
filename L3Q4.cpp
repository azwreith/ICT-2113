#include <iostream>
#include <conio.h>
#include <string.h>
#define MAX_SIZE 20

using namespace std;

class stack {
  char s[MAX_SIZE];
  int top;
public:
  stack() {
    top = -1;
  }
  void push(char data) {
    if(top==MAX_SIZE - 1)
      return;
    s[++top] = data;
  }

  char pop() {
    if(top == -1)
      return '\0';
    return s[top--];
  }

};

int main() {
  stack s;
  int flag = 1;
  char exp[50], c;
  cin>>exp;
  
  for(int i=0; i<strlen(exp); i++) {
    if(exp[i] == '(' || exp[i] == '[' || exp[i] == '<')
      s.push(exp[i]);
    else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '>') {
      switch(exp[i]) {
        case ')': if(s.pop()!='(') flag = 0; break;
        case ']': if(s.pop()!='[') flag = 0; break;
        case '>': if(s.pop()!='<') flag = 0; break;
      }
    }
  }

  if(s.pop() != '\0')
    flag = 0;
  if(flag == 0)
    cout<<"Not Matching";
  else
    cout<<"Matching";
  getch();
  return 0;
}
