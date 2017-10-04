/*
 大致思路：本题可以利用贪心算法的思路求解,将每门课程结束时间从小到大（从早到晚）按序排序,选择最早结束，且未在之前选过的课程,为了所选课程最大化，一共有五种可能，分别是从第0，1，2，3，4分钟开始选课，因此我们可以遍历这5种情况，从中找出使选课门数最大化的情况。
 */


#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct course{
    int start;
    int end;
}course;

bool compare(course first,course second){
    if(first.end != second.end) return (first.end < second.end);
    else return (first.start < second.start);
    
}
int main(void){
    course list[310];
    bool finish[310];
    int f_result;
    int temp_result;
    int N;
    cin >> N;
    while(N != 0){
        f_result = 0;
        memset(list, 0, sizeof(list));
        for(int i = 0;i < N;i++){
            scanf("%d %d",&list[i].start,&list[i].end);
        }
        sort(&list[0],&list[N],compare);
        for(int i = 0;i < 5;i++){
            temp_result = 0;
            memset(finish,false,sizeof(finish));
            for(int j = i;j < list[N - 1].end; j += 5){
                for(int z = 0;z < N;z++){
                    if(finish[z] != true){
                        if(j < list[z].end && j >= list[z].start){
                            temp_result++;
                            finish[z] = true;
                            break;
                        }
                    }
                }
            }
            if(temp_result > f_result)
                f_result = temp_result;
        }
        cout << f_result << endl;
        cin >> N;
    }
    return 0;
}
