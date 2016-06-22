class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (source == NULL || target == NULL)
            return -1;
        string haystack(source);
        string needle(target);
        int i, j, lenh = haystack.length(), lenn = needle.length();
        if (lenn == 0)  return 0;
        for (i = 0; i <= lenh - lenn; i++) {
            for (j = 0; j < lenn; j++) 
                if (haystack[i + j] != needle[j]) break;

            if (j == lenn)  return i;
        }
        return -1;
    }
};
