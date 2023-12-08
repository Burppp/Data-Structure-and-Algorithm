Description
给定一个字符串，求需要添加至少几个字符到字符串末尾才能使得整个字符串由某一个不为本身的子串循环构成？ 如“abca”，添加“bc”后构成“abcabc”，其由子串“abc”循环构成;也可以添加“abca”后构成“abcaabca”，其由子串“abca”循环构成，相比之下“bc”只有2个字符，添加的字符量最少。

Input
第一行包括一个整数T(1 <= T <= 100)，代表测试组数

每组测试数据包括一行字符串，其长度范围为 [3, 10^4]

Output
对于每组测试数据

输出一个整数N，代表添加的最小字符数量

Sample
#0
Input
4
aaa
abca
abcdefg
abcabcabca
Output
0
2
7
2