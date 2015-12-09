#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class btree {
  int data;
  btree *lc, *rc;
public:
  btree() {
    lc = rc = NULL;
  }

  btree* create(btree* root);
  // void inorder(btree*);
  // void postorder(btree*);
  // void preorder(btree*);
  void parent(btree*, int);
  int dept(btree*);
  int ancestor(btree*, int);
  int leaves(btree*);
};

btree* btree::create(btree* root) {
    int data;
    cin>>data;
    if(data!=-1) {
      root = new btree;
      root->data = data;
      cout<<"Enter data for lc of " << root->data << "(-1 to discard): ";
      root->lc = create(root->lc);
      cout<<"Enter data for rc of " << root->data << "(-1 to discard): ";
      root->rc = create(root->rc);
    }
    return root;
}

void btree::parent(btree* root, int key) {
  if(root==NULL)
    return;
  if(root->lc && root->lc->data == key) {
    cout<<root->data;
    return;
  }
  if(root->rc && root->rc->data ==key) {
    cout<<root->data;
    return;
  }
  parent(root->lc, key);
  parent(root->rc, key);
}

int btree::dept(btree* root) {
  if(root == NULL)
    return 0;
  return max(dept(root->lc),dept(root->rc)) + 1;
}

int btree::ancestor(btree* root, int key) {
  if(root == NULL)
    return 0;
  if(root->data == key)
    return 1;
  if(ancestor(root->lc, key) || ancestor(root->rc, key)) {
    cout<<root->data<<" ";
    return 1;
  }
  return 0;
}

int btree::leaves(btree *root) {
  if(root == NULL)
    return 0;
  if(root->lc == NULL && root->rc == NULL)
    return 1;
  return leaves(root->lc) + leaves(root->rc);
}

int main() {
  btree t, *root = NULL;
  int c, data;
  while(1) {
    cout<<"\nChoose: ";
    cin>>c;
    switch(c) {
      case 1: root = t.create(root); break;
      case 2: case 3: case 4: break;
      case 5: cin>>data; t.parent(root, data); break;
      case 6: cout<< t.dept(root); break;
      case 7: cin>>data; t.ancestor(root, data); break;
      case 8: cout<< t.leaves(root); break;
      default: return 0;
    }
  }
}
