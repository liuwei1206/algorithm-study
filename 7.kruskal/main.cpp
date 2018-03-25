#include<bits/stdc++.h>

using namespace std;

int tot = 0;                                                   //��¼����
int head[100];                                                 //��¼ÿ�������Ӧ����ʼ�ߣ�˳ʱ�뷽����������Ϊ��ʵ��
int N;                                                         //�ܽڵ���
int father[100];                                               //��¼���Ƚڵ�
int Rank[100];                                                 //��¼x����

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
}e[100];

void addE(int u, int v, int w){                                 //����һ����u �� v�ı�
    e[tot] = arc(u, v, head[u], w);
    head[u] = tot;
    tot++;

    e[tot] =arc(v, u, head[v], w);
    head[v] = tot;
    tot++;
}

int Find_Set(int x){
    if(x != father[x]){
        father[x] = Find_Set(father[x]);                        //���ҵ�ͬʱ��ɸ���
    }
    return father[x];
}

void Union(int x, int y){
    x = Find_Set(x);                                            //x������
    y = Find_Set(y);

    if(x == y)return;                                           //�������ȣ���ֱ�ӷ���

    if(Rank[x] > Rank[y]){
        father[y] = x;                                          //С�ĺϲ�����ģ�û�и���y��Ӧ�������нڵ����ȣ���Ϊ�´�Find_Set���Զ�ȫ������
    }
    else{
        if(Rank[x] == Rank[y]){                                 //�ϲ���ͬ��ʱ���Ż����ȼ�1
            Rank[y]++;
        }
        father[x] = y;
    }
}

bool compare(const arc e1, const arc e2){
    return e1.weight < e2.weight;
}

void kruskal(){
    //�����б�����
    sort(e, e + tot, compare);

    int num = 0;                                               //��¼�ߵ�����
    int i = 0;
    while(num < N - 1){                                        //�������ߵ������Ƚڵ�����1
        while(Find_Set(e[i].start) == Find_Set(e[i].end))      //�ҵ����ڵ㲻����ͬһ���鼯�ı�
            i++;

        //�ϲ�
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

















