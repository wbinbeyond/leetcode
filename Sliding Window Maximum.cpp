class MonotonicQueue {
public: 
    void push(int e) {
        while (!data_.empty() && e > data_.back())
        {
            data_.pop_back();
        }
        data_.push_back(e);
    }
    
    void pop() {
        data_.pop_front();
    }
    
    int top() const {
        return data_.front();
    }
private:
    deque<int> data_;
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            q.push(nums[i]);
            if (i - 0 + 1 >= k) {
                res.push_back(q.top());
                if (nums[i - k + 1] == q.top()) q.pop();
            }
        }
        return res;
    }
};
