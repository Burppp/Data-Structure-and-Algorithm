Description
给定一颗二叉树的逻辑结构如下图，（先序遍历的结果，空树用字符‘#’表示，例如AB#C##D##），建立该二叉树的二叉链式存储结构，并输出该二叉树的先序遍历、中序遍历和后序遍历结果。

  A
 /  \
B    D
 \
  C
Input
第一行输入一个整数t，表示有t个二叉树

第二行起输入每个二叉树的先序遍历结果，空树用字符‘#’表示，连续输入t行。

Output
输出每个二叉树的先序遍历、中序遍历和后序遍历结果。

Sample
#0
Input
2
AB#C##D##
AB##C##
Output
ABCD
BCAD
CBDA
ABC
BAC
BCA