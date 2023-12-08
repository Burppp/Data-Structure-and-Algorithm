Description
给你一个字符串str，字符串中的字母都已按照升序排序，且只包含小写字母。另外给出一个目标字母target，请你寻找在这一有序字符串里比目标字母大的最小字母。
在比较时，字母是依序循环出现的。例如，str="ab"，target='z'，则答案为'a'。
字符串str至少包含了两个不同的字母。
target是一个小写字母。
要求必须使用二分查找来解题。
Input
第一行输入t，表示有t个测试样例。
第二行起，每一行首先输入一个字符串str，接着输入目标字母target。
以此类推共输入t个测试样例。
接收字符串可以使用：#include <string>，string str; cin>>str;
Output
每一行输出字符串中比目标字母大的最小字母。
以此类推共输出t行。
Sample
#0
Input
7
abcd a
abcd b
acegi r
abce c
aaaabbbbbccc b
aaaaabbbbbccccceeeee c
aaabbcccddd z
Output
b
c
a
e
c
e
a
Hint
2 <= str.length() <= 10000000