#include<bits/stdc++.h>

using namespace std;

int tot = 0;                                                   //记录边数
int head[100];                                                 //记录每个几点对应的起始边，顺时针方向数，最右为其实边
int dis[100][100];                                             //记录到各点的距离
int N;                                                         //总节点数
int path[100][100];                                            //路径

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


void floyd(){
    //初始化两个数组，最短路径数组，和路径数组
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                dis[i][j] = 0;
                path[i][j] = i;
            }
            else{
                dis[i][j] = INT_MAX;
                path[i][j] = -1;
            }
        }
    }

    //用已有的图初始化
    for(int i = 0; i < N; i++){
        for(int j = head[i]; j != -1; j = e[j].next){
            int v = e[j].end;

            dis[i][v] = e[j].weight;
        }
    }

    //然后动态规划，用各个点作为中间节点可能性去更新路径长度
    for(int k = 0; k < N; k++){                                             //中间节点
        for(int i = 0; i < N; i++){
            for(int j = head[k]; j != -1; j = e[j].next){                   //k作为中间节点，进行更新
                int v = e[j].end;

                if(dis[i][v] > dis[i][k] + e[j].weight){
                    dis[i][v] = dis[i][k] + e[j].weight;                     //更新路径长度值
                    path[i][v] = k;                                          //记录上几次路径为k
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<(i + 1)<<" 到 "<<(j + 1)<<" 最短长度为:"<<dis[i][j]<<endl;
        }
    }

    cout<<(0 + 1)<<" 到 "<<(2 + 1)<<" 最短路径为:"<<endl;
    int p = path[0][2];
    while(p != -1){
        cout<<(p + 1)<<" ";
        p = path[0][p];
    }
    cout<<endl;
}



int main()
{
    N = 3;

    memset(head, -1, sizeof(head));

    addE(0, 1, 4);
    addE(0, 2, 11);

    addE(1, 0, 6);
    addE(1, 2, 2);

    addE(2, 0, 3);

    floyd();

    return 0;
}

















