#include<stdio.h>
#include<stdlib.h>
int count = 0;
bool checkQueen(char **arr, int x_, int y_) {
    bool valid = true;
    //橫排檢查
    //printf("橫排檢查\n");
    for (int i = 0; i < 8; i++) {
        //printf("%d %d\n", y_, i);
        if (arr[y_][i] == '1') {
            valid = false;
        }
    }
    //printf("直排檢查\n");
    //直排檢查
    for (int i = 0; i < 8; i++) {
        //printf("%d %d\n", i, x_);
        if (arr[i][x_] == '1') {
            valid = false;
        }
    }
    //printf("右下檢查\n");
    //右下斜角檢查
    int offset = x_;
    for (int i = y_; i < 8 && offset<8; i++) {
        //printf("%d %d\n", i, offset);
        if (arr[i][offset] == '1') {
            valid = false;
        }
        offset++;
    }
    //printf("左下檢查\n");
    offset = y_;
    for (int i = x_; i < 8 && offset >= 0; i++) {
        //printf("%d %d\n", i, offset);
        if (arr[i][offset] == '1') {
            valid = false;
        }
        offset--;
    }
    //左上斜角檢查
    //printf("左上檢查\n");
    offset = y_;
    for (int i = x_; i >= 0 && offset>=0; i--) {
        //printf("%d %d\n", offset, i);
        if (arr[offset][i] == '1') {
            valid = false;
        }
        offset--;
    }
    //printf("右上檢查\n");
    offset = x_;
    for (int i = y_; i < 8 && offset >= 0; i++) {
        //printf("%d %d\n", offset, i);
        if (arr[offset][i] == '1') {
            valid = false;
        }
        offset--;
    }
    return valid;
}

void show(char **arr) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

void queen(char **b, int bx, int by) {
    for (int col = 0; col < 8; col++){
    //find
        if (checkQueen(b, col, by)){
            b[by][col] = '1';
            //show(b);
            //printf("%d %d填入X\n", by, col);
            if (by < 7){
                //因為by+1 所以要少1
                //forward
                queen(b, col, by+1);
            }
            else{
                //done
                count++;
                printf("第%d種\n",count);
                show(b);
                printf("\n");
            }
            //找新解 重置皇后位置
            b[by][col] = '0';
        }
    }
    //back
}


int main() {
    char **board;
    board = (char**)malloc(sizeof(char*) * 8);
    for (int i = 0; i < 8; i++) {
        board[i] = (char*)malloc(sizeof(char*) * 8);
        for (int j = 0; j < 8; j++) {
            board[i][j] = '0';
        }
    }
    queen(board, 0, 0);
    printf("共%d種解\n", count);
    system("pause");
    return 0;
}
