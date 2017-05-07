; File Name : DELAY.INC
; Author : DEEPAK KUMAR
; Date : 05-05-2017
; Details : Header file for all the delay function
;	    Supported in All AVR Microcontroller

; FUNCTION NAME: DELAY_US 
; ARGUMENT: DELAY in microseconds (use ".SET DELAY = 23" command)
; MAX DELAY: 0xFFFF or 65000 Microseconds
; MIN DELAY: 10 microseconds
; 
; === Very low error in Timing, eg. for 1000uS actual delay was 1001uS ==
;------------------------------------------


;Delay subroutine
DELAY_US:PUSH R23
	LDI R23,5
D:	DEC R23
	BRNE DELAY_R
	POP R23
	RET
DELAY_R:PUSH R23
	PUSH R24
	PUSH R25
        LDI R25, HIGH(DELAY)
        LDI R24, LOW(DELAY)
        TST R24
        BREQ D_L2
D_L1:   DEC R24
        NOP
        BRNE D_L1
        TST R25
        BRNE D_L2
	POP R25
	POP R24
	POP R23
        RJMP D
D_L2:   LDI R24,$FF
        DEC R25
        LDI R23,8
D_L3:   DEC R23
        BRNE D_L3
        RJMP D_L1
	
	
;-------END OF THE HEADER--------------------
