
#include <iostream>
#include "vector"
#include "thread"
#include "Rastreador.h"
#include "Seed.h"


void startSimuladorDeRede(){

}

void startRastreador(int portaRastreador) {
    Rastreador rastreador(portaRastreador);
}

void startSeed(int porta){

    Seed s(porta);
};

void startSeeds(std::thread threads_seeds[],int portaBase) {

    for (int i = 1; i <=4; ++i) {
        threads_seeds[i]=std::thread(startSeed,portaBase+i);
    }
}

void startLeecher(int porta ){
 Leecher l(porta);

}


int main() {
    std::thread threads_seeds[5];
    std::thread thread_leecher;
    std::thread thread_rastreador(startRastreador, 8080);
    sleep(2);
    startSeeds(threads_seeds,8080);
    sleep(2);
    thread_leecher=std::thread(startLeecher,8010);

    thread_rastreador.join();
    for (int i = 1; i <=4; ++i) {
        threads_seeds[i].join();
    }
    thread_leecher.join();

    return 0;
}