class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n, false);
        bool validTree = false;
        for (int i = 0; i < n; i++) {
            validTree = validTree || bfs(leftChild, rightChild, visited, i);
        }
        return validTree;
    }
    bool bfs(vector<int>& leftChild, vector<int>& rightChild, vector<bool> visited, int root) {
        visited[root] = true;
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int next = q.front();
            q.pop();
            int l = leftChild[next], r = rightChild[next];
            if (l != -1) {
                if (visited[l]) return false;
                visited[l] = true;
                q.push(l);
            }
            if (r != -1) {
                if (visited[r]) return false;
                visited[r] = true;
                q.push(r);
            }
        }
        bool val = true;
        for (bool b : visited) {
            val = val && b;
        }
        return val;
    }
};