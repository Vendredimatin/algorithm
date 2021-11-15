//
// Created by Admin on 2021/11/9.
//
#include<vector>

using namespace std;

vector<vector<int>> direction;
int m,n;

void helper(vector<vector<int>> heights,vector<vector<bool>>& visit, vector<vector<bool>>& canFlow,int i, int j){
    int height = heights[i][j];
    visit[i][j] = true;
    canFlow[i][j] = true;
    for (int k = 0; k < direction.size(); ++k) {
        int newPosX = i + direction[k][0];
        int newPosY = j + direction[k][1];
        if(newPosX < 0  || newPosY < 0 || newPosX >= m || newPosY >= n || visit[newPosX][newPosY]) continue;

        if (heights[newPosX][newPosY] >= height){
            helper(heights, visit, canFlow, newPosX, newPosY);
        }
    }

}


vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    direction.push_back({0,1});
    direction.push_back({1,0});
    direction.push_back({0,-1});
    direction.push_back({-1,0});

    vector<vector<bool>> pacific;
    vector<vector<bool>> altantic;
    vector<vector<bool>> pVisit(heights.size(), vector<bool>(heights[0].size()));
    vector<vector<bool>> aVisit(heights.size(), vector<bool>(heights[0].size()));

    pacific.resize(heights.size(), vector<bool>(heights[0].size()));
    altantic.resize(heights.size(), vector<bool>(heights[0].size()));


    m = heights.size();
    n = heights[0].size();

    for (int i = 0; i < m; ++i) {
        pacific[i][0] = true;
        altantic[i][n-1] = true;
        helper(heights, pVisit, pacific, i,0);
        helper(heights, aVisit, altantic, i,n-1);
    }

    for (int i = 0; i < n; ++i) {
        pacific[0][i] = true;
        altantic[m-1][i] = true;
        helper(heights, pVisit, pacific, 0,i);
        helper(heights, aVisit, altantic, m-1,i);
    }

    vector<vector<int>> ans;
    for (int i = 0; i < heights.size(); ++i) {
        for (int j = 0; j < heights[i].size(); ++j) {
            if (pacific[i][j] && altantic[i][j])    ans.push_back({i,j});
        }
    }

    return ans;
}

//https://leetcode.com/problems/pacific-atlantic-water-flow/discuss/90747/Very-Concise-C%2B%2B-solution-using-DFS-and-bit-mask
// 用mask来代替两个方向的访问，显得更加明智和优雅
// 之前还犹豫，两个方向的如何在同一个方法中区分，这个可以借鉴学习，不同方向的可以用不同mask来表示
/**
 * 从每一个点遍历两次会存在重复情况，从无找有比较麻烦，不如从有到无中找，更高效一些
 * @param heights
 * @return
 */
vector<vector<int>> pacificAtlantic1(vector<vector<int>>& heights) {
    direction.push_back({0,1});
    direction.push_back({1,0});
    direction.push_back({0,-1});
    direction.push_back({-1,0});

    vector<vector<bool>> pacific;
    vector<vector<bool>> altantic;
    vector<vector<bool>> pVisit(heights.size(), vector<bool>(heights[0].size()));
    vector<vector<bool>> aVisit(heights.size(), vector<bool>(heights[0].size()));

    pacific.resize(heights.size(), vector<bool>(heights[0].size()));
    altantic.resize(heights.size(), vector<bool>(heights[0].size()));


    m = heights.size();
    n = heights[0].size();

    for (int i = 0; i < m; ++i) {
        pacific[i][0] = true;
        altantic[i][n-1] = true;
    }

    for (int i = 0; i < n; ++i) {
        pacific[0][i] = true;
        altantic[m-1][i] = true;
    }

    vector<vector<int>> ans;
    for (int i = 0; i < heights.size(); ++i) {
        for (int j = 0; j < heights[i].size(); ++j) {

            helper(heights, pVisit, pacific, i,j);

            helper(heights, aVisit, altantic, i,j);
            if (pacific[i][j] && altantic[i][j])    ans.push_back({i,j});
        }
    }

    return ans;
}

int main417(){
    vector<vector<int>> heights;
    heights.push_back({1,2,2,3,5});
    heights.push_back({3,2,3,4,4});
    heights.push_back({2,4,5,3,1});
    heights.push_back({6,7,1,4,5});
    heights.push_back({5,1,1,2,4});
    /*heights.push_back({2,1});
    heights.push_back({1,2});*/
    pacificAtlantic(heights);
    return 0;
}