#pragma once


#include "include/SDL.h"
#include "include/SDL_ttf.h"
#include "include/SDL_image.h"
#include "Cell.h"
#include <vector>
#include <iostream>


// Game class
class Game
{
public:
	Game();
	// Initialize the game
	bool Initialize();
	// Runs the game loop until the game is over
	void RunLoop();
	// Shutdown the game
	void Shutdown();
	//checks for shutdown
	bool getExit() const;





private:
	// Helper functions for the game loop
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void getMousePos();
	void drawGrid();
	int numAdy(int x);
	void PauseExit();
	void drawCell(int x);
	void eraseCell(int x);


	// Window created by SDL
	SDL_Window* mWindow;
	// Renderer for 2D drawing
	SDL_Renderer* mRenderer;
	// Number of ticks since start of game
	Uint32 mTicksCount;
	// Game should continue to run
	bool mIsRunning;

	//Pause
	bool mPause;
	//exit
	bool mExit;

	//GRID
	Cell* cell2;
	std::vector<std::vector<std::unique_ptr<Cell>>> Grid;//(4,std::vector<Cell*>(4,Cell*));
	Cell **Grid2;
	SDL_Rect cell2Render = {0,0,10,10 };
	SDL_Rect* cell2Renderp = &cell2Render;
	// Pong specific

};
