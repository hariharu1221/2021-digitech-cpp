#pragma once
#include <chrono>

template<typename T>
class cTimer
{
private:
    bool is_start;
    std::chrono::system_clock::time_point start_point;
    T total_time;

public:
    cTimer(bool _start = false)
        :is_start(_start), total_time()
    {
        if (is_start)
            start_point = std::chrono::system_clock::now();
    }

    /**
    * @brief    누적시간을 0으로 초기화 하면서 실행
    * @return   이미 실행중인 타이머일경우 false, 지금 실행에 성공했으면 true
    */
    bool Play()
    {
        if (is_start)
            return false;
        is_start = true;
        total_time = 0;
        start_point = std::chrono::system_clock::now();
        return true;
    }

    /**
    * @brief    누적시간을 초기화하지 않고 실행
    * @return   이미 실행중인 타이머일경우 false, 지금 실행에 성공했으면 true
    */
    bool Resume()
    {
        if (is_start)
            return false;
        is_start = true;
        start_point = std::chrono::system_clock::now();
        return true;
    }

    /**
    * @brief    타이머를 일시정지 시킴
    * @return   타이머의 누적 시간
    */
    T Pause()
    {
        if (is_start)
        {
            std::chrono::duration<T> result = std::chrono::system_clock::now() - start_point;
            total_time = result.count();
            is_start = false;
        }
        return total_time;
    }

    operator T()
    {
        std::chrono::duration<T> result = std::chrono::system_clock::now() - start_point;
        return result.count() + total_time;
    }
};

