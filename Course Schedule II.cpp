class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (const auto& p : prerequisites)
        {
            graph[p.second].push_back(p.first);
        }
        
        vector<int> visit(numCourses, 0);
        vector<int> res;
        for (int i = 0; i < numCourses; ++i)
        {
            if (isCycle(i, visit, graph, res)) return {};
        }
        std::reverse(res.begin(), res.end());
        
        return res;
    }
    
    bool isCycle(int root, vector<int>& visit, const vector<vector<int>>& graph, vector<int>& res)
    {
        if (visit[root] == 2) return false;  //visited
        if (visit[root] == 1) return true;   //visiting
        visit[root] = 1;
        for (const auto& n : graph[root])
        {
            if (isCycle(n, visit, graph, res)) return true;
        }
        visit[root] = 2;
        res.push_back(root);
        return false;
    }
};
