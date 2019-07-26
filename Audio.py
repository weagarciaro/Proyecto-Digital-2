#!/usr/bin/python3

#
#Llamado a migen
#-----------------------------------------------------------------------
from migen import *
from migen.build.generic_platform import *
from migen.build.xilinx import XilinxPlatform
from litex.soc.interconnect.csr import *
from litex.soc.interconnect.csr_eventmanager import *

# Modulo Principal
class Audio(Module,AutoCSR):
    def __init__(self):

        self.submodules.ev      = EventManager()
        self.ev.dataPending     = EventSourceProcess()

    ##Entradas
        self.CLK                = Signal()
        self.Reset              = Signal()
    ##Salidas
        self.I2S_CLK            = Signal()
        self.I2S_DATA           = Signal()
        self.I2S_WS             = Signal()
    ##Valores Internos
        self.iData               = CSRStorage(32)
        self.enable              = CSRStorage()
        self.bussy               = CSRStatus()
        self.bussy_wire          = Signal()
    ##Instancia
        self.specials +=Instance("i2s",

            i_CLK           =self.CLK,
            i_reset         =self.Reset,
	        i_iData         =self.iData.storage,			##Datos a transmitir
            i_enable        =self.enable.storage,
	        o_bussy         =self.bussy_wire,
	        o_I2S_DATA      =self.I2S_DATA,		           ##Bit transmitido
            o_BCLK          =self.I2S_CLK,				   ##Clock de salida
            o_WSelect       =self.I2S_WS,			      ##Canal de salida
            )

        self.comb += self.bussy.status.eq(self.bussy_wire)
        self.comb += self.ev.dataPending.trigger.eq(self.bussy_wire==0) ##cuando este en flanco de bajada escribe
