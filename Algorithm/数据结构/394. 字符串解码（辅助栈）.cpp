//
//题目：输入：s = "3[a]2[bc]"   输出："aaabcbc"
//用栈分别记录数字和字母，遇到‘[’进栈同时将数字归零、字符串清空
//
class Solution {
public:
    string decodeString(string s) {
        stack<pair<int,string>> stk;
        int multi=0;
        string res="";
        for(int i=0;i<s.size();++i){
            if(s[i]>='0' && s[i]<='9'){
                multi*=10;
                multi+=s[i]-'0';
            }
            else if(s[i]=='['){
                stk.push(make_pair(multi,res));
                multi=0;
                res="";
            }
            else if(s[i]==']'){
                auto tmp=stk.top();
                stk.pop();
                string str=tmp.second;      // 需要加上之前已经计算的字符串！
                for(int i=0;i<tmp.first;++i){
                    str+=res;
                }
                res=str;
            }
            else{
                res+=s[i];
            }
        }
        return res;
    }
};
