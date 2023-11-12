class Test {
    chrono::time_point<std::chrono::system_clock> tstart, tend;
    public:
    Test() {tstart = chrono::system_clock::now(); f();}
    void f() {} // Test function to chronometer.
    ~Test() {
        tend = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = tend - tstart;
        time_t end_time = chrono::system_clock::to_time_t(tend);
        cout << "Finished test at: " << ctime(&end_time) << "Elapsed time: " << elapsed_seconds.count() << "s\n";
    }
};

