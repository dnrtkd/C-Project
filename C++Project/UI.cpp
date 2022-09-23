#include "UI.h"
#include "CursorManager.h"

void UI::Start()
{
}

void UI::Render()
{
	for (size_t i = 0; i < box.size(); i++)
	{		
		CursorManager::GetInstance()->WriteBuffer(StartP.x, StartP.y+i, (char*)box[i].c_str());
	}
	
	CursorManager::GetInstance()->WriteBuffer(((StartP.x + (StartP.x + Widht)) / 2) - (title.size() / 2), StartP.y + 1, (char*)title.c_str());
	
	for (size_t i = 0; i < contents.size(); i++)
	{
		CursorManager::GetInstance()->WriteBuffer(StartP.x + 2, StartP.y + 3+i, (char*)contents[i].c_str());
	}
	
	
}

void UI::setTitle(string _title)
{
	title = _title;
}

void UI::InputContents(string content)
{
	contents.push_back(content);
}

void UI::drawRec()
{
	

}

void UI::setSize(int Width, int Height)
{
	Widht = Width;
	height = Height;
	for (int h = 0; h < Height; ++h)
	{
		box.push_back("");
		for (int w = 0; w < Width; ++w)
		{
			if (h == 0 || h == height-1)
				box[h].push_back('-');
			else
				box[h].push_back(' ');
			
		}
	}
}

UI::UI()
{
}

UI::~UI()
{
}
