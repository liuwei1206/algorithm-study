#include<iostream>
using namespace std;
/*
*   �ж�start �� end֮���Ԫ�ظ������������һ��������еݹ�2�֣����򷵻�return
*   �ڻ��ݵĹ����У��Ѿ�֪����start �� mid �� mid �� end֮�䶼������ģ��ϲ�����
*   �൱�ںϲ�������������
*
*   params:
*       A: Ҫ���е�����
*       start: ��ʼλ��
*       end: ����λ��
*   ע��ǰ�󶼰���
*/
void merge_solve(int* A, int start, int end){
    if(start >= end) return;                                        //ֻʣ��һ��Ԫ��ʱ

    int s = start;
    int e = end;
    int mid = (start + end) / 2;                                    //�м��Ԫ��

    merge_solve(A, s, mid);
    merge_solve(A, mid + 1, e);

    //���ݽ׶�,������������ϲ�����Ҫһ���µ������ס�ĺõ���֮���ֵ
    int* tmp = new int[end - start + 1];                            //����ʱ���������
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

    //��������
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
