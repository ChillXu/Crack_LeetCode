/* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
 * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
 * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
 * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
 * 这样 pivot 本身最大也只能是第 k-1 小的元素
 * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
 * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
 * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
*/
class Solution {
public:
    int getKthElement(vector<int>& nums1, vector<int>& nums2, int k){
        int m=nums1.size();
        int n=nums2.size();
        int index1=0,index2=0;
        while(true){
            if(index1==m){    // nums1 已经删完
                return nums2[index2+k-1];
            }
            if(index2==n){    // nums2 已经删完
                return nums1[index1+k-1];
            }
            if(k==1){         // 找第1小的元素
                return min(nums1[index1],nums2[index2]);
            }
            int newindex1=min(index1+k/2-1,m-1);
            int newindex2=min(index2+k/2-1,n-1);
            int pivot1=nums1[newindex1],pivot2=nums2[newindex2];
            if(pivot1<=pivot2){
                k -= (newindex1-index1+1);
                index1=newindex1+1; 
            }
            else{
                k -= (newindex2-index2+1);
                index2=newindex2+1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=nums1.size()+nums2.size();
        if(len%2==1){
            return getKthElement(nums1,nums2,len/2+1);   // len/2+1 是指第几个，不是下标
        }
        else{
            return (getKthElement(nums1,nums2,len/2)+getKthElement(nums1,nums2,len/2+1))/2.0;
        }
    }
};
