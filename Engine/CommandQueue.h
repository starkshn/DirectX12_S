#pragma once

class SwapChain;
class DescriptorHeap;
 
class CommandQueue
{
public:
	~CommandQueue();

	void Init(ComPtr<ID3D12Device> device, shared_ptr<SwapChain> swapChain);
	void WaitSync();

	// ������ ������ �׷����� �κ�
	void RenderBegin(const D3D12_VIEWPORT* vp, const D3D12_RECT* rect);
	void RenderEnd();

	void FlushResourceCommandQueue();

public:
	ComPtr<ID3D12CommandQueue>			GetCmdQueue()	{ return _cmdQueue; };
	ComPtr<ID3D12GraphicsCommandList>	GetCmdList() { return _cmdList; }; // ���ñ� ����Ʈ��.
	ComPtr<ID3D12GraphicsCommandList>	GetResourceCmdList()	{ return _resCmdList; }; // ���ñ� ����Ʈ��.

private:
	// CommandQueue : DX12�� ����
	// ���ָ� ��û�� ��, �ϳ��� ��û�ϸ� ��ȿ����
	// [���� ���]�� �ϰ��� �������� ����ߴٰ� �� �濡 ��û�ϴ� ��
	// �̰� 3���� main��
	ComPtr<ID3D12CommandQueue>			_cmdQueue; // GPU���� �ѹ濡 ��û�� �κ��̴�.
	ComPtr<ID3D12CommandAllocator>		_cmdAlloc; // �ϰ��� �־��ְ� ���ִ� �޸� �Ҵ� �κ�
	ComPtr<ID3D12GraphicsCommandList>	_cmdList; // Command ����Ʈ��.


	ComPtr<ID3D12CommandAllocator>		_resCmdAlloc;
	ComPtr<ID3D12GraphicsCommandList>	_resCmdList; 
	

	// Fence : ��Ÿ�� (?)
	// CPU / GPU ����ȭ�� ���� ������ ����
	// ������ ó���� ���� ������ ��ٸ� �� �ְ��ϴ� ���.
	ComPtr<ID3D12Fence>					_fence;
	uint32								_fenceValue = 0;
	HANDLE								_fenceEvent = INVALID_HANDLE_VALUE;
	
	shared_ptr<SwapChain>				_swapChain;

};

