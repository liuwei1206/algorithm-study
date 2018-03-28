#include<bits/stdc++.h>

using namespace std;

int tot = 0;                                                   //��¼����
int head[100];                                                 //��¼ÿ�������Ӧ����ʼ�ߣ�˳ʱ�뷽����������Ϊ��ʵ��
int N;                                                         //�ܽڵ���

int DNF[100];                                                  //��ȱ���ʱ���ڵ㱻���ʵ�˳��
int low[100];                                                  //��¼�ڵ��ܹ��ҵ������ȷ��ʵ�����
int flag[100];                                                 //��¼�ڵ��Ƿ���ջ��
int order = 1;                                                 //��¼���ʵĴ���
int num = 0;                                                   //��¼ǿ��ͨ�����ĸ���
int nodes[100];                                                //ջ�����ڴ���ʹ��Ľڵ�
int top = -1;                                                  //��¼ջ��λ��

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

/*
*   tarjan�㷨�������ж�����ͼ���ж��ٸ�ǿ��ͨ����������uΪ��ʼ���ʽڵ�
*/
void tarjan(int u){
    DNF[u] = low[u] = order++;
    nodes[++top] = u;                                          //ѹ��ջ��
    flag[u] = 1;

    for(int i = head[u]; i != -1; i = e[i].next){
        int v = e[i].end;
        if(!DNF[v]){                                           //����ڵ�δ�����ʣ��ݹ�
            tarjan(v);
            if(low[u] > low[v])
                low[u] = low[v];
        }
        else{                                                  //������ʹ�,���һ���ջ�У����ڸ���u��������ʵ�����
            if(low[u] > DNF[v] && flag[v])
                low[u] = DNF[v];
        }
    }

    //���û�нڵ������������ˣ�����ǰ���ݡ�������ݵ�ĳ���ڵ�i��low[i]=DNF[i]��˵������ĳ��ǿ��ͨ�����ĸ��ڵ��ˣ�����
    if(DNF[u] == low[u]){
        num++;
        int ele;
        do{
            ele = nodes[top--];                                //����ջ��Ԫ��
            flag[ele] = 0;

            cout<<(ele + 1)<<" ";
        }while(ele != u);                                      //ֱ��������u

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

    cout<<"���� "<<num<<" ��ǿ��ͨ����"<<endl;

    return 0;
}

















