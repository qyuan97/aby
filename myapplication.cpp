#include <cstdint>
#include <vector>
#include "string.h"
#include "circuit/booleancircuits.h"
#include "aby/abyparty.h"

int main(){
    std::string address = "127.0.0.1";
    uint16_t port = 6677;
    seclvl seclvl = get_sec_lvl(128);
    e_sharing sharing = S_YAO;
    uint32_t bitlen = 32;
    uint32_t nthreads = 1;

    ABYParty* party = new ABYParty(role, (char*) address.c_str(), port, seclvl, bitlen, nthreads);
    vector<Sharing*>& sharings = party->GetSharings();
    Circuit* circ = sharings[sharing]-> GetCircuitBuildRoutine();

    uint32_t alice_money = 6;
    uint32_t bob_money = 7;
    uint32_t money_bitlen = 3;

    return 0;
}