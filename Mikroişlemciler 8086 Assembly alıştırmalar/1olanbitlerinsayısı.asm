;Verilen 9A04H degerindeki 1 bitlerin sayisi tek ise
;BH 1 yap degilse 0 yap

        MOV DX, 9A04H
        MOV BX, 0H
        

SKIP:   INC BX
        CMP DX, 0000H
        JNE SKIP2
           

           
        HLT        
SKIP2:  SHR DX, 1
        JC THEN
        


