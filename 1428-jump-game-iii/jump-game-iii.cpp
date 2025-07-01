class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        bool flag = false;
        vector<bool> visited(arr.size(),false);
        helper(arr,start,flag,visited);
        return flag;
    }

    void helper(vector<int> &arr,int curr,bool &flag,vector<bool> &visited)
    {
        visited[curr] = true;
        if(flag)
        {
            return;
        }
        if(arr[curr] == 0)
        {
            flag = true;
            return;
        }
        if(curr-arr[curr] >= 0 and !visited[curr-arr[curr]])
        {
            helper(arr,curr-arr[curr],flag,visited);
        }
        if(curr+arr[curr] < arr.size() and !visited[curr+arr[curr]])
        {
            helper(arr,curr+arr[curr],flag,visited);
        }
        return;
    }
};