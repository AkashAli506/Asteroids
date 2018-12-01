/*
 * Board.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Sibt ul Hussain
 */

#include "Board.h"
#include <cstdio>

// Asteroids board

// Note that all these enum constants from NILL onwards
// have been given numbers in increasing order
// e.g. NILL=0, and so on
// and these numbers are represented in the board array...
enum BoardParts {
	NILL, S_BRICK, G_BRICK, R_BRICK
};
// defining some utility functions...

/* board_array[Board::BOARD_Y][Board::BOARD_X] = { { 0 } };*/

// Destructor
Board::~Board(void) {
}
void Board::InitalizeBoard(int w, int h) {
//	cout << "Initialize board" << endl;
//	width = w;
//	height = h;
//	for (int i = 0; i < BOARD_Y - 1; ++i) {
//		for (int j = 0; j < BOARD_X; ++j) {
//			// can use G_BRICK, R_BRICK, or S_BRICK here
//			board_array[i][j] = NILL;
//		}
//
//	}
	pointer[0]=new PlayerShip();
	pointer[1]=new BigSaucer();
	pointer[2]=new MiniSaucer();
	p=dynamic_cast<PlayerShip*>(pointer[0]);
	bs=dynamic_cast<BigSaucer*>(pointer[1]);
	ms=dynamic_cast<MiniSaucer*>(pointer[2]);
	for (int i=3;i<size;i++)
	{
		pointer[i]=new BigAsteroid();
	}







}
//Constructor
Board::Board(int xsize, int ysize)
{
	size=5;
	s=3;
	pointer= new GameObject*[size];
	score=0;
	level=1;
	x=new int[200];
	y=new int[200];
	for (int i=0;i<200;i++)
	{
		x[i]=GetRandInRange(5, 1000);
		y[i]=GetRandInRange(5, 800);
	}
	check=0;
	gamePause=false;


}

void Board::nextStateCheck(char c)
{


	if (p->getLives()>0)
	{
		for (int i=0;i<size;i++)
		{
			pointer[i]->nextStateCheck(c);
		}
	}
	else
	{
		DrawString(450, 430, "GAME OVER", colors[5]);
	}

	if (size==1)
	{
		level++;
		p->setLives(3);
		AddBsaucer();
		AddMsaucer();
		for (int i=0;i<(level*2);i++)
		{
			AddBasteroid();
			AddBasteroid();
		}

	}
	if (score>40000)
	{
		p->setLives(p->getLives()+1);
		score=0;
	}

}
void Board::checkCollision()
{
	for (int i=1;(i<size && p->Alive()&& p->isImmunity()==false && pointer[i]->Alive());i++)
	{
		Point distance;
		distance.assign((pointer[0]->getCenter().getX()+p->getRadius())-(pointer[i]->getCenter().getX()+pointer[i]->getRadius()),
						(pointer[0]->getCenter().getY()+p->getRadius())-(pointer[i]->getCenter().getY()+pointer[i]->getRadius()));

		int totalDistance=sqrt((distance.getX()*distance.getX())+(distance.getY()*distance.getY()));

		if (totalDistance<(p->getRadius()+pointer[i]->getRadius()))
		{
			if (pointer[i]->getRadius()==50)
			{
				score+=10;
				addComplexAsteroid(i);
				addComplexAsteroid(i);
			}
			if (pointer[i]->getRadius()==35)
			{
				score+=20;
				addMiniAsteroid(i);
				addMiniAsteroid(i);
				addMiniAsteroid(i);
				addMiniAsteroid(i);
			}
			Remove(i);
			p->setLives(p->getLives()-1);
			p->setImmune(120);
			p->setImmunity(true);
			p->setAlive(false);
			break;
		}
	}


	for (int i=0;i<1;i++)
	{
		for (int j=0;(j<size && bs->Alive() && p->isImmunity()==false && bs->getBullet(i)->isDisplay()==true && p->Alive()==true);j++)
		{
			Point distance;
			distance.assign(bs->getBullet(i)->getCenter().getX()+bs->getBullet(i)->getRadius()
							-(p->getCenter().getX()+p->getRadius()),
							bs->getBullet(i)->getCenter().getY()+bs->getBullet(i)->getRadius()
							-(p->getCenter().getY()+p->getRadius()));

			int totalDistance=sqrt((distance.getX()*distance.getX())+(distance.getY()*distance.getY()));
			if (totalDistance<(bs->getBullet(i)->getRadius()+p->getRadius())+10)
			{
				bs->getBullet(i)->setDisplay(0);
				bs->getBullet(i)->setTime1(90);
				p->setLives(p->getLives()-1);
				p->setImmune(150);
				p->setImmunity(true);
				p->setAlive(false);
				break;
				cout<<" Bullet Collision Detected"<<" "<<j<<endl;
			}
		}

	}

	for (int i=0;i<1;i++)
	{
		for (int j=0;(j<size && ms->Alive()&& p->isImmunity()==false && ms->getBullet(i)->isDisplay()==true && p->Alive()==true);j++)
		{
			Point distance;
			distance.assign(ms->getBullet(i)->getCenter().getX()+ms->getBullet(i)->getRadius()
							-(p->getCenter().getX()+p->getRadius()),
							ms->getBullet(i)->getCenter().getY()+ms->getBullet(i)->getRadius()
							-(p->getCenter().getY()+p->getRadius()));

			int totalDistance=sqrt((distance.getX()*distance.getX())+(distance.getY()*distance.getY()));
			if (totalDistance<(ms->getBullet(i)->getRadius()+p->getRadius())+10)
			{
				ms->getBullet(i)->setDisplay(0);
				ms->getBullet(i)->setTime1(90);
				p->setLives(p->getLives()-1);
				p->setImmune(120);
				p->setImmunity(true);
				p->setAlive(false);
				break;
				cout<<" Bullet Collision Detected"<<" "<<j<<endl;
			}
		}

	}







//	for (int i=3;i<size && bs->Alive();i++)
//	{
//		Point distance;
//		distance.assign((pointer[1]->getCenter().getX()+bs->getRadius())-(pointer[i]->getCenter().getX()+pointer[i]->getRadius()),
//						(pointer[1]->getCenter().getY()+bs->getRadius())-(pointer[i]->getCenter().getY()+pointer[i]->getRadius()));
//
//		int totalDistance=sqrt((distance.getX()*distance.getX())+(distance.getY()*distance.getY()));
//
//		if (totalDistance<(bs->getRadius()+pointer[i]->getRadius()))
//		{
//			if (pointer[i]->getRadius()==50)
//			{
//				score+=10;
//				addComplexAsteroid(i);
//				addComplexAsteroid(i);
//			}
//			if (pointer[i]->getRadius()==35)
//			{
//				score+=20;
//				addMiniAsteroid(i);
//				addMiniAsteroid(i);
//				addMiniAsteroid(i);
//				addMiniAsteroid(i);
//			}
//			Remove(i);
//			bs->setAlive(false);
//			break;
//		}
//	}
//
//	for (int i=3;i<size && ms->Alive();i++)
//		{
//			Point distance;
//			distance.assign((pointer[1]->getCenter().getX()+ms->getRadius())-(pointer[i]->getCenter().getX()+pointer[i]->getRadius()),
//							(pointer[1]->getCenter().getY()+ms->getRadius())-(pointer[i]->getCenter().getY()+pointer[i]->getRadius()));
//
//			int totalDistance=sqrt((distance.getX()*distance.getX())+(distance.getY()*distance.getY()));
//
//			if (totalDistance<(ms->getRadius()+pointer[i]->getRadius()))
//			{
//				if (pointer[i]->getRadius()==50)
//				{
//					score+=10;
//					addComplexAsteroid(i);
//					addComplexAsteroid(i);
//				}
//				if (pointer[i]->getRadius()==35)
//				{
//					score+=20;
//					addMiniAsteroid(i);
//					addMiniAsteroid(i);
//					addMiniAsteroid(i);
//					addMiniAsteroid(i);
//				}
//				Remove(i);
//				ms->setAlive(false);
//				break;
//			}
//		}




	for (int i=0;i<5;i++)
	{
		for (int j=1;(j<size && p->getBullet(i)->isDisplay()==true && pointer[j]->Alive()==true);j++)
		{
			Point distance;
			distance.assign(p->getBullet(i)->getCenter().getX()+p->getBullet(i)->getRadius()
							-(pointer[j]->getCenter().getX()+pointer[j]->getRadius()),
							p->getBullet(i)->getCenter().getY()+p->getBullet(i)->getRadius()
							-(pointer[j]->getCenter().getY()+pointer[j]->getRadius()));

			int totalDistance=sqrt((distance.getX()*distance.getX())+(distance.getY()*distance.getY()));
			if (totalDistance<(p->getBullet(i)->getRadius()+pointer[j]->getRadius())+10)
			{
				if (pointer[j]->getRadius()==50)
				{
					score+=10;
					addComplexAsteroid(j);
					addComplexAsteroid(j);
				}
				if (pointer[j]->getRadius()==35)
				{
					score+=20;
					addMiniAsteroid(j);
					addMiniAsteroid(j);
					addMiniAsteroid(j);
					addMiniAsteroid(j);
				}
				if (pointer[j]->getRadius()==15)
				{
					score+=40;
				}
				if (pointer[j]->getRadius()==30)
				{
					score+=500;
				}
				if (pointer[j]->getRadius()==60)
				{
					score+=100;
				}
				p->getBullet(i)->setDisplay(0);
				p->getBullet(i)->setTime1(90);
				pointer[j]->setAlive(false);
				Remove(j);
				break;
				cout<<" Bullet Collision Detected"<<" "<<j<<endl;
			}
		}

	}


	//cout<<pointer[1]->getCenter().getX()<<" "<<pointer[1]->getCenter().getY()<<endl;

}
void Board::addComplexAsteroid(int l)
{
	GameObject **temp;
	int tsize=size;
	temp=new GameObject*[tsize];
	for (int i=0;i<size;i++)
	{
		temp[i]=pointer[i];
	}
	delete []pointer;
	size=tsize+1;
	pointer=new GameObject*[size];
	for (int i=0;i<size-1;i++)
	{
		pointer[i]=temp[i];
	}
	pointer[size-1]=new ComplexAsteroid(pointer[l]->getCenter().getX(),pointer[l]->getCenter().getY());
}

void Board::addMiniAsteroid(int l)
{
	GameObject **temp;
	int tsize=size;
	temp=new GameObject*[tsize];
	for (int i=0;i<size;i++)
	{
		temp[i]=pointer[i];
	}
	delete []pointer;
	size=tsize+1;
	pointer=new GameObject*[size];
	for (int i=0;i<size-1;i++)
	{
		pointer[i]=temp[i];
	}
	pointer[size-1]=new MiniAsteroid(pointer[l]->getCenter().getX(),pointer[l]->getCenter().getY());
}

void Board::AddBasteroid()
{
	GameObject **temp;
	int tsize=size;
	temp=new GameObject*[tsize];
	for (int i=0;i<tsize;i++)
	{
		temp[i]=pointer[i];
	}
	delete[] pointer;
	size=tsize+1;
	pointer=new GameObject*[size];
	for (int i=0;i<size-1;i++)
	{
		pointer[i]=temp[i];
	}
	pointer[size-1]=new BigAsteroid();
}
void Board::AddBsaucer()
{
	GameObject **temp;
	int tsize=size;
	temp=new GameObject*[tsize];
	for (int i=0;i<tsize;i++)
	{
		temp[i]=pointer[i];
	}
	delete[] pointer;
	size=tsize+1;
	pointer=new GameObject*[size];
	for (int i=0;i<size-1;i++)
	{
		pointer[i]=temp[i];
	}
	pointer[size-1]=new BigSaucer();
}
void Board::AddMsaucer()
{
	GameObject **temp;
	int tsize=size;
	temp=new GameObject*[tsize];
	for (int i=0;i<tsize;i++)
	{
		temp[i]=pointer[i];
	}
	delete[] pointer;
	size=tsize+1;
	pointer=new GameObject*[size];
	for (int i=0;i<size-1;i++)
	{
		pointer[i]=temp[i];
	}
	pointer[size-1]=new MiniSaucer();
}

void Board::Remove(int k)
{
	GameObject **temp;
	int tsize=size-1;
	temp=new GameObject*[tsize];
	for (int i=0;i<k;i++)
	{
		temp[i]=pointer[i];
	}
	for (int j=k,i=k+1;i<size;i++,j++)
	{
		temp[j]=pointer[i];
	}

	delete []pointer;
	size= tsize;
	pointer=new GameObject*[size];
	for (int i=0;i<size;i++)
	{
		pointer[i]=temp[i];
	}

}


void Board::Draw() {

//	glColor3f(0, 0, 1);
//	glPushMatrix();
//
//	for (int i = BOARD_Y - 2, y = 0; i >= 0; --i, y += xcellsize) {
//		for (int j = 0, x = 0; j < BOARD_X; j++, x += (ycellsize)) {
//			//			cout <<      " " << board_array[i][j] << " " << flush;
//			switch (board_array[i][j]) {
//			case NILL:
//				// Empty space
//				break;
//			case S_BRICK:
//				DrawRectangle(x - 10, y, ycellsize, xcellsize,
//						colors[SLATE_GRAY]);
//				//DrawLine(x - 10, y, x - 10 + ycellsize, y, 4, colors[BLACK]);
//				break;
//			case G_BRICK:
//				DrawRectangle(x - 10, y, ycellsize, xcellsize,
//						colors[LIGHT_GREEN]);
//				break;
//			case R_BRICK:
//				DrawRectangle(x - 10, y, ycellsize, xcellsize, colors[RED]);
//				break;
//			}
//		}
//	}
//	glPopMatrix();
}

int Board::getLevel() const {
	return level;
}

int Board::getCheck() const {
	return check;
}

int Board::getX(int i) const {
	return x[i];
}

bool Board::isGamePause() const {
	return gamePause;
}

void Board::setGamePause(bool gamePause) {
	this->gamePause = gamePause;
}

int Board::getY(int i) const {
	return y[i];
}

void Board::setCheck(int check) {
	this->check = check;
}

void Board::setLevel(int level) {
	this->level = level;
}

int Board::getScore() const {
	return score;
}

void Board::GetInitTextPosition(int &x, int &y) {
	x = xcellsize;
	y = (BOARD_Y - 1) * ycellsize + ycellsize / 2;
}
