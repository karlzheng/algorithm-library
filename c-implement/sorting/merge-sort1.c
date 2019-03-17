// poj 1804
#include <stdio.h>
#include <string.h>
#define MAXN 1005

int a[MAXN], tmp[MAXN];
int ans;                // ����Ը���

// ������ [left, right] �� middle Ϊ������ 
void merge(int left, int middle, int right) {
    int i = left, j = middle + 1, k = left;
    // �ֱ�װ� tmp �����λ�� 
    while (i <= middle && j <= right) {
        if (a[i] > a[j]) {
            tmp[k++] = a[j++];
            ans += middle - i + 1;       // ��������Ը��� 
        } else {
            tmp[k++] = a[i++];
        }
    }
    
    while (i <= middle)
        tmp[k++] = a[i++];
    while (j <= right)
        tmp[k++] = a[j++];
    for (i = left; i <= right; i++)
        a[i] = tmp[i];
}

void merge_sort(int left, int right) {
    if (left < right) {
        int middle = (left + right) >> 1;
        merge_sort(left, middle);
        merge_sort(middle + 1, right);
        merge(left, middle, right);
    }
}


int main() {
    int n, t, i, count = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        ans = 0;
        merge_sort(0, n - 1);
        printf("Scenario #%d:\n%d\n\n", ++count, ans);
    }
    return 0;
}
