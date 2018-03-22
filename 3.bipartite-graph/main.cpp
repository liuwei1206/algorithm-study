#include<bits/stdc++.h>
using namespace std;

int graph[100][100];                                            //表示图
int N;                                                          //节点数
int colors[100];                                                //节点对应的颜色，0代表无色，1代表红色，2代表蓝色, 3代表有冲突色

/*
*   判断是否是二部图，其中包含该图是非连通图情况下的判断
*   @return:
*   true:是 ； false:不是
*/
bool isBipartiteGraph(){
    for(int i = 0; i < N; i++){
        if(colors[i] == 0){                                     //未着过色
            queue<int> myqueue;
            myqueue.push(i);                                    //
            colors[i] = 1;                                      //奇数层红色，偶数层蓝色

            while(myqueue.size()){                              //广度优先遍历进行着色，
                int top = myqueue.front();                      //队首元素
                myqueue.pop();

                int nextColor = 0;                              //下一层应该着的颜色

                if(colors[top] == 1)
                    nextColor = 2;
                else if(colors[top] == 2)
                    nextColor = 1;

                for(int j = 0; j < N; j++){                     //遍历相连节点进行着色
                    if(graph[top][j]){                            //存在路径
                        if(colors[j] == 0){
                            colors[j] = nextColor;
                            myqueue.push(j);
                        }
                        else{
                            if(colors[j] == nextColor)
                                continue;
                            else
                                return 0;                        //直接返回出错
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
        cout<<"是二部图"<<endl;
        showColors();
    }
    else
        cout<<"不是二部图"<<endl;

    return 0;
}
