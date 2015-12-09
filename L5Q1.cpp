#include <iostream>
#include <conio.h>

using namespace std;

class stack {
  char s[20];
  int top;
public:
  stack() {
    top = -1;
  }
  void push(char data) {
    s[++top] = data;
  }

  char pop() {
    return s[top--];
  }

  char stktop() {
    return s[top];
  }

};

int instack(char c) {
  switch(c) {
    case '#': return -1; break;
    case '+':
    case '-': return 1; break;
    case '/':
    case '*': return 2; break;
    case '$': return 3; break;
    case '(': return 0; break;
  }
}

int inexp(char c) {
  switch(c) {
    case '+':
    case '-': return 1; break;
    case '/':
    case '*': return 2; break;
    case '$': return 4;
    case '(': return 5;
  }
}

int main() {
  stack s;
  char infix[20], postfix[20], c;
  int i=0, j=0;
  cin>>infix;
  s.push('#');
  while(infix[i]!='\0') {
    c = infix[i];
    if((c>=48 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122))
      postfix[j++] = c;
    else if(c==')') {
      while(s.stktop()!='(')
        postfix[j++] = s.pop();
      s.pop();
      }
    else {
      while(instack(s.stktop()) >= inexp(c))
        postfix[j++] = s.pop();
      s.push(c);
    }
    i++;
  }

  while(s.stktop()!='#')
    postfix[j++] = s.pop();
  postfix[j] = '\0';
  cout<<postfix;
  getch();
  return 0;
}
