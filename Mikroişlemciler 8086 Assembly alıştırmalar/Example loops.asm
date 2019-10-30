;int a=9; int sum=0;
;while (a>2)
;{
;if (a%2==1)
;{
;sum+=a;
;}
;a--;
;}

        MOV DL, 9H
        MOV BL, 0H
        
WHILE:  MOV BH, 02H
        MOV AL, DL
        DIV BH
        CMP AH, 01H
        JE IF
THEN:   DEC DL
        CMP DL, 02H
        JA SKIP
        HLT
IF:     ADD BL, DL
        LOOP THEN
SKIP:   LOOP WHILE
