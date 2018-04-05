#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;

int tot = 0;                                   //记录边的总数
int N;
int head[100];                                 //记录每个节点对应的第一条边的编号
queue<int> S;                                  //入度为0的节点集合
int in_num[100];                               //每个节点对应的入度

/*
*   一条边对应的结构体
*/
struct arc{
    int end;
    int next;

    arc(int e = 0, int n = -1){
        end = e;
        next = n;
    }
}e[100];

/*
*   添加一条新的边
*/
void addE(int u, int v){
    e[tot] = arc(v, head[u]);
    in_num[v]++;
    head[u] = tot;
    tot++;
}

/*
*   判断是不是DAG图(有向无圈图)
*/
bool isDAG(){
    int count = 0;                                     //删除的节点数
    for(int i = 0; i < N; i++)
        if(!in_num[i]) S.push(i);
    while(count < N){
        //1.从S中获取一个节点
        if(S.empty()) return false;

        int node = S.front();
        S.pop();
        cout<<(node + 1)<<" ";

        //2.删除的节点数加1
        count++;

        //3.更新各节点入边度
        for(int i = head[node]; i != -1; i = e[i].next){
            int end = e[i].end;
            in_num[end]--;
            if(in_num[end] == 0) S.push(end);
        }
    }
}

int main(){
    N = 7;
    memset(head, -1, sizeof(head));
    memset(in_num, 0, sizeof(in_num));

    addE(0, 3);
    addE(0, 4);
    addE(0, 6);

    addE(1, 2);
    addE(1, 4);
    addE(1, 5);

    addE(2, 3);
    addE(2, 4);

    addE(3, 4);

    addE(4, 5);
    addE(4, 6);

    addE(5, 6);

    //addE(6, 0);

    if(isDAG())
        cout<<"有向无圈图"<<endl;
    else
        cout<<"不存在拓扑排序"<<endl;

    return 0;
}

