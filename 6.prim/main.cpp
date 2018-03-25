#include<bits/stdc++.h>

using namespace std;

int tot = 0;                                                   //��¼����
int head[100];                                                 //��¼ÿ�������Ӧ����ʼ�ߣ�˳ʱ�뷽����������Ϊ��ʵ��
int N;                                                         //�ܽڵ���
int visit[100];                                                //�Ƿ���ʹ�

struct arc{                                                    //�ߵı�ʾ
    int start;
    int end;                                                   //�ߵ���ֹ�ڵ�
    int next;                                                  //ͬ����ڱ�
    int weight;                                                //Ȩ��

    arc(int s = 0, int x = 0, int y = -1, int w = -1){         //�ṹ��Ĭ����public�Ĺ��캯��
        start = s;
        end = x;
        next = y;
        weight = w;
    }
}e[100], tmp[100];

void addE(int u, int v, int w){                                 //����һ����u �� v�ı�
    e[tot] = arc(u, v, head[u], w);
    head[u] = tot;
    tot++;

    e[tot] =arc(v, u, head[v], w);
    head[v] = tot;
    tot++;
}

//��uΪ��㣬����prim�㷨
void prim(int u){
    visit[u] = 1;
    int num = 1;                                                //�Ѿ��ҵ�һ����
    int tmpSize = 0;
    for(int i = head[u]; i != -1; i = e[i].next)                //����u�����ı߼��뵽��ʱ����
        tmp[tmpSize++] = e[i];

    while(num < N){
        int pos = -1;
        int min = INT_MAX;

        //���Ѵ��ڵ㼯���������У���һ����̱ߣ��ߵ���һ����δ�����ʹ�
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

















