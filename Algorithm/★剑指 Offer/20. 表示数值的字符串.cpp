//
//自动状态机DFA
//

class Solution {
public:
    bool isNumber(string s) {
        vector<unordered_map<char,int>> states={
            {{' ',0},{'s',1},{'d',2},{'.',4}},    //状态0
            {{'d',2},{'.',4}},                    //状态1...
            {{'d',2},{'.',3},{'e',5},{' ',8}},    //注意unordered_map的自定义格式！！
            {{'d',3},{'e',5},{' ',8}},
            {{'d',3}},
            {{'s',6},{'d',7}},
            {{'d',7}},
            {{'d',7},{' ',8}},
            {{' ',8}}
        };    // “;” 注意格式！！
        int p=0;
        char t;
        for(char c:s){
            if(c==' ' || c=='.'){
                t=c;
            }
            else if(c=='+' || c=='-'){
                t='s';
            }
            else if(c>='0' && c<='9'){
                t='d';
            }
            else if(c=='e' || c=='E'){
                t='e';
            }
            else t='?';
            if(!states[p].count(t)){     //判断当前状态 p 在 t 情况下是否可以转移，若无法转移则不满足数值规则
                return false;
            }
            p=states[p][t];
        }
        return p==2||p==3||p==7||p==8;   //状态2、3、7、8为满足数值规则的状态
    }
};
