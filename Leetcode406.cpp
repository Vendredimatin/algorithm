//
// Created by Admin on 2021/11/4.
//

//
// Created by Admin on 2021/11/4.
//
#include<vector>
#include<algorithm>
using namespace std;

//我就奇了怪了，明明一开始就想到插入排序，为什么就偏偏不直接淳朴地去插入呢？
bool camp1(vector<int> v1, vector<int> v2){
    if(v1[0] == v2[0]){
        return v1[1] <= v2[1];
    }else
        return v1[0] <= v2[0];
}

bool camp(vector<int> v1, vector<int> v2){
    if(v1[0] == v2[0]){
        return v1[1] < v2[1];
    }else
        return v1[0] > v2[0];
}

//确立排序规则，然后考虑怎么插入比较合适
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(),people.end(), camp);
    vector<vector<int>> res;
    for (int i = 0; i < people.size(); ++i) {
        res.insert(res.begin()+people[i][1], people[i]);
    }

    return res;

}

vector<vector<int>> reconstructQueue1(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), camp);
    int n = people.size();

    while (true){
        bool isChange = false;

        for (int i = 0; i < n; ++i) {
            int h = people[i][0];
            int k = people[i][1];
            int t = 0; //t 代表大于等于其h前面的人
            for (int j = 0; j < i; ++j) {
                if (people[j][0] >= h) t++;
            }

            int j = i + 1;
            while (k > t && j < n) {
                if (people[j][0] >= h){
                    t++;
                }
                j++;
            }

            if (j != i+1) {
                people.insert(people.begin() + j, vector<int>{h, k});
                people.erase(people.begin() + i);
                isChange = true;
                break;
            }

        }

        if (!isChange)
            break;
    }

    return people;
}

int main406(){
    vector<vector<int>> people;
    /*people.push_back({7,0});
    people.push_back({4,4});
    people.push_back({7,1});
    people.push_back({5,0});
    people.push_back({6,1});
    people.push_back({5,2});*/
    people.push_back({6,0});
    people.push_back({5,0});
    people.push_back({4,0});
    people.push_back({3,2});
    people.push_back({2,2});
    people.push_back({1,4});
    reconstructQueue(people);
    return 0;
}

/*

*/
