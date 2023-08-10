class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        auto comp = [](auto a, auto b) {
            return a > b;
        };
        int n = costs.size();
        priority_queue<int, vector<int>, decltype(comp)> head_queue(comp);
        priority_queue<int, vector<int>, decltype(comp)> tail_queue(comp);
        int start = 0;
        for (int i = 0; i < min(n / 2, candidates); i++) {
            start++;
            head_queue.push(costs[i]);
        }
        int end = n - 1;
        for (int j = n - 1; j > max(n - candidates - 1, n / 2 - 1); j--) {
            end--;
            tail_queue.push(costs[j]);
        }
        long long res = 0;
        while (k > 0) {
            if (head_queue.empty()) {
                res += tail_queue.top();
                tail_queue.pop();
            } else if (tail_queue.empty()) {
                res += head_queue.top();
                head_queue.pop();
            } else {
                int h_next = head_queue.top(), t_next = tail_queue.top();
                if (h_next <= t_next) {
                    head_queue.pop();
                    res += h_next;
                    if (start <= end) {
                        head_queue.push(costs[start]);
                        start++;
                    }
                } else {
                    tail_queue.pop();
                    res += t_next;
                    if (start <= end) {
                        tail_queue.push(costs[end]);
                        end--;
                    }
                }
            }
            k--;
        }
        return res;
    }
};