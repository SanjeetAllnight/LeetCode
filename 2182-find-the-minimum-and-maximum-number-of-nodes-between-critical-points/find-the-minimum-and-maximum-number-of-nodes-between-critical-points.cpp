/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //first identify critical point nodes
        //secondly find distances between critical points
        //lastly return array with max&min of those distances
        ListNode* prev=head;
        ListNode* curr=head->next;
        int pos=1;
        int firstPos=-1, lastPos=-1, minDist=INT_MAX;
        while(curr->next){
            if((curr->val>prev->val && curr->val>curr->next->val) || (curr->val<prev->val && curr->val<curr->next->val)){
                if(firstPos==-1){
                    firstPos=pos; 
                } else {
                    minDist=min(minDist, pos-lastPos);
                }
                lastPos=pos; 
            }
            prev=curr;
            curr=curr->next;
            pos++;
        }
        if(firstPos==-1 || firstPos==lastPos){
            return {-1,-1};
        }
        int maxDist=lastPos-firstPos;
        return {minDist, maxDist};
    }
};