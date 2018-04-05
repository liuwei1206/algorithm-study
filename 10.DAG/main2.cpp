#include<iostream>
#include<memory.h>
#include<queue>
using namespace std;

int tot = 0;                                   //��¼�ߵ�����
int N;
int head[100];                                 //��¼ÿ���ڵ��Ӧ�ĵ�һ���ߵı��
queue<int> S;                                  //���Ϊ0�Ľڵ㼯��
int in_num[100];                               //ÿ���ڵ��Ӧ�����

/*
*   һ���߶�Ӧ�Ľṹ��
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
*   ���һ���µı�
*/
void addE(int u, int v){
    e[tot] = arc(v, head[u]);
    in_num[v]++;
    head[u] = tot;
    tot++;
}

/*
*   �ж��ǲ���DAGͼ(������Ȧͼ)
*/
bool isDAG(){
    int count = 0;                                     //ɾ���Ľڵ���
    for(int i = 0; i < N; i++)
        if(!in_num[i]) S.push(i);
    while(count < N){
        //1.��S�л�ȡһ���ڵ�
        if(S.empty()) return false;

        int node = S.front();
        S.pop();
        cout<<(node + 1)<<" ";

        //2.ɾ���Ľڵ�����1
        count++;

        //3.���¸��ڵ���߶�
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
        cout<<"������Ȧͼ"<<endl;
    else
        cout<<"��������������"<<endl;

    return 0;
}

