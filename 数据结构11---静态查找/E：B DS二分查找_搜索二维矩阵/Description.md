Description
使用二分查找法来判断m*n矩阵matrix中是否存在目标值target。
该矩阵有以下特性：
1. 每行中的整数从左到右升序排列；
2. 每行的第一个整数大于前一行的最后一个整数。
Input
第一行输入m和n，分别表示矩阵的行数和列数，接着输入m*n个整数。
接着，输入查找次数t，接着依次输入t个整数target。
Output
对于每次查找，若target存在于矩阵中，则输出true，否则输出false。
共输出t行。
Sample
#0
Input
3 4
-1 3 5 7
10 11 16 20
23 30 34 60

3
3
13
16
Output
true
false
true
Hint
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4