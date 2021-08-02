//
// Created by 刘汉乙 on 2021/6/12.
//

#include<vector>
#include<queue>
#include<unordered_set>
#include <iostream>

using namespace std;

bool isPrime(int num){
    int end = sqrt(num);
    for(int i = 2; i <= end; i++){
        if(num%i == 0)  return false;
    }

    return true;
}

int ans1026 = 0;
void dfs1036(vector<int> v, int start, vector<int> tmp, int k){
    if(tmp.size() == k){
        int sum = 0;
        for (int i = 0; i < k; i++) sum += tmp[i];
        if(isPrime(sum))   ans1026++;
        return;
    }
    if(k >= v.size()) return;


    for(int i = start; i < v.size(); i++){
        tmp.push_back(v[i]);
        dfs1036(v, i+1, tmp, k);
        tmp.pop_back();
    }
}

int main1036(){
    int N,K;
    cin >> N >> K;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    vector<int> tmp;
    dfs1036(v, 0, tmp,K);
    cout << ans1026;
    return 0;
}

