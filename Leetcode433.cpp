//
// Created by 刘汉乙 on 2021/11/17.
//

//
// Created by 刘汉乙 on 2021/11/17.
//
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
#include <iostream>

using namespace std;
/**
 * 逐步变化的过程，找变化的最小次数，很容易想到BFS
 * @param start
 * @param end
 * @param bank
 * @return
 */
int minMutation(string start, string end, vector<string>& bank) {
    if (start.size() != end.size()) return -1;

    unordered_set<string> visit;
    unordered_set<string> bankSet;
    queue<string> q;
    q.push(start);
    visit.insert(start);

    for (string str : bank) {
        bankSet.insert(str);
    }

    int ans = 0;
    while (!q.empty()){
        int n = q.size();
        while (n-- > 0) {
            string str = q.front();
            q.pop();

            for (int i = 0; i < str.size(); ++i) {
                char ch = str[i];
                for (int j = 0; j < 26; ++j) {
                    str[i] = 'A' + j;

                    if (bankSet.find(str) != bankSet.end() && visit.find(str) == visit.end()){
                        if (str == end){
                            return ans + 1;
                        }
                        q.push(str);
                        visit.insert(str);
                    }
                }
                str[i] = ch;
            }

        }

        ans++;
    }

    return -1;
}

int main(){
    string start = "AAAAACCC";
    string end = "AACCCCCC";
    vector<string> bank({"AAAACCCC","AAACCCCC","AACCCCCC"});
    cout << minMutation(start,end,bank);
    return 0;
}
