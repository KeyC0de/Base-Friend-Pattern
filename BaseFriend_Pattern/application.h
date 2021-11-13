#pragma once

#include <memory>
#include "user_class.h"


class Graphics;

class Game
{
	std::unique_ptr<Graphics> gph;

	struct Vertex
	{
		int x;
		int y;
		int z;

		Vertex( int x, int y, int z )
			:
			x(x),
			y(y),
			z(z)
		{

		}
	};
	VertexBuffer<Vertex> m_pVb;
public:
	Game( int width, int height);
	~Game() noexcept;

	// run
	void loop();
};