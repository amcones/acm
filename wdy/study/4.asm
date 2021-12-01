data segment
str db 'please input number(1-3):','$'
str1 db 'chapter1: introduction','$'
str2 db 'chapter2: designing method','$'
str3 db 'chapter3:experimenr','$'
table dw A1,A2,A3 
data ends
code segment
     assume cs:code,ds:data
start: mov ax,data
       mov ds,ax
       begin:mov dx,offset str
             mov ah,9
             int 21h
             mov ah,01h
             int 21h
             cmp al,'1'
             jb finish
             cmp al,'3'
             ja finish
             and ax,000FH
             dec ax
	     shl ax,1
             mov bx,ax
             jmp table[bx]
      A1: mov dx,offset str1
          mov ah,9
          int 21h
          jmp enter
      A2: mov dx,offset str2
          mov ah,9
          int 21h
          jmp enter
      A3: mov dx,offset str3
          mov ah,9
          int 21h
          jmp enter
      finish: mov dl,0dh
             mov ah,2
             int 21h
             mov dl,0ah
             int 21h
             jmp begin
     enter: mov ax,4c00h
              int 21h
code ends
end start