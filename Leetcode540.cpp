//
// Created by Admin on 2021/11/18.
//
#include<vector>
#include <iostream>

using namespace std;
/**
 * 利用mid与旁边的元素成对而导致的两边奇偶个数来判断single在哪
 * 因为只有一个single，那么总数一定是奇数个
 * @param nums
 * @return
 */
int singleNonDuplicate(vector<int>& nums) {
   int r = nums.size()-1;
   int l = 0;
   while(l <= r){
       int mid = (l + r)/2;
       int halfCount = mid - l;
       if (halfCount%2 == 0){
           //两边都剩偶数个，那么mid和哪边成一对，single就在哪边
           if(nums[mid] == nums[mid - 1])   r = mid - 2;
           else if(nums[mid] == nums[mid + 1])  l = mid + 2;
           else return nums[mid];
       }else{
           //两边都剩奇数个，那么mid和哪边成一对，single就在另外一边边
           if(nums[mid] == nums[mid - 1])   l = mid + 1;
           else if(nums[mid] == nums[mid + 1])  r = mid - 1;
           else return nums[mid];
       }
   }
   return nums[l];
}

int main540(){
    vector<int> nums({3,3,7,7,10,11,11});
    cout << singleNonDuplicate(nums);
    return 0;
}