Description
小明这个学期必须选修n门课程，课程编号记为0到n-1。
在选修某些课程之前需要一些先修课程。先修课程按数组prerequisites给出，其中prerequisites[i] = [a, b]，表示如果要学习课程a则必须先学习课程b。
例如，先修课程对[0, 1]表示：要想学习课程0，则需要先完成课程1。
请判断小明能否完成所有课程的学习，如果可以则输出true，否则输出false。
Input
第一行输入t，表示有t个测试样例。
接着输入n，表示有n门课程，接着输入len，表示prerequisites数组的长度，接着输入prerequisites数组。
以此类推，共输入t个测试样例。
Output
每一行输出能否完成所有课程的学习，若可以则输出true，否则输出false。
共输出t行。
Sample
#0
Input
3

2
1
1 0

2
2
1 0
0 1

3
3
1 0
2 0
2 1
Output
true
false
true
Hint
1 <= n <= 10^5
len == prerequisites.length
1 <= len <= 5000
prerequisites[i].length == 2
0 <= a, b < n
prerequisites中的所有课程对互不相同。