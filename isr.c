#include <generated/csr.h>
#include <irq.h>
#include "variables.h"
#include <stdio.h>
#include <stdbool.h>


extern void periodic_isr(void);

unsigned int localState=0;

void isr(void);
void isr(void){

	unsigned int irqs;
	unsigned int interrupt_botones;
	irqs = irq_pending() & irq_getmask();
  interrupt_botones = Botones_WB_ev_pending_read(); // leo la bandera de la interrupcion para ejecutar una de las acciones

	if(irqs & (1 << AUDIO_WB_INTERRUPT)){
		Audio_WB_iData_write(dataA);
		Audio_WB_ev_pending_write(1);			// Escribir 0 en el flag de interrupcion
		Audio_WB_ev_enable_write(1);			// Rehabilitar las interrupciones en el modulo de Botones
	}else if(irqs & (1 << BOTONES_WB_INTERRUPT)){
		if((interrupt_botones & 1)==1){
			Botones_WB_ev_enable_write(0x0);			// Deshabilitar las interrupciones en el modulo de Botones
			wait_ms(200);
			state_player=1; //
			Botones_WB_ev_pending_write(0xF);			// Escribir 0 en el flag de interrupcion
			Botones_WB_ev_enable_write(0xF);			// Rehabilitar las interrupciones en el modulo de Audio
		}else if((interrupt_botones & (1<<1))==(1<<1)){
			Botones_WB_ev_enable_write(0x0);			// Deshabilitar las interrupciones en el modulo de Botones
			wait_ms(200);
			state_player=2;
			Botones_WB_ev_pending_write(0xF);			// Escribir 0 en el flag de interrupcion
			Botones_WB_ev_enable_write(0xF);			// Rehabilitar las interrupciones en el modulo de Audio
		}else if((interrupt_botones & (1<<2))==(1<<2)){
			Botones_WB_ev_enable_write(0x0);			// Deshabilitar las interrupciones en el modulo de Botones
			wait_ms(200);
			state_player=3;
			Botones_WB_ev_pending_write(0xF);			// Escribir 0 en el flag de interrupcion
			Botones_WB_ev_enable_write(0xF);			// Rehabilitar las interrupciones en el modulo de Audio
		}else if((interrupt_botones & (1<<3))==(1<<3)){
			Botones_WB_ev_enable_write(0x0);			// Rehabilitar las interrupciones en el modulo de Botones
			wait_ms(200);
			state_player=4;
			Botones_WB_ev_pending_write(0xF);			// Escribir 0 en el flag de interrupcion
			Botones_WB_ev_enable_write(0xF);			// Rehabilitar las interrupciones en el modulo de Audio
		}

	}

}
