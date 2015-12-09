#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

class stack {
  char s[30][30];
  int top;
public:
  stack() {
    top = -1;
  }
  void push(char data[]) {
    strcpy(s[++top],data);
  }

  char* pop() {
    return s[top--];
  }

};


int isOperator(char op) {
  if(op=='+' || op=='-' || op=='/' || op=='*' || op=='$')
    return 1;
  return 0;
}

int main() {
  stack s;
  char postfix[30], c[2], op1[30], op2[30], temp[30];
  int i = 0;
  cin>>postfix;
  while(postfix[i] != '\0') {
    c[0] = postfix[i];
    c[1] = '\0';
    if(isOperator(c[0])) {
      strcpy(op1, s.pop());
      strcpy(op2, s.pop());
      strcpy(temp, "(");
      strcat(temp, op2);
      strcat(temp, c);
      strcat(temp, op1);
      strcat(temp, ")");
      s.push(temp);
    }
    else
      s.push(c);
    i++;
  }
  cout<< s.pop();
  getch();
  return 0;
}
