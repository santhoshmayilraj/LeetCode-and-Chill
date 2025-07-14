class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int l(0),r(0);
        while(l<players.size() and r<trainers.size())
        {
            if(players[l] <= trainers[r])
            {
                l++;
                r++;
            }
            else
            {
                r++;
            }
        }
        return l;        
    }
};