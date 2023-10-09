class Solution {
public:
    vector<int> a;
    int minCostConnectPoints(vector<vector<int>>& points) {
        #define tiii tuple<int, int, int>
        int n = points.size();
        priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                pq.push({dist, i, j});
            }
        }
        a = vector<int>(n); // a is the array for union find
        for (int i = 0; i < n; i++) {
            a[i] = -1; // set parent of each elem to itself
        }
        int cost = 0, edges = 0;
        while (edges < n - 1) {
            tiii next = pq.top();
            pq.pop();
            if (find(get<1>(next)) == find(get<2>(next))) {
                continue;
            }
            UNION(get<1>(next), get<2>(next));
            cost += get<0>(next);
            edges++;
        }
        return cost;
    }
    void UNION(int f, int s) {
        int fr = find(f), sr = find(s);
        a[sr] = fr;
    }
    int find(int q) {
        int qp = q;
        while (true) {
            if (a[qp] == -1) break;
            qp = a[qp];
        }
        return qp;
    }
};