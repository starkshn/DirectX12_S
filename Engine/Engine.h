#pragma once

class Engine
{
public:
	void Init(const WindowInfo& winInfo);
	void Render();


public:
	void RenderBegin();	// CommandQueue ���ٰ� ��û���׵� ���� �ð�? �κ�? ����
	void RenderEnd();	// ��¥ ������ �ƴ϶� GPU���� commit �� �κ����� ��� ���� ����.

	void ResizeWindow(int32 width, int32 height);
	
private:
	// �׷��� ȯ�� ũ�� ���� �� ������
	WindowInfo		_winInfo;
	D3D12_VIEWPORT	_viewport = {};
	D3D12_RECT		_scissorRect = {};

	// Tool? �ʱ�ȭ�� �� �ʿ��� �κе�
	shared_ptr<class Device>			_device;	// Device (�ٽ�?!)
	shared_ptr<class CommandQueue>		_cmdQueue;	// ������(�ϰ�) ó�� �κ�
	shared_ptr<class SwapChain>			_swapChain; // Double Buffering
	shared_ptr<class DescriptorHeap>	_descHeap;	// ?

};

