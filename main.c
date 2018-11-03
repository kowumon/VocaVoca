#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VOCA_SIZE 15

typedef struct VOCA{
    char *word;
    char *meanings;
    int id;
}Voca;
Voca voca[VOCA_SIZE];
void Voca_practice(Voca *voca);
void Voca_open(FILE *fp, Voca *voca);


int main(void) {
    int i;
    int count = 0;

    while(1) { // 파일이름을 계속해서 묻는다.
        char *filename = malloc(sizeof(char) * 10);
        printf("Enter filename\n");
        scanf("%s", filename);
        FILE *fp = fopen(filename, "r");
        if(strcmp(filename,"done") == 0) {
            printf("See you again !\n");
            break;
        }
        if(!fp) {
            // 파일이 존재하지 않으면 파일 쓰기
            char *s1 = malloc(sizeof(char) * 10);
            char newline = '\n';
            printf("Enter write word.\n");

            fp = fopen(filename, "w"); // 파일 쓰기
            while (1) {
                scanf(" %[^\n]", s1);
                if (strcmp(s1, "done") == 0) {
                    break;
                }
                fwrite(s1, strlen(s1), 1, fp);
                fwrite(&newline, sizeof(newline), 1, fp);
                count++;
            }
            voca->id = count;
            fseek(fp, 0, SEEK_END);
            int size = ftell(fp);
            printf("End of fp : %d\n", size);

        } else {// 파일 읽어서 단어연습 시작하기
            Voca_open(fp, voca);
            Voca_practice(voca);

            for(i = 0; i < voca->id; i++) {
                free(voca[i].word);
                free(voca[i].meanings);
            }
        }
        fclose(fp);
    }

}

void Voca_open(FILE *fp, Voca *voca) {
    int i;
    int count = 0;
    char temp[100];
    char temp1[100];

    while(feof(fp) == 0) {
        if(fgetc(fp) == '\n') {
            printf("This is \\n.\n");
            count++;
        }
    }

    rewind(fp);

    for(i = 0; i < count; i++) {
        fscanf(fp, "%s %[^\n]", temp, temp1);
        voca[i].word = malloc(sizeof(strlen(temp)+ 1));
        voca[i].meanings = malloc(sizeof(strlen(temp1)+ 1));
        strcpy(voca[i].word, temp);
        strcpy(voca[i].meanings, temp1);
    }

    printf("count : %d", count);

    for(i = 0; i < count; i++) {
        printf("%s %s\n", voca[i].word, voca[i].meanings);
    }

    voca->id = count;
}

void Voca_practice(Voca *voca) {
    int count = voca->id;
    char temp[100];
    char *user_input;
    int i,j;
    char *wrongArray[10];
    int wrongNum = 0;
    int index = 0;

    printf("START GAME!\n");
    int wrongSum = 0;
    for (i = 0; i < count; i++) {
        printf("%s\n", voca[i].meanings);
        scanf(" %s", temp);
        user_input = malloc(sizeof(strlen(temp) + 1));
        strcpy(user_input, temp);
        // 한 문자 씩 비교하여 틀리면 wrongSum 추가.
        for(j = 0; j <= strlen(user_input); j++) {
            if(user_input[j] != voca[i].word[j]) {
                ++wrongNum;
            }
            if(user_input[j] == '\0' && wrongNum != 0) {
                wrongSum = wrongSum + 1;
                wrongArray[index] = malloc(sizeof(strlen(voca[i].word)));
                strcpy(wrongArray[index], voca[i].word);
                index++;
                wrongNum = 0;
            }
        }

        free(user_input);
    }

    //틀린 문자와 숫자를 출력하기.
    printf("You are wrong: %d\n", wrongSum);
    printf("You are wrong: ");
    for(i = 0; i < wrongSum; i++) {
        printf("%s ", wrongArray[i]);
        free(wrongArray[i]);
    }
    printf("\n");
}
