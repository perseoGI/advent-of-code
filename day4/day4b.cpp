#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream f("day4.input");
    string line;
    char c;
    int num;
    vector<int> sec;

    do {
        f >> num >> c;
        sec.push_back(num);
    } while (c == ',');

    // board, row, col
    typedef tuple<int, int, int> Pos;
    multimap<int, Pos> boards;

    vector<array<int, 5>> rows;
    vector<array<int, 5>> cols;
    vector<set<int>> nonMarkedNumbers;
    set<int> finishedBoards;
    int boardIndex = 0;
    do {
        f.putback(c); // rev the ifstream pointer
        nonMarkedNumbers.push_back({});
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                f >> num;
                boards.insert({num, {boardIndex, i, j}});
                nonMarkedNumbers[boardIndex].insert(num);
            }
            rows.push_back({0, 0, 0, 0, 0});
            cols.push_back({0, 0, 0, 0, 0});
        }
        ++boardIndex;
    } while (f >> c);

    for (int i = 0; i < sec.size(); ++i) {
        int val = sec[i];
        int count = 0;
        auto eqr = boards.equal_range(val);
        for (auto it = eqr.first; it != eqr.second; ++it) {
            int board, row, col;
            tie(board, row, col) = it->second;
            nonMarkedNumbers[board].erase(val);
            if (++rows[board][row] == 5 || ++cols[board][col] == 5) {
                finishedBoards.insert(board);
                if(finishedBoards.size() == boardIndex){
                    int sum = accumulate(nonMarkedNumbers[board].begin(),
                            nonMarkedNumbers[board].end(), 0);
                    cout << (sum * val) << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}

