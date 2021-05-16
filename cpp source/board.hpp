#include <raylib.h>
#include <string>

#include "life.hpp"

using namespace std;

class board{
public:
	life** grid;
	int yPos, lifeSize, width, height;
	
	// Get grid coordinates based on the mouse position
	int MouseX(){ return GetMouseX() / lifeSize; }
	int MouseY(){ return (GetMouseY() - yPos) / lifeSize; }
	
	board(int w, int h, int size, int ypos){
		yPos = ypos;
		width = w;
		height = h;
		lifeSize = size;
		
		grid = new life*[width];
		for(int i = 0; i < width; i++){
			grid[i] = new life[height];
		}
		
		for(int y = 0; y < height; y++){
			for(int x = 0; x < width; x++){
				grid[x][y].init(x * size, y * size + yPos, size);
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
	
	// Update the board by one frame
	void update(){
		for(int y = 0; y < height; y++){
			for(int x = 0; x < width; x++){
				countNeighbors(x, y);
			}
		}
		for(int y = 0; y < height; y++){
			for(int x = 0; x < width; x++){
				grid[x][y].update();
			}
		}
	}
	
	// Handle mouse clicks
	void checkMouse(){
		if(!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) return;
		if(!CheckCollisionPointRec(GetMousePosition(), Rectangle{0, (float)yPos, (float)(width * lifeSize), (float)(height * lifeSize)})) return;
				
		grid[MouseX()][MouseY()].isAlive = true;
	}
	
	// Draw the board
	void draw(){
		checkMouse();
		for(int y = 0; y < height; y++){
			for(int x = 0; x < width; x++){
				grid[x][y].draw();
			}
		}
		DrawRectangle(MouseX() * lifeSize, MouseY() * lifeSize + yPos, lifeSize, lifeSize, Color{255, 255, 255, 100});
	}
};

