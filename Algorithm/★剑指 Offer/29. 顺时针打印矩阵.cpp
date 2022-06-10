//
//定义directions来改变方向
//直接先计算nextm和nextn然后进行边界判断，就不需要回退了，如果visited那么就转向
//
class Solution {
public:
    vector<int> directions{0,1,0,-1,0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return {};
        }
        int row=matrix.size(), column=matrix[0].size();
        int num=row*column;        
        vector<vector<bool>> visited(row,vector<bool>(column,false));
        int m=0,n=0;
        int k=0;
        vector<int> ordered(num);
        for(int i=0;i<num;++i){
            ordered[i]=matrix[m][n];
            visited[m][n]=true;
            int nextm=m+directions[k],nextn=n+directions[k+1];
            if(nextn>=column || nextm>=row || nextn<0 || nextm<0 || visited[nextm][nextn]){
                k=(k+1)%4;
            }
            m += directions[k];
            n += directions[k+1];
        }
        return ordered;
    }
};
