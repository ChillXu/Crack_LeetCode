//
//数组映射字符
//
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chars(128,0);
        vector<bool> flags(128,false);
        for(int i=0;i<t.size();++i){      //统计t中的字符情况
            flags[t[i]]=true;
            ++chars[t[i]];
        }
        int l=0,r,min_len=s.size()+1,cnt=0,start;
        for(r=0;r<s.size();++r){        //移动右指针r
            if(flags[s[r]]){
                if(--chars[s[r]]>=0){    //满足说明t中的字符还未全部覆盖
                    cnt++;         
                }
            }
            while(cnt==t.size()){
                if(r-l+1<min_len){     //可能上一轮的r也产生了一个最小覆盖
                    min_len=r-l+1;
                    start=l;
                }
                if(flags[s[l]] && ++chars[s[l]]>0){
                    --cnt;
                }
                ++l;
            }
        }
        return s.size()<min_len?"":s.substr(start,min_len);
    }
};


//
//hash映射
//
