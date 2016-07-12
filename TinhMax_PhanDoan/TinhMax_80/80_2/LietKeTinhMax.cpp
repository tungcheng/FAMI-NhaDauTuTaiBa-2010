#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


FILE *fileStockList, *fileDateList, *fileMatrix, *fileOut;
const int MAX_STOCK = 201, MAX_DAY = 251; // 201 - 251
const float LE_PHI = 0.003;
char cStockList[MAX_STOCK+1][10], cDateList[MAX_DAY+1][15];
float fMatrix[MAX_STOCK+1][MAX_DAY+1];
float fGiaTriHienTai = 99051752, fGiaTriKiLuc = 99051752;
int iPhuongAnHienTai[MAX_DAY+1][3], iPhuongAnKiLuc[MAX_DAY+1][3];
float fGiaTriNgay[MAX_DAY+1];

void khoiTaoPA();
void taoStockList();
void taoDateList();
void taoMatrix();
void lietKeTime(int iNgay);
int iTimMax(int iNgayDau, int iNgayCuoi);
void capNhatGiaTri(float fDau, float fCuoi, int iNumber);
void capNhatPhuongAn(int iStock, int iNgayDau, int iNgayCuoi, int iNumber);
void quayLuiGiaTri(float fDau, float fCuoi, int iNumber);
void quayLuiPhuongAn(int iStock, int iNgayDau, int iNgayCuoi, int iNumber);
void capNhatKiLuc();
void inKetQua();

void main()
{
	fileOut = fopen("PhuongAn.txt", "w");
	printf("\nRunning...");
	khoiTaoPA();
	taoStockList();
	taoDateList();
	taoMatrix();
	lietKeTime(163);
	inKetQua();
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
		//printf("\nNhap ten file Danh sach CP: ");
    	//scanf("%63s", cInName);
    	strcpy(cInName, "DSCP.txt");
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
		//printf("\nNhap ten file Danh sach Ngay: ");
    	//scanf("%63s", cInName);
    	strcpy(cInName, "DSNgay.txt");
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
		//printf("\nNhap ten file Ma tran Gia tri: ");
    	//scanf("%63s", cInName);
    	strcpy(cInName, "Matrix.txt");
    	if((fileMatrix = fopen (cInName, "r")) == NULL)
    	printf("\nTen file nhap khong dung!");
	}
	while((fileMatrix = fopen (cInName, "r")) == NULL);
    for(i=1; i <= MAX_STOCK; i++)
    for(j=1; j <= MAX_DAY; j++)
    fscanf(fileMatrix, "%f", &fMatrix[i][j]);
    fclose(fileMatrix);
}

void lietKeTime(int iNgay)
{
	int j, iStock, iNumber;
	float fDau, fCuoi, fHienTai;
	for(j=3; ((iNgay + j <= 251)&&(j<=40)); j++) 
	{
		//if((iNgay==1)||(iNgay==2)||(iNgay==3)||(iNgay==4)||(iNgay==5)||(iNgay==6)) 
		//fGiaTriHienTai = 1000000.0;
		//printf("\n%f", fGiaTriHienTai);
		
		if(iNgay == 1)
		{
			//lietKeTime(2);
			//lietKeTime(3);
			//lietKeTime(4);
			//lietKeTime(5);
			//lietKeTime(6);
		}
		
		iStock = iTimMax(iNgay, iNgay+j);
		fDau = fMatrix[iStock][iNgay];
		fCuoi = fMatrix[iStock][iNgay+j];
		fHienTai = fGiaTriHienTai;
		
		//if((iNgay >  80)&&(fGiaTriHienTai <  23500000.0)) break;	//4844667.0		5/5/2009
		//if((iNgay > 160)&&(fGiaTriHienTai < 235000000.0)) break;	//40171132.0	8/25/2009
				
		//if((iNgay >  50)&&(fGiaTriHienTai <   4200000.0)) break;	//	3/19/2009
		//if((iNgay > 100)&&(fGiaTriHienTai <  17000000.0)) break;	//	6/2/2009
		//if((iNgay > 150)&&(fGiaTriHienTai <  68000000.0)) break;	//	8/11/2009
		//if((iNgay > 200)&&(fGiaTriHienTai < 380000000.0)) break;	//	10/21/2009
				
		if((fCuoi > fDau)&&(fDau>0)&&(fCuoi>0))
		{
			iNumber = int(fHienTai/fDau)/10;
			while(fHienTai < 10*fDau*iNumber*(1+LE_PHI)) iNumber -= 1;
			iNumber = iNumber - iNumber/3000;
			fHienTai = fHienTai + 10*iNumber*(fCuoi-fDau) - 10*iNumber*(fDau+fCuoi)*LE_PHI;
			fGiaTriHienTai = fHienTai;
			capNhatPhuongAn(iStock, iNgay, iNgay+j, iNumber);
		}
		//&&(fGiaTriHienTai > 200000000.0)		
		if((iNgay + j + 3 > 251)) capNhatKiLuc();
		else if (iNgay + j + 3 <= 251) lietKeTime(iNgay + j + 3);
				
		if((fCuoi > fDau)&&(fDau>0)&&(fCuoi>0))
		{
			quayLuiGiaTri(fDau, fCuoi, iNumber);
			quayLuiPhuongAn(iStock, iNgay, iNgay+j, iNumber);
		}
		
		
	}
}

int iTimMax(int iNgayDau, int iNgayCuoi)
{
	int iMax = 1, iNumber, i;
	float fHienTai = fGiaTriHienTai, fMax = 0, fDau, fCuoi, fLoiNhuan;
	for(i=1; i <= MAX_STOCK; i++)
	{
		fCuoi = fMatrix[i][iNgayCuoi];
		fDau = fMatrix[i][iNgayDau];
		if((fDau > 0)&&(fDau < fCuoi)&&(fCuoi>0))
		{
			iNumber = int(fHienTai/fDau)/10;
			while(fHienTai < 10*fDau*iNumber*(1+LE_PHI)) iNumber -= 1;
			fLoiNhuan = 10*iNumber*(fCuoi - fDau);
			if(fLoiNhuan > fMax)
			{
				iMax = i;
				fMax = fLoiNhuan;
			}
		}
	}
	return iMax;
}

void capNhatGiatri(float fDau, float fCuoi, int iNumber)
{
	float fHienTai = fGiaTriHienTai;
	fHienTai = fHienTai + 10*iNumber*(fCuoi-fDau) - 10*iNumber*(fDau+fCuoi)*LE_PHI;
	fGiaTriHienTai = fHienTai;
}

void capNhatPhuongAn(int iStock, int iNgayDau, int iNgayCuoi, int iNumber)
{
	iPhuongAnHienTai[iNgayDau][0] = iStock;
	iPhuongAnHienTai[iNgayDau][1] = iNgayCuoi;
	iPhuongAnHienTai[iNgayDau][2] = iNumber;
	fGiaTriNgay[iNgayDau] = fGiaTriHienTai;
}

void quayLuiGiaTri(float fDau, float fCuoi, int iNumber)
{
	float fHienTai = fGiaTriHienTai;
	fHienTai = fHienTai - 10*iNumber*(fCuoi-fDau) + 10*iNumber*(fDau+fCuoi)*LE_PHI;
	fGiaTriHienTai = fHienTai;
}

void quayLuiPhuongAn(int iStock, int iNgayDau, int iNgayCuoi, int iNumber)
{
	iPhuongAnHienTai[iNgayDau][0] = 0;
	iPhuongAnHienTai[iNgayDau][1] = 0;
	iPhuongAnHienTai[iNgayDau][2] = 0;
	fGiaTriNgay[iNgayDau] = 0;
}

void capNhatKiLuc()
{
	int i,j;
	if(fGiaTriHienTai > fGiaTriKiLuc)
	{
		for(i=0; i <= MAX_DAY; i++)
		for(j=0; j<3; j++)
		iPhuongAnKiLuc[i][j] = iPhuongAnHienTai[i][j];
		fGiaTriKiLuc = fGiaTriHienTai;
		fprintf(fileOut, "\n");
		for(i=1; i<=MAX_DAY; i++)
		if(iPhuongAnKiLuc[i][0] != 0)
		{
			fprintf(fileOut,"\n%s ", cStockList[iPhuongAnKiLuc[i][0]]);
			fprintf(fileOut,"%s ", cDateList[i]);
			fprintf(fileOut,"%s ", cDateList[iPhuongAnKiLuc[i][1]]);
			fprintf(fileOut,"%d ", iPhuongAnKiLuc[i][2]);
			fprintf(fileOut,"%f", fGiaTriNgay[i]);
		}
		fprintf(fileOut, "\n--->Phuong an ki luc ung voi gia tri: %f", fGiaTriKiLuc);
		printf("\nDa cap nhat ki luc: %f", fGiaTriKiLuc);
	}
}

void inKetQua()
{
	int i,j;
	printf("GIA TRI MAX LA: %f", fGiaTriKiLuc);
	fprintf(fileOut, "\n");
	for(i=1; i<=MAX_DAY; i++)
	{
		if(iPhuongAnKiLuc[i][0] != 0)
		{
			fprintf(fileOut,"\n%s ", cStockList[iPhuongAnKiLuc[i][0]]);
			fprintf(fileOut,"%s ", cDateList[i]);
			fprintf(fileOut,"%s ", cDateList[iPhuongAnKiLuc[i][1]]);
			fprintf(fileOut,"%d", iPhuongAnKiLuc[i][2]);
		}
	}
	fprintf(fileOut, "\n-->PHUONG AN GIAO DICH MAX UNG VOI GIA TRI: %f", fGiaTriKiLuc);
	fclose(fileOut);
	getch();
	system("pause");
}
