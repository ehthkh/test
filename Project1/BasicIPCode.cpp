#include <stdio.h>
#include <string.h>

using namespace std;

//size of individual image
int width = 512;
int height = 512;

//size of input image
int inputWidth = 512;
int inputHeight = 512;

int offset = 16;

char strInputFile[] = "lena(512x512).raw";
char strOutputFile[] = "extracted.raw";

int main()
{
	printf("Hi\n");
	FILE* pInput = NULL;
	FILE* pOutput = NULL;
	//���� 1 - char* buf = new char[width*2];
	//����ũ�� : 262144byte / �ػ󵵰� 512x512��� ������ ���� 512�� �������� 1px�� 1byte��� ������ ����
	int imageSize = width * height;
	char* buf = new char[imageSize];
	//����2 - memset(buf, 0, width*2);
	//�ʿ� ���� ����

	fopen_s (&pInput, strInputFile, "rb");
	fopen_s (&pOutput, strOutputFile, "wb");

	/* ����3 - �ǹ̾��� �ݺ���
	for (int i = 0; i < height; i++)
	{
		//read in a row of pixels
		fread_s (buf, width, 1, width, pInput);
		//write out the row of pixels
		fwrite (buf, width, 1, pOutput);
		//move the file pointer forward to the next row of pixels
		//fseek(pInput, inputWidth - width, SEEK_CUR);
	}
	*/

	fread(buf, imageSize, 1, pInput);
	fwrite(buf, imageSize, 1, pOutput);

	delete[] buf;
	fclose(pInput);
	fclose(pOutput);

	printf("end\n");
	return 0;
}