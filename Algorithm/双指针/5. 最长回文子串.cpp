//
//中心扩展法
//枚举所有的回文中心并向两边扩展，直到无法扩展为止
//
class Solution {
public:
    pair<int,int> expandAroundCenter(string s, int left, int right){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return make_pair(left+1,right-1);
    }
    string longestPalindrome(string s) {
        int maxlen=0;
        int start=0,end=0;
        for(int i=0;i<s.length();++i){
            auto [left1,right1]=expandAroundCenter(s,i,i);       //需要考虑回文中心是1还是2
            auto [left2,right2]=expandAroundCenter(s,i,i+1);
            if(right1-left1>end-start){
                start=left1;
                end=right1;
            }
            if(right2-left2>end-start){
                start=left2;
                end=right2;
            }
        }
        return s.substr(start,end-start+1);
    }
};
