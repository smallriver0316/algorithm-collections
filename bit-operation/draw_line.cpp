#include <iostream>
using namespace std;

#define PIXELS 320
#define BYTE_SIZE 8

void drawLine(unsigned char *screen, int width, int x1, int x2, int y)
{
  int startBitIdx = width * y + x1;
  int startByteIdx = startBitIdx >> 3;
  int startBitOffset = startBitIdx - (startByteIdx << 3);
  int endBitIdx = width * y + x2;
  int endByteIdx = endBitIdx >> 3;
  int endBitOffset = endBitIdx - (endByteIdx << 3);
  if (endBitIdx - startBitIdx < 0 || endBitIdx - startBitIdx + 1 > width)
  {
    return;
  }

  unsigned char headMask = ~((~0) << (BYTE_SIZE - startBitOffset));
  unsigned char tailMask = (~0) << (BYTE_SIZE - endBitOffset - 1);
  if (startByteIdx != endByteIdx)
  {
    screen[startByteIdx] |= headMask;
    screen[endByteIdx] |= tailMask;
    for (int i = startByteIdx + 1; i < endByteIdx; i++)
    {
      screen[i] = 0xFF;
    }
  }
  else // startByteIdx == endByteIdx
  {
    unsigned char mask = headMask & tailMask;
    screen[startByteIdx] |= mask;
  }
}

void printScreen(unsigned char *screen, int width)
{
  int height = PIXELS / width;
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < width; j += BYTE_SIZE)
    {
      int index = (i * width + j) / BYTE_SIZE;
      if (screen[index] == 0)
      {
        cout << "00000000";
      }
      else
      {
        for (int k = BYTE_SIZE - 1; k >= 0; k--)
        {
          if ((screen[index] >> k) & 1)
          {
            cout << "1";
          }
          else
          {
            cout << "0";
          }
        }
      }
    }
    cout << endl;
  }
}

int main()
{
  int len = PIXELS / BYTE_SIZE;
  unsigned char screen[len];

  for (int i = 0; i < len; i++)
  {
    screen[i] = 0;
  }

  int width, x1, x2, y;

  cin >> width >> x1 >> x2 >> y;
  if (x1 < 0 || x1 >= width || x2 < 0 || x2 >= width || y < 0 || y >= PIXELS / width)
  {
    cout << "Invalid Input" << endl;
    return -1;
  }

  drawLine(screen, width, x1, x2, y);

  printScreen(screen, width);

  return 0;
}
