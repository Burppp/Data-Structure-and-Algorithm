Description
根据输入创建无向网。分别用Prim算法和Kruskal算法构建最小生成树。（假设：输入数据的最小生成树唯一。）

Input
顶点数n

n个顶点

边数m

m条边信息,格式为：顶点1 顶点2 权值

Prim算法的起点v

Output
输出最小生成树的权值之和

对两种算法，按树的生长顺序，输出边信息(Kruskal中边顶点按数组序号升序输出)

Sample
#0
Input
6
v1 v2 v3 v4 v5 v6 
10
v1 v2 6
v1 v3 1
v1 v4 5
v2 v3 5
v2 v5 3
v3 v4 5
v3 v5 6
v3 v6 4
v4 v6 2
v5 v6 6
v1
Output
15
prim:
v1 v3 1
v3 v6 4
v6 v4 2
v3 v2 5
v2 v5 3
kruskal:
v1 v3 1
v4 v6 2
v2 v5 3
v3 v6 4
v2 v3 5