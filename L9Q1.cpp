#include <iostream>
#include <conio.h>

using namespace std;

class node {
  node *next;
  int coeff, power;
public:
  node() {
    coeff = power = 0;
    next = this;
  }

  node* insert(node*, int, int);
  void display(node*);
  node* add(node*, node*, node*);
  node* mult(node*, node*, node*);
};

node* node::insert(node* head, int coeff, int power) {
  node *iterator = head->next;
  while(iterator->next!=head)
    iterator = iterator->next;
  node* temp = new node();
  temp->coeff = coeff;
  temp->power = power;
  iterator->next = temp;
  temp->next = head;
  return head;
}

void node::display(node* head) {
  node *iterator = head->next;
  while(iterator!=head) {
    cout<< iterator->coeff << "x^" << iterator->power << " + ";
    iterator = iterator->next;
  }
  cout<<"cake";
}

node* node::add(node *h1, node *h2, node * h3) {
  node *a = h1->next, *b = h2->next;
  while(a!=h1 && b!= h2) {
    if(a->power == b->power) {
      h3 = insert(h3, a->coeff + b->coeff, a->power);
      a = a->next;
      b = b->next;
    }
    else if(a->power < b->power) {
      h3 = insert(h3, a->coeff, a->power);
      a = a->next;
    }
    else {
      h3 = insert(h3, b->coeff, b->power);
      b = b->next;
    }
  }
  while(a!=h1) {
    h3 = insert(h3, a->coeff, a->power);
    a = a->next;
  }
  while(b!=h2) {
    h3 = insert(h3, b->coeff, b->power);
    b = b->next;
  }
  return h3;
}

node* node::mult(node *h1, node *h2, node * h3) {
  node *a = h1->next;
  int flag, coeff, power;
  while(a!=h1) {
    node *b = h2->next;
    while(b!=h2) {
      coeff = a->coeff * b->coeff;
      power = a->power + b->power;
      flag = 0;
      node *c = h3->next;
      while(c!=h3) {
        if(power == c->power) {
          flag = 1;
          c->coeff+= coeff;
        }
        c = c->next;
      }
      if(flag == 0)
        h3 = insert(h3, coeff, power);
      b = b->next;
    }
    a = a->next;
  }
  return h3;
}


int main() {
  node list, *h1 = new node, *h2 = new node, *h3 = new node;
  int coeff, power, n;

  cout<<"Enter no. of elements in Poly 1: ";
  cin>> n;
  for(int i=0; i<n; i++) {
    cout<<"Enter coeff & power: ";
    cin>>coeff>>power;
    h1 = list.insert(h1, coeff, power);
  }

  cout<<"Enter no. of elements in Poly 2: ";
  cin>> n;
  for(int i=0; i<n; i++) {
    cout<<"Enter coeff & power: ";
    cin>>coeff>>power;
    h2 = list.insert(h2, coeff, power);
  }

  h3 = list.add(h1, h2, h3);
  cout<<"\nAddition is: ";
  list.display(h3);

  h3 = new node;
  h3 = list.mult(h1, h2, h3);
  cout<<"\nMultiplication is: ";
  list.display(h3);

  getch();
  return 0;
}
