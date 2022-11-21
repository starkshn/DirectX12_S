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
	void RenderBegin();	// CommandQueue 에다가 요청사항들 넣을 시간? 부분? 정도
	void RenderEnd();	// 진짜 끝난게 아니라 GPU에게 commit 할 부분정도 라고 이해 ㄱㄱ.
	void ResizeWindow(int32 width, int32 height);

public:
	shared_ptr<Device>				GetDevice()			{ return _device; };
	shared_ptr<CommandQueue>		GetCmdQueue()		{ return _cmdQueue; };
	shared_ptr<SwapChain>			GetSwapChain()		{ return _swapChain; };
	shared_ptr<RootSignature>		GetRootSignature()	{ return _rootSignature; };
	shared_ptr<ConstantBuffer>		GetCB()				{ return _cd; };
	
private:
	// 그려질 환면 크기 관련 된 변수들
	WindowInfo		_winInfo;
	D3D12_VIEWPORT	_viewport = {};
	D3D12_RECT		_scissorRect = {};
	
	// Tool? 초기화에 꼭 필요한 부분들
	shared_ptr<Device>				_device;	// Device (핵심?!)
	shared_ptr<CommandQueue>		_cmdQueue;	// 데이터(일감) 처리 부분
	shared_ptr<SwapChain>			_swapChain; // Double Buffering
	shared_ptr<RootSignature>		_rootSignature;

	// shared_ptr<class DescriptorHeap>	_descHeap;	// ?
	
	shared_ptr<ConstantBuffer> _cd;
};

 