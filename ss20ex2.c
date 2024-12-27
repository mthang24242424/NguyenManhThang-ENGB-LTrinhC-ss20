#include <stdio.h>
#include <string.h>

typedef struct {
    char id[20];
    char name[50];
    double importPrice;
    double sellPrice;
    int quantity;
} Shop;

void enter(Shop menu[], int *n);
void display(Shop menu[], int n);
void addProduct(Shop menu[], int *n);
void update(Shop menu[], int n);
void sort(Shop menu[], int n);
void search(Shop menu[], int n);
void sell(Shop menu[], int n, double *revenue);
void calculateRevenue(double revenue);

int main() {
    Shop menu[50];
    int n = 0;
    double revenue = 0;
    int choose;

    do {
        printf("\nMENU\n");
        printf("1. Nhap thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia (tang/giam)\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham (co the nhap so luong ban)\n");
        printf("8. Doanh thu hien tai\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Nhap so luong san pham: ");
                scanf("%d", &n);
                fflush(stdin);
                enter(menu, &n);
                break;
            case 2:
                display(menu, n);
                break;
            case 3:
                addProduct(menu, &n);
                break;
            case 4:
                update(menu, n);
                break;
            case 5:
                sort(menu, n);
                break;
            case 6:
                search(menu, n);
                break;
            case 7:
                sell(menu, n, &revenue);
                break;
            case 8:
                printf("Doanh thu hien tai: %.2lf\n", revenue);
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choose != 9);

    return 0;
}

void enter(Shop menu[], int *n) {
    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin san pham thu %d:\n", i + 1);
        printf("ID: ");
        fgets(menu[i].id, 20, stdin);
        menu[i].id[strcspn(menu[i].id, "\n")] = 0;
        printf("Ten san pham: ");
        fgets(menu[i].name, 50, stdin);
        menu[i].name[strcspn(menu[i].name, "\n")] = 0;
        printf("Gia nhap: ");
        scanf("%lf", &menu[i].importPrice);
        printf("Gia ban: ");
        scanf("%lf", &menu[i].sellPrice);
        printf("So luong: ");
        scanf("%d", &menu[i].quantity);
        fflush(stdin);
    }
}

void addProduct(Shop menu[], int *n) {
    printf("Nhap thong tin san pham moi:\n");
    printf("ID: ");
    fflush(stdin);
    fgets(menu[*n].id, 20, stdin);
    menu[*n].id[strcspn(menu[*n].id, "\n")] = 0;
    printf("Ten san pham: ");
    fgets(menu[*n].name, 50, stdin);
    menu[*n].name[strcspn(menu[*n].name, "\n")] = 0;
    printf("Gia nhap: ");
    scanf("%lf", &menu[*n].importPrice);
    printf("Gia ban: ");
    scanf("%lf", &menu[*n].sellPrice);
    printf("So luong: ");
    scanf("%d", &menu[*n].quantity);
    fflush(stdin);
    (*n)++;
    printf("Da them san pham moi thanh cong.\n");
}

void display(Shop menu[], int n) {
    printf("\nDanh sach san pham:\n");
    for (int i = 0; i < n; i++) {
        printf("San pham thu %d:\n", i + 1);
        printf("ID: %s\n", menu[i].id);
        printf("Ten: %s\n", menu[i].name);
        printf("Gia nhap: %.2lf\n", menu[i].importPrice);
        printf("Gia ban: %.2lf\n", menu[i].sellPrice);
        printf("So luong: %d\n", menu[i].quantity);
        printf("-------------------\n");
    }
}

void update(Shop menu[], int n) {
    char id[20];
    printf("Nhap ID san pham can cap nhat: ");
    fflush(stdin);
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(menu[i].id, id) == 0) {
            printf("Nhap thong tin moi:\n");
            printf("Ten san pham: ");
            fgets(menu[i].name, 50, stdin);
            menu[i].name[strcspn(menu[i].name, "\n")] = 0;
            printf("Gia nhap: ");
            scanf("%lf", &menu[i].importPrice);
            printf("Gia ban: ");
            scanf("%lf", &menu[i].sellPrice);
            printf("So luong: ");
            scanf("%d", &menu[i].quantity);
            printf("Da cap nhat thong tin san pham.\n");
            return;
        }
    }
    printf("Khong tim thay san pham voi ID: %s\n", id);
}

void sort(Shop menu[], int n) {
    int choice;
    printf("Sap xep theo gia:\n1. Tang dan\n2. Giam dan\nLua chon cua ban: ");
    scanf("%d", &choice);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((choice == 1 && menu[i].sellPrice > menu[j].sellPrice) ||
                (choice == 2 && menu[i].sellPrice < menu[j].sellPrice)) {
                Shop temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }
    printf("Da sap xep san pham theo gia.\n");
}

void search(Shop menu[], int n) {
    char name[50];
    printf("Nhap ten san pham can tim: ");
    fflush(stdin);
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < n; i++) {
        if (strstr(menu[i].name, name)) {
            printf("ID: %s\n", menu[i].id);
            printf("Ten: %s\n", menu[i].name);
            printf("Gia nhap: %.2lf\n", menu[i].importPrice);
            printf("Gia ban: %.2lf\n", menu[i].sellPrice);
            printf("So luong: %d\n", menu[i].quantity);
            printf("-------------------\n");
        }
    }
}

void sell(Shop menu[], int n, double *revenue) {
    char id[20];
    int quantity;

    printf("Nhap ID san pham can ban: ");
    fflush(stdin);
    fgets(id, 20, stdin);
    id[strcspn(id, "\n")] = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(menu[i].id, id) == 0) {
            printf("Nhap so luong can ban: ");
            scanf("%d", &quantity);
            if (quantity > menu[i].quantity) {
                printf("Khong du hang de ban!\n");
            } else {
                menu[i].quantity -= quantity;
                *revenue += quantity * menu[i].sellPrice;
                printf("Ban thanh cong %d san pham '%s'.\n", quantity, menu[i].name);
            }
            return;
        }
    }
    printf("Khong tim thay san pham voi ID: %s\n", id);
}

void calculateRevenue(double revenue) {
    printf("Doanh thu hien tai: %.2lf\n", revenue);
}
