#include<lpc213x.h>
#define in1 (1<<2)
#define in2 (1<<3)
#define sw (1<<14)
#define rs (1<<10)
#define e (1<<11)
#define d (0xff<<16)

void cmd(char a)
{int i;
	IO0CLR=rs|e|d;
	IO0SET=a<<16;
	IO0SET=e;
	for(i=0;i<100000;i++);
	IO0CLR=e;
}

void data(char a)
{int i;
	IO0CLR=rs|e|d;
	IO0SET=rs;
	IO0SET=a<<16;
	IO0SET=e;
	for(i=0;i<100000;i++);
	IO0CLR=e;
}
void display(const char *p)
{
	while(*p)
	{
	data(*p++);
	}
}
void main()
{
	int i;
	PINSEL0=0;
	IO0DIR=in2|in1|rs|d|e;
	cmd(0x38);
	cmd(0x0f);
	cmd(0x01);
	
	while(1)
	{
		if((IO0PIN&sw)==sw)
		{
			if(i%2==0)
			{
			IO0SET=in1;
			IO0CLR=in2;
				cmd(0x01);
				display("Clockwise");
			}
			else
			{
			IO0SET=in2;
			IO0CLR=in1;
				cmd(0x01);
				display("Anti-Clockwise");
			}
			while((IO0PIN&sw)==sw);
			i++;
		}
	}
}