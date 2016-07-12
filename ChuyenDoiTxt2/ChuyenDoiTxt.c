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
    	if(dem%15<2||dem%15==5) fprintf(fOut, "%s", s);
    	if(dem%15<2) fprintf(fOut, " ");
    	if(dem%15==5) fprintf(fOut, "\n");
    	dem++;
    	if(dem==15)
		{
	 		dem=0; demCP++;
	 		if(endDay==1)
	 		{
	 			//fprintf(fOut, "-----------------------------------------------------Co: %d Ma~ CP\n", demCP);
	 			//fprintf(fOut, "-----------------------------------------------------Het ngay thu %d \n", demNgay--);
	 			endDay=0;
	 			demCP=0;
	 		}
		}
    }
    fclose(fIn);
    fclose(fOut);
    getch();
}
