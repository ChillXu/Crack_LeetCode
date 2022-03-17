//
//按行放置n个皇后，放置完对应列、左斜、右斜皆需记录为true
//位于同一左斜的（行-列）为固定值（对应的加上n避免容器索引为负数），位于同一右斜的（行+列）为固定值，且容器内元素的最多为2n-1个
//例如n=8，索引为[0,1,2,...,7]，行+列的范围为[0,14]即2n-1
//
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if(n==0){
            return ans;
        }
        vector<string> board(n,string(n,'.'));
        vector<bool> column(n,false), ldiag(2*n-1,false), rdiag(2*n-1,false);
        backtracking(ans,n,column,ldiag,rdiag,board,0);
        return ans;
    }

    void backtracking(vector<vector<string>>& ans, int n, vector<bool>& column, vector<bool>& ldiag, vector<bool>& rdiag, vector<string> board, int row){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;++i){
            if(column[i] || ldiag[row-i+n] || rdiag[row+i]){
                continue;
            }
            board[row][i]='Q';
            column[i]=ldiag[row-i+n]=rdiag[row+i]=true;
            backtracking(ans,n,column,ldiag,rdiag,board,row+1);
            board[row][i]='.';
            column[i]=ldiag[row-i+n]=rdiag[row+i]=false;
        }
    }
};
