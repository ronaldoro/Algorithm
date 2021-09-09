#pragma once
int search(vector<string>& board) {
    int cnt = 0;
    queue<pair<int, int>> que;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {

            if (i + 1 < board.size() && j + 1 < board[0].size()) {
                if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i + 1][j + 1]) {
                    que.push(make_pair(i, j));
                }
            }
        }
    }

    while (que.empty() == false) {
        int y = que.front().first;
        int x = que.front().second;

        if (board[y][x] != ' ') {
            board[y][x] = ' ';
            ++cnt;
        }

        if (board[y + 1][x] != ' ') {
            board[y + 1][x] = ' ';
            ++cnt;
        }

        if (board[y][x + 1] != ' ') {
            board[y][x + 1] = ' ';
            ++cnt;
        }

        if (board[y + 1][x + 1] != ' ') {
            board[y + 1][x + 1] = ' ';
            ++cnt;
        }

        que.pop();
    }

    return cnt;
}

void sort(vector<string>& board) {
    for (int i = board.size() - 1; i >= 0; --i) {
        for (int j = board[0].size() - 1; j >= 0; --j) {
            if (board[i][j] == ' ') {
                int temp = i - 1;
                while (temp >= 0) {
                    if (board[temp][j] != ' ') {
                        board[i][j] = board[temp][j];
                        board[temp][j] = ' ';
                        break;
                    }
                    --temp;
                }
            }
        }
    }
}
