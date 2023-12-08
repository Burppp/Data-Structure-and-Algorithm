Description
套汇是指利用货币汇兑率的差异将一个单位的某种货币转换为大于一个单位的同种货币。例如，假定1 美元可以买0.7 英镑，1 英镑可以买9.5 法郎，1法郎可以买到0.16美元。通过货币兑换，一个商人可以从1 美元开始买入，得到0.7×9.5×0.16=1.064美元，从而获得6.4%的利润。 给定n种货币c1 ,c2 ,… ,cn的有关兑换率，试设计一个有效算法，确定货币间是否存在套汇的可能性。

提示：判断图上是否出现正环,即环上所有的边相乘大于1

Input
第一行：测试数据组数

每组测试数据格式为：

第一行：正整数n (1< =n< =30)，正整数m，分别表示n种货币和m种不同的货币兑换率。

2~n+1行，n种货币的名称。

n+2~n+m+1行，每行有3 个数据项ci，rij 和cj ，表示货币ci 和cj的兑换率为 rij。

Output
对每组测试数据，如果存在套汇的可能则输出YES

如果不存在套汇的可能，则输出NO。

Sample
#0
Input
2
3 3
USDollar
BritishPound
FrenchFranc
USDollar 0.5 BritishPound
BritishPound 10.0 FrenchFranc
FrenchFranc 0.21 USDollar
3 6
USDollar
BritishPound
FrenchFranc
USDollar 0.5 BritishPound
USDollar 4.9 FrenchFranc
BritishPound 10.0 FrenchFranc
BritishPound 1.99 USDollar
FrenchFranc 0.09 BritishPound
FrenchFranc 0.19 USDollar
Output
YES
NO