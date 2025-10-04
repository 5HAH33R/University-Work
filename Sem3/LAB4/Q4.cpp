#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool search(long i, long j, int x, vector<vector<char>> &board, int rows, int cols, string word)
{
    if (x == word.size())
        return true;
    if (i == rows || j == cols || i < 0 || j < 0 || board[i][j] != word[x])
        return false;
    board[i][j] = '#';
    bool down = search(i + 1, j, x + 1, board, rows, cols, word);
    bool up = search(i - 1, j, x + 1, board, rows, cols, word);
    bool right = search(i, j + 1, x + 1, board, rows, cols, word);
    bool left = search(i, j - 1, x + 1, board, rows, cols, word);
    board[i][j] = word[x];

    if (up || down || left || right)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool exist(vector<vector<char>> &board, string word)
{
    int rows = board.size();
    int cols = board[0].size();
    for (long i = 0; i < rows; i++)
    {
        for (long j = 0; j < cols; j++)
        {
            if (board[i][j] == word[0])
            {
                if (search(i, j, 0, board, rows, cols, word))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "SEE";

    bool result = exist(board, word);

    if (result)
    {
        cout << "Word " << word << " exists" << endl;
    }
    else
    {
        cout << "Word " << word << " does not exist" << endl;
    }

    return 0;
}
