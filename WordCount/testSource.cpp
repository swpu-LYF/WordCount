#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100

int main(int argc, char* argv[]) {
    char ch;
    int char_count = 0, word_count = 0, in_word = 0;
    FILE* fp;

    // 检查命令行参数
    if (argc != 3) {
        printf("Usage: WordCount -[c|w] <filename>\n");
        return 1;
    }

    // 判断参数
    int mode = 0;
    if (strcmp(argv[1], "-c") == 0) {
        mode = 1; // 统计字符数
    }
    else if (strcmp(argv[1], "-w") == 0) {
        mode = 2; // 统计单词数
    }
    else {
        printf("Unknown parameter %s\n", argv[1]);
        return 1;
    }

    // 打开文本文件
    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", argv[2]);
        return 1;
    }

    // 逐个字符读取文本文件
    while ((ch = fgetc(fp)) != EOF) {
        char_count++;
        if (isspace(ch) || ch == ',') { // 遇到空格或逗号，单词计数器加一
            in_word = 0;
        }
        else {
            if (!in_word) { // 遇到新单词，单词计数器加一
                word_count++;
                in_word = 1;
            }
        }
    }

    // 关闭文件
    fclose(fp);

    // 输出结果
    if (mode == 1) {
        printf("字符数：%d\n", char_count);
    }
    else {
        printf("单词数：%d\n", word_count);
    }

    return 0;
}