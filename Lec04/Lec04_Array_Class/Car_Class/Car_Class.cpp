#include <iostream>
#include "Car_Class.h" // 작성한 Car 클래스 헤더 파일 포함

// SportsCar 클래스 (자식 클래스)
class SportsCar : public Car
{
public:
	bool bTurbo; // 터보 장치 ON?

	// 💡 새롭게 추가한 생성자: 부모 클래스(Car)의 생성자를 호출하여 초기화합니다.
	SportsCar(int s, const char* n, int g, bool t) : Car(s, n, g) {
		bTurbo = t;
	}

	void setTurbo(bool bTur) { bTurbo = bTur; }

	// 터보가 켜져 있으면 속도가 20씩 증가 (오버라이딩)
	void speedUp() {
		if (bTurbo) speed += 20;
		else Car::speedUp();
	}
};

int main() {
	// 1. 일반 자동차 테스트
	Car normalCar(50, "Normal Car", 3);
	normalCar.display();
	normalCar.speedUp();
	normalCar.display();
	normalCar.whereAmI();

	printf("-------------------\n");

	// 2. 스포츠카 테스트
	// 💡 이제 스포츠카를 만들 때 이름, 속도, 기어, 터보 상태를 한 번에 전달합니다.
	SportsCar mySportsCar(100, "Sports Car", 5, true);

	mySportsCar.display();     // 터보 가속 전 상태 출력

	mySportsCar.speedUp();     // 터보 가속 진행 (+20 증가)

	mySportsCar.display();     // 터보 가속 후 상태 출력
	mySportsCar.whereAmI();    // 객체 주소 출력

	return 0;
}