#include "iostream"
using namespace std;

struct Node{
    long data;
    struct Node* next = nullptr;
};

//void printList(Node *head){
//    Node *p = head->next;
//    while(p!= nullptr){
//        cout << p->data << "->";
//        p = p->next;
//    }
//    cout << "NULL" << endl;
//}


int main(){

    int n = 0, m = 0;
    // 初始化链表
    cin >> n;
    Node *head = new Node();
    head->next = nullptr;
    if(n == 0){cout << 0; return 0;}

    Node *first = new Node();
    cin >> first->data;
    first->next = nullptr;
    Node *cur = first;
    for (int i = 0; i < n - 1; ++i){
        Node *next = new Node();//下一个结点
        cin >> next->data;
        next->next = nullptr;
        cur->next = next;
        cur = cur->next;
    }
    cur->next = nullptr;
    head->next = first;

    // 数据查找
    cin >> m;
    long ans = 0;
    long number = 0;

    for (int i = 0; i < m ; ++i){
        cin >> number;
        Node *p = head->next; Node *q = head;
        while(p!= nullptr) {
            if (p->data == number) {
                if(q != head){
                    q->next = p->next;
                    p->next = head->next;
                    head->next = p;
                }
                ++ ans;
                break;
            } else {
                p = p->next;
                q = q->next;
                ++ ans;
            }
        }
//        printList(head);
    }

    cout << ans;

}

