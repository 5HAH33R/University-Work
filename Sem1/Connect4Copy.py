import pygame 
import sys
import math

# Initialising rows, cols and the 2D array
rows, cols = (6, 7)
arr = [[0] * cols for _ in range(rows)]

# Colours used
Blue = (0, 0, 255)
Black = (0, 0, 0)
Red = (255, 0, 0)
Yellow = (255, 255, 0)

# Functions
def is_choice_valid(choice):
    return arr[0][choice] == 0

def insert_piece(choice, player):
    global arr
    for i in range(5, -1, -1):
        if arr[i][choice] == 0:
            arr[i][choice] = player
            break
        
def create_board():
    global arr
    for i in range(6):
        for j in range(7):
            print(arr[i][j], end=" ")
        print()
    print("- - - - - - -")
    print("0 1 2 3 4 5 6")

def winning_move(player):
    global arr
    # Check all horizontals
    for i in range(rows):
        for j in range(cols - 3):
            if all(arr[i][j + k] == player for k in range(4)):
                return True

    # Check all verticals
    for i in range(rows - 3):
        for j in range(cols):
            if all(arr[i + k][j] == player for k in range(4)):
                return True

    # Check all positive diagonals
    for i in range(rows - 3):
        for j in range(cols - 3):
            if all(arr[i + k][j + k] == player for k in range(4)):
                return True

    # Check all negative diagonals
    for i in range(3, rows):
        for j in range(cols - 3):
            if all(arr[i - k][j + k] == player for k in range(4)):
                return True

    return False

# Main Code
pygame.init()

SquareSize = 100
height = (rows * SquareSize) + SquareSize  # For additional row on top
width = cols * SquareSize
Circle_Radius = int(SquareSize / 2 - 5)  # So circles don't touch and it looks like a board

size = (width, height)
screen = pygame.display.set_mode(size)
screen.fill(Black)

myfont = pygame.font.SysFont(None, 75)  # Initialises font

def draw_board():    
    for i in range(cols):
        for j in range(rows):
            pygame.draw.rect(screen, Blue, (i * SquareSize, j * SquareSize + SquareSize, SquareSize, SquareSize))
            pygame.draw.circle(screen, Black, (int(i * SquareSize + SquareSize / 2), int(j * SquareSize + SquareSize * 1.5)), Circle_Radius)
    for i in range(cols):
        for j in range(rows):
            if arr[j][i] == 1:
                pygame.draw.circle(screen, Red, (int(i * SquareSize + SquareSize / 2), int(j * SquareSize + SquareSize * 1.5)), Circle_Radius)
            elif arr[j][i] == 2:
                pygame.draw.circle(screen, Yellow, (int(i * SquareSize + SquareSize / 2), int(j * SquareSize + SquareSize * 1.5)), Circle_Radius)
    pygame.display.update()

create_board()
draw_board()

Game_over = False
turn = 0

while not Game_over:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()

        if event.type == pygame.MOUSEMOTION:
            pygame.draw.rect(screen, Black, (0, 0, width, SquareSize))
            posx = event.pos[0]
            if turn == 0:
                pygame.draw.circle(screen, Red, (posx, int(SquareSize / 2)), Circle_Radius)
            else:
                pygame.draw.circle(screen, Yellow, (posx, int(SquareSize / 2)), Circle_Radius)
            pygame.display.update()

        if event.type == pygame.MOUSEBUTTONDOWN:
            pygame.draw.rect(screen, Black, (0, 0, width, SquareSize))
            posx = event.pos[0]
            PlayerChoice = int(math.floor(posx / SquareSize))
            
            if 0 <= PlayerChoice <= 6:
                if is_choice_valid(PlayerChoice):
                    insert_piece(PlayerChoice, 1 if turn == 0 else 2)
                    create_board()
                    draw_board()
                    
                    if winning_move(1 if turn == 0 else 2):
                        label = myfont.render(f"Player {turn + 1} Wins!", 1, Red if turn == 0 else Yellow)
                        screen.blit(label, (40, 10))
                        pygame.display.update()
                        Game_over = True
                    
                    turn = (turn + 1) % 2

    if Game_over:
        pygame.time.wait(5000)
