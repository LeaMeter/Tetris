#pragma once
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <vector>

using namespace std;

class Shape {

protected:
	int currentX;
	int currentY;
	int currentRotation;
public:
	Shape() {
	}
	virtual ~Shape() {}
	virtual int getCoordX() = 0;
	virtual int getCoordY() = 0;
	virtual void setCoordY(int) = 0;
	virtual void setCoordX(int) = 0;
	virtual int getRotation() = 0;
	virtual void setRotation(bool defaultShapeState = false) = 0;
	virtual int* getArray(int) = 0;
	virtual void Draw() = 0;
};

class LShape : public Shape
{
protected:
	int array[4][16] = { {0,1,0,0,
						  0,1,0,0,
						  0,1,1,0,
						  0,0,0,0 },

						{ 0,0,0,0,
						  0,0,1,0,
						  1,1,1,0,
						  0,0,0,0},

						{ 0,1,1,0,
						  0,0,1,0,
						  0,0,1,0,
						  0,0,0,0},

						{ 0,0,0,0,
						  1,1,1,0,
						  1,0,0,0,
						  0,0,0,0} };
public:
	LShape() {}
	~LShape() {}

	int getCoordX();
	int getCoordY();
	void setCoordY(int num);
	void setCoordX(int num);
	int getRotation();
	void setRotation(bool defaultShapeState = false);
	int* getArray(int rotation);
	void Draw();
};

class IShape : public Shape
{
protected:
	int array[4][16] = { {0,1,0,0,
						  0,1,0,0,
						  0,1,0,0,
						  0,1,0,0 },

						{ 0,0,0,0,
						  0,0,0,0,
						  1,1,1,1,
						  0,0,0,0},

						{ 0,0,1,0,
						  0,0,1,0,
						  0,0,1,0,
						  0,0,1,0},

						{ 0,0,0,0,
						  1,1,1,1,
						  0,0,0,0,
						  0,0,0,0} };
public:
	IShape() {}
	~IShape() {}
	int getCoordX();
	int getCoordY();
	void setCoordY(int num);
	void setCoordX(int num);
	int getRotation();
	void setRotation(bool defaultShapeState = false);
	int* getArray(int rotation);
	void Draw();
};

class ZShape : public Shape
{
protected:
	int array[4][16] = { {0,0,1,0,
						  0,1,1,0,
						  0,1,0,0,
						  0,0,0,0 },

						{ 0,0,0,0,
						  1,1,0,0,
						  0,1,1,0,
						  0,0,0,0},

						{ 0,0,0,1,
						  0,0,1,1,
						  0,0,1,0,
						  0,0,0,0},

						{ 0,1,1,0,
						  0,0,1,1,
						  0,0,0,0,
						  0,0,0,0} };
public:
	ZShape() {}
	~ZShape() {}
	int getCoordX();
	int getCoordY();
	void setCoordY(int num);
	void setCoordX(int num);
	int getRotation();
	void setRotation(bool defaultShapeState = false);
	int* getArray(int rotation);
	void Draw();
};

class SShape : public Shape
{
protected:
	int array[4][16] = { {0,1,0,0,
						  0,1,1,0,
						  0,0,1,0,
						  0,0,0,0 },

						{ 0,0,0,0,
						  0,1,1,0,
						  1,1,0,0,
						  0,0,0,0},

						{ 0,0,1,0,
						  0,0,1,1,
						  0,0,0,1,
						  0,0,0,0},

						{ 0,0,1,1,
						  0,1,1,0,
						  0,0,0,0,
						  0,0,0,0} };
public:
	SShape() {}
	~SShape() {}
	int getCoordX();
	int getCoordY();
	void setCoordY(int num);
	void setCoordX(int num);
	int getRotation();
	void setRotation(bool defaultShapeState = false);
	int* getArray(int rotation);
	void Draw();
};

class OShape : public Shape
{
protected:
	int array[4][16] = { {0,1,1,0,
						  0,1,1,0,
						  0,0,0,0,
						  0,0,0,0 },

						{ 0,1,1,0,
						  0,1,1,0,
						  0,0,0,0,
						  0,0,0,0},

						{ 0,1,1,0,
						  0,1,1,0,
						  0,0,0,0,
						  0,0,0,0},

						{ 0,1,1,0,
						  0,1,1,0,
						  0,0,0,0,
						  0,0,0,0} };
public:
	OShape() {}
	~OShape() {}
	int getCoordX();
	int getCoordY();
	void setCoordY(int num);
	void setCoordX(int num);
	int getRotation();
	void setRotation(bool defaultShapeState = false);
	int* getArray(int rotation);
	void Draw();
};

class TShape : public Shape
{
protected:
	int array[4][16] = { {0,0,1,0,
						  0,1,1,0,
						  0,0,1,0,
						  0,0,0,0 },

						{ 0,0,0,0,
						  1,1,1,0,
						  0,1,0,0,
						  0,0,0,0},

						{ 0,0,0,0,
						  0,1,0,0,
						  0,1,1,0,
						  0,1,0,0},

						{ 0,0,0,0,
						  0,0,1,0,
						  0,1,1,1,
						  0,0,0,0} };
public:
	TShape() {}
	~TShape() {}
	int getCoordX();
	int getCoordY();
	void setCoordY(int num);
	void setCoordX(int num);
	int getRotation();
	void setRotation(bool defaultShapeState = false);
	int* getArray(int rotation);
	void Draw();
};

class JShape : public Shape
{
protected:
	int array[4][16] = { {0,0,1,0,
						  0,0,1,0,
						  0,1,1,0,
						  0,0,0,0 },

						{ 0,0,0,0,
						  1,1,1,0,
						  0,0,1,0,
						  0,0,0,0},

						{ 0,0,0,0,
						  0,1,1,0,
						  0,1,0,0,
						  0,1,0,0},

						{ 0,0,0,0,
						  0,1,0,0,
						  0,1,1,1,
						  0,0,0,0} };
public:
	JShape() {}
	~JShape() {}
	int getCoordX();
	int getCoordY();
	void setCoordY(int num);
	void setCoordX(int num);
	int getRotation();
	void setRotation(bool defaultShapeState = false);
	int* getArray(int rotation);
	void Draw();
};
#endif //SHAPE_H
