class Solution {
public:
    set<string> s;

    void dfs(string exp) {
        int j = exp.find('}');

        if (j == string::npos) {
            s.insert(exp);
            return;
        }

        int i = exp.rfind('{', j);

        string left = exp.substr(0, i);
        string right = exp.substr(j + 1);

        string inside = exp.substr(i + 1, j - i - 1);

        stringstream ss(inside);
        string part;

        while (getline(ss, part, ',')) {
            dfs(left + part + right);
        }
    }

    vector<string> braceExpansionII(string expression) {
        dfs(expression);

        return vector<string>(s.begin(), s.end());
    }
};