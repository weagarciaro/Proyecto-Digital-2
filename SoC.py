#!/usr/bin/python3
#
#Llamado a migen
#-----------------------------------------------------------------------
from migen import *

from migen.genlib.io import CRG

from migen.build.generic_platform import *
from migen.build.xilinx import XilinxPlatform

from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from Hardware.Audio import Audio
from Hardware.Botones import Botones


##from ios import Led


#-----------------------------------------------------------------------
# Definicion de Pines
#
_io = [
    ("user_led"         , 0 , Pins("H17"), IOStandard("LVCMOS33")),
    ("user_led"         , 1 , Pins("K15"), IOStandard("LVCMOS33")),
    ("user_led"         , 2 , Pins("J13"), IOStandard("LVCMOS33")),
    ("user_led"         , 3 , Pins("N14"), IOStandard("LVCMOS33")),
    ("user_led"         , 4 , Pins("R18"), IOStandard("LVCMOS33")),
    ("user_led"         , 5 , Pins("V17"), IOStandard("LVCMOS33")),
    ("user_led"         , 6 , Pins("U17"), IOStandard("LVCMOS33")),
    ("user_led"         , 7 , Pins("U16"), IOStandard("LVCMOS33")),
    ("user_led"         , 8 , Pins("V16"), IOStandard("LVCMOS33")),
    ("user_led"         , 9 , Pins("T15" ), IOStandard("LVCMOS33")),
    ("user_led"         , 10, Pins("U14" ), IOStandard("LVCMOS33")),
    ("user_led"         , 11, Pins("T16" ), IOStandard("LVCMOS33")),
    ("user_led"         , 12, Pins("V15" ), IOStandard("LVCMOS33")),
    ("user_led"         , 13, Pins("V14" ), IOStandard("LVCMOS33")),
    ("user_led"         , 14, Pins("V12" ), IOStandard("LVCMOS33")),
    ("user_led"         , 15, Pins("V11" ), IOStandard("LVCMOS33")),
    ("user_sw"          , 0 , Pins("J15"), IOStandard("LVCMOS33")),
    ("user_sw"          , 1 , Pins("L16"), IOStandard("LVCMOS33")),
    ("user_sw"          , 2 , Pins("M13"), IOStandard("LVCMOS33")),
    ("user_sw"          , 3 , Pins("R15"), IOStandard("LVCMOS33")),
    ("user_sw"          , 4 , Pins("R17"), IOStandard("LVCMOS33")),
    ("user_sw"          , 5 , Pins("T18"), IOStandard("LVCMOS33")),
    ("user_sw"          , 6 , Pins("U18"), IOStandard("LVCMOS33")),
    ("user_sw"          , 7 , Pins("R13"), IOStandard("LVCMOS33")),
    ("user_sw"          , 8 , Pins("T8" ), IOStandard("LVCMOS33")),
    ("user_sw"          , 9 , Pins("U8" ), IOStandard("LVCMOS33")),
    ("user_sw"          , 10, Pins("R16" ), IOStandard("LVCMOS33")),
    ("user_sw"          , 11, Pins("T13" ), IOStandard("LVCMOS33")),
    ("user_sw"          , 12, Pins("H6" ), IOStandard("LVCMOS33")),
    ("user_sw"          , 13, Pins("U12" ), IOStandard("LVCMOS33")),
    ("user_sw"          , 14, Pins("U11" ), IOStandard("LVCMOS33")),
    ("user_sw"          , 15, Pins("V10" ), IOStandard("LVCMOS33")),
    ("user_btn"         , 0 , Pins("P18"), IOStandard("LVCMOS33")),
    ("user_btn"         , 1 , Pins("N17"), IOStandard("LVCMOS33")),
    ("user_btn"         , 2 , Pins("M17'"), IOStandard("LVCMOS33")),
    ("user_btn"         , 3 , Pins("M18"), IOStandard("LVCMOS33")),
    ("clk100"           , 0 , Pins("E3" ), IOStandard("LVCMOS33")),
    ("cpu_reset"        , 0 , Pins("C12"), IOStandard("LVCMOS33")),

    #I2S-JA
    ("I2S_WS"           , 0 , Pins("C17"), IOStandard("LVCMOS33")),
    ("I2S_DATA"         , 0 , Pins("D18"), IOStandard("LVCMOS33")),
    ("I2S_CLK"          , 0 , Pins("E18"), IOStandard("LVCMOS33")),

     #USB-UART
    ("serial", 0,
        Subsignal("tx", Pins("D4")),
        Subsignal("rx", Pins("C4")),
        IOStandard("LVCMOS33"),
    ),
]

#-----------------------------------------------------------------------
#Defincinicion de Plataforma (Marca y referencia de FPGA)
#
class Platform(XilinxPlatform):
    default_clk_name = "clk100"
    default_clk_period = 10.0

    def __init__(self):
        XilinxPlatform.__init__(self,"xc7a100t-CSG324-1", _io, toolchain="ise")

    def do_finalize(self, fragment):
        XilinxPlatform.do_finalize(self, fragment)

def csr_map_update(csr_map, csr_peripherals):
    csr_map.update (dict((n, v)
        for v, n in enumerate(csr_peripherals,6 )))  ##start=max(csr_map.values()) + 1)

#----------------------------------------------------------------------
#Creacion de Plataforma
platform = Platform()
#Definicion de pines como variables

leds             = Cat(*[platform.request("user_led",         i) for i in range(16)])
switches         = Cat(*[platform.request("user_sw" ,         i) for i in range(16)])
buttons          = Cat(*[platform.request("user_btn",         i) for i in range(4) ])
SystemClock      = ClockSignal()
I2S_DATA         = platform.request("I2S_DATA", 0)
I2S_CLK          = platform.request("I2S_CLK" , 0)
I2S_WS           = platform.request("I2S_WS"  , 0)

#-----------------------------------------------------------------------
# DISEÑO
#

# Adicion de modulos en verilog
#  Audio
platform.add_source("Hardware/Audio/i2s.v")
#Periferico Botones

platform.add_source("Hardware/Botones/Buttons.v")
platform.add_source("Hardware/Botones/ButtonDebouncer.v")
platform.add_source("Hardware/Botones/FrequencyGenerator.v")

# Modulo Principal
class SoC(SoCCore):
    csr_peripherals = [
        "Audio_WB",
        "Botones_WB"
    ]

    csr_map_update(SoCCore.csr_map, csr_peripherals)


    def __init__(self, platform):
        interrupt_map= {
            'Audio_WB': 7, ##ANTES HAY OTRAS INTERRUPCIONES DE OTROS MODULOS
            'Botones_WB': 8,
        }
        SoCCore.interrupt_map.update(interrupt_map)

        sys_clk_freq = int(100e6)
        # SoC with CPU
        SoCCore.__init__(self, platform,
            csr_data_width=32,
            cpu_type="lm32",
            clk_freq=100e6,
            ident="CPU Test SoC", ident_version=True,
            integrated_rom_size=0x8000,
            integrated_main_ram_size=16*1024)




        self.submodules.crg         = CRG(platform.request("clk100"),~platform.request("cpu_reset"))
        self.submodules.Audio_WB    = Audio()
        self.submodules.Botones_WB  = Botones()
        self.Reset                  = Signal()




        self.comb += [
            self.Botones_WB.CLK.eq(SystemClock),
            self.Botones_WB.Buttons.eq(buttons),
            self.Audio_WB.CLK.eq(SystemClock),
            self.Audio_WB.Reset.eq(self.Reset),
            I2S_DATA.eq(self.Audio_WB.I2S_DATA),
            I2S_WS.eq(self.Audio_WB.I2S_WS),
            I2S_CLK.eq(self.Audio_WB.I2S_CLK),

        ]

#------------------------------------------------------------------------
# Sintetizacion de Modulo Principal
#
soc = SoC(platform)

#
# build
#
builder = Builder(soc, output_dir="build", csr_csv="MemoryMap.csv")
builder.build()
