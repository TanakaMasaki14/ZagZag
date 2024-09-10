#include "Terrain.h"
#include "DxLib.h"

// コンストラクタ
Terrain::Terrain(int width, int height, int chipSize):mapWidth(width),mapHeight(height),chipSize(chipSize)
{
}

// マップチップの関数
void Terrain::AddMapChip(const char* filePath, float posX, float posY)
{
	MapChip mapChip;
	mapChip.imageHandle = LoadGraph(filePath);
	mapChip.posX = posX;
	mapChip.posY = posY;
	mapChips.push_back(mapChip);
}

// マップの初期化
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

void Terrain::Remove(float posX, float posY)
{
	for (auto it = mapChips.begin(); it != mapChips.end(); ++it)
	{
		// マップチップの座標とプレイヤーの掘る座標を比較(当たり判定)
		{
			if (it->posX == posX && it->posY == posY)
			{
				// マップチップを削除
				it = mapChips.erase(it);
				break;
			}
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