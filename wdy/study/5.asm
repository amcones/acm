DATA SEGMENT
DAT DB 35H,78H,25H,13H,8H,0D2H
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
START: MOV AX,DATA
       MOV DS,AX
       MOV CX,5
A1:    MOV DI,CX
       MOV BX,0
A2:    MOV AL,DAT[BX]
       CMP AL,DAT[BX+1]
       JGE A3
       XCHG AL,DAT[BX+1]
       MOV DAT[BX],AL
A3:    ADD BX,1
       LOOP A2
       MOV CX,DI
       LOOP A1
       MOV DL,DAT[0]
       MOV CL,4
       SHR DL,CL
       OR DL,30H
       CMP DL,39H
       JBE AD1
       ADD DL,7
AD1:   MOV AH,2
       INT 21H
       MOV DL,DAT[0]
       AND DL,0FH
       OR DL,30H
       CMP DL,39H
       JBE AD2
       ADD DL,7
AD2:   MOV AH,2
       INT 21H
       MOV AH,4CH
       INT 21H
CODE ENDS
     END START