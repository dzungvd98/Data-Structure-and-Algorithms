#include<iostream>

using namespace std;

struct node {
	int info;
	struct node *left, *right;
};

typedef struct node *NODEPTR;
NODEPTR First, Last;

void Initialize(NODEPTR &First) {
	First = NULL;
}

NODEPTR New_node(void) {
	NODEPTR p;
	p = new node;
	return (p);
}

void Insert_First(NODEPTR &First, NODEPTR &Last, int x) {
	NODEPTR p;
	p = new node;
	p->info = x;
	p->left = NULL;
	p->right = First;
	if(First == NULL) {
		Last = p;
	} else First->left = p;
	First = p;
}

void Insert_Right(NODEPTR p, NODEPTR &Last, int x) {
	NODEPTR q, r;
	if(p == NULL) {
		cout << "Nut khong ton tai, khong them duoc" << endl;
	} else {
		q = new node;
		q->info = x;

		r= p->right;
		
		if(r != NULL) {
			r->left = q;
		}
		q->right = r;
		
		q->left = p;
		p->right = q;
		
		if(p == Last) Last =q;
	}
}

void Insert_Left(NODEPTR &First, NODEPTR p, int x) {
	NODEPTR q, l;
	if(p == NULL) {
		cout << "Nut khong ton tai, khong them duoc" << endl;
	} else {
		if(p == First) {
			Insert_First(First, p);
		} else {
			q = new node;
			q->info = x;
			l = p->left;
			
			q->left = l;
			l->right = q;
			
			q->right = p;
			p->left = q;
			
		}
	}
}

void Right_traverse(NODEPTR First) {
	NODEPTR p;
	if(empty(First)) {
		cout << "Khong co doan nao" << endl;
	} else {
		p = First;
		while(p!= NULL) {
			cout << p->info << " ";
			p = p->right;
		}
	}
}

void Left_traverse(NODEPTR First, NODEPTR Last) {
	NODEPTR p;
	if(empty(First)) {
		cout << "Khong co doan nao" << endl;
	} else {
		p = Last;
		while(p != NULL) {
			cout << p->info << " ";
			p = p->left;
		}
	}
}

bool Empty(NODEPTR First) {
	return First == NULL;
}

void Delete_first(NODEPTR &First) {
	NODEPTR p;
	if(empty(First)) {
		cout << "Danh sach rong, khong xoa duoc" << endl;
	} else {
		p = First;
		if(First->right == NULL) {
			First = NULL;
		} else {
			First = p->right;
			First->left = NULL;
		}
		delete p;
	}
}

void clearList(NODEPTR &First) {
	while(First != NULL) {
		Delete_first(First);
	}
}

void Search_Info(NODEPTR First, int x) {
	NODEPTR p = First;
	while(p->info != x && p != NULL) {
		p = p->right;
	}
	return p;
}



int main() {
	
}