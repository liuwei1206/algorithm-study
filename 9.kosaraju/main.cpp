#include<bits/stdc++.h>

using namespace std;

int tot1 = 0;                                                  //��¼����
int head1[100];                                                //��¼ÿ�������Ӧ����ʼ�ߣ�˳ʱ�뷽����������Ϊ��ʵ��
int N;                                                         //�ܽڵ���

int tot2 = 0;
int head2[100];                                                //���ڼ�¼����ͼ

int order[100];                                                //��¼�����˳��
int marked[100];                                               //��¼�������
int top = -1;
int num = 0;                                                   //ǿ��ͨ����������


struct arc{                                                    //�ߵı�ʾ
    int end;                                                   //�ߵ���ֹ�ڵ�
    int next;                                                  //ͬ����ڱ�
    int weight;                                                //Ȩ��

    arc(int x = 0, int y = -1, int w = -1){                    //�ṹ��Ĭ����public�Ĺ��캯��
        end = x;
        next = y;
        weight = w;
    }
}e1[100], e2[100];

void addE1(int u, int v, int w){                                //����һ����u �� v�ı�
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
*   ԭͼ����ȱ���
*/
void dfs1(int u, int type){
    marked[u] = type;
    for(int i = head1[u]; i != -1; i = e1[i].next){
        int v = e1[i].end;
        if(!marked[v]){                                          //���δ���ʹ�
            dfs1(v, type);
        }
    }
}

/*
*   ����ͼ��������ȱ���
*/
void dfs2(int u){
    marked[u] = 1;
    for(int i = head2[u]; i != -1; i = e2[i].next){
        int v = e2[i].end;
        if(!marked[v])
            dfs2(v);
    }
    cout<<u<<endl;
    order[++top] = u;                                            //�����������������ȱ��������У��ȱ����ģ�����ջ
}

/*
*   Ҳ���������ж�����ͼ��ǿ��ͨ����������
*/
void kosaraju(){

    //�õ�����ͼ
    for(int i = 0; i < N; i++){
        for(int j = head1[i]; j != -1; j = e1[j].next){
            int v = e1[j].end;
            addE2(v, i, 1);                                      //���
        }
    }

    //���������������¼�ڵ���Ϣ
    for(int i = 0; i < N; i++)
        if(!marked[i])
            dfs2(i);                                             //�����������ͼ���õ��ڵ����˳��order


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

    cout<<"���� "<<num<<" ��ǿ��ͨ����"<<endl;

    for(int i = 1; i <= num; i++){
        for(int j = 0; j < N; j++){
            if(marked[j] == i)
                cout<<(j + 1)<<" ";
        }
        cout<<endl;
    }

    return 0;
}

















