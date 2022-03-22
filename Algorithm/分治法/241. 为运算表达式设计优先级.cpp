//
//以 2*3-4*5 为例
//
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ways;
        for(int i=0;i<expression.size();++i){
            char c=expression[i];
            if(c=='+' || c=='-' || c=='*'){
                vector<int> left=diffWaysToCompute(expression.substr(0,i));  //当i=0时，left返回[2]，right返回[-17,-5]
                vector<int> right=diffWaysToCompute(expression.substr(i+1)); 
                for(const int& l:left){                                       //所以需要遍历整个left和right，进行运算组合
                    for(const int& r:right){
                        switch(c){
                            case '+': ways.push_back(l+r);break;
                            case '-': ways.push_back(l-r);break;
                            case '*': ways.push_back(l*r);break;
                        }
                    }
                }
            }
        }
        if(ways.empty()){    //递归出口，即字符串内无运算符号，只有数字
            ways.push_back(stoi(expression));
        }
        return ways;
    }
};

//
//用memoization处理重复出现的子字符串
//
class Solution {
public:
    unordered_map<string,vector<int>> hash;
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ways;
        for(int i=0;i<expression.size();++i){
            char c=expression[i];
            if(c=='+' || c=='-' || c=='*'){
                vector<int> left,right;
                if(!hash.count(expression.substr(0,i))){         //先判断是否不在hash表中！！（这样比反过来快，说明大部分都是不在的）
                    left=diffWaysToCompute(expression.substr(0,i));
                }
                else{
                    left=hash[expression.substr(0,i)];
                }
                if(!hash.count(expression.substr(i+1))){
                    right=diffWaysToCompute(expression.substr(i+1));
                }
                else{
                    right=hash[expression.substr(i+1)];
                }
                for(const int& l:left){
                    for(const int& r:right){
                        switch(c){
                            case '+': ways.push_back(l+r);break;
                            case '-': ways.push_back(l-r);break;
                            case '*': ways.push_back(l*r);break;
                        }
                    }
                }
            }
        }
        if(ways.empty()){
            ways.push_back(stoi(expression));
        }
        hash[expression]=ways;
        return ways;
    }
};
