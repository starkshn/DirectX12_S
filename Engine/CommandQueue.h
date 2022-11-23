#pragma once

class SwapChain;
class DescriptorHeap;
 
class CommandQueue
{
public:
	~CommandQueue();

	void Init(ComPtr<ID3D12Device> device, shared_ptr<SwapChain> swapChain);
	void WaitSync();

	// 실제로 게임이 그려지는 부분
	void RenderBegin(const D3D12_VIEWPORT* vp, const D3D12_RECT* rect);
	void RenderEnd();

	void FlushResourceCommandQueue();

public:
	ComPtr<ID3D12CommandQueue>			GetCmdQueue()	{ return _cmdQueue; };
	ComPtr<ID3D12GraphicsCommandList>	GetCmdList() { return _cmdList; }; // 뭐시기 리스트임.
	ComPtr<ID3D12GraphicsCommandList>	GetResourceCmdList()	{ return _resCmdList; }; // 뭐시기 리스트임.

private:
	// CommandQueue : DX12에 등장
	// 외주를 요청할 때, 하나씩 요청하면 비효율적
	// [외주 목록]에 일감을 차곡차곡 기록했다가 한 방에 요청하는 것
	// 이거 3개가 main임
	ComPtr<ID3D12CommandQueue>			_cmdQueue; // GPU한테 한방에 요청할 부분이다.
	ComPtr<ID3D12CommandAllocator>		_cmdAlloc; // 일감을 넣어주게 해주는 메모리 할당 부분
	ComPtr<ID3D12GraphicsCommandList>	_cmdList; // Command 리스트임.


	ComPtr<ID3D12CommandAllocator>		_resCmdAlloc;
	ComPtr<ID3D12GraphicsCommandList>	_resCmdList; 
	

	// Fence : 울타리 (?)
	// CPU / GPU 동기화를 위한 간단한 도구
	// 데이터 처리가 끝날 때까지 기다릴 수 있게하는 기능.
	ComPtr<ID3D12Fence>					_fence;
	uint32								_fenceValue = 0;
	HANDLE								_fenceEvent = INVALID_HANDLE_VALUE;
	
	shared_ptr<SwapChain>				_swapChain;

};

