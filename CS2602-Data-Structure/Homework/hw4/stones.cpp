#include <iostream>
using namespace std;
const int N = 10010;
int huffman[N];
int num = 0;
// 维护一个小根堆
void insert(int x){
    huffman[++num] = x;
    int now = num, nxt = num >> 1;
    while(nxt){
        if(huffman[now] >= huffman[nxt]) break;
        swap(huffman[now], huffman[nxt]);
        now = nxt;
        nxt >>= 1;
    }
}

int top(){
    return huffman[1];
}

void erase(){
    // num为总数
    huffman[1] = huffman[num--];
    int now = 1, nxt = 2;
    while(nxt <= num){
        if(nxt < num && huffman[nxt] > huffman[nxt+1]) ++nxt; // 右孩子更小
        if(huffman[now] <= huffman[nxt]) break;
        swap(huffman[now], huffman[nxt]);
        now = nxt;
        nxt <<= 1;
    }
}

int main(){
    int n;
    cin >> n;
    int tmp;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        insert(tmp);
    }

    long ans = 0;
    while(-- n){
        int a = top(); erase();
        int b = top(); erase();
        ans += a + b;
        insert(a + b);
    }

    cout << ans;
}