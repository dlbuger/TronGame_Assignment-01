# Tron Game
### UWS subject - OOP Assignment 01  
*Create on 20 August 2019*
### `@Jason Cao`  
- Requirement is in ./doc
- Source Code is in ./src
- Executable file is in ./out

## Class Structure
### Player

|Player                         |HumanPlayer:virtual Player     |Bot: virtual Player            |
|      ---                      |---                            |---                            |
|id                             |Player::generateChoice()       |virtul char generateChoice()=0 | 
|name                           |                               |preMove()                      |  
|color                          |                               |bool isSuicide()               |
|-------------------------------|                               |char popChoice()               |                              
|getColor()                     |
|move()                         |
|int[2] getPosition()           |
|virtual char generateChoice(); |
|moveUp()                       |
|moveDown()                     |
|moveLeft()                     |
|moveRight()                    |

### Bot
|EasyBot: virtual Bot        |HardBot: virtual Bot|
|---                         |---|
|char generateChoice()       |char generateChoice()|

