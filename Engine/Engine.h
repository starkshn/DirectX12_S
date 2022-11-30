#pragma once

#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"
#include "RootSignature.h"
#include "Mesh.h"
#include "Shader.h"
#include "ConstantBuffer.h"
#include "TableDescriptorHeap.h"
#include "Texture.h"
#include "DepthStencilBuffer.h"

// Component
#include "Input.h"
#include "Timer.h"

class Engine
{
public:
	void Init(const WindowInfo& winInfo);
	void Render();

public:
	void Update();

public:
	void RenderBegin();	// CommandQueue ���ٰ� ��û���׵� ���� �ð�? �κ�? ����
	void RenderEnd();	// ��¥ ������ �ƴ϶� GPU���� commit �� �κ����� ��� ���� ����.
	void ResizeWindow(int32 width, int32 height);

public:
	shared_ptr<Device>				GetDevice()			{ return _device; };
	shared_ptr<CommandQueue>		GetCmdQueue()		{ return _cmdQueue; };
	shared_ptr<SwapChain>			GetSwapChain()		{ return _swapChain; };
	shared_ptr<RootSignature>		GetRootSignature()	{ return _rootSignature; };
	shared_ptr<ConstantBuffer>		GetCB()				{ return _cb; };
	shared_ptr<TableDescriptorHeap> GetTableDescHeap() { return _tableDescHeap; };
	shared_ptr<DepthStencilBuffer> GetDepthStencilBuffer() { return _depthStencilBuffer; };

	// Component
	shared_ptr<Input> GetInput() { return _input; };
	shared_ptr<Timer> GetTimer() { return _timer; };

private:
	void ShowFPS();
	
private:
	// �׷��� ȯ�� ũ�� ���� �� ������
	WindowInfo		_winInfo;
	D3D12_VIEWPORT	_viewport = {};
	D3D12_RECT		_scissorRect = {};
	
	shared_ptr<Device> _device = make_shared<Device>();
	shared_ptr<CommandQueue> _cmdQueue = make_shared<CommandQueue>();
	shared_ptr<SwapChain> _swapChain = make_shared<SwapChain>();
	shared_ptr<RootSignature> _rootSignature = make_shared<RootSignature>();
	shared_ptr<ConstantBuffer> _cb = make_shared<ConstantBuffer>();
	shared_ptr<TableDescriptorHeap> _tableDescHeap = make_shared<TableDescriptorHeap>();
	shared_ptr<DepthStencilBuffer> _depthStencilBuffer = make_shared<DepthStencilBuffer>();

	// component
	shared_ptr<Input> _input = make_shared<Input>();
	shared_ptr<Timer> _timer = make_shared<Timer>();
};

 