//
// Created by 刘汉乙 on 2021/6/12.
//
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Location{
    int x;
    int y;
    int time;
}location;

/**
 * 1. 这种时间序列的问题，如果每一步单独考虑流星会不会坠落，那么问题会变得比较复杂，如果提前把流星这个变量固定了，就会变成正常的bfs，并且还存在一点是，如果每一步单独考虑时间，可能会有的点在后面的时间才会被流星砸，问题变得更加复杂
 * 2. 时间序列问题，问最少时间，使用bfs能够得到最少的时间。
 * 3. 因为它有时间坠落问题，所以直接把时间刻在位置数组上。
 * 4. 最后一个例子没过，猜想逻辑应该是没有问题，问题应该是出在了一些常量设置上，因为其实并没有说明农场的大小，就被限制成了300，万一刚好有流星砸在了300上，所以地图搜索没有固定大小，一般要开大一点
 */

pair<int,int> op[] = {make_pair(-1,0), make_pair(1,0),make_pair(0,1),make_pair(0,-1)};
int main2895(){
    int M;
    cin >> M;
    vector<vector<int>> farm(400,vector<int>(400, 1001));
    vector<vector<bool>> visit(400,vector<bool>(400, false));

    for (int i = 0; i < M;i++){
        int x,y,t;
        cin >> x >> y >> t;
        if(t < farm[x][y])
            farm[x][y] = t;
        for (int j = 0; j < 4; ++j) {
            int newX = x + op[j].first;
            int newY = y + op[j].second;
            if(newX >= 0 && newX <= 400 && newY >= 0 && newY <= 400){
                if(t < farm[newX][newY])    farm[newX][newY] = t;
            }
        }
    }

    queue<Location> q;
    Location st = {0,0,0};
    q.push(st);

    int ans = -1;
    while (!q.empty()){
        Location cur = q.front(); q.pop();
        if (farm[cur.x][cur.y] == 1001){
            ans = cur.time;
            break;
        }

        for(int j = 0; j < 4; j++){
            int newX = cur.x + op[j].first;
            int newY = cur.y + op[j].second;
            int newTime = cur.time + 1;
            if(newX >= 0 && newX <= 400 && newY >= 0 && newY <= 400 && !visit[newX][newY] && newTime < farm[newX][newY]){
                Location newL = {newX,newY,newTime};
                visit[newX][newY] = true;
                q.push(newL);
            }
        }
    }

    cout << ans;
    return 0;
}