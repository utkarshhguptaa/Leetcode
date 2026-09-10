class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lossCount;
        set<int> players;

        for (auto &match : matches) {
            int winner = match[0];
            int loser = match[1];

            players.insert(winner);
            players.insert(loser);

            lossCount[loser]++;
        }

        vector<int> zeroLoss;
        vector<int> oneLoss;

        for (int player : players) {
            if (lossCount[player] == 0)
                zeroLoss.push_back(player);
            else if (lossCount[player] == 1)
                oneLoss.push_back(player);
        }

        return {zeroLoss, oneLoss};
    }
};
