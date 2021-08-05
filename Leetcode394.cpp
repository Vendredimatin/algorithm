//
// Created by 刘汉乙 on 2021/8/4.
//
#include<string>
#include<stack>
using namespace std;

/**
 * 虽然题是挺简单的，但还是比较有借鉴和代表意义，当遇到这样成对括号的，有回溯需求的，可以使用栈或者递归
 * @param ch
 * @return
 */
bool isDigit(string ch){
    if (ch == "0" || ch == "1" || ch == "2" || ch == "3" || ch == "4" || ch == "5" || ch == "6" || ch == "7" || ch == "8" || ch == "9")
        return true;
    else return false;
}

string decodeString(string s) {
    string t = s;
    stack<string> st;
    int n = s.size();
    int i = 0;
    string ans = "";

    while (i < n){
        if(isalpha(s[i]) || s[i] == '[' || isdigit(s[i]))  st.push(string(1,s[i]));
        else if(s[i] == ']'){
            string tmp = "";
            while(st.top() != "["){
                tmp = st.top() + tmp;
                st.pop();
            }
            st.pop();

            int num = 0;
            string numStr = "";
            while(!st.empty() && isDigit(st.top())){
                numStr = st.top() + numStr;
                st.pop();
            }
            num = stoi(numStr);

            string str = "";
            for (int k = 0; k < num; ++k) {
                str += tmp;
            }
            
            st.push(str);
        }

        i++;
    }

    while(!st.empty()){
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}

int main394(){
    string s = "abc3[cd]xyz";
    decodeString(s);
    return 0;
}