class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row_check = true, col_check = true, box_check = true;
        
        for (int i = 0; i < 9; i++) {
            vector<int> row(9, 0);
            vector<int> col(9, 0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int rcurr = board[i][j] - '1';
                    row[rcurr]++;
                }

                if (board[j][i] != '.') {
                    int ccurr = board[j][i] - '1';
                    col[ccurr]++;
                }
            }
            sort(row.begin(), row.end(), greater<int>());
            sort(col.begin(), col.end(), greater<int>());

            if (row[0] > 1 || col[0] > 1) {
                return false;
            }
        }

        

        vector<vector<char>> bb;
        vector<int> cpp = {0, 3, 6};
        vector<int> rpp = {0, 3, 6};

        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                vector<char> tt;
                for (int i = 0 + rpp[a]; i < 3 + rpp[a]; i++) {
                    for (int j = 0 + cpp[b]; j < 3 + cpp[b]; j++) {
                        tt.push_back(board[i][j]);
                    }
                }
                bb.push_back(tt);
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << bb[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < 9; i++) {
            vector<int> box(9, 0);
            for (int j = 0; j < 9; j++) {
                if (bb[i][j] != '.') {
                    int bcurr = bb[i][j] - '1';
                    box[bcurr]++;
                }   
            }
            sort(box.begin(), box.end(), greater<int>());
            if (box[0] > 1) {
                return false;
            }  
        }

        return true;
    }
};