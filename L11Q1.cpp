#include <iostream>

using namespace std;

class tree {
	tree *left, *right;
	int data;
public:
	tree() {
		left = right = NULL;
	}

	tree *insert(tree *, int);
	tree *del(tree *, int);
	void search(tree *, int);
	void display(tree *);
	void levelOrder(tree *);
};

class queue {
	friend tree;
	tree* nodes[50];
	int front, rear;
	queue() {
		front = 0;
		rear = -1;
	}
	void enQueue(tree* data) {
		nodes[++rear] = data;
	}
	tree* deQueue() {
		if(rear < front)
			return NULL;
		return nodes[front++];
	}
};

tree * tree::insert(tree *root, int data) {
	if(root == NULL) {
		tree *temp = new tree;
		temp->data = data;
		return temp;
	}
	else if(root->data > data) {
		root->left = insert(root->left, data);
		return root;
	}
	else if(root->data < data) {
		root->right = insert(root->right, data);
		return root;
	}
	else {
		cout<<"Element already exists!";
		return root;
	}
}

tree * tree::del(tree *root, int key) {
    if(root == NULL)
    	return root;
    if(key < root->data)
        root->left = del(root->left, key);
    else if(key > root->data)
        root->right = del(root->right, key);
    else {
        // node with only one child or no child
        if(root->left == NULL) {
            tree *temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right == NULL) {
            tree *temp = root->left;
            delete(root);
            return temp;
        }
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        tree* temp = root->right;
				while(temp->left != NULL)
						temp = temp->left;
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        // Delete the inorder successor
        root->right = del(root->right, temp->data);
    }
    return root;
}

void tree::search(tree *root, int key) {
	if(root == NULL)
		return;
	if(root->data == key) {
		cout<<"Element found!";
		return;
	}
	else if(root-> data > key)
		search(root->left, key);
	else
		search(root->right, key);
}

void tree::display(tree *root) {
	if(root==NULL)
		return;
	display(root->left);
	cout << root->data << " ";
	display(root->right);
}

void tree::levelOrder(tree *root) {
	queue q;
	tree *temp = root;
	while(temp) {
		cout<<temp->data << " " ;
		if(temp->left)
			q.enQueue(temp->left);
		if(temp->right)
			q.enQueue(temp->right);
		temp = q.deQueue();
	}
}


int main() {
	tree t, *root = NULL;
	int c, data;
	while(1) {
		cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Level Order\n";
		cin>>c;
		switch(c) {
		case 1:
			cin>>data;
			root = t.insert(root, data);
			break;
		case 2:
			cin>>data;
			root = t.del(root, data);
			break;
		case 3:
			cin>>data;
			t.search(root, data);
			break;
		case 4:
			t.display(root);
			break;
		case 5:
			t.levelOrder(root);
			break;
		}
	}
	return 0;
}
