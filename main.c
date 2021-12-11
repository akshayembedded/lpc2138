#include<lpc213x.h>
void main()
{
	int i;
	PINSEL0=0;
	PINSEL1=0;
	IO0DIR=~0;
	while(1)
	{
	IO0SET=~0;
		for(i=0;i<100000;i++);
		IO0CLR=~0;
		for(i=0;i<100000;i++);
	}
}