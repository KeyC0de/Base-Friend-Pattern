#pragma once


class Graphics
{
	friend class GraphicsFriend;

	int m_width;
	int m_height;

	struct GPUDevice
	{
		unsigned nFrame;
		char adapterName[32];
	} m_device;
public:
	Graphics( int width, int height );

	void render();
	void present();
};