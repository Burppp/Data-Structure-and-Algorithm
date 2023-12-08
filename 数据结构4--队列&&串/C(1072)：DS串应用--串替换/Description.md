Description
给出主串、模式串、替换串，用KMP算法找出模式串在主串的位置，然后用替换串的字符替换掉模式串

本题只考虑一处替换的情况，如果你想做的完美一些，能够实现多处替换那可能需要考虑模式串和替换串长度不一致的情况

Input
第一个输入t，表示有t个实例

第二行输入第1个实例的主串，第三行输入第1个实例的模式串，第四行输入第1个实例的替换串

以此类推

Output
第一行输出第1个实例的主串

第二行输出第1个实例的主串替换后结果，如果没有发生替换就输出主串原来的内容。

以此类推

Sample
#0
Input
4
aabbccdd
bb
ff
aaabbbccc
ddd
eee
abcdef
abc
ccccc
abcdef
abc
c
Output
aabbccdd
aaffccdd
aaabbbccc
aaabbbccc
abcdef
cccccdef
abcdef
cdef