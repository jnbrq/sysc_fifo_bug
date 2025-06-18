#include <iostream>
#include <systemc>

using namespace sc_core;
using namespace sc_dt;

struct Module : public sc_module {
    Module(sc_module_name const& name = "")
        : sc_module(name)
        , SC_NAMED(fifo) {
        SC_THREAD(produce);
        SC_THREAD(consume);
    }

private:
    sc_fifo<sc_bv_base> fifo;

    void print(sc_bv_base const& bv) {
        std::cout << "length: " << bv.length() << ", value: " << std::hex << "0x" << bv.to_uint64() << std::dec << "\n";
    }

    void produce() {
        fifo.write(sc_bv<32>(0xDEAD'BEEF));
        fifo.write(sc_bv<64>(0xDEAD'BEEF'DEAD'BEEFull));
        fifo.write(sc_bv_base(48));
        fifo.write(sc_bv_base(16));
    }

    void consume() {
        print(fifo.read());
        print(fifo.read());
        print(fifo.read());
        print(fifo.read());
    }
};

int sc_main(int, char**) {
    Module m;
    sc_start(100, SC_NS);
    return 0;
}
