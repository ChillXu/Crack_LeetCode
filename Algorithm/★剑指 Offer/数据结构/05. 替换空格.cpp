//
//新建一个string；或者利用erase、insert也是可以的
//
class Solution {
public:
    string replaceSpace(string s) {
        string array;
        for(auto &c:s){
            if(c==' '){
                array.push_back('%');
                array.push_back('2');
                array.push_back('0');
            }
            else array.push_back(c);
        }
        return array;
    }
};
