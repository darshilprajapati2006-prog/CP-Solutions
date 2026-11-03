class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* temp = new ListNode(0);
       ListNode* curr = temp;

       int carry =0;

        while(l1 != NULL || l2 != NULL ||  carry != 0){
            int sum = carry ;

            if(l1 != NULL){
                sum += l1->val ;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val ;
                l2 = l2->next;
            }

            carry = sum/10;
            int digit = sum % 10;

            curr->next = new ListNode(digit);
            curr = curr-> next;
       }
       return temp-> next;;
    }
};

/*
APPROCH :
Steps:
1. Create a temp node with value 0 and a pointer curr pointing to it. Set carry = 0.
2. Run a while loop as long as l1 is not NULL, l2 is not NULL, or carry is not 0.
3. Inside the loop, start with sum = carry.
4. If l1 is not NULL, add l1->val to sum and move l1 to l1->next. Do the same for l2.
5. Create a new node with value (sum % 10) and attach it to curr->next, then move curr forward.
6. Update carry = sum / 10.
7. After the loop ends, return temp->next as the head of the result list.

Time Complexity : O(max(n, m)), where n and m are the lengths of l1 and l2
Space Complexity : O(max(n, m)) for the output list (O(1) extra space)

note: The digits are already stored in reverse order, so we can add from the head directly without reversing. The carry in the while condition handles the last extra node.
*/