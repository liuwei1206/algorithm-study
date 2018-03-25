#include<bits/stdc++.h>

using namespace std;

int tot = 0;                                                   //��¼����
int head[100];                                                 //��¼ÿ�������Ӧ����ʼ�ߣ�˳ʱ�뷽����������Ϊ��ʵ��
int dis[100];                                                  //��¼������ľ���
int N;                                                         //�ܽڵ���
int visit[100];                                                //�Ƿ���ʹ�

struct arc{                                                    //�ߵı�ʾ
    int end;                                                   //�ߵ���ֹ�ڵ�
    int next;                                                  //ͬ����ڱ�
    int weight;                                                //Ȩ��

    arc(int x = 0, int y = -1, int w = -1){                    //�ṹ��Ĭ����public�Ĺ��캯��
        end = x;
        next = y;
        weight = w;
    }
}e[100];

void addE(int u, int v, int w){                                //����һ����u �� v�ı�
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
*   dijkstra�㷨�ǵ�Դ���·���㷨�����Ը�������uΪ���
*   @params:
*       u:��Դ�е����
*/
void dijkstra(int u){
    for(int i = head[u]; i != -1; i = e[i].next)
        dis[e[i].end] = e[i].weight;                            //��ʼ��Ȩ��

    int count = 1;
    visit[u] = 1;
    dis[u] = 0;

    while(count < N){
        int pos = getMin();                                     //�ҵ���Сֵ
        visit[pos] = 1;
        count++;

        for(int i = head[pos]; i != -1; i = e[i].next)          //��pos�ڵ�Ϊ�м�ڵ㣬���µ�Դ���·��
            if((dis[pos] + e[i].weight < dis[e[i].end]) || dis[e[i].end] == -1)
                dis[e[i].end] = dis[pos] + e[i].weight;


    }

    for(int i = 0; i < N; i++){
        if(dis[i] >= 0)
            cout<<u<<" �� "<<i<<" �����·��Ϊ: "<<dis[i]<<endl;
        else
            cout<<u<<", "<<i<<" ���ɴ�!"<<endl;
    }
}


int main()
{
    N = 6;

    memset(head, -1, sizeof(head));
    memset(dis, -1, sizeof(dis));                               //��ʼ��disΪ-1,��Ϊ���ɴ�
    memset(visit, 0, sizeof(visit));                            //��ʼ��visitΪ0����ʾ��δ���ʹ�

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

















