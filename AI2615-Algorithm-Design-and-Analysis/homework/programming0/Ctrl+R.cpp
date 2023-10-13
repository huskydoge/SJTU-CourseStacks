//
// Created by 黄奔皓 on 2023/2/14.
// https://acm.sjtu.edu.cn/OnlineJudge/problem/1786
#include <iostream>
#include <vector>
#include "string"
#include "map"
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    int cnt = 0;
    std::string tmp;
    std::cin >> n;

    std::vector<std::string> v1;
    std::vector<std::string> v2;

    std::map<std::string,std::string> storage;

    while(cnt < n){
        std::cin >> tmp;
        v1.push_back(tmp);
        ++ cnt;
    }
    cnt = 0;
    while(cnt < n){
        std::cin >> tmp;
        v2.push_back(tmp);
        ++ cnt;
    }

    for(int i = 0; i < n; ++ i){
        tmp = v1.at(i);
        if(storage.count(tmp)){
            if(v2.at(i)!=storage[tmp]){
                std::cout << "No";
                return 0;
            }
        } else {
            storage[tmp] = v2.at(i);
        }
    }
    std::cout << "Yes";
    return 0;
}