Description
输入一组字符串，用2-路归并排序按字典顺序进行降序排序。

以自底向上方式进行，即每组2个归并、每组4个归并、每组8个归并…

Input
测试次数t

每组测试数据：数据个数n，后跟n个字符串，字符串不含空格。

Output
对每组测试数据，输出2-路归并排序的每一趟排序结果。每组测试数据的输出之间有1空行。

Sample
#0
Input
2
6 shenzhen beijing guangzhou futian nanshan baoan
10 apple pear peach grape cherry dew fig haw lemon marc
Output
shenzhen beijing guangzhou futian nanshan baoan
shenzhen guangzhou futian beijing nanshan baoan
shenzhen nanshan guangzhou futian beijing baoan

pear apple peach grape dew cherry haw fig marc lemon
pear peach grape apple haw fig dew cherry marc lemon
pear peach haw grape fig dew cherry apple marc lemon
pear peach marc lemon haw grape fig dew cherry apple