#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include<algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
    class Compare
    {
    public:
        bool operator()(string a, string b)
        {
            return a > b;
        }
    };

    unordered_map<string, priority_queue<string, vector<string>, Compare>> graph;
    vector<string> ans;

    void dfs(string s)
    {
           while (!graph[s].empty()) {
                
                string next = graph[s].top();
                graph[s].pop();
                dfs(next);

            }

            ans.push_back(s);
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
       
        for (int i = 0; i < tickets.size(); i++)
        {
            graph[tickets[i][0]].push(tickets[i][1]);
        }

        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<vector<string>> v = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};

    vector<string> k = sol->findItinerary(v);
    for (auto x : k)
        cout << x << " " << endl;
    return 0;
}
