        MOV AL, 0H
        MOV BL, 5H
HERE:   MOV DL, 4H
HERE2:  
        ADD AL, DL
        DEC DL
        CMP DL, 00H
        JA SKIP2
        DEC BL
        CMP BL, 01H
        JAE SKIP
END:    HLT
SKIP:   LOOP HERE
SKIP2:  LOOP HERE2