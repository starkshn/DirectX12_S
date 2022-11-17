#include "pch.h"
#include "Engine.h"
#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"
#include "DescriptorHeap.h"

void Engine::Init(const WindowInfo& winInfo)
{
	_winInfo = winInfo;
	ResizeWindow(winInfo.width, winInfo.height);

	// �׷��� ȭ�� ũ�� ����
	_viewport = { 0, 0, static_cast<FLOAT>(winInfo.width), static_cast<FLOAT>(winInfo.height), 0.0f, 1.0f };
	_scissorRect = CD3DX12_RECT(0, 0, winInfo.width, winInfo.height);

	// �ʱ�ȭ �۾�
	_device = make_shared<Device>();
	_cmdQueue = make_shared<CommandQueue>();
	_swapChain = make_shared<SwapChain>();
	_descHeap = make_shared<DescriptorHeap>();

	_device->Init();
	_cmdQueue->Init(_device->GetDevice(), _swapChain, _descHeap);
	_swapChain->Init(winInfo, _device->GetDXGI(), _cmdQueue->GetCmdQueue());
	_descHeap->Init(_device->GetDevice(), _swapChain);
}

void Engine::Render()
{
	RenderBegin();

	// TODO : ������ ��ü���� �׷��ش�.

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
	
}
