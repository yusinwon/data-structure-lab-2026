#pragma once
#include <iostream>
#define	HEIGHT	8
#define	WIDTH	8

int GetMaxBrightness(int img[HEIGHT][WIDTH]) {
    int max_val = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (img[i][j] > max_val) {
                max_val = img[i][j];
            }
        }
    }
    return max_val;
}
int main() {
int image[HEIGHT][WIDTH] = {
  {  10,  30,  55,  80, 120, 160, 200, 230},
  {  20,  45,  70, 100, 140, 180, 220, 210},
  {  35,  60,  90, 130, 170, 210, 240, 190},
  {  50,  80, 115, 150, 190, 230, 255, 170},
  {  40,  65, 100, 140, 175, 215, 235, 150},
  {  25,  50,  80, 115, 155, 195, 210, 130},
  {  15,  35,  60,  90, 130, 165, 185, 110},
  {    5,  20,  40,  70, 105, 140, 160,  90},
};

// 함수를 호출하여 최댓값을 알아냄
int max_pixel = GetMaxBrightness(image);

// 결과 출력
std::cout << "이미지의 최대 화소 밝기: " << max_pixel << std::endl;

return 0;
}
