#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100

int main(int argc, char* argv[]) {
    char ch;
    int char_count = 0, word_count = 0, in_word = 0;
    FILE* fp;

    // ��������в���
    if (argc != 3) {
        printf("Usage: WordCount -[c|w] <filename>\n");
        return 1;
    }

    // �жϲ���
    int mode = 0;
    if (strcmp(argv[1], "-c") == 0) {
        mode = 1; // ͳ���ַ���
    }
    else if (strcmp(argv[1], "-w") == 0) {
        mode = 2; // ͳ�Ƶ�����
    }
    else {
        printf("Unknown parameter %s\n", argv[1]);
        return 1;
    }

    // ���ı��ļ�
    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Unable to open file %s\n", argv[2]);
        return 1;
    }

    // ����ַ���ȡ�ı��ļ�
    while ((ch = fgetc(fp)) != EOF) {
        char_count++;
        if (isspace(ch) || ch == ',') { // �����ո�򶺺ţ����ʼ�������һ
            in_word = 0;
        }
        else {
            if (!in_word) { // �����µ��ʣ����ʼ�������һ
                word_count++;
                in_word = 1;
            }
        }
    }

    // �ر��ļ�
    fclose(fp);

    // ������
    if (mode == 1) {
        printf("�ַ�����%d\n", char_count);
    }
    else {
        printf("��������%d\n", word_count);
    }

    return 0;
}