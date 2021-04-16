#include <stdio.h>
#include "product.h"

int selectMenu(){ // 원하는 기능을 선택하는 함수
        int menu;
        printf("\n*** 과일 스토어 관리 ***\n");
        printf("1. 조회\n");
        printf("2. 추가\n");
        printf("3. 수정\n");
        printf("4. 삭제\n");
	printf("5. 별점 입력\n");
        printf("0. 종료\n\n");
        printf("=> 원하는 메뉴는? ");
        scanf("%d", &menu);
        return menu;
}
int addproduct(product *p){ // 제품을 추가하는 함수
        printf("제품명은? ");
        scanf(" %[^\n]s", p->name);
        printf("중량은(g)? ");
        scanf(" %d", &p->weight);
        printf("가격은(원)? ");
        scanf(" %d", &p->price);
	p->star = 0;
	p->star_num = 0;
	p->star_total = 0;
        return 1;
}

void star(product *p){ // 별점 입력하기
	int i = 0;
	printf("별점을 입력하세요(1~5): ");
	scanf("%d", &i);
	if(0<i && i<6){
		p->star_total += i;
		p->star_num++;
		p->star = (int)(p->star_total/p->star_num);
		printf("=> 입력 성공\n");
		return;
	}
	printf("=> 잘못된 별점입니다.\n");
	return;
}

void readproduct(product p){ // 하나의 제품을 출력하는 함수
        //printf("================================\n");
	printf("%s %dg\n", p.name, p.weight);
        printf("%d원\n", p.price);
        printf("(100g당: %d원)\n", (int)(1.0*p.price/p.weight*100));
        printf("별점: %d (%d개)\n", p.star, p.star_num);
        printf("--------------------------------\n");
}

int updateproduct(product *p){ // 제품을 수정하는 함수
        printf("제품명은? ");
        scanf(" %[^\n]s", p->name);
        printf("중량은(g)? ");
        scanf(" %d", &p->weight);
        printf("가격은(원)? ");
        scanf(" %d", &p->price);
        printf("=> 수정됨!\n");
	p->star = 0;
	p->star_num = 0;
	p->star_total = 0;
        return 1;
}
int deleteproduct(product *p){ // 제품을 목록에서 삭제하는 함수
        p->price = -1;
        printf("=> 삭제됨!\n");
        return 1;
}

//void filesave(product *list, int n); // 리스트를 저장하는 함수
//int openfile(product *list); // 저장된 리스트파일을 불러오는 함수

//void searchName(product* p, int count); // 원하는 제품명을 검색하는 함수
//void searchstar(product* p, int count); // 원하는 별점의 제품을 검색하는 함수
//void searchpri(product* p, int count); // 원하는 가격의 제품을 검색하는 함수

