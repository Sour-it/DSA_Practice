352. Data Stream as Disjoint Intervals
Hard

Binary Search, Design, Ordered Set
Time : O(n log n)
Space : O(n)

class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        if (map.count(value))
            return;

        const int lo = lowerKey(value);
        const int hi = higherKey(value);
        if (lo >= 0 && hi >= 0 && map[lo][1] + 1 == value && value + 1 == hi) {
            map[lo][1] = map[hi][1];
            map.erase(hi);
        } else if (lo >= 0 && map[lo][1] + 1 >= value) {
            map[lo][1] = max(map[lo][1], value);
        } else if (hi >= 0 && value + 1 == hi) {
            map[value] = {value, map[hi][1]};
            map.erase(hi);
        } else {
            map[value] = {value, value};
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        for (const auto& [_, interval] : map)
            intervals.push_back(interval);
        return intervals;
    }
private:
    map<int, vector<int>> map;
        int lowerKey(int key) {
        auto it = map.lower_bound(key);
        if (it == begin(map))
            return -1;
        return (--it)->first;
    }
    int higherKey(int key) {
        const auto it = map.upper_bound(key);
        if (it == cend(map))
            return -1;
        return it->first;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */