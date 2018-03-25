kruskal algorithm is used to get the Minimum tree of the undirected graph.(kruskal算法用于求无向图的最小生成树)

具体思想是:
1.对图中所有边进行排序，由小到大排序。

2.依次从小到大取边，取出的边要属于不同的并查集，然后将边的节点合并到同一并查集。

3.直到取出的边的数量为节点数-1


关于并查集，请参考：
http://www.cnblogs.com/cherish_yimi/archive/2009/10/11/1580839.html