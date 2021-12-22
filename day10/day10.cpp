#include <bits/stdc++.h>
using namespace std;

class Solver {
  private:
    map<char, int> pointsMap{{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
    map<char, int> pointsMapSecond{{'(', 1}, {'[', 2}, {'{', 3}, {'<', 4}};
    map<char, char> charMap{{')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}};
    vector<string> input;
    vector<stack<char>> firstPartResult;

  public:
    Solver(ifstream &f) { parse(f); };

    void parse(ifstream &f) {
        string line;
        while (getline(f, line)) {
            input.push_back(line);
        }
    }

    int getResultFirstPart() {
        vector<char> illegalChars;
        for (const auto &line : input) {
            stack<char> symbols;
            bool error = false;
            for (const char &c : line) {
                // Close char
                if (charMap.count(c) == 1) {
                    if (symbols.empty() || symbols.top() != charMap[c]) {
                        illegalChars.push_back(c);
                        error = true;
                    } else
                        symbols.pop();
                } else
                    symbols.push(c);
                if (error)
                    break;
            }
            // For second part
            if (!error && !symbols.empty())
                firstPartResult.push_back(symbols);
        }

        return accumulate(
            illegalChars.cbegin(), illegalChars.cend(), 0,
            [this](int acc, char c) { return acc + pointsMap[c]; });
    }

    long long getResultSecondPart() {
        constexpr int MULT_CONSTANT = 5;
        vector<long long> pointsVec;
        for (auto &st : firstPartResult) {
            long long points{};
            while (!st.empty()) {
                points = points * MULT_CONSTANT + pointsMapSecond[st.top()];
                st.pop();
            }
            pointsVec.push_back(points);
        }
        sort(pointsVec.begin(), pointsVec.end());
        return pointsVec[pointsVec.size() / 2];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream fileTest("day10.test");
    ifstream fileInput("day10.input");

    auto testSolver = Solver(fileTest);
    auto inputSolver = Solver(fileInput);

    assert(testSolver.getResultFirstPart() == 26397);
    cout << inputSolver.getResultFirstPart() << '\n';

    assert(testSolver.getResultSecondPart() == 288957);
    cout << inputSolver.getResultSecondPart() << '\n';

    return 0;
}
