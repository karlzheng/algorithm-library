#include <cstdio>
#include <cmath> 
#include <algorithm>

const int MAXN = 205;
const double eps = 1e-8;        // �������

int n;
double del;
double a[MAXN][MAXN];

bool gauss() {
    // ��ÿ��ʽ�ӽ���ö�� 
    for (int i = 0; i < n; i++) {
        int k = i;
        // �� i ����һ����ʽ��ʼö�� 
        for (int j = i + 1; j < n; j++) {
            // �Ƚϵ� k ��ʽ�Ӻ͵� j ��ʽ����δ֪�� i ϵ���Ĵ�С, fabs() ��ʾ�Ը�����ȡ����ֵ 
            if (fabs(a[j][i]) > fabs(a[k][i])) {
                k = j;      // �ҵ��� i ��δ֪��ϵ������ 
            }
        }

        del = a[k][i];

        // �����һ��δ֪��������ʽ���е�ϵ����Ϊ 0������ֵ���ֵС�ڸ����������޽� 
        if (fabs(del) < eps) {
            return false;
        }

        // ���ڵ�ǰʽ�ӣ���� k ��ʽ�ӽ����������ϵ��������ǰʽ��ʵΪδ֪�� i ϵ�����ĵ� k ��ʽ�� 
        for (int j = i; j <= n; j++) {
            std::swap(a[i][j], a[k][j]);
        }

        // Ȼ��Ե�ǰʽ�ӵ����������ֵ����ȥ�� k ��ʽ���е� i ��δ֪����ϵ�� 
        for (int j = i; j <= n; j++) {
            a[i][j] /= del;
        }

        // ����������ʽ�ӣ��Ը������/��ȥ��ͬϵ�� 
        for (k = 0; k < n; k++) {
            // ֻ�Էǵ�ǰʽ�Ӳ��� 
            if (k != i) {
                del = a[k][i];
                for (int j = i; j <= n; j++) {
                    a[k][j] -= a[i][j] * del;
                }
            }
        }
    }
    return true;
}

int main() {
    // δ֪������Ŀ 
    scanf("%d", &n);

    // n ��δ֪����������Ҫ�� n ����ʽ������⣬�����޽� 
    for (int i = 0; i < n; i++) { 
        // ע��ڶ���ѭ����������� j <= n����Ҫ�����˳���ϵ���⻹Ҫ����һ������ʽ��ֵ 
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    // a[i][j] ��ʾ�ڵ� i ����ʽ�е� j ��δ֪����ϵ�� 

    // ��˹��Ԫ��⣬����÷������н⣬���� true 
    bool flag = gauss(); 

    if (!flag) {
        // �޽�
        printf("No Solution");
    } else {
        for (int i = 0; i < n; i++) {
            // ����� i ��ʽ�ӵ�ֵ����Ϊ�� i ��δ֪���Ĵ�
            printf("%.2lf\n", a[i][n]);
        }
    }

    return 0;
}
