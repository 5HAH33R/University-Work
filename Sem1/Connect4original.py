"""
University Project for Course : Programming Fundamentals

Game Name : 4 IN A ROW

*Concept* : Imagine a vertical grid with 6 rows and 7 columns. Two players, X and O, take turns dropping their pieces into one of the columns. 
The piece falls to the lowest empty space in that column. The first player to get four of their pieces in a row, either horizontally, vertically, or diagonally, wins the game. If the board fills up without a winner, it's a draw.

Note : I have used Black Formatter for python after completing the code to make it more readable , all the code was written in VS Code in python 3.11

"""


#libraries used
import pygame
import sys
import math

# initialising rows , cols and the 2d array
rows, cols = (6, 7)
arr = [[0] * cols for _ in range(rows)]

# colours used
Blue = (0, 0, 255)
Black = (0, 0, 0)
Red = (255, 0, 0)
Yellow = (255, 255, 0)


# functions
def is_choice_valid(Choice):
    if arr[0][Choice] == 0:
        return True


def insert_piece(Choice, player):
    global arr
    for i in range(5, 0, -1):
        if arr[i][Choice] == 0:
            arr[i][Choice] = player
            break


def CreateBoard():
    global arr
    for i in range(6):
        for j in range(7):
            print(arr[i][j], end=" ")
        print("\n", end="")
    print("- - - - - - -")
    print("0 1 2 3 4 5 6")


def Winning_move(player):
    global arr
    # checking all horizontals
    for i in range(rows):
        for j in range(cols - 3):
            if (
                arr[i][j] == player
                and arr[i][j + 1] == player
                and arr[i][j + 2] == player
                and arr[i][j + 3] == player
            ):
                return True

    # checking all verticals
    for i in range(rows - 3):
        for j in range(cols):
            if (
                arr[i][j] == player
                and arr[i + 1][j] == player
                and arr[i + 2][j] == player
                and arr[i + 3][j] == player
            ):
                return True

    # checking all  positive diagonals
    for i in range(rows - 3):
        for j in range(cols - 3):
            if (
                arr[i][j] == player
                and arr[i + 1][j + 1] == player
                and arr[i + 2][j + 2] == player
                and arr[i + 3][j + 3] == player
            ):
                return True

    # checking all  negative  diagonals
    for i in range(3, rows):
        for j in range(cols - 3):
            if (
                arr[i][j] == player
                and arr[i - 1][j + 1] == player
                and arr[i - 2][j + 2] == player
                and arr[i - 3][j + 3] == player
            ):
                return True


# Main Code
pygame.init()

SquareSize = 100
height = (rows * SquareSize) + SquareSize  # for additional row on top
width = cols * SquareSize
Circle_Radius = int(
    SquareSize / 2 - 5
)  # -5 so circles dont touch and it looks like a board , /2 because we need the diameter

size = (width, height)
myfont = pygame.font.SysFont(None, 75)  # initialises font

screen = pygame.display.set_mode(size)
screen.fill(Black)



def draw_board():
    for i in range(cols):
        for j in range(rows):
            pygame.draw.rect(
                screen,
                Blue,
                (i * SquareSize, j * SquareSize + SquareSize, SquareSize, SquareSize),
            )
            if arr[j][i] == 0:
                pygame.draw.circle(
                    screen,
                    Black,
                    (
                        int(i * SquareSize + SquareSize / 2),
                        int(j * SquareSize + SquareSize + SquareSize / 2),
                    ),
                    Circle_Radius,
                )
    for i in range(cols):
        for j in range(rows):
            if arr[j][i] == 1:
                pygame.draw.circle(
                    screen,
                    Red,
                    (
                        int(i * SquareSize + SquareSize / 2),
                        int(j * SquareSize + SquareSize + SquareSize / 2),
                    ),
                    Circle_Radius,
                )
            elif arr[j][i] == 2:
                pygame.draw.circle(
                    screen,
                    Yellow,
                    (
                        int(i * SquareSize + SquareSize / 2),
                        int(j * SquareSize + SquareSize + SquareSize / 2),
                    ),
                    Circle_Radius,
                )
    pygame.display.update()


print(CreateBoard())  # for terminal
draw_board()  # for pygame window
pygame.display.update()

Game_over = False
turn = 0
PlayerChoice = 0
while not Game_over:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()  # so program safely exits

        if event.type == pygame.MOUSEMOTION:
            pygame.draw.rect(
                screen, Black, (0, 0, width, SquareSize)
            )  # so red circles are deleted too after being created at every possible (x,y) coordinate
            posx = event.pos[0]
            if turn == 0:
                pygame.draw.circle(
                    screen, Red, (posx, int(SquareSize / 2)), Circle_Radius
                )
            else:
                pygame.draw.circle(
                    screen, Yellow, (posx, int(SquareSize / 2)), Circle_Radius
                )
        pygame.display.update()

        if event.type == pygame.MOUSEBUTTONDOWN:
            pygame.draw.rect(
                screen, Black, (0, 0, width, SquareSize)
            )  # to fix Text behind the circles on top when won
            if turn == 0:
                posx = event.pos[0]
                PlayerChoice = int(math.floor(posx / SquareSize))
                if PlayerChoice <= 6 and PlayerChoice > -1:
                    if is_choice_valid(PlayerChoice) == True:
                        insert_piece(PlayerChoice, 1)
                        print(CreateBoard())
                        draw_board()
                        pygame.display.update()
                        if Winning_move(1) == True:
                            label = myfont.render("Player 1 Wins", 1, Red)
                            screen.blit(label, (40, 30))
                            pygame.display.update()
                            Game_over = True
                    turn = turn + 1
            else:
                posx = event.pos[0]
                PlayerChoice = int(math.floor(posx / SquareSize))
                if PlayerChoice <= 6 and PlayerChoice > -1:
                    if is_choice_valid(PlayerChoice) == True:
                        insert_piece(PlayerChoice, 2)
                        print(CreateBoard())
                        draw_board()
                        pygame.display.update()
                        if Winning_move(2) == True:
                            label = myfont.render("Player 1 Wins", 1, Red)
                            screen.blit(label, (40, 30))  # updates in a specified area
                            pygame.display.update()
                            Game_over = True
                    turn = turn - 1
    if Game_over:
        pygame.time.wait(5000)  # so Game doesnt close automatically after a player wins
