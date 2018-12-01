import random


def operation(var1, var2):
    if var1 in ["1", "rock", "Rock"] and var2 == "Scissors":
        print("Rock wins!")
    elif var1 in ["1", "rock", "Rock"] and var2 == "Paper":
        print("Paper wins!")
    elif var1 in ["2", "scissors", "Scissors"] and var2 == "Paper":
        print("Scissors wins!")
    elif var1 in ["2", "scissors", "Scissors"] and var2 == "Rock":
        print("Rock wins!")
    elif var1 in ["3", "paper", "Paper"] and var2 == "Scissors":
        print("Scissors wins!")
    elif var1 in ["3", "paper", "Paper"] and var2 == "Rock":
        print("Paper wins!")
    elif var1 in ["3", "paper", "Paper"] and var2 == "Paper":
        print("Draw!")
    elif var1 in ["2", "scissors", "Scissors"] and var2 == "Scissors":
        print("Draw!")
    elif var1 in ["1", "rock", "Rock"] and var2 == "Rock":
        print("Draw!")
    else:
        print("Sorry, try again.")


def main():
    var1 = input("1. Rock, 2. Scissors, 3. Paper\n")
    var2 = random.choice(["Rock", "Paper", "Scissors"])
    print(var2)
    operation(var1, var2)
    question = input("Would you like play again? Y/N\n")
    if question in ["N", 'n']:
        return
    elif question in ["Y", 'y']:
        main()


main()