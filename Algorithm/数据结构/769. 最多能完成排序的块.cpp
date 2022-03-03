\\
\\如果下标与元素的值一致，块数加一
\\如果下标与元素的值不一致，则当前块的大小（所应含有的元素数目）至少为元素的值    [2,1,0,3] [2,1,0]和[3]
\\
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int num=0;
        for(int i=0;i<n;++i){
            int block_len=arr[i];
            if(arr[i]==i){num++;}
            for(int j=i+1;j<=block_len;++j){
                if(arr[j]>block_len){
                    block_len=arr[j];
                }
                if(j==block_len){
                    i=block_len;    \\错误：i=block_len+1 || ++i会进行自增操作
                    num++;
                }
            }
        }
        return num;
    }
};
    
