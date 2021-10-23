//
// Created by 刘汉乙 on 2021/8/6.
//
#include<string>
#include<iostream>
using namespace std;

int findNthDigit(int n) {
    string s = " ";
    int num = 1;
    char ans = ' ';
    while(s.size() <= n){
        s += to_string(num);
        num++;

        if (s.size() > n){
            ans = s[n];
            break;
        }
    }

    return ans -'0';
}

int main400(){
    cout << findNthDigit(3);
    return 0;
}
