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
  node* insertBefore(node *head, int data, int key);
  node* insertAfter(node *head, int data, int key);
  node* del(node *head, int key);
  void display(node *head);
  node* reverse(node *head);
  node* sort(node *head);
  node* delAlt(node *head);
  node* insertSorted(node *head, int data);
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

node* node::insertBefore(node *head, int data, int key) {
  if(head==NULL) {
    cout<<"Not found!";
    return NULL;
  }
  if(head->data == key) {
    node *temp = new node;
    temp->data = data;
    temp->next = head;
    return temp;
  }
  head->next = insertBefore(head->next, data, key);
  return head;
}

node* node::insertAfter(node *head, int data, int key) {
  if(head==NULL) {
    cout<<"Not found!";
    return NULL;
  }
  if(head->data == key) {
    node *temp = new node;
    temp->data = data;
    temp->next = head->next;
    head->next = temp;
    return head;
  }
  head->next = insertAfter(head->next, data, key);
  return head;
}

node* node::del(node *head, int key) {
  if(head==NULL) {
    cout<<"Not found!";
    return NULL;
  }
  if(head->data == key) {
    node *temp = head->next;
    delete(head);
    return temp;
  }
  head->next = del(head->next, key);
  return head;
}

void node::display(node *head) {
  if(!head)
    return;
  cout<<head->data<<" ";
  display(head->next);
}

node* node::reverse(node *head) {

}

node* node::sort(node *head) {

}

node* node::delAlt(node *head) {
  if(head==NULL || head->next == NULL)
    return head;
  node *temp = head->next;
  head->next = delAlt(head->next->next);
  delete(temp);
  return head;
}

node* node::insertSorted(node *head, int data) {
  if(head==NULL || data < head->data) { //head == NULL for end
    node *temp = new node;
    temp->data = data;
    temp->next = head;
    return temp;
  }
  head->next = insertSorted(head->next, data);
  return head;
}

int main() {
  node list, *head=NULL;
  int c, data, key;
  while(1) {
    cout<<"\n1. Insert\n2. Insert Before\n3. Insert After\n4. Delete\n5. Display\n6. Reverse\n7. Sort\n8. Delete Alt\n9. Insert Sorted\n";
    cin>>c;
    switch(c) {
      case 1: cin>>data; head = list.insert(head, data); break;
      case 2: cin>>key>>data; head = list.insertBefore(head, data, key); break;
      case 3: cin>>key>>data; head = list.insertAfter(head, data, key); break;
      case 4: cin>>key; head = list.del(head, key); break;
      case 5: list.display(head); break;
      case 6: break;
      case 7: break;
      case 8: head = list.delAlt(head); break;
      case 9: cin>>data; head = list.insertSorted(head, data); break;
      default: return 0;
    }
  }
}
