#include<bits/stdc++.h>

using namespace std;

int tot = 0;                                                   //记录边数
int head[100];                                                 //记录每个几点对应的起始边，顺时针方向数，最右为其实边
int dis[100];                                                  //记录到各点的距离
int N;                                                         //总节点数
int visit[100];                                                //是否访问过

struct arc{                                                    //边的表示
    int end;                                                   //边的终止节点
    int next;                                                  //同起点邻边
    int weight;                                                //权重

    arc(int x = 0, int y = -1, int w = -1){                    //结构体默认是public的构造函数
        end = x;
        next = y;
        weight = w;
    }
}e[100];

void addE(int u, int v, int w){                                //增加一条从u 到 v的边
    e[tot] = arc(v, head[u], w);
    head[u] = tot;
    tot++;
}


int getMin(){
    int min = 99999;
    int pos = -1;
    for(int i = 0; i < N; i++){
        if(dis[i] >0 && dis[i] < min && !visit[i]){
            min = dis[i];
            pos = i;
        }
    }
    return pos;
}


/*
*   dijkstra算法是单源最短路径算法，所以给定参数u为起点
*   @params:
*       u:单源中的起点
*/
void dijkstra(int u){
    for(int i = head[u]; i != -1; i = e[i].next)
        dis[e[i].end] = e[i].weight;                            //初始化权重

    int count = 1;
    visit[u] = 1;
    dis[u] = 0;

    while(count < N){
        int pos = getMin();                                     //找到最小值
        visit[pos] = 1;
        count++;

        for(int i = head[pos]; i != -1; i = e[i].next)          //以pos节点为中间节点，更新单源最短路径
            if((dis[pos] + e[i].weight < dis[e[i].end]) || dis[e[i].end] == -1)
                dis[e[i].end] = dis[pos] + e[i].weight;


    }

    for(int i = 0; i < N; i++){
        if(dis[i] >= 0)
            cout<<u<<" 到 "<<i<<" 的最短路径为: "<<dis[i]<<endl;
        else
            cout<<u<<", "<<i<<" 不可达!"<<endl;
    }
}


int main()
{
    N = 6;

    memset(head, -1, sizeof(head));
    memset(dis, -1, sizeof(dis));                               //初始化dis为-1,意为不可达
    memset(visit, 0, sizeof(visit));                            //初始化visit为0，表示都未访问过

    addE(0, 2, 10);
    addE(0, 4, 30);
    addE(0, 5, 100);

    addE(1, 2, 5);

    addE(2, 3, 50);

    addE(3, 5, 10);

    addE(4, 3, 20);
    addE(4, 5, 60);

    dijkstra(0);

    return 0;
}

















