//
// Created by 刘汉乙 on 2021/11/4.
//
#include<string>
using namespace std;

string toHex(int num) {
    //数制转换成，统一转换成unsined来处理
    unsigned int ourNum = num;
    // Implicitly cast negative numbers.
    // -1 turns to the maximum number representable
    // as an unsigned int.

    string str; // Our result
    char ourArray[17] = "0123456789abcdef"; // We will pick from this set of characters

    // While our number exists, convert it into base 16.
    // We are going from left to right, so we need to reverse our result
    // when we return it.
    do {
        str += ourArray[ourNum % 16];
        ourNum /= 16;
    } while (ourNum);

    return {str.rbegin(), str.rend()};
}