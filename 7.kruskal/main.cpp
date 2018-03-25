#include<bits/stdc++.h>

using namespace std;

int tot = 0;                                                   //记录边数
int head[100];                                                 //记录每个几点对应的起始边，顺时针方向数，最右为其实边
int N;                                                         //总节点数
int father[100];                                               //记录祖先节点
int Rank[100];                                                 //记录x的秩

struct arc{                                                    //边的表示
    int start;
    int end;                                                   //边的终止节点
    int next;                                                  //同起点邻边
    int weight;                                                //权重

    arc(int s = 0, int x = 0, int y = -1, int w = -1){         //结构体默认是public的构造函数
        start = s;
        end = x;
        next = y;
        weight = w;
    }
}e[100];

void addE(int u, int v, int w){                                 //增加一条从u 到 v的边
    e[tot] = arc(u, v, head[u], w);
    head[u] = tot;
    tot++;

    e[tot] =arc(v, u, head[v], w);
    head[v] = tot;
    tot++;
}

int Find_Set(int x){
    if(x != father[x]){
        father[x] = Find_Set(father[x]);                        //查找的同时完成更新
    }
    return father[x];
}

void Union(int x, int y){
    x = Find_Set(x);                                            //x的祖先
    y = Find_Set(y);

    if(x == y)return;                                           //公共祖先，则直接返回

    if(Rank[x] > Rank[y]){
        father[y] = x;                                          //小的合并到大的，没有更新y对应集合所有节点祖先，因为下次Find_Set会自动全部更新
    }
    else{
        if(Rank[x] == Rank[y]){                                 //合并相同秩时，才会让秩加1
            Rank[y]++;
        }
        father[x] = y;
    }
}

bool compare(const arc e1, const arc e2){
    return e1.weight < e2.weight;
}

void kruskal(){
    //对所有边排序
    sort(e, e + tot, compare);

    int num = 0;                                               //记录边的数量
    int i = 0;
    while(num < N - 1){                                        //生成树边的数量比节点数少1
        while(Find_Set(e[i].start) == Find_Set(e[i].end))      //找到两节点不属于同一并查集的边
            i++;

        //合并
        cout<<e[i].start + 1<<" "<<e[i].end + 1<<" : "<<e[i].weight<<endl;
        Union(e[i].start, e[i].end);
        num++;
    }

}

int main()
{
    N = 6;

    memset(head, -1, sizeof(head));

    addE(0, 1, 6);
    addE(0, 2, 1);
    addE(0, 3, 5);

    addE(1, 2, 5);
    addE(1, 4, 3);

    addE(2, 3, 5);
    addE(2, 4, 6);
    addE(2, 5, 4);

    addE(3, 5, 2);

    addE(4, 5, 6);

    for(int i = 0; i < N; i++){
        father[i] = i;
        Rank[i] = 1;
    }

    kruskal();

    return 0;
}

















