#include "TestLock.h"
#include "mtc_log.h"


TestLock::TestLock() {}

void TestLock::callback() {
//    std::unique_lock<std::mutex> lck(mutex);
//    cond.notify_one();
    LOGD("callback");
    while (true) {
        LOGD("start sleep");
        sleep(8);
//        LOGD("notify");
//        isReady = 1;
//        cond.notify_one();
    }
}


void TestLock::initReveiver() {
    std::thread thd_serial(std::bind(&TestLock::callback, &(TestLock::getInstance())));
    thd_serial.detach();
}


void TestLock::notify() {
    LOGD("notify");
    cond.notify_one();
}


void swap(int &p1, int &p2) //此处函数的形参p1, p2都是引用
{
    int p;
    p = p1;
    p1 = p2;
    p2 = p;
}


void TestLock::testWaitLock() {


    std::unique_lock<std::mutex> lck(this->mutex);
    {
        LOGD("start testWaitLock");

  /*      if (this->cond.wait_for(lck, std::chrono::seconds(3600), [] {
            LOGD("time out1111");
            if (isReady == 1) {
                LOGD("return true");
                return true;
            } else {
                LOGD("return false");
                return false;
            }
        })) {
            LOGD("isReady:%d", isReady);
        } else {
            LOGD("isReady:%d", isReady);
        }*/


        if (this->cond.wait_for(lck, std::chrono::milliseconds(5000)) == std::cv_status::timeout) {
            LOGD("time out");
        }
        LOGD("had notified");
    }

}

TestLock &TestLock::getInstance() {
    static TestLock mtc;
    return mtc;
}


