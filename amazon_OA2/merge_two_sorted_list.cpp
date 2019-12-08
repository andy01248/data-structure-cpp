//use the existed link!! and no need to make connection all the time
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1 = l1; // res link list head
        ListNode* temp2 = l2;
        ListNode* prev = NULL; // track the prev node of l1
        if (l1==NULL) return l2;
        else if (l2==NULL) return l1;
        else{                   
            while (temp1!=NULL && temp2!=NULL){   
                
                while (temp1!= NULL && temp1->val<=temp2->val){
                    prev=temp1;
                    temp1=temp1->next;
                }
                if (prev!=NULL) prev->next=temp2;
                if (temp1==NULL) break;
                while(temp2!= NULL && temp1->val>temp2->val){
                    prev=temp2;
                    temp2=temp2->next;
                }
                    prev->next=temp1;           
            }                             
            if(l1->val<=l2->val) return l1;    //set the head position
            else return l2;
        }         
    }
};

/////////////////////////////////////////////
//Create a new link and make the connetion all the time
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* prev = new ListNode(0);
        ListNode* res = prev;
        if (l1==NULL) return l2;
        else if (l2==NULL) return l1;
        else{                   
            while (l1!=NULL && l2!=NULL){   
                
                if ( l1->val<=l2->val){
                    prev->next=l1;
                    l1=l1->next;
                }
                else {
                    prev->next=l2;
                    l2=l2->next;
                }
                   prev=prev->next;
            } 
            while (l1!=NULL){
                    prev->next=l1;
                    l1=l1->next;
                    prev=prev->next;
            }
            while (l2!=NULL){
                    prev->next=l2;
                    l2=l2->next;
                    prev=prev->next;
            }
        return res->next;
        }         
    }
};