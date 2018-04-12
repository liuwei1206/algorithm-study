#include<iostream>
using namespace std;
/*
*   判断start 和 end之间的元素个数，如果超过一个，则进行递归2分；否则返回return
*   在回溯的过程中，已经知道了start 到 mid 和 mid 到 end之间都是有序的，合并过程
*   相当于合并两个有序数组
*
*   params:
*       A: 要排列的数组
*       start: 开始位置
*       end: 结束位置
*   注意前后都包含
*/
void merge_solve(int* A, int start, int end){
    if(start >= end) return;                                        //只剩下一个元素时

    int s = start;
    int e = end;
    int mid = (start + end) / 2;                                    //中间的元素

    merge_solve(A, s, mid);
    merge_solve(A, mid + 1, e);

    //回溯阶段,两个有序数组合并，需要一个新的数组记住拍好的序之后的值
    int* tmp = new int[end - start + 1];                            //存临时结果的数组
    int j = 0;
    int s2 = mid + 1;

    while(s <= mid && s2 <= e){
        if(A[s] < A[s2])
            tmp[j++] = A[s++];
        else
            tmp[j++] = A[s2++];
    }

    while(s <= mid)
        tmp[j++] = A[s++];
    while(s2 <= e)
        tmp[j++] = A[s2++];

    //复制数据
    s = start;
    while(s <= e){
        A[s] = tmp[s - start];
        s++;
    }
    delete[] tmp;
}

int main(){
    int A[12] = {1, 9, 2, 14, 13, 11, 7, 56, 21, 3, 9, 12};

    merge_solve(A, 0, 11);

    for(int i = 0; i < 12; i++)
        cout<<A[i]<<" ";
    cout<<endl;

    return 0;
}
