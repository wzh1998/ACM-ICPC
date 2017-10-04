#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
const long double PI = 3.1415926535897932384626433832795;
int main(void) {
    long double s, s1, s2, s3, s6;
    long double p1, p2, p3;
    long double R;
    long double LBZ;//六边形总数
    long double DD1;//顶点1数
    long double DD2;//顶点2数
    long double DD3;//顶点3数
    
    int N, M, K;
    cin >> N >> M >> K;
    //scanf("%d %d %d", &N, &M, &K);
    for (int t = 1; !(N == 0 && M == 0 && K == 0); t++) {
        cin >> R;
        //scanf("%llf", &R);
        if ((K == N) && (M % 2 == 1)) {
            DD1 = 2 * (N + M + 1);
            DD2 = 2 * (N + M - 2);
            DD3 = (2 * N - 3) * (M - 1);
            LBZ = N * (M + 1) * 0.5 + (N - 1) * (M - 1) * 0.5;
        }
        else if ((K == N) && (M % 2 == 0)) {
            LBZ = N * M * 0.5 + (N - 1) * M * 0.5;
            DD1 = 2 * (N + M + 1) - 1;
            DD2 = 2 * (N + M - 2) - 1;
            DD3 = (2 * N - 3) * (M - 1);
        }
        else if ((K == N - 1) && (M % 2 == 1)) {
            DD1 = 2 * (N + M);
            DD2 = 2 * (N + M - 3);
            DD3 = (2 * N - 3) * (M - 1);
            LBZ = (N - 1) * (M + 1) * 0.5 + N * (M - 1) * 0.5;
        }
        else {
            DD1 = 2 * (N + M + 1) - 1;
            DD2 = 2 * (N + M - 2) - 1;
            DD3 = (2 * N - 3) * (M - 1);
            LBZ = (N - 1) * M * 0.5 + N * M * 0.5;
        }
        s = 1.5 * sqrt(3);
        
        
        s1 = (DD1 * s) / 6 + 2 * DD2*((s / 6) - 0.5*(((R*PI / 6) + 1))*R) + DD3 * (0.5 - (R / sqrt(3))) *(0.5 * sqrt(3) - R) * 3;
        
        s3 = DD3 * pow(R, 2)*((PI / 6) + (1 / sqrt(3))) * 3;
        
        
        s6 = LBZ * s;
        p1 = s1 / s6;
        p3 = s3 / s6;
        
        p2 = 1 - p3 - p1;
        if (p2 < 0)
            p2 = 0;
        p1 *= 100;
        p2 *= 100;
        p3 *= 100;
        printf("Case %d:\n", t);
        printf("Probability of covering 1 hexagon   = %.3llf percent.\n", p1);
        printf("Probability of covering 2 hexagons  = %.3llf percent.\n", p2);
        printf("Probability of covering 3 hexagons  = %.3llf percent.\n", p3);
        printf("\n");
        cin >> N >> M >> K;
        //scanf("%d %d %d", &N, &M, &K);
    }
    return 0;
}
