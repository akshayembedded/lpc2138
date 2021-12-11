#include<lpc213x.h>
#define in1 (1<<2)
#define in2 (1<<3)
#define sw (1<<14)
void main()
{
	int i;
	PINSEL0=0;
	IO0DIR=in2|in1;
	while(1)
	{
		if((IO0PIN&sw)==sw)
		{
			if(i%2==0)
			{
			IO0SET=in1;
				IO0CLR=in2;
			}
			else
			{
			IO0SET=in2;
				IO0CLR=in1;
			}
			while((IO0PIN&sw)==sw);
			i++;
		}
	}
}