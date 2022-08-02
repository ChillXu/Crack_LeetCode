//
//贪心
//
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> hash;
        int task_maxnum=0;
        for(auto task:tasks){         //统计每个任务出现的次数，找到出现次数最多的任务
            task_maxnum=max(task_maxnum,++hash[task-'A']);
        }
        int mint=(task_maxnum-1)*(n+1);   //因为相同元素必须有n个冷却时间，假设A出现3次，n = 2，任务要执行完，至少形成AXX AXX A序列
      
        //此时为了尽量利用X所预占的空间（贪心）使得整个执行序列长度尽量小，将剩余任务往X预占的空间插入
        //剩余的任务次数有两种情况：
        //1.与A出现次数相同，那么B任务最优插入结果是ABX ABX AB，中间还剩两个空位，当前序列长度+1
        //2.比A出现次数少，若还有X，则按序插入X位置，比如C出现两次，形成ABC ABC AB的序列
        //直到X预占位置还没插满，剩余元素逐个放入X位置就满足冷却时间至少为n
      
        for(auto it=hash.begin();it!=hash.end();++it){
            if(it->second==task_maxnum) mint++;
        }
      
        //当所有X预占的位置插满了怎么办？
        //在任意插满区间（这里是ABC）后面按序插入剩余元素，比如ABCD ABCD发现D之间距离至少为n+1，肯定满足冷却条件
        //因此，当X预占位置能插满时，最短序列长度就是task.size()，不能插满则取mint
      
        return max(mint,int(tasks.size()));
    }
};
