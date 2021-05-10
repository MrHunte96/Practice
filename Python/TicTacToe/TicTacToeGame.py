import keyboard
from os import system
import time

keys   = ['1','2','3','4','5','6','7','8','9']
pieces = [' ',' ',' ',' ',' ',' ',' ',' ',' ']
turn = True
currPiece = 'x'
gameMode = 0
running = True
won = False

def SelectGameMode():
    print("  Welcome to Tic-Tac-Toe")
    print("  Please select game mode")
    print("  [1] Player v.s. CPU")
    print("  [2] Player v.s. Player")

    global gameMode
    while gameMode == 0:
        if keyboard.is_pressed('1'): # 1 Player
            gameMode = 1
        elif keyboard.is_pressed('2'): # 2 Player
            gameMode = 2
    
    # Go next state
    global stateFn
    stateFn = PlayGame

stateFn = SelectGameMode

# Toggle the pieces turn
def ToggleTurn():
    global turn
    global currPiece
    turn = not turn
    currPiece = 'x' if turn else 'o'
    
    CheckBoard()

# Check where pieces are placed
def CheckKeys():
    for k in keys:
        if keyboard.is_pressed(k) and pieces[int(k)-1] == ' ':
            # Update the board
            pieces[int(k)-1] = currPiece
            return True

def CheckBoard():
    pass

def AIMove():
    pass

# Clear Screen
def ClearPrints():
    system('cls')

# Print the board
def PrintBoard():
    # Print board
    print("  ", pieces[6], "|", pieces[7], "|", pieces[8])
    print("  ---+---+---")
    print("  ", pieces[3], "|", pieces[4], "|", pieces[5])
    print("  ---+---+---")
    print("  ", pieces[0], "|", pieces[1], "|", pieces[2])
    if won:
        print("\n[Player", "1" if turn else "2", "WON!]")
        running = False
    else:
        print("\n[Player", "1" if turn else "2", "turn]")

def PlayGame():
    ClearPrints()
    PrintBoard()

    global stateFn
    stateFn = PlayingGame

def PlayingGame():
    if CheckKeys():
        ToggleTurn()
        if gameMode == 1 and not won: # vs ai
            AIMove()
            ToggleTurn()
        ClearPrints()
        PrintBoard()

################################################################################

def main():
    ClearPrints()

    while running:
        stateFn()
        if keyboard.is_pressed('esc') == True:
            running = False

################################################################################

if __name__ == "__main__":
    main()