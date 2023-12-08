Description
学习KMP算法，给出主串和模式串，求模式串在主串的位置

算法框架如下，仅供参考

#include<iostream>
#include<string>
using namespace std;
class myString
{
private:
    string mainstr; // 串
    int size;       // 串长度
    void GetNext(string p, int next[]);
    int KMPFind(string p, int pos, int next[]);
public:
    myString();
    ~myString();
    void SetVal(string sp);
    int KMPFindSubstr(string p, int pos);
};
myString::myString()
{
    size = 0;
    mainstr = "";
}
myString::~myString()
{
    size = 0;
    mainstr = "";
}
void myString::SetVal(string sp)
{
    mainstr = "";
    mainstr.assign(sp);
    size = mainstr.length();
}
int myString::KMPFindSubstr(string p, int pos)
{
    int i;
    int L = p.length();
    int *next = new int[L];
    GetNext(p, next);
    for(i = 0; i < L; i ++)
        cout << next[i] << ' ';
    cout << endl;
    int v = -1;
    v = KMPFind(p, pos, next);
    delete []next;
    return v;
}
Input
第一个输入t，表示有t个实例

第二行输入第1个实例的主串，第三行输入第1个实例的模式串

以此类推

Output
第一行输出第1个实例的模式串的next值

第二行输出第1个实例的匹配位置，位置从1开始计算，如果匹配成功输出位置，匹配失败输出0

以此类推

Sample
#0
Input
3
qwertyuiop
tyu
aabbccdd
ccc
aaaabababac
abac
Output
-1 0 0 
5
-1 0 1 
0
-1 0 0 1 
8
Hint
为什么next值和课本的不一样？？？