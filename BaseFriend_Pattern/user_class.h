#pragma once

#include <vector>
#include <iostream>
#include "friend_class.h"

#if defined _DEBUG && !defined NDEBUG
#	define BDEBUG 1
#else
#	define BDEBUG 0
#endif
#define cond_noex noexcept( !BDEBUG )


template<typename VertexT>
class VertexBuffer
	: public GraphicsFriend
{
	unsigned m_nVertices;
	std::vector<VertexT> m_verts;
public:
	VertexBuffer()
		:
		m_nVertices{0}
	{
	
	}
	
	VertexBuffer( const std::vector<VertexT>& verts )
		:
		m_nVertices{verts.size()},
		m_verts{verts}
	{
	
	}
	
	VertexBuffer( const VertexBuffer& rhs ) = delete;
	VertexBuffer& operator=( const VertexBuffer& rhs ) = delete;

	void supply( const std::vector<VertexT>& verts )
	{
		m_verts.clear();
		m_nVertices = verts.size();
		m_verts.reserve( m_nVertices );
		for ( const VertexT& vertex : verts )
		{
			m_verts.emplace_back( vertex );
		}
	}
	
	void update( Graphics& gph ) cond_noex
	{
		std::cout << "Updating buffer with "
			<< m_nVertices
			<< "vertices\n";
		for ( const auto& vertex : m_verts )
		{
			std::cout << "(x=" << vertex.x + 1
				<< ",y=" << vertex.y + 1
				<< ",z=" << vertex.z + 1
				<< ")\n";
		}
	
		/// the User class (VertexBuffer) will now use the Resource class (Graphics) in whichever
		///		way it deems fit
		++getDevice( gph ).nFrame;
	}
};