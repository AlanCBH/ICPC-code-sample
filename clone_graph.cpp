/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }    
        Node* new_node = new Node(node->val);
        queue<Node*> bfs_queue;
        map<Node*, int> visited;
        map<Node*, Node*> copied;
        bfs_queue.push(node);
        visited[node] = 1;
        copied[node] = new_node;
        while(!bfs_queue.empty()) {
            Node* temp = bfs_queue.front();
            
            bfs_queue.pop();
            
            if (copied[temp] == NULL) {
                Node* copy_i = new Node(temp->val);
                copied[temp] = copy_i;
            }
            Node* copy_temp = copied[temp];
            for (int i = 0; i < temp->neighbors.size(); i++) {
                if (visited[temp->neighbors[i]] == 0) {
                    bfs_queue.push(temp->neighbors[i]);
                    visited[temp->neighbors[i]] = 1;
                }
                if (copied[temp->neighbors[i]] == NULL) {
                    Node* copy_i = new Node(temp->neighbors[i]->val);
                    copied[temp->neighbors[i]] = copy_i;
                }
                copy_temp->neighbors.push_back(copied[temp->neighbors[i]]);
            }
            
        }
        return new_node;
        
    }
};