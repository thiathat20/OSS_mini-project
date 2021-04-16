#include <stdio.h>

typedef struct
{
    char name[100]; // 제품명
    int weight; // 중량
    int price; // 가격
    int star; // 별점
    int star_num; // 별점개수
    int star_total; // 총별점
}product; // 제품의 정보를 담고있는 구조체

int selectMenu(){ // 원하는 기능을 선택하는 함수
	int menu;
	printf("\n*** 과일 스토어 관리 ***\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
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
 	return 1;
}
void readproduct(product p){ // 하나의 제품을 출력하는 함수
	printf("\t%s %dg\n", p.name, p.weight);
	printf("\t%d원\n", p.price);
	printf("\t(100g당: %d원)\n", (int)(1.0*p.price/p.weight*100));
	printf("\t별점: %d (%d개)\n", p.star, p.star_num);
	printf("---------------------------------------------\n");
}
void listproduct(product *p, int count){ // 전제 제품 리스트 출력
	int i = 0;
 	printf("=================== 리스트 ==================\n");
 	for(i= 0; i < count; i++){
   		if(p[i].price == -1) continue;
   		printf("%2d. ", i+1);
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
int updateproduct(product *p){ // 제품을 수정하는 함수
	printf("제품명은? ");
        scanf(" %[^\n]s", p->name);
        printf("중량은(g)? ");
        scanf(" %d", &p->weight);
        printf("가격은(원)? ");
        scanf(" %d", &p->price);
	printf("=> 수정됨!\n");
        return 1;
}
int deleteproduct(product *p){ // 제품을 목록에서 삭제하는 함수
	p->price = -1;
	printf("=> 삭제됨!\n");
	return 1;
}

void filesave(product *list, int n); // 리스트를 저장하는 함수
int openfile(product *list); // 저장된 리스트파일을 불러오는 함수

void searchName(product* p, int count); // 원하는 제품명을 검색하는 함수
void searchstar(product* p, int count); // 원하는 별점의 제품을 검색하는 함수
void searchpri(product* p, int count); // 원하는 가격의 제품을 검색하는 함수

int main(){
	product slist[100];
	int count=0, index = 0, menu;

 	while(1){
 		menu = selectMenu();
 		if(menu == 0) break;
 		if(menu == 1 || menu ==3 || menu == 4)
      		if(count == 0) continue;
 		if(menu == 1){
   			listproduct(slist, index);
 		}
 		else if(menu == 2)
   			count += addproduct(&slist[index++]);
 		else if(menu == 3) {
   			int no = selectDataNo(slist, index);
   			if( no > 0){
     				updateproduct(&slist[no-1]);
   			}
 		}
 		else if(menu == 4){
   			int no = selectDataNo(slist, index);
   			if( no > 0){
     				int deleteok ;
     				printf("정말로 삭제하시겠습니까?(삭제:1)");
     				scanf("%d", &deleteok);
     				if(deleteok == 1){
       					deleteproduct(&slist[no-1]);
       					count--;
     				}
   			}	
		}
	}
	return 0;
}
