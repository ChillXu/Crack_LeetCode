//
//设定visited容器，到边界或者已访问则转向
//
class Solution {
public:
    vector<int> dirs{0,1,0,-1,0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        if(r==0 || c==0) return {};
        int num=r*c;
        vector<int> ans(num);
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        int m=0,n=0;
        int k=0;
        for(int i=0;i<num;++i){
            ans[i]=matrix[m][n];
            visited[m][n]=true;
            int nextm=m+dirs[k],nextn=n+dirs[k+1];
            if(nextm<0 || nextm>=r || nextn<0 || nextn>=c || visited[nextm][nextn]){
                k=(k+1)%4;
            }
            m+=dirs[k];
            n+=dirs[k+1];
        }
        return ans;
    }
};
