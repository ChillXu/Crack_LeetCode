//
//KMP算法
//构造next数组，背诵！！！！
//
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(),m=needle.size();
        if(m==0) return 0;
        haystack.insert(haystack.begin(),' ');      // 添加空字符，避免 j=next[j-1] j=-1 的情况！
        needle.insert(needle.begin(),' ');
        vector<int> next(m+1);
        for(int i=2,j=0;i<=m;++i){      // 构建next数字，在匹配串needle中，找最大相同的前缀后缀
            while(j && needle[i]!=needle[j+1]) j=next[j];   // 当前字符不匹配 j 指针回退到上一个相同的前缀，直到 j=0
            if(needle[i]==needle[j+1]) j++;
            next[i]=j;
        }
        for(int i=1,j=0;i<=n;++i){
            while(j && haystack[i]!=needle[j+1]) j=next[j];
            if(haystack[i]==needle[j+1]) j++;
            if(j==m) return i-j;      // 当 j 到达匹配串末尾，说明完成匹配，返回索引
        }
        return -1;
    }
};
