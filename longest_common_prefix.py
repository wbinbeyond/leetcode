class Solution:
    # @param strs: A list of strings
    # @return: The longest common prefix
    def longestCommonPrefix(self, strs):
        # write your code here
        if (len(strs) == 0):
            return ""
        pf = ""
        minL = min(len(s) for s in strs)
        for i in range(minL):
            for j in range(len(strs)):
                if strs[j][i] != strs[0][i]:
                    return pf
            pf = pf + strs[0][i]
        return pf
