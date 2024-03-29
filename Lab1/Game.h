#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include <glfw3.h>
#include "ScreenDisplay.h"
#include "FBO.h"
#include "Audio.h"
#include "GameObject.h"
#include "Shading.h"
#include "Texturing.h"
#include <string>
#include <iostream>
using std::cout;

enum class GameState { PLAYING, QUITTING };

class Game
{
public:

	Game();
	~Game();

	void StartGame(); //This function boots up the game
	void Exit(std::string text); //This function lets the user exit the app by pressing any key

private:

	void InitializeSystems(); //This function initializes the game's systems
	void ProcessUserInputs(); //This function takes in and processes the user's inputs
	void GameLoop(); //This function runs the game loop; no game loop means the game ends
	void UpdateScreen(); //This function updates the game's display
	void DrawDisplay();
	void DrawMinimap();
	void UpdateDelta();

	bool DetectCollision(glm::vec3 position1, float radius1, glm::vec3 position2, float radius2);

	void LinkFogShaderData();
	void LinkToonShaderData();
	void LinkRimLightingShaderData();
	void LinkToonRimShaderData(Camera camera);
	void LinkGeoShaderData();
	void LinkReflectionShaderData();
	void LinkADSShaderData();

	GameState gameState; //Variable holding a reference to the current game state
	ScreenDisplay* gameDisplay; //Variable holding a pointer to the game's screen display

	GameObject monkey;
	GameObject teapot;
	GameObject laser;
	GameObject asteroids[8];
	GameObject spaceship;
	Camera camera;
	Camera minimapCamera;
	FBO displayFBO;
	FBO minimapFBO;

	Texturing textures;
	Shading shader;
	Shading fogshader;
	Shading toonshader;
	Shading rimshader;
	Shading toonrimshader;
	Shading geoshader;
	Shading reflectionshader;
	Shading adsshader;
	Shading fboshader;
	Shading fbograyscaleshader;
	Shading fboinversionshader;
	Audio audio;

	Uint64 deltaNow = SDL_GetPerformanceCounter();
	Uint64 deltaLast = 0;
	float deltaTime = 0;
	float deltaTimeSeconds = 0;

	float cameraSpeed = 5;
	float meshSpeed = 10;

	bool cameraLock = true;

	float counter;

	//TODO: move skybox stuff to its own class
	void DisplaySkybox();
	void InitializeSkybox();
	GLuint skyboxVAO, skyboxVBO, cubemapTexture;
	std::vector<std::string> faces;
	Texturing skybox;
	Shading shaderSkybox;
};

