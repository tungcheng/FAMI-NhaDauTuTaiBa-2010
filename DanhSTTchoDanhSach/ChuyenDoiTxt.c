#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
FILE *fIn;
void main()
{
	char inName[64];
	char s[20], a[201][20];
	int i=0,j;
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
    	strcpy(a[i],s);
    	i++;
    }
    for(j=0; j<i; j++) printf("\n%d - %s", j+1, a[j]);
    fclose(fIn);
    getch();
}
