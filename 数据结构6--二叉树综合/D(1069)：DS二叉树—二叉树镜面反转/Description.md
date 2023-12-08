D (1069) : DS二叉树—二叉树镜面反转
                Time Limit: 1 Sec     Memory Limit: 128 Mb     Submitted: 255     Solved: 96    
Description
假设二叉树用二叉链表存储，用先序序列结果创建。输入二叉树的先序序列，请你先创建二叉树，并对树做个镜面反转，再输出反转后的二叉树的先序遍历、中序遍历、后序遍历和层序遍历的序列。所谓镜面反转，是指将所有非叶结点的左右孩子对换。

–程序要求–

若使用C++只能include一个头文件iostream；若使用C语言只能include一个头文件stdio.h
程序中若include多过一个头文件，不看代码，作0分处理
不允许使用第三方对象或函数实现本题的要求
Input
t组测试数据

每组测试数据是一个二叉树的先序遍历序列，#表示空树

Output
对每棵二叉树，输出镜面反转后的先序、中序、后序和层次遍历序列。如果空树，输出四个NULL（后面不加空格）。如下：

NULL
NULL
NULL
NULL
Sample
#0
Input
3
41#32###65##7##
AB#C##D##
AB##C##
Output
4 6 7 5 1 3 2 
7 6 5 4 3 2 1 
7 5 6 2 3 1 4 
4 6 1 7 5 3 2 
A D B C 
D A C B 
D C B A 
A D B C 
A C B 
C A B 
C B A 
A C B 