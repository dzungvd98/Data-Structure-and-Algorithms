#include<iostream>

using namespace std;
struct SinhVien {
	int mssv;
	char ho[30];
	char ten[10];
};

struct Node {
	SinhVien info;
	Node *next;
};

typedef Node *PTRSV;

// Tạo một node mới
PTRSV new_Node() {
	PTRSV p = new Node;
	return p;
}

// Khởi động danh sách
void initialize(PTRSV &First) {
	First = NULL;
}

// Kiểm tra danh sách rỗng
bool empty(PTRSV First) {
	return First == NULL;
}

void insertFirst(PTRSV &First, SinhVien x) {
	PTRSV p = new_Node();
	p->info = x;
	p->next = First;
	First = p;
}

bool deleteNode(PTRSV &First, PTRSV p) {
	if(empty(First) || p == NULL) return false;
	
	// Nếu p là nút đầu tiên
	if(First == p) {
		First = First->next;
		delete p;
		return true;
	}
	
	// Tìm nút trước p
	PTRSV current = First;
	while(current!= NULL && current->next != p) {
		current = current->next;
	}
	
	// Nếu tìm thấy
	if(current != NULL) {
		current->next = p->next;
		delete p;
		return true;
	}
	return false;
}

// Hàm xóa tất cả các node có nội dung x
int removeAll(PTRSV &First, SinhVien x) {
	int count = 0;
	if(empty(First)) return count;
	
	PTRSV current = First;
	PTRSV prev = NULL;
	while(current != NULL) {
		if(current->info.mssv == x.mssv) {
			if(prev == NULL) {
				// Nếu nút hiện tại là nút đầu
				First = current->next;
				delete current;
				count++;
				current = First;
			} else {
				prev->next = current->next;
				delete current;
				count++;
				current = prev->next;
			}
		} else {
			prev = current;
			current = current->next;
		}
	}
	return count;
}

// Hàm sao chép danh sách
PTRSV copyList(PTRSV First) {
	if (empty(First)) return NULL; 

    PTRSV newList = NULL; 
    PTRSV lastNode = NULL;
    PTRSV current = First; 

    while (current != NULL) {
        // Tạo nút mới
        PTRSV newNode = new_Node();
        newNode->info = current->info; // Sao chép thông tin

        // Nếu danh sách mới rỗng, nút mới là nút đầu tiên
        if (newList == NULL) {
            newList = newNode;
        } else {
            lastNode->next = newNode; // Kết nối nút cuối cùng với nút mới
        }

        lastNode = newNode; // Cập nhật lastNode thành nút mới
        current = current->next; // Di chuyển đến nút tiếp theo trong danh sách cũ
    }

    return newList; // Trả về danh sách mới
}

// Hàm in danh sách liên kết
void printList(PTRSV First) {
    if (empty(First)) {
        cout << "Danh sach rong." << endl; // Thông báo nếu danh sách rỗng
        return;
    }

    PTRSV current = First; // Khởi tạo con trỏ để duyệt danh sách
    while (current != NULL) {
        // In thông tin sinh viên
        cout << "MSSV: " << current->info.mssv
             << ", Ho: " << current->info.ho
             << ", Ten: " << current->info.ten << endl;

        current = current->next; // Di chuyển đến nút tiếp theo
    }
}


// Ghép danh sách First2 vào sau phần tử thứ i của danh sách First1
void Merge_List(PTRSV &First1, PTRSV First2, int i) {
    if (First2 == NULL) return; // Nếu danh sách thứ hai rỗng, không làm gì cả

    PTRSV current = First1; // Duyệt qua danh sách First1
    PTRSV prev = NULL; // Dùng để giữ nút trước current
    int count = 0; // Đếm số lượng nút đã duyệt

    // Duyệt đến nút thứ i
    while (current != NULL && count < i) {
        prev = current; // Cập nhật nút trước
        current = current->next; // Di chuyển đến nút tiếp theo
        count++;
    }

    // Nếu danh sách First1 rỗng hoặc i = 0, thêm vào đầu danh sách First1
    if (prev == NULL) {
        // Kết nối nút cuối của First2 với danh sách First1
        PTRSV lastNode = First2;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = First1; // Kết nối nút cuối của First2 với First1
        First1 = First2; // Cập nhật First1
        return;
    }

    // Kết nối nút trước current với First2
    prev->next = First2;

    // Tìm nút cuối của danh sách First2
    PTRSV lastNode = First2;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next; // Duyệt đến nút cuối của First2
    }
    
    // Kết nối nút cuối của First2 với current
    lastNode->next = current;
}

// Đảo ngược vùng liên kết trong danh sách liên kết
void Reverse_Linked_List(PTRSV &First) {
    if (empty(First)) return; // Nếu danh sách rỗng, không làm gì cả

    PTRSV prev = NULL;  // Nút trước
    PTRSV current = First;  // Nút hiện tại
    PTRSV next = NULL;  // Nút tiếp theo

    // Duyệt qua danh sách và đảo ngược các liên kết
    while (current != NULL) {
        next = current->next; // Lưu nút tiếp theo
        current->next = prev; // Đảo ngược liên kết
        prev = current; // Cập nhật nút trước
        current = next; // Di chuyển đến nút tiếp theo
    }

    // Cập nhật First để trỏ đến phần tử cuối
    First = prev; // Cập nhật First
}

// Hàm in danh sách (giúp kiểm tra)
void printList(PTRSV First) {
    while (First != NULL) {
        cout << First->info.mssv << " ";
        First = First->next;
    }
    cout << endl;
}


// Duyệt ngược danh sách liên kết
void Left_Traverse(PTRSV First) {
    if (First == NULL) return; // Nếu danh sách rỗng, không làm gì cả

    // Duyệt đến nút cuối
    Left_Traverse(First->next);

    // In giá trị sau khi trở lại
    cout << First->info.mssv << " ";
}

// Hàm in danh sách (giúp kiểm tra)
void printList(PTRSV First) {
    while (First != NULL) {
        cout << First->info.mssv << " ";
        First = First->next;
    }
    cout << endl;
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n <= 1) return false; // Các số <= 1 không phải số nguyên tố
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false; // Nếu n chia hết cho i thì không phải số nguyên tố
    }
    return true; // Nếu không chia hết cho bất kỳ số nào thì là số nguyên tố
}

void Split_List(PTRSV First, PTRSV &PrimeList, PTRSV &NonPrimeList) {
    // Khởi động hai danh sách mới
    initialize(PrimeList);
    initialize(NonPrimeList);

    PTRSV current = First; // Duyệt qua danh sách chính

    while (current != NULL) {
        if (isPrime(current->info.mssv)) {
            // Nếu là số nguyên tố, thêm vào PrimeList
            insertFirst(PrimeList, current->info);
        } else {
            // Nếu không phải, thêm vào NonPrimeList
            insertFirst(NonPrimeList, current->info);
        }
        current = current->next; // Di chuyển đến nút tiếp theo
    }
}





int main() {
	PTRSV danhSach;
    initialize(danhSach);

    SinhVien sv1 = {1, "Nguyen", "An"};
    SinhVien sv2 = {2, "Tran", "Binh"};
    
    insertFirst(danhSach, sv1);
    insertFirst(danhSach, sv2);

    cout << "Danh sach goc:\n";
    printList(danhSach);

    // Sao chép danh sách
    PTRSV danhSachSaoChep = copyList(danhSach);
    
    cout << "\nDanh sach sau khi sao chep:\n";
    printList(danhSachSaoChep);
}          