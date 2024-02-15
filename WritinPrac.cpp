#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <graphics.h>
using namespace std;

int main(int argc, char** argv)
{
	initwindow(1920, 1080, "WritinPrac", -3, -3, true, true);
	long long types = 0, correct = 0, acc;
	int page = 0, dots = 0;
	srand(time(NULL));
	vector<string> v;
	queue<int> q;
	v.push_back("animation");
	v.push_back("rendezvous");
	v.push_back("director");
	v.push_back("institution");
	v.push_back("computer");
	v.push_back("condition");
	v.push_back("situation");
	v.push_back("enthusiasm");
	v.push_back("abundant");
	v.push_back("adorable");
	v.push_back("anxious");
	v.push_back("appreciate");
	v.push_back("attractive");
	v.push_back("beautiful");
	v.push_back("careless");
	v.push_back("relentless");
	v.push_back("delicious");
	v.push_back("diamond");
	v.push_back("different");
	v.push_back("faithful");
	v.push_back("generously");
	v.push_back("handsome");
	v.push_back("humorous");
	v.push_back("jackhammer");
	v.push_back("knockout");
	v.push_back("patriotism");
	v.push_back("quadrilateral");
	v.push_back("magazine");
	v.push_back("rainbow");
	v.push_back("talented");
	v.push_back("umbrella");
	v.push_back("violent");
	v.push_back("window");
	v.push_back("youthful");
	settextstyle(10, 0, 5);
	while(!kbhit())
	{
		dots = (dots + 1) % 4;
		setactivepage(page);
		setvisualpage(1 - page);
		cleardevice();
		outtextxy(450, 200, "Get your hands ready!");
		outtextxy(450, 300, "Press any key to start");
		outtextxy(1200, 600, "Atul Raj");
		outtextxy(1200, 650, "21JE0195");
		outtextxy(1200, 700, "IIT(ISM)");
		outtextxy(1100, 750, "(c) Copyright");
		for(int i = 0; i < dots; i++)
			outtextxy(1000 + i*20, 300, ".");
		page = 1 - page;
		delay(200);
	}
	getch();
	setactivepage(page);
	setvisualpage(page);
	cleardevice();
	outtextxy(750, 300, "3");
	delay(1000);
	outtextxy(750, 300, "2");
	delay(1000);
	outtextxy(750, 300, "1");
	delay(1000);
	while(1)
	{
		int time = 600, size, pointer = 0, userpointer = 0, usercolor = GREEN;
		string final;
		for(int i = 0; i < 4; i++)
		{
			int choice = rand() % (v.size());
			final = final + v[choice] + " ";
		}
		size = final.size() - 1;
		char finalchar[100], userchar[100];
		for(int i = 0; i < 100; i++)
		{
			finalchar[i] = ' ';
			userchar[i] = ' ';
		}
		for(int i = 0; i < size; i++)
		{
			finalchar[i] = final[i];
			if(finalchar[i] == ' ')
				q.push(i);
		}
		while(pointer < size)
		{
			setactivepage(page);
			setvisualpage(1 - page);
			cleardevice();
			
			setcolor(WHITE);
			outtextxy(100, 200, finalchar);
			line(100 + pointer*25, 240, 125 + pointer*25, 240);
			acc = (types == 0)? 0 : (100*correct/types);
			char accnew[20];
			sprintf(accnew, "%d", acc);
			outtextxy(10, 50, "Accuracy : ");
			outtextxy(270, 50, accnew);
			outtextxy(350, 50, "%");
			
			if(kbhit())
			{
				types++;
				char c = getch();
				if(c == finalchar[pointer])
				{
					correct++;
					usercolor = GREEN;
					if(c == ' ')
						q.pop();
				}
				else
				{
					usercolor = RED;
					if(finalchar[pointer] == ' ')
						pointer--;
					else if(c == ' ')
					{
						if(q.empty())
							time = 0;
						else
						{
							if(!pointer)
								pointer--;
							else
							{
								pointer = q.front();
								q.pop();
							}
						}
						correct = (correct >= 10)? (correct - 10) : 0;
					}
				}
				pointer++;
				userchar[userpointer++] = c;
			}
			setcolor(usercolor);
			outtextxy(100, 400, userchar);
			
			int color;
			if(time >= 450)
				color = GREEN;
			else if(time >= 300)
				color = LIGHTGREEN;
			else if(time >= 150)
				color = YELLOW;
			else if(time >= 75)
				color = LIGHTRED;
			else
				color = RED;
			setcolor(color);
			rectangle(1099, 50, 1100 + (time*2)/3, 90);
			setfillstyle(SOLID_FILL, color);
			floodfill(1100, 75, color);
			
			if(!time)
			{
				correct = (correct >= 10)? (correct - 10) : 0;
				break;
			}
			time--;
			
			page = 1 - page;
			delay(20);
		}
	}
	return 0;
}
