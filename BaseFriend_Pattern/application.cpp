#include "application.h"
#include <vector>
#include "resource_class.h"
#include <iostream>


Game::Game( int width, int height )
	:
	gph{std::make_unique<Graphics>( width, height )}
{
	// Initialization of Application/Game specific resources
	std::vector<Vertex> verts;
	verts.reserve( 3 );
	verts.emplace_back( 0, 0, 0 );
	verts.emplace_back( 0, 1, 0 );
	verts.emplace_back( 0, 0, 1 );
	m_pVb.supply( verts );
}

Game::~Game() noexcept
{
	std::cout << "Game ended.\nCome again!"
		<< std::endl;
}

void Game::loop()
{
	// update
	m_pVb.update( *(gph.get()) );

	// render
	gph->render();

	// present
	gph->present();
}