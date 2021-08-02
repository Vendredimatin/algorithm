//
// Created by 刘汉乙 on 2021/7/29.
//
#include<vector>
#include<iostream>
using namespace std;

vector<int> dp887;

void helper(int eggs, int l, int r, int count){
    if (l > r || eggs == 0){
        return;
    }

    count++;
    int mid = l + (r - l)/2;
    // if eggs break;
    dp887[mid] = max(dp887[mid],count);
    helper(eggs-1, l, mid - 1, count);
    // if eggs do not break;
    helper(eggs, mid + 1, r, count);
}

int superEggDrop(int k, int n) {
    dp887.resize(n+1);
    helper(k, 0, n, 0);
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, dp887[i]);
    }

    return ans;
}

int main887(){
    cout << superEggDrop(1,3);
    return 0;
}