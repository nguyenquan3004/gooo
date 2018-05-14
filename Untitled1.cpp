#include<stdio.h>
#include<string.h>
#define SIZE 100

typedef struct member{
	char name[51];
	int age;
	int ID;
	int group_ID;
} ;
typedef struct member member;

void input(member *tv)
{
	printf("Nhap vao so hieu thanh vien: ");
	scanf("%d", &tv->ID);
	while (getchar()!='\n');
	printf("Nhap vao ten thanh vien: ");
	gets(tv->name);
	printf("Nhap vao tuoi cua thanh vien: ");
	scanf("%d", &tv->age);
	while (getchar()!='\n');
	printf("Nhap vao group_ID: ");
	scanf("%d", &tv->group_ID);
	while (getchar()!='\n');
}

void output(member *tv)
{
	printf("%-35s\t%-7d\t%-5d\t%-9d\n",tv->name, tv->age, tv->ID, tv->group_ID);
}

int find(member *tv, char *ten)
{
	int count=-1;
	while (strcmp(tv->name, ten)!=0);
 	{
	tv++;
	count ++;
	}
	return count;
}

void del(member *tv)
{
	strcpy(tv->name, (tv+1)->name);
	tv->age=(tv+1)->age;
	tv->group_ID=(tv+1)->group_ID;
	tv->ID=(tv+1)->ID;
}                 

void edit(member *tv)
{
	printf("Nhap lai so hieu thanh vien: ");
	scanf("%d", &tv->ID);
	while (getchar()!='\n');
	printf("Nhap lai ten thanh vien: ");
	gets(tv->name);
	do{printf("Nhap lai tuoi cua thanh vien: ");
	scanf("%d", &tv->age);
	while (getchar()!='\n');
	if((tv->age<0)&&(tv->age>100)) printf("Nhap lai so tuoi!\n");
	}
	while((tv->age<0)&&(tv->age>110));
	printf("Nhap lai group_ID: ");
	scanf("%d", &tv->group_ID);
	while (getchar()!='\n');	
}
int main()
{
	char hoten[51];
	member tv[SIZE];
	int stt,i;
	char choice;
	//Menu
	printf("Chuong trinh quan ly thanh vien doi SVTN vien CNTT&TT: \n");
	do{
	printf("Menu: \n");
	printf("1. Nhap vao thong tin thanh vien\n");
	printf("2. In thong tin thanh vien\n");
	printf("3. Them thanh vien\n");
	printf("4. Tim kiem thong tin thanh vien\n");
	printf("5. Xoa thanh vien\n");
	printf("6. Chinh sua thong tin thanh vien\n");
	printf("7. Thoat\n");
	printf("Moi ban nhap vao lua chon: ");
	scanf("%c", &choice);
	while(getchar()!='\n');
	switch (choice)
	{
		case '1': printf("Nhap vao thong tin thanh vien\n");
			printf("Nhap vao so thanh vien nhap vao: ");
			scanf("%d", &stt);
			while (getchar()!='\n');
			for (i=0; i<stt; i++)
				{printf("Nhap vao thong tin thanh vien thu %d\n", i+1);
				input(&tv[i]);}
			printf("\n");
			break;
		case '2': printf("In thong tin thanh vien\n");
			int i;
			printf("%-35s\t%-7s\t%-5s\t%-9s\n", "Ho ten", "Tuoi", "ID", "Group_ID");
			for (i=0; i<stt; i++)
			output(&tv[i]);
			printf("\n");
			break;
		case '3': printf("Them thanh vien\n");
			stt++;
			input(&tv[stt-1]);
			printf("\n");
			break;
		case '4': printf("Tim kiem thong tin thanh vien\n");
			printf("Nhap vao ten thanh vien can tim: ");
			gets(hoten);
			printf("%-35s\t%-7s\t%-5s\t%-9s\n", "Ho ten", "Tuoi", "ID", "Group_ID");
			output(&tv[find( tv, hoten)]); 
			printf("\n");
			break;
		case '5': printf("Xoa thanh vien:\n");
			printf("Nhap vao ten thanh vien can xoa: ");
			gets(hoten);
			int num;
			stt--;
			num=find(tv, hoten);
			for (i=num; i<stt;i++)
				del(&tv[i]);
			printf("Da xoa thanh vien!\n");
			printf("\n");
			break;
		case '6': printf("Chinh sua thong tin thanh vien:\n"); 
			printf("Nhap ten thanh vien can sua thong tin: ");
			gets(hoten);
			num=find(tv, hoten);
			edit(&tv[num]);
			printf("Da sua xong thong tin thanh vien! \n");
			printf("\n");
			break;
		case '7': printf("Ban da chon che do thoat khoi chuong trinh!\n"); break;
		default:  printf("Moi ban nhap lai lua chon tu 1 den 7!\n"); break;
	}
		}while (choice!='7');
	return 0;
}
