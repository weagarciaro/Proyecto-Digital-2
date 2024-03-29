//--------------------------------------------------------------------------------
// Auto-generated by Migen (562c046) & LiteX (38a2d89a) on 2019-07-25 15:59:05
//--------------------------------------------------------------------------------
#ifndef __GENERATED_CSR_H
#define __GENERATED_CSR_H
#include <stdint.h>
#ifdef CSR_ACCESSORS_DEFINED
extern void csr_writeb(uint8_t value, unsigned long addr);
extern uint8_t csr_readb(unsigned long addr);
extern void csr_writew(uint16_t value, unsigned long addr);
extern uint16_t csr_readw(unsigned long addr);
extern void csr_writel(uint32_t value, unsigned long addr);
extern uint32_t csr_readl(unsigned long addr);
#else /* ! CSR_ACCESSORS_DEFINED */
#include <hw/common.h>
#endif /* ! CSR_ACCESSORS_DEFINED */

/* Audio_WB */
#define CSR_AUDIO_WB_BASE 0xe0003000L
#define CSR_AUDIO_WB_IDATA_ADDR 0xe0003000L
#define CSR_AUDIO_WB_IDATA_SIZE 1
static inline unsigned int Audio_WB_iData_read(void) {
	unsigned int r = csr_readl(0xe0003000L);
	return r;
}
static inline void Audio_WB_iData_write(unsigned int value) {
	csr_writel(value, 0xe0003000L);
}
#define CSR_AUDIO_WB_ENABLE_ADDR 0xe0003004L
#define CSR_AUDIO_WB_ENABLE_SIZE 1
static inline unsigned int Audio_WB_enable_read(void) {
	unsigned int r = csr_readl(0xe0003004L);
	return r;
}
static inline void Audio_WB_enable_write(unsigned int value) {
	csr_writel(value, 0xe0003004L);
}
#define CSR_AUDIO_WB_BUSSY_ADDR 0xe0003008L
#define CSR_AUDIO_WB_BUSSY_SIZE 1
static inline unsigned int Audio_WB_bussy_read(void) {
	unsigned int r = csr_readl(0xe0003008L);
	return r;
}
#define CSR_AUDIO_WB_EV_STATUS_ADDR 0xe000300cL
#define CSR_AUDIO_WB_EV_STATUS_SIZE 1
static inline unsigned int Audio_WB_ev_status_read(void) {
	unsigned int r = csr_readl(0xe000300cL);
	return r;
}
static inline void Audio_WB_ev_status_write(unsigned int value) {
	csr_writel(value, 0xe000300cL);
}
#define CSR_AUDIO_WB_EV_PENDING_ADDR 0xe0003010L
#define CSR_AUDIO_WB_EV_PENDING_SIZE 1
static inline unsigned int Audio_WB_ev_pending_read(void) {
	unsigned int r = csr_readl(0xe0003010L);
	return r;
}
static inline void Audio_WB_ev_pending_write(unsigned int value) {
	csr_writel(value, 0xe0003010L);
}
#define CSR_AUDIO_WB_EV_ENABLE_ADDR 0xe0003014L
#define CSR_AUDIO_WB_EV_ENABLE_SIZE 1
static inline unsigned int Audio_WB_ev_enable_read(void) {
	unsigned int r = csr_readl(0xe0003014L);
	return r;
}
static inline void Audio_WB_ev_enable_write(unsigned int value) {
	csr_writel(value, 0xe0003014L);
}

/* Botones_WB */
#define CSR_BOTONES_WB_BASE 0xe0003800L
#define CSR_BOTONES_WB_DATAREGISTER_ADDR 0xe0003800L
#define CSR_BOTONES_WB_DATAREGISTER_SIZE 1
static inline unsigned int Botones_WB_DataRegister_read(void) {
	unsigned int r = csr_readl(0xe0003800L);
	return r;
}
#define CSR_BOTONES_WB_EV_STATUS_ADDR 0xe0003804L
#define CSR_BOTONES_WB_EV_STATUS_SIZE 1
static inline unsigned int Botones_WB_ev_status_read(void) {
	unsigned int r = csr_readl(0xe0003804L);
	return r;
}
static inline void Botones_WB_ev_status_write(unsigned int value) {
	csr_writel(value, 0xe0003804L);
}
#define CSR_BOTONES_WB_EV_PENDING_ADDR 0xe0003808L
#define CSR_BOTONES_WB_EV_PENDING_SIZE 1
static inline unsigned int Botones_WB_ev_pending_read(void) {
	unsigned int r = csr_readl(0xe0003808L);
	return r;
}
static inline void Botones_WB_ev_pending_write(unsigned int value) {
	csr_writel(value, 0xe0003808L);
}
#define CSR_BOTONES_WB_EV_ENABLE_ADDR 0xe000380cL
#define CSR_BOTONES_WB_EV_ENABLE_SIZE 1
static inline unsigned int Botones_WB_ev_enable_read(void) {
	unsigned int r = csr_readl(0xe000380cL);
	return r;
}
static inline void Botones_WB_ev_enable_write(unsigned int value) {
	csr_writel(value, 0xe000380cL);
}

/* ctrl */
#define CSR_CTRL_BASE 0xe0000000L
#define CSR_CTRL_RESET_ADDR 0xe0000000L
#define CSR_CTRL_RESET_SIZE 1
static inline unsigned int ctrl_reset_read(void) {
	unsigned int r = csr_readl(0xe0000000L);
	return r;
}
static inline void ctrl_reset_write(unsigned int value) {
	csr_writel(value, 0xe0000000L);
}
#define CSR_CTRL_SCRATCH_ADDR 0xe0000004L
#define CSR_CTRL_SCRATCH_SIZE 1
static inline unsigned int ctrl_scratch_read(void) {
	unsigned int r = csr_readl(0xe0000004L);
	return r;
}
static inline void ctrl_scratch_write(unsigned int value) {
	csr_writel(value, 0xe0000004L);
}
#define CSR_CTRL_BUS_ERRORS_ADDR 0xe0000008L
#define CSR_CTRL_BUS_ERRORS_SIZE 1
static inline unsigned int ctrl_bus_errors_read(void) {
	unsigned int r = csr_readl(0xe0000008L);
	return r;
}

/* timer0 */
#define CSR_TIMER0_BASE 0xe0002800L
#define CSR_TIMER0_LOAD_ADDR 0xe0002800L
#define CSR_TIMER0_LOAD_SIZE 1
static inline unsigned int timer0_load_read(void) {
	unsigned int r = csr_readl(0xe0002800L);
	return r;
}
static inline void timer0_load_write(unsigned int value) {
	csr_writel(value, 0xe0002800L);
}
#define CSR_TIMER0_RELOAD_ADDR 0xe0002804L
#define CSR_TIMER0_RELOAD_SIZE 1
static inline unsigned int timer0_reload_read(void) {
	unsigned int r = csr_readl(0xe0002804L);
	return r;
}
static inline void timer0_reload_write(unsigned int value) {
	csr_writel(value, 0xe0002804L);
}
#define CSR_TIMER0_EN_ADDR 0xe0002808L
#define CSR_TIMER0_EN_SIZE 1
static inline unsigned int timer0_en_read(void) {
	unsigned int r = csr_readl(0xe0002808L);
	return r;
}
static inline void timer0_en_write(unsigned int value) {
	csr_writel(value, 0xe0002808L);
}
#define CSR_TIMER0_UPDATE_VALUE_ADDR 0xe000280cL
#define CSR_TIMER0_UPDATE_VALUE_SIZE 1
static inline unsigned int timer0_update_value_read(void) {
	unsigned int r = csr_readl(0xe000280cL);
	return r;
}
static inline void timer0_update_value_write(unsigned int value) {
	csr_writel(value, 0xe000280cL);
}
#define CSR_TIMER0_VALUE_ADDR 0xe0002810L
#define CSR_TIMER0_VALUE_SIZE 1
static inline unsigned int timer0_value_read(void) {
	unsigned int r = csr_readl(0xe0002810L);
	return r;
}
#define CSR_TIMER0_EV_STATUS_ADDR 0xe0002814L
#define CSR_TIMER0_EV_STATUS_SIZE 1
static inline unsigned int timer0_ev_status_read(void) {
	unsigned int r = csr_readl(0xe0002814L);
	return r;
}
static inline void timer0_ev_status_write(unsigned int value) {
	csr_writel(value, 0xe0002814L);
}
#define CSR_TIMER0_EV_PENDING_ADDR 0xe0002818L
#define CSR_TIMER0_EV_PENDING_SIZE 1
static inline unsigned int timer0_ev_pending_read(void) {
	unsigned int r = csr_readl(0xe0002818L);
	return r;
}
static inline void timer0_ev_pending_write(unsigned int value) {
	csr_writel(value, 0xe0002818L);
}
#define CSR_TIMER0_EV_ENABLE_ADDR 0xe000281cL
#define CSR_TIMER0_EV_ENABLE_SIZE 1
static inline unsigned int timer0_ev_enable_read(void) {
	unsigned int r = csr_readl(0xe000281cL);
	return r;
}
static inline void timer0_ev_enable_write(unsigned int value) {
	csr_writel(value, 0xe000281cL);
}

/* uart */
#define CSR_UART_BASE 0xe0001800L
#define CSR_UART_RXTX_ADDR 0xe0001800L
#define CSR_UART_RXTX_SIZE 1
static inline unsigned int uart_rxtx_read(void) {
	unsigned int r = csr_readl(0xe0001800L);
	return r;
}
static inline void uart_rxtx_write(unsigned int value) {
	csr_writel(value, 0xe0001800L);
}
#define CSR_UART_TXFULL_ADDR 0xe0001804L
#define CSR_UART_TXFULL_SIZE 1
static inline unsigned int uart_txfull_read(void) {
	unsigned int r = csr_readl(0xe0001804L);
	return r;
}
#define CSR_UART_RXEMPTY_ADDR 0xe0001808L
#define CSR_UART_RXEMPTY_SIZE 1
static inline unsigned int uart_rxempty_read(void) {
	unsigned int r = csr_readl(0xe0001808L);
	return r;
}
#define CSR_UART_EV_STATUS_ADDR 0xe000180cL
#define CSR_UART_EV_STATUS_SIZE 1
static inline unsigned int uart_ev_status_read(void) {
	unsigned int r = csr_readl(0xe000180cL);
	return r;
}
static inline void uart_ev_status_write(unsigned int value) {
	csr_writel(value, 0xe000180cL);
}
#define CSR_UART_EV_PENDING_ADDR 0xe0001810L
#define CSR_UART_EV_PENDING_SIZE 1
static inline unsigned int uart_ev_pending_read(void) {
	unsigned int r = csr_readl(0xe0001810L);
	return r;
}
static inline void uart_ev_pending_write(unsigned int value) {
	csr_writel(value, 0xe0001810L);
}
#define CSR_UART_EV_ENABLE_ADDR 0xe0001814L
#define CSR_UART_EV_ENABLE_SIZE 1
static inline unsigned int uart_ev_enable_read(void) {
	unsigned int r = csr_readl(0xe0001814L);
	return r;
}
static inline void uart_ev_enable_write(unsigned int value) {
	csr_writel(value, 0xe0001814L);
}

/* uart_phy */
#define CSR_UART_PHY_BASE 0xe0001000L
#define CSR_UART_PHY_TUNING_WORD_ADDR 0xe0001000L
#define CSR_UART_PHY_TUNING_WORD_SIZE 1
static inline unsigned int uart_phy_tuning_word_read(void) {
	unsigned int r = csr_readl(0xe0001000L);
	return r;
}
static inline void uart_phy_tuning_word_write(unsigned int value) {
	csr_writel(value, 0xe0001000L);
}

/* identifier_mem */
#define CSR_IDENTIFIER_MEM_BASE 0xe0002000L

/* constants */
#define AUDIO_WB_INTERRUPT 7
static inline int audio_wb_interrupt_read(void) {
	return 7;
}
#define BOTONES_WB_INTERRUPT 8
static inline int botones_wb_interrupt_read(void) {
	return 8;
}
#define TIMER0_INTERRUPT 1
static inline int timer0_interrupt_read(void) {
	return 1;
}
#define UART_INTERRUPT 0
static inline int uart_interrupt_read(void) {
	return 0;
}
#define CSR_DATA_WIDTH 32
static inline int csr_data_width_read(void) {
	return 32;
}
#define SYSTEM_CLOCK_FREQUENCY 100000000
static inline int system_clock_frequency_read(void) {
	return 100000000;
}
#define CONFIG_CLOCK_FREQUENCY 100000000
static inline int config_clock_frequency_read(void) {
	return 100000000;
}
#define CONFIG_CPU_RESET_ADDR 0
static inline int config_cpu_reset_addr_read(void) {
	return 0;
}
#define CONFIG_CPU_TYPE "LM32"
static inline const char * config_cpu_type_read(void) {
	return "LM32";
}
#define CONFIG_CSR_DATA_WIDTH 32
static inline int config_csr_data_width_read(void) {
	return 32;
}

#endif
