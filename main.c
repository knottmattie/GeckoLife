#include <msp430.h> 

/*
 * main.c
 */
#include <stdint.h>

enum SM_States{SM_Clock,SM_Menu, SM_Food, SM_Temp}SM_State;
enum M_States{M_Init, M_HotTemp, M_ColdTemp, M_HotHumidity, M_ColdHumidity, M_FoodLog}M_State;
enum FL_States{FL_Increment, FL_Decrement} FL_State;
enum CT_States{CT_Fahrenheit, CT_Celsius, CT_Kelvin} CT_State;
enum IT_States{IT_Month, IT_Day, IT_Hour, IT_Minute} IT_State;

uint8_t months[12]={1,2,3,4,5,6,7,8,9,10,11,12};
uint8_t days[31] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
uint8_t hours[24]={0,1,2,3,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
uint8_t minutes[60]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59};

uint8_t month;
uint8_t day;
uint8_t hour;
uint8_t minute;
uint32_t counter;
uint8_t trigger=0;

uint8_t holderMo;
uint8_t holderD;
uint8_t holderH;
uint8_t holderMi;

uint8_t foodLog = 0;

void food(){
	switch(FL_State)
	{
	case FL_Increment:
		foodLog++;
		break;
	case FL_Decrement:
		foodLog--;
		break;
	default:
		break;
	}
}

void temp(){

}
void menu(){
	switch(M_State)
	{
	case M_Init:
		M_State=M_HotTemp;
		break;
	case M_HotTemp:
		//display the hot temperature
		break;
	case M_ColdTemp:
		//display cold temp
		break;
	case M_HotHumidity:
		//display the humidity
		break;
	case M_ColdHumidity:
		//display the cold humidity
		break;
	case M_FoodLog:
		break;
	default:
		break;
	}
}
void inputTime(){
	switch(IT_State)
	{
	case IT_Month:
		if (months[month]!= '\0')
		{month = month + 1;}
		else
		{month = 0;}
		//display month
		SM_State = SM_Clock;
		trigger = 0;
		break;
	case IT_Day:
		if (days[day] != '\0')
		{day = day +1;}
		else
		{day = 0;}
		//display day
		SM_State = SM_Clock;
		trigger = 0;
		break;
	case IT_Hour:
		if (hours[hour] != '\0')
		{hour = hour + 1;}
		else
		{hour=0;}
		//display hour
		SM_State = SM_Clock;
		trigger = 0;
		break;
	case IT_Minute:
		if (minutes[minute]!= '\0')
		{minute = minute + 1;}
		else
		{minute = 0;}
		//display minute
		SM_State = SM_Clock;
		trigger = 0;
		break;
	}
}

void changeThings()
{
	if (SM_State == Menu)
	{
		if (M_State == M_HotTemp){
			//update the Hot temperature
		}
		else if (M_State == M_ColdTemp){
			//update the cold temperature
		}
		else if (M_State == M_HotHumidity){
			//update the hot humidity
		}
		else if (M_State == M_ColdHumidity){
			//update the cold humidity
		}
		else{
			//do nothing
		}
	}
	else{
		//do nothing
	}
}
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5;

	P1DIR |= BIT0;						// Set LED1 as an output
	P9DIR |= BIT7;						// Set LED2 as an output

	P1OUT |= (BIT1 + BIT2);
	P1DIR &= ~(BIT1 + BIT2);
	P1REN |= (BIT1 + BIT2);
	P1IES |= (BIT1 +BIT2);
	P1IE |= (BIT1 + BIT2);
	P1IFG &= ~(BIT1+BIT2);


	__enable_interrupt();
	SM_State = SM_Clock;
	IT_State = IT_Month;
	month = day = hour = minute = 0;
	//display month with blinking 1
	while (SM_State == SM_Clock)
	{
		if (trigger == 1)
		{
			inputTime();
		}
	}
	holderMo = months[month];
	holderD = days[day];
	holderH = hours[hour];
	holderMi = minutes[minute];
	while (1)
	{
		menu();
		temp();
		food();
		changeThings();
	}
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
	switch(P1IV)
	{

	case 4:
		while ((P1IN & 0x02)==0)
		{
			counter++;
		}
		if (counter < 150000){
			if (SM_State == SM_Clock)
			{
				trigger = 1;
			}
			else if (SM_State == SM_Menu)
			{
				switch(M_State)
				{
				case M_HotTemp:
					M_State = M_FoodLog;
					break;
				case M_ColdTemp:
					M_State = M_HotTemp;
					break;
				case M_HotHumidity:
					M_State = M_ColdTemp;
					break;
				case M_ColdHumidity:
					M_State = M_HotHumidity;
					break;
				case M_FoodLog:
					M_State = M_ColdHumidity;
					break;
				default:
					break;
				}
			}
			else if (SM_State == SM_Food)
			{
				FL_State = FL_Decrement;
			}
			else if (SM_State == SM_Temp)
			{
				if (CT_State == CT_Fahrenheit){
					CT_State = CT_Celsius;
				}
				else if (CT_State == CT_Celsius){
					CT_State = CT_Kelvin;
				}
				else if (CT_State == CT_Kelvin){
					CT_State = CT_Fahrenheit;
				}
			}
		}
		else {
			if (SM_State == SM_Menu)
			{
				SM_State = SM_Temp;
			}
			else if (SM_State == SM_Temp)
			{
				SM_State = SM_Menu;
			}
			P9OUT ^= BIT7;
		}
		counter = 0;
		break;
	case 6:
		while ((P1IN & 0x04)==0)
		{
			counter++;
		}
		if (counter < 150000) {
			if (SM_State == SM_Clock) {
				switch (IT_State)
				{
				case IT_Month:
					//display
					IT_State = IT_Day;
					trigger = 1;
					break;
				case IT_Day:
					//display
					IT_State = IT_Hour;
					trigger = 1;
					break;
				case IT_Hour:
					//display
					IT_State = IT_Minute;
					trigger = 1;
					break;
				case IT_Minute:
					trigger = 1;
					SM_State = SM_Menu;
					break;
				default:
					break;
				}
			} else if (SM_State == SM_Menu) {
				switch(M_State)
				{
				case M_HotTemp:
					M_State = M_ColdTemp;
					break;
				case M_ColdTemp:
					M_State = M_HotHumidity;
					break;
				case M_HotHumidity:
					M_State = M_HotHumidity;
					break;
				case M_ColdHumidity:
					M_State = M_FoodLog;
					//display the cold humidity
					break;
				case M_FoodLog:
					M_State = M_HotTemp;
					break;
				default:
					break;
				}

			} else if (SM_State == SM_Food) {

				FL_State = FL_Increment;

			} else if (SM_State == SM_Temp) {
				if (CT_State == CT_Fahrenheit) {
					CT_State = CT_Kelvin;
				}
				else if (CT_State == CT_Celsius) {
					CT_State = CT_Fahrenheit;
				}
				else if (CT_State == CT_Kelvin) {
					CT_State = CT_Celsius;
				}
			}
		}
		else
		{
			if (SM_State == SM_Menu)
			{
				SM_State = SM_Food;
			}
			else if (SM_State == SM_Food)
			{
				SM_State = SM_Menu;
			}
			P9OUT ^= BIT7;
		}
		break;
	default:
		break;
	}
	P1IFG &= ~(BIT1+BIT2);
}


//right button interrupt vector here!

//left button interrupt vector here!
