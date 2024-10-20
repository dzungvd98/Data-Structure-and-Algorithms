#include<iostream>

using namespace std;
struct node {
	int key;
	int info;
	struct node *left;
	struct node *right;
};
	
typedef node *NODEPTR;
NODEPTR tree = NULL;

void Initialize(NODEPTR &root) {
	root = NULL;
}

void Insert_Node(NODEPTR &p, int x, int a) {
	if(p == NULL) {
		p = new node;
		p->key = x;
		p->info = a;
		p->left = nullptr;
		p->right = nullptr;
	} else if(x < p->key) {
		Insert_Node(p->left, x, a); 
	} else if(x > p->key) {
		Insert_Node(p->right, x, a);
	}
    

int main() {
	
}