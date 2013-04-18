//Magnetometr Jan Chroust 2013
//vypise hodnoty jednotlivych os

#include "main.h"

#define EEPROM_SDA  PIN_B0
#define EEPROM_SCL  PIN_B1
#use i2c(master, sda=EEPROM_SDA, scl=EEPROM_SCL)
#use rs232(baud=9600,parity=N,xmit=PIN_B3,rcv=PIN_B2,bits=8) //rcv TXD xmit RXD

#include "HMC5883L.h"
void main()
{

   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_ccp1(CCP_OFF);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard

printf("Magnetometr:  \r\n",);
printf("(c)mlab JACHO 2013:  \r\n",);
printf("Vysledky z jednotlivych os:\r\n",);
signed int16 X,Y,Z;


while(true)
{  
   printf("Vysledky z jednotlivych os:\r\n",);
   X=mag_readX();
   Y=mag_readY();
   Z=mag_readZ();
   printf("X: %Ld \r\n", X);
   printf("Y %Ld \r\n", Y);
   printf("Z: %Ld \r\n", Z);
   Delay_ms(2000);  
   
}
}
