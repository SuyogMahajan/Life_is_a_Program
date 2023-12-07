#include <iostream>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:

    Node* intersect(Node* root1, Node* root2) {

        if(root1->isLeaf && root1->val) {
            return root1;
        }

        if(root2->isLeaf && root2->val) {
            return root2;
        }
        if(root1->isLeaf && !root1->val) {
            return root2;
        }

        if(root2->isLeaf && !root2->val) {
            return root1;
        }

        Node* top_left = intersect(root1->topLeft,root2->topLeft);
        Node* top_right = intersect(root1->topRight,root2->topRight);
        Node* bottom_left = intersect(root1->bottomLeft,root2->bottomLeft);
        Node* bottom_right = intersect(root1->bottomRight,root2->bottomRight);

        if(top_left->val == top_right->val && top_right->val == bottom_left->val &&bottom_left->val == bottom_right->val && top_left->isLeaf &&
        top_right->isLeaf && bottom_left->isLeaf && bottom_right->isLeaf
       ) {
            return new Node(top_left->val,true);
        }

            return new Node(false,false,top_left,top_right,bottom_left,bottom_right);
    }
};