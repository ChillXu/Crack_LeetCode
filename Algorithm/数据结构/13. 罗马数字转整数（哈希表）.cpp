//
//比较当前字符与其右边字符的大小，当前字符小于右边字符则减，否则加
//IV  -1+5
//
class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map<char,int> hash={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        for(int i=0;i<s.size();++i){
            if(hash[s[i]]>=hash[s[i+1]]){   // c++11 之后规定，string末尾会多一个'\0'字符，所以 s[i+1] 访问到的是'\0'字符，也不算越界
                ans+=hash[s[i]];            // hash 访问不到会返回0
            }
            else{
                ans-=hash[s[i]];
            }
        }
        return ans;
    }
};
