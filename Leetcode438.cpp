//
// Created by Admin on 2021/11/17.
//

//
// Created by Admin on 2021/11/17.
//
#include<vector>
#include<string>
using namespace std;
//anagrams异位词就是看count
vector<int> findAnagrams(string s, string p) {
    int alphabet[26] = {0};
    int pSize = p.size();
    int sSize = s.size();

    for (int i = 0; i < p.size(); ++i) {
        alphabet[p[i] - 'a']++;
    }

    int start = 0;
    int checkAlphabet[26] = {0};
    for (int i = 0; i < pSize-1; ++i) {
        checkAlphabet[s[i] - 'a']++;
    }

    vector<int> ans;
    for (int end = pSize-1; end < sSize; ++end) {
        checkAlphabet[s[end] - 'a']++;
        bool isMatch = true;
        for (int i = 0; i < 26; ++i) {
            if (checkAlphabet[i] != alphabet[i]){
                isMatch = false;
                break;
            }
        }

        if (isMatch)    ans.push_back(start);
        checkAlphabet[s[start] - 'a']--;
        start++;
    }

    return ans;
}

int main438(){
    findAnagrams("abab", "ab");
    return 0;
}

