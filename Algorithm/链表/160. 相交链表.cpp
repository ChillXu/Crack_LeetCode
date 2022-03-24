//
//先遍历headA，用unordered_set记录所有节点
//再遍历headB，查找节点是否在表中存在
//
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited;
        ListNode *temp=headA;
        while(temp){
            visited.insert(temp);
            temp=temp->next;
        }
        temp=headB;
        while(temp){
            if(visited.count(temp)){
                return temp;
            }
            temp=temp->next;
        }
        return nullptr;
    }
};
