class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        for (auto pre : prerequisites)
        {
            graph[pre[1]].push_back(pre[0]);
        }

        vector<bool> visited(numCourses, false), seen(numCourses, false);

        for (int u = 0; u < numCourses; u++)
        {
            if (cycle_found(u, graph, visited, seen))
                return false;
        }
        return true;
    }

private:
    bool cycle_found(int u, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &seen)
    {
        if (seen[u])
            return true;
        if (visited[u])
            return false;

        visited[u] = seen[u] = true;
        for (auto v : graph[u])
        {
            if (cycle_found(v, graph, visited, seen))
                return true;
        }
        seen[u] = false;
        return false;
    }
};