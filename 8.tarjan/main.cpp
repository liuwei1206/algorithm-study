#include<bits/stdc++.h>

using namespace std;

int tot = 0;                                                   //记录边数
int head[100];                                                 //记录每个几点对应的起始边，顺时针方向数，最右为其实边
int N;                                                         //总节点数

int DNF[100];                                                  //深度遍历时，节点被访问的顺序
int low[100];                                                  //记录节点能够找到的最先访问的祖先
int flag[100];                                                 //记录节点是否在栈中
int order = 1;                                                 //记录访问的次序
int num = 0;                                                   //记录强连通分量的个数
int nodes[100];                                                //栈，用于存访问过的节点
int top = -1;                                                  //记录栈顶位置

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

/*
*   tarjan算法，用于判断有向图中有多少个强连通分量，参数u为起始访问节点
*/
void tarjan(int u){
    DNF[u] = low[u] = order++;
    nodes[++top] = u;                                          //压入栈，
    flag[u] = 1;

    for(int i = head[u]; i != -1; i = e[i].next){
        int v = e[i].end;
        if(!DNF[v]){                                           //如果节点未被访问，递归
            tarjan(v);
            if(low[u] > low[v])
                low[u] = low[v];
        }
        else{                                                  //如果访问过,并且还在栈中，用于更新u的最早访问的祖先
            if(low[u] > DNF[v] && flag[v])
                low[u] = DNF[v];
        }
    }

    //如果没有节点可以深入遍历了，则向前回溯。如果回溯到某个节点i有low[i]=DNF[i]，说明这是某个强连通分量的根节点了，弹出
    if(DNF[u] == low[u]){
        num++;
        int ele;
        do{
            ele = nodes[top--];                                //弹出栈顶元素
            flag[ele] = 0;

            cout<<(ele + 1)<<" ";
        }while(ele != u);                                      //直到弹出了u

        cout<<endl;
    }

}



int main()
{
    N = 6;

    memset(head, -1, sizeof(head));
    memset(low, 0, sizeof(low));
    memset(DNF, 0, sizeof(DNF));
    memset(flag, 0, sizeof(flag));

    addE(0, 1, 1);
    addE(0, 2, 5);

    addE(1, 3, 2);

    addE(2, 3, 6);
    addE(2, 4, 7);

    addE(3, 0, 3);
    addE(3, 5, 4);

    addE(4, 5, 8);

    tarjan(0);

    cout<<"共有 "<<num<<" 个强连通分量"<<endl;

    return 0;
}

















