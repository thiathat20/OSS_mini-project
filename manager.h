void listproduct(product *p, int count); // 전제 제품 리스트 출력
int selectDataNo(product p[], int count); // 제품 리스트중에 원하는 제품을 고르는 함수

void filesave(product *list, int n); // 리스트를 저장하는 함수
int openfile(product *list); // 저장된 리스트파일을 불러오는 함수

void searchName(product* p, int count); // 원하는 제품명을 검색하는 함수
void searchstar(product* p, int count); // 원하는 별점의 제품을 검색하는 함수
void searchpri(product* p, int count); // 원하는 가격의 제품을 검색하는 함
