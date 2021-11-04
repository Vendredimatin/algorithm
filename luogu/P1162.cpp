//
// Created by 刘汉乙 on 2021/7/24.
//

#include<iostream>
#include<vector>
using namespace std;

vector<vector<bool>> visit1162;
vector<vector<int>> board1162;
vector<pair<int,int>> directions1162({{-1,0},{1,0},{0, -1},{0,1}});
/**
 * 反向思考，一开始想着找1内的0，如果从某个0开始搜索，一直搜索到1，那么这些0就都是2，但这样比较麻烦
 * 所以反向思考，从边界出发，之所以0会变2，是因为这些0没有与边界接触，那么就从边界0开始搜索，涉及到的0都是0，没有涉及到的0就是2
 * @param i
 * @param j
 */
void helper1162(int i, int j){

    visit1162[i][j] = true;
    if (board1162[i][j] == 1 || board1162[i][j] == -1) return;

    board1162[i][j] = -1;

    for(pair<int,int> direc:directions1162){
        int x = i + direc.first, y = j + direc.second;

        if(x < 0 || y < 0 || x >= board1162.size() || y >= board1162.size()) continue;
        if(visit1162[x][y]) continue;

        helper1162(x,y);
    }
}

int main1162(){
    int n;
    cin >> n;

    board1162.resize(n, vector<int>(n));
    visit1162.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board1162[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (board1162[0][i] == 0 && !visit1162[0][i])   helper1162(0,i);
        if (board1162[i][0] == 0 && !visit1162[i][0])   helper1162(i,0);
        if (board1162[n-1][i] == 0 && !visit1162[n-1][i])   helper1162(n-1,i);
        if (board1162[i][n-1] == 0 && !visit1162[i][n-1])   helper1162(i,n-1);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board1162[i][j] == -1) board1162[i][j] = 0;
            else if(board1162[i][j] == 0) board1162[i][j] = 2;
            cout << board1162[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}