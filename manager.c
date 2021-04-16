#include <stdio.h>
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
