DAG is Directed acyclic graph. To judge a directed graph is a DAG or not, we can use Topological sorting of graphs.

DAG�������޻�ͼ���ж�����ͼ�ǲ���DAG��һ�㶼��ʹ����������

������ǰ��������ϵ����������iҪ������j��ɵĻ����ϲ��ܿ�ʼ������Ҫ��ĳ���γ̱�����������һ���γ̲��У�����������ϵ��
���⣬һ�㶼�������޻�ͼ������������������Ҫ����������

main1.cpp: use matrix to represent a graph, time complexity is O(n*n)
main1.cpp���þ����ʾͼ��ʱ�临�Ӷ���O(n*n)

main2.cpp: use Adiacent List model to represent a graph, time complexity is O(n + m), where n is the number of node,
m is the number of edge.
main2.cpp�����ڽӱ���ʾͼ��ʱ�临�Ӷ���O(n+m),n�ǽڵ�����m�Ǳߵ�������

һ�������������ÿ���ҵ�һ�����Ϊ0�Ľڵ㣬Ȼ��ɾ��������ʣ��ڵ����ȣ�Ȼ������һ�����Ϊ0�ĵ㣬��������ѭ����ȥ��
ֱ�����е㶼ɾ�������Ҳ������Ϊ0�ĵ㣬���ж�һ������ͼ�Ƿ��л���

��main2.cpp�У���ά����һ���ڵ���Ⱦ��󣬺�һ�����Ϊ0�Ľڵ���С�ÿ��ȡ�ڵ㶼ֱ�ӴӶ�����ȡ��Ȼ��ͣ���½ڵ���ȣ�
�ж�����Ƿ�Ϊ0������ǣ�����뵽���С�