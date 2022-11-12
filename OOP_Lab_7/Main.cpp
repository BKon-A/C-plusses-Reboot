#include <iostream>

using namespace std;

class ChessFigure
{

public:
	virtual int shah(char enemyKingPlaseH, int enemyKingPlaseV, char attakerPositionH, int attakerPositionV) = 0;

};
class Knight : public ChessFigure // кінь
{

public:
	int shah(char enemyKingPlaseH, int enemyKingPlaseV, char attakerPositionH, int attakerPositionV)
	{
		if ((attakerPositionH == ('d' || 'g')) || (attakerPositionV != (1 || 3 || 4)))
		{
			cout << "-> Knight: Shah is imposible\n";
			return 0;
		}
		if (attakerPositionH == 'e' || 'f' || 'h')
		{
			if ((attakerPositionH == 'e' && attakerPositionV == 4) || (attakerPositionH == 'f' && attakerPositionV == (1 || 3))
				|| (attakerPositionH == 'h' && attakerPositionV == (1 || 3)))
			{
				cout << "-> Knight: Shah is imposible!\n";
				return 0;
			}
		}
		else
		{
			cout << "-> Knight: Shah!\n";
			return 1;
		}
	}
};
class Bishop : public ChessFigure // слон
{

public:
	int shah(char enemyKingPlaseH, int enemyKingPlaseV, char attakerPositionH, int attakerPositionV)
	{
		string enemyPlase, friendPlase;

		enemyPlase = enemyKingPlaseH + enemyKingPlaseV;
		friendPlase = attakerPositionH + attakerPositionV;

		if ((friendPlase != (enemyPlase) || "g1"))
		{
			if ((friendPlase == "h1" || "h3" || "f1" || "f3" || "e4" || "d5" || "c6" || "b7" || "a8"))
			{
				cout << "-> Bishop: Shah!\n";
				return 1;
			}
			else
			{
				cout << "-> Bishop: Shah is imposible!\n";
				return 0;
			}
		}
	}
};
class Rook : public ChessFigure // тура
{

public:
	int shah(char enemyKingPlaseH, int enemyKingPlaseV, char attakerPositionH, int attakerPositionV)
	{
		string enemyPlase, friendPlase;

		enemyPlase = enemyKingPlaseH + enemyKingPlaseV;
		friendPlase = attakerPositionH + attakerPositionV;

		if (friendPlase != enemyPlase)
		{
			if ((attakerPositionH != 'g' && attakerPositionV == 2))
			{
				cout << "-> Rook: Shah!\n";
				return 1;
			}
			else if ((attakerPositionH == 'g' && attakerPositionV != 2))
			{
				cout << "-> Rook: Shah!\n";
				return 1;
			}
			else
			{
				cout << "-> Rook: Shah is imposible!\n";
				return 0;
			}
		}
	}
};
class Queen : public ChessFigure // ферзь
{

public:
	int shah(char enemyKingPlaseH, int enemyKingPlaseV, char attakerPositionH, int attakerPositionV)
	{
		if (attakerPositionV == 1)
		{
			cout << "-> Queen: Shah!\n";
			return 1;
		}
		else
		{
			cout << "-> Queen: Shah is imposible!\n";
			return 0;
		}
	}
};

int main()
{

	ChessFigure* winTactic[4];
	Knight knight; Bishop bishop; Rook rook; Queen queen;

	/*knight.shah('g', 2, 'f', 1);
	bishop.shah('g', 2, 'f', 1);
	rook.shah('g', 2, 'f', 1);

	if (bishop.shah('g', 2, 'f', 1) 
		|| rook.shah('g', 2, 'f', 1))
	{
		queen.shah('g', 2, 'f', 1);
	}
	else
	{
		queen.shah('g', 2, 'f', 0);
	}*/
	cout << "--------------------------\n--------------------------\n\n";

	winTactic[0] = &knight;
	winTactic[1] = &bishop;
	winTactic[2] = &rook;
	winTactic[3] = &queen;

	for (int i = 0; i < 4; i++)
	{
		winTactic[i]->shah('g', 2, 'f', 1);

		if (i == 4)
		{
			if (bishop.shah('g', 2, 'f', 1)
				|| rook.shah('g', 2, 'f', 1))
			{
				queen.shah('g', 2, 'f', 1);
			}
			else
			{
				queen.shah('g', 2, 'f', 0);
			}
		}
	}

	cout << "\n--------------------------\n--------------------------\n";

	return 0;
}
