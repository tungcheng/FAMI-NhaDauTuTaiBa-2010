#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
FILE *fIn, *fOut;
void main()
{
	char inName[64];
	char s[200];
	int i,dem=0,endDay=0, demNgay=251, demCP=0;
	fOut = fopen("Out.txt","w");
	do
	{
		printf("\nNhap ten file: ");
    	scanf("%63s", inName);
    	if((fIn = fopen (inName, "r")) == NULL)
    	printf("\nTen file nhap khong dung!");
	}
    while((fIn = fopen (inName, "r")) == NULL);
    while(feof(fIn)==0)
    {
    	fscanf(fIn, "%s", s);
    	if(strcmp(s,"VTO")==0) endDay = 1;
    	if(dem%3==0||dem%3==2) fprintf(fOut, "%s", s);
    	if(dem%3==0) fprintf(fOut, " ");
    	if(dem%3==2) fprintf(fOut, "\n");
    	dem++;
    	if(dem==3)
		{
	 		dem=0; demCP++;
	 		if(endDay==1)
	 		{
	 			endDay=0;
	 			demCP=0;
	 		}
		}
    }
    fclose(fIn);
    fclose(fOut);
    getch();
}
