#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <string>
#include <iostream>
#include <functional>
#include <stdexcept>


class ThreadPool {
public:
    ThreadPool(size_t);
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args)
    -> std::future<typename std::result_of<F(Args...)>::type>;
    ~ThreadPool();
private:
    // �̳߳�
    std::vector< std::thread > workers;
    // �������
    std::queue< std::function<void()> > tasks;

    // synchronizationͬ��
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads)
        :   stop(false)
{
    //����n���̣߳�ÿ���̵߳ȴ��Ƿ����µ�task, �����߳�stop��Ҫ��ֹ��
    for(size_t i = 0;i<threads;++i)
        workers.emplace_back(
                [this]
                {
                    for(;;)//��ѯ
                    {
                        std::function<void()> task;

                        {
                            //��ȡͬ����
                            std::unique_lock<std::mutex> lock(this->queue_mutex);
                            //�̻߳�һֱ������ֱ�����µ�task���������߳�Ҫ�˳�
                            this->condition.wait(lock,
                                                 [this]{ return this->stop || !this->tasks.empty(); });
                            //�߳��˳�
                            if(this->stop && this->tasks.empty())
                                return;
                            //��taskȡ��
                            task = std::move(this->tasks.front());
                            //�������Ƴ��Լ�ȡ����task
                            this->tasks.pop();
                        }
                        //ִ��task,�����������һ��ѭ��
                        task();
                    }
                }
        );
}

// add new work item to the pool
// ������ѹ���̳߳�,����f��Ҫִ�еĺ����� args�Ƕ��еĲ���
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args)
-> std::future<typename std::result_of<F(Args...)>::type>
{
    //���صĽ�������ͣ���Ȼ���Ը���ʵ�ʵ���Ҫȥ�����(gcc4.7��c++11��֧��)
    using return_type = typename std::result_of<F(Args...)>::type;
//������handle�������
    auto task = std::make_shared< std::packaged_task<return_type()> >(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );

    //after finishing the task, then get result by res.get() (mainly used in the invoked function)
    std::future<return_type> res = task->get_future();
    {
        //ѹ�������Ҫ�̰߳�ȫ�������Ҫ�Ȼ�ȡ��
        std::unique_lock<std::mutex> lock(queue_mutex);

        // don't allow enqueueing after stopping the pool
        if(stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");
        //����ѹ�����
        tasks.emplace([task](){ (*task)(); });
    }
    //������µ�task�������������֪ͨ�����߳̿��Ի�ȡtaskִ��
    condition.notify_one();
    return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();//֪ͨ�����ڵȴ������߳�
    //�ȴ����е��߳�����ִ������˳�
    for(std::thread &worker: workers)
        worker.join();
};

//�̳߳�Ҫִ�е�����

//ģ�����أ�sleep 2S
void dummy_download(std::string url){
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout<<" complete download: "<<url<<std::endl;
}

//����id�����û���
std::string get_user_name(int id){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return "user_" + std::to_string(id);
}


int main(){

    ThreadPool tp(5);

    //�߳�ִ�н���ķ���
    std::vector<std::future<std::string>> vecStr;
    // ���ض�Ӧ��url���ӣ�û�з���ֵ
    tp.enqueue(dummy_download, "www.baidu.jpg");
    tp.enqueue(dummy_download, "www.yy.jpg");

    //���ݿ����id��ѯuser name
    vecStr.emplace_back(tp.enqueue(get_user_name, 101));
    vecStr.emplace_back(tp.enqueue(get_user_name, 102));

    //����̷߳��ص�ֵ��ʵ���п��Բ�Ҫ
    std::future<void> res1 = std::async(std::launch::async, [&vecStr](){
        for (auto &&ret:vecStr) {
            std::cout<<"get user: "<<ret.get();
        }
        std::cout<<std::endl;
    });

    return 0;
}
