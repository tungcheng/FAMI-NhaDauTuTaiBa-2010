#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

FILE *fileIn, *fileOut;

void main()
{
	char cInName[64], cTenCP[10];
	char cNgay1[12], cNgay2[12], cSoLuong[20], cGiaTri[50];
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
    	fscanf(fileIn, "%s", cSoLuong);
    	fscanf(fileIn, "%s", cGiaTri);
    	
    	if((cNgay1[2]=='/')&&(cNgay1[5]=='/'))
    	{
	    	fprintf(fileOut, "%c", cNgay1[3]);
	    	fprintf(fileOut, "%c", cNgay1[4]);
	    	fprintf(fileOut, "%c", cNgay1[5]);
	    	fprintf(fileOut, "%c", cNgay1[0]);
	    	fprintf(fileOut, "%c", cNgay1[1]);
	    	fprintf(fileOut, "%c", cNgay1[2]);
	    	fprintf(fileOut, "%c", cNgay1[6]);
	    	fprintf(fileOut, "%c", cNgay1[7]);
	    	fprintf(fileOut, "%c", cNgay1[8]);
	    	fprintf(fileOut, "%c", cNgay1[9]);
    	}
    	else if((cNgay1[1]=='/')&&(cNgay1[4]=='/'))
    	{
    		fprintf(fileOut, "%c", cNgay1[2]);
	    	fprintf(fileOut, "%c", cNgay1[3]);
	    	fprintf(fileOut, "%c", cNgay1[4]);
	    	fprintf(fileOut, "0%c", cNgay1[0]);
	    	fprintf(fileOut, "%c", cNgay1[1]);
	    	fprintf(fileOut, "%c", cNgay1[5]);
	    	fprintf(fileOut, "%c", cNgay1[6]);
	    	fprintf(fileOut, "%c", cNgay1[7]);
	    	fprintf(fileOut, "%c", cNgay1[8]);
    	}
    	else if((cNgay1[2]=='/')&&(cNgay1[4]=='/'))
    	{
    		fprintf(fileOut, "0%c", cNgay1[3]);
	    	fprintf(fileOut, "%c", cNgay1[4]);
	    	fprintf(fileOut, "%c", cNgay1[0]);
	    	fprintf(fileOut, "%c", cNgay1[1]);
	    	fprintf(fileOut, "%c", cNgay1[2]);
	    	fprintf(fileOut, "%c", cNgay1[5]);
	    	fprintf(fileOut, "%c", cNgay1[6]);
	    	fprintf(fileOut, "%c", cNgay1[7]);
	    	fprintf(fileOut, "%c", cNgay1[8]);
    	}
    	else
    	{
    		fprintf(fileOut, "0%c", cNgay1[2]);
	    	fprintf(fileOut, "%c", cNgay1[3]);
	    	fprintf(fileOut, "0%c", cNgay1[0]);
	    	fprintf(fileOut, "%c", cNgay1[1]);
	    	fprintf(fileOut, "%c", cNgay1[4]);
	    	fprintf(fileOut, "%c", cNgay1[5]);
	    	fprintf(fileOut, "%c", cNgay1[6]);
	    	fprintf(fileOut, "%c", cNgay1[7]);
    	}
    	
    	fprintf(fileOut, "_M_");
    	fprintf(fileOut, "%s", cTenCP);
    	fprintf(fileOut, "_%s", cSoLuong);
    	fprintf(fileOut, "0");
    	fprintf(fileOut, "\n");
    	
    	if((cNgay2[2]=='/')&&(cNgay2[5]=='/'))
    	{
	    	fprintf(fileOut, "%c", cNgay2[3]);
	    	fprintf(fileOut, "%c", cNgay2[4]);
	    	fprintf(fileOut, "%c", cNgay2[5]);
	    	fprintf(fileOut, "%c", cNgay2[0]);
	    	fprintf(fileOut, "%c", cNgay2[1]);
	    	fprintf(fileOut, "%c", cNgay2[2]);
	    	fprintf(fileOut, "%c", cNgay2[6]);
	    	fprintf(fileOut, "%c", cNgay2[7]);
	    	fprintf(fileOut, "%c", cNgay2[8]);
	    	fprintf(fileOut, "%c", cNgay2[9]);
    	}
    	else if((cNgay2[1]=='/')&&(cNgay2[4]=='/'))
    	{
    		fprintf(fileOut, "%c", cNgay2[2]);
	    	fprintf(fileOut, "%c", cNgay2[3]);
	    	fprintf(fileOut, "%c", cNgay2[4]);
	    	fprintf(fileOut, "0%c", cNgay2[0]);
	    	fprintf(fileOut, "%c", cNgay2[1]);
	    	fprintf(fileOut, "%c", cNgay2[5]);
	    	fprintf(fileOut, "%c", cNgay2[6]);
	    	fprintf(fileOut, "%c", cNgay2[7]);
	    	fprintf(fileOut, "%c", cNgay2[8]);
    	}
    	else if((cNgay2[2]=='/')&&(cNgay2[4]=='/'))
    	{
    		fprintf(fileOut, "0%c", cNgay2[3]);
	    	fprintf(fileOut, "%c", cNgay2[4]);
	    	fprintf(fileOut, "%c", cNgay2[0]);
	    	fprintf(fileOut, "%c", cNgay2[1]);
	    	fprintf(fileOut, "%c", cNgay2[2]);
	    	fprintf(fileOut, "%c", cNgay2[5]);
	    	fprintf(fileOut, "%c", cNgay2[6]);
	    	fprintf(fileOut, "%c", cNgay2[7]);
	    	fprintf(fileOut, "%c", cNgay2[8]);
    	}
    	else
    	{
    		fprintf(fileOut, "0%c", cNgay2[2]);
	    	fprintf(fileOut, "%c", cNgay2[3]);
	    	fprintf(fileOut, "0%c", cNgay2[0]);
	    	fprintf(fileOut, "%c", cNgay2[1]);
	    	fprintf(fileOut, "%c", cNgay2[4]);
	    	fprintf(fileOut, "%c", cNgay2[5]);
	    	fprintf(fileOut, "%c", cNgay2[6]);
	    	fprintf(fileOut, "%c", cNgay2[7]);
    	}
    	
    	fprintf(fileOut, "_B_");
    	fprintf(fileOut, "%s", cTenCP);
    	fprintf(fileOut, "_%s", cSoLuong);
    	fprintf(fileOut, "0");
    	fprintf(fileOut, "\n");
    }
    fclose(fileIn);
    fclose(fileOut);
    getch();
}
