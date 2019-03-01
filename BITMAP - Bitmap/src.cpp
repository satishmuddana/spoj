#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


void UpdateBottomLeftPositions(int i, int j, int row, int col, vector<vector<int>>& dp) {
	if (j+1 < col) {
		if (dp[i][j+1] == -1) {
			dp[i][j+1] = dp[i][j] +1;
			UpdateBottomLeftPositions(i, j+1, row, col, dp);
		}
		else {
			if (dp[i][j+1] > dp[i][j]) {
				dp[i][j+1] = dp[i][j] +1;
				UpdateBottomLeftPositions(i, j+1, row, col, dp);
			}
		}
	}
	if (i+1 < row) {
		if (dp[i+1][j] == -1) {
			dp[i+1][j] = dp[i][j] +1;
			UpdateBottomLeftPositions(i+1, j, row, col, dp);
		}
		else {
			if (dp[i+1][j] > dp[i+1][j]) {
				dp[i+1][j] = dp[i][j] +1;
				UpdateBottomLeftPositions(i+1, j, row, col, dp);
			}
		}
	}
	return;
}

void UpdateTopRightPositions(int i, int j, int row, int col, vector<vector<int>>& dp) {
	if (j-1 >= 0) {
		if (dp[i][j-1] == -1) {
			dp[i][j-1] = dp[i][j] +1;
			UpdateTopRightPositions(i, j-1, row, col, dp);
		}
		else {
			if (dp[i][j-1] > dp[i][j]) {
				dp[i][j-1] = dp[i][j] +1;
				UpdateTopRightPositions(i, j-1, row, col, dp);
			}
		}
	}
	
	if (i-1 >= 0) {
		if (dp[i-1][j] == -1) {
			dp[i-1][j] = dp[i][j] +1;
			UpdateTopRightPositions(i-1, j, row, col, dp);
		}
		else {
			if (dp[i-1][j] > dp[i][j]) {
				dp[i-1][j] = dp[i][j] +1;
				UpdateTopRightPositions(i-1, j, row, col, dp);
			}
		}
	}
}

void NearestPixel(int row, int col, vector<vector<char>>& bitMap) {
	vector< vector<int > > dp(row, vector<int>(col));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (bitMap[i][j] == '1')
				dp[i][j] = 0;
			else
				dp[i][j] = -1;
		}
	}
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (dp[i][j] == 0) {
				UpdateBottomLeftPositions(i, j, row, col, dp);
			}
		}
	}
	
	for (int i = row-1; i >= 0; i--) {
		for (int j = col-1; j >= 0; j--) {
			if (dp[i][j] == 0) {
				UpdateTopRightPositions(i, j, row, col, dp);
			}
		}
	}
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
				cout << dp[i][j];
				if (j == col - 1)
					cout << endl;
				else
					cout << " ";
		}
	}
}

int main() {
	int testCases = 0, row = 0, col = 0;
	cin >> testCases;
	while (testCases--) {
		cin >> row >> col;
		vector<vector<char>> bitMap(row, vector<char>(col));
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> bitMap[i][j];
			}
		}
		NearestPixel(row, col, bitMap);
	}
	return 0;
}