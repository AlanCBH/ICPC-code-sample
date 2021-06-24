/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* tmp = new Node(head->val);
        tmp->next = copyList(head->next);
        return tmp;
    }
    
    Node* copyRandomList(Node* head) {
        Node* res = copyList(head);
        map<Node*, int> node_index;
        map<int, Node*> index_new_node;
        Node* temp = head;
        Node* temp_copy = res;
        int index = 0;
        while (temp != NULL) {
            node_index[temp] = index;
            index_new_node[index] = temp_copy;
            temp_copy = temp_copy->next;
            temp = temp->next;
            index++;
        }
        index = 0;
        temp = head;
        while (temp != NULL) {
            Node* ran = temp->random;
            if (ran != NULL) {
                int new_ind = node_index[ran];
                index_new_node[index]->random = index_new_node[new_ind];
            }
            temp = temp->next;
            index++;
        }
        return res;
    }
};