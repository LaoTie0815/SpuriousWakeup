#ifndef MTC_H
#define MTC_H

#include <thread>

//static void *callback(void *data);

static int isReady = 0;

class TestLock
{
private:
    TestLock();
    TestLock(const TestLock& other);
    TestLock & operator=(const TestLock & other);
//    static TestLock *m_Instace;

    volatile char uploadAiInfoMode = 0x00;
    volatile char rgbHeadImg = 0x00;
    volatile char rgbBgImg = 0x00;
    volatile char irImg = 0x00;
    volatile char m_is_frame_ai_info = 0x00;

    int initSerial(int fd,int busNum,int devNum);

    void destroySerial() noexcept;
    void processSerialThread();
    void processJniCallbackThread();






public:
    /*** JNI ***/

    pthread_mutex_t pthread_mutex;
    pthread_cond_t pthread_cond;
    pthread_t product;

    static TestLock &getInstance();

    void destroy();
    void initReveiver();
    int init(int fd,int busNum,int devNum);
    void testWaitLock();
    void notify();
    void callback();

    std::mutex mutex;
    std::condition_variable cond;
};

#endif // MTC_H
