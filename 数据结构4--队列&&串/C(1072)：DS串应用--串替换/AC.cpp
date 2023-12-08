#include<iostream>
#include<string>
using namespace std;
class myString
{
private:
    string mainstr; // 串
    int size;       // 串长度
    void GetNext(string p, int next[]);
    int KMPFind(string p, int next[]);
public:
    myString();
    ~myString();
    void SetVal(string sp);
    int KMPFindSubstr(string p);
    void strReplace(string p, int idx, int size);
};
void myString::strReplace(string p, int idx, int size)
{
    if (idx == -1)
    {
        cout << this->mainstr << endl;
        return;
    }
    int i = 0, count = 0;
    this->mainstr.replace(this->mainstr.begin() + idx - 1, 
                    this->mainstr.begin() + idx - 1 + size, 
                    p.c_str());

    cout << this->mainstr << endl;
}
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
    size = (int)mainstr.length();
    cout << this->mainstr << endl;
}
int myString::KMPFindSubstr(string p)
{
    int i;
    int L = (int)p.length();
    int* next = new int[L];
    GetNext(p, next);
    /*for (i = 0; i < L; i++)
        cout << next[i] << ' ';
    cout << endl;*/
    int v = -1;
    v = KMPFind(p, next);
    /*cout << v << endl;*/
    delete[]next;
    return v;
}
void myString::GetNext(string p, int next[])
{
    next[0] = -1;
    next[1] = 0;
    int i = 1, j = 0;
    int idx = 2;
    while (i < p.size())
    {
        if (p[i] == p[j])
        {
            j++;
            i++;
            if (idx < p.size())
                next[idx++] = j;
        }
        else
        {
            if (j == 0)
            {
                if (idx < p.size())
                    next[idx++] = 0;
                i++;
            }
            else
                j = next[j];
        }
    }
}
int myString::KMPFind(string p, int next[])
{
    int i, j;
    for (i = 0, j = 0;i < this->mainstr.size();)
    {
        if (this->mainstr[i] == p[j])
            i++, j++;
        else if (j > 0)
            j = next[j];
        else
            i++;
        if (j >= p.size())
            return i - j + 1;
    }
    return -1;
}
int main()
{
    int t, idx = 0, i;
    myString str;
    string txt, replace, Str;
    cin >> t;
    while (t--)
    {
        cin >> Str >> txt >> replace;
        str.SetVal(Str);
        idx = str.KMPFindSubstr(txt);
        str.strReplace(replace, idx, txt.size());
    }
    return 0;
}
/**********************************************************************
	Problem: 1072
	User: 202200201118
	Language: C++
	Result: AC
	Time:8 ms
	Memory:2224 kb
**********************************************************************/
