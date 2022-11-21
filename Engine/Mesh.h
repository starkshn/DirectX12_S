#pragma once

// [����Ƽ¯]�� ���� �������� �̷���� ��ü
class Mesh
{
public:
	void Init(vector<Vertex>& vec);
	void Render(); 

private:
	ComPtr<ID3D12Resource>		_vertexBuffer;
	D3D12_VERTEX_BUFFER_VIEW	_vertexBufferView = {}; // ID3D12Resource �� ����Ű�� ��Ī�ϴ� ����.
	uint32						_vertexCount = 0;
};

