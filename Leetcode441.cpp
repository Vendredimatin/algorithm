//
// Created by Admin on 2021/11/18.
//
/**
 * 这种二分查找与正常二分查找的不同在，比较的mid是不一样的，需要经过一些计算
 * @param n
 * @return
 */
int arrangeCoins(int n) {
    int l = 0;
    int r = n;
    int mid = 0;
    while(l <= r){
        mid = l + (r-l)/2;
        int tempSum = (mid+2) * (mid + 1)/2;
        if(tempSum > n) r = mid - 1;
        else if(tempSum < n) l = mid + 1;
        else return mid+1;
    }

    return l;
}

int main441(){
    arrangeCoins(8);
    return 0;
}