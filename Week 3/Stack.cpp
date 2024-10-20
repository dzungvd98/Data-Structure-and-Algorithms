#include<iostream>

using namespace std;

struct node {
	int info;
	node *next;
};
typedef node *Stack;

void push(Stack &sp, int x) {
	Stack p;
	p = new node;
	p->info = x;
	p->next = sp;
	sp = p;
}

void pop(Stack &sp, int &x) {
	if(sp == NULL) return 0;
	x = sp->info;
	Stack p = sp;
	sp = p->next;
	delete p;
	return x;
}

int main() {
	
}