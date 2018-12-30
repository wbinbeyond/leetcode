class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Event> events;
        for (const auto& b : buildings) {
            events.push_back(Event{b[0], b[2], 1});
            events.push_back(Event{b[1], b[2], -1});
        }
        sort(events.begin(), events.end());
        
        priority_queue<int> heap;
        heap.push(0);
        unordered_map<int, int> mp;
        vector<pair<int, int>> res;
        for (const auto& e : events) {
            if (e.type == 1) {
                if (e.h > heap.top()) {
                    res.push_back({e.x, e.h});
                }
                heap.push(e.h);
            }
            else {
                mp[e.h]++;
                while (!heap.empty() && mp[heap.top()] > 0) {
                    mp[heap.top()]--;
                    heap.pop();
                }
                if (e.h > heap.top()) {
                    res.push_back({e.x, heap.top()});
                }
            }
        }
        return res;
    }

private:
    struct Event {
        int x;
        int h;
        int type;  // entering 1, leaving -1
        
        bool operator<(const Event& e) const {
            if (x == e.x) {
                // entering event h from large to small
                // leaving event h from small to large
                return type * h > e.type * e.h;
            }
            return x < e.x;
        }
    };
};
