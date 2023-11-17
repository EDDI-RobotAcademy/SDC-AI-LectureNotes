#ifndef ADD_H_
#define ADD_H_

// 실제 GoogleTest는 C++ 코드에 해당하므로
// C 코드와 연동 할 때는 아래와 같은 설정이 필요합니다
// C++ 이라면 하위 extern "C" { 프로토타입 } 이 있으니 참고하라는 뜻
// 결론적으로 C 타입으로 만든 함수가 있으니까 이거 봐야해!
// 라는 것을 알려주는 부분입니다.
#ifdef __cplusplus
extern "C" {
#endif

int add(int num1, int num2);

#ifdef __cplusplus
}
#endif

#endif