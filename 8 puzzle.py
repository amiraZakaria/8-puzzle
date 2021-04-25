import random
N=3
a, b = -1, -1
grid = [['0' for x in range(N)] for y in range(N)]



# This function prints the grid of Gomoku as the game progresses
def print_grid():
    print('--' + '---' * N + '--')
    for i in range(N):
        print(end='|  ')
        for j in range(N):
            print(grid[i][j], end='  ')
        print(end='|')
        print()
    print('--' + '---' * N + '--')

def check_win():
    c=1
    for i in range(N):
        for j in range(N):
            c+=1
            if grid[i][j]!=c:
                return False
    return True

def check_valid_num(a):
    for i in range(N):
        for j in range(N):
            if grid[i][j]==a:
                return False
    return True

def move(i):
    global a
    global b
    if i == 3:
        grid[a][b]=grid[a][b-1]
        grid[a][b-1]=0
        b -= 1

    elif i == 1:
        grid[a][b]=grid[a+1][b]
        grid[a+1][b]=0
        a += 1

    elif i == 2:
        grid[a][b]=grid[a-1][b]
        grid[a-1][b]=0
        a -= 1

    elif i == 4:
        grid[a][b]=grid[a][b+1]
        grid[a][b+1]=0
        b += 1


# This function checks if given position is valid or not
def check_valid_direction(i):
    if i == 1 or i == 2 or i == 3 or i == 4:
        return True
    else:
        return False

def check_available_move(i):
    if i == 4:
        if b + 1 > N - 1:
            return False  # right
    elif i == 2:
        if a - 1 < 0:
            return False  # up
    elif i == 1:
        if a + 1 > N - 1:
            return False  # down
    elif i == 3:
        if b - 1 < 0:
            return False  # left
    return True

# This function clears the game structures
def grid_clear():
    for i in range(N):
        for j in range(N):
            grid[i][j]=0

def set_cell():
    global a
    global b
    for i in range(N):
        for j in range(N):
            d = random.randint(0,9)
            while True:
                if not check_valid_num(d):
                   d = random.randint(0, 9)
                else:
                    break
            grid[i][j] = d

    for i in range(N):
        if 9 in grid[i]:
           j=grid[i].index(9)
           a=i
           b=j
           grid[i][j] = 0

# This function reads a valid position input
def read_input():
    i = int(input('Enter the direction: '))
    while not check_valid_direction(i) or not check_available_move(i):
        i = int(input('Enter a valid direction: '))
    return i


# MAIN FUNCTION
def play_game():
    print("8 puzzel Game!!")
    print("Welcome...")
    print("============================")
    while True:
        # Prints the grid
        print_grid()
        i = read_input()
        # Check if the grid has a tie state
        move(i)
        if check_win():
            print_grid()
            move(i)
            print("Congrats, YOU WON")
            break

while True:
    grid_clear()
    set_cell()
    play_game()
    c = input('Play Again [Y/N] ')
    if c not in 'yY':
        break
