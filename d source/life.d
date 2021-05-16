module life;

import std.stdio;
import std.string;
import std.conv;
import raylib;

class life{
	bool isAlive = false;
	int liveNeighbors = 0;
	Rectangle rec;
	Color liveColor = Colors.VIOLET;
	
	this(){}
	
	this(int x, int y, int size){ init(x, y, size); }
	
	void init(int x, int y, int size){
		rec.x = x;
		rec.y = y;
		rec.w = size;
		rec.h = size;
	}
	
	// Draw the life
	void draw(){
		if(isAlive) DrawRectangleRec(rec, liveColor);
		else DrawRectangleRec(rec, Colors.BLACK);
	}
	
	// Apply the rules of GOL to this life instance
	void update(){
		if(isAlive){
			if(liveNeighbors < 2 || liveNeighbors > 3) isAlive = false;
		}
		else{
			if(liveNeighbors == 3) isAlive = true;
		}
		liveNeighbors = 0;
	}
}
