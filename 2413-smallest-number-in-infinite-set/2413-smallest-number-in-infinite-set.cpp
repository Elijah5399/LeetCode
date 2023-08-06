class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> contents;
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            pq.push(i);
            contents.insert(i);
        }
    }
    
    int popSmallest() {
        int smallest = pq.top();
        pq.pop();
        contents.erase(smallest);
        return smallest;
    }
    
    void addBack(int num) {
        if (!contents.count(num)) {
            pq.push(num);
            contents.insert(num);
        } 
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */