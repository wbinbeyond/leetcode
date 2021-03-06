class Solution {
public:
    int calculate(string s) {
        int res = 0,
            sign = 1,
            n = s.size();
        stack<int> theS;
        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            if (c >= '0' && c <= '9')
            {
                int num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                res += num * sign;
                i--;
            }
            else if (c == '+') 
            {
                sign = 1;
            }
            else if (c == '-')
            {
                sign = -1;
            }
            else if (c == '(')
            {
                theS.push(res);
                theS.push(sign);
                res = 0;  // need to reset res and sign to process expression inside ()
                sign = 1;
            }
            else if (c == ')')
            {
                res *= theS.top();
                theS.pop();
                res += theS.top();
                theS.pop();
            }
        }
        return res;
    }
};
