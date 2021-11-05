//
// Created by Admin on 2021/11/5.
//

//
// Created by Admin on 2021/11/5.
//
#include<string>
#include<unordered_map>
#include <iostream>

using namespace std;

int longestPalindrome(string s) {
    unordered_map<char,int> map;
    for(char ch:s){
        if (map.count(ch)){
            map[ch]++;
        }else map[ch] = 1;
    }

    unordered_map<char,int>::iterator it = map.begin();
    bool hasSingle = false;
    int ans = 0;
    while (it != map.end()){
        int count = it->second;
        if (it->second % 2 != 0) {
            if (count > 1) ans+= (count-1);
            hasSingle = true;
        }else{
            ans += it->second;
        }
        it++;
    }

    return (hasSingle)?ans+1:ans;
}

int main409(){
    string s = "ccc";

    cout << longestPalindrome(s);
    return 0;
}
