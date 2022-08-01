//
//优先队列（默认为大顶堆）
//
lass Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>> que;
        vector<int> ans;
        for(int i=0;i<k;++i){
            que.emplace(nums[i],i);
        }
        ans.push_back(que.top().first);
        for(int i=k;i<n;++i){
            que.emplace(nums[i],i);
            while(que.top().second<=i-k){   // 当顶元素不在滑动窗口中时，此时会影响当前最大值的入栈，所以需要出队
                que.pop();
            }
            ans.push_back(que.top().first);
        }
        return ans;
    }
};

//
//单调队列
//维护一个单调队列，队列中的元素单调减，队首即为当前滑动窗口最大值
//
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> que;
        vector<int> ans;
        for(int i=0;i<k;++i){
            while(!que.empty() && nums[i]>=nums[que.back()]){   // 维护单调队列
                que.pop_back();
            }
            que.push_back(i);
        }
        ans.push_back(nums[que.front()]); 
        for(int i=k;i<n;++i){
            while(!que.empty() && nums[i]>=nums[que.back()]){
                que.pop_back();
            }
            que.push_back(i);
            while(que.front()<=i-k){  // 若队首不在滑动窗口中，则移除
                que.pop_front();
            }
            ans.push_back(nums[que.front()]);
        }
        return ans;
    }
};
