#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>

void get_cpuinfo(uint64_t fields[]) {
    char line[3];
    std::ifstream in("/proc/stat", std::ios_base::in);
    in >> line;
    if (in.is_open()) {
        for (int i = 0; i < 10; ++i) {
            in >> fields[i];
        }
    }
}

int main() {
    uint64_t fields[10], total_tick, total_tick_old, idle, idle_old, del_total_tick, del_idle;
    double percent_usage;
    get_cpuinfo(fields);
    total_tick = 0;
    for (int i = 0; i < 10; i++) {
        total_tick += fields[i];
    }
    idle = fields[3];
    while (true) {
        std::chrono::milliseconds sleep_time(1000);
        std::this_thread::sleep_for(sleep_time);
        total_tick_old = total_tick;
        idle_old = idle;
        get_cpuinfo(fields);
        total_tick = 0;
        for (int i = 0; i < 10; i++) {
            total_tick += fields[i];
        }
        idle = fields[3];
        del_total_tick = total_tick - total_tick_old;
        del_idle = idle - idle_old;
        percent_usage = ((del_total_tick - del_idle) / static_cast<double>(del_total_tick)) * 100;
        std::cout << "Total CPU Usage: "<< percent_usage << std::endl;
    }
  return 0;
}
