//
// Created by 刘汉乙 on 2021/8/2.
//
#include<vector>
using namespace std;

vector<int> ans;

/**
    一看到要O（n）解决，那么说明只能遍历一次，肯定首先要*10进行遍历，然后再+1进行遍历
    唯一值得注意的是，1～9和10～19是不一样的，一个是隔了9个数，一个是隔了10个数，为了保证遍历的统一，将前者放进调用函数，后者放进递归函数
    */
void helper(int cur, int n){
    if (cur > n)    return;

    for (int i = cur; i <= cur + 9 ; ++i) {
        if (i > n)  break;
        ans.push_back(i);
        helper(i * 10, n);
    }
}

vector<int> lexicalOrder(int n) {
    for (int i = 1; i <= 9; ++i) {
        if(i > n)   break;
        ans.push_back(i);
        helper(i*10, n);
    }
    return ans;
}

int main386(){
    lexicalOrder(103);
    return 0;
}