Description
给出一个图的邻接矩阵，对图进行深度优先搜索，从顶点0开始

注意：图n个顶点编号从0到n-1

如果图不连通，则对尚未访问的编号结点继续进行深度优先搜索，直到所有结点被访问

Input
第一行输入t，表示有t个测试实例

第二行输入n，表示第1个图有n个结点

第三行起，每行输入邻接矩阵的一行，以此类推输入n行

第i个结点与其他结点如果相连则为1，无连接则为0，数据之间用空格隔开

以此类推输入下一个示例

Output
每行输出一个图的深度优先搜索结果，结点编号之间用空格隔开

Sample
#0
Input
2
4
0 0 1 1
0 0 1 1
1 1 0 1
1 1 1 0
5
0 0 0 1 1
0 0 1 0 0
0 1 0 1 1
1 0 1 0 0
1 0 1 0 0
Output
0 2 1 3 
0 3 2 1 4