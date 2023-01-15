#include "Game.h"

void PlayingField::Draw()
{
	this_thread::sleep_for(50ms);
	system("cls");
	Shape* currentShape = getCurrentShape();
	cout << "NEXT SHAPE:" << endl;
	preview->Draw();
	DrawPiece(currentShape);

	bool flag = false;
	int tempCoordY = currentShape->getCoordY();
	int currentRotation = currentShape->getRotation();
	int index = 0;
	cout << endl<<endl;

	for (int x = 0; x < height; x++)
	{
		for (int y = 0; y < width; y++)
		{
			if (arrayOnesIndex[index] == (x * width + y))
			{
				cout << letterShape[this->currentShape];
				index++;
			}
			else
			{
				if (fieldLogic[x * width + y] == 1)
				{
					cout << "0";
				}
				if (fieldLogic[x * width + y] == 8)
				{
					cout << "*";
				}

				if ((y == 0 || y == this->width - 1 || x == this->height - 1))
				{
					cout << "#";
				}
				else if (fieldLogic[x * width + y] == 0)
				{
					cout << " ";
				}

			}
		}

		flag = false;
		cout << endl;
	}

	index = 0;
	cout << endl << "  SCORE: " << score << endl;

}


void PlayingField::FieldLogic()
{
	bool flag = false;
	Shape* currentShape = getCurrentShape();

	if (dir == LEFT)
	{
		if (CollisionTest(-1, 0, currentShape->getRotation()) == true)
		{
			currentShape->setCoordX(-1);
		}
		dir = DEFAULT;
	}
	if (dir == RIGHT)
	{
		if (CollisionTest(1, 0, currentShape->getRotation()) == true)
		{
			currentShape->setCoordX(1);
		}
		dir = DEFAULT;
	}
	if (dir == ROTATE)
	{
		if (CollisionTest(0, 0, (currentShape->getRotation() + 1)) == true)
		{
			currentShape->setRotation();
		}
		dir = DEFAULT;
	}
	if (dir == DOWN)
	{
		if (CollisionTest(0, 1, currentShape->getRotation()) == true)
		{
			currentShape->setCoordY(1);
		}
		dir = DEFAULT;
	}
	speedCount++;
	if (speed == speedCount)
	{
		speedCount = 0;
		if (CollisionTest(0, 1, currentShape->getRotation()) == true)
		{
			currentShape->setCoordY(1);
		}
		if (CollisionTest(0, 1, currentShape->getRotation()) == false)
		{
			PlacePiece(currentShape);
			numShapes++;
			score += 25;

			if ((numShapes % 50) == 0)
			{
				if (speed >= 10)
				{
					speed--;
				}
			}
			CheckIfLineCompleted();
			setUpRandomShape();

			if (CollisionTest(0, 1, currentShape->getRotation()) == false)
			{
				PlacePiece(currentShape);
				gameOver = false;
			}
		}
		
	}
	

}

void PlayingField::PlacePiece(Shape* currentShape)
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (currentShape->getArray(currentShape->getRotation())[x * 4 + y] != 0)
			{
				fieldLogic[(currentShape->getCoordY() + x) * width + (currentShape->getCoordX() + y)] = 1;
			}
		}
	}
}

void PlayingField::DrawPiece(Shape* currentShape)
{
	int counter = 0;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (currentShape->getArray(currentShape->getRotation())[x * 4 + y] != 0)
			{
				arrayOnesIndex[counter] = (currentShape->getCoordY() + x) * width + (currentShape->getCoordX() + y);
				counter++;
			}
		}
	}
	counter = 0;
}

void PlayingField::CheckIfLineCompleted()
{
	canClear = false;
	int counter = 0;

	for (int x = 0; x < height - 1; x++)
	{
		for (int y = 0; y < width; y++)
		{
			if (fieldLogic[x * width + y] == 0)
			{
				counter = 0;
				break;
			}
			if (fieldLogic[x * width + y] != 0)
			{
				counter++;
			}

			if (counter == width)
			{
				rowIndex = x;
				numberOfLinesToClear += 1;
				counter = 0;
			}
		}
	}
	if (numberOfLinesToClear > 0)
	{
		canClear = true;
	}
	score += numberOfLinesToClear * 400;
	DoClearCompletedLines();
}

void PlayingField::DoClearCompletedLines()
{

	int tempNumberOfLinesToClear = numberOfLinesToClear;
	int tempRowIndex = rowIndex;
	if (canClear == true)
	{
		while (numberOfLinesToClear > 0)
		{
			for (int j = 1; j < width - 1; j++)
			{
				fieldLogic[rowIndex * width + j] = 8;
			}
			numberOfLinesToClear--;
			rowIndex--;
		}
	}
	numberOfLinesToClear = tempNumberOfLinesToClear;
	rowIndex = tempRowIndex;
}

void PlayingField::TranslateFilledBlocks()
{
	if (numberOfLinesToClear > 0)
	{
		this_thread::sleep_for(500ms);
	}

	while (numberOfLinesToClear > 0)
	{
		for (int x = 1; x < width - 1; x++)
		{
			for (int y = rowIndex; y > 0; y--)
			{
				fieldLogic[y * width + x] = fieldLogic[(y - 1)* width + x];
			}

			fieldLogic[x] = 0;
		}
		numberOfLinesToClear--;
	}
	rowIndex = 0;
}


Shape* Game::getCurrentShape()
{
	return shape;
}

void Game::setUpRandomShape()
{
	srand(time(NULL));
	this->currentShape = previewShape;
	previewShape = rand() % 7;
	shape = shapesVector[currentShape];
	preview = shapesVector[previewShape];
	int positionX = (width / 2) - 1;
	shape->setCoordX(positionX);
	shape->setCoordY(0);
	shape->setRotation(true);
}

bool PlayingField::CollisionTest(int xOffset, int yOffset, int rotation)
{

	Shape* currentShape = getCurrentShape();
	int newCoordX = currentShape->getCoordX() + xOffset;
	int newCoordY = currentShape->getCoordY() + yOffset;
	int* array = currentShape->getArray(rotation);

	for (int fieldX = 0; fieldX < 4; fieldX++)
	{
		for (int fieldY = 0; fieldY < 4; fieldY++)
		{
			int indexInField = (newCoordY + fieldY) * width + (newCoordX + fieldX);

			if (((newCoordX + fieldX) >= 0) && (((newCoordX + fieldX)) < width))
			{
				if (((newCoordY + fieldY) >= 0) && ((newCoordY + fieldY) < height))
				{
					if ((array[fieldY * 4 + fieldX] != 0) && (fieldLogic[indexInField] != 0))
						return false;
				}
			}

		}
	}
	return true;
}

void Game::Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case KEY_LEFT:
			dir = LEFT;
			break;
		case KEY_RIGHT:
			dir = RIGHT;
			break;

		case KEY_UP:
			dir = ROTATE;
			break;

		case KEY_DOWN:
			dir = DOWN;
			break;
		}
	}
}


void PlayingField::createFieldLogic()
{
	for (int x = 0; x < this->width; x++)
	{
		for (int y = 0; y < this->height; y++)
		{
			fieldLogic[y * this->width + x] = (x == 0 || x == this->width - 1 || y == this->height - 1) ? 9 : 0;
		}
	}
}