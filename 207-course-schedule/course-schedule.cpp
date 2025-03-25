class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> edges(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            indegree[prerequisites[i][1]]++;
            edges[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        queue<int> temp;
        int count(0);
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                temp.push(i);
                count++;
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
                    count++;
                }
            }
        }
        return count == numCourses;
    }
};