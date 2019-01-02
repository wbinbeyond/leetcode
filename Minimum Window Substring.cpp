class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> T;
        for (const auto& c : t) {
            T[c]++;
        }
        
        int start = 0,
            end = 0,
            len = INT_MAX,
            counter = T.size();  //unique character in t
        string res = "";
        
        while (end < s.size()) {
            char endChar = s[end];
            if (T.find(endChar) != T.end()) {
                T[endChar]--;
                if (T[endChar] == 0) counter--;
            }
            end++;
            while (counter == 0) {
                //valid substring
                if (end - start < len) {
                    len = end - start;
                    res = s.substr(start, len);
                }
                char startChar = s[start];
                if (T.find(startChar) != T.end()) {
                    T[startChar]++;
                    if (T[startChar] > 0) counter++;
                }
                start++;
            }
        }
        return res;
    }
};


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> T;
        for (const auto& c : t) {
            T[c]++;
        }
        
        int start = 0,
            end = 0,
            len = INT_MAX,
            counter = T.size();  //unique character in t
        string res = "";
        
        while (end < s.size()) {
            char endChar = s[end];
            if (T.find(endChar) != T.end()) {
                T[endChar]--;
                if (T[endChar] == 0) counter--;
            }
            while (counter == 0) {
                //valid substring
                if (end - start + 1 < len) {
                    len = end - start + 1;
                    res = s.substr(start, len);
                }
                char startChar = s[start];
                if (T.find(startChar) != T.end()) {
                    T[startChar]++;
                    if (T[startChar] > 0) counter++;
                }
                start++;
            }
            end++;  //move end++ down here, easier than the above one to understand
        }
        return res;
    }
};
