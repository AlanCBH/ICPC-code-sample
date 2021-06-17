class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> num1;
        stack<int> num2;
        stack<int> res;
        ListNode* temp = l1;
        while(temp != NULL) {
            num1.push(temp->val);
            temp = temp->next;
        }
        temp = l2;
        while(temp != NULL) {
            num2.push(temp->val);
            temp = temp->next;
        }
        int over_ten = 0;
        while (!num1.empty() && !num2.empty()) {
            if (num1.top() + num2.top()+over_ten >= 10) {
                res.push(num1.top() + num2.top()+over_ten-10);
                over_ten = 1;
            } else {
                res.push(num1.top() + num2.top()+over_ten);
                over_ten = 0;
            }
            num1.pop();
            num2.pop();
        }
        if (!num1.empty()) {
            while(!num1.empty()) {
                if (num1.top() + over_ten >= 10) {
                    res.push(num1.top()+over_ten-10);
                    over_ten = 1;
                } else {
                    res.push(num1.top() +over_ten);
                    over_ten = 0;
                }
                num1.pop();
            }
        } 
        if (!num2.empty()) {
             while(!num2.empty()) {
                if (num2.top() + over_ten >= 10) {
                    
                    res.push(num2.top()+over_ten-10);
                    over_ten = 1;
                } else {
                    
                    res.push(num2.top() +over_ten);
                    over_ten = 0;
                }
                num2.pop();
            }
        }
        if (over_ten != 0) {
            res.push(over_ten);
        }
        ListNode* fin;
        fin = new ListNode(res.top());
        res.pop();
        ListNode* prev = fin;
        while (!res.empty()) {
            temp = new ListNode(res.top());
            prev->next = temp;
            prev = temp;
            res.pop();
        }
        return fin;
    }
};
