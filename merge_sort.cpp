// 归并排序

#include <bits/stdc++.h>
#define N 1111111
using namespace std;
int a[N], t[N], n;

void msort(int l, int r)
{
    // 如果数组长度为1（即l和r指向同一个位置），数组已经有序，直接返回即可
    if(l >= r) return;
    int mid = l + r >> 1;
    // 分别排序左侧和右侧
    msort(l, mid);
    msort(mid + 1, r);
    // 声明一个指针
    int i = l, j = mid + 1, p = l;
    // 当两个指针都没有触底时
    while(i <= mid && j <= r)
    {
        // 如果符合从小到大的顺序（即a[i] <= a[j]），将a[i] 上的数字放入临时数组中
        if(a[i] <= a[j]) t[p++] = a[i++];
        // 否则就将a[j] 上的数字放入临时数组中
        else t[p++] = a[j++];
    }
    // 将剩下的数字放入临时数组中
    while(i <= mid) t[p++] = a[i++];
    while(j <= r) t[p++] = a[j++];
    // 将临时数组的数字搬回去
    for(int ii = l; ii <= r; ii++) a[ii] = t[ii];
}


int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    msort(1, n);
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}
