//
// Created by 刘汉乙 on 2021/11/17.
//

//
// Created by 刘汉乙 on 2021/11/16.
//

#include "AllOne.h"
#include<string>
#include <iostream>

using namespace std;

int main432(){
    AllOne* obj = new AllOne();
    obj->inc("hello");
    obj->inc("hello");
    cout <<  obj->getMaxKey();
    cout << obj->getMinKey();
    obj->inc("leet");
    cout <<  obj->getMaxKey();
    cout << obj->getMinKey();
    return 0;
}