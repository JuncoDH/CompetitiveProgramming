#include <chrono>
chrono::time_point<std::chrono::system_clock> tstart, tend;

void chronoIni(){	
    tstart = chrono::system_clock::now();
}

void chronoFin(){
    tend = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = tend - tstart;
    time_t end_time = chrono::system_clock::to_time_t(tend);

    cout << "finished computation at " << ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";

}

//chronoIni(); test1(); chronoFin();
