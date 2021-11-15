//
// Created by Admin on 2021/11/10.
//
#include<vector>
#include <iostream>

using namespace std;
vector<vector<bool>> visit;
int m419,n419;

void helper(vector<vector<char>> board, int x, int y){
    if (x < 0 || y < 0 || x >= m419 || y >= n419 || visit[x][y]) return;
    if (board[x][y] == '.') return;

    visit[x][y] = true;
    helper(board, x-1, y);
    helper(board, x+1, y);
    helper(board, x, y-1);
    helper(board, x, y+1);
}

int countBattleships(vector<vector<char>>& board) {
     m419 = board.size();
     n419 = board[0].size();
    visit.resize(m419, vector<bool>(n419));

    int ans = 0;
    for (int i = 0; i < m419; ++i) {
        for (int j = 0; j < n419; ++j) {
            if (visit[i][j]) continue;
            if (board[i][j] == '.') continue;
            ans++;
            helper(board, i , j);
        }
    }
    return ans;
}

int main419(){
    vector<vector<char>> board;
    board.push_back({'X','.','.','X'});
    board.push_back({'.','.','.','X'});
    board.push_back({'.','.','.','X'});

    cout << countBattleships(board);
    return 0;
}