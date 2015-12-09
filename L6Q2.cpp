#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>

using namespace std;

class stack {
  int s[20];
  int top;
public:
  stack() {
    top = -1;
  }
  void push(int data) {
    s[++top] = data;
  }

  int pop() {
    return s[top--];
  }

};

int operate(char op, int op1, int op2) {
  switch(op) {
    case '+': return op1+op2;
    case '-': return op1-op2;
    case '/': return op1/op2;
    case '*': return op1*op2;
    case '$': return pow(op1,op2);
  }
}

int isOperator(char op) {
  if(op=='+' || op=='-' || op=='/' || op=='*' || op=='$')
    return 1;
  return 0;
}

int main() {
  stack s;
  char prefix[20], c;
  int op1, op2;
  int i = 0;
  cin>>prefix;
  strrev(prefix);
  while(prefix[i] != '\0') {
    c = prefix[i];
    if(isOperator(c)) {
      op1 = s.pop();
      op2 = s.pop();
      s.push(operate(c, op1, op2));
    }
    else
      s.push(c-'0');
    i++;
  }
  cout<< s.pop();
  getch();
  return 0;
}
