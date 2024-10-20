#include <iostream>
using namespace std;

struct node {
	int info;
	node *next;
};

typedef node *PTR;

void Initialize(PRT &First) {
	First = NULL;
}

void Insert_First(PTR &First, int x) {
	PTR p;
	p = new node;
	p->info = x;
	p->next = First;
	First = p;
}


void Insert_After(PTR &p, int x) {
	PRT q;
	if(p == NULL) {
		cout << "Khong them duoc vao danh sach rong";
	}
	q = new node;
	q->info = x;
	q->next = p->next;
	p->next = q;
}

PTR Search_Info(PTR First, int x) {
	PTR p;
	for(p = First; p != NULL; p = p->next) {
		if(p->info = x) return p;
	}
	return NULL;
}

bool Empty(PTR First) {
	return First == NULL;
}

bool Delete_First(PTR &First) {
	PTR p;
	if(Empty(First)) return 0;
	p = First;
	First = p->next;
	delete p;
	return 1;
}

bool Delete_After(PTR p) {
	PTR q;
	if(p = NULL || p->next = NULL) return 0;
	q = p->next;
	p->next = q->next;
	delete q;
	return 1;
}

// Xoa 1 phan tu theo noi dung
bool Delete_Info(PTR &First, int x) {
	PTR p;
	if(First == NULL) return  0;
	if(First->info == x) {
		Delete_First(First); return 1;
	}
	
	for(p = First; p->next != NULL && p->next->info != x; p = p->next);
	
	if(p->next != NULL) {
		Delete_After(p);
		return 1;
	}
	return 0;
}

// Xoa toan bo phan tu theo noi dung
bool Delete_All_Info(PTR &First, int x) {
	int count = 0;
	PTR p;
	if(First == NULL) return 0;
	while(First->info == x && First != NULL) {
		Delete_First(First);
		count++;
	}
	
	if(First == NULL) return 0;
	
	for(p = First; p->next != NULL) {
		if(p->next->info == x) {
			Delete_After(p);
			count++;
		} else {
			p = p->next;
		}
	}
	
	if(p->info == x) {
		count++;
		delete p;
	}
	return count;
}

// Xoa toan bo danh sach
void Clear_List(PTR &First) {
	PTR p;
	while(First != NULL) {
		Delete_First(First);
	}
}

// Duyet danh sach
void Traverse(PTR First) {
	PTR p;
	int stt = 0;
	for(p = First; p != NULL; p=p->next) {
		cout << stt++ << " " << p->info << endl;
	}
}

void Selection_Sort(PTR &First) {
	PTR p, q, pmin; int min;
	for(p = First; p->next != NULL; p = p->next) {
		min = p->info;
		pmin = p;
		for(q = p->next; q != NULL; q = q->next) {
			if(q->info < min) {
				min = q->info;
				pmin = q;
			}
		}
		
		// hoan doi truong info cua p va pmin;
		pmin->info = p->info;
		p->info = min;
	}
}

// Them vao danh sach co thu tu
void Insert_Order(PTR &First, int x) {
	PTR p, t, s; // t la nut truoc, s la nut sau;
	p = new node;
	p->info = x;
	for(s = First; s != NULL && s->info < x; t = s; s = s->next);
	if(s == First) {// them nut vao dau danh sach;
		p->next = First;
		First = p;
	} else {
		p->next = s;
		t->next = p;
	}
} 

struct Queue() {
	PTR Front, Rear;
}

void Insert_Queue(Queue &q, int x) {
	PTR p;
	p = new node;
	p->info = x;
	p->next = NULL;
	if(q.Front == NULL) {
		q.Front = p;
	} else {
		q.Rear->next = p;
		q.Rear = p;
	}
}

int Delete_Queue(Queue &q, int &x) {
	
	if(q.Front == NULL) return 0;
	PTR p = q.Front;
	x = p->info;
	q.Front = p->next;
	
	if(q.Front == NULL) q.Rear = NULL;
	delete p;
	return x;
}


int main() {

}

