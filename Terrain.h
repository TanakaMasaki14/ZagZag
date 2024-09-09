#pragma once
#include <vector>

class Terrain
{
private:

	// �}�b�v�`�b�v��\���\����
	struct MapChip
	{
		int imageHandle; // �摜�̃n���h��
		float posX; // X���W
		float posY; // Y���W
	};

	int mapWidth; // �}�b�v�̉���(�`�b�v�P��)
	int mapHeight; // �}�b�v�̏c��(�`�b�v�P��)
	int chipSize; // �`�b�v�̃T�C�Y
	std::vector<MapChip> mapChips; // �}�b�v�`�b�v�̃��X�g

public:
	Terrain(int width, int height, int chipSize); // �R���X�g���N�^

	void AddMapChip(const char* filePath, float posX, float posY);
	
	void InitializeMap(const char* filePath);
	
	void Update();

	void Draw();
};