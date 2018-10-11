#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VOCA_SIZE 15

typedef struct VOCA{
    char *word;
    char *meanings;
}Voca;

int Voca_write(Voca *voca, int count) {
    count = 0;
    char temp[100];
    int i = 0;

    while(1) {
        printf("Enter word\n");
        scanf("%s", temp);
        if( *temp == 'q' )
            break;

        voca[count].word = malloc(sizeof(strlen(temp) + 1));
        strcpy(voca[count].word, temp);
        printf("Enter meanings\n");
        scanf("%s", temp);
        voca[count].meanings = malloc(sizeof(strlen(temp) + 1));
        strcpy(voca[count].meanings, temp);

        count++;
    }


    for(i = 0; i < count; i++) {
        printf("%s %s\n", voca[i].word, voca[i].meanings);
    }

    return count;
}
int main(void) {
    Voca voca[15];
    int i = 0;
    int count;
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

        for(i = 0; i < count; i++) {
            free(voca[i].word);
            free(voca[i].meanings);
        }

    } else {// 파일 읽어서 단어연습 시작하기
        // 파일을 읽어서 파일에 있는 단어 갯수 만큼 출력하기.
        char c;
        int r_count = 0;

        while(feof(fp) == 0){
            c = getc(fp);
            if(c != EOF) {
                if(c == '\n') {
                    r_count = r_count + 1;
                }
            }
        }

        rewind(fp);
       for(i = 0; i < r_count; i++) {
           voca[i].word = malloc(sizeof(char) * 10);
           voca[i].meanings = malloc(sizeof(char) * 10);
           fscanf(fp, "%s %s\n", voca[i].word, voca[i].meanings);
       }

        for(i = 0; i < r_count; i++) {
            printf("%s %s\n", voca[i].word, voca[i].meanings);
        }

        for(i = 0; i < 5; i++) {
            free(voca[i].word);
            free(voca[i].meanings);
        }


    }

    fclose(fp);
}












   // free(conn);

