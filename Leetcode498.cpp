//
// Created by Admin on 2021/11/18.
//
#include<vector>
using namespace std;
vector<int> findDiagonalOrder2(vector<vector<int>>& mat) {
    vector<int> res;
    int row = mat.size(), col = mat[0].size();
    int r = 0, c = 0, cnt = row*col, dir = 1;
    while (cnt--) {
        res.push_back(mat[r][c]);
        r -= dir;
        c += dir;
        if (r >= row) {
            --r;
            c += 2;
            dir *= -1;
        } else if (c >= col) {
            --c;
            r += 2;
            dir *= -1;
        } if (r < 0) {
            ++r;
            dir *= -1;
        } else if (c < 0) {
            ++c;
            dir *= -1;
        }
    }
    return res;
}

/**
 * 写的还不够简洁，反正通过i、j之和的奇偶性来判断方向，当遇到边界时转向应的方向
 * @param mat
 * @return
 */
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    // i + j = even ， up traverse; odd, down traverse
    int m = mat.size(); int n = mat[0].size();
    int sz = m*n;
    vector<int> ans;
    int i = 0, j = 0;

    while(sz-- > 0){
        if ((i+j)%2 == 0){
            //up
            while(i >=0 && j <= n-1){
                ans.push_back(mat[i][j]);
                if (j == n-1){
                    j++;
                    break;
                }else if(i == 0){
                    i++;
                    break;
                }
                i--; j++;
            }

        }else{
            while(i < m && j >= 0){
                ans.push_back(mat[i][j]);
                if(i == m-1){
                    j++;
                    break;
                }else if(j == 0){
                    i++;
                    break;
                }
                i++; j--;
            }
            if (j == -1) j = 0;
        }
    }

    return ans;
}
