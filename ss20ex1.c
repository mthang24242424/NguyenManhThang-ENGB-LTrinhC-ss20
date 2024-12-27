#include <stdio.h>
#include <string.h>
typedef struct {
    char id[20];
    char nameBook[50];
    char author[50];
    double price;
    char genre[50]; 
} Book;
void enter(Book danhSach[],int *n);
void printBook(Book danhSach[],int *n);
void add(Book danhSach[],int *n);
void delete(Book danhSach[], int *n);
void update(Book danhSach[], int *n); 
void sort(Book danhSach[], int *n);
void search(Book danhSach[], int *n);
int main(){
    Book danhSach[50];
    int choose;
    int number;
    do{
    	printf("MENU\n1.Nhap so luong va thong tin sach\n2.Hien thi thong tin sach\n3.Them sach vao vi tri\n4.Xoa sach theo vi tri\n5.Cap nhat thong tin sach theo ma sach\n6.Sap xep sach theo gia(tang/giam)\n7.Tim kiem sach theo ten sach\n8.Thoat\nLua chon cua ban: ");
    	scanf("%d",&choose);
    	switch(choose){
    		case 1: 
    			printf("nhap so luong sach: ");
    			scanf("%d",&number);
    			fflush(stdin);
    			enter(danhSach,&number);
    			break;
    		case 2:
    			printBook(danhSach,&number);
    			break;
    		case 3:
    			add(danhSach,&number); 
    			break;
    		case 4:
    			delete(danhSach, &number);
    			break;
    		case 5:
    			update(danhSach, &number);
    			break;
    		case 6:
    			sort(danhSach, &number);
    			break;
    		case 7:
    			search(danhSach, &number);
    			break;
    		case 8:
    			printf("thoat chuong trinh");
    			break;
    		default:
    			printf("lua chon ko hop le\n");
		}
	}while(choose!=8);
    return 0;
}
void enter(Book danhSach[],int *n){
	for(int i=0;i<*n;i++){
		printf("nhap thong tin sach thu %d:\n",i+1);
		printf("nhap id sach: ");
		fgets(danhSach[i].id,20,stdin);
		danhSach[i].id[strcspn(danhSach[i].id, "\n")] = 0;
		printf("nhap ten sach: ");
		fgets(danhSach[i].nameBook,50,stdin);
		danhSach[i].nameBook[strcspn(danhSach[i].nameBook, "\n")] = 0;
		printf("nhap ten tac gia: ");
		fgets(danhSach[i].author,50,stdin);
		danhSach[i].author[strcspn(danhSach[i].author, "\n")] = 0;
		printf("nhap gia sach: ");
		scanf("%lf",&danhSach[i].price);
		fflush(stdin);
		printf("nhap the loai sach: ");
		fgets(danhSach[i].genre,50,stdin); 
		danhSach[i].genre[strcspn(danhSach[i].genre, "\n")] = 0;
		printf("-------------------------\n"); 
	}
}
void printBook(Book danhSach[],int *n){
	printf("nhung sach dang co trong thu vien:\n");
	for(int i=0;i<*n;i++){
		printf("sach thu %d\n",i+1);
		printf("ID: %s\n",danhSach[i].id);
		printf("Ten sach: %s\n",danhSach[i].nameBook);
		printf("Ten tac gia: %s\n",danhSach[i].author);
		printf("Gia tien: %.0lf\n",danhSach[i].price);
		printf("The loai: %s\n",danhSach[i].genre); 
		printf("-------------------------\n");
	}
}
void add(Book danhSach[],int *n){
	int index;
	printf("nhap vao vi tri muon them(0-%d): ",*n);
	scanf("%d",&index);
	fflush(stdin);
	if(index<0||index>*n){
		printf("vi tri ko hop le\n");
		return; 
	} 
	for(int i=*n;i>index;i--){
		danhSach[i]=danhSach[i-1]; 
	}
	printf("nhap thong tin sach can them\n");
	printf("nhap id sach: ");
	fgets(danhSach[index].id,20,stdin);
	danhSach[index].id[strcspn(danhSach[index].id, "\n")] = 0;
	printf("nhap ten sach: ");
	fgets(danhSach[index].nameBook,50,stdin);
	danhSach[index].nameBook[strcspn(danhSach[index].nameBook, "\n")] = 0;
	printf("nhap ten tac gia: ");
	fgets(danhSach[index].author,50,stdin);
	danhSach[index].author[strcspn(danhSach[index].author, "\n")] = 0;
	printf("nhap gia sach: ");
	scanf("%lf",&danhSach[index].price);
	fflush(stdin);
	printf("nhap the loai sach: ");
	fgets(danhSach[index].genre,50,stdin); 
	danhSach[index].genre[strcspn(danhSach[index].genre, "\n")] = 0;
	(*n)++;
}
void delete(Book danhSach[], int *n) {
    int index;
    printf("Nhap vao vi tri muon xoa (0-%d): ", *n - 1);
    scanf("%d", &index);
    if (index < 0 || index >= *n) {
        printf("Vi tri khong hop le\n");
        return;
    }
    for (int i = index; i < *n - 1; i++) {
        danhSach[i] = danhSach[i + 1];
    }
    (*n)--;
    printf("Da xoa sach o vi tri %d\n", index);
}
void update(Book danhSach[], int *n) {
    char id[20];
    printf("Nhap ma sach can cap nhat: ");
    fflush(stdin);
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = 0;

    for (int i = 0; i < *n; i++) {
        if (strcmp(danhSach[i].id, id) == 0) {
            printf("Nhap thong tin moi cho sach co ID %s:\n", id);
            printf("Nhap ten sach: ");
            fgets(danhSach[i].nameBook, 50, stdin);
            danhSach[i].nameBook[strcspn(danhSach[i].nameBook, "\n")] = 0;
            printf("Nhap ten tac gia: ");
            fgets(danhSach[i].author, 50, stdin);
            danhSach[i].author[strcspn(danhSach[i].author, "\n")] = 0;
            printf("Nhap gia sach: ");
            scanf("%lf", &danhSach[i].price);
            fflush(stdin);
            printf("Nhap the loai sach: ");
            fgets(danhSach[i].genre, 50, stdin);
            danhSach[i].genre[strcspn(danhSach[i].genre, "\n")] = 0;
            printf("Thong tin sach da duoc cap nhat.\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ID %s\n", id);
}
void sort(Book danhSach[], int *n) {
    int choice;
    printf("Sap xep theo gia:\n1. Tang dan\n2. Giam dan\nLua chon cua ban: ");
    scanf("%d", &choice);

    for (int i = 0; i < *n - 1; i++) {
        for (int j = i + 1; j < *n; j++) {
            if ((choice == 1 && danhSach[i].price > danhSach[j].price) ||
                (choice == 2 && danhSach[i].price < danhSach[j].price)) {
                Book temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
    printf("Da sap xep sach theo gia.\n");
}
void search(Book danhSach[], int *n) {
    char name[50];
    printf("Nhap ten sach can tim: ");
    fflush(stdin);
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;

    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (strstr(danhSach[i].nameBook, name)) {
            printf("Tim thay sach:\n");
            printf("ID: %s\n", danhSach[i].id);
            printf("Ten sach: %s\n", danhSach[i].nameBook);
            printf("Tac gia: %s\n", danhSach[i].author);
            printf("Gia: %.0lf\n", danhSach[i].price);
            printf("The loai: %s\n", danhSach[i].genre);
            printf("-------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sach nao co ten chua chuoi '%s'\n", name);
    }
}
