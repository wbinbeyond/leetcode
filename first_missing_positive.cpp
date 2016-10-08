class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code her
        int n = A.size();
        int i = 0;
        while (i < n)
        {
            if (A[i] != i+1 && A[i] > 0 && A[i] < n && A[i] != A[A[i] - 1])
            {
                swap(A[i], A[A[i]-1]);
            }
            else
            {
                ++i;
            }
        }
        for (int j = 0; j < n; ++j)
        {
            if (A[j] != j+1)
            {
                return j+1;
            }
        }
        return n + 1;
    }
};
