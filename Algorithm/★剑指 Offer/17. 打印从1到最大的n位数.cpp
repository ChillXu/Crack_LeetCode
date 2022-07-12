//
//
//


//
//不考虑大数
//
class Solution {
public:
    vector<int> printNumbers(int n) {
        int maxNum=1;
        while(n){
            maxNum*=10;
            n--;
        }
        vector<int> ans;
        for(int i=1;i<maxNum;++i){
            ans.push_back(i);    //或者emplace_back
        }
        return ans;
    }
};
