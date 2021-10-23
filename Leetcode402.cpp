//
// Created by 刘汉乙 on 2021/8/8.
//
#include<iostream>
#include<string>
#include<stack>
using namespace std;

string removeKdigits(string num, int k) {
    if (num.size() == 0) return "0";
    stack<char> s;
    string ans;
    s.push(num[0]);
    for (int i = 1; i < num.size(); ++i) {
        char ch = num[i];

        while(!s.empty() && s.top() > ch && k > 0){
            s.pop();
            k--;
        }

        if (ch != '0' || !s.empty() )
            s.push(ch);

    }

    while(!s.empty() && k > 0){
        s.pop(); k--;
    }

    if (s.empty())  return "0";

    while (!s.empty()){
        ans = s.top() + ans;
        s.pop();
    }

    return ans;
}

int main(){
    cout << removeKdigits("10200",1);
    return 0;
}