//Interleaved insert l2 to l1  l1[1,5,6] l2 [2,3,4] -> [1,2,5,3,6,4]
 //Definition for singly-linked list.
#include<iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp = l1; // copy of l1
        ListNode* nxt = l1; // track the next node of l1
        ListNode* nxt2 = l2; // track the next node of l2
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        while (nxt!=NULL){
            nxt = nxt->next;
            nxt2 = nxt2->next;
            l2->next = temp->next;
            temp->next = l2;    //insert current l2 after L1
            temp = nxt;         //temp list to next node
            l2=nxt2;            //l2 list to next node
        }   
        return l1;
        
    }
};

int main(){



}