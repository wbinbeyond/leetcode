class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0,
            r = s.size() - 1;
        while (l < r) {
            swap(s[l], s[r]);
            l++;
            r--;
        }
    }
    
    void swap(char& l, char& r) {
        char tmp = l;
        l = r;
        r = tmp;
    }
};
