#include<iostream>
#include<memory.h>
using namespace std;

int graph[100][100];                                   //图的矩阵表示
int N;                                                 //边数为N

int in_num[100];                                       //每个节点对应的进入边
int visit[100];                                        //是否被访问

/*
*   判断是否是有向无圈图，使用拓扑排序
*/
bool isDAG(){
    int count = 0;                                     //删除的点的数量

    while(count < N){
        //1.找到入度为0的
        int p = -1;
        for(int i = 0; i < N; i++){
            if(!visit[i]&&!in_num[i]){
                p = i;
                break;
            }
        }

        if(p == -1) return false;                       //如果p为-1，表示没找到，返回false

        //2.找到边，标记为已经访问
        count++;                                        //边数加1
        visit[p] = 1;
        cout<<(p + 1 )<<" ";

        //3.更新节点对应进入边数量
        for(int i = 0; i < N; i++)
            if(graph[p][i])
                in_num[i]--;
    }
    return true;
}

/*
*   初始化函数
*/
void init(){
    memset(visit, 0, sizeof(visit));
    memset(in_num, 0, sizeof(in_num));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(graph[i][j])
                in_num[j]++;
}

int main(){
    N = 7;
    graph[0][3] = 1;
    graph[0][4] = 1;
    graph[0][6] = 1;

    graph[1][2] = 1;
    graph[1][4] = 1;
    graph[1][5] = 1;

    graph[2][3] = 1;
    graph[2][4] = 1;

    graph[3][4] = 1;

    graph[4][5] = 1;
    graph[4][6] = 1;

    graph[5][6] = 1;

    graph[6][0] = 1;
    init();

    if(isDAG())
        cout<<"有向无圈图"<<endl;
    else
        cout<<"不存在拓扑排序"<<endl;

    return 0;
}
