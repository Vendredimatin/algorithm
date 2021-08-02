//
// Created by 刘汉乙 on 2021/6/12.
//
#include<iostream>
#include<vector>
#include "limits.h"
using namespace std;

int ans2036 = INT_MAX;
void dfs2036(vector<int> s, vector<int> b, int st, int sum, int product){
    if (st >= s.size()) return;

    for (int i = st; i < s.size(); ++i) {
        int tmpSum = sum;
        int tmpProduct = product;

        tmpProduct *= s[i];
        tmpSum += b[i];
        ans2036 = min(ans2036, abs(tmpProduct - tmpSum));
        dfs2036(s,b,i+1,tmpSum,tmpProduct);
    }
}

int main2036(){
    int N;
    cin >> N;
    vector<int> s(N);
    vector<int> b(N);
    for (int i = 0; i < N; i++){
        cin >> s[i] >> b[i];
    }

    int sum = 0;
    int product = 1;
    dfs2036(s,b,0,sum,product);
    cout << ans2036;
    return 0;
}

/**
 * 这是另外一个比较好的思路，从状态的角度出发，是否该放调料而分为两个状态
 */

/*
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int M=15;//养成良好习惯
int a[M],b[M],n,ans=0x7f;
//ans初始化为最大值
void dfs(int i,int x,int y){
//i是表示目前的配料编号，x为酸度，y为甜度
    if(i>n){
        //注意，必须大于n才表示全部搜完
        if(x==1&&y==0)return;
        //判断清水的情况
        ans=min(abs(x-y),ans);
        //更新ans
        return;
    }
    //分两种情况搜索：1添加 2不添加
    dfs(i+1,x*a[i],y+b[i]);
    dfs(i+1,x,y);
    //这题无需回溯，不明白为何有些题解居然还用全局变量，非得回溯-_-||
}
int main2036_2(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
        //读入，用cin太慢了
    }
    dfs(1,1,0);
    printf("%d\n",ans);
    return 0;
}*/
