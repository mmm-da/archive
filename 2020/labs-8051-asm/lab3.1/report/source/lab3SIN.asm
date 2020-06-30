org 00h

mov dph,#1 
mov dpl,#0 
clr p0.7

loop:
	mov a,#0
	movc a,@a+dptr
	mov p1,a
	inc dpl 
	jmp loop

org 0100h
db 07fh, 065h, 04dh, 036h, 023h, 013h, 08h, 01h, 00h, 04h, 0dh, 01bh, 02ch, 041h, 059h, 072h, 08ch, 0a5h, 0bdh, 0d2h, 0e3h, 0f1h, 0fah, 0feh, 0fdh, 0f6h, 0ebh, 0dbh, 0c8h, 0b1h, 099h, 07fh, 07fh, 065h, 04dh, 036h, 023h, 013h, 08h, 01h, 00h, 04h, 0dh, 01bh, 02ch, 041h, 059h, 072h, 08ch, 0a5h, 0bdh, 0d2h, 0e3h, 0f1h, 0fah, 0feh, 0fdh, 0f6h, 0ebh, 0dbh, 0c8h, 0b1h, 099h, 07fh, 07fh, 065h, 04dh, 036h, 023h, 013h, 08h, 01h, 00h, 04h, 0dh, 01bh, 02ch, 041h, 059h, 072h, 08ch, 0a5h, 0bdh, 0d2h, 0e3h, 0f1h, 0fah, 0feh, 0fdh, 0f6h, 0ebh, 0dbh, 0c8h, 0b1h, 099h, 07fh, 07fh, 065h, 04dh, 036h, 023h, 013h, 08h, 01h, 00h, 04h, 0dh, 01bh, 02ch, 041h, 059h, 072h, 08ch, 0a5h, 0bdh, 0d2h, 0e3h, 0f1h, 0fah, 0feh, 0fdh, 0f6h, 0ebh, 0dbh, 0c8h, 0b1h, 099h, 07fh, 07fh, 065h, 04dh, 036h, 023h, 013h, 08h, 01h, 00h, 04h, 0dh, 01bh, 02ch, 041h, 059h, 072h, 08ch, 0a5h, 0bdh, 0d2h, 0e3h, 0f1h, 0fah, 0feh, 0fdh, 0f6h, 0ebh, 0dbh, 0c8h, 0b1h, 099h, 07fh, 07fh, 065h, 04dh, 036h, 023h, 013h, 08h, 01h, 00h, 04h, 0dh, 01bh, 02ch, 041h, 059h, 072h, 08ch, 0a5h, 0bdh, 0d2h, 0e3h, 0f1h, 0fah, 0feh, 0fdh, 0f6h, 0ebh, 0dbh, 0c8h, 0b1h, 099h, 07fh, 07fh, 065h, 04dh, 036h, 023h, 013h, 08h, 01h, 00h, 04h, 0dh, 01bh, 02ch, 041h, 059h, 072h, 08ch, 0a5h, 0bdh, 0d2h, 0e3h, 0f1h, 0fah, 0feh, 0fdh, 0f6h, 0ebh, 0dbh, 0c8h, 0b1h, 099h, 07fh