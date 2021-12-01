
DATA SEGMENT
MEG DB 'Please input a number(0~99):',0DH,0AH,'$'
ME2 DB 0DH,0AH,'Input a invalid number,exit!',0DH,0AH,'$'
X DB ?
Y DB 0AH
BUF DB 10
    DB ?
    DB 10 DUP(?)
BU2 DB '0','$'
    DB 8 DUP(?)
    
DATA ENDS
CODE SEGMENT
   ASSUME DS:DATA,CS:CODE
START: MOV AX,DATA
       MOV DS,AX
 
       MOV AH,09H
       MOV DX,OFFSET MEG
       INT 21H
       
       MOV AH,0AH
       MOV DX,OFFSET BUF
       INT 21H
 
       MOV DL,BUF[1]
       CMP DL,3
       JA ER
       MOV DL,BUF[2]
       CMP DL,0DH
       JZ PD
       CMP DL,'0'
       JB ER
       CMP DL,'9'
       JA ER
       SUB DL,'0'
       MOV X,DL
 
       MOV DL,BUF[3]
       CMP DL,0DH
       JZ PD
       CMP DL,'0'
       JB ER
       CMP DL,'9'
       JA ER
       MOV AL,X
       MUL Y
       SUB DL,'0'
       ADD AL,DL
       MOV X,AL
       
       MOV DL,BUF[4]
       CMP DL,0DH
       JZ PD
       CMP DL,'0'
       JB ER
       CMP DL,'9'
       JA ER
       SUB DL,'0'
       MOV AL,X
       CMP AL,19H
       JA ER
       MUL Y
       MOV BL,0FFH
       SUB BL,DL
       CMP AL,BL
       JA ER
       ADD AL,DL
       MOV X,AL
 
PD:    CMP X,0
       JB ER
       CMP X,99
       JA ER
       MOV AL,X
       MOV Y,AL
       
       CMP AL,0
       JE XS
 
       MOV BL,BUF[1]
       MOV DI,BX
       MOV BU2[DI],'$'
 
       MOV BL,0AH
       AND AX,00FFH
       DIV BL
       DEC DI
       ADD AH,'0'
       MOV BU2[DI],AH
       MOV BL,AL
       CMP BL,0
       JE XS
    
       MOV AL,BL
       MOV BL,0AH
       AND AX,00FFH
       DIV BL
       ADD AH,'0'
       DEC DI
       MOV BU2[DI],AH
       MOV BL,AL
       CMP BL,0
       JE XS
       
       DEC DI
       MOV AL,BL
       MOV BL,0AH
       AND AX,00FFH
       DIV BL
       ADD AH,'0'
       MOV BU2[DI],AH
 
XS:    MOV AH,09H
       MOV DX,OFFSET BU2
       INT 21H
       
       MOV AH,02H
       MOV DL,'='
       INT 21H
 
       MOV CX,8
       MOV AL,X
 
       
SEC:   MOV AL,Y
       MOV DI,CX
       MOV CL,1
       ROL AL,CL
       MOV Y,AL
       AND AL,01H
       MOV DL,AL
       MOV AH,02H
       ADD DL,'0'
       INT 21H
       MOV CX,DI
       LOOP SEC
 
       MOV AH,02H
       MOV DL,'B'
       INT 21H
 
       MOV AH,02H
       MOV DL,'='
       INT 21H
 
       MOV DL,X
       MOV CL,4
       SHR DL,CL
       OR DL,30H
       CMP DL,39H
       JBE AD1
       ADD DL,7
AD1:   MOV AH,2
       INT 21H
 
       MOV DL,X
       AND DL,0FH
       OR DL,30H
       CMP DL,39H
       JBE AD2
       ADD DL,7
AD2:   MOV AH,2
       INT 21H
 
       MOV AH,02H
       MOV DL,'H'
       INT 21H
 
       MOV AH,4CH
       INT 21H
ER:    MOV AH,09H
       MOV DX,OFFSET ME2
       INT 21H
       MOV AH,4CH
       INT 21H
CODE ENDS
     END START