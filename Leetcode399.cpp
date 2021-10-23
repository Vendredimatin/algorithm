//
// Created by 刘汉乙 on 2021/8/6.
//

#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/**
 * 这道题乍看之下是到很傻逼的题，但一细想其实是一个图问题，每次给定起点和终点进行搜索，然后对边的值进行运算，所以这道题非常有意思。很不错。
 */
struct Edge{
    string desc;
    double value;
};

unordered_map<string, vector<Edge>> map;
unordered_set<string> visit;

double calBtwPoints(string start, string end, double prevValue){
    if(map.find(start) == map.end())    return -1.0;
    vector<Edge> edges = map[start];

    double ans = -1.0;
    for (Edge edge: edges){
        if (visit.find(edge.desc) != visit.end()) continue;
        visit.insert(edge.desc);
        if (edge.desc == end){
            ans = prevValue * edge.value;
            break;
        }else{
            ans = calBtwPoints(edge.desc, end, prevValue * edge.value);
            if (ans != -1.0) break;
        }
    }

    return ans;
}

vector<double> calcEquation1(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    for (int i = 0; i < equations.size(); ++i) {
        vector<string> equation = equations[i];
        double value = values[i];
        if (map.find(equation[0]) == map.end()){
            vector<Edge> v;
            map[equation[0]] = v;
        }

        if (map.find(equation[1]) == map.end()){
            vector<Edge> v;
            map[equation[1]] = v;
        }

        map[equation[0]].push_back((Edge){equation[1], value});
        map[equation[1]].push_back((Edge){equation[0], 1/value});
    }

    vector<double> ans;
    for (int i = 0; i < queries.size(); ++i) {
        visit.clear();
        vector<string> query = queries[i];
        string s1 = query[0];
        string s2 = query[1];

        if(map.find(s1) == map.end() || map.find(s2) == map.end()){
            ans.push_back(-1.0);
            continue;
        }

        if (s1 == s2){
            ans.push_back(1);
            continue;
        }

        visit.insert(s1);
        double res = calBtwPoints(s1,s2, 1);
        ans.push_back(res);
    }

    return ans;
}

struct Node{
    Node* parent;
    double value = 0.0;
    Node()  {parent = this;}
};

Node* findParent(Node* node){
    if (node->parent == node)
        return node;
    node->parent = findParent(node->parent);
    return node->parent;
}

void unionNodes(Node* node1, Node* node2, unordered_map<string, Node*>& nodes,double value){
    double ratio = node2->value * value / node1->value;
    Node* parent1 = findParent(node1); Node* parent2 = findParent(node2);
    for (auto it = nodes.begin(); it != nodes.end() ; it++) {
        if (findParent(it->second) == parent1){
            it->second->value *= ratio;
        }
    }
    parent1->parent = parent2;
}

/**
 * 因为这道题可能存在不同的几个类，涉及到类间的计算，所以想到了并查集。之前自己做的并查集想的是子节点存储父节点/子节点的值，这样面对query的时候就比较麻烦，不如dfs直接搜索方便。
 * 所以作者用了一个非常妙的方法，假设父节点为1，那么子节点的值自然就定了，然后这样并查集就建立起来
 * 关键是当两个之前的类别要合并时，需要修改其中一个集合的值，就是 double ratio = node2->value * value / node1->value;的作用，这是因为之前
 * node1和node2已经存在，并且其值都是建立在parent = 1的基础上，是相对的值，所以此时node1/node2 ！= num，为了使得num成立，所以必须修改其中一个集合的所有值
 * 例如：
 *      1        1
 *     /           \
 *    b(2)          a(5)
 *    又得到a/b = 2， 那么计入要把右边直接连接到左边的parent下，那么保持b=2不变，又要求等式成立，所以a必须为4，所以a = a/b * b / a = 2
 * 另外：并查集，就想像成有一个array，其中每个元素都是一个节点，然后依靠某种指针连接其父节点
 * @param equations
 * @param values
 * @param queries
 * @return
 * https://leetcode.com/problems/evaluate-division/discuss/88170/0ms-C%2B%2B-Union-Find-Solution-EASY-to-UNDERSTAND
 */

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, Node*> uf;

    for (int i = 0; i < equations.size(); ++i) {
        string s1 = equations[i][0];
        string s2 = equations[i][1];
        double value = values[i];
        if (uf.find(s1) == uf.end() && uf.find(s2) == uf.end()){
            Node* n1 = new Node(), *n2 = new Node();
            n1->value = value;
            n2->value = 1;
            n1->parent = n2;
            uf[s1] = n1;
            uf[s2] = n2;
        }else if(uf.find(s1) == uf.end()){
            Node *n1 = new Node();
            n1->value = uf[s2]->value * value;
            n1->parent = uf[s2];
            uf[s1] = n1;
        }else if(uf.find(s2) == uf.end()){
            Node *n2 = new Node();
            n2->value = uf[s1]->value / value;
            n2->parent = uf[s1];
            uf[s2] = n2;
        }else{
            unionNodes(uf[s1], uf[s2], uf, value);
        }

    }

    vector<double> res;
    for (auto query : queries) {
        if (uf.count(query[0]) == 0 || uf.count(query[1]) == 0 || findParent(uf[query[0]]) != findParent(uf[query[1]]))
            res.push_back(-1);
        else
            res.push_back(uf[query[0]] -> value / uf[query[1]] -> value);
    }
    return res;

}



int main399(){
    vector<vector<string>> equations;
    equations.push_back({"a","b"});
    equations.push_back({"b","c"});
    vector<double> values({2.0,3.0});
    vector<vector<string>> queries;
   queries.push_back({"a","c"});
   queries.push_back({"b","a"});
   queries.push_back({"a","e"});
   queries.push_back({"a","a"});
   queries.push_back({"x","x"});
    calcEquation(equations,values,queries);
    return 0;
}