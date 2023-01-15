#include "Game.h"


int main()
{
	PlayingField pf(14, 18);
	pf.setUpRandomShape();

	while (pf.gameOver)
	{
		pf.Input();
		pf.FieldLogic();
		pf.Draw();
		pf.TranslateFilledBlocks();
	}
	cout << "GAME OVER :(" << endl;
}
