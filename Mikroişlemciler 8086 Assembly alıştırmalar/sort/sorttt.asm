Array Dw 3h,2h, 8h ,9h ,10h, 12h
count DW 6h
dd Dw 2h
mov si , offset Array
lea si,[Array+si]
mov bx,0h; sayacç
mov cx, count
l1: lodsw
    div dd
    cmp dx,0 
    je l2 
    add bx,1
    l2:
    loop l1