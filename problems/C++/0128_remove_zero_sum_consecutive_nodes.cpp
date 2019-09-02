// Problem Statement
// Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

// After doing so, return the head of the final linked list.  You may return any such answer.
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private:
    ListNode* stackToList(stack<pair<int,int>> sum_index){
        ListNode * new_head = NULL;
        while(!sum_index.empty()){
            auto curr = sum_index.top();
            sum_index.pop();
            ListNode *new_node = new ListNode(curr.first);
            new_node->next = new_head;
            new_head = new_node;
        }
        
        return new_head;
    }
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return head;
        
        stack<pair<int,int>> sum_index;
        unordered_set<int>sums;
        ListNode *it = head;
        
        sums.insert(0);
        
        while(it){
            int curr_sum = it->val;
            if(!sum_index.empty()){
                curr_sum += sum_index.top().second;
            }
            
            if(sums.find(curr_sum)!=sums.end()){
                while(!sum_index.empty() && sum_index.top().second != curr_sum){
                    auto curr_top = sum_index.top();
                    sums.erase(curr_top.second);
                    sum_index.pop();
                }
            }else{
                sums.insert(curr_sum);
                sum_index.push(make_pair(it->val,curr_sum));
            }
            
            it = it->next;
        }
        
        return stackToList(sum_index);
        
    }
};

ListNode* arrayToList(const vector<int> &vec){
    ListNode *head = nullptr,*it = nullptr;
    for(auto val : vec){
        ListNode* new_node = new ListNode(val); 
        if(it){
            it->next = new_node;
            it = it->next;
        }else{
            head = new_node;
            it = head;
        }
    }

    return head;
}

void printList(ListNode *list){
    ListNode *it = list;
    while(it){
        cout<<it->val<<" ";
        it = it->next;
    }
    cout<<endl;
}

int main(){
    ListNode* array = arrayToList({1,2,3,-3,-2});
    printList(array);
    Solution sol;
    printList(sol.removeZeroSumSublists(array));
    return 0;
}