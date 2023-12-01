#include <iostream>
#include "dice/Dice.h"
#include "player/Player.h"
#include "post/Post.h"
#include "vector/Vector.h"

//int main() {
////    if (true) {
////        Dice dice;
////        Dice dice2;
////    }
//
//    Dice *dice = new Dice();
//    dice->rollDice();
//
//    std::cout << "얼마 나옴 ? " << dice->getDiceNumber() << std::endl;
//
//    // 포인터로 객체 받았을 경우 delete가 필요함
//    delete dice;
//
//    Dice dice2;
//    dice2.rollDice();
//
//    std::cout << "이것도 됨 ? " << dice2.getDiceNumber() << std::endl;
//
//    std::string test_name = "테스트";
//    Player *player = new Player(test_name, 20);
//
//    std::cout << "사용자 정보 - 이름: " << player->getPlayerName() <<
//        ", 나이: " << player->getPlayerAge() << std::endl;
//
//    delete player;
//    std::string post_user = "리빵준";
//    std::string post_title = "속보 대한민국 전국민 탈모증세 보여";
//    std::string post_content = "손흥민의 플레이에서 '헤어'나올 수 없어...";
//    Post *post =new Post(1,post_user,post_title,post_content);
//    std::cout << "게시글 정보 - 번호: " << post->getPostNumber()
//              << ", 사용자: " << post->getPostUserName()
//              << ", 제목: " << post->getPostTitle()
//              << ", 내용: " << post->getPostContent()
//              << std::endl;
//    delete post;
//    Vector *vector=new Vector();
//    std::cout <<"현재 벡터 값"
//              <<vector->getxVector()<<" "
//              <<vector->getyVector()<<" "
//              <<vector->getzVector()
//              <<std::endl;
//    vector->plusxVector();
//    vector->plusyVector();
//    vector->pluszVector();
//    std::cout <<"더하기 후벡터 값"
//              <<vector->getxVector()<<" "
//              <<vector->getyVector()<<" "
//              <<vector->getzVector()
//              <<std::endl;
//    delete vector;
//
//    return 0;
//}

//using test = void*(*)(void*);
//
//int* plus(int* a) {
//    *a=9;
//    return a;
//}
//
//int main() {
//    test func;
//    int a=3;
//    plus(&a);
//    std::cout<<a;
//    func= plus;
//    func(&a);
//    return 0;
//}
//int plus(int *value) {
//    return (*value) + 1;
//}
//
//using FunctionPointer = void* (*)(void*);
//
//void* plusWrapper(void *arg) {
//    int *input = static_cast<int*>(arg);
//    int result = plus(input);
//
//    return new int(result);
//}
//
//void fp_test() {
//    FunctionPointer functionPtr = &plusWrapper;
//
//    int inputValue = 5;
//    void *result = functionPtr(&inputValue);
//
//    std::cout << "Result: " << *static_cast<int*>(result) << std::endl;
//
//    delete static_cast<int*>(result);
//}
//
//int main()
//{
//    fp_test();
//    return 0;
//}
int plus(int *value) {
    return (*value) + 1;
}

using FunctionPointer = void* (*)(void*);

void* plusWrapper(void *arg) {
    int *input = static_cast<int*>(arg);
    int result = plus(input);

    return new int(result);
}



int main()
{
    FunctionPointer functionPtr = &plusWrapper;

    int inputValue = 5;
    void *result = functionPtr(&inputValue);

    std::cout << "Result: " << *static_cast<int*>(result) << std::endl;

    delete static_cast<int*>(result);
    return 0;
}
//using test = void* (*)(void*);
//test func은 void* func(*)(void*);인게 맞나?
//phind 왈
//using test = void* (*)(void*);  void* func(*)(void*);와 void*(*func)(void*) 둘다 같다
//챗지피티 왜 따로 물어보니까 맞는 문법이 아니라고 하니
//void*(*func)(void*) 이게 유일하게 맞는걸로

//void* func(void*): 이것은 함수를 나타내는 문법이며, 직접적인 함수 선언 또는 정의입니다.
//void* (*func)(void*): 이것은 함수 포인터를 나타내는 문법이며, 함수 포인터를 선언하는 것



// 둘다 맞는 표현이나 void*(*func)(void*) 이렇게 써야겠다


//아니라면 void*(*func)(void*)만이 맞는 표현인가요?
//또 void형 포인터는 타입이 정해져있지 않기 때문에 다른 타입 포인터를 받을 수 있다고 해서 한번 시도해보고 싶었는데
//사진의 코드대로는 실행이 안되서 func=plus를 func=static_case<void*>(plus);로도 바꿔봤는데 되지 않아서 어떻게 해야 되는지 궁금합니다
//using namespace std std를 namespace로대체 namespace는 쓸게 없어서 std::cout을 cout으로 생략 할 수 있다라고 봐야겠다
//namespace MyNamespace1 {
//    void myFunction() {
//        std::cout << "Hello from MyNamespace1!" << std::endl;
//    }
//}
//int main() {
//    // Now you can directly use myFunction without specifying the namespace
//    myFunction();  // Calls the function from MyNamespace1
//
//    MyNamespace2::myFunction();  // Calls the function from MyNamespace2
//
//    return 0;
//}
//using namespace Mynamespace1을 쓰니 그냥 myFunction()으로 쓸 수 있다
//namespace MN1 = MyNamespace1; 로 이름을 변경하여 MN1::namespace1로 쓸 수도 있어보인다.


