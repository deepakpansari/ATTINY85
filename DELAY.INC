; File Name :  Library for Delay
; Author : DEEPAK KUMAR
; Date : 05-05-2017
; Details : Complete Library for Delay
;
; FUNCTION NAME: DELAY_US
; ARGUMENT: DELAY in microsecond (.SET DELAY = 100 just before the call)
;       
; Max duration 0xFFFF in Microseconds
;------------------------------------------
; Start of the subroutine

DELAY_US:

; Pushing the registers to avoid data loss
        PUSH R23

; Loop through 4 times as the CPU if running at 16MHZ to sync time
	LDI R23,5
DELAY_D:DEC R23
	BRNE DELAY_R   ; Jump to the main delay loop
	POP R23        ; Pop out the saved register
	RET            ; Return from the Call 

DELAY_R: ; Push the register to be used in the stack
        PUSH R23
	PUSH R24
	PUSH R25

        LDI R25, HIGH(DELAY)    ; Load the high delay time in the R25 register
        LDI R24, LOW(DELAY)     ; Low the low delay time in the R24 register

        TST R24                 ; Set flags according to the register
        BREQ D_L2               ; If the low time is 0 then decrease go to D_L2
D_L1:   DEC R24                 ; If not 0 than low time decrease
        NOP
        BRNE D_L1               ; Loop through the low time to make it 0
        TST R25                 ; Set the flag according to the High time
        BRNE D_L2               ; If not 0 goto the D_L2 loop
	POP R25                 ; Otherwise pop the register and end the loop
	POP R24
	POP R23
        RJMP DELAY_D            ; Loop through the DELAY_D
D_L2:   LDI R24,$FF             ; Decrease the high register and make the Low register $FF
        DEC R25
        LDI R23,8               ; Loop for end time calibration
D_L3:   DEC R23                 ;
        BRNE D_L3
        RJMP D_L1

