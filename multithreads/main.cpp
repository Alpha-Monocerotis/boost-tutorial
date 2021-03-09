#include <iostream>
#include <string>
#include <fstream>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>

boost::mutex mut;

inline void love(std::string girl) {
    boost::lock_guard<boost::mutex> lock(mut);
    std::cout << "I Love " << girl << std::endl;
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cout << "File path required" << std::endl;
        return -1;
    }
    std::vector<std::string> girls;
    std::freopen(argv[1], "r", stdin);
    std::string girl;
    while(std::cin>> girl) {
        girls.push_back(girl);
    }
    int thread_num = girls.size();
    std::vector<boost::thread> threadPool(thread_num);
    for(int i=0;i<thread_num;i++) {
        threadPool[i] = boost::thread(love, girls[i]);
    }
    for(int i=0;i<thread_num;i++) {
        threadPool[i].join();
    }
    return 0;
}
