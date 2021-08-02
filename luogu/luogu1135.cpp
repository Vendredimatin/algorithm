//
// Created by 刘汉乙 on 2021/6/12.
//

//
// Created by 刘汉乙 on 2021/6/12.
//

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/**
 * 之前没过有两个比较粗糙的原因：一个是没有及时break；一个是没有把访问过的节点设置为true，都是经典错误。
 * 这道题dfs和bfs都可以做，之所以选择bfs，是因为使用bfs不需要进行比较，使用bfs到达的节点即是最少的层数。这启示当要求最少的时候，可以直接使用bfs并且不需要比较
 * 本来很多图算法也是基于BFS
 * @return
 */

int main1135(){
    int N,A,B;
    cin >> N >> A >> B;
    vector<int> ks(N+1);
    vector<bool> isVisit(N+1);

    for (int i = 1; i <= N; ++i) {
        cin >> ks[i];
    }

    queue<pair<int,int>> q;
    q.push(make_pair(A,0));
    isVisit[A] = true;

    int ans = -1;
    while (!q.empty()){
        pair<int,int> ele = q.front(); q.pop();
        if (ele.first == B){
            ans = ele.second;
            break;
        }else{
            int upEnd = ele.first + ks[ele.first];
            int downEnd = ele.first - ks[ele.first];
            int count = ele.second + 1;

            if(upEnd <= N && !isVisit[upEnd]){
                isVisit[upEnd] = true;
                q.push(make_pair(upEnd, count));
            }
            if(downEnd >= 1 && !isVisit[downEnd]){
                isVisit[downEnd] = true;
                q.push(make_pair(downEnd, count));
            }
        }
    }

    cout << ans << endl;
    return 0;
}
