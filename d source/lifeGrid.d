module board;

import std.stdio;
import std.random;
import raylib;
import life;

class board{
	life[][] grid;
	int yPos, lifeSize, width, height;
	
	@property int MouseX(){ return GetMouseX() / lifeSize; }
	@property int MouseY(){ return (GetMouseY() - yPos) / lifeSize; }
	
	this(int width, int height, int lifeSize, int yPos){
		this.width = width;
		this.height = height;
		this.lifeSize = lifeSize;
		this.yPos = yPos;
		
		grid = new life[][](width, height);
		
		foreach(y; 0 .. height){
			foreach(x; 0 .. width){
				grid[x][y] = new life(x * lifeSize, y * lifeSize + yPos, lifeSize);
			}
		}
	}
	
	// Count the number of living neighbors at given coordinates
	void countNeighbors(int X, int Y){
		for(int y = Y-1; y <= Y+1; y++){
			for(int x = X-1; x <= X+1; x++){
				if(!(x == X && y == Y)){
					if(x >= 0 && x < width && y >= 0 && y < height){
						if(grid[x][y].isAlive) grid[X][Y].liveNeighbors++;
					}
				}
			}
		}
	}
	
	// The new way of updating. Each life has pointers to its neighbors and applies rules to itself
	void update(){
		foreach(y; 0 .. height){
			foreach(x; 0 .. width){
				countNeighbors(x, y);
			}
		}
		foreach(y; 0 .. height){
			foreach(x; 0 .. width){
				grid[x][y].update();
			}
		}
	}
	
	// Handle mouse clicks
	void checkMouse(){
		if(!IsMouseButtonDown(MouseButton.MOUSE_LEFT_BUTTON)) return;
		if(!CheckCollisionPointRec(GetMousePosition(), Rectangle(0, cast(float)yPos, cast(float)(width * lifeSize), cast(float)(height * lifeSize)))) return;
		
		grid[MouseX][MouseY].isAlive = true;
	}
	
	// Draw the board
	void draw(){
		checkMouse();
		foreach(y; 0 .. height){
			foreach(x; 0 .. width){
				grid[x][y].draw();
			}
		}
		DrawRectangle(MouseX() * lifeSize, MouseY() * lifeSize + yPos, lifeSize, lifeSize, Color(255, 255, 255, 100));
	}
}
