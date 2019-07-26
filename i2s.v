`timescale 1ns / 1ps

module i2s(
	input  wire 		CLK, 			//clock de RECIBIMIENTO DE DATOS
   	input  wire 		reset,
	input  wire [31:0]  iData,			// Datos a transmitir
   	input  wire 		enable,
	output wire 		bussy,
	output wire         I2S_DATA,		//Bit transmitido
   	output wire         BCLK,			//Clock de salida
   	output reg          WSelect 		//Canal de salida
);
	reg  [4:0]  counter; //contador que recorre los 32 bits
	reg  [31:0] Data;
	wire TCLK;

	initial begin 			//inicializacion
		counter=0;
    	Data =0;
	end

//logica de transmision
	always@(negedge TCLK) begin
		if(reset)begin
			counter<=0;			
			WSelect<=0;
		end else begin
			if(counter==31)begin
            	WSelect<=0;
			end else if(counter==15) begin
				WSelect<=1;
			end
			counter<=counter+1;
		end
	end
	 
	always@(posedge WSelect)begin
		if(reset)begin
			Data<=0;
		end else begin
        	Data<=(enable)?iData:0;
        	
        end
    end

    //Logica Combinacional

    assign I2S_DATA=Data[31-counter];
    assign BCLK=enable?TCLK:0;

	assign bussy=enable ? WSelect : 1;
	reg [5:0] counter1;
//Divisor de frecuencia
	initial begin
		counter1=0;// para alcanzar 3.3 Mhz
	end
	parameter DIVISOR=63; // 30

	always@(posedge CLK)begin
		if (counter1>=(DIVISOR-1)) begin 
			counter1<=0;
		end else begin
			counter1<=counter1+1;

		end
	end
	assign TCLK=(counter1<DIVISOR/2)?0:1;

endmodule
