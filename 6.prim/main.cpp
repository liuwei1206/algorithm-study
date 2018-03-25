#include<bits/stdc++.h>

using namespace std;

int tot = 0;                                                   //记录边数
int head[100];                                                 //记录每个几点对应的起始边，顺时针方向数，最右为其实边
int N;                                                         //总节点数
int visit[100];                                                //是否访问过

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
}e[100], tmp[100];

void addE(int u, int v, int w){                                 //增加一条从u 到 v的边
    e[tot] = arc(u, v, head[u], w);
    head[u] = tot;
    tot++;

    e[tot] =arc(v, u, head[v], w);
    head[v] = tot;
    tot++;
}

//以u为起点，运行prim算法
void prim(int u){
    visit[u] = 1;
    int num = 1;                                                //已经找到一个店
    int tmpSize = 0;
    for(int i = head[u]; i != -1; i = e[i].next)                //将与u相连的边加入到临时表中
        tmp[tmpSize++] = e[i];

    while(num < N){
        int pos = -1;
        int min = INT_MAX;

        //从已存在点集的相连边中，找一个最短边，边的另一顶点未被访问过
        for(int i = 0; i < tmpSize; i++){
            if(min > tmp[i].weight && !visit[tmp[i].end]){
                min = tmp[i].weight;
                pos = i;
            }
        }
        cout<<tmp[pos].start+1<<" "<<tmp[pos].end+1<<" : "<<tmp[pos].weight<<endl;
        pos = tmp[pos].end;
        visit[pos] = 1;
        num++;

        for(int i = head[pos]; i != -1; i = e[i].next)
            if(!visit[e[i].end])
                tmp[tmpSize++] = e[i];
    }

}

int main()
{
    N = 6;

    memset(head, -1, sizeof(head));
    memset(visit, 0, sizeof(visit));



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


    prim(0);

    return 0;
}

















