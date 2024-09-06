#include <iostream>
#include <ctime>

#define BOARD_SPACE 9

void drawBoard(char *spaces);
void playerTurn(char *spaces, char player, char computer);
void computerTurn(char *spaces, char computer, char player);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main(int argc, char const *argv[])
{
    char spaces[BOARD_SPACE]{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char playerMarker{'X'};
    char computerMarker{'O'};
    bool gaming = true;

    drawBoard(spaces);
    while (gaming)
    {
        playerTurn(spaces, playerMarker, computerMarker);
        drawBoard(spaces);
        if (checkWinner(spaces, playerMarker, computerMarker))
        {
            gaming = false;
            break;
        }
        else if (checkTie(spaces))
        {
            gaming = false;
            break;
        }
        computerTurn(spaces, computerMarker, playerMarker);
        drawBoard(spaces);
        if (checkWinner(spaces, playerMarker, computerMarker))
        {
            gaming = false;
            break;
        }
        else if (checkTie(spaces))
        {
            gaming = false;
            break;
        }
    }
    return 0;
}

void drawBoard(char *spaces)
{
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << std::endl;
    std::cout << "     |     |     " << std::endl
              << std::endl;
}

void playerTurn(char *spaces, char player, char computer)
{
    int choice;
    std::cout << "Pick a spot (1-9): ";
    std::cin >> choice;
    while (choice < 1 || choice > 9)
    {
        std::cout << "Pick again (1-9): ";
        std::cin >> choice;
    }
    choice--;
    while (spaces[choice] != player && spaces[choice] != computer)
    {
        spaces[choice] = player;
        break;
    }
}

void computerTurn(char *spaces, char computer, char player)
{
    srand(time(0));
    int choice = rand() % 9;
    while (spaces[choice] == player || spaces[choice] == computer)
    {
        choice = rand() % 9;
    }
    std::cout << "Computer chose spot " << choice + 1 << std::endl;
    spaces[choice] = computer;
}

bool checkWinner(char *spaces, char player, char computer)
{
    if (spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        (spaces[0] == player) ? std::cout << "You win!" << std::endl : std::cout << "You lose. " << std::endl;
        return true;
    }
    else if (spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        (spaces[3] == player) ? std::cout << "You win!" << std::endl : std::cout << "You lose. " << std::endl;
        return true;
    }
    else if (spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        (spaces[6] == player) ? std::cout << "You win!" << std::endl : std::cout << "You lose. " << std::endl;
        return true;
    }
    else if (spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        (spaces[0] == player) ? std::cout << "You win!" << std::endl : std::cout << "You lose. " << std::endl;
        return true;
    }
    else if (spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        (spaces[1] == player) ? std::cout << "You win!" << std::endl : std::cout << "You lose. " << std::endl;
        return true;
    }
    else if (spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        (spaces[2] == player) ? std::cout << "You win!" << std::endl : std::cout << "You lose. " << std::endl;
        return true;
    }
    else if (spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        (spaces[0] == player) ? std::cout << "You win!" << std::endl : std::cout << "You lose. " << std::endl;
        return true;
    }
    else if (spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        (spaces[2] == player) ? std::cout << "You win!" << std::endl : std::cout << "You lose. " << std::endl;
        return true;
    }

    return false;
}

bool checkTie(char *spaces)
{
    char nums[BOARD_SPACE]{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < BOARD_SPACE; ++i)
    {
        for (int j = 0; j < BOARD_SPACE; ++j)
        {
            if (spaces[i] == nums[j]){
                return false;
            }
        }
    }
    std::cout << "It's a tie!" << std::endl;
    return true;
}
