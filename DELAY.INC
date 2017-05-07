; Delay header file
; Contains DELAY_US function,
; Max duration 0xFFFF in Microseconds
; .SET DELAY = time   variable for time in delay
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
