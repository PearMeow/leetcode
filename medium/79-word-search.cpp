/**
 * @file 79-word-search.cpp
 * @author Perry Huang
 * @date 2024-10-13
 * 79. Word Search
 * Given an m x n grid of characters board and a string word,
 * return true if word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once.
 */

#include <vector>
#include <string>
// #include <iostream>
// #include <unordered_set>

bool helper(std::vector<std::vector<char>>& board, const std::string& word,
            int row, int col, int strInd, std::vector<std::vector<int>>& used) {
  if (strInd >= word.size()) return true; // done because
  if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return false; // out of bounds
  if (used[row][col] == 1) return false;  // if we already used it
  if (board[row][col] == word[strInd]) {
    used[row][col] = 1;
  } else {
    return false;
  }
  if (helper(board, word, row + 1, col, strInd + 1, used) ||
      helper(board, word, row - 1, col, strInd + 1, used) ||
      helper(board, word, row, col + 1, strInd + 1, used) ||
      helper(board, word, row, col - 1, strInd + 1, used)) {
    return true;
  }
  used[row][col] = 0;
  return false;
}

bool exist(std::vector<std::vector<char>>& board, const std::string& word) {
  // std::unordered_set<std::string> existing_strings;
  std::vector<std::vector<int>> used(board.size(), std::vector<int>(board[0].size(), 0));
  for (std::size_t i = 0; i < used.size(); ++i) {
    for (std::size_t j = 0; j < used[i].size(); ++j) {
      if (used[i][j] == word[0]) {
        if (helper(board, word, i, j, 1, used) == true) return true;
      }
    }
  }
  return false;
}