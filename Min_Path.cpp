#include<cstdio>
#include<cstdlib>

using namespace std;

int map[6][6] = {
{ 0, 20, 1e9, 1e9, 1e9, 1e9 },
{ 20, 0, 5, 10, 1e9, 1e9 },
{ 1e9, 5, 0, 1e9, 40, 1e9 },
{ 1e9, 10, 1e9, 0, 1e9, 30 },
{ 1e9, 1e9, 40, 1e9, 0, 15 },
{ 1e9, 1e9, 1e9, 30, 15, 0 }
};
int visited[6] = { 0 };
int min_path = 1e9;

void dfs(int x, int end, int len) {
    if (x == end) {
        min_path = len < min_path ? len : min_path;
        printf("Arrival in length : %d\n", len);
        return;
    }
    for (int i = 0; i < 6; i++) {
        if (x == i) continue;
        if (visited[x] != 1 && map[x][i] != 1e9) {
            visited[x] = 1;
            dfs(i, 5, len + map[x][i]);
            visited[x] = 0;
        }
    }
}


int main() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%10d ", map[i][j]);
        }
        printf("\n");
    }
    dfs(0, 5, 0);
    printf("\n\n%d\n", min_path);

    system("pause");
    return 0;
}