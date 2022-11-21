#pragma once

#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"
#include "RootSignature.h"
#include "Mesh.h"
#include "Shader.h"
#include "ConstantBuffer.h"

class Engine
{
public:
	void Init(const WindowInfo& winInfo);
	void Render();

public:
	void RenderBegin();	// CommandQueue ���ٰ� ��û���׵� ���� �ð�? �κ�? ����
	void RenderEnd();	// ��¥ ������ �ƴ϶� GPU���� commit �� �κ����� ��� ���� ����.
	void ResizeWindow(int32 width, int32 height);

public:
	shared_ptr<Device>				GetDevice()			{ return _device; };
	shared_ptr<CommandQueue>		GetCmdQueue()		{ return _cmdQueue; };
	shared_ptr<SwapChain>			GetSwapChain()		{ return _swapChain; };
	shared_ptr<RootSignature>		GetRootSignature()	{ return _rootSignature; };
	shared_ptr<ConstantBuffer>		GetCB()				{ return _cd; };
	
private:
	// �׷��� ȯ�� ũ�� ���� �� ������
	WindowInfo		_winInfo;
	D3D12_VIEWPORT	_viewport = {};
	D3D12_RECT		_scissorRect = {};
	
	// Tool? �ʱ�ȭ�� �� �ʿ��� �κе�
	shared_ptr<Device>				_device;	// Device (�ٽ�?!)
	shared_ptr<CommandQueue>		_cmdQueue;	// ������(�ϰ�) ó�� �κ�
	shared_ptr<SwapChain>			_swapChain; // Double Buffering
	shared_ptr<RootSignature>		_rootSignature;

	// shared_ptr<class DescriptorHeap>	_descHeap;	// ?
	
	shared_ptr<ConstantBuffer> _cd;
};

 