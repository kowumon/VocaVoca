#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 원하는 날짜의 파일을 읽고 쓰는 프로그램
 * 사용자는 날짜를 입력한다.
 * 사용자가 입력한 날짜가 존재하면 그 파일을 연다.
 * 존재 하지 않으면 파일을 새로 만들겠냐고 물어본다.
 * 물어보면 파일을 쓰는 tool이 시작된다.
 */
#define VOCASIZE 15

struct VOCA{
    char word[10];
    char meanings[10];
};

void die(char *messeage) {
    if(errno) {
        perror(messeage);
    }
    printf("ERROR: %s", messeage);
    exit(1);
}


//
void Voca_write(FILE* fp, struct VOCA *V)
{
    int i;
    char temp[100];
    int count = 0;

    while(1) {
        printf("Please enter a word to remember\n");
        scanf(" %s", temp);
        strcpy(V[count].word , temp);

        printf("Please enter a word-meaning\n");
        scanf(" %[^\n]", temp);
        strcpy(V[count].meanings , temp);
        count++;

        if(count == 3) {
            break;
        }
    }

    for(i = 0; i < count; i++) {
        fprintf(fp, "%s %s \n", V[i].word, V[i].meanings);
    }

}

int main(void) {
    struct VOCA V[VOCASIZE];
    int test;
    int i;
    char answer;

    char *filename = malloc(sizeof(char)*10);
    printf("Do you want to open filename?\n");
    scanf("%s", filename);

    //파일이 존재 하는지 안 하는지 판별
    FILE *fp = fopen(filename, "r");
    if(!fp) {
        printf("Create New file. y/n ? \n");
        scanf(" %c", &answer);
        if(answer == 'y') {
            fp = fopen(filename, "w");
            Voca_write(fp, V);


        }

    }

    // 파일이 존재하면 파일 읽어오기. (
    for(i = 0; i < VOCASIZE; i++) {
        fscanf(fp,"%s %s", V[i].word, V[i].meanings);
    }

    for(i = 0; i < VOCASIZE; i++) {
        printf("%s %s \n", V[i].word, V[i].meanings);
    }
    //GAME START !


}