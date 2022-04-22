//
//遍历每个数字j，将该数字作为树根，将1...（j-1）作为左子树，将(j+1)...i作为右子树
//
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n+1,0);
        G[0]=1;
        G[1]=1;
        for(int i=2;i<=n;++i){
            for(int j=1;j<=i;++j){
                G[i]+=G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
};
