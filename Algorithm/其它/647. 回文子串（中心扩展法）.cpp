//
//
//
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int num=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<=1;++j){  // j=0，回文中心为一个字符；j=1，回文中心为两个字符
                int l=i;
                int r=i+j;
                while(l>=0 && r<n && s[l--]==s[r++]) num++;
            }
        }
        return num;
    }
};
