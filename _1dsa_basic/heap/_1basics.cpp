#include <iostream>
using namespace std;

// heap data structure is always a complete binary tree
// complete BT means all the levels should be filled from left to right, no gaps
// not necessary all leaves to be present, but should be contiguous from left to right
// heap is stored as an array
// so complete tree allows storing the nodes without any gap
// nodes present in array in level order traversal
// height becomes log(h) instead of h

// left child of node(i)= 2i+1
// right child of node(i)=2i+2
// parent of node(i)=[i-1]/2 (integer division)

// min heap -> complete BT and the given node is smaller than all of its desendent