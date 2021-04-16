typedef struct
{
    char name[100]; // 제품명
    int weight; // 중량
    int price; // 가격
    int star; // 별점
    int star_num; // 별점개수
    int star_total; // 총별점
}product; // 제품의 정보를 담고있는 구조체

int selectMenu(); // 원하는 기능을 선택하는 함수

int addproduct(product *p); // 제품을 추가하는 함수
void star(product *p); // 별점 입력하는(추가하는) 함수
void readproduct(product p); // 하나의 제품을 출력하는 함수
int updateproduct(product *p); // 제품을 수정하는 함수
int deleteproduct(product *p); // 제품을 목록에서 삭제하는 함수






//void filesave(product *list, int n); // 리스트를 저장하는 함수
//int openfile(product *list); // 저장된 리스트파일을 불러오는 함수

//void searchName(product* p, int count); // 원하는 제품명을 검색하는 함수
//void searchstar(product* p, int count); // 원하는 별점의 제품을 검색하는 함수
//void searchpri(product* p, int count); // 원하는 가격의 제품을 검색하는 함

