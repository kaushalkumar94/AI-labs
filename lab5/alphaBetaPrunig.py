import math

# Tic-Tac-Toe Board
board = [" " for _ in range(9)]

def print_board(b):
    print("\n")
    for i in range(3):
        print(" " + " | ".join(b[i*3:(i+1)*3]))
        if i < 2:
            print("---+---+---")
    print("\n")

def is_winner(b, player):
    win_states = [
        [0,1,2], [3,4,5], [6,7,8],  # rows
        [0,3,6], [1,4,7], [2,5,8],  # cols
        [0,4,8], [2,4,6]            # diagonals
    ]
    for state in win_states:
        if all(b[pos] == player for pos in state):
            return True
    return False

def is_draw(b):
    return " " not in b

def evaluate(b):
    if is_winner(b, "X"):
        return 1
    elif is_winner(b, "O"):
        return -1
    return 0

def minimax(b, depth, alpha, beta, is_maximizing):
    score = evaluate(b)

    if score == 1 or score == -1:
        return score
    if is_draw(b):
        return 0

    if is_maximizing:  # AI = X
        best = -math.inf
        for i in range(9):
            if b[i] == " ":
                b[i] = "X"
                val = minimax(b, depth+1, alpha, beta, False)
                b[i] = " "
                best = max(best, val)
                alpha = max(alpha, best)
                if beta <= alpha:
                    break
        return best
    else:  # Human = O
        best = math.inf
        for i in range(9):
            if b[i] == " ":
                b[i] = "O"
                val = minimax(b, depth+1, alpha, beta, True)
                b[i] = " "
                best = min(best, val)
                beta = min(beta, best)
                if beta <= alpha:
                    break
        return best

def best_move():
    best_val = -math.inf
    move = -1
    for i in range(9):
        if board[i] == " ":
            board[i] = "X"
            move_val = minimax(board, 0, -math.inf, math.inf, False)
            board[i] = " "
            if move_val > best_val:
                move = i
                best_val = move_val
    return move

# Game loop
def play_game():
    print("Welcome to Tic-Tac-Toe with Alpha-Beta AI!")
    print("You are O, AI is X")
    print("Enter positions as 1-9 (like numpad):")
    print(" 1 | 2 | 3 ")
    print("---+---+---")
    print(" 4 | 5 | 6 ")
    print("---+---+---")
    print(" 7 | 8 | 9 ")

    print_board(board)

    while True:
        # Human move
        human_move = int(input("Enter your move (1-9): ")) - 1
        if board[human_move] != " ":
            print("Invalid move! Try again.")
            continue
        board[human_move] = "O"
        print_board(board)

        if is_winner(board, "O"):
            print("You win!")
            break
        if is_draw(board):
            print("It's a draw!")
            break

        # AI move
        print("AI is thinking...")
        ai_move = best_move()
        board[ai_move] = "X"
        print_board(board)

        if is_winner(board, "X"):
            print(" AI wins!")
            break
        if is_draw(board):
            print("It's a draw!")
            break

# Run the game
if __name__ == "__main__":
    play_game()
