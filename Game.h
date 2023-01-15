#pragma once
#ifndef GAME_H
#define GAME_H

#include "Shape.h"

#include <iostream>
#include <vector>
#include <map> 

#include <windows.h>
#include <conio.h>
#include <time.h>
#include <thread>

#define KEY_RIGHT 77
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_UP 72

using namespace std;

class Game
{
protected:
	enum eDirecton { DEFAULT, LEFT, RIGHT, DOWN, ROTATE };
	eDirecton dir;

	vector<Shape*> shapesVector = { new LShape(),new IShape(),new ZShape(),new SShape(),new OShape(),new TShape(),new JShape() };
	
	Shape* shape;
	Shape* preview;
	int width;
	int height;
	int previewShape;
	int currentShape;
	map<int, char> letterShape;

public:
	Game()
	{
		previewShape = rand() % 7;
		currentShape = rand() % 7;
		preview = shapesVector[previewShape];
		shape = shapesVector[currentShape];
		letterShape.insert(pair<int, char>(0, 'L'));
		letterShape.insert(pair<int, char>(1, 'I'));
		letterShape.insert(pair<int, char>(2, 'Z'));
		letterShape.insert(pair<int, char>(3, 'S'));
		letterShape.insert(pair<int, char>(4, 'O'));
		letterShape.insert(pair<int, char>(5, 'T'));
		letterShape.insert(pair<int, char>(6, 'J'));
	}
	~Game()
	{
		shapesVector.clear();
	}
	void Input();
	void setUpRandomShape();
	Shape* getCurrentShape();
};

class PlayingField : public Game
{
private:
	int* fieldLogic;
	int speed = 17;
	int speedCount;
	int score;
	int numShapes;
	int arrayOnesIndex[4];
	bool canClear;
	int rowIndex;
	int numberOfLinesToClear;

public:
	bool gameOver = true;

	PlayingField(int width, int height) {

		this->width = width;
		this->height = height;
		fieldLogic = new int[this->width * this->height];
		createFieldLogic();
	}
	~PlayingField()
	{
		delete[]fieldLogic;
		fieldLogic = 0;
	};

	void createFieldLogic();
	void FieldLogic();
	void PlacePiece(Shape* currentShape);
	void DrawPiece(Shape* currentShape);
	void Draw();
	void CheckIfLineCompleted();
	void DoClearCompletedLines();
	bool CollisionTest(int xOffset, int yOffset, int rotation);
	void TranslateFilledBlocks();
};

#endif //GAME_H