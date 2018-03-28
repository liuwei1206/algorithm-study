#include<bits/stdc++.h>

using namespace std;

int tot1 = 0;                                                  //记录边数
int head1[100];                                                //记录每个几点对应的起始边，顺时针方向数，最右为其实边
int N;                                                         //总节点数

int tot2 = 0;
int head2[100];                                                //用于记录逆向图

int order[100];                                                //记录逆序的顺序
int marked[100];                                               //记录所属类别
int top = -1;
int num = 0;                                                   //强连通分量的数量


struct arc{                                                    //边的表示
    int end;                                                   //边的终止节点
    int next;                                                  //同起点邻边
    int weight;                                                //权重

    arc(int x = 0, int y = -1, int w = -1){                    //结构体默认是public的构造函数
        end = x;
        next = y;
        weight = w;
    }
}e1[100], e2[100];

void addE1(int u, int v, int w){                                //增加一条从u 到 v的边
    e1[tot1] = arc(v, head1[u], w);
    head1[u] = tot1;
    tot1++;
}

void addE2(int u, int v, int w){
    e2[tot2] = arc(v, head2[u], w);
    head2[u] = tot2;
    tot2++;
}
/*
*   原图的深度遍历
*/
void dfs1(int u, int type){
    marked[u] = type;
    for(int i = head1[u]; i != -1; i = e1[i].next){
        int v = e1[i].end;
        if(!marked[v]){                                          //如果未访问过
            dfs1(v, type);
        }
    }
}

/*
*   逆向图的逆序深度遍历
*/
void dfs2(int u){
    marked[u] = 1;
    for(int i = head2[u]; i != -1; i = e2[i].next){
        int v = e2[i].end;
        if(!marked[v])
            dfs2(v);
    }
    cout<<u<<endl;
    order[++top] = u;                                            //逆序遍历，就是先深度遍历过程中，先遍历的，后入栈
}

/*
*   也可以用于判断有向图中强连通分量的数量
*/
void kosaraju(){

    //得到逆向图
    for(int i = 0; i < N; i++){
        for(int j = head1[i]; j != -1; j = e1[j].next){
            int v = e1[j].end;
            addE2(v, i, 1);                                      //添加
        }
    }

    //进行逆序遍历，记录节点信息
    for(int i = 0; i < N; i++)
        if(!marked[i])
            dfs2(i);                                             //逆序遍历逆向图，得到节点访问顺序order


    memset(marked, 0, sizeof(marked));

    while(top >= 0){
        int v = order[top--];

        if(!marked[order[v]]){
            num++;
            dfs1(order[v], num);
        }
    }
}



int main()
{
    N = 6;

    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));
    memset(marked, 0, sizeof(marked));



    addE1(0, 1, 1);
    addE1(0, 2, 5);

    addE1(1, 3, 2);

    addE1(2, 3, 6);
    addE1(2, 4, 7);

    addE1(3, 0, 3);
    addE1(3, 5, 4);

    addE1(4, 5, 8);


    kosaraju();

    cout<<"共有 "<<num<<" 个强连通分量"<<endl;

    for(int i = 1; i <= num; i++){
        for(int j = 0; j < N; j++){
            if(marked[j] == i)
                cout<<(j + 1)<<" ";
        }
        cout<<endl;
    }

    return 0;
}

















