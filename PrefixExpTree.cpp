#include <iostream>
#include <conio.h>
#include <string.h>
#include <math.h>

using namespace std;

class btree {
  char data;
  btree *lc, *rc;
public:
btree() {
  lc = rc = NULL;
}

btree* create(char prefix[30]);
int isOperator(char);
void preorder(btree* root);
char evaluate(btree* root);
char operate(char op, int op1, int op2);
void inorder(btree *root);

};

class stack {
  friend class btree;
  btree* nodes[30];
  int top;
  stack() {
    top = -1;
  }
  void push(btree *data) {
    nodes[++top] = data;
  }
  btree* pop() {
    return nodes[top--];
  }
};


btree* btree::create(char prefix[30]) {
  char c;
  stack s;
  btree *op1, *op2;
  strrev(prefix);
  int i = 0;
  while(prefix[i]!='\0') {
    c = prefix[i];
    if(isOperator(c)) {
      op1 = s.pop();
      op2 = s.pop();
      btree *temp = new btree;
      temp->data = c;
      temp->lc = op1;
      temp->rc = op2;
      s.push(temp);
    }
    else {
      btree *temp = new btree;
      temp->data = c;
      s.push(temp);
    }
    i++;
  }
  return s.pop();
}

void btree::preorder(btree *root) {
  if(!root)
    return;
  cout<<root->data;
  preorder(root->lc);
  preorder(root->rc);
}

char btree::evaluate(btree* root) {
  if(!root)
    return '\0';
  char op1 = evaluate(root->lc);
  char op2 = evaluate(root->rc);
  if(!isOperator(root->data))
    return root->data;
  else {
    root->data = operate(root->data, op1 - '0', op2 - '0');
    return root->data;
  }
}

char btree::operate(char op, int op1, int op2) {
  switch(op) {
    case '+': return op1+op2 + '0';
    case '-': return op1-op2 + '0';
    case '/': return op1/op2 + '0';
    case '*': return op1*op2 + '0';
    case '$': return pow(op1, op2) + '0';
  }
}

int btree::isOperator(char c) {
  if(c == '+' || c == '-' || c == '/' || c == '*' || c == '$')
    return 1;
  return 0;
}

void btree::inorder(btree *root) {
  if(!root)
    return;
  if(isOperator(root->data)) {
    cout<<"(";
    inorder(root->lc);
    cout<<root->data;
    inorder(root->rc);
    cout<<")";
  }
  else
    cout<<root->data;
}

int main() {
  btree t;
  char prefix[50];
  cin>>prefix;
  btree *root = t.create(prefix);
  t.preorder(root);
  cout<<"\n";
  t.inorder(root);
  cout<<"\n"<<t.evaluate(root);
  getch();
  return 0;
}
