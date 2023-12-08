#include <iostream>
using namespace std;

class SeqList {
private:
    int* list;//定义一个列表的指针//
    int maxsize;//定义一个列表最长值//
    int size;//定义此时的列表长度//
public:
    SeqList() {
        maxsize = 1000;
        size = 0;
        list = new int[maxsize];//给这个列表争取到了1000长度的内存//
    }
    ~SeqList() {
        delete[]list;
    }
    void push_back(int i) {//定义一个函数，把数据依次导入到列表中//
        list[size] = i;
        size++;
    }
    void list_del(int i) {//定义一个函数，用来删掉某位置的数//
        if (i <= 0 || i > size || i > 1000) {//如果他输入的数都没有在这个范围内，那就报错误
            cout << "error" << endl;
            return;
        }
        else {
            for (int j = i - 1; j < size - 1; j++) {//从i-1位置开始，一次去变换为其下一个值
                list[j] = list[j + 1];

            }
            size--;//列表长度-1
            list_display();//展示的函数
        }
    }
    void list_insert(int i, int item) {
        if (i <= 0 || i > size + 1 || i > 1000) {
            cout << "error" << endl;
            return;
        }
        size++;
        for (int j = size;j >= i - 1;j--) {
            list[j] = list[j - 1];
        }
        list[i - 1] = item;
        list_display();
    }
    void list_get(int k) {
        if (k > 0 && k < size + 1) {
            cout << list[k - 1] << endl;
        }
        else
        {
            cout << "error" << endl;
            return;
        }

    }
    void list_display() {
        cout << size << " ";
        for (int i = 0;i < size;i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
};
int main() {//主函数开始//
    int n;//储存初始变量数//
    int a;//作为输入的值//
    int item;//作为位置输入//
    cin >> n;
    SeqList s;
    for (int i = 0;i < n;i++) {
        cin >> a;
        s.push_back(a);
    }
    s.list_display();
    cin >> a >> item;
    s.list_insert(a, item);
    cin >> a >> item;
    s.list_insert(a, item);
    cin >> a;
    s.list_del(a);
    cin >> a;
    s.list_del(a);
    cin >> a;
    s.list_get(a);
    cin >> a;
    s.list_get(a);
    return 0;
}
/**********************************************************************
	Problem: 1096
	User: 202200201118
	Language: C++
	Result: AC
	Time:8 ms
	Memory:2220 kb
**********************************************************************/
