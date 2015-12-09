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
  char word[50];
  cin>>word;
  for(int i=0; i<strlen(word); i++)
    s.push(word[i]);
  for(int i=0; i<strlen(word); i++)
    if(word[i] != s.pop()) {
      cout<<"Not Palindrome!";
      getch();
      return 0;
    }
  cout<<"Palindome!";
  getch();
  return 0;
}
