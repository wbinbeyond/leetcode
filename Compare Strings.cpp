class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        if (A.length() < B.length())
        {
            return false; 
        }
        unordered_map<char, int> count;
        for (auto& c : A)
        {
            ++count[c];
        }
        for (auto& c : B)
        {
            --count[c];
            if(count[c] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
