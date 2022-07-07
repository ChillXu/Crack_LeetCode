//
//二分查找
//
//

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
