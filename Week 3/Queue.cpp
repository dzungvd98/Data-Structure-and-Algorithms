#include<iostream>

using namespace std;

struct node {
	int info;
	node *next;
}

typedef node *PTR;
struct Queue {
	PTR Front, Rear;
};

void Insert_queue(Queue &q, int x) {
	PTR p;
	p = new node;
	p->info = x;
	p->next = NULL;
	if(q.Front == NULL) {
		q.Front = p;
	} else q.Rear->next = p;
	q.Rear = p;
}

int Delete_queue(Queue &q, int &x) {
	if(q.Front = NULL) return 0;
	PTR p = q.Front;
	q.Front = p->next;
	delete p;
	return 1;
}

int main() {
	
}