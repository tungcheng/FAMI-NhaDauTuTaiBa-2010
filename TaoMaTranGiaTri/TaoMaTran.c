#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
FILE *fIn, *fOut,*fDanhSach;
void main()
{
	char inName[64];
	char s[20], a[201][20];
	float b[202][252];
	float giaCP;
	int i=0, j, dem=0, endDay=0, demNgay=251;
	fOut = fopen("Out.txt","w");
	do
	{
		printf("\nNhap ten file CP va Gia: ");
    	scanf("%63s", inName);
    	if((fIn = fopen (inName, "r")) == NULL)
    	printf("\nTen file nhap khong dung!");
	}
    while((fIn = fopen (inName, "r")) == NULL);
    
    do
	{
		printf("\nNhap ten file Danh sach CP: ");
    	scanf("%63s", inName);
    	if((fDanhSach = fopen (inName, "r")) == NULL)
    	printf("\nTen file nhap khong dung!");
	}
    while((fDanhSach = fopen (inName, "r")) == NULL);
    
    while(feof(fDanhSach)==0)
    {
    	fscanf(fDanhSach, "%s", s);
    	strcpy(a[i],s);
    	i++;
    }
    
    for(i=0; i < 200; i++) printf("\n %s", a[i]);
    
 	for(i=0; i < 200; i++)
 	for(j=0; j < 251; j++) b[i][j]=0;
 	
    while(feof(fIn)==0)
    {
    	fscanf(fIn, "%s", s);
    	fscanf(fIn, "%f", &giaCP);
    	if(strcmp(s,"VTO")==0) endDay = 1;
    	for(i=0; i < 200; i++)
    		if(strcmp(s, a[i])==0)
    		{
    			b[i][demNgay-1]=giaCP;

    		}
		if(endDay==1)
		{
			endDay=0;
			demNgay--;
		}
    }
    for(i=0; i < 200; i++)
    {
    	fprintf(fOut, "\n");
 		for(j=0; j < 250; j++) fprintf(fOut, "%g ", b[i][j]);
 		fprintf(fOut, "%g", b[i][250]);
    }
    fclose(fIn);
    fclose(fOut);
    fclose(fDanhSach);
    getch();
}
