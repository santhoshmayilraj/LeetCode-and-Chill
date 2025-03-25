class Solution {
    // topological BFS
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> edges(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            indegree[prerequisites[i][0]]++;
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> temp;
        vector<int> ans;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                temp.push(i);
                ans.push_back(i);
            }
        }

        while(!temp.empty())
        {
            int curr = temp.front();
            temp.pop();
            for(int i:edges[curr])
            {
                indegree[i]--;
                if(indegree[i] == 0)
                {
                    temp.push(i);
                    ans.push_back(i);
                }
            }
        }
        if(ans.size() == numCourses)
        {
            return ans;
        }       
        else
        {
            vector<int> temp;
            return temp;
        }
    }
};