//
//
//
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> search(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        deque<vector<string>> worker;//双端队列记录当前层
        worker.push_back({beginWord});
        while(!worker.empty()){
            unordered_set<string> visited;
            for(int i=worker.size();i>0;--i){//层遍历
                auto sub=worker.front();
                worker.pop_front();
                auto tail=sub.back();
                if(tail==endWord){
                    ans.push_back(sub);
                    continue;//继续检查同一层
                }
                for(int j=0;j<tail.size();++j){
                    char temp=tail[j];
                    for(char c='a';c<='z';++c){
                        if(c==temp) continue;
                        tail[j]=c;
                        if(!search.count(tail)) continue;
                        sub.push_back(tail);
                        worker.push_back(sub);
                        visited.insert(tail);
                        sub.pop_back();//回溯！！！
                    }
                    tail[j]=temp;
                }
            }
            if(!ans.empty()) return ans;
            for(const auto &w:visited) search.erase(w);
        }
        return ans;
    }
};

/*
          hit
             \
             hit,hot
          /          \
      hit,hot,dot    hit,hot,lot
      /                 \
    hit,hot,dot,dog     hit,hot,lot,log
   /                      \
hit,hot,dot,dog,cog       hit,hot,lot,log,cog
*/
