#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100

typedef struct{
    char maSach[6];
    char name[max];
    char tacGia[max];
    float gia;
    char theLoai[max];
}book;

void menu();
void inFile(book *b, int size);
void addBook(book b[], int *count);//case 1
void update(book b[], int count);//case 2
void delete(book b[],int *count);//case 3
void outp(book b[], int size);//case 4
void giaTang(book b[], int count);//case 5
void giaGiam(book b[], int count);//case 6
void timByTacGia(book b[], int count); //case 7
void timByGia(book b[], int count);//case 8
void xoaDuLieu();//case 9
int main(){


        int choice, count = 0;
        book b[max];
        char input[10];// mảng lưu chuỗi kí từ được nhập
        char *endptr;  // Con trỏ để kiểm tra xem có lỗi hay không

        do {
            menu();
            printf("choose (0-9): ");
            fflush(stdin);
            fgets(input, sizeof(input), stdin);

            // Chuyển đổi chuỗi thành số nguyên
            choice = strtol(input, &endptr, 10);

            // Kiểm tra giá trị trả về và xem có lỗi hay không
            if (*endptr != '\0' && *endptr != '\n') //chỉ vô chữ
            {
                printf("Nhap sai! Vui long nhap lai.\n");
                continue;  // Lặp lại vòng lặp do-while để yêu cầu người dùng nhập lại
            }



            switch (choice){
            case 1:
                addBook( b, &count);
                inFile(b,count);
                break;
            case 2:
                update(b, count);
                break;
            case 3:
                delete(b, &count);
                break;
            case 4:
                outp(b, count);
                break;
            case 5:
                giaTang(b,count);
                break;
            case 6:
                giaGiam(b,count);
                break;
            case 7:
                timByTacGia(b,count);
                break;
            case 8:
                timByGia(b,count);
                break;
            case 0:
                xoaDuLieu();
                break;
            case 9:
                printf("Chuong trinh da thoat!!");
                break;
            default:
                printf("Nhap sai!\n Vui long nhap lai!\n");

        }
    }while (choice!=9);

    return 0;
}

void menu() {
    printf ("CHUONG TRINH QUAN LY SACH C/C++\n");
    printf ("*************************MENU**************************\n");
    printf ("**  0. Xoa sach.                                     **\n");
    printf ("**  1. Them sach.                                    **\n");
    printf ("**  2. Cap nhat thong tin sach boi ID.               **\n");
    printf ("**  3. Xoa sach boi ID.                              **\n");
    printf ("**  4. Hien thi thong tin sach.                      **\n");
    printf ("**  5. Sap xep sach theo gia tang dan.               **\n");
    printf ("**  6. Sap xep sach theo gia giam dan.               **\n");
    printf ("**  7. Tim kiem sach theo ten tac gia.               **\n");
    printf ("**  8. Tim kiem sach theo khoang gia.                **\n");
    printf ("**  9. Thoat.                                        **\n");
    printf ("*******************************************************\n");
}

void vietHoa(char *str) //viet hoa chu cai dau
{

    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 || (i > 0 && str[i - 1] == ' ')) {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

void addBook(book b[], int *count) // case 1
{
    char tieptuc;
    do {
        if (*count < max) {
            printf("Nhap thong tin sach muon them vao:\n ");
            printf("Nhap ma sach (5 ki tu): ");
            fflush(stdin);//loại bỏ bất kỳ ký tự nào còn lại trong bộ đệm sau khi người dùng nhập lựa chọn số từ bàn phím.
            fgets(b[*count].maSach, sizeof(b[*count].maSach), stdin);
            b[*count].maSach[strcspn(b[*count].maSach, "\n")] = '\0';// tìm vị trí đầu tiên của kí tự xuống dòng trong chuỗi
            //Nếu không tìm thấy, sẽ trả về chuỗi


            while(strlen(b[*count].maSach)!=5){
                printf("Ma sach phai co 5 ki tu.\n Nhap lai:\n  Nhap ma sach (5 ki tu): ");
                scanf("%s",b[*count].maSach);
            }

            printf("Nhap ten sach (10 ki tu tro len): ");
            fflush(stdin);
            fgets(b[*count].name, sizeof(b[*count].name), stdin);
            b[*count].name[strcspn(b[*count].name, "\n")] = '\0';


            while(strlen(b[*count].name) < 10){
                printf("Ten sach phai co it nhat 10 ky tu.\n Nhap lai:\n  Nhap ten sach (10 ki tu tro len): ");
                fflush(stdin);
                fgets(b[*count].name, sizeof(b[*count].name), stdin);
                b[*count].name[strcspn(b[*count].name, "\n")] = '\0';
            }


            vietHoa(b[*count].name);

            printf("Nhap ten tac gia: ");
            fflush(stdin);
            fgets(b[*count].tacGia, sizeof(b[*count].tacGia), stdin);
            b[*count].tacGia[strcspn(b[*count].tacGia, "\n")] = '\0';

            printf("Nhap gia (>= 1000): ");
            scanf("%f", &b[*count].gia);


            while (b[*count].gia < 1000) {
                printf("Gia sach phai lon hon hoac bang 1000.\n Nhap lai:\n Nhap gia (>= 1000):  ");
                scanf("%f", &b[*count].gia);
            }

            printf("Nhap the loai: ");
            fflush(stdin);
            fgets(b[*count].theLoai, sizeof(b[*count].theLoai), stdin);
            b[*count].theLoai[strcspn(b[*count].theLoai, "\n")] = '\0';

            (*count)++;
            printf("Successfully added\n");

            printf("Ban co muon nhap them khong (Y/N): ");
            fflush(stdin);
            scanf(" %c", &tieptuc);
        } else {
            printf("Khong the bo sung thong tin\n");
            break;
        }
    } while (tieptuc == 'y' || tieptuc == 'Y');
    ++count;
}

void update(book b[], int count) // case 2
{
    char timNoiDung[100];
    printf("Nhap ma sach muon cap nhap: ");
    fflush(stdin);
    fgets(timNoiDung, sizeof(timNoiDung), stdin);
    timNoiDung[strcspn(timNoiDung, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(b[i].maSach, timNoiDung) == 0) {
            printf("Ma sach: ");
            fflush(stdin);
            fgets(b[i].maSach, sizeof(b[i].maSach), stdin);
            b[i].maSach[strcspn(b[i].maSach, "\n")] = '\0';

            printf("Ten sach: ");
            fflush(stdin);
            fgets(b[i].name, sizeof(b[i].name), stdin);
            b[i].name[strcspn(b[i].name, "\n")] = '\0';

            printf("Tac gia: ");
            fflush(stdin);
            fgets(b[i].tacGia, sizeof(b[i].tacGia), stdin);
            b[i].tacGia[strcspn(b[i].tacGia, "\n")] = '\0';

            printf("Gia sach: ");
            scanf("%f", &b[i].gia);

            printf("The loai: ");
            fflush(stdin);
            fgets(b[i].theLoai, sizeof(b[i].theLoai), stdin);
            b[i].theLoai[strcspn(b[i].theLoai, "\n")] = '\0';

            printf("Cap nhat thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay mang co noi dung \"%s\"\n", timNoiDung);
}

void delete(book b[], int *count) //case 3
{
    char timNoiDung[100];
    printf("Nhap ma so cua sach ban muon xoa: ");
    scanf(" %[^\n]s", timNoiDung);

    for (int i = 0; i < *count; ++i) {
        if (strcmp(b[i].maSach, timNoiDung) == 0) {
            for (int j = i; j < *count - 1; ++j) {
                b[j] = b[j + 1];
            }
            (*count)--;
            printf("Thong tin sach ban chon da duoc xoa thanh cong!\n");
            return;
        }
    }

    printf("Khong tim thay sach co noi dung \"%s\"\n", timNoiDung);
}

void outp(book b[], int size) //case 4
{
    printf("\n| %-10s | %-18s | %-13s | %-13s | %-13s |\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
    printf("|---------------------------------------------------------------------------------|\n");
    for (int i = 0; i < size; ++i) {
        printf("| %-10s | %-18s | %-13s | %-13.2f | %-13s |\n",
               b[i].maSach,
               b[i].name,
               b[i].tacGia,
               b[i].gia,
               b[i].theLoai);
    }

    inFile(b, size);
}

void inFile(book *b, int size)

{
    FILE *fp = fopen("book.txt","w");
    if (fp != NULL) {
        fprintf(fp,"\n| %-10s | %-18s | %-13s | %-13s | %-13s |\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
        fprintf(fp,"|---------------------------------------------------------------------------------|\n");
        for (int i = 0; i < size; i++) {
            fprintf(fp,"| %-10s | %-18s | %-13s | %-13.2f | %-13s |\n",
                    b[i].maSach,
                    b[i].name,
                    b[i].tacGia,
                    b[i].gia,
                    b[i].theLoai);
        }
        fclose(fp);
    }
    if (fclose(fp) == 0) {
        printf("Du lieu da duoc ghi vao tep tin.\n");
    }
}

void giaTang(book b[], int count) {
    int i;
    for ( i =0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (b[i].gia > b[j].gia) {
                book temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    outp(b,count);
    printf("Danh sach da duoc sap xep tang dan theo gia tien!\n");
}

void giaGiam(book b[],int count) {
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (b[i].gia < b[j].gia) {
                book temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    outp(b,count);
    printf("Danh sach da duoc sap xep giam dan theo gia tien!\n");
}

void timByTacGia(book b[], int count) //case 7
{
    char tacGia[max];
    printf("Nhap tac gia cua sach muon tim: ");
    fflush(stdin);
    fgets(tacGia, sizeof(tacGia), stdin);
    tacGia[strcspn(tacGia, "\n")] = '\0';
    printf("\n| %-10s | %-18s | %-13s | %-13s | %-13s |\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
    printf("|---------------------------------------------------------------------------------|\n");
    int x=0;
    for (int i = 0; i < count; ++i) {
        if (strstr(b[i].tacGia, tacGia) != NULL) {
            printf("| %-10s | %-18s | %-13s | %-13.2f | %-13s |\n",
                   b[i].maSach,
                   b[i].name,
                   b[i].tacGia,
                   b[i].gia,
                   b[i].theLoai);
            x = 1;
        }
    }

    if (!x) {
        printf("Khong tim thay sach cua tac gia \"%s\"\n", tacGia);
    }
}

void timByGia(book b[], int count)
{
    float nho, lon;
    printf("Nhap khoang gia muon tim kiem (Gia nho nhat - Gia lon nhat): ");
    scanf("%f %f", &nho, &lon);

    printf("\n| %-10s | %-18s | %-13s | %-13s | %-13s |\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
    printf("|---------------------------------------------------------------------------------|\n");

    int y = 0;
    printf("Sach trong khoang gia %.2f - %.2f\n", nho, lon);
    for (int i = 0; i < count; ++i) {
        if (b[i].gia >= nho && b[i].gia <= lon) {
            printf("| %-10s | %-18s | %-13s | %-13.2f | %-13s |\n",
                   b[i].maSach,
                   b[i].name,
                   b[i].tacGia,
                   b[i].gia,
                   b[i].theLoai);
            y = 1;
        }
    }

    if (!y) {
        printf("Khong tim thay sach trong khoang gia %.2f - %.2f\n", nho, lon);
    }
}


void xoaDuLieu() {
    FILE *file = fopen("book.txt", "w");

    if (file != NULL) {
        fclose(file);
        printf("Da xoa du lieu trong file book.txt.\n");
    }
}