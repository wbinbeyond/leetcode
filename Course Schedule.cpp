class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (const auto& p : prerequisites)
        {
            graph[p.second].push_back(p.first);
        }
        
        vector<int> visit(numCourses, 0);
        for (int i = 0; i < numCourses; ++i)
        {
            if (isCycle(i, visit, graph)) return false;
        }
        
        return true;
    }
    
    bool isCycle(int root, vector<int>& visit, const vector<vector<int>>& graph)
    {
        if (visit[root] == 2) return false;  //visited
        if (visit[root] == 1) return true;   //visiting
        visit[root] = 1;
        for (const auto& n : graph[root])
        {
            if (isCycle(n, visit, graph)) return true;
        }
        visit[root] = 2;
        return false;
    }
};



// below is wrong, need to see why
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (const auto& p : prerequisites)
        {
            graph[p.first].push_back(p.second);
        }
        
        vector<int> visit(numCourses, 0);
        for (int i = 0; i < numCourses; ++i)
        {
            if (isCycle(i, visit, graph)) return false;
        }
        
        return true;
    }
    
    bool isCycle(int root, vector<int>& visit, const vector<vector<int>>& graph)
    {
        if (visit[root] == 1) return true;   //visited
        visit[root] = 1;
        for (const auto& n : graph[root])
        {
            if (visit[root] == 1)
            {
                return true;
            }
            else
            {
                if (isCycle(n, visit, graph)) return true;
            }
        }
        visit[root] = 0;
        return false;
    }
};
