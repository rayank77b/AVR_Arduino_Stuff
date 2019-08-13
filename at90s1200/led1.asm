; simple led on pb0
.nolist  
.include "1200def.inc"
.list 

rjmp      main      
main:  
  ldi      r16,0xFF

  ldi r16,0b00001 ; set pb0 to output
  out DDRB,r16 

loop: 
  sbi PORTB,0 ; low
  rcall warten ; Aufruf des Warte-Unterprogramms
  cbi PORTB,0 ; schalte die Leuchtdiode aus
   rcall warten ; Aufruf des Warte-Unterprogramms
  rjmp loop ; springe zum Label 'loop'

warten: ; ca. 1/6 Sekunde verzögern
  inc r21
  brne PC-1
  inc r22
  brne PC-3
  ret ; Rücksprung ins Hauptprogramm
