//
// Created by 刘汉乙 on 2021/7/24.
//

#include<iostream>
#include<vector>
#include <limits.h>
#include <queue>
using namespace std;

struct Point{
    int x;
    int y;
    int time;
};

//一开始用dfs没过，换成bfs就过了，这确实搞笑，其实这就是普通的搜索题加上了一个特殊的传送门而，求最短路径/时间，这种题我还是想错了，应该使用bfs而不是dfs的，使用bfs能够最快到达终点
//记住，求最短路径使用bfs
vector<vector<char>> board;
vector<vector<bool>> visit1825;
vector<vector<pair<int,int>>> devices;
vector<pair<int,int>> directions({{-1,0},{1,0},{0, -1},{0,1}});
int ans1825 = INT_MAX;

int main1825(){
    int sx, sy,m,n = 0;
    cin >> m >> n;

    board.resize(m, vector<char>(n));
    devices.resize(26, vector<pair<int,int>>());
    visit1825.resize(m, vector<bool>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
            if (board[i][j] == '@'){
                sx = i, sy = j;
            }else if (isalpha(board[i][j])){
                devices[board[i][j] - 'A'].push_back(make_pair(i,j));
            }
        }
    }

    queue<Point> q;
    visit1825[sx][sy] = true;
    q.push((Point){sx, sy, 0});
    while (!q.empty()){
        Point cur = q.front(); q.pop();

        if (board[cur.x][cur.y] == '='){
            ans1825 = cur.time;
            break;
        }else if (isalpha(board[cur.x][cur.y])){
            int newX,newY = 0;
            vector<pair<int,int>> device = devices[board[cur.x][cur.y] - 'A'];
            if (device.size() == 2) {
                if (device[0].first == cur.x && device[0].second == cur.y) {
                    newX = device[1].first, newY = device[1].second;
                } else {
                    newX = device[0].first, newY = device[0].second;
                }
                visit1825[cur.x][cur.y] = false;
                cur.x = newX;
                cur.y = newY;
                visit1825[cur.x][cur.y] = false;
            }
        }

        for(pair<int,int> direc:directions){
            int x = direc.first + cur.x, y = direc.second + cur.y;
            if (x < 0 || y < 0 || x >=m || y >= n)  continue;
            if (board[x][y] == '#') continue;
            if (visit1825[x][y])    continue;

            visit1825[x][y] = true;
            q.push((Point){x,y,cur.time+1});
        }
    }

    cout << ans1825;
    return 0;
}