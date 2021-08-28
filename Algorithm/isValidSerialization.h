#include "algorithmHeader.h"
#pragma once

class Solution {

    class Tree {
    public:
        Tree* left;
        Tree* right;
        int value;

        Tree() {
            left = NULL;
            right = NULL;
        }
    };

public:
    string makeTree(Tree* node, string order, bool left) {
        if (order == "")
            return "";

        Tree* child = new Tree();
        if (left) {
            node->left = child;
        }
        else {
            node->right = child;
        }

        if (order[0] == '#') {
            child->value = -1;
            return order.substr(2);
        }

        child->value = order[0] - 48;
        string right = makeTree(child, order.substr(2), true);
        return makeTree(child, right, false).substr(2);
    }

    bool isValidSerialization(string preorder) {
        if (preorder[0] == '#')
            return false;

        Tree root;
        root.value = preorder[0];
        makeTree(&root, preorder.substr(2), true);
    }
};
