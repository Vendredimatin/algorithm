//
// Created by Admin on 2021/11/8.
//

#include<string>
#include<iostream>
using namespace std;

string addStrings(string num1, string num2) {
    //保证num1的size更大
    if (num2.size() > num1.size()){
        string temp = num1;
        num1 = num2;
        num2 = temp;
    }

    string ans = "";
    int carry = 0;
    int diff = num1.size() - num2.size();
    for (int i = num1.size()-1; i >= diff; --i) {
        int n1 = num1[i] - '0';
        int n2 = num2[i - diff] - '0';
        int sum = n1 + n2 + carry;
        carry = sum/10;
        ans = to_string(sum%10) + ans;
    }

    int start = num1.size() - num2.size() - 1;
    for (int i = start; i >= 0; --i) {
        int n1 = num1[i] - '0';
        int sum = n1 + carry;
        carry = sum/10;
        ans = to_string(sum%10) + ans;
    }

    if (carry != 0) ans = to_string(carry) + ans;

    return ans;
}

int main415(){
    string num1 = "1";
    string num2 = "9";
    cout << addStrings(num1,num2);
    return 0;
}
