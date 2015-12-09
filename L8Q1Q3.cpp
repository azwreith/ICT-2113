#inlcude <iostream>
#inlcude <conio.h>

using namespace std;

class node {

  node *prev, *next;
  int data;
public:
  node() {
    prev = next = NULL;
  }
  node* insert(node*, int);
  node* insertBefore(node*, int, int);
  node* insertAfter(node*, int, int);
  node* del(node*, int);
  void display(node*);
  node* reverse(node*);
  node* concat(node*, node*);

};

node* node::insert(node *head, int data) { //For iterative, gotta check if head is null(for first node), if not, iterate till head->next is null and insert
  if(head==NULL) {
    node *temp = new node;
    temp->data = data;
    return temp;
  }
  head->next = insert(head->next, data);
  head->next->prev = head;
  return head;
}

node* node::insertBefore(node* head, int key, int data) {
  if(!head) {
    cout<<"Not Found!";
    return NULL;
  }
  if(head->data == key) {
    node *temp = new node;
    temp->data = data;
    temp->next = head;
    temp->prev = head->prev;
    head->prev = temp;
    return temp;
  }
  head->next = insertBefore(head->next, key, data);
  return head;
}

node* node::insertAfter(node *head, int key, int data) { //can be made void
  if(!head) {
    cout<<"Not Found!";
    return NULL;
  }
  if(head->data == key) {
    node *temp = new node;
    temp->data = data;
    temp->next = head->next;
    temp->prev = head;
    if(head->next)
      head->next->prev = temp;
    head->next = temp;
    return head;
  }
  head->next = insertAfter(head->next, key, data);
}

node* node::del(node* head, int key) {
  if(!head) {
    cout<<"Not Found!";
    return NULL;
  }
  if(head == key) {
    node *temp = head->next;
    if(temp)
      temp->prev = head->prev;
    delete(head);
    return temp;
  }
  head->next = del(head, key);
}

void node::display(node *head) {
  if(!head)
    return;
  cout<< head->data << " ";
  display(head->next);
}

node* node::reverse(node *head) {
  while(head->next) {
    node *temp = head->next;
    head->next = head->prev;
    head->prev = temp;
    head = temp;
  }
  head->next = head->prev;
  head->prev = NULL;
  return head;
}

node* node::concat(node *h1, node *h2) {
  if(!h1)
    return h2;
  h1->next = concat(h1->next, h2);
  return h1;
}

int main() {
  
}
