#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VOCA_SIZE 15

typedef struct VOCA{
    char *word;
    char *meanings;
}Voca;

void Voca_practice(int count, Voca *voca) {
    char temp[100];
    char *user_input;
    int wrongNum = 0;
    int check = 0;
    int i,j;

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
            if(user_input[j] == '\0' && wrongNum != check ) {
                wrongSum = wrongSum + 1;
                wrongNum = 0;
            }
        }
        free(user_input);
    }

    printf("You are wrong. %d", wrongSum);

}
int Voca_write(Voca *voca, int count) {
    count = 0;
    char temp[100];
    int i = 0;

    while(1) {
        printf("Enter word\n");
        scanf("%s", temp); // 단어 입력하기
        if( *temp == 'q' )
            break;
        voca[count].word = malloc(sizeof(strlen(temp) + 1));
        strcpy(voca[count].word, temp);
        printf("Enter meanings\n");
        scanf(" %[^\n]", temp); // 의미 입력하기
        voca[count].meanings = malloc(sizeof(strlen(temp) + 1));
        strcpy(voca[count].meanings, temp);

        count++;
    }

    for(i = 0; i < count; i++) {
        printf("%s %s\n", voca[i].word, voca[i].meanings);
    }

    return count;
}


int Voca_open(FILE *fp, Voca *voca, int re_count) {
    re_count = 0;
    char ch;
    int i;

    //전체 파일 단어 갯수 알기(re_count)
    while(feof(fp) == 0){
        ch = getc(fp);
        if(ch != EOF) {
            if(ch == '\n') {
                re_count = re_count + 1;
            }
        }
    }
    rewind(fp);

    for(i = 0; i < re_count; i++) {
        char temp[100];
        char temp1[100];

        fscanf(fp, "%s %s", temp, temp1);
        voca[i].word = malloc(sizeof(char) * 10);
        voca[i].meanings = malloc(sizeof(char) * 10);
        strcpy(voca[i].word, temp);
        strcpy(voca[i].meanings, temp1);
    }

    for(i = 0; i < re_count; i++) {
        printf("%s %s\n", voca[i].word, voca[i].meanings);
    }

    return re_count;
}

int main(void) {
    Voca voca[15];
    int i;
    int count;
    int re_count;
    char answer;

    char *filename = malloc(sizeof(char) * 10);
    printf("Enter filename\n");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if(!fp) {
        // 파일이 존재하지 않으면 파일 쓰기
        count = Voca_write(voca, count);
        fp = fopen(filename, "w");

        for(i = 0; i < count; i++) {
            fprintf(fp,"%s %s\n", voca[i].word, voca[i].meanings);
        }

        printf("Do you want to game? y/n \n");
        scanf(" %c", &answer);
        if(answer == 'y') {
            Voca_practice(count, voca);
        } else {
          printf("See you again!\n");
        }

        for(i = 0; i < count; i++) {
            free(voca[i].word);
            free(voca[i].meanings);
        }

    } else {// 파일 읽어서 단어연습 시작하기
        // 파일을 읽어서 파일에 있는 단어 갯수 만큼 출력하기.
        re_count = Voca_open(fp,voca,re_count);
        Voca_practice(re_count, voca);

        for(i = 0; i < 5; i++) {
            free(voca[i].word);
            free(voca[i].meanings);
        }

    }

    fclose(fp);
}












   // free(conn);

