//
//回溯法
//
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()){
            return false;
        }
        int m=board.size(),n=board[0].size();
        bool find=false;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                backtracking(i,j,board,word,0,visited,find);
            }
        }
        return find;
    }

    void backtracking(int i, int j, vector<vector<char>>& board, string word, int pos, vector<vector<bool>>& visited, bool& find){   //find 引用传递很关键！！！
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){  //边界判定
            return;
        }
        if(word[pos]!=board[i][j] || visited[i][j]){  //字符不匹配或者已经使用过
            return;
        }
        if(pos==word.size()-1){  //上述都不满足且是最后一个字符，则说明网格中存在该字符串
            find=true;
            return;
        }
        visited[i][j]=true;
        backtracking(i+1,j,board,word,pos+1,visited,find);
        backtracking(i-1,j,board,word,pos+1,visited,find);
        backtracking(i,j+1,board,word,pos+1,visited,find);
        backtracking(i,j-1,board,word,pos+1,visited,find);
        visited[i][j]=false;   //回溯
    }
};
