//
//题目：people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面正好有 ki 个身高大于或等于 hi 的人
//
//首先对数对进行排序，按照数对的元素 1 降序排序，按照数对的元素 2 升序排序。
//按照元素 1 降序排序，对于每个元素，在其之前的元素的个数，就是大于等于他的元素的数量，
//按照元素 2 正向排序，我们希望 k 大的尽量在后面，减少插入操作的次数。
//
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const auto& p1,const auto& p2){
            return p1[0]>p2[0] || (p1[0]==p2[0] && p1[1]<p2[1]);
        });
        vector<vector<int>> ans;
        for(int i=0;i<people.size();++i){
            if(people[i][1]>=i){        // 在people[i]前面的元素个数，大于等于目前ans中已有的元素个数，则直接将其添加在末尾
                ans.push_back(people[i]);
            }
            else{
                ans.insert(ans.begin()+people[i][1],people[i]);     // 否则插入在索引为people[i][1]的位置（索引从0开始）
            }
        }
        return ans;
    }
};
