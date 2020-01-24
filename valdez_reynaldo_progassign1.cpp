#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int score_limit = 100;
int dice_roll();
int user_turn(int& humanTotalScore);
int CPU_turn(int& computerTotalScore);


int main()
{
	bool win = 1;
	int user_total_score = 0, CPU_total_score = 0;

	cout << "Its your turn. Press r to roll.\n";
	if ((user_total_score < score_limit) && (CPU_total_score < score_limit))
	{
		win = 1;
	}
	else
	{
		win = 0;
	}
	do
	{
		cout << "CPU Score: " << CPU_total_score << endl;
	   
		user_turn(user_total_score);
		CPU_turn(CPU_total_score);
	}
	while(win == 1);
   
	if ((win = 1) && (user_total_score > CPU_total_score))
	{
		cout << "You win!";
	}
	else
	{
		cout << "You lost!";
	}
   
   
	return 0;
}


int user_turn(int& user_total_score)
{
	int current_score = 0;
	int final_roll;
	char roll_or_hold;

	cout << "Your total score is: " << user_total_score << "." << endl;
	cout << "Press r to roll again, or h to hold." << endl;
	cin >> roll_or_hold;

	while (roll_or_hold == 'r')
	{
		srand (time(NULL));
		final_roll = dice_roll();
		if (final_roll == 1)
		{
			cout << "You rolled a 1, yout turn has ended." << endl;
			break;
		}
		else
		{
			current_score += final_roll;
			cout << "You roll a " << final_roll << ". Your score this turn is: " << current_score << endl;
			cout << "Press r to roll again, or h to hold." << endl;
			cin >> roll_or_hold;
		}
	}
	while (roll_or_hold == 'h')
	{
		user_total_score += current_score;
		break;
	}
   
	return user_total_score;
}

int CPU_turn(int& CPU_total_score)
{
	int current_score = 0;
	int final_roll;

	cout << "Computer's total score is: " << CPU_total_score << "." << endl;
	while ((current_score <= 20) && (current_score != 1))
	{
		final_roll = dice_roll();
		if (final_roll == 1)
		{
			cout << "The computer rolled a 1, ending their turn." << endl;
			break;
		}
		else
		{
			current_score += final_roll;
			cout << "The computer rolls a " << final_roll << ". Computer's score this turn is: " << current_score << endl;
		}
	}
	if(current_score >= 20)
	{
		CPU_total_score += current_score;
		cout << "After the computer's turn, they have gained an additional " << final_roll << " points." << endl;
	}
   
	return CPU_total_score;
}

int dice_roll()
{
	int roll;

	roll = (int)(rand()%6)+1;
   
	return roll;
}
