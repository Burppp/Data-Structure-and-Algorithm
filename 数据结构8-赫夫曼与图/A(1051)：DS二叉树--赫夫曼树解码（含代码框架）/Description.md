Description
已知赫夫曼编码算法和程序，在此基础上进行赫夫曼解码

在赫夫曼树的类定义中增加了一个公有方法：

int Decode(const string codestr, char txtstr[]); //输入编码串codestr，输出解码串txtstr

该方法如果解码成功则返回1，解码失败则返回-1，本程序增加宏定义ok表示1，error表示-1

解码方法的代码框架如下：

// 赫夫曼解码
int HuffMan::Decode(const string codestr, char txtstr[])
{
    // 编码串是codestr，解码结果放在 txtstr 中
    // 编码 0 表示往左孩子移动，编码 1 表示往右孩子移动
    int i, k, c;
    char ch;
    c = len; // c表示结点数组下标
    // 根结点是结点数组的最后一个结点，所以 c 一开始指向根节点
    k = 0;  // txtstr的指针
    for(i = 0; i < codestr.length(); i ++)
    {
        // 解码流程如下：
        // 取编码串的第 i 个字符放入变量ch
        // 如果 ch 是字符 0 ，表示往左孩子移动，则 c 跳转到左孩子
        // 如果 ch 是字符 1 ，表示往右孩子移动，则 c 跳转到右孩子
        // 如果 ch 非 0 非 1 ，表示编码串有错误，返回 error 表示解码失败
        // 如果 c 指向的结点是叶子
            // 解码串 txtstr 的第 k 位置保存结点 c 内的字符
            // k ++
            // c 跳回根节点
        // 否则
            // ch = '\0';   // 设置 ch 值是用于检查不完整编码的报错
    }
    if(ch == '\0') return error;
    else txtstr[k] = '\0';  // 解码成功，加入字符串结束符
    return ok;
}
Input
第一行输入t，表示有t个测试实例

第二行先输入n，表示第1个实例有n个权值，接着输入n个权值，权值全是小于1万的正整数

第三行输入n个字母，表示与权值对应的字符

第四行输入k，表示要输入k个编码串

第五行起输入k个编码串

以此类推输入下一个示例

Output
每行输出解码后的字符串，如果解码失败直接输出字符串“error”，不要输出部分解码结果

Sample
#0
Input
2
5 15 4 4 3 2
A B C D E
3
11111
10100001001
00000101100
4 7 5 2 4
A B C D
3
1010000
111011
111110111
Output
AAAAA
ABEAD
error
BBAAA
error
DCD