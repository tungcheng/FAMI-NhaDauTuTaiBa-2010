#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


FILE *fileStockList, *fileDateList, *fileMatrix, *fileOut, *fileIn;
const int MAX_STOCK = 201, MAX_DAY = 251; // 201 - 251
const float LE_PHI = 0.003;
char cStockList[MAX_STOCK+1][10], cDateList[MAX_DAY+1][15];
float fMatrix[MAX_STOCK+1][MAX_DAY+1];
float fGiaTriHienTai = 1000000, fGiaTriKiLuc = 1000000;
int iPhuongAnHienTai[MAX_DAY+1][3], iPhuongAnKiLuc[MAX_DAY+1][3];
float fGiaTriNgay[MAX_DAY+1];

//	void khoiTaoPA();
void taoStockList();
void taoDateList();
void taoMatrix();
void kiemTra();
//	void lietKeTime(int iNgay);
//	int iTimMax(int iNgayDau, int iNgayCuoi);
//	void capNhatGiaTri(float fDau, float fCuoi, int iNumber);
//	void capNhatPhuongAn(int iStock, int iNgayDau, int iNgayCuoi, int iNumber);
//	void quayLuiGiaTri(float fDau, float fCuoi, int iNumber);
//	void quayLuiPhuongAn(int iStock, int iNgayDau, int iNgayCuoi, int iNumber);
//	void capNhatKiLuc();
//	void inKetQua();

void main()
{
	//	khoiTaoPA();
	taoStockList();
	taoDateList();
	taoMatrix();
	kiemTra();
	//	lietKeTime(1);
	//	inKetQua();
}

void khoiTaoPA()
{
	int i, j;
	for(i=0; i <= MAX_DAY; i++)
	for(j=0; j < 3; j++) iPhuongAnHienTai[i][j] = 0;
}
void taoStockList()
{
	int i=1;
	char cInName[64], s[10];
	do
	{
		printf("\nNhap ten file Danh sach CP: ");
    	scanf("%63s", cInName);
    	if((fileStockList = fopen (cInName, "r")) == NULL)
    	printf("\nTen file nhap khong dung!");
	}
    while((fileStockList = fopen (cInName, "r")) == NULL);
    while(feof(fileStockList)==0)
    {
    	fscanf(fileStockList, "%s", s);
    	strcpy(cStockList[i],s);
    	i++;
    }
    fclose(fileStockList);
}

void taoDateList()
{
	int i=251;
	char cInName[64], s[15];
	do
	{
		printf("\nNhap ten file Danh sach Ngay: ");
    	scanf("%63s", cInName);
    	if((fileDateList = fopen (cInName, "r")) == NULL)
    	printf("\nTen file nhap khong dung!");
	}
	while((fileDateList = fopen (cInName, "r")) == NULL);
    while(feof(fileDateList)==0)
    {
    	fscanf(fileDateList, "%s", s);
    	strcpy(cDateList[i],s);
    	i--;
    }
    fclose(fileDateList);
}

void taoMatrix()
{
	int i,j;
	char cInName[64];
	do
	{
		printf("\nNhap ten file Ma tran Gia tri: ");
    	scanf("%63s", cInName);
    	if((fileMatrix = fopen (cInName, "r")) == NULL)
    	printf("\nTen file nhap khong dung!");
	}
	while((fileMatrix = fopen (cInName, "r")) == NULL);
    for(i=1; i <= MAX_STOCK; i++)
    for(j=1; j <= MAX_DAY; j++)
    fscanf(fileMatrix, "%f", &fMatrix[i][j]);
    fclose(fileMatrix);
}



void kiemTra()
{
	char cInName[64], cTenCP[10];
	char cNgay1[12], cNgay2[12], cGiaTri[50];
	int iSoLuong, iSttCP, iSttNgay1, iSttNgay2;
	float f = 1000000;
	fileOut = fopen("Out.txt", "w");
	
	do
	{
		printf("\nNhap ten file Phuong An Giao Dich: ");
    	scanf("%63s", cInName);
    	if((fileIn = fopen (cInName, "r")) == NULL)
    	printf("\nTen file nhap khong dung!");
	}
	while((fileIn = fopen (cInName, "r")) == NULL);
	
	while(feof(fileIn)==0)
    {
    	fscanf(fileIn, "%s", cTenCP);
    	fscanf(fileIn, "%s", cNgay1);
    	fscanf(fileIn, "%s", cNgay2);
    	fscanf(fileIn, "%d", &iSoLuong);
    	fscanf(fileIn, "%s", cGiaTri);
    	
    	for(int i=1; i<=MAX_STOCK; i++)
    		if(strcmp(cTenCP, cStockList[i])==0) iSttCP = i;
    		
   		for(int i=1; i<=MAX_DAY; i++)
   		{
   			if(strcmp(cNgay1, cDateList[i])==0) iSttNgay1 = i;
   			if(strcmp(cNgay2, cDateList[i])==0) iSttNgay2 = i;
   		}
   		
   		f = f - iSoLuong*10*fMatrix[iSttCP][iSttNgay1]*(1 + LE_PHI);
   		if(f<0) printf("\nError: f < 0");
   		f = f + iSoLuong*10*fMatrix[iSttCP][iSttNgay2]*(1 - LE_PHI);
    }
    
    printf("\nGia tri dau tu la: %f", f);
    printf("\n");
    fprintf(fileOut, "Gia tri dau tu la : %f", f);
    getch();
    system("pause");
}
