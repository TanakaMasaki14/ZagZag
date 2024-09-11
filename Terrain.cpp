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
	mapChip.isRemove = false;
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
	for (auto& mapChip : mapChips)
	{
		// プレイヤーが掘った位置とマップチップの位置を比較
		if (mapChip.posX == posX && mapChip.posY == posY)
		{
			// マップチップを非表示にする（削除フラグを立てる）
			mapChip.isRemove = true;
			break;
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
		if (chip.imageHandle != -1 && !chip.isRemove)
		{
			DrawGraph(static_cast<int>(chip.posX), static_cast<int>(chip.posY), chip.imageHandle, TRUE);
		}
	}
}