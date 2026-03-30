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
        if (node == nullptr) {
            return nullptr;
        }
        else {
            vector<Node*> visited (101, nullptr);
            queue<Node*> itin {};
            itin.push(node);
            while (!(itin.empty())) {
                Node* current = itin.front();
                Node* clone = new Node(current->val);
                visited[current->val] = clone;
                for (Node* nod : current->neighbors) {
                    if (visited[nod->val] == nullptr) {
                        itin.push(nod);
                    }
                    else {
                        continue;
                    }
                }
                itin.pop();
            }
            itin.push(node);
            vector<int> again(101, 0);
            while (!(itin.empty())) {
                Node* now = itin.front();
                if (again[now->val] == 0) {
                    again[now->val] = 1;
                }
                else {
                    itin.pop();
                    continue;
                }
                for (Node* nodee : now->neighbors) {
                    visited[now->val]->neighbors.push_back(visited[nodee->val]);
                    if (again[nodee->val] == 0) {
                        itin.push(nodee);
                    }
                    else {
                        continue;
                    }
                }
                itin.pop();
            }
            return visited[node->val];
        }
    }
};
