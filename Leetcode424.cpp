//
// Created by 刘汉乙 on 2021/11/17.
//

//
// Created by 刘汉乙 on 2021/11/13.
//
#include<string>
#include <iostream>
#include<queue>
using namespace std;
/**
 * 思路：计算一个窗口内所有字符出现的最大次数，当然是看出现次数最多的字符，将其他字符改成相应的字符
 * end - start + 1代表该窗口的长度l，l-maxcount等于剩下的字符，如果剩下的字符数量小于k，代表整个窗口都可以变成连续重复的字符（这样就解决了连续的问题）
 * https://leetcode.com/problems/longest-repeating-character-replacement/discuss/91271/Java-12-lines-O(n)-sliding-window-solution-with-explanation
 * @param s
 * @param k
 * @return
 */
int characterReplacement(string s, int k) {
    int n = s.size();
    int start = 0, end = 0, repeatingCount = 0, ans = 0;
    int alphabet[26] = {0};
    for (; end < n; ++end) {
        alphabet[s[end] - 'A']++;
        repeatingCount = max(repeatingCount, alphabet[s[end]- 'A']);
        while (end - start + 1 - repeatingCount > k){
            alphabet[s[start] - 'A']--;
            start++;
        }

        ans = max(ans, end-start+1);
    }

    return ans;
}

int main424(){
    string s = "AABABBA";
    int k = 1;
    cout << characterReplacement(s, k);
    return 0;
}

