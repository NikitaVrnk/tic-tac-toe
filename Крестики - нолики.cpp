
#include <iostream>
using namespace std;

//массив для игровокго поля
char board[9] = { '-', '-', '-' , '-' , '-' , '-' , '-' , '-' , '-' };

void print_board()
{
	//поле для игры
// массив board, для отображения введенного пользователем числа
	cout << "~Игровое поле~" << endl;
	cout << "|-" << board[6] << "-|-" << board[7] << "-|-" << board[8] << "-|" << endl;
	cout << "|-" << board[3] << "-|-" << board[4] << "-|-" << board[5] << "-|" << endl;
	cout << "|-" << board[0] << "-|-" << board[1] << "-|-" << board[2] << "-|" << endl;
	cout << endl;
}

int get_move()
{
	//заготовка поля(пример)
	cout << " ===========" << endl;
	cout << "|Пример поля|" << endl;
	cout << "|-7-|-8-|-9-|" << endl;
	cout << "|-4-|-5-|-6-|" << endl;
	cout << "|-1-|-2-|-3-|" << endl;
	cout << " ===========" << endl;
	cout << endl;

	void print_board();
	cout << endl << "Ваш ход" << endl;

	int move = 0;
	cin >> move;

	//проверка на правильность ввода координат и проверка заполнена ли эта ячейка
	//пока move не подходит запраштваем число
	while (move > 9 || move < 1 || board[move - 1] != '-')
	{
		cout << "Введите правильный ход (1 - 9): " << endl;
		cin >> move;
	}

	return move;
}

/*
//проверка на выигрышную ситуацию
bool end_game()
{
	вынести проверку в отдельную функцию
}
*/

int game(int i)
{
	int x = 0;
	int o = 0;
	bool win = false;

	for (&i; i != 0; i--)
	{
		int move = get_move();
		cout << "Вы ввели " << move;

		if (i % 2 == 0) {
			//меняем значение в ячейке массива на O
			board[move - 1] = 'O';
		}
		else {
			//меняем значение в ячейке массива на Х
			board[move - 1] = 'X';
		}

		system("cls");
		print_board();
		
		if (
			//проверка по горизонтали
			(board[6] == 'X' && board[7] == 'X' && board[8] == 'X') ||
			(board[3] == 'X' && board[4] == 'X' && board[5] == 'X') ||
			(board[0] == 'X' && board[1] == 'X' && board[2] == 'X') ||
			//проверка по вертикали
			(board[0] == 'X' && board[3] == 'X' && board[6] == 'X') ||
			(board[1] == 'X' && board[4] == 'X' && board[7] == 'X') ||
			(board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
			//проверка по диогонали
			(board[0] == 'X' && board[4] == 'X' && board[8] == 'X') ||
			(board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
			)

		{
			cout << "Выиграл Х" << endl;
			x = 1;
			win = true;
			break;
		}

		else if (
			//проверка по горизонтали
			(board[6] == 'O' && board[7] == 'O' && board[8] == 'O') ||
			(board[3] == 'O' && board[4] == 'O' && board[5] == 'O') ||
			(board[0] == 'O' && board[1] == 'O' && board[2] == 'O') ||
			//проверка по вертикали
			(board[0] == 'O' && board[3] == 'O' && board[6] == 'O') ||
			(board[1] == 'O' && board[4] == 'O' && board[7] == 'O') ||
			(board[2] == 'O' && board[5] == 'O' && board[8] == 'O') ||
			//проверка по диогонали
			(board[0] == 'O' && board[4] == 'O' && board[8] == 'O') ||
			(board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
			)

			{
			cout << "Выиграл O" << endl;
			o = 1;
			win = true;
			break;
			}
	}

	if (x == 0 && o == 0)
	cout << "Ничья" << endl;

		return 0;
}



int main()
{
	setlocale(LC_ALL, "Rus");
	
	game(9);

	/*
	реализовать функцию продолжения игры
	сделать очистку массива
	реализовать счет и счетчик количества сыгранных игр
	сделать возможность выбора режима игры
	добавить бота через функцию ранд
	*/

	return 0;
}

