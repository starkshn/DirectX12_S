#pragma once
class Texture
{
public:
	void Init(const wstring& path);

public:
	void CreateTexture(const wstring& path);
	void CreateView();

public:
	D3D12_CPU_DESCRIPTOR_HANDLE GetCpuHandle() { return _srvHandle; }

private:
	ScratchImage			 		_image;
	ComPtr<ID3D12Resource>			_tex2D;


	// View µÎ°³
	ComPtr<ID3D12DescriptorHeap>	_srvHeap;
	D3D12_CPU_DESCRIPTOR_HANDLE		_srvHandle;

};

