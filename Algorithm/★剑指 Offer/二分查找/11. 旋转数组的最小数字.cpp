//
//二分查找
//升序数组只旋转一次。
//    1. numbers[pivot]<numbers[r]，pivot右侧升序，最小值在pivot左侧
//    2. numbers[pivot]>numbers[r]，pivot右侧存在降序，最小值在pivot右侧
//    3. numbers[pivot]==numbers[r]，存在相同元素，无法判断，可忽略一个r

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l=0,r=numbers.size()-1;
        while(l<r){
            int pivot=l+(r-l)/2;
            if(numbers[pivot]<numbers[r]){
                r=pivot;
            }
            else if(numbers[pivot]>numbers[r]){
                l=pivot+1;
            }
            else{
                r--;
            }
        }
        return numbers[l];
    }
};
