# game-of-hex
Command line representation of the game Hex with the ability to play against an AI player

> Hex is a strategy board game for two players played on a hexagonal grid, theoretically of any size and several possible 
> shapes, but traditionally as an 11×11 rhombus. Players alternate placing markers or stones on unoccupied spaces in an 
> attempt to link their opposite sides of the board in an unbroken chain. One player must win; there are no draws.  
https://en.wikipedia.org/wiki/Hex_(board_game)

### How To Build

+ `cd game-of-hex/HexGame/build`  
+ `cmake ..`  
+ `make`  

### How To Run

+ `cd game-of-hex/HexGame/build`  
+ `./Hex`  

### Example With Two AI Playing Eachother
```
Welcome to a game of Hex!
The board will be NxN in size, what would you like N to be?
7 
Time for Player 1 to register...
AI? (y/n)
y
Player 1: Jeremy
Time for Player 2 to register...
AI? (y/n)
n
what's your name?
TGilmour94
  . - . - . - . - . - . - .
   \ / \ / \ / \ / \ / \ / \
    . - . - . - . - . - . - .
     \ / \ / \ / \ / \ / \ / \
      . - . - . - . - . - . - .
       \ / \ / \ / \ / \ / \ / \
        . - . - . - . - . - . - .
         \ / \ / \ / \ / \ / \ / \
          . - . - . - . - . - . - .
           \ / \ / \ / \ / \ / \ / \
            . - . - . - . - . - . - .
             \ / \ / \ / \ / \ / \ / \
              . - . - . - . - . - . - .
(x=0,y=0)  <.....>  (x=N,y=0)
  . - . - . - . - . - . - .
   \ / \ / \ / \ / \ / \ / \
    . - . - . - . - . - . - .
     \ / \ / \ / \ / \ / \ / \
      . - . - . - . - . - . - .
       \ / \ / \ / \ / \ / \ / \
        . - . - . - . - . - . - .
         \ / \ / \ / \ / \ / \ / \
          . - . - . - . - . - . - .
           \ / \ / \ / \ / \ / \ / \
            . - X - . - . - . - . - .
             \ / \ / \ / \ / \ / \ / \
              . - . - . - . - . - . - .
(x=0,y=0)  <.....>  (x=N,y=0)
TGilmour94, please enter the coordinates of your next move (x,y)
4 4
  . - . - . - . - . - . - .
   \ / \ / \ / \ / \ / \ / \
    . - . - . - . - . - . - .
     \ / \ / \ / \ / \ / \ / \
      . - . - . - . - O - . - .
       \ / \ / \ / \ / \ / \ / \
        . - . - . - . - . - . - .
         \ / \ / \ / \ / \ / \ / \
          . - . - . - . - . - . - .
           \ / \ / \ / \ / \ / \ / \
            . - X - . - . - . - . - .
             \ / \ / \ / \ / \ / \ / \
              . - . - . - . - . - . - .
(x=0,y=0)  <.....>  (x=N,y=0)
  . - . - . - . - . - . - .
   \ / \ / \ / \ / \ / \ / \
    . - . - . - . - . - . - .
     \ / \ / \ / \ / \ / \ / \
      . - . - . - . - O - . - .
       \ / \ / \ / \ / \ / \ / \
        . - . - . - . - . - . - .
         \ / \ / \ / \ / \ / \ / \
          . - X - . - . - . - . - .
           \ / \ / \ / \ / \ / \ / \
            . - X - . - . - . - . - .
             \ / \ / \ / \ / \ / \ / \
              . - . - . - . - . - . - .
(x=0,y=0)  <.....>  (x=N,y=0)
```
