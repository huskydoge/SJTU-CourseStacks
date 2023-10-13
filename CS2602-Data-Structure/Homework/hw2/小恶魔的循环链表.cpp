#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

    struct NODE {
        int data;
        NODE* next;
    };

    NODE *head = nullptr;
    int len = 0;

    void init() {
        head = new NODE;
        head->next = head;
    }
    NODE* move(int i) {

        // TODO
    }
    void insert(int i, int x) {
        int j = 0;
        NODE * tmp;
        NODE *d = new NODE;
        d->data = x;
        tmp = head;

        while(j < i){
            tmp = tmp->next;
            ++ j;
        }
        d->next = tmp->next;
        tmp->next = d;
        ++ len;

    }
    void remove(int i) {
        int j = 0;
        NODE* tmp = head;
        NODE* d;

        while(j < i){
            tmp = tmp->next;
            ++ j;
        }
        d = tmp->next;
        tmp->next = d->next;
        delete d;
        -- len;
    }
    void remove_insert(int i) {
        int j = 0;
        NODE* tmp = head;
        NODE* d;

        while(j < i){
            tmp = tmp->next;
            ++ j;
        }

        d = tmp->next;
        tmp->next = d->next;

        while(j < len - 1){
            tmp = tmp->next;
            ++ j;
        }

        d->next = tmp->next;
        tmp->next = d;
    }
    void get_length() {
        cout << len << endl;
    }
    void query(int i) {
        if(i > len - 1 || i < 0){
            cout << -1 << endl;
        } else {
            int j = 0;
            NODE* tmp = head;
            while(j < i){
                tmp = tmp->next;
                ++ j;
            }
            cout << tmp->next->data << endl;
        }
    }
    void get_max() {
        int k = -1;
        NODE* tmp = head;
        if(len == 0){cout << k << endl;
            return;}
        else {
            tmp = tmp->next;
            while (tmp!=head) {
                if (tmp->data > k) {
                    k = tmp->data;
                }
                tmp = tmp->next;
            }

            cout << k << endl;
        }

    }
    void clear() {
        if(len != 0){
            NODE* tmp = head->next;
            NODE* cur;
            while(tmp != head){
                cur = tmp;
                tmp = tmp->next;
                delete cur;
            }
        }

        delete head;
    }
}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch(op) {
            case 0:
                LIST::get_length();
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                LIST::query(p);
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                cin >> p;
                LIST::remove_insert(p);
                break;
            case 5:
                LIST::get_max();
                break;
        }
    }
    LIST::clear();
    return 0;
}