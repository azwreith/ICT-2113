#include <iostream>
#include <conio.h>
#define SIZE 20

using namespace std;

class cqueue {
  int a[SIZE];
  int front, rear;
public:
  cqueue() {
    front = rear = 0;
  }

  void enqueue(int data) {
    if((rear+1)%SIZE == front) {
      cout<<"Full";
      return;
    }
    a[rear] = data;
    rear = (rear+1) % SIZE;
  }

  int dequeue() {
    if(rear == front) {
      cout<<"Empty";
      return -1;
    }
    int c = a[front];
    front = (front+1) % SIZE;
    return c;
  }

  void display() {
    int i=front;
    while(i!=rear) {
      cout<<a[i] << " ";
      i = (i+1) % SIZE;
    }
  }

};

int main() {
  cqueue q;
  int c, x;
  while(1) {
    cout<<"\n1. Enqueue\n2. Dequeue\n3. Display\n";
    cin>>c;
    switch(c) {
      case 1: cin>>x; q.enqueue(x); break;
      case 2: cout<< q.dequeue(); break;
      case 3: q.display(); break;
      case 4: return 0;
    }
  }

}
