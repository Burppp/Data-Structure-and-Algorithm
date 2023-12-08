Description
给定一个串，如ABCDAB，则 - ABCDAB的真前缀有：{ A, AB,ABC, ABCD, ABCDA } - ABCDAB的真后缀有：{ B, AB,DAB, CDAB, BCDAB }

因此，该串的真前缀和真后缀中最长的相等串为AB，我们称之为该串的“最长的真前后缀”。 试实现一个函数string matched_Prefix_Postfix(string str)，得到输入串str的最长的真前后缀。若不存在最长的真前后缀则输出empty

Input
第1行：串的个数 n 第2行到第n+1行：n个字符串

Output
n个最长的真前后缀，若不存在最长的真前后缀则输出empty。

Sample
#0
Input
6
a
ab
abc
abcd
abcda
abcdab
Output
empty
empty
empty
empty
a
ab