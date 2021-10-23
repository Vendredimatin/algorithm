//
// Created by 刘汉乙 on 2021/8/5.
//
#include <vector>
#include <algorithm>
#include<iostream>
#include<queue>
#include<unordered_set>
#include<time.h>
#include<map>

using namespace std;

vector<int> dp397397;

//TLE,老火老火
//慢的原因是，有很多地方没必要+1/-1，直接*2是最快的选择，所以最合适的复杂度是O(logn)~O(n),比O（n）快
int integerReplacement2(int n) {
    clock_t start,finish;
    double totaltime;

    start = clock();

    dp397397.resize(n*2+1,INT_MAX);
    dp397397[1] = 0;
    for (int i = 1; i <= n; ++i) {
        if(dp397397[i+1] != INT_MAX)
            dp397397[i] = min(dp397397[i], dp397397[i+1]+1);
        dp397397[i+1] = min(dp397397[i+1], dp397397[i]+1);
        dp397397[2*i] = min(dp397397[2*i], dp397397[i]+1);
    }

    finish = clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<endl;

    return dp397397[n];
}

struct Point{
    int operations;
    int num;
};

//求最短，试试BFS
//虽然符合之前的总结，但是BFS更慢，100000000需要22秒
unordered_set<int> set;
int integerReplacement3(int n) {
    clock_t start,finish;
    double totaltime;

    queue<pair<int, int>> q;
    q.push({0,1});

    int ans = INT_MAX;
    while(!q.empty()){
        pair<int, int> p = q.front(); q.pop();
        if (p.second == n){
            ans = p.first;
            break;
        }

        int num = p.second;
        int operations = p.first;
        if (set.find(num * 2) == set.end()) {
            q.push({operations + 1, num * 2});
            set.insert(num * 2);
        }
        if (set.find(num + 1) == set.end()) {
            q.push( {operations + 1, num + 1});
            set.insert(num + 1);
        }
        if (set.find(num - 1) == set.end() && num-1 >= 1) {
            q.push( {operations + 1, num - 1});
            set.insert(num - 1);
        }
    }

    finish = clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<endl;

    return ans;
}

//2/3都是从1开始反向递推得到n，这在没限制num is even/old时是正确的，当限制num is even就除于2时已经相当于在已有三种操作的基础上，对某一种操作进行特殊化。
//所以从n开始向1正向递推的bfs
int integerReplacement(int n) {
    //clock_t start,finish;
    //double totaltime;

    queue<pair<int, int>> q;
    q.push({0,n});

    int ans = INT_MAX;
    while(!q.empty()){
        pair<int, int> p = q.front(); q.pop();
        if (p.second == 1){
            ans = p.first;
            break;
        }

        int num = p.second;
        int operations = p.first;

        if (num %2 == 0 && set.find(num / 2) == set.end()) {
            q.push({operations + 1, num / 2});
            set.insert(num * 2);
            continue;
        }
        if (set.find(num + 1) == set.end()) {
            q.push( {operations + 1, num + 1});
            set.insert(num + 1);
        }
        if (set.find(num - 1) == set.end() && num-1 >= 1) {
            q.push( {operations + 1, num - 1});
            set.insert(num - 1);
        }
    }

    //finish = clock();
    //totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    //cout<<"\n此程序的运行时间为"<<totaltime<<"秒！"<<endl;

    return ans;
}

int integerReplacement5(int n) {
    static map<int,int>dp397397;
    if(n<=1)
        return 0;
    if(dp397397[n]!=0)
        return dp397397[n];

    if(n%2==0){

        dp397397[n] = 1 + integerReplacement5(n/2);

    }else{//This is the crucial step: done so to prevent overflowing during code submission
        dp397397[n] = 2 + min(integerReplacement5(n/2 + 1),integerReplacement5(n/2));
    }

    return dp397397[n];
}

int main397(){
    cout << integerReplacement(100000000);
    return 0;
}