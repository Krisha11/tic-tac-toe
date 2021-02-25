#ifndef TEST_HPP
#define TEST_HPP

#include "cstdio"

class Test {
protected:
    static int failedNum; // количество тестов, которые сломались
    static int totalNum;  // общее количество тестов
                                                                
    /** Проверяет условие на верность (expr). 
        Сообщает об результате пользователю, в случае неудачи подробно сообщает об источнике. */
    static void check(bool expr,/* const char *func, */const char  *filename, std::size_t lineNum); 

public:
    static void showFinalResult();
    
    /** Запускает все тесты в конкретном наборе тестов */
    virtual void runAllTests() = 0;

    // Можно добавлять методы при необходимости 
};


#endif
