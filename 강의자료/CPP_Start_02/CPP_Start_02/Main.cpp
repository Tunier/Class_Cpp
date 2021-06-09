//#include <stdio.h>
#include <iostream>

/*
struct Object
{

};
*/

class Object
{

};

int main(void)
{
	//Object* pObj = (Object*)malloc(sizeof(Object));
	Object* pObj = new Object;


	//printf_s("Hello World!!");
	std::cout << "Hello World!!" << std::endl;


	//free(pObj);
	//pObj = NULL;

	delete pObj;
	pObj = NULL;


	return 0;
}






/*
//** 객체지향 특징 5가지

1. 정보은닉
데이터를 은닉 하는것이 가능하고, 만약 데이터에 접근해야하는 상황이 발생했을때,
접근 권한을 요청 할 수 있다. 그리고 요청을 받은후에 데이터접근 권한을 
허가할지 말지 결정 할 수 있다.


2. 캡슐화
데이터와 기능을 별도로 보지않고 하나로 봄으로서, 
하나의 객체가 데이터와 기능을 동시에 갖을수 있도록 한다.


3. 추상화
프로그램을 작성할때 여러객체를 하나의 추상객체로 봄으로서,
개체를 관리하기 편하게 해준다.


4. 상속
부모계층과 자식계층 생김으로서 부모의 기능 및 데이터를 공유 할 수 있고,
자기 자신의 기능 및 데이터를 사용 할 수 있다.


5. 다형성
하나의 형식을두고 여러가지의 형태로 존재 할 수 있는것.

예1:) 공 => 축구공, 농구공, 야구공 등 으로 존재 할 수 있다.
예2:) 펜 => 볼펜, 연필, 샤프 등으로 존재 할 수 있다.

*/