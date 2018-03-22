#include<bits/stdc++.h>
using namespace std;

int graph[100][100];                                            //��ʾͼ
int N;                                                          //�ڵ���
int colors[100];                                                //�ڵ��Ӧ����ɫ��0������ɫ��1�����ɫ��2������ɫ, 3�����г�ͻɫ

/*
*   �ж��Ƿ��Ƕ���ͼ�����а�����ͼ�Ƿ���ͨͼ����µ��ж�
*   @return:
*   true:�� �� false:����
*/
bool isBipartiteGraph(){
    for(int i = 0; i < N; i++){
        if(colors[i] == 0){                                     //δ�Ź�ɫ
            queue<int> myqueue;
            myqueue.push(i);                                    //
            colors[i] = 1;                                      //�������ɫ��ż������ɫ

            while(myqueue.size()){                              //������ȱ���������ɫ��
                int top = myqueue.front();                      //����Ԫ��
                myqueue.pop();

                int nextColor = 0;                              //��һ��Ӧ���ŵ���ɫ

                if(colors[top] == 1)
                    nextColor = 2;
                else if(colors[top] == 2)
                    nextColor = 1;

                for(int j = 0; j < N; j++){                     //���������ڵ������ɫ
                    if(graph[top][j]){                            //����·��
                        if(colors[j] == 0){
                            colors[j] = nextColor;
                            myqueue.push(j);
                        }
                        else{
                            if(colors[j] == nextColor)
                                continue;
                            else
                                return 0;                        //ֱ�ӷ��س���
                        }
                    }
                }
            }
        }
    }
    return 1;
}

void showColors(){
    for(int i = 0; i < N; i++){
        cout<<(i + 1)<<" : "<<colors[i]<<endl;
    }
}
int main()
{
    memset(graph, 0, sizeof(graph));
    memset(colors, 0, sizeof(colors));
    N = 9;

    graph[0][1] = 1;

    graph[1][0] = 1;
    graph[1][2] = 1;
    graph[1][8] = 1;

    graph[2][1] = 1;
    graph[2][3] = 1;

    graph[3][2] = 1;
    graph[3][6] = 1;

    graph[4][5] = 1;
    graph[4][7] = 1;

    graph[5][4] = 1;

    graph[6][3] = 1;

    graph[7][4] = 1;
    graph[7][8] = 1;

    graph[8][1] = 1;
    graph[8][7] = 1;

    //graph[4][6] = 1;
    //graph[6][4] = 1;

    if(isBipartiteGraph()){
        cout<<"�Ƕ���ͼ"<<endl;
        showColors();
    }
    else
        cout<<"���Ƕ���ͼ"<<endl;

    return 0;
}
