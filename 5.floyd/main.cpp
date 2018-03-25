#include<bits/stdc++.h>

using namespace std;

int tot = 0;                                                   //��¼����
int head[100];                                                 //��¼ÿ�������Ӧ����ʼ�ߣ�˳ʱ�뷽����������Ϊ��ʵ��
int dis[100][100];                                             //��¼������ľ���
int N;                                                         //�ܽڵ���
int path[100][100];                                            //·��

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


void floyd(){
    //��ʼ���������飬���·�����飬��·������
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                dis[i][j] = 0;
                path[i][j] = i;
            }
            else{
                dis[i][j] = INT_MAX;
                path[i][j] = -1;
            }
        }
    }

    //�����е�ͼ��ʼ��
    for(int i = 0; i < N; i++){
        for(int j = head[i]; j != -1; j = e[j].next){
            int v = e[j].end;

            dis[i][v] = e[j].weight;
        }
    }

    //Ȼ��̬�滮���ø�������Ϊ�м�ڵ������ȥ����·������
    for(int k = 0; k < N; k++){                                             //�м�ڵ�
        for(int i = 0; i < N; i++){
            for(int j = head[k]; j != -1; j = e[j].next){                   //k��Ϊ�м�ڵ㣬���и���
                int v = e[j].end;

                if(dis[i][v] > dis[i][k] + e[j].weight){
                    dis[i][v] = dis[i][k] + e[j].weight;                     //����·������ֵ
                    path[i][v] = k;                                          //��¼�ϼ���·��Ϊk
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<(i + 1)<<" �� "<<(j + 1)<<" ��̳���Ϊ:"<<dis[i][j]<<endl;
        }
    }

    cout<<(0 + 1)<<" �� "<<(2 + 1)<<" ���·��Ϊ:"<<endl;
    int p = path[0][2];
    while(p != -1){
        cout<<(p + 1)<<" ";
        p = path[0][p];
    }
    cout<<endl;
}



int main()
{
    N = 3;

    memset(head, -1, sizeof(head));

    addE(0, 1, 4);
    addE(0, 2, 11);

    addE(1, 0, 6);
    addE(1, 2, 2);

    addE(2, 0, 3);

    floyd();

    return 0;
}

















