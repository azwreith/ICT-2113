#include <iostream>
#include <conio.h>
#include <string.h>

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
    case ')': return 0; break;
  }
}

int inexp(char c) {
  switch(c) {
    case '+':
    case '-': return 1; break;
    case '/':
    case '*': return 2; break;
    case '$': return 4;
    case ')': return 5;
  }
}

int main() {
  stack s;
  char infix[20], prefix[20], c;
  int i=0, j=0;
  cin>>infix;
  strrev(infix);
  s.push('#');
  while(infix[i]!='\0') {
    c = infix[i];
    if((c>=48 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122))
      prefix[j++] = c;
    else if(c=='(') {
      while(s.stktop()!=')')
        prefix[j++] = s.pop();
      s.pop();
    }
    else {
      while(instack(s.stktop()) > inexp(c))
        prefix[j++] = s.pop();
      s.push(c);
    }
    i++;
  }

  while(s.stktop()!='#')
    prefix[j++] = s.pop();
  prefix[j] = '\0';
  strrev(prefix);
  cout<<prefix;
  getch();
  return 0;
}
