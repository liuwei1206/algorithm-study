DAG is Directed acyclic graph. To judge a directed graph is a DAG or not, we can use Topological sorting of graphs.

DAG是有向无环图。判断有向图是不是DAG，一般都是使用拓扑排序。

这种有前后依赖关系，例如任务i要在任务j完成的基础上才能开始，或者要修某个课程必须先修另外一个课程才行，这种依赖关系的
问题，一般都是有向无环图。求解这样的问题就需要用拓扑排序。

main1.cpp: use matrix to represent a graph, time complexity is O(n*n)
main1.cpp是用矩阵表示图，时间复杂度是O(n*n)

main2.cpp: use Adiacent List model to represent a graph, time complexity is O(n + m), where n is the number of node,
m is the number of edge.
main2.cpp是用邻接表法表示图，时间复杂度是O(n+m),n是节点数，m是边的数量。

一般的拓扑排序都是每次找到一个入度为0的节点，然后删除，更新剩余节点的入度，然后再找一个入度为0的点，这样依次循环下去，
直到所有点都删掉或者找不到入度为0的点，来判断一个有向图是否有环。

而main2.cpp中，它维护了一个节点入度矩阵，和一个入度为0的节点队列。每次取节点都直接从队列中取，然后不停更新节点入度，
判断入度是否为0，如果是，则加入到队列。