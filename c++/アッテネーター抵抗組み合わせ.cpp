#include <iostream>
#include <fstream>

void swap(float*, float*);

int main()
{
	std::ofstream ofs;
	ofs.open("data.txt", std::ios::out);

	//抵抗器系列(ex. E12系列  { 1.0F,1.2F,1.5F,1.8F,2.2F,2.7F,3.3F,3.9F,4.7F,5.6F,6.8F,8.2F }  )
	const float resister_0[] = { 1.0F,1.2F,1.5F,1.8F,2.2F,2.7F,3.3F,3.9F,4.7F,5.6F,6.8F,8.2F };

	//アッテネーター最大、最小インピーダンス
	const float impedance_Max = 100000;
	const float impedance_Min = 10000;

	const int size_0 = std::extent<decltype(resister_0), 0>::value;
	const int a = (int)std::log10(impedance_Max + 1) + 1;

	//抵抗器配列作成
	const int size_1 = size_0 * a;

	float* resister_1 = new float[size_1];
	for (int i = 0; i < a; i++)
	{
		for (int n = 0; n < size_0; n++)
		{
			resister_1[i * size_0 + n] = resister_0[n] * (float)pow(10, i);
		}
	}


	//データ作成
	const int size_2 = size_1 * size_1;

	float** data_0 = new float* [size_2];
	for (int i = 0; i < size_2; i++)
	{
		data_0[i] = new float[4];
	}

	int b = 0;
	for (int i = 0; i < size_1; i++)
	{
		for (int n = 0; n < size_1; n++)
		{
			data_0[i * size_1 + n][0] = resister_1[i];
			data_0[i * size_1 + n][1] = resister_1[n];
			data_0[i * size_1 + n][2] = resister_1[n] / (resister_1[i] + resister_1[n]);
			data_0[i * size_1 + n][3] = resister_1[i] + resister_1[n];
			if (impedance_Min < data_0[i * size_1 + n][3] && data_0[i * size_1 + n][3] < impedance_Max)
			{
				b++;
			}
		}


	}

	delete[] resister_1;


	//データ整理
	float** data_1 = new float* [b];
	for (int i = 0; i < b; i++)
	{
		data_1[i] = new float[4];
	}

	int c = 0;
	for (int i = 0; i < size_2; i++)
	{
		if (impedance_Min < data_0[i][3] && data_0[i][3] < impedance_Max)
		{
			data_1[c][0] = data_0[i][0];
			data_1[c][1] = data_0[i][1];
			data_1[c][2] = data_0[i][2];
			data_1[c][3] = data_0[i][3];
			c++;
		}
	}

	for (int i = 0; i < size_2; i++)
	{
		delete[]  data_0[i];
	}
	delete[] data_0;



	//データソート
	for (int i = 0; i != 1;)
	{
		i = 1;
		for (int n = 0; n < b - 1; n++)
		{
			if (data_1[n][2] > data_1[n + 1][2])
			{
				swap(&data_1[n][0], &data_1[n + 1][0]);
				swap(&data_1[n][1], &data_1[n + 1][1]);
				swap(&data_1[n][2], &data_1[n + 1][2]);
				swap(&data_1[n][3], &data_1[n + 1][3]);
				i = 0;
			}
		}
	}




	//データ表示
	for (int i = 0; i < b; i++)
	{
		std::cout << data_1[i][2] << std::endl;
		ofs << i << " " << data_1[i][2] << std::endl;
	}


	for (int i = 0; i < b; i++)
	{
		delete[]  data_1[i];
	}
	delete[] data_1;


	return 0;
}

void swap(float* a, float* b) {
	float c = 0;
	c = *b;
	*b = *a;
	*a = c;
}
