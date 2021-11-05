# MDA dot matrix:

Think each LED as 3 leg LED. 8255's port C is conected with each column starting from 7 to 0 (Left - Right) and port A and B conected as 7 to 0 (Top - Bottom). 
LED are common anode LED. Prot A responsible for green and port B is responsible for green light. To light up a specific point of that matrix we should keep 
C of that column (1)(Common Anode) and if red light then rows(A = 1, B = 0) and if green light then rows(A = 0, B = 1) { 0 = ON, 1 = OFF}
 

# MDA LED:

To light up a LED we should output this pattern (11110001) to port A. Here (4)MSB should always keep 1. Then from LSB each positions bit (1) lights up that specific
LED from 0-3. Check it out by setting different 1 combinition with the trial and error for understanding the 4 LED sequence.

# MDA Seven Segment:

Works like normal seven segment display.
