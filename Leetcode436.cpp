//
// Created by Admin on 2021/11/17.
//
#include<vector>
#include<algorithm>
using namespace std;

struct Interval{
    int start;
    int end;
    int index;
    Interval(int _start, int _end, int _index){start = _start; end = _end; index = _index;}
};

bool camp436(Interval* i1, Interval* i2){
    if (i1->start == i2->start) return i1->end < i2->end;
    else return i1->start < i2->start;
}

//挺像桶排序的，把start作为桶
vector<int> findRightInterval(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<int> ans(n);
    vector<Interval*> newIntervals(n);
    for (int i = 0; i < n; ++i) {
        newIntervals[i] = new Interval(intervals[i][0],intervals[i][1],i);
    }

    sort(newIntervals.begin(), newIntervals.end(), camp436);

    for (int i = 0; i < n-1; ++i) {
        ans[newIntervals[i]->index] = -1;
        for (int j = i; j < n; ++j) {
            if (newIntervals[j]->start >= newIntervals[i]->end){
                ans[newIntervals[i]->index] = newIntervals[j]->index;
                break;
            }
        }
    }

    ans[newIntervals[n-1]->index] = -1;
    return ans;
}

/**
 * 确实，排序之后直接可以用二分查找
 * @param v
 * @param target
 * @return
 */
int Binary_search(vector<pair<pair<int, int>,int>>& v, int target){
    if(v[v.size()-1].first.first < target)
        return -1;
    int l=0, r=v.size()-1, mid;
    while(l <= r){
        mid = l + (r - l)/2;
        if(v[mid].first.first >= target)
            r = mid -1;
        else
            l = mid + 1;
    }
    return v[l].second;
}

vector<int> findRightInterval1(vector<vector<int>>& intervals) {
    vector<int> result;
    vector<pair<pair<int,int>, int>> copy;
    for(int i=0;i<intervals.size();i++)
        copy.push_back({{intervals[i][0], intervals[i][1]}, i});

    sort(copy.begin(), copy.end());
    for(int i=0;i<copy.size();i++)
        result.push_back(Binary_search(copy, intervals[i][1]));

    return result;
}

int main436(){
    vector<vector<int>> intervals;
    intervals.push_back({1,4});
    intervals.push_back({2,3});
    intervals.push_back({3,4});
    findRightInterval(intervals);
    return 0;
}