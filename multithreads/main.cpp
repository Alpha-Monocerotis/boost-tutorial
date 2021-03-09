#include <iostream>
#include <string>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>

using namespace std;

boost::mutex mut;

inline void love(string girl) {
    boost::lock_guard<boost::mutex> lock(mut);
    cout << "I Love " << girl << endl;
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        cout << "File path required" << endl;
        return -1;
    }
    vector<string> girls;
    freopen(argv[1], "r", stdin);
    string girl;
    while(cin>> girl) {
        girls.push_back(girl);
    }
    int thread_num = girls.size();
    vector<boost::thread> threadPool(thread_num);
    for(int i=0;i<thread_num;i++) {
        threadPool[i] = boost::thread(love, girls[i]);
    }
    for(int i=0;i<thread_num;i++) {
        threadPool[i].join();
    }
    return 0;
}
