
#include"MiniSaucer.h"
#include"util.h"

MiniSaucer::MiniSaucer()
{
	shape=new Point[10];
	shape[0].assign(15,30);
	shape[1].assign(0,15);
	shape[2].assign(15,0);
	shape[3].assign(50,0);
	shape[4].assign(65,15);
	shape[5].assign(50,30);
	shape[6].assign(40,45);
	shape[7].assign(25,45);
	shape[8].assign(15,30);
	shape[9].assign(50,30);

	radius=30;

	center.assign(100,200);
	angle=0;
	alive=true;

	fireSize=2;
	fire=new Bullet*[fireSize];
	for(int i=0;i<fireSize;i++)
	{
		fire[i]=new Bullet;
	}
}
int MiniSaucer::getRadius()
{
	return radius;
}
void MiniSaucer::Draw()
{
	for (int i=0;i<10;i++)
	{
		DrawLine(shape[i].getX()+center.getX(), shape[i].getY()+center.getY(),shape[(i+1)%10].getX()+center.getX(), shape[(i+1)%10].getY()+center.getY(), 10, colors[SKY_BLUE]);
	}
	for (int i=0;i<fireSize;i++)
	{
		if (fire[i]->isDisplay())
		{
			fire[i]->Draw();
		}
	}



}
void MiniSaucer::Shoot()
{

}
Bullet* MiniSaucer::getBullet(int i)
{
	return fire[i];
}

void MiniSaucer::nextStateCheck(char c)
{
	if (Alive())
	{
		this->Draw();
		this->Move(c);

		for (int i=0;i<fireSize;i++)
		{
			if (fire[i]->isDisplay()==0)
			{
				fire[i]->setDisplay(true);
				fire[i]->setBullet(center.getX(),center.getY(),GetRandInRange(5,360));
			}
		}
		for (int i=0;i<fireSize;i++)
		{
			if (fire[i]->getTime1()>60)
			{
				fire[i]->setDisplay(false);
			}
			if (fire[i]->isDisplay())
			{
				fire[i]->Move(c);
			}
		}
	}

}

void MiniSaucer::Move(char c)
{
	if (center.getX()>1100)
	{
		center.setX(center.getX()-1100);
	}
	if (center.getX()<0)
	{
		center.setX(center.getX()+1100);
	}
	if (center.getY()>890)
	{
		center.setY(center.getY()-890);
	}
	if (center.getY()<0)
	{
		center.setY(center.getY()+890);
	}

	center.assign(center.getX()+5,center.getY()+(5*cos(Deg2Rad(angle))));
	angle+=3;
	if (angle>=360)
	{
		angle%=360;
	}
}
bool MiniSaucer::Alive()
{
	return alive;
}
Point MiniSaucer::getCenter()
{
	return center;
}
void MiniSaucer::Rotate(double)
{

}

MiniSaucer::~MiniSaucer() {
	// TODO Auto-generated destructor stub
}

void MiniSaucer::setAlive(bool alive) {
	this->alive = alive;
}
