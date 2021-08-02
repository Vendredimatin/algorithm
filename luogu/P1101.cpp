//
// Created by 刘汉乙 on 2021/6/14.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n1101;
vector<string > matrix;
vector<string> words;
vector<pair<int,int>> ops({{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}});

char getNextMatch(char match){
    if(match == 'y') return 'i';
    else if(match == 'i') return 'z';
    else if(match == 'z') return 'h';
    else if(match == 'h') return 'o';
    else if(match == 'o') return 'n';
    else  return 'g';
}

bool dfs(vector<string> matrix, int x, int y, char match, int direction){
    if(x < 0 || y < 0 || x >= n1101 || y >= n1101) return false;
    if(matrix[x][y] == match && match == 'g'){
        words[x][y] = match;
        return true;
    }


    if(matrix[x][y] == match){
        char nextMatch = getNextMatch(match);
        int newX = x + ops[direction].first;
        int newY = y + ops[direction].second;
        bool ret = dfs(matrix, newX, newY, nextMatch, direction);

        if (ret)
        {
            words[x][y] = match;
            return true;
        }
    }

    return false;
}

int main1101()
{

    cin >> n1101;
    //int n = 8;
    matrix.resize(n1101);

    string defaultStr = "";
    

    words.resize(n1101,"********");
    for (int i = 0; i < n1101; i++)
    {
        cin >> matrix[i];
    }

    /*matrix.push_back("qyizhong");
    matrix.push_back("gydthkjy");
    matrix.push_back("nwidghji");
    matrix.push_back("orbzsfgz");
    matrix.push_back("hhgrhwth");
    matrix.push_back("zzzzzozo");
    matrix.push_back("iwdfrgng");
    matrix.push_back("yyyygggg");*/

    for (int i = 0; i < n1101; i++)
    {
        for (int j = 0; j < n1101; j++)
        {
            for (int k = 0; k < 8; k++)
                dfs(matrix,i,j,'y', k);
        }

    }

    for (int i = 0; i < n1101; i++)
    {
        cout << words[i] << endl;
    }

    return 0;
}