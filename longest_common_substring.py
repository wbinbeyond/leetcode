class Solution:
    # @param A, B: Two string.
    # @return: the length of the longest common substring.
    def longestCommonSubstring(self, A, B):
        # write your code here
        max = 0;
        la, lb = len(A), len(B)
        dp = [[0 for j in range(lb)] for i in range(la)]
        for i in range(la) :
            for j in range(lb) :
                if A[i] == B[j] :
                    if i == 0 or j == 0 :
                        dp[i][j] = 1
                    else :
                        dp[i][j] = dp[i-1][j-1] + 1
                    if max < dp[i][j] :
                        max = dp[i][j]
        return max
