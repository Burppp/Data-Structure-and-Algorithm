Description
层次遍历二叉树，是从根结点开始遍历，按层次次序“自上而下，从左至右”访问树中的各结点。

建树方法采用“先序遍历+空树用0表示”的方法

采用队列实现

Input
第一行输入一个整数t，表示有t个测试数据

第二行起输入二叉树先序遍历的结果，空树用字符‘0’表示，输入t行

Output
逐行输出每个二叉树的层次遍历结果

Sample
#0
Input
2
AB0C00D00
ABCD00E000FG00H0I00
Output
ABDC
ABFCGHDEI