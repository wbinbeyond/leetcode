class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto b : mybook) {
            int s = b.first;
            int e = b.second;
            if (max(start, s) < min(end, e)) return false;
        }
        mybook.emplace_back(start, end);
        return true;
    }

private:
    vector<pair<int, int>> mybook;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * b4ool param_1 = obj.book(start,end)
 =/1
