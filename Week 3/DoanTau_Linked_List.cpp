#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

#define TRUE 1
#define FALSE 0

// Cấu trúc của một đoạn đường trên tuyến đường
struct Doan {
    char gatruoc[12];
    char gasau[12];
    int chieudai;   // km
    int thoigian;   // thời gian xe lửa chạy trên đoạn, tính theo phút
};

// Cấu trúc của một nút
struct Node {
    Doan info;
    Node* left, *right;
};

// Định nghĩa NODEPTR
typedef Node* NODEPTR;

// Tạo mới một node
NODEPTR New_node() {
    NODEPTR p = new Node;
    return p;
}

// Khởi động danh sách liên kết kép
void Initialize(NODEPTR& First) {
    First = NULL;
}

// Kiểm tra danh sách liên kết kép có rỗng không
int empty(NODEPTR First) {
    return (First == NULL) ? TRUE : FALSE;
}

// Thêm nút vào đầu danh sách liên kết
void Insert_first(NODEPTR& First, Doan x) {
    NODEPTR p = New_node();
    p->info = x;
    if (First == NULL) {  // trường hợp danh sách rỗng
        p->right = NULL;
    } else {
        p->right = First;
        First->left = p;
    }
    First = p;
    p->left = NULL;
}

// Thêm nút mới sau nút p
void Insert_right(NODEPTR p, Doan x) {
    if (p == NULL) {
        cout << "Nút p không hiện hữu, không thêm nút được\n";
    } else {
        NODEPTR q = New_node();
        q->info = x;
        NODEPTR r = p->right;
        if (r != NULL) {
            r->left = q;
        }
        q->right = r;
        q->left = p;
        p->right = q;
    }
}

// Thêm nút mới trước nút p
void Insert_left(NODEPTR& First, NODEPTR p, Doan x) {
    if (p == NULL) {
        cout << "Nút p không hiện hữu, không thêm nút được\n";
    } else {
        if (p == First) {  // Thêm nút vào đầu danh sách
            Insert_first(First, x);
        } else {
            NODEPTR q = New_node();
            q->info = x;
            NODEPTR r = p->left;
            r->right = q;
            q->left = r;
            q->right = p;
            p->left = q;
        }
    }
}

// Xóa nút ở đầu danh sách liên kết
void Delete_first(NODEPTR& First) {
    if (empty(First)) {
        cout << "Danh sách rỗng, không xóa nút được\n";
    } else {
        NODEPTR p = First;
        if (First->right == NULL) {
            First = NULL;
        } else {
            First = p->right;
            First->left = NULL;
        }
        delete p;
    }
}

// Xóa nút có con trỏ là p
void Delete_node(NODEPTR& First, NODEPTR p) {
    if (p == NULL) {
        cout << "Nút p không hiện hữu, không xóa nút được\n";
    } else {
        if (empty(First)) {
            cout << "Danh sách rỗng, không xóa nút được\n";
        } else {
            if (p == First) {
                Delete_first(First);
            } else {
                NODEPTR q = p->left;
                NODEPTR r = p->right;
                if (r != NULL) {
                    r->left = q;
                }
                q->right = r;
                delete p;
            }
        }
    }
}

// Duyệt danh sách từ trái sang phải
void Right_traverse(NODEPTR First) {
    if (empty(First)) {
        cout << "\n(không có đoạn nào)\n";
    } else {
        NODEPTR p = First;
        int stt = 1;
        while (p != NULL) {
            cout << "\n" << stt++ << "\t" << p->info.gatruoc << "\t" << p->info.gasau << "\t" 
                 << p->info.chieudai << " km\t" << p->info.thoigian << " phút";
            p = p->right;
        }
    }
}

// Duyệt danh sách từ phải sang trái
void Left_traverse(NODEPTR First) {
    if (empty(First)) {
        cout << "\n(không có đoạn nào)\n";
    } else {
        NODEPTR p;
        for (p = First; p->right != NULL; p = p->right);  // tìm nút cuối
        int stt = 1;
        while (p != NULL) {
            cout << "\n" << stt++ << "\t" << p->info.gasau << "\t" << p->info.gatruoc << "\t" 
                 << p->info.chieudai << " km\t" << p->info.thoigian << " phút";
            p = p->left;
        }
    }
}

// Tìm ga trước của một đoạn
NODEPTR Search_info1(NODEPTR First, char x[]) {
    NODEPTR p = First;
    while (p != NULL && strcmp(p->info.gatruoc, x) != 0) {
        p = p->right;
    }
    return p;
}

// Tìm ga sau của một đoạn
NODEPTR Search_info2(NODEPTR First, char x[]) {
    NODEPTR p = First;
    while (p != NULL && strcmp(p->info.gasau, x) != 0) {
        p = p->right;
    }
    return p;
}

// Xóa toàn bộ danh sách liên kết kép
void clearlist(NODEPTR& First) {
    while (First != NULL) {
        Delete_first(First);
    }
}

// Xác định vị trí của một nút trong danh sách liên kết
int position(NODEPTR First, NODEPTR p) {
    int vitri = 0;
    NODEPTR q = First;
    while (q != NULL && q != p) {
        q = q->right;
        vitri++;
    }
    return (q == NULL) ? -1 : vitri;
}

// Xử lý báo lộ trình
void baolotrinh(NODEPTR& First, char noidi[], char noiden[], char c) {
    NODEPTR p1, p2;
    int kc = 0, tg = 0;
    
    if (c == 'X') {
        p1 = Search_info1(First, noidi);
        p2 = Search_info2(First, noiden);
        if (p1 == NULL || p2 == NULL || position(First, p1) > position(First, p2)) {
            cout << "Lộ trình không hợp lệ\n";
            return;
        }
        
        while (p1 != p2) {
            kc += p1->info.chieudai;
            tg += p1->info.thoigian;
            cout << "\n" << p1->info.gatruoc << " -> " << p1->info.gasau << ": " 
                 << p1->info.chieudai << " km  " << p1->info.thoigian << " phút";
            p1 = p1->right;
        }
        kc += p1->info.chieudai;
        tg += p1->info.thoigian;
        cout << "\nTổng chiều dài: " << kc << " km. Tổng thời gian: " << tg << " phút\n";
    }
    
    if (c == 'N') {
        p1 = Search_info2(First, noidi);
        p2 = Search_info1(First, noiden);
        if (p1 == NULL || p2 == NULL || position(First, p1) < position(First, p2)) {
            cout << "Lộ trình không hợp lệ\n";
            return;
        }

        while (p1 != p2) {
            kc += p1->info.chieudai;
            tg += p1->info.thoigian;
            cout << "\n" << p1->info.gasau << " -> " << p1->info.gatruoc << ": " 
                 << p1->info.chieudai << " km  " << p1->info.thoigian << " phút";
            p1 = p1->left;
        }
        kc += p1->info.chieudai;
        tg += p1->info.thoigian;
        cout << "\nTổng chiều dài: " << kc << " km. Tổng thời gian: " << tg << " phút\n";
    }
}

// Xác định con trỏ chỉ nút thứ i
NODEPTR nodepointer(NODEPTR First, int i) {
    NODEPTR p = First;
    int vitri = 1;
    while (p != NULL && vitri < i) {
        p = p->right;
        vitri++;
    }
    return p;
}

// Menu chương trình
char menu() {
    char chucnang;
    do {
        cout << "\nLựa chọn một chức năng (1-12) hoặc 'T' để thoát: ";
        cout << "\n1: Khởi động danh sách";
        cout << "\n2: Xóa danh sách";
        cout << "\n3: Thêm một đoạn vào đầu danh sách";
        cout << "\n4: Thêm một đoạn vào sau một đoạn";
        cout << "\n5: Thêm một đoạn vào trước một đoạn";
        cout << "\n6: Xóa đoạn đầu";
        cout << "\n7: Xóa đoạn bất kỳ";
        cout << "\n8: In danh sách từ trái sang phải";
        cout << "\n9: In danh sách từ phải sang trái";
        cout << "\n10: Báo lộ trình đi xuôi";
        cout << "\n11: Báo lộ trình đi ngược";
        cout << "\n12: Tìm một đoạn";
        cout << "\nT: Thoát\n";
        cin >> chucnang;
    } while (!((chucnang >= '1' && chucnang <= '9') || chucnang == 'T'));
    return chucnang;
}

// Hàm chính
int main() {
	SetConsoleOutputCP(CP_UTF8);
    NODEPTR First;
    Doan d;
    char noidi[12], noiden[12], c;
    Initialize(First);
    char chucnang;
    int i;
    NODEPTR p;
    
    do {
        chucnang = menu();
        switch (chucnang) {
            case '1':  // Khởi động danh sách
                Initialize(First);
                cout << "Danh sách đã được khởi động.\n";
                break;

            case '2':  // Xóa danh sách
                clearlist(First);
                cout << "Danh sách đã được xóa.\n";
                break;

            case '3':  // Thêm đoạn vào đầu danh sách
                cout << "Nhập ga trước: "; cin >> d.gatruoc;
                cout << "Nhập ga sau: "; cin >> d.gasau;
                cout << "Nhập chiều dài (km): "; cin >> d.chieudai;
                cout << "Nhập thời gian (phút): "; cin >> d.thoigian;
                Insert_first(First, d);
                cout << "Đoạn đã được thêm vào danh sách.\n";
                break;

            case '4':  // Thêm đoạn vào sau một đoạn
                cout << "Nhập ga trước của đoạn bạn muốn thêm sau: "; cin >> noidi;
                p = Search_info1(First, noidi);
                if (p == NULL) {
                    cout << "Không tìm thấy đoạn này.\n";
                } else {
                    cout << "Nhập ga trước: "; cin >> d.gatruoc;
                    cout << "Nhập ga sau: "; cin >> d.gasau;
                    cout << "Nhập chiều dài (km): "; cin >> d.chieudai;
                    cout << "Nhập thời gian (phút): "; cin >> d.thoigian;
                    Insert_right(p, d);
                    cout << "Đoạn đã được thêm vào sau đoạn đã chọn.\n";
                }
                break;

            case '5':  // Thêm đoạn vào trước một đoạn
                cout << "Nhập ga sau của đoạn bạn muốn thêm trước: "; cin >> noiden;
                p = Search_info2(First, noiden);
                if (p == NULL) {
                    cout << "Không tìm thấy đoạn này.\n";
                } else {
                    cout << "Nhập ga trước: "; cin >> d.gatruoc;
                    cout << "Nhập ga sau: "; cin >> d.gasau;
                    cout << "Nhập chiều dài (km): "; cin >> d.chieudai;
                    cout << "Nhập thời gian (phút): "; cin >> d.thoigian;
                    Insert_left(First, p, d);
                    cout << "Đoạn đã được thêm vào trước đoạn đã chọn.\n";
                }
                break;

            case '6':  // Xóa đoạn đầu
                Delete_first(First);
                cout << "Đoạn đầu đã được xóa.\n";
                break;

            case '7':  // Xóa đoạn bất kỳ
                cout << "Nhập ga trước của đoạn bạn muốn xóa: "; cin >> noidi;
                p = Search_info1(First, noidi);
                if (p == NULL) {
                    cout << "Không tìm thấy đoạn này.\n";
                } else {
                    Delete_node(First, p);
                    cout << "Đoạn đã được xóa.\n";
                }
                break;

            case '8':  // In danh sách từ trái sang phải
                Right_traverse(First);
                break;

            case '9':  // In danh sách từ phải sang trái
                Left_traverse(First);
                break;

            case '10':  // Báo lộ trình đi xuôi
                cout << "Nhập ga đi: "; cin >> noidi;
                cout << "Nhập ga đến: "; cin >> noiden;
                baolotrinh(First, noidi, noiden, 'X');
                break;

            case '11':  // Báo lộ trình đi ngược
                cout << "Nhập ga đi: "; cin >> noidi;
                cout << "Nhập ga đến: "; cin >> noiden;
                baolotrinh(First, noidi, noiden, 'N');
                break;

            case '12':  // Tìm một đoạn
                cout << "Nhập ga trước của đoạn bạn muốn tìm: "; cin >> noidi;
                p = Search_info1(First, noidi);
                if (p == NULL) {
                    cout << "Không tìm thấy đoạn này.\n";
                } else {
                    cout << "Đã tìm thấy đoạn: " << p->info.gatruoc << " -> " << p->info.gasau 
                         << ": " << p->info.chieudai << " km, " << p->info.thoigian << " phút.\n";
                }
                break;

            case 'T':  // Thoát chương trình
                cout << "Chương trình kết thúc.\n";
                break;

            default:
                cout << "Chức năng không hợp lệ. Vui lòng chọn lại.\n";
        }
    } while (chucnang != 'T');
    
    return 0;
}

