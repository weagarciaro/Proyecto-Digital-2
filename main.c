#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <irq.h>
#include <uart.h>
#include <console.h>
#include <generated/csr.h>
#include "variables.h"

int main(void){

	//inicializacion de Perifericos
	Audio_WB_ev_enable_write(1);
	irq_setmask((1<<AUDIO_WB_INTERRUPT)+(1<<BOTONES_WB_INTERRUPT));
	Botones_WB_ev_enable_write(0xF);
  state_player=3;
	irq_setie(1); //habilitar INTERRUPCIONES

	Audio_WB_enable_write(1);
	Audio_WB_iData_write(0x0000FFFF);
	while(1){
		if (state_player==1){
			wait_us(2500);
			dataA=0x00000000;
			wait_us(2500);
			dataA=0X00000000;
		}else if(state_player==2){
			wait_us(2500);
			dataA=0x00000000;
			wait_us(2500);
			dataA=0x7FFF7FFF;
		}else if(state_player==3){
			wait_us(5000);
			dataA=0x00000000;
			wait_us(5000);
			dataA=0x7FFF7FFF;
	 	}else if(state_player==4){
			wait_us(7500);
			dataA=0x00000000;
			wait_us(7500);
			dataA=0x7FFF7FFF;}
	}



	return 0;
}
