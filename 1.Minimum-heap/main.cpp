#include <bits/stdc++.h>
using namespace std;

class MiniHeap{
public:
    MiniHeap(){
        array = new int[100];                     //默认有100个
        size = 0;
    }
    ~MiniHeap(){
        delete [] array;
    }

    //增加元素
    void addItem(int item){
        array[size++] = item;                     //添加元素

        shiftUp(size - 1);                        //向上调整
    }

    //删除最小元素
    int getMin(){
        if(size > 0)
            return array[0];
        else
            return -1;
    }

    void removeMin(){
        array[0] = array[size - 1];
        size--;
        shiftDown(0);
    }

    int popMin(){
        int min = getMin();
        removeMin();
        return min;
    }

    //向上调整
    void shiftUp(int pos){
        int node = (pos - 1) / 2;

        while(node >= 0){
            if(array[node] > array[pos]){
                swapVal(node, pos);

                pos = node;
                node = (pos - 1) / 2;
            }
            else
                break;
        }
    }

    //向下调整
    void shiftDown(int pos){
        int node = pos * 2 + 1;

        while(node < size && node + 1 < size){
            if(array[node] > array[node+1])         //找子元素中最大值
                node++;

            if(array[node] < array[pos]){           //交换
                swapVal(node, pos);

                pos = node;
                node = pos * 2 + 1;
            }
            else
                break;
        }
    }

    //交换x和的对应值
    void swapVal(int x, int y){
        int tmp = array[x];
        array[x] = array[y];
        array[y] = tmp;
    }

    int getSize(){
        return size;
    }

private:
    int *array;                                   //内部容器
    int size;                                     //当前元素个数
};


int main(){
    int A[10] = {20, 9, 15, 6, 8, 6, 31, 2, 14, 25};

    MiniHeap *minHeap = new MiniHeap();

    for(int i = 0; i < 10; i++){
        minHeap->addItem(A[i]);
    }

    for(int i = 0; i < 10; i++)
        cout<<minHeap->popMin()<<endl;
}
