#include "Terrain.h"
#include "DxLib.h"

// �R���X�g���N�^
Terrain::Terrain(int width, int height, int chipSize):mapWidth(width),mapHeight(height),chipSize(chipSize)
{
}

// �}�b�v�`�b�v�̊֐�
void Terrain::AddMapChip(const char* filePath, float posX, float posY)
{
	MapChip mapChip;
	mapChip.imageHandle = LoadGraph(filePath);
	mapChip.posX = posX;
	mapChip.posY = posY;
	mapChips.push_back(mapChip);
}

// �}�b�v�̏�����
void Terrain::InitializeMap(const char* filePath)
{
	for (int y = 0; y < mapHeight; ++y)
	{
		for (int x = 0; x < mapWidth; ++x)
		{
			float posX = static_cast<float>(x * chipSize);
			float posY = static_cast<float>(y * chipSize);
			AddMapChip(filePath, posX, posY);
		}
	}
}

void Terrain::Update()
{
}

void Terrain::Draw()
{
	for (const auto& chip : mapChips)
	{
		if (chip.imageHandle != -1)
		{
			DrawGraph(static_cast<int>(chip.posX), static_cast<int>(chip.posY), chip.imageHandle, TRUE);
		}
	}
}