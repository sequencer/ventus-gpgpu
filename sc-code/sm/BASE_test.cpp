#include "BASE.h"
#include "BASE_sti.h"
#include <chrono>

int sc_main(int argc, char *argv[])
{
    BASE BASE_impl("BASE");
    BASE_sti BASE_sti_impl("BASE_STI");

    sc_clock clk("clk", PERIOD, SC_NS, 0.5, 0, SC_NS, false);
    sc_signal<bool> rst_n("rst_n");

    BASE_impl.clk(clk);
    BASE_impl.rst_n(rst_n);

    BASE_sti_impl.rst_n(rst_n);

    sc_trace_file *tf0 = sc_create_vcd_trace_file("BASE_wave_warp0");
    tf0->set_time_unit(1, SC_NS);
    sc_trace(tf0, clk, "Clk");
    sc_trace(tf0, rst_n, "Rst_n");
    sc_trace(tf0, BASE_impl.WARPS[0].jump, "jump");
    sc_trace(tf0, BASE_impl.WARPS[0].jump_addr, "jump_addr");
    sc_trace(tf0, BASE_impl.WARPS[0].branch_sig, "bramch_sig");
    sc_trace(tf0, BASE_impl.WARPS[0].fetch_valid, "fetch_valid");
    sc_trace(tf0, BASE_impl.WARPS[0].pc, "pc");
    sc_trace(tf0, BASE_impl.WARPS[0].fetch_ins, "fetch_ins");
    sc_trace(tf0, BASE_impl.WARPS[0].dispatch_warp_valid, "dispatch_warp_valid");
    sc_trace(tf0, BASE_impl.WARPS[0].ibuf_empty, "ibuf_empty");
    sc_trace(tf0, BASE_impl.WARPS[0].ibuf_swallow, "ibuf_swallow");
    sc_trace(tf0, BASE_impl.WARPS[0].ibuftop_ins, "ibuftop_ins");
    sc_trace(tf0, BASE_impl.WARPS[0].ififo_elem_num, "ififo_elem_num");
    sc_trace(tf0, BASE_impl.WARPS[0].wait_bran, "wait_bran");
    sc_trace(tf0, BASE_impl.WARPS[0].can_dispatch, "can_dispatch");
    sc_trace(tf0, BASE_impl.opc_full, "opc_full");
    sc_trace(tf0, BASE_impl.last_dispatch_warpid, "last_dispatch_warpid");
    sc_trace(tf0, BASE_impl.issue_ins, "issue_ins");
    sc_trace(tf0, BASE_impl.issueins_warpid, "issueins_warpid");
    sc_trace(tf0, BASE_impl.dispatch_valid, "dispatch_valid");
    sc_trace(tf0, BASE_impl.dispatch_ready, "dispatch_ready");
    sc_trace(tf0, BASE_impl.opcfifo_elem_num, "opcfifo_elem_num");
    sc_trace(tf0, BASE_impl.emit_ins, "emit_ins");
    sc_trace(tf0, BASE_impl.emitins_warpid, "emitins_warpid");
    sc_trace(tf0, BASE_impl.doemit, "doemit");
    sc_trace(tf0, BASE_impl.findemit, "findemit");
    sc_trace(tf0, BASE_impl.emit_idx, "emit_idx");
    sc_trace(tf0, BASE_impl.emito_salu, "emito_salu");
    sc_trace(tf0, BASE_impl.emito_valu, "emito_valu");
    sc_trace(tf0, BASE_impl.emito_vfpu, "emito_vfpu");
    sc_trace(tf0, BASE_impl.emito_lsu, "emito_lsu");
    sc_trace(tf0, BASE_impl.salu_ready, "salu_ready");
    sc_trace(tf0, BASE_impl.rss1_addr, "rss1_addr");
    sc_trace(tf0, BASE_impl.rss2_addr, "rss2_addr");
    sc_trace(tf0, BASE_impl.rss1_data, "rss1_data");
    sc_trace(tf0, BASE_impl.rss2_data, "rss2_data");
    sc_trace(tf0, BASE_impl.salufifo_empty, "salufifo_empty");
    sc_trace(tf0, BASE_impl.salutmp2, "salutmp2");
    sc_trace(tf0, BASE_impl.salutop_dat, "salutop_dat");
    sc_trace(tf0, BASE_impl.salufifo_elem_num, "salufifo_elem_num");
    sc_trace(tf0, BASE_impl.valu_ready, "valu_ready");
    sc_trace(tf0, BASE_impl.rsv1_addr, "rsv1_addr");
    sc_trace(tf0, BASE_impl.rsv2_addr, "rsv2_addr");
    sc_trace(tf0, BASE_impl.rsv1_data[0], "rsv1_data.data(0)");
    sc_trace(tf0, BASE_impl.rsv1_data[1], "rsv1_data.data(1)");
    sc_trace(tf0, BASE_impl.rsv1_data[2], "rsv1_data.data(2)");
    sc_trace(tf0, BASE_impl.rsv1_data[3], "rsv1_data.data(3)");
    sc_trace(tf0, BASE_impl.rsv1_data[4], "rsv1_data.data(4)");
    sc_trace(tf0, BASE_impl.rsv1_data[5], "rsv1_data.data(5)");
    sc_trace(tf0, BASE_impl.rsv1_data[6], "rsv1_data.data(6)");
    sc_trace(tf0, BASE_impl.rsv1_data[7], "rsv1_data.data(7)");
    sc_trace(tf0, BASE_impl.rsv2_data[0], "rsv2_data.data(0)");
    sc_trace(tf0, BASE_impl.rsv2_data[1], "rsv2_data.data(1)");
    sc_trace(tf0, BASE_impl.rsv2_data[2], "rsv2_data.data(2)");
    sc_trace(tf0, BASE_impl.rsv2_data[3], "rsv2_data.data(3)");
    sc_trace(tf0, BASE_impl.rsv2_data[4], "rsv2_data.data(4)");
    sc_trace(tf0, BASE_impl.rsv2_data[5], "rsv2_data.data(5)");
    sc_trace(tf0, BASE_impl.rsv2_data[6], "rsv2_data.data(6)");
    sc_trace(tf0, BASE_impl.rsv2_data[7], "rsv2_data.data(7)");
    sc_trace(tf0, BASE_impl.valufifo_empty, "valufifo_empty");
    sc_trace(tf0, BASE_impl.valutop_dat, "valutop_dat");
    sc_trace(tf0, BASE_impl.valufifo_elem_num, "valufifo_elem_num");
    sc_trace(tf0, BASE_impl.vfpu_ready, "vfpu_ready");
    sc_trace(tf0, BASE_impl.rsf1_addr, "rsf1_addr");
    sc_trace(tf0, BASE_impl.rsf2_addr, "rsf2_addr");
    sc_trace(tf0, BASE_impl.rsf1_data[0], "rsf1_data.data(0)");
    sc_trace(tf0, BASE_impl.rsf1_data[1], "rsf1_data.data(1)");
    sc_trace(tf0, BASE_impl.rsf1_data[2], "rsf1_data.data(2)");
    sc_trace(tf0, BASE_impl.rsf1_data[3], "rsf1_data.data(3)");
    sc_trace(tf0, BASE_impl.rsf1_data[4], "rsf1_data.data(4)");
    sc_trace(tf0, BASE_impl.rsf1_data[5], "rsf1_data.data(5)");
    sc_trace(tf0, BASE_impl.rsf1_data[6], "rsf1_data.data(6)");
    sc_trace(tf0, BASE_impl.rsf1_data[7], "rsf1_data.data(7)");
    sc_trace(tf0, BASE_impl.rsf2_data[0], "rsf2_data.data(0)");
    sc_trace(tf0, BASE_impl.rsf2_data[1], "rsf2_data.data(1)");
    sc_trace(tf0, BASE_impl.rsf2_data[2], "rsf2_data.data(2)");
    sc_trace(tf0, BASE_impl.rsf2_data[3], "rsf2_data.data(3)");
    sc_trace(tf0, BASE_impl.rsf2_data[4], "rsf2_data.data(4)");
    sc_trace(tf0, BASE_impl.rsf2_data[5], "rsf2_data.data(5)");
    sc_trace(tf0, BASE_impl.rsf2_data[6], "rsf2_data.data(6)");
    sc_trace(tf0, BASE_impl.rsf2_data[7], "rsf2_data.data(7)");
    sc_trace(tf0, BASE_impl.vfpufifo_empty, "vfpufifo_empty");
    sc_trace(tf0, BASE_impl.vfputop_dat, "vfputop_dat");
    sc_trace(tf0, BASE_impl.vfpufifo_elem_num, "vfpufifo_elem_num");
    sc_trace(tf0, BASE_impl.lsu_ready, "lsu_ready");
    sc_trace(tf0, BASE_impl.lsufifo_empty, "lsufifo_empty");
    sc_trace(tf0, BASE_impl.lsutop_dat, "lsutop_dat");
    sc_trace(tf0, BASE_impl.lsufifo_elem_num, "lsufifo_elem_num");
    sc_trace(tf0, BASE_impl.write_s, "write_s");
    sc_trace(tf0, BASE_impl.write_v, "write_v");
    sc_trace(tf0, BASE_impl.write_f, "write_f");
    sc_trace(tf0, BASE_impl.execpop_salu, "execpop_salu");
    sc_trace(tf0, BASE_impl.execpop_valu, "execpop_valu");
    sc_trace(tf0, BASE_impl.execpop_vfpu, "execpop_vfpu");
    sc_trace(tf0, BASE_impl.execpop_lsu, "execpop_lsu");
    sc_trace(tf0, BASE_impl.wb_ena, "wb_ena");
    sc_trace(tf0, BASE_impl.wb_ins, "wb_ins");
    sc_trace(tf0, BASE_impl.wb_warpid, "wb_warpid");
    for (int i = 0; i < 32; i++)
        sc_trace(tf0, BASE_impl.WARPS[0].s_regfile[i], "s_regfile.data(" + std::to_string(i) + ")");
    sc_trace(tf0, BASE_impl.WARPS[0].v_regfile[0][0], "v_regfile(0)(0)");
    sc_trace(tf0, BASE_impl.WARPS[0].v_regfile[1][0], "v_regfile(1)(0)");
    sc_trace(tf0, BASE_impl.WARPS[0].v_regfile[2][0], "v_regfile(2)(0)");
    sc_trace(tf0, BASE_impl.WARPS[0].v_regfile[3][0], "v_regfile(3)(0)");
    sc_trace(tf0, BASE_impl.WARPS[0].v_regfile[4][0], "v_regfile(4)(0)");
    sc_trace(tf0, BASE_impl.WARPS[0].v_regfile[5][0], "v_regfile(5)(0)");
    sc_trace(tf0, BASE_impl.WARPS[0].v_regfile[6][0], "v_regfile(6)(0)");
    sc_trace(tf0, BASE_impl.WARPS[0].v_regfile[7][0], "v_regfile(7)(0)");
    sc_trace(tf0, BASE_impl.external_mem[0], "external_mem.data(0)");
    // sc_trace(tf0, BASE_impl., "");

    sc_trace_file *tf1 = sc_create_vcd_trace_file("BASE_wave_warp1");
    tf1->set_time_unit(1, SC_NS);

    auto start = std::chrono::high_resolution_clock::now();
    sc_start(10000, SC_NS);

    sc_close_vcd_trace_file(tf0);
    sc_close_vcd_trace_file(tf1);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time taken: " << duration.count()/1000 << " milliseconds" << std::endl;

    return 0;
}