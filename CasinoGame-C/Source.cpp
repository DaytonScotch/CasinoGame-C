#include <stdio.h>
#include <stdlib.h>

int rules();

int round1();

int main() 
{
	rules();

	printf("\n\n");

	round1();

	return 0;

}

int round1()
{
	char name[50];
	printf("Enter player name: ");
	scanf_s("%s", &name, 50);
	printf("\n\n");

	int deposit;
	printf("Enter the amount to deposit in player account: ");
	scanf_s("%d", &deposit);
	printf("\n\n");

	printf("Your account has a balance of $%d", deposit);
	printf("\n\n");

	int bet1;
	printf("%s, Enter your bet amount: $", name);
	scanf_s("%d", &bet1);
	printf("\n\n");

	if(bet1 > deposit)
	{
		printf("Insufficient Balance\n");
		printf("Enter another amount: $");
		scanf_s("%d", &bet1);
	}

	printf("\n\n");

	int computer1;
	computer1 = rand() % 10;

	int guess1;
	printf("Guess a number between 1 and 10: ");
	scanf_s("%d", &guess1);
	printf("\n\n");

	if(guess1 > 10)
	{
		printf("Too high! Try another guess: ");
		scanf_s("%d", &guess1);
	}

	printf("\n\n");

	if (guess1 == computer1)
	{
		printf("Correct!\n\n");
		printf("You have won $%d", bet1);

		int bet2;
		bet2 = bet1 * 10;

		int new_won;
		if (bet1 == deposit)
		{
			new_won = bet2 + 0;
		}
		else
		{
			new_won = bet2 + deposit;
			printf("You have won $%d", new_won);
		}
	}
	if(guess1 != computer1)
	{
		printf("You just lost yourself $%d !", bet1);
		printf("\n\n");
		printf("The correct number is %d", computer1);
		printf("\n\n");

		int new_loss;
		new_loss = deposit - bet1;
		
		printf("You now have a balance of $%d", new_loss);
		printf("\n\n");

		if (new_loss == 0)
		{
			printf("You player account is now empty.\n");
			printf("Thanks for playing!\n\n");
		}
		else
		{
			int choice;
			printf("Would you like to play again?\n\n");
			printf("Enter 1 for Yes or 2 for No:");
			scanf_s("%d", &choice);
			printf("\n\n");

			if (choice == 1)
			{
				rules();

				printf("\n\n");

				printf("Your current player account balance is: $%d", new_loss);

				printf("\n\n");

				int bet3;
				printf("%s, Enter your bet amount: $", name);
				scanf_s("%d", &bet3);
				printf("\n\n");

				if(bet3 > new_loss)
				{
					printf("Insufficient Balance\n");
					printf("Enter another amount: $");
					scanf_s("%d", &bet3);
				}

				int guess2;
				printf("Guess a number between 1 and 10: ");
				scanf_s("%d", &guess2);
				printf("\n\n");

				int computer2;
				computer2 = 9;

				if(guess2 > 10)
				{
					printf("You guessed too high!\n");
					printf("Try again: ");
					scanf_s("%d", &guess2);
					printf("\n\n");
				}
				if (guess2 == computer2)
				{
					printf("You have won $%d", bet3);
					printf("\n\n");

					int b;
					b = bet3 * 10;

					int b1;
					if (bet3 == new_loss)
					{
						b1 = b + 0;
					}
					else
					{
						b1 = b + new_loss;
					}
					printf("You just won $%d !!", b1);
				}
				if (guess2 != computer2)
				{
					printf("You just lost $%d !!", bet3);
					printf("\n\n");

					int b2;
					b2 = new_loss - bet3;

					printf("Your current account balance is $%d", b2);
					printf("\n\n");

					if (b2 == 0)
					{
						printf("Your player account is cleaned out!");
						printf("Thank you for playing!");
					}
				}
			}
			else if (choice == 2)
			{
				printf("Thanks for playing! Please come again!");
			}
		}
	}
	return 0;

}

	int rules()
	{
		printf("----------------------------------------------------------------\n");
		printf("RULES\n");
		printf("Chose a number between 1 and 10\n");
		printf("If you guess correctly, you win 10x the amount of your bet!\n");
		printf("Guess incorrectly, you lose the bet....\n");
		printf("----------------------------------------------------------------\n");

		return 0;
	}