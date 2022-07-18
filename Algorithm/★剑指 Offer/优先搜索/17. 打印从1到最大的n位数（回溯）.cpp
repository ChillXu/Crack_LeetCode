//
//考虑大数情况，只能用字符串来表示，利用回溯列举
//

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ans;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=9;++j){
                string num(1,j+'0');
                backtracking(num,1,i,ans);
            }
        }
        return ans;
    }

    void backtracking(string num, int level, int digit, vector<int>& ans){
        if(level==digit){
            ans.emplace_back(stoi(num));   //leetcode本题结果需要返回vector<int>
            return;
        }
        for(int i=0;i<=9;++i){
            num.push_back(i+'0');
            backtracking(num,level+1,digit,ans);
            num.pop_back();
        }
    }
};

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
