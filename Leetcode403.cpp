//
// Created by 刘汉乙 on 2021/10/30.
//
#include<iostream>
#include<unordered_map>
#include<vector>
#include <unordered_set>
#include<set>
using namespace std;

vector<set<int>> dp;


bool canCross(vector<int>& stones) {
    if (stones.size() >= 2 && stones[1] != 1) return false;
    int n = stones.size();
    dp.resize(n);
    dp[1].insert(1);
    for (int curPos = 2; curPos < n; ++curPos) {
        for (int j = curPos-1; j >= 1; j--) {
            set<int>::iterator it = dp[j].begin();
            while (it != dp[j].end()){
                int jump = *it;
                if (jump + stones[j] == stones[curPos]){
                    dp[curPos].insert(jump);
                }else if(jump + stones[j] + 1 == stones[curPos]){
                    dp[curPos].insert(jump + 1);
                }else if(jump + stones[j] - 1 == stones[curPos]){
                    dp[curPos].insert(jump - 1);
                }

                it++;
            }
        }
    }

    bool ans = (dp[n-1].size() == 0)?false:true;
    return ans;
}


int main403(){
    vector<int> stones({0,1,2,3,4,8,9,11});
    cout << canCross(stones);
    return 0;
}
/**
  两相对比，虽然思路是一样的思路，但写法却没有最新的高效，最新的是直接根据两个点之间的距离k来看前一个点是否有k，之前的做法还要来遍历每一个dp。
  其实用k来就行了，不需要分别k-1、k、k+1都试试
bool canCross(vector<int>& stones) {
  if (stones.size() >= 2 && stones[1] != 1) return false;
  int n = stones.size();
  dp.resize(n);
  dp[1].insert(1);
  for (int curPos = 2; curPos < n; ++curPos) {
      for (int j = curPos-1; j >= 1; j--) {
          set<int>::iterator it = dp[j].begin();
          while (it != dp[j].end()){
              int jump = *it;
              if (jump + stones[j] == stones[curPos]){
                  dp[curPos].insert(jump);
              }else if(jump + stones[j] + 1 == stones[curPos]){
                  dp[curPos].insert(jump + 1);
              }else if(jump + stones[j] - 1 == stones[curPos]){
                  dp[curPos].insert(jump - 1);
              }

              it++;
          }
      }
  }

  bool ans = (dp[n-1].size() == 0)?false:true;
  return ans;
}

  */