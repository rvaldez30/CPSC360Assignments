#include <iostream>

using namespace std;

const int row = 15;
const int seat = 30;
double price[row][seat];
char availability[row][seat];

int display_the_menu();
void enter_the_price(double[][seat], int, int);
void show_the_price(double[][seat], int);
void OG_availability(char[][seat], int, int);
void show_the_availability(char[][seat], int,int);
int get_the_row();
int get_the_seat();
bool is_sold(int, int);

int main()
{
	double sale_total = 0;
	int seat_sold = 0;
	int again = 0;
	
	int seat_tavailable = 0;
		
		int total_tavailable = 0;
		
		enter_the_price(price, row, seat);
		
		OG_availability(availability, row, seat);
		
		do
		{
			show_the_availability(availability, row, seat);
			
			display_the_menu();
			int choice;
			cin >> choice;
			int trow;
			int tseat;
			
			switch (choice)
			
			{
				case 1:
					show_the_availability(availability, row, seat);
					cout << "Press any key to proceed." << endl;
					system("Pause");
					break;
					
				case 2:
					trow = get_the_row();
					cout << "The price for the row " << trow + 1 << " is $";
					show_the_price(price, trow);
					cout << "Press any key to proceed." << endl;
					system("Pause");
					break;
					
				case 3:
					trow = get_the_row();
					tseat = get_the_seat();
					
					bool sold;
					sold = is_sold(trow, tseat);
					
					while (sold)
					{
						cout << "The seat you entered has already been sold." << endl;
						
						cout << "Please choose a different seat." << endl;
						
						trow = get_the_row();
						tseat = get_the_seat();
						sold = is_sold(trow, tseat);
					}
					
					cout << "Price for row " << trow + 1 << "is $";
					
					show_the_price(price, trow);
					availability[trow][tseat] = '*';
					sale_total += price[trow][tseat];
					seat_sold++;
					cout << endl << "Successfuly bought." << endl;
					cout << "Press any key to continue." << endl;
					system("Pause");
					break;
					
				case 4:
					cout << "Total Sales at the moment is $" << sale_total << endl;
					cout << "Press any to proceed." << endl;
					system("pause");
					break;
					
				case 5:
					cout << "At the moment, " << seat_sold << " seats have been sold." << endl;
					cout << "Press any key to proceed." << endl;
					system("Pause");
					break;
					
				case 6:
					trow = get_the_row();
					seat_tavailable = 0;
					for (int j = 0; j < seat; j++)
					
					{
						if (availability[trow][j] == '#')
							
							seat_tavailable++;
					}
					
					cout << "In row " << trow +1 << ", there are " << seat_tavailable << " seat still available." << endl;
					cout << "Press any key to proceed." << endl;
					system("Pause");
					break;
					
				case 7:
					
					total_tavailable = 0;
					
					for (int i = 0; i < row; i++)
					
					{
						for (int j =0; j < seat; j++)
						
						{
							if (availability[i][j] == '#')
								total_tavailable++;
						}
					}
					
					cout << "There are " << total_tavailable << " seats still available." << endl;
					cout << "Press any key to proceed." << endl;
					system("Pause");
					break;
					
				default:
					
					cout << "Please choose a option that is valid." << endl;
					cout << "Press any key to proceed." << endl;
					system("Pause");
					break;
			}
			
		} while (again != -1);
		
		system("pause");
		
		return 0;
} 

int display_the_menu() // display the menu function

{
	int choose;
	
	do 
	{
		cout << "MOVIE THEATER MENU" << endl;
	
		cout << "------------------" << endl;
	
		cout << "1) Show seating chart " << endl;
	
		cout << "2) Show ticket price " << endl;
	
		cout << "3) Purchase tickets " << endl;
	
		cout << "4) Show how many seats sold " << endl;
	
		cout << "5) Show how many seats have been sold." << endl;
	
		cout << "6) Show how many seats are available in each row." << endl;
	
		cout << "7) Show how many seats are available in the entire auditorium." << endl;
	
		cout << "8) Quit the program" << endl;
	
		cout << endl << "Please Enter Your Choice: " << endl;
	
		cin  >> choose;
	
		cout << endl;
		
    }while(choose < 1 || choose > 8);

	return choose;
	
}

void enter_the_price(double array[][seat], int row, int seat)

{
	for (int i = 0; i < row; i++)
	
	{
		double tprice;
		
		cout << "Please enter ticket price for row " << i + 1 << " : " << endl;
		
		cin >> tprice;
		
		for (int j = 0; j < seat; j++)
		
		{
			array[i][j] = tprice;
		}
	}
}

void show_the_price(double array[][seat], int row)

{
	cout << array[row][0];
}

void OG_availability(char array[][seat], int row, int seat)

{
	for (int i = 0; i < row; i++)
	
	{
		for (int j = 0; j < seat; j++)
			array[i][j] = '#';
	}
}

void show_the_availability(char array[][seat], int row, int seat)

{
	cout << "-----------------------------------------------------" << endl;
	
	cout << "(Seat availability, * means sold, # means available.)" << endl;
	
	cout << "-----------------------------------------------------" << endl;
	
	cout << "Row  \t123456789012345678901234567890" << endl;
	
	for (int i = 0; i < row; i++)
	
	{
		cout << "row " << i + 1 << "\t";
		
		for (int j = 0; j < seat; j++)
			cout << array[i][j];
		cout << endl;
	}

}

int get_the_row()

{
	cout << "Which row? Enter a number: " << endl;
	
	int trow;
	
	cin >> trow;
	
	while (trow < 1 || trow > 15)
	
	{
		cout << "Please enter a number 1 - 15." << endl;
		
		cin >> trow;
	}
	
	trow--;
	return trow;
}

int get_the_seat()

{
	cout << " Which seat? Enter a number: " << endl;
	
	int tseat;
	
	cin >> tseat;
	
	while (tseat < 1 || tseat > 30)
	
	{
		cout << "Please enter a number 1 - 30." << endl;
		
		cin >> tseat;
	}
	
	tseat--;
	
	return tseat;
}

bool is_sold(int row, int seat)

{
	bool is_sold = 0;
	
	if (availability[row][seat] == '*')
		
		is_sold = 1;
	return is_sold;
}
