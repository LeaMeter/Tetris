#include "Shape.h"

int LShape::getCoordX() {
	return currentX;
}
int LShape::getCoordY() {
	return currentY;
}
void LShape::setCoordY(int num) {
	currentY = (num == 1) ? (currentY + 1) : 0;
}
void LShape::setCoordX(int num) {
	currentX = ((num == 1) || (num == -1)) ? (currentX + num) : num;
}
int LShape::getRotation() {
	return currentRotation;
}
void LShape::setRotation(bool defaultShapeState) {
	if (defaultShapeState == true)
	{
		currentRotation = 0;
	}
	else
	{
		if (currentRotation == 3)
		{
			currentRotation = 0;
		}
		else
		{
			currentRotation++;
		}
	}
}
int* LShape::getArray(int rotation)
{
	return array[rotation];
}




int IShape::getCoordX() {
	return currentX;
}
int IShape::getCoordY() {
	return currentY;
}
void IShape::setCoordY(int num) {
	currentY = (num == 1) ? (currentY + 1) : 0;
}
void IShape::setCoordX(int num) {
	currentX = ((num == 1) || (num == -1)) ? (currentX + num) : num;
}
int IShape::getRotation() {
	return currentRotation;
}
void IShape::setRotation(bool defaultShapeState) {
	if (defaultShapeState == true)
	{
		currentRotation = 0;
	}
	else
	{
		if (currentRotation == 3)
		{
			currentRotation = 0;
		}
		else
		{
			currentRotation++;
		}
	}
}
int* IShape::getArray(int rotation)
{
	return array[rotation];
}



int ZShape::getCoordX() {
	return currentX;
}
int ZShape::getCoordY() {
	return currentY;
}
void ZShape::setCoordY(int num) {
	currentY = (num == 1) ? (currentY + 1) : 0;
}
void ZShape::setCoordX(int num) {
	currentX = ((num == 1) || (num == -1)) ? (currentX + num) : num;
}
int ZShape::getRotation() {
	return currentRotation;
}
void ZShape::setRotation(bool defaultShapeState) {
	if (defaultShapeState == true)
	{
		currentRotation = 0;
	}
	else
	{
		if (currentRotation == 3)
		{
			currentRotation = 0;
		}
		else
		{
			currentRotation++;
		}
	}
}
int* ZShape::getArray(int rotation)
{
	return array[rotation];
}



int SShape::getCoordX() {
	return currentX;
}
int SShape::getCoordY() {
	return currentY;
}
void SShape::setCoordY(int num) {
	currentY = (num == 1) ? (currentY + 1) : 0;
}
void SShape::setCoordX(int num) {
	currentX = ((num == 1) || (num == -1)) ? (currentX + num) : num;
}
int SShape::getRotation() {
	return currentRotation;
}
void SShape::setRotation(bool defaultShapeState) {
	if (defaultShapeState == true)
	{
		currentRotation = 0;
	}
	else
	{
		if (currentRotation == 3)
		{
			currentRotation = 0;
		}
		else
		{
			currentRotation++;
		}
	}
}
int* SShape::getArray(int rotation)
{
	return array[rotation];
}



int OShape::getCoordX() {
	return currentX;
}
int OShape::getCoordY() {
	return currentY;
}
void OShape::setCoordY(int num) {
	currentY = (num == 1) ? (currentY + 1) : 0;
}
void OShape::setCoordX(int num) {
	currentX = ((num == 1) || (num == -1)) ? (currentX + num) : num;
}
int OShape::getRotation() {
	return currentRotation;
}
void OShape::setRotation(bool defaultShapeState) {
	if (defaultShapeState == true)
	{
		currentRotation = 0;
	}
	else
	{
		if (currentRotation == 3)
		{
			currentRotation = 0;
		}
		else
		{
			currentRotation++;
		}
	}
}
int* OShape::getArray(int rotation)
{
	return array[rotation];
}



int TShape::getCoordX() {
	return currentX;
}
int TShape::getCoordY() {
	return currentY;
}
void TShape::setCoordY(int num) {
	currentY = (num == 1) ? (currentY + 1) : 0;
}
void TShape::setCoordX(int num) {
	currentX = ((num == 1) || (num == -1)) ? (currentX + num) : num;
}
int TShape::getRotation() {
	return currentRotation;
}
void TShape::setRotation(bool defaultShapeState) {
	if (defaultShapeState == true)
	{
		currentRotation = 0;
	}
	else
	{
		if (currentRotation == 3)
		{
			currentRotation = 0;
		}
		else
		{
			currentRotation++;
		}
	}
}
int* TShape::getArray(int rotation)
{
	return array[rotation];
}



int JShape::getCoordX() {
	return currentX;
}
int JShape::getCoordY() {
	return currentY;
}
void JShape::setCoordY(int num) {
	currentY = (num == 1) ? (currentY + 1) : 0;
}
void JShape::setCoordX(int num) {
	currentX = ((num == 1) || (num == -1)) ? (currentX + num) : num;
}
int JShape::getRotation() {
	return currentRotation;
}
void JShape::setRotation(bool defaultShapeState) {
	if (defaultShapeState == true)
	{
		currentRotation = 0;
	}
	else
	{
		if (currentRotation == 3)
		{
			currentRotation = 0;
		}
		else
		{
			currentRotation++;
		}
	}
}
int* JShape::getArray(int rotation)
{
	return array[rotation];
}

void LShape::Draw()
{
	int newLineCounter = 0;
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";

	}
	cout << endl;
	for (int i = 0; i < 16; i++)
	{
		if (newLineCounter == 0)
		{
			cout << "    *";
		}
		if (array[0][i] == 1)
		{
			cout << "$";
		}
		else {
			cout << " ";
		}
		newLineCounter++;
		if (newLineCounter == 4) {
			cout << "*" << endl;
			newLineCounter = 0;
		}
	}
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";
	}
}

void IShape::Draw()
{
	int newLineCounter = 0;
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";

	}
	cout << endl;
	for (int i = 0; i < 16; i++)
	{
		if (newLineCounter == 0)
		{
			cout << "    *";
		}
		if (array[0][i] == 1)
		{
			cout << "$";
		}
		else {
			cout << " ";
		}
		newLineCounter++;
		if (newLineCounter == 4) {
			cout << "*" << endl;
			newLineCounter = 0;
		}
	}
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";
	}
}

void ZShape::Draw()
{
	int newLineCounter = 0;
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";

	}
	cout << endl;
	for (int i = 0; i < 16; i++)
	{
		if (newLineCounter == 0)
		{
			cout << "    *";
		}
		if (array[0][i] == 1)
		{
			cout << "$";
		}
		else {
			cout << " ";
		}
		newLineCounter++;
		if (newLineCounter == 4) {
			cout << "*" << endl;
			newLineCounter = 0;
		}
	}
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";
	}
}

void SShape::Draw()
{
	int newLineCounter = 0;
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";

	}
	cout << endl;
	for (int i = 0; i < 16; i++)
	{
		if (newLineCounter == 0)
		{
			cout << "    *";
		}
		if (array[0][i] == 1)
		{
			cout << "$";
		}
		else {
			cout << " ";
		}
		newLineCounter++;
		if (newLineCounter == 4) {
			cout << "*" << endl;
			newLineCounter = 0;
		}
	}
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";
	}
}

void OShape::Draw()
{
	int newLineCounter = 0;
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";

	}
	cout << endl;
	for (int i = 0; i < 16; i++)
	{
		if (newLineCounter == 0)
		{
			cout << "    *";
		}
		if (array[0][i] == 1)
		{
			cout << "$";
		}
		else {
			cout << " ";
		}
		newLineCounter++;
		if (newLineCounter == 4) {
			cout << "*" << endl;
			newLineCounter = 0;
		}
	}
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";
	}
}

void TShape::Draw()
{
	int newLineCounter = 0;
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";

	}
	cout << endl;
	for (int i = 0; i < 16; i++)
	{
		if (newLineCounter == 0)
		{
			cout << "    *";
		}
		if (array[0][i] == 1)
		{
			cout << "$";
		}
		else {
			cout << " ";
		}
		newLineCounter++;
		if (newLineCounter == 4) {
			cout << "*" << endl;
			newLineCounter = 0;
		}
	}
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";
	}
}

void JShape::Draw()
{
	int newLineCounter = 0;
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";

	}
	cout << endl;
	for (int i = 0; i < 16; i++)
	{
		if (newLineCounter == 0)
		{
			cout << "    *";
		}
		if (array[0][i] == 1)
		{
			cout << "$";
		}
		else {
			cout << " ";
		}
		newLineCounter++;
		if (newLineCounter == 4) 
		{
			cout << "*" << endl;
			newLineCounter = 0;
		}
	}
	cout << "    ";
	for (int i = 0; i < 6; i++)
	{
		cout << "*";
	}
}