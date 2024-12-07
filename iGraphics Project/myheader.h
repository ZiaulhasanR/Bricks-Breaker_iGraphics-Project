#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED

/*int pic_x, pic_y;
int dx, dy;

void objectChange() {
	pic_x += dx;
	pic_y += dy;

	if (pic_x >= 400 || pic_x <= 0)
		dx = -dx;
	if (pic_y >= 400 || pic_y <= 0)
		dy = -dy;
}*/
int dxx[5];
int dyy[5];
bool show[5];
for(int i=0;i<5;i++)
{
	dxx[i]=100;
}
for(int i=0;i<5;i++)
{
	dyy[i]=20;
}
for(int i=0;i<5;i++)
{
	show[i]=true;
}

#endif // !MYHEADER_H_INCLUDED
