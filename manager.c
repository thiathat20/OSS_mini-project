#include <stdio.h>
#include <string.h>
#include "product.h"
#include "manager.h"

void listproduct(product *p, int count){ // 전제 제품 리스트 출력
	int i = 0;
 	printf("\n*** 싱싱 과일 상회 관리 프로그램 *** \n");
 	for(i= 0; i < count; i++){
   		if(p[i].price == -1) continue;
   		printf("%2d ", i+1);
   		readproduct(p[i]);
 	}
}
int selectDataNo(product p[], int count){ // 제품 리스트중에 원하는 제품을 고르는 함수
	int no;
 	listproduct(p, count);
 	printf("번호는? (취소:0)? ");
 	scanf("%d", &no);
 	return no;
}

void filesave(product *list, int n){ // 리스트를 저장하는 함수
	FILE* pfile = fopen("fruits.txt", "wt");
	for(int i=0; i<n; i++){
		if(list[i].price == -1) continue;
		fprintf(pfile, "%s\n", list[i].name);
		fprintf(pfile, "%d ", list[i].weight);
		fprintf(pfile, "%d ", list[i].price);
		fprintf(pfile, "%d ", list[i].star);
		fprintf(pfile, "%d ", list[i].star_num);
		fprintf(pfile, "%d ", list[i].star_total);
		fprintf(pfile, "\n");
	}
	printf("==> 저장됨!\n");
	fclose(pfile);
}
int openfile(product *list){ // 저장된 리스트파일을 불러오는 함수
	FILE* pfile = fopen("fruits.txt", "rt");
	if(pfile == NULL){
		printf("==> 파일이 없습니다\n");
		return 0;
	}
	printf("==> 로딩중...\n");
	int i=0;
	for(; i<100; i++){
		fscanf(pfile, " %[^\n]s", list[i].name);
                if(feof(pfile)) break;
		fscanf(pfile, " %d", &list[i].weight);
                fscanf(pfile, " %d", &list[i].price);
                fscanf(pfile, " %d", &list[i].star);
                fscanf(pfile, " %d", &list[i].star_num);
                fscanf(pfile, " %d", &list[i].star_total);
	}
	printf("==> 로딩 성공!\n");
	fclose(pfile);
	return i;
}
void searchName(product* p, int count){ // 원하는 제품명을 검색하는 함수
	char name[100] = {0};
	printf("==> 원하는 제품명을 입력 하세요(취소:0): ");
	scanf("%s", name);
	if(strcmp(name, "0") == 0){
		printf("==> 취소되었습니다.\n");
		return;
	}
	int flag = 0;
	for(int i=0; i<count; i++){
		if(strstr(p[i].name, name)){
			printf("NO.%d) \n", i+1);
			readproduct(p[i]);
			flag = 1;
		}
	}
	if(flag == 1) printf("==>검색 성공!\n");
	else printf("==>검색 결과 없음\n");
}

void searchstar(product* p, int count){ // 원하는 별점의 제품을 검색하는 함수
	int star = 0;
        printf("==> 원하는 별점을 입력 하세요(0~5점)(취소:0~5 이외의 다른 숫자): ");
        scanf("%d", &star);
	int flag = 0;
        if(0 <= star && star <= 5){
        	for(int i=0; i<count; i++){
                	if(p[i].star == star){
                        	printf("NO.%d) \n", i+1);
                        	readproduct(p[i]);
                        	flag = 1;
                	}
        	}
	}
	else{
                printf("==> 취소되었습니다.\n");
                return;
        }
        if(flag == 1) printf("==>검색 성공!\n");
        else printf("==>검색 결과 없음\n");
}
void searchpri(product* p, int count){ // 원하는 가격의 제품을 검색하는 함수
	int min = 0, max = 0;
	int flag = 0;
	printf("최소 가격은(원)?(취소: -1): \n");
	scanf("%d", &min);
	if (min == -1){
		printf("==>취소됨\n");
		return;
	}
	printf("최대 가격은(원)?(취소: -1): \n");
        scanf("%d", &max);
	printf("\n");
	if (max == -1){
                printf("==>취소됨\n");
                return;
        }
	else if(max<min){
		printf("==>잘못된 입력!\n");
		return;
	}
	for(int i=0; i<count; i++){
		if(min <= p[i].price && p[i].price <= max){
                	printf("NO.%d) \n", i+1);
                        readproduct(p[i]);
                        flag = 1;
                }
	}
	if(flag == 1) printf("==>검색 성공!\n");
        else printf("==>검색 결과 없음\n");
}
