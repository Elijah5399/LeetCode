class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= n - 1) {
            return -1;
        }
        int l = 1, r = 10e7;
        while (l < r) {
            int mid = (l + r) / 2;
            //cout << "l: " << l << endl;
            //cout << "r: " << r << endl;
            //cout << "mid: " << mid << endl;
            if (canMakeIt(dist, hour, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    int canMakeIt(vector<int>& dist, double hour, int speed) {
        double t = 0.0;
        
        for (auto d : dist) {
            t = ceil(t);
            double time_taken = (double) d / speed;
            t += time_taken;
            //cout << "t in loop: " << t << endl;
        }
        //cout << "t end: " << t << endl;
        return t <= hour;
    }
};