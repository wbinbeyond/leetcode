class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for (auto& p : s2) {
            if (start >= p.second || p.first >= end) continue;
            else return false;
        }
        for (auto& p : s1) {
            if (start >= p.second || p.first >= end) continue;
            else {
                s2.emplace_back(max(start, p.first), min(end, p.second));
            }
        }
        s1.emplace_back(start, end);
        return true;
    }
private:
    vector<pair<int, int>> s1, s2;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
