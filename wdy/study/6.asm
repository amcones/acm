DATA SEGMENT
	BUF  DB 01H,25H,38H,62H,8DH,9AH,0BAH,0CEH
	N    DW $-BUF
	X    DW 0DB 30H,31H,32H,33H,34H,35H,36H,37H,38H,39H
      DB 41H,42H,43H,44H,45H,46H
X DW 0
	       ASSUME CS:CODE,DS:DATA
	START: MOV    AX,DATA
	       MOV    DS,AX
	       MOV    CX,NDE,DS:DATA
	BE:    MOV    N,CXATA
	       MOV    BX,XX
	       MOV    DL,BUF[BX]
	       INC    BX
	       MOV    X,BX
	       CALL   DELY
	       MOV    CX,NUF[BX]
	       CMP    CX,1
	       JE     FINISH
	       MOV    DL,','
	       MOV    AH,2
	       INT    21H1
	       LOOP   BESH
	FINISH:MOV    AX,4C00H
	       INT    21H2
DELY PROC NEAR
	       MOV    BL,DL
	       MOV    CL,4
	       SHR    DL,CL00H
	       OR     DL,30H
	       CMP    DL,39H
	       JBE    AD1L
	       ADD    DL,7
	AD1:   MOV    AH,2L
	       INT    21HOFFSET ASCII
	       MOV    DL,BL
	       AND    DL,0FH
	       OR     DL,30H
	       CMP    DL,39H
	       JBE    AD22
	       ADD    DL,7
	AD2:   MOV    AH,2
	       INT    21H0FH
	       MOV    DL,'H'
	       MOV    AH,2L
	       INT    21H2
	       RET 21H
 
       MOV DL,'H'
       MOV AH,2
       INT 21H
       RET
DELY ENDP
CODE ENDS
END START