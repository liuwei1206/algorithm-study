#include<iostream>
#include<memory.h>
using namespace std;

int graph[100][100];                                   //ͼ�ľ����ʾ
int N;                                                 //����ΪN

int in_num[100];                                       //ÿ���ڵ��Ӧ�Ľ����
int visit[100];                                        //�Ƿ񱻷���

/*
*   �ж��Ƿ���������Ȧͼ��ʹ����������
*/
bool isDAG(){
    int count = 0;                                     //ɾ���ĵ������

    while(count < N){
        //1.�ҵ����Ϊ0��
        int p = -1;
        for(int i = 0; i < N; i++){
            if(!visit[i]&&!in_num[i]){
                p = i;
                break;
            }
        }

        if(p == -1) return false;                       //���pΪ-1����ʾû�ҵ�������false

        //2.�ҵ��ߣ����Ϊ�Ѿ�����
        count++;                                        //������1
        visit[p] = 1;
        cout<<(p + 1 )<<" ";

        //3.���½ڵ��Ӧ���������
        for(int i = 0; i < N; i++)
            if(graph[p][i])
                in_num[i]--;
    }
    return true;
}

/*
*   ��ʼ������
*/
void init(){
    memset(visit, 0, sizeof(visit));
    memset(in_num, 0, sizeof(in_num));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(graph[i][j])
                in_num[j]++;
}

int main(){
    N = 7;
    graph[0][3] = 1;
    graph[0][4] = 1;
    graph[0][6] = 1;

    graph[1][2] = 1;
    graph[1][4] = 1;
    graph[1][5] = 1;

    graph[2][3] = 1;
    graph[2][4] = 1;

    graph[3][4] = 1;

    graph[4][5] = 1;
    graph[4][6] = 1;

    graph[5][6] = 1;

    graph[6][0] = 1;
    init();

    if(isDAG())
        cout<<"������Ȧͼ"<<endl;
    else
        cout<<"��������������"<<endl;

    return 0;
}
