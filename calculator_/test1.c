#include<p18f4580.h>

char key_pad(void);
void lcd_ini();
void lcd_data(char);
void lcd_com(char);
void Delay(int);

#define rs PORTCbits.RC0
#define e PORTCbits.RC1

char key;
char temp = 0;
long num1=0;
long num2=0;
int x=0;
long result;
int i=0;
int data[10];

void main()
{
	ADCON1=0x0f;
	TRISB = 0x0f;
	TRISD = 0x00;
	TRISCbits.RC0 = 0;
	TRISCbits.RC1 = 0;

	lcd_ini();
	
	while(1)
	{
		key = key_pad();
		if(key >= '0' && key<='9')
		{
			lcd_data(key);
			if(temp == 0)	num1=(num1*10)+(key-'0');
			else			num2=(num2*10)+(key-'0');
		}
		if(key=='/' || key=='x' || key=='-' || key=='+')
		{
			if(x==1)
			{
				lcd_com(0x01);
				if(temp=='/') result=num1/num2;
				if(temp=='x') result=num1*num2;
				if(temp=='-') result=num1-num2;
				if(temp=='+') result=num1+num2;
				num1=result;
				num2=0;
				while(result>0)
				{
					data[i++] = result % 10;
					result=result/10;
				}
				while(i>0)	lcd_data(data[--i]+'0');
			}
			x=1;
			temp=key;
			lcd_data(key);
		}
		if(key == '=')
		{
			lcd_com(0xc0);
			if(temp=='/') result=num1/num2;
			if(temp=='x') result=num1*num2;
			if(temp=='-') result=num1-num2;
			if(temp=='+') result=num1+num2;
			num1=result;
			num2=0;
			while(result>0)
			{
				data[i++] = result % 10;
				result=result/10;
			}
			while(i>0)	lcd_data(data[--i]+'0');
		}
		if(key == 'C')
		{
			lcd_com(0x01);
			x=0;
			temp=0;
			num1=0;
			num2=0;
		}
	}
}

char key_pad(void)
{
    // ROW 1
    PORTB = 0xEF;
    if(PORTB == 0xEE)
    {
        while(PORTBbits.RB0 == 0);
        return '7';
    }
    if(PORTB == 0xED)
    {
        while(PORTBbits.RB1 == 0);
        return '4';
    }
    if(PORTB == 0xEB)
    {
        while(PORTBbits.RB2 == 0);
        return '1';
    }
    if(PORTB == 0xE7)
    {
        while(PORTBbits.RB3 == 0);
        return 'C';
    }

    // ROW 2
    PORTB = 0xDF;
    if(PORTB == 0xDE)
    {
        while(PORTBbits.RB0 == 0);
        return '8';
    }
    if(PORTB == 0xDD)
    {
        while(PORTBbits.RB1 == 0);
        return '5';
    }
    if(PORTB == 0xDB)
    {
        while(PORTBbits.RB2 == 0);
        return '2';
    }
    if(PORTB == 0xD7)
    {
        while(PORTBbits.RB3 == 0);
        return '0';
    }

    // ROW 3
    PORTB = 0xBF;
    if(PORTB == 0xBE)
    {
        while(PORTBbits.RB0 == 0);
        return '9';
    }
    if(PORTB == 0xBD)
    {
        while(PORTBbits.RB1 == 0);
        return '6';
    }
    if(PORTB == 0xBB)
    {
        while(PORTBbits.RB2 == 0);
        return '3';
    }
    if(PORTB == 0xB7)
    {
        while(PORTBbits.RB3 == 0);
        return '=';
    }

    // ROW 4
    PORTB = 0x7F;
    if(PORTB == 0x7E)
    {
        while(PORTBbits.RB0 == 0);
        return '/';
    }
    if(PORTB == 0x7D)
    {
        while(PORTBbits.RB1 == 0);
        return 'x';
    }
    if(PORTB == 0x7B)
    {
        while(PORTBbits.RB2 == 0);
        return '-';
    }
    if(PORTB == 0x77)
    {
        while(PORTBbits.RB3 == 0);
        return '+';
    }

    return 0;
}

void lcd_ini()
{
	lcd_com(0x0e); //lcd on , cursor on
	lcd_com(0x01); //clear screen
	lcd_com(0x06); //inc cursor
	lcd_com(0x38); //2 line, 5x7 matrix
	lcd_com(0x80); //1st row, 1st position
}
void lcd_com(char cm)
{
	rs=0;
	PORTD = cm;
	e=1;
	Delay(10);
	e=0;
	Delay(10);
}
void lcd_data(char dt)
{
	rs=1;
	PORTD = dt;
	e=1;
	Delay(10);
	e=0;
	Delay(10);
}
void Delay(int a)
{
	int i, j;
	for(i=0; i<a; i++)
		for(j=0; j<a; j++);
}