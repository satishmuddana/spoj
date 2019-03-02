#include <iostream>
#include<vector>
#include <limits>
using namespace std;

void FindMinDistance(vector< vector<char>>& bitMap, int row, int col) {
    vector< vector<int>> dp(row, vector<int>(col));
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (bitMap[i][j] == '1')
                dp[i][j] = 0;
            else
                dp[i][j] = INT_MAX;
        }
    }

    /* bottom-left
     * First Iterate in a bottom-left and update
     * For i,j: update [i+1][j], [i][j+1], [i+1][j+1]
     */

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i+1 < row && dp[i][j] != INT_MAX)
                dp[i+1][j] = min (dp[i][j]+1, dp[i+1][j]);
            if (j+1 < col && dp[i][j] != INT_MAX)
                dp[i][j+1] = min (dp[i][j]+1, dp[i][j+1]);
            if (i+1 < row && j+1 < col) {
                if (dp[i+1][j] != INT_MAX && dp[i][j+1] != INT_MAX) {
                    dp[i+1][j+1] = min (dp[i+1][j+1], min(dp[i][j+1], dp[i+1][j])+1);
                }
                else if (dp[i+1][j] != INT_MAX) {
                    dp[i+1][j+1] = min (dp[i+1][j]+1, dp[i+1][j+1]);
                }
                else if (dp[i][j+1] != INT_MAX) {
                    dp[i+1][j+1] = min (dp[i][j+1]+1, dp[i+1][j+1]);
                }
            }
        }
    }

    /* top -right
     * Now update in a top right fashion
     * Update the cell only if it is minimum
     * For i,j: update [i-1][j], [i][j-1], [i-1][j-1]
     */
    for (int i = row-1; i >= 0; i--) {
        for (int j = col-1; j >= 0; j--) {
            if (i-1 >= 0)
                dp[i-1][j] = min (dp[i][j]+1, dp[i-1][j]);
            if (j-1 >= 0)
                dp[i][j-1] = min (dp[i][j]+1, dp[i][j-1]);
            if (i-1 >= 0 && j-1 >= 0)
                dp[i-1][j-1] = min ((dp[i-1][j], dp[i][j-1])+1, dp[i-1][j-1]);
        }
    }

    /* Print the Output */
    for (int i = 0; i < row; i++) {
        for (int j =0; j < col; j++) {
            cout << dp[i][j];
            if (j == col-1)
                cout << endl;
            else
                cout << " ";
        }
    }
}

int main() {
    int testCases = 0, row = 0, col = 0;
    cin  >> testCases;
    while (testCases--) {
        cin >> row >> col;
        vector< vector<char>> bitMap(row, vector<char>(col));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> bitMap[i][j];
            }
        }
        FindMinDistance(bitMap, row, col);
    }
    return 0;
}