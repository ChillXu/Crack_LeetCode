//
//nums1是大小为m+n填充好0的数组，从后往前归并排序
//最终如果m>=0即nums1有剩余则排序完成，n>=0仍需要将nums2中的复制到nums1中
//
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos=m-- + n-- -1;
        while(m>=0 && n>=0){                           
            if(nums2[n]>=nums1[m]){                 //nums1[pos--] = nums2[n]>=nums1[m]?nums2[n--]:nums1[m--]
                nums1[pos]=nums2[n];
                pos--;
                n--;
            }
            else{
                nums1[pos]=nums1[m];
                pos--;
                m--;
            }
        }
        while(n>=0){
            nums1[pos]=nums2[n];
            pos--;
            n--;
        }
    }
};
