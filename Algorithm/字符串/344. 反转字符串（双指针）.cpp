//
//easy
//
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        for(int l=0,r=n-1;l<r;++l,--r){
            swap(s[l],s[r]);
        }
    }
};
