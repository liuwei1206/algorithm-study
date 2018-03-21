#include <bits/stdc++.h>
using namespace std;

class MiniHeap{
public:
    MiniHeap(){
        array = new int[100];                     //Ĭ����100��
        size = 0;
    }
    ~MiniHeap(){
        delete [] array;
    }

    //����Ԫ��
    void addItem(int item){
        array[size++] = item;                     //���Ԫ��

        shiftUp(size - 1);                        //���ϵ���
    }

    //ɾ����СԪ��
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

    //���ϵ���
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

    //���µ���
    void shiftDown(int pos){
        int node = pos * 2 + 1;

        while(node < size && node + 1 < size){
            if(array[node] > array[node+1])         //����Ԫ�������ֵ
                node++;

            if(array[node] < array[pos]){           //����
                swapVal(node, pos);

                pos = node;
                node = pos * 2 + 1;
            }
            else
                break;
        }
    }

    //����x�͵Ķ�Ӧֵ
    void swapVal(int x, int y){
        int tmp = array[x];
        array[x] = array[y];
        array[y] = tmp;
    }

    int getSize(){
        return size;
    }

private:
    int *array;                                   //�ڲ�����
    int size;                                     //��ǰԪ�ظ���
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
