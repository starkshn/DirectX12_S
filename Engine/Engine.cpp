#include "pch.h"
#include "Engine.h"


void Engine::Init(const WindowInfo& winInfo)
{
	_winInfo = winInfo;

	// 그려질 화면 크기 설정
	_viewport = { 0, 0, static_cast<FLOAT>(winInfo.width), static_cast<FLOAT>(winInfo.height), 0.0f, 1.0f };
	_scissorRect = CD3DX12_RECT(0, 0, winInfo.width, winInfo.height);

	// 초기화 작업
	_device = make_shared<Device>();
	_cmdQueue = make_shared<CommandQueue>();
	_swapChain = make_shared<SwapChain>();
	_rootSignature = make_shared<RootSignature>();
	_cd = make_shared<ConstantBuffer>();
	_tableDescHeap = make_shared<TableDescriptorHeap>();
	_depthStencilBuffer = make_shared<DepthStencilBuffer>();

	_device->Init();
	_cmdQueue->Init(_device->GetDevice(), _swapChain);
	_swapChain->Init(winInfo, _device->GetDevice(), _device->GetDXGI(), _cmdQueue->GetCmdQueue());
	_rootSignature->Init();
	_cd->Init(sizeof(Transform), 256);
	_tableDescHeap->Init(256);
	_depthStencilBuffer->Init(_winInfo);

	ResizeWindow(winInfo.width, winInfo.height);
}

void Engine::Render()
{
	RenderBegin();

	// TODO : 나머지 물체들을 그려준다.

	RenderEnd();
}

void Engine::RenderBegin()
{
	_cmdQueue->RenderBegin(&_viewport, &_scissorRect);
}

void Engine::RenderEnd()
{
	_cmdQueue->RenderEnd();
}

void Engine::ResizeWindow(int32 width, int32 height)
{
	_winInfo.width = width;
	_winInfo.height = height;

	RECT rect = { 0, 0, width, height };
	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	::SetWindowPos(_winInfo.hWnd, 0, 100, 100, width, height, 0);

	_depthStencilBuffer->Init(_winInfo);
	
}
