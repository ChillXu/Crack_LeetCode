//
//用两个大小为26的vector记录字符出现的次数
//
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m=s.size(),n=p.size();
        if(m<n) return vector<int>();   // 临界情况，s字符串比p短
        vector<int> counts(26);
        vector<int> countp(26);
        vector<int> ans;
        for(int i=0;i<n;++i){
            ++countp[p[i]-'a'];
            ++counts[s[i]-'a'];
        }
        if(counts==countp){       // 容器可以直接比较
            ans.push_back(0);
        }
        for(int i=0;i<=m-n-1;++i){
            --counts[s[i]-'a'];
            ++counts[s[i+n]-'a'];
            if(counts==countp){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};


//
//真正的滑动窗口！
//维持数组每个元素>=0，小于0时则收缩左边窗口
//
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m=s.size(),n=p.size();
        if(m<n) return vector<int>();
        vector<int> count(26);
        vector<int> ans;
        for(int i=0;i<n;++i){     // 记账
            ++count[p[i]-'a'];
        }
        for(int l=0,r=0;r<m;++r){
            --count[s[r]-'a'];    // 还账
            while(count[s[r]-'a']<0){   // 还多了
                ++count[s[l]-'a'];
                ++l;
            }
            if(r-l+1==n) ans.push_back(l);
        }
        return ans;
    }
};
