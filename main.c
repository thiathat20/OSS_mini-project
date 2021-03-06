#include <stdio.h>
#include "product.h"
#include "manager.h"

#ifdef DEBUG
#define PRINT(func) func;
#else
#define PRINT(func) ;
#endif

int main(){
	PRINT(printf("==>DEBUG MODE\n"));
        product plist[100];
        int menu, count = 0;
	int index = 0;

	count = openfile(plist);
	index = count;
	
        while(1){
                menu = selectMenu();
                if(menu == 0) break;
                if(menu == 1 || menu ==3 || menu == 4 || menu ==5 || menu == 6 || menu == 7 || menu == 8 || menu == 9)
                        if(count == 0){
				printf("err: 상품 목록이 없습니다.\n");
				continue;
			}
                if(menu == 1){
                        listproduct(plist, index);
                }
                else if(menu == 2){
                        count += addproduct(&plist[index++]);
                }
                else if(menu == 3) {
			int no = selectDataNo(plist, index);
   			if( no > 0){
     				updateproduct(&plist[no-1]);
			}
                }
                else if(menu == 4){
			int no = selectDataNo(plist, index);
   			if( no > 0){
                        	int deleteok ;
                        	printf("정말로 삭제하시겠습니까?(삭제:1)");
                        	scanf("%d", &deleteok);
                        	if(deleteok == 1){
                                	deleteproduct(&plist[no-1]);
                                	count--;
                        	}
			}
                }
                else if(menu == 5){
			int no = selectDataNo(plist, index);
                        if( no > 0){
                        	star(&plist[no-1]);
                        	listproduct(plist, index);
			}
                }
		else if(menu == 6){
			filesave(plist, index);
		}
		else if(menu == 7){
			searchName(plist, index);
		}
		else if(menu == 8){
                        searchstar(plist, index);
                }
		else if(menu == 9){
                        searchpri(plist, index);
                }
        }
        return 0;
}
