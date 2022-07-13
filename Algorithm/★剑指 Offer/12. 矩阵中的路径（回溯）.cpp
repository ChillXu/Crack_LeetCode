//
//只需要找到一个满足条件的字符串单词，注意剪枝!
//
//优化：1.不使用visited记录，直接修改board[row][column]='/0'
//      2.不使用find记录，backtracking返回值为bool，res= * || * || * || *

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        int m=board.size(),n=board[0].size();
        bool find=false;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                backtracking(board,word,visited,i,j,find,0);
                //if(find) return true;
            }
        }
        return find;
    }

    void backtracking(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int row, int column, bool& find, int pos){
        if(row<0 || column<0 || row>=board.size() || column>=board[0].size()) {
            return;
        }
        if(visited[row][column] || word[pos]!=board[row][column]){
            return;
        }
        if(pos==word.size()-1){
            find=true;
            return;
        }
        if(find) return;    //如果已经找到，则其它路径不需要继续递归深搜

        visited[row][column]=true;
        backtracking(board,word,visited,row+1,column,find,pos+1);
        backtracking(board,word,visited,row-1,column,find,pos+1);
        backtracking(board,word,visited,row,column+1,find,pos+1);
        backtracking(board,word,visited,row,column-1,find,pos+1);
        visited[row][column]=false;
    }
};
