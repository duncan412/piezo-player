// A fun sketch to demonstrate the use of the Tone library.
// By Brett Hagman
// bhagman@roguerobotics.com
// www.roguerobotics.com

// To mix the output of the signals to output to a small speaker (i.e. 8 Ohms or higher),
// simply use 1K Ohm resistors from each output pin and tie them together at the speaker.
// Don't forget to connect the other side of the speaker to ground!

// You can get more RTTTL (RingTone Text Transfer Language) songs from
// http://code.google.com/p/rogue-code/wiki/ToneLibraryDocumentation

#define OCTAVE_OFFSET 0
#define TONE_PIN 13
#include "noten.h"

//char *song = "Pokemon:d=16,o=5,b=112:32p,f,a#,c6,c#6,c6,c#6,d#6,2f6,a#,c6,8c#6,8f6,8d#6,32c#.6,32d#.6,32c#.6,8c6,8g#.,f,a#,c6,c#6,c6,c#6,d#6,2f6,8a#,c#6,8f6,a,d#6,4g#6";
char *song = "The Simpsons:d=4,o=5,b=160:c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g,8p,8p,8f#,8f#,8f#,8g,a#.,8c6,8c6,8c6,c6";
//char *song = "Indiana:d=4,o=5,b=250:e,8p,8f,8g,8p,1c6,8p.,d,8p,8e,1f,p.,g,8p,8a,8b,8p,1f6,p,a,8p,8b,2c6,2d6,2e6,e,8p,8f,8g,8p,1c6,p,d6,8p,8e6,1f.6,g,8p,8g,e.6,8p,d6,8p,8g,e.6,8p,d6,8p,8g,f.6,8p,e6,8p,8d6,2c6";
//char *song = "Entertainer:d=4,o=5,b=140:8d,8d#,8e,c6,8e,c6,8e,2c.6,8c6,8d6,8d#6,8e6,8c6,8d6,e6,8b,d6,2c6,p,8d,8d#,8e,c6,8e,c6,8e,2c.6,8p,8a,8g,8f#,8a,8c6,e6,8d6,8c6,8a,2d6";
//char *song = "Looney:d=4,o=5,b=140:32p,c6,8f6,8e6,8d6,8c6,a.,8c6,8f6,8e6,8d6,8d#6,e.6,8e6,8e6,8c6,8d6,8c6,8e6,8c6,8d6,8a,8c6,8g,8a#,8a,8f";
//char *song = "Bond:d=4,o=5,b=80:32p,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d#6,16d#6,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d6,16c#6,16c#7,c.7,16g#6,16f#6,g#.6";
//char *song = "MASH:d=8,o=5,b=140:4a,4g,f#,g,p,f#,p,g,p,f#,p,2e.,p,f#,e,4f#,e,f#,p,e,p,4d.,p,f#,4e,d,e,p,d,p,e,p,d,p,2c#.,p,d,c#,4d,c#,d,p,e,p,4f#,p,a,p,4b,a,b,p,a,p,b,p,2a.,4p,a,b,a,4b,a,b,p,2a.,a,4f#,a,b,p,d6,p,4e.6,d6,b,p,a,p,2b";
//char *song = "StarWars:d=4,o=5,b=45:32p,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#.6,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#6";
//char *song = "GoodBad:d=4,o=5,b=56:32p,32a#,32d#6,32a#,32d#6,8a#.,16f#.,16g#.,d#,32a#,32d#6,32a#,32d#6,8a#.,16f#.,16g#.,c#6,32a#,32d#6,32a#,32d#6,8a#.,16f#.,32f.,32d#.,c#,32a#,32d#6,32a#,32d#6,8a#.,16g#.,d#";
//char *song = "TopGun:d=4,o=4,b=31:32p,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,16f,d#,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,g#";
//char *song = "A-Team:d=8,o=5,b=125:4d#6,a#,2d#6,16p,g#,4a#,4d#.,p,16g,16a#,d#6,a#,f6,2d#6,16p,c#.6,16c6,16a#,g#.,2a#";
//char *song = "Flinstones:d=4,o=5,b=40:32p,16f6,16a#,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,d6,16f6,16a#.,16a#6,32g6,16f6,16a#.,32f6,32f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c6,a#,16a6,16d.6,16a#6,32a6,32a6,32g6,32f#6,32a6,8g6,16g6,16c.6,32a6,32a6,32g6,32g6,32f6,32e6,32g6,8f6,16f6,16a#.,16a#6,32g6,16f6,16a#.,16f6,32d#6,32d6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#,16c.6,32d6,32d#6,32f6,16a#6,16c7,8a#.6";
//char *song = "Jeopardy:d=4,o=6,b=125:c,f,c,f5,c,f,2c,c,f,c,f,a.,8g,8f,8e,8d,8c#,c,f,c,f5,c,f,2c,f.,8d,c,a#5,a5,g5,f5,p,d#,g#,d#,g#5,d#,g#,2d#,d#,g#,d#,g#,c.7,8a#,8g#,8g,8f,8e,d#,g#,d#,g#5,d#,g#,2d#,g#.,8f,d#,c#,c,p,a#5,p,g#.5,d#,g#";
//char *song = "MahnaMahna:d=16,o=6,b=125:c#,c.,b5,8a#.5,8f.,4g#,a#,g.,4d#,8p,c#,c.,b5,8a#.5,8f.,g#.,8a#.,4g,8p,c#,c.,b5,8a#.5,8f.,4g#,f,g.,8d#.,f,g.,8d#.,f,8g,8d#.,f,8g,d#,8c,a#5,8d#.,8d#.,4d#,8d#.";
//char *song = "MissionImp:d=16,o=6,b=95:32d,32d#,32d,32d#,32d,32d#,32d,32d#,32d,32d,32d#,32e,32f,32f#,32g,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,a#,g,2d,32p,a#,g,2c#,32p,a#,g,2c,a#5,8c,2p,32p,a#5,g5,2f#,32p,a#5,g5,2f,32p,a#5,g5,2e,d#,8d";
//char *song = "KnightRider:d=4,o=5,b=125:16e,16p,16f,16e,16e,16p,16e,16e,16f,16e,16e,16e,16d#,16e,16e,16e,16e,16p,16f,16e,16e,16p,16f,16e,16f,16e,16e,16e,16d#,16e,16e,16e,16d,16p,16e,16d,16d,16p,16e,16d,16e,16d,16d,16d,16c,16d,16d,16d,16d,16p,16e,16d,16d,16p,16e,16d,16e,16d,16d,16d,16c,16d,16d,16d";
//char *song = "Macarena:d=4,o=5,b=180:f,8f,8f,f,8f,8f,8f,8f,8f,8f,8f,8a,8c,8c,f,8f,8f,f,8f,8f,8f,8f,8f,8f,8d,8c,p,f,8f,8f,f,8f,8f,8f,8f,8f,8f,8f,8a,p,2c.6,a,8c6,8a,8f,p,2p";
//char *song = "YMCA:d=4,o=5,b=160:8c#6,8a#,2p,8a#,8g#,8f#,8g#,8a#,c#6,8a#,c#6,8d#6,8a#,2p,8a#,8g#,8f#,8g#,8a#,c#6,8a#,c#6,8d#6,8b,2p,8b,8a#,8g#,8a#,8b,d#6,8f#6,d#6,f.6,d#.6,c#.6,b.,a#,g#";
//char *song = "batman:d=8,o=5,b=180:b,b,a#,a#,a,a,a#,a#,b,b,a#,a#,a,a,a#,a#,4b,p,4b";
//char *song = "MoneyMon:d=4,o=6,b=112:8e7,8e7,8e7,8e7,8e7,8e7,16e,16a,16c7,16e7,8d_7,8d_7,8d_7,8d_7,8d_7,8d_7,16f,16a,16c7,16d_7,d7,8c7,8a,8c7,c7,2a,32a,32c7,32e7,8a7";
//char *song = "Bohemian:d=4,o=5,b=80:16e,2e.,16p,8c,8d,16e,2e,16p,8p,16d,16e,8f,16g,16f,16p,8e,d,16p,8d,8e,8f,16g,16f,16p,8e,2d,16p,16e,2e,16p,8p,8e,8g,8b.,16a,2a,8p,8c6,8c6,8c6,8c6,8c6,8c.6,16a,8f.,8e.,2d.,8p,16a,2a,16p,8p,8g,16a,16a#,2a.,8p,16a,16a,8a#.,16a#,8a#,8a,g.,16p,16c,8c,8g,8g,8a,8a,8a#,8a#,8c6,16a#,a,16p,16g,16a,c.6,16g,16a,2f,16c#,8d#,8c#.,16d#,2c";
//char *song = "WeWillRo:d=4,o=6,b=100:f5,e5,d5,c5,8d5,8d5,p,8d5,8d5,p,f5,e5,d5,c5,8d5,8d5,p,8d5,8d5";
//char *song = "AnotherO:d=16,o=5,b=80:32p,32d#.6,32c#.6,8a#.,8a#.,4a#.,32a#.,a#.,a#.,c#.6,32a#.,4d#.6,32d#.6,32c#.6,8a#.,8a#.,4a#.,32a#.,a#.,a#.,c#.6,32a#.,4d#.6,32d#.6,32c#.6,8a#.,8a#.,4a#.,32a#.,a#.,a#.,c#.6,32a#.,4d#.6,32d#.6,32c#.6,8a#.,8a#.,4a#.,32a#.,a#.,a#.,c#.6,32a#.,4d#6";
//char *song = "LosingMy:d=4,o=5,b=63:2p,8b,8c#6,8b,8f#,a.,8a,8a,a,a,a.,8b,8c#6,8b,8f#,a.,8a,8a,a,a.,8b,8c#6,8b,8f#,a.,8a,8a,a,a.,8b,8c#6,8b,8f#,a,a,8a,a,8g#,2g#";
//char *song = "StarWars:d=4,o=5,b=180:8f,8f,8f,2a#.,2f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8d#6,2c6,p,8f,8f,8f,2a#.,2f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8c6,2a#.6,f.6,8d#6,8d6,8d#6,2c6";
//char *song = "Argentina:d=4,o=5,b=70:8e.4,8e4,8e4,8e.4,8f4,8g4,8a4,g4,8p,8g4,8a4,8a4,8g4,c,g4,8f4,e.4,8p,8e4,8f4,8g4,8d4,d4,8d4,8e4,8f4,c4,16p,8c4,8d4,8c4,8e4,g4,16p,8g4,8g4,8a4,c,16p";
//char *song = "FurElise:d=8,o=5,b=125:32p,e6,d#6,e6,d#6,e6,b,d6,c6,4a.,32p,c,e,a,4b.,32p,e,g#,b,4c.6,32p,e,e6,d#6,e6,d#6,e6,b,d6,c6,4a.,32p,c,e,a,4b.,32p,d,c6,b,2a";
//char *song = "9thSymph:d=4,o=5,b=100:16f#6,16f#6,16f#6,8c#6,16f#6,16f#6,16f#6,8c#6,16p,16f#6,16f#6,16f#6,16f#6,16f#6,16f#6,16f#6,16c#7,16c#7,16c#7,8a#6,16f#6,16f#6,16c#6,16f#6,16f#6,16f#6,16f#6,16d#7,16d#7,16d#7";
//char *song = "5thSymph:d=16,o=5,b=100:g,g,g,4d#,4p,f,f,f,4d,4p,g,g,g,d#,g#,g#,g#,g,d#6,d#6,d#6,4c6,8p,g,g,g,d,g#,g#,g#,g,f6,f6,f6,4d6,8p,g6,g6,f6,4d#6,8p,g6,g6,f6,4d#6";
//char *song = "SwanLake:d=8,o=6,b=112:2c,f5,g5,g#5,a#5,4c.,g#5,4c.,g#5,4c.,f5,g#5,f5,c#5,g#5,2f5.,a#5,g#5,g5,2c,f5,g5,g#5,a#5,4c.,g#5,4c.,g#5,4c.,f5,g#5,f5,c#5,g#5,2f5.,4f5,4g5,4g#5,4a#5,c,c#,4d#.,c#,4c,c#,d#,4f.,d#,4c#,d#,f,4g.,f,4e,4f5,4g5,4g#5,4a#5,c,c#,4d#.,c#,4c,c#,d#,4f.,d#,4c#,d#,f,4g.,f,4e.";
//char *song = "HarryPot:d=8,o=6,b=100:b5,e.,16g,f#,4e,b,4a.,4f#.,e.,16g,f#,4d,f,2b5,p,b5,e.,16g,f#,4e,b,4d7,c#7,4c7,g#,c.7,16b,a#,4a#5,g,2e";
//char *song = "OhOhDenH:d=16,o=5,b=112:4e6,4e6,8d#6,2d6,4d6,8d6,4d.6,4a,8a,8b,4d6,2c#6,8a,8e6,8d#6,2d6,8d6,8d6,8d6,8d6,2a,8a,8b,2c#.6,8e6,8e6,8d#6,2d6,4d6,8d6,8d6,4a.,8a,8b,8d6,2c#6,8a,8a,8b,8c#6,2b,8a,8a,8b,4c#6,8c#6,4c#6,4c#6,8c#6,2a.";
//char *song = "HedwigsT:d=8,o=6,b=125:c.,16d#,d,4c,g,4f.,4d.,c.,16d#,d,4b5,c#,4g5,4p,g5,c.,16d#,d,4c,g,4a#,a,4g#,e,g#.,16g,4f#,p,d#,4c.,4p,g5";
//char *song = "Scatman:d=4,o=5,b=200:32p,8b,16b,32p,8b,16b,32p,8b,2d6,16p,16c#.6,16p.,8d6,16p,16c#6,8b,16p,8f#,2p.,16c#6,8p,16d.6,16p.,16c#6,16b,8p,8f#,2p,32p,2d6,16p,16c#6,8p,16d.6,16p.,16c#6,16a.,16p.,8e,2p.,16c#6,8p,16d.6,16p.,16c#6,16b,8p,8b,16b,32p,8b,16b,32p,8b,2d6,16p,16c#.6,16p.,8d6,16p,16c#6,8b,16p,8f#,2p.,16c#6,8p,16d.6,16p.,16c#6,16b,8p,8f#,2p,32p,2d6,16p,16c#6,8p,16d.6,16p.,16c#6,16a.,16p.,8e,2p.,16c#6,8p,16d.6,16p.,16c#6,16a,8p,8e,2p,32p,16f#.6,16p.,16b.,16p.";
//char *song = "Twilight:d=16,o=5,b=125:8a.,p,c6,p,2b,8p,a,8p,p,c6,p,2b,8p,a,8p,p,c6,p,2b,8p,a,8p,p,a,8p,p,2a,a,8p,p,c6,p,4b,8p,a,8p,p,8c.6,p,b,p,4b,8p,a,8p,p,4b,c6,p,4d.6,8c6,8p,4b,a,p,4a.,4p";
//char *song =  "Powerpuf:d=8,o=5,b=160:g.6,e.6,g6,p,g6,e6,g6,a.6,g.6,f6,p,f6,e6,f6,g.6,e.6,4g.6,p,g6,c.7,g.6,a.6,4f.6,16p,g.6,e.6,g6,p,g6,e6,g6,a.6,g.6,f6,p,f6,e6,f6,g.6,e.6,4g.6,p,g6,c.7,g.6,a.6,4f.6,16p,16c7,16c7,16c7";
//char *song = "Barbie girl:d=4,o=5,b=125:8g#,8e,8g#,8c#6,a,p,8f#,8d#,8f#,8b,g#,8f#,8e,p,8e,8c#,f#,c#,p,8f#,8e,g#,f# ";
//char *song = "we-rock:d=4,o=6,b=80:16d#6,16g#6,16g#5,16g#6,32d#6,32f6,32d#6,32c6,16g#5,16d#5,32g#5,32a#5,32c6,32c#6,16d#6,16g#6,4d#6,16d#6,16g#6,16g#5,16g#6,32d#6,32f6,32c6,16g#5,16d#5,32f#5,32g#5,32a#5,32c6,16c#6,16f#6,4c#6";
//char *song = "Star Trek:d=4,o=5,b=63:8f.,16a#,d#.6,8d6,16a#.,16g.,16c.6,f6";
//char *song = "teletubbies:d=4,o=5,b=125:16g.,8p,16g,8e,g.,8p,a,2f.,16g.,8p,16g,8e,g.,8p,2d.,16g.,8p,16g,8e,g.,8p,a,2f.,2g,2b,2c.6";
//char *song = "Under The sea:d=4,o=5,b=200:8d,8f,8a#,d6,d6,8a#,c6,d#6,d6,a#,8a#4,8d,8f,a#,a#,8c,a,c6,a#,p,8d,8f,8a#,d6,d6,8a#,c6,d#6,d6,a#,8a#4,8d,8f,a#,a#,8c,a,c6,16a#,16d,16a#,16d,16a#,16d,16a#";
//char *song = "DrJones:d=32,o=5,b=70:p,16e,b,e,16e6,b,e,16f#,b,f#,16f#6,b,f#,16a,c#6,a,16e6,e,e6,16b,e6,b,f#6,b,16g#6,16e,b,e,16e6,b,e,16f#,b,f#,16f#6,b,f#,16g#,c#6,g#,16d#6,g#,e6,16b,e6,b,f#6,b,16g#6";
//char *song = "Mamamia:d=16,o=7,b=90:a.6,b.6,d.,2f#,f#.,e.,f#.,e.,8d.,a.6,b.6,d.,2f#,f#.,e.,f#.,e.,8d";
//char *song = "Theme:d=4,o=6,b=160:8c,f,8a,f,8c,b5,2g,8f,e,8g,e,8e5,a5,2f,8c,f,8a,f,8c,b5,2g,8f,e,8c,d,8e,1f,8c,8d,8e,8f,1p,8d,8e,8f_,8g,1p,8d,8e,8f_,8g,p,8d,8e,8f_,8g,p,c,8e,1f";
//char *song = "Theme:d=4,o=6,b=200:8d,8e,2f,8g,8a,g,f,e,f,g,a,g,p,8f,8g,a,p,8g,8f,e,f,e,d,p,8e,8c,d,8p,p,8d,8e,f,p,8e,8f,g,f,g,a,g,f,d";
//char *song = "DeKleine:d=4,o=6,b=125:c,c,8a5,g.5,8f5,8g5,8f5,8g5,g5,p,c,c,8a5,g.5,8f5,8g5,8f5,8g5,c5,p,c,c,8a5,g.5,8f5,8g5,8f5,8g5,g5,p,c,c,8a5,g.5,8f5,8g5,8f5,8g5,c5,p,c,c,8a5,g.5,8f5,8g5,8f5,8g5,g5,p,c,c,8a5,g.5,8f5,8g5,8f5,8g5,c5,p,c,c,8a5,g.5,8f5,8g5,8f5,8g5,g5,p,c,c,8a5,g.5,8f5,8g5,8f5,8g5,c5";
//char *song = "AllYouNe:d=4,o=5,b=100:16d#7,16d#7,16d#7,8d#7,8d#7,8p,16d#7,16d#7,16d#7,8d#7,8d#7,8p,16d#7,16d#7,16e#7,8e#7,16p,8e#6,8p,16a#6,16a#6,8a#6,16g#6,8g#6";
//char *song = "Theme:d=4,o=6,b=200:e5,g5,b5,c,1f5,p,e5,g5,b5,c,2d.5,p,b5,c,d5,2f.5,p,e,f5,d5,e5,1c5";
//char *song = "AllIWant:d=16,o=5,b=140:2c,2e,2g,4b,p,2c6,8p,p,2b,4a,p,2g,8p,p,2d6,2c6,2c6,2b,4c6,p,2b,8p,p,4a,2g,4p,2f,2a,2c6,2d6,2e6,4d6,2c6,2a,4p,2f,4g#,2c6,4p,2d6,4d#6,2d6,4p,4a#,1g#";
//char *song = "FelizNav:d=8,o=5,b=140:a,4d6,c#6,d6,2b.,4p,b,4e6,d6,b,2a.,4p,a,4d6,c#6,d6,4b.,g,4b,4b,a,a,b,a,4g,g,1f#";
//char *song = "Memories:d=4,o=5,b=100:8a#4,8a#4,8a#4,16a#.4,32c6,8c#6,8c6,8a#,8g#,8g#,8f4,8f#,8f4,8f,8f4,8a#,8f4,8g#,8c#,8c#,8c#6,8c#6,8c#6,8c#6,8d#6,8c,8c6,8c,8c6,8c,8c6,8c,8c6,8a#4,8c#6,8a#,16a#.4,32c6,8c#6,8c6,8a#,8g#,8g#,8f4,8f#,8f4,8f,8f4,8a#,8f4,8g#,8c#,8c#,8c#6,8c#6,8c#6,8c#6,8d#6,8c,8c6,8c,8c,8a#,8c6,8c#6,8f6,8a#4,8a#4,8a#4,8a#4,8a#4,8a#4,8a#4,8a#4";
//char *song = "DoctorWh:d=4,o=6,b=80:b.5,8g5,16b.5,8a.5,32g.5,32f#5,g.5,e,32d,32c,8d,8g5,8e.,32d,32c,8d,8b5,2a5,32g5,32f#5,2g5";
//char *song = "PiratesO:d=4,o=5,b=100:8a.,8c.6,8d.6,8c6,16a#,8a,16a,8g,16g,f,16p,16a,16a.,32p,16a,16a,16a,16a,16a,16a,16a,16a,16a,16a,16d.6,32p,16a,16f,16f,16g,16a.,p,16a,16a#,16a#,16a#,16g,16g,16g,16a,16a,16a,16f,16f,16f,16g,16g,16g,16g,16a";
//char *song = "Theme:d=4,o=6,b=200:8d,8e,2f,8g,8a,g,f,e,f,g,a,g,p,8f,8g,a,p,8g,8f,e,f,e,d,p,8e,8c,d,8p,p,8d,8e,f,p,8e,8f,g,f,g,a,g,f,d
//char *song = "HebJeEve:d=16,o=5,b=200:4d6,4f6,4a#.6,4a.6,4f6,4d.6,8a#,8a#,8p,8a#,8p,8a#,4p,8a#,8a#,8p,8a#,8p,8a#,4p,8a#,4d6,4f6,4a#.6,4a.6,4f6,4d#.6,8f,8f,8p,8f,8p,8f,8p,8f,8f,8p,8f,8p,8f,8p,8f,4d#6,4f6,4a#.6,4a.6,4f6,4d#.6,8f,4d#6,4f6,4a#6,8f,4a.6,4f6,4d#.6,8f,4d#6,4f6,4c7,8f,4a#.6,4a6,4a#.6,8a#,8a#,8p,8a#,8p,8a#,4p,8a#,8a#,8p,8a#,8p,8a#,8p,8a#";

const int BUTTON = 8;

int notes[] = { 0,
NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4,
NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5,
NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6,
NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7
};

int val = 0;

void setup(void)
{
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

#define isdigit(n) (n >= '0' && n <= '9')

void play_rtttl(char *p)
{
  //char *song = "The Simpsons:d=4,o=5,b=160:c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g,8p,8p,8f#,8f#,8f#,8g,a#.,8c6,8c6,8c6,c6";
  
  int notes[] = { 0,
NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4,
NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5,
NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6,
NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7
};
  
  // Absolutely no error checking in here

  byte default_dur = 4;
  byte default_oct = 6;
  int bpm = 63;
  int num;
  long wholenote;
  long duration;
  byte note;
  byte scale;

  // format: d=N,o=N,b=NNN:
  // find the start (skip name, etc)

  while(*p != ':') p++;    // ignore name
  p++;                     // skip ':'

  // get default duration
  if(*p == 'd')
  {
    p++; p++;              // skip "d="
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    if(num > 0) default_dur = num;
    p++;                   // skip comma
  }

  Serial.print("ddur: "); Serial.println(default_dur, 10);

  // get default octave
  if(*p == 'o')
  {
    p++; p++;              // skip "o="
    num = *p++ - '0';
    if(num >= 3 && num <=7) default_oct = num;
    p++;                   // skip comma
  }

  Serial.print("doct: "); Serial.println(default_oct, 10);

  // get BPM
  if(*p == 'b')
  {
    p++; p++;              // skip "b="
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    bpm = num;
    p++;                   // skip colon
  }

  Serial.print("bpm: "); Serial.println(bpm, 10);

  // BPM usually expresses the number of quarter notes per minute
  wholenote = (60 * 1000L / bpm) * 4;  // this is the time for whole note (in milliseconds)

  Serial.print("wn: "); Serial.println(wholenote, 10);


  // now begin note loop
  while(*p)
  {
    // first, get note duration, if available
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    
    if(num) duration = wholenote / num;
    else duration = wholenote / default_dur;  // we will need to check if we are a dotted note after

    // now get the note
    note = 0;

    switch(*p)
    {
      case 'c':
        note = 1;
        break;
      case 'd':
        note = 3;
        break;
      case 'e':
        note = 5;
        break;
      case 'f':
        note = 6;
        break;
      case 'g':
        note = 8;
        break;
      case 'a':
        note = 10;
        break;
      case 'b':
        note = 12;
        break;
      case 'p':
      default:
        note = 0;
    }
    p++;

    // now, get optional '#' sharp
    if(*p == '#')
    {
      note++;
      p++;
    }

    // now, get optional '.' dotted note
    if(*p == '.')
    {
      duration += duration/2;
      p++;
    }
  
    // now, get scale
    if(isdigit(*p))
    {
      scale = *p - '0';
      p++;
    }
    else
    {
      scale = default_oct;
    }

    scale += OCTAVE_OFFSET;

    if(*p == ',')
      p++;       // skip comma for next note (or we may be at the end)

    // now play the note

    if(note)
    {
      Serial.print("Playing: ");
      Serial.print(scale, 10); Serial.print(' ');
      Serial.print(note, 10); Serial.print(" (");
      //Serial.print(notes[(scale - 4) * 12 + note], 10);
      Serial.print(") ");
      Serial.println(duration, 10);
      tone(TONE_PIN, notes[(scale - 4) * 12 + note]);
      delay(duration);
      noTone(TONE_PIN);
    }
    else
    {
      Serial.print("Pausing: ");
      Serial.println(duration, 10);
      delay(duration);
    }
  }
   Serial.println("Done.");
}

void loop(void)
{
  
 // play_rtttl(song);
  
  while(1)
  {
    val = digitalRead(BUTTON); // read input value and store it
    
    // check whether the input is HIGH (button pressed)
    if (val == HIGH) 
    {
      //play_rtttl(song);
    } 
    else 
    {
      play_rtttl(song);
    };
  }  
}
