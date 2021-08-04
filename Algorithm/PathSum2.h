#include "algorithmHeader.h"
#pragma once


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 class Solution {
 private:
     void backTracking(TreeNode* node, vector<vector<int>>& result, vector<int> path, int cur, int targetSum) {
         if (node == NULL)
             return;

         int val = node->val;
         if (cur + val == targetSum && node->left == NULL && node->right == NULL) {
             path.push_back(val);
             result.push_back(path);
             return;
         }

         path.push_back(val);

         backTracking(node->left, result, path, cur + val, targetSum);
         backTracking(node->right, result, path, cur + val, targetSum);
     }

 public:
     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<vector<int>> result;
         vector<int> path;

         backTracking(root, result, path, 0, targetSum);

         return result;
     }
 };
