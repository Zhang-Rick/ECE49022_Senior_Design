#include "Key.h"


uint8_t ReadKey(void)
{	uint8_t	key=0;
	if(!Key_UP)
	{
		DEV_Delay_ms(10);
		if(!Key_UP)
		{	
			while(!Key_UP);
			key=1;
			return	key;
		}
	}
	if(!Key_DOWN)
	{
		DEV_Delay_ms(10);
		if(!Key_DOWN)
		{	key=2;
			while(!Key_DOWN);
			return	key;
		}
	}
	if(!Key_BACK)
	{
		DEV_Delay_ms(10);
		if(!Key_BACK)
		{	key=3;
			while(!Key_BACK);
			return	key;
		}
	}
	if(!Key_OK)
	{
		DEV_Delay_ms(10);
		if(!Key_OK)
		{	key=4;
			while(!Key_OK);
			return	key;
		}
	}
	return 0;
}
