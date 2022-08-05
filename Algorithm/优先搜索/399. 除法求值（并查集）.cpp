//
//
//
class UnionFind{
private:
    vector<int> parent;        // 存放父节点
    vector<double> weight;     // 指向父节点的权值
public:
    UnionFind(int n){
        for(int i=0;i<n;++i){
            parent.push_back(i);    // 初始化父亲节点即为自己本身
            weight.push_back(1.0);  // 对应的权重也为1.0 (a/a=1.0)
        }
    }

    void myunion(int x, int y, double value){
        int rootX=find(x),rootY=find(y);
        if(rootX==rootY){
            return;
        }
        parent[rootX]=rootY;
        weight[rootX]=value*weight[y]/weight[x];
    }
    // 路径压缩
    int find(int x){
        if(x!=parent[x]){
            int tmp=parent[x];
            parent[x]=find(parent[x]);
            weight[x]*=weight[tmp];
        }
        return parent[x];
    }
    // 返回除法结果
    double isConnected(int x, int y){
        int rootX=find(x),rootY=find(y);
        if(rootX==rootY){
            return weight[x]/weight[y];
        }
        return -1.00000;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        UnionFind unionfind(2*n);   // 最极端的情况equations中的每个var都不同
        unordered_map<string,int> hash;
        int id=0;
        for(int i=0;i<n;++i){       // 第 1 步：预处理，将变量的值与 id 进行映射
            string var1=equations[i][0];
            string var2=equations[i][1];
            if(!hash.count(var1)){
                hash[var1]=id++;
            }
            if(!hash.count(var2)){
                hash[var2]=id++;
            }
            unionfind.myunion(hash[var1],hash[var2],values[i]); // 把分子分母用有向边连起来
        }
        // 第 2 步： 查询
        int queriesSize=queries.size();
        vector<double> ans(queriesSize,-1.00000);
        for(int i=0;i<queriesSize;++i){
            string var1=queries[i][0];
            string var2=queries[i][1];
            if(hash.count(var1) && hash.count(var2)){       // 如果两个值有至少一个不在equations中，结果为-1，否则做除法
                ans[i]=unionfind.isConnected(hash[var1],hash[var2]);
            }
        }
        return ans;
    }
};
