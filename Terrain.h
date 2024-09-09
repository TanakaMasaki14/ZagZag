#pragma once
#include <vector>

class Terrain
{
private:

	// マップチップを表す構造体
	struct MapChip
	{
		int imageHandle; // 画像のハンドル
		float posX; // X座標
		float posY; // Y座標
	};

	int mapWidth; // マップの横幅(チップ単位)
	int mapHeight; // マップの縦幅(チップ単位)
	int chipSize; // チップのサイズ
	std::vector<MapChip> mapChips; // マップチップのリスト

public:
	Terrain(int width, int height, int chipSize); // コンストラクタ

	void AddMapChip(const char* filePath, float posX, float posY);
	
	void InitializeMap(const char* filePath);
	
	void Update();

	void Draw();
};