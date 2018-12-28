class Solution {
public:
    int calculate(string s) {
        int res = 0,
            num = 0,
            n = s.size();
        char op = '+';
        stack<int> theS;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] >= '0')
            {
                num = num * 10 + s[i] - '0';
            }
            if ((s[i] < '0' && s[i] != ' ') || i == n - 1)
            {
                if (op == '+') theS.push(num);
                if (op == '-') theS.push(-num);
                if (op == '*' || op == '/')
                {
                    int tmp = (op == '*') ? theS.top() * num : theS.top() / num;
                    theS.pop();
                    theS.push(tmp);
                }
                op = s[i];
                num = 0;
            }
        }
        while (!theS.empty())
        {
            res += theS.top();
            theS.pop();
        }
        return res;
    }
};
