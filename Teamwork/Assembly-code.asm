.386
.model flat, C

.code

; Complete the procedure
IsValidAssembly PROC

mov eax, 1024				;eax = bit 10 = 0x400h
AND edx, eax				;edx = eax
shr edx, 10					;move to the right 10 bits
mov eax, 0					;eax = 0
cmp edx, eax				;if(bit10 == 0)
jne endBad					;jump to the end if they are not equal
XOR ebx, ecx				;input2 XOR input3
mov eax, 988921				;eax = 988921 the result of the XOR must equal this
cmp ebx, eax				;if(iput2 XOR input3 == 988921)
jne endBad					;jump to the end if they are not equal
jmp endGood					;jump to endGood
endBad: 
ret 0						;returns 0
endGood: 
ret 1						;returns 1
IsValidAssembly ENDP 

END 