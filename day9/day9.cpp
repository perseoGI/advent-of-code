#include <bits/stdc++.h>
using namespace std;

class Solver {
  private:
    vector<vector<int>> mat;
    vector<pair<int, int>> minPos;
    vector<vector<bool>> visited;

    int ROWS;
    int COLS;

  public:
    Solver(ifstream &f) {
        parse(f);
        ROWS = mat.size();
        COLS = mat[0].size();
        calcMinPositions();
    };

    void parse(ifstream &f) {
        string line;
        while (getline(f, line)) {
            vector<int> v;
            for (const char &num : line)
                v.push_back(num - '0');
            mat.push_back(v);
        }
    }

    void calcMinPositions() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                int current = mat[i][j];
                if ((j > 0 && mat[i][j - 1] > current || j <= 0) &&
                    (j < COLS - 1 && mat[i][j + 1] > current ||
                     j >= COLS - 1) &&
                    (i > 0 && mat[i - 1][j] > current || i <= 0) &&
                    (i < ROWS - 1 && mat[i + 1][j] > current ||
                     i >= ROWS - 1)) {
                    minPos.push_back({i, j});
                }
            }
        }
    }

    int getResultFirstPart() {
        constexpr int RISK_LEVEL_CONSTANT = 1;
        return accumulate(
            minPos.cbegin(), minPos.cend(), 0,
            [RISK_LEVEL_CONSTANT, this](int acc, const pair<int, int> p) {
                return acc + mat[p.first][p.second] + RISK_LEVEL_CONSTANT;
            });
    }

    int search(int x, int y) {
        if (x < 0 || x >= ROWS || y < 0 || y >= COLS || mat[x][y] == 9 ||
            visited[x][y])
            return 0;
        visited[x][y] = true;
        return 1 + search(x + 1, y) + search(x - 1, y) + search(x, y + 1) +
               search(x, y - 1);
    }

    int getResultSecondPart() {
        int res = 1;
        priority_queue<int> maxCounters;
        for (const auto &[x, y] : minPos) {
            visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));
            int counter = search(x, y);
            maxCounters.push(counter);
        }
        for (int i = 0; i < 3; ++i)
            res *= maxCounters.top();
        maxCounters.pop();
        return res;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream fileTest("day9.test");
    ifstream fileInput("day9.input");

    auto testSolver = Solver(fileTest);
    auto inputSolver = Solver(fileInput);

    assert(testSolver.getResultFirstPart() == 15);
    cout << inputSolver.getResultFirstPart() << '\n';

    assert(testSolver.getResultSecondPart() == 1134);
    cout << inputSolver.getResultSecondPart() << '\n';

    return 0;
}
