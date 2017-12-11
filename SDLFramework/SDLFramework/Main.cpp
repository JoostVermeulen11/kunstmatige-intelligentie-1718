#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>

#include "Cow.h"
#include "Graph.h"


int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	auto graph = new Graph();
	
	application->SetTargetFPS(60);

	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){
					
				default:
					break;
				}
			case SDL_MOUSEBUTTONDOWN:
				graph->shortestPath();
				break;
			}

		}

		if (graph->cow->currentPoint() == graph->rabbit->currentPoint()) {
			graph->rabbit->setStartPoint(graph->getRandomVertex());
		}
				
		graph->draw();

		// For the background
		application->SetColor(Color(255, 255, 255, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}
