Description
二叉树两个结点的距离是一个结点经过双亲结点，祖先结点等中间结点到达另一个结点经过的分支数。二叉树结点的最大距离是所有结点间距离的最大值。例如，下图所示二叉树结点最大距离是3，C和D的距离。

  A
 /  \
B    D
 \
  C
二叉树用先序遍历顺序创建，#表示空树。计算二叉树结点最大距离和最大距离的两个结点。

如果有多个解，输出字典序最小的解（即第一个结点字母更小的，如果第一个字母相同，输出第二个结点字母更小的）。

Input
测试次数T

第2行之后的T行，每行为一棵二叉树先序遍历结果（#表示空树）

Output
对每棵二叉树，输出树的结点最大距离和最大距离的结点，输出格式见样例。

Sample
#0
Input
3
A##
ABC##EF#G###D##
ABEH###F#K###
Output
0:
5:D G
4:H K