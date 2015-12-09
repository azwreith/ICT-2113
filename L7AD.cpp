#include <iostream>
#include <conio.h>

using namespace std;

class node {
  node *next;
  int data;
public:
  node() {
    next = NULL;
  }

  node* insert(node *head, int data);
  node* mergeSortedList(node *h1, node *h2);
  node* mergeList(node *h1, node *h2);
  void display(node *head);
};

node* node::insert(node *head, int data) {
  if(head == NULL) {
    node *temp = new node;
    temp->data = data;
    return temp;
  }
  head->next = insert(head->next, data);
  return head;
}

node* node::mergeSortedList(node *h1, node *h2) {
  if(h1==NULL)
    return h2;
  if(h2==NULL)
    return h1;
  if(h1->data < h2->data) {
    h1->next = mergeSortedList(h1->next, h2);
    return h1;
  }
  h2->next = mergeSortedList(h1, h2->next);
  return h2;
}

node* node::mergeList(node *h1, node *h2) {
  if(h1==NULL)
    return h2;
  if(h2==NULL)
    return h1;
  h1->next = mergeList(h2, h1->next);
  return h1;
}

void node::display(node *head) {
  if(head == NULL)
    return;
  cout<<head->data;
  display(head->next);
}

int main() {
  node list, *h1 = NULL, *h2 = NULL;
  int c, data;
  while(1) {
    cout<<"\n1. Insert L1\n2. Insert L2\n3. Merge Sorted(AD2)\n4. Merge(AD3)\n5. Display Merge Result\n";
    cin>>c;
    switch(c) {
      case 1: cin>>data; h1 = list.insert(h1, data); break;
      case 2: cin>>data; h2 = list.insert(h2, data); break;
      case 3: h1 = list.mergeSortedList(h1, h2); break;
      case 4: h1 = list.mergeList(h1, h2); break;
      case 5: list.display(h1); break;
      default: return 0;
    }
  }
}
