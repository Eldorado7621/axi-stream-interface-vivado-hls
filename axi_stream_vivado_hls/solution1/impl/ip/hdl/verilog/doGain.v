// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Version: 2021.2
// Copyright (C) Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="doGain_doGain,hls_ip_2021_2,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7z010-clg400-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=6.912000,HLS_SYN_LAT=1004,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=733,HLS_SYN_LUT=445,HLS_VERSION=2021_2}" *)

module doGain (
        ap_local_block,
        ap_clk,
        ap_rst_n,
        inStream_TDATA,
        inStream_TVALID,
        inStream_TREADY,
        inStream_TKEEP,
        inStream_TSTRB,
        inStream_TUSER,
        inStream_TLAST,
        inStream_TID,
        inStream_TDEST,
        outStream_TDATA,
        outStream_TVALID,
        outStream_TREADY,
        outStream_TKEEP,
        outStream_TSTRB,
        outStream_TUSER,
        outStream_TLAST,
        outStream_TID,
        outStream_TDEST,
        s_axi_CRTL_BUS_AWVALID,
        s_axi_CRTL_BUS_AWREADY,
        s_axi_CRTL_BUS_AWADDR,
        s_axi_CRTL_BUS_WVALID,
        s_axi_CRTL_BUS_WREADY,
        s_axi_CRTL_BUS_WDATA,
        s_axi_CRTL_BUS_WSTRB,
        s_axi_CRTL_BUS_ARVALID,
        s_axi_CRTL_BUS_ARREADY,
        s_axi_CRTL_BUS_ARADDR,
        s_axi_CRTL_BUS_RVALID,
        s_axi_CRTL_BUS_RREADY,
        s_axi_CRTL_BUS_RDATA,
        s_axi_CRTL_BUS_RRESP,
        s_axi_CRTL_BUS_BVALID,
        s_axi_CRTL_BUS_BREADY,
        s_axi_CRTL_BUS_BRESP,
        interrupt
);

parameter    ap_ST_fsm_state1 = 3'd1;
parameter    ap_ST_fsm_pp0_stage0 = 3'd2;
parameter    ap_ST_fsm_state6 = 3'd4;
parameter    C_S_AXI_CRTL_BUS_DATA_WIDTH = 32;
parameter    C_S_AXI_CRTL_BUS_ADDR_WIDTH = 5;
parameter    C_S_AXI_DATA_WIDTH = 32;

parameter C_S_AXI_CRTL_BUS_WSTRB_WIDTH = (32 / 8);
parameter C_S_AXI_WSTRB_WIDTH = (32 / 8);

output   ap_local_block;
input   ap_clk;
input   ap_rst_n;
input  [31:0] inStream_TDATA;
input   inStream_TVALID;
output   inStream_TREADY;
input  [3:0] inStream_TKEEP;
input  [3:0] inStream_TSTRB;
input  [1:0] inStream_TUSER;
input  [0:0] inStream_TLAST;
input  [4:0] inStream_TID;
input  [5:0] inStream_TDEST;
output  [31:0] outStream_TDATA;
output   outStream_TVALID;
input   outStream_TREADY;
output  [3:0] outStream_TKEEP;
output  [3:0] outStream_TSTRB;
output  [1:0] outStream_TUSER;
output  [0:0] outStream_TLAST;
output  [4:0] outStream_TID;
output  [5:0] outStream_TDEST;
input   s_axi_CRTL_BUS_AWVALID;
output   s_axi_CRTL_BUS_AWREADY;
input  [C_S_AXI_CRTL_BUS_ADDR_WIDTH - 1:0] s_axi_CRTL_BUS_AWADDR;
input   s_axi_CRTL_BUS_WVALID;
output   s_axi_CRTL_BUS_WREADY;
input  [C_S_AXI_CRTL_BUS_DATA_WIDTH - 1:0] s_axi_CRTL_BUS_WDATA;
input  [C_S_AXI_CRTL_BUS_WSTRB_WIDTH - 1:0] s_axi_CRTL_BUS_WSTRB;
input   s_axi_CRTL_BUS_ARVALID;
output   s_axi_CRTL_BUS_ARREADY;
input  [C_S_AXI_CRTL_BUS_ADDR_WIDTH - 1:0] s_axi_CRTL_BUS_ARADDR;
output   s_axi_CRTL_BUS_RVALID;
input   s_axi_CRTL_BUS_RREADY;
output  [C_S_AXI_CRTL_BUS_DATA_WIDTH - 1:0] s_axi_CRTL_BUS_RDATA;
output  [1:0] s_axi_CRTL_BUS_RRESP;
output   s_axi_CRTL_BUS_BVALID;
input   s_axi_CRTL_BUS_BREADY;
output  [1:0] s_axi_CRTL_BUS_BRESP;
output   interrupt;

wire   [0:0] ap_local_deadlock;
 reg    ap_rst_n_inv;
wire    ap_start;
reg    ap_done;
reg    ap_idle;
(* fsm_encoding = "none" *) reg   [2:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    ap_ready;
wire   [31:0] gain;
reg    inStream_TDATA_blk_n;
wire    ap_CS_fsm_pp0_stage0;
reg    ap_enable_reg_pp0_iter0;
wire    ap_block_pp0_stage0;
wire   [0:0] icmp_ln14_fu_141_p2;
reg    outStream_TDATA_blk_n;
reg    ap_enable_reg_pp0_iter2;
reg    ap_enable_reg_pp0_iter3;
reg  signed [31:0] gain_read_reg_198;
reg  signed [31:0] tmp_data_V_reg_206;
reg    ap_block_state2_pp0_stage0_iter0;
wire    ap_block_state3_pp0_stage0_iter1;
reg    ap_block_state4_pp0_stage0_iter2;
reg    ap_block_state5_pp0_stage0_iter3;
reg    ap_block_pp0_stage0_11001;
reg   [3:0] tmp_keep_V_reg_211;
reg   [3:0] tmp_keep_V_reg_211_pp0_iter1_reg;
reg   [3:0] tmp_strb_V_reg_216;
reg   [3:0] tmp_strb_V_reg_216_pp0_iter1_reg;
reg   [1:0] tmp_user_V_reg_221;
reg   [1:0] tmp_user_V_reg_221_pp0_iter1_reg;
reg   [0:0] tmp_last_V_reg_226;
reg   [0:0] tmp_last_V_reg_226_pp0_iter1_reg;
reg   [4:0] tmp_id_V_reg_231;
reg   [4:0] tmp_id_V_reg_231_pp0_iter1_reg;
reg   [5:0] tmp_dest_V_reg_236;
reg   [5:0] tmp_dest_V_reg_236_pp0_iter1_reg;
wire   [31:0] grp_fu_186_p2;
reg    ap_block_pp0_stage0_subdone;
reg    ap_condition_pp0_exit_iter0_state2;
reg    ap_enable_reg_pp0_iter1;
reg   [9:0] idx_fu_80;
wire   [9:0] idx_2_fu_147_p2;
reg    ap_block_pp0_stage0_01001;
reg    grp_fu_186_ce;
wire    ap_CS_fsm_state6;
wire    regslice_both_outStream_V_data_V_U_apdone_blk;
reg   [2:0] ap_NS_fsm;
reg    ap_ST_fsm_state1_blk;
reg    ap_ST_fsm_state6_blk;
reg    ap_idle_pp0;
wire    ap_enable_pp0;
wire    regslice_both_inStream_V_data_V_U_apdone_blk;
wire   [31:0] inStream_TDATA_int_regslice;
wire    inStream_TVALID_int_regslice;
reg    inStream_TREADY_int_regslice;
wire    regslice_both_inStream_V_data_V_U_ack_in;
wire    regslice_both_inStream_V_keep_V_U_apdone_blk;
wire   [3:0] inStream_TKEEP_int_regslice;
wire    regslice_both_inStream_V_keep_V_U_vld_out;
wire    regslice_both_inStream_V_keep_V_U_ack_in;
wire    regslice_both_inStream_V_strb_V_U_apdone_blk;
wire   [3:0] inStream_TSTRB_int_regslice;
wire    regslice_both_inStream_V_strb_V_U_vld_out;
wire    regslice_both_inStream_V_strb_V_U_ack_in;
wire    regslice_both_inStream_V_user_V_U_apdone_blk;
wire   [1:0] inStream_TUSER_int_regslice;
wire    regslice_both_inStream_V_user_V_U_vld_out;
wire    regslice_both_inStream_V_user_V_U_ack_in;
wire    regslice_both_inStream_V_last_V_U_apdone_blk;
wire   [0:0] inStream_TLAST_int_regslice;
wire    regslice_both_inStream_V_last_V_U_vld_out;
wire    regslice_both_inStream_V_last_V_U_ack_in;
wire    regslice_both_inStream_V_id_V_U_apdone_blk;
wire   [4:0] inStream_TID_int_regslice;
wire    regslice_both_inStream_V_id_V_U_vld_out;
wire    regslice_both_inStream_V_id_V_U_ack_in;
wire    regslice_both_inStream_V_dest_V_U_apdone_blk;
wire   [5:0] inStream_TDEST_int_regslice;
wire    regslice_both_inStream_V_dest_V_U_vld_out;
wire    regslice_both_inStream_V_dest_V_U_ack_in;
reg    outStream_TVALID_int_regslice;
wire    outStream_TREADY_int_regslice;
wire    regslice_both_outStream_V_data_V_U_vld_out;
wire    regslice_both_outStream_V_keep_V_U_apdone_blk;
wire    regslice_both_outStream_V_keep_V_U_ack_in_dummy;
wire    regslice_both_outStream_V_keep_V_U_vld_out;
wire    regslice_both_outStream_V_strb_V_U_apdone_blk;
wire    regslice_both_outStream_V_strb_V_U_ack_in_dummy;
wire    regslice_both_outStream_V_strb_V_U_vld_out;
wire    regslice_both_outStream_V_user_V_U_apdone_blk;
wire    regslice_both_outStream_V_user_V_U_ack_in_dummy;
wire    regslice_both_outStream_V_user_V_U_vld_out;
wire    regslice_both_outStream_V_last_V_U_apdone_blk;
wire    regslice_both_outStream_V_last_V_U_ack_in_dummy;
wire    regslice_both_outStream_V_last_V_U_vld_out;
wire    regslice_both_outStream_V_id_V_U_apdone_blk;
wire    regslice_both_outStream_V_id_V_U_ack_in_dummy;
wire    regslice_both_outStream_V_id_V_U_vld_out;
wire    regslice_both_outStream_V_dest_V_U_apdone_blk;
wire    regslice_both_outStream_V_dest_V_U_ack_in_dummy;
wire    regslice_both_outStream_V_dest_V_U_vld_out;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 3'd1;
#0 ap_enable_reg_pp0_iter0 = 1'b0;
#0 ap_enable_reg_pp0_iter2 = 1'b0;
#0 ap_enable_reg_pp0_iter3 = 1'b0;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
end

doGain_CRTL_BUS_s_axi #(
    .C_S_AXI_ADDR_WIDTH( C_S_AXI_CRTL_BUS_ADDR_WIDTH ),
    .C_S_AXI_DATA_WIDTH( C_S_AXI_CRTL_BUS_DATA_WIDTH ))
CRTL_BUS_s_axi_U(
    .AWVALID(s_axi_CRTL_BUS_AWVALID),
    .AWREADY(s_axi_CRTL_BUS_AWREADY),
    .AWADDR(s_axi_CRTL_BUS_AWADDR),
    .WVALID(s_axi_CRTL_BUS_WVALID),
    .WREADY(s_axi_CRTL_BUS_WREADY),
    .WDATA(s_axi_CRTL_BUS_WDATA),
    .WSTRB(s_axi_CRTL_BUS_WSTRB),
    .ARVALID(s_axi_CRTL_BUS_ARVALID),
    .ARREADY(s_axi_CRTL_BUS_ARREADY),
    .ARADDR(s_axi_CRTL_BUS_ARADDR),
    .RVALID(s_axi_CRTL_BUS_RVALID),
    .RREADY(s_axi_CRTL_BUS_RREADY),
    .RDATA(s_axi_CRTL_BUS_RDATA),
    .RRESP(s_axi_CRTL_BUS_RRESP),
    .BVALID(s_axi_CRTL_BUS_BVALID),
    .BREADY(s_axi_CRTL_BUS_BREADY),
    .BRESP(s_axi_CRTL_BUS_BRESP),
    .ACLK(ap_clk),
    .ARESET(ap_rst_n_inv),
    .ACLK_EN(1'b1),
    .gain(gain),
    .ap_start(ap_start),
    .interrupt(interrupt),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_idle(ap_idle),
    .ap_local_deadlock(ap_local_deadlock)
);

doGain_mul_32s_32s_32_2_1 #(
    .ID( 1 ),
    .NUM_STAGE( 2 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
mul_32s_32s_32_2_1_U1(
    .clk(ap_clk),
    .reset(ap_rst_n_inv),
    .din0(tmp_data_V_reg_206),
    .din1(gain_read_reg_198),
    .ce(grp_fu_186_ce),
    .dout(grp_fu_186_p2)
);

doGain_regslice_both #(
    .DataWidth( 32 ))
regslice_both_inStream_V_data_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(inStream_TDATA),
    .vld_in(inStream_TVALID),
    .ack_in(regslice_both_inStream_V_data_V_U_ack_in),
    .data_out(inStream_TDATA_int_regslice),
    .vld_out(inStream_TVALID_int_regslice),
    .ack_out(inStream_TREADY_int_regslice),
    .apdone_blk(regslice_both_inStream_V_data_V_U_apdone_blk)
);

doGain_regslice_both #(
    .DataWidth( 4 ))
regslice_both_inStream_V_keep_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(inStream_TKEEP),
    .vld_in(inStream_TVALID),
    .ack_in(regslice_both_inStream_V_keep_V_U_ack_in),
    .data_out(inStream_TKEEP_int_regslice),
    .vld_out(regslice_both_inStream_V_keep_V_U_vld_out),
    .ack_out(inStream_TREADY_int_regslice),
    .apdone_blk(regslice_both_inStream_V_keep_V_U_apdone_blk)
);

doGain_regslice_both #(
    .DataWidth( 4 ))
regslice_both_inStream_V_strb_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(inStream_TSTRB),
    .vld_in(inStream_TVALID),
    .ack_in(regslice_both_inStream_V_strb_V_U_ack_in),
    .data_out(inStream_TSTRB_int_regslice),
    .vld_out(regslice_both_inStream_V_strb_V_U_vld_out),
    .ack_out(inStream_TREADY_int_regslice),
    .apdone_blk(regslice_both_inStream_V_strb_V_U_apdone_blk)
);

doGain_regslice_both #(
    .DataWidth( 2 ))
regslice_both_inStream_V_user_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(inStream_TUSER),
    .vld_in(inStream_TVALID),
    .ack_in(regslice_both_inStream_V_user_V_U_ack_in),
    .data_out(inStream_TUSER_int_regslice),
    .vld_out(regslice_both_inStream_V_user_V_U_vld_out),
    .ack_out(inStream_TREADY_int_regslice),
    .apdone_blk(regslice_both_inStream_V_user_V_U_apdone_blk)
);

doGain_regslice_both #(
    .DataWidth( 1 ))
regslice_both_inStream_V_last_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(inStream_TLAST),
    .vld_in(inStream_TVALID),
    .ack_in(regslice_both_inStream_V_last_V_U_ack_in),
    .data_out(inStream_TLAST_int_regslice),
    .vld_out(regslice_both_inStream_V_last_V_U_vld_out),
    .ack_out(inStream_TREADY_int_regslice),
    .apdone_blk(regslice_both_inStream_V_last_V_U_apdone_blk)
);

doGain_regslice_both #(
    .DataWidth( 5 ))
regslice_both_inStream_V_id_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(inStream_TID),
    .vld_in(inStream_TVALID),
    .ack_in(regslice_both_inStream_V_id_V_U_ack_in),
    .data_out(inStream_TID_int_regslice),
    .vld_out(regslice_both_inStream_V_id_V_U_vld_out),
    .ack_out(inStream_TREADY_int_regslice),
    .apdone_blk(regslice_both_inStream_V_id_V_U_apdone_blk)
);

doGain_regslice_both #(
    .DataWidth( 6 ))
regslice_both_inStream_V_dest_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(inStream_TDEST),
    .vld_in(inStream_TVALID),
    .ack_in(regslice_both_inStream_V_dest_V_U_ack_in),
    .data_out(inStream_TDEST_int_regslice),
    .vld_out(regslice_both_inStream_V_dest_V_U_vld_out),
    .ack_out(inStream_TREADY_int_regslice),
    .apdone_blk(regslice_both_inStream_V_dest_V_U_apdone_blk)
);

doGain_regslice_both #(
    .DataWidth( 32 ))
regslice_both_outStream_V_data_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(grp_fu_186_p2),
    .vld_in(outStream_TVALID_int_regslice),
    .ack_in(outStream_TREADY_int_regslice),
    .data_out(outStream_TDATA),
    .vld_out(regslice_both_outStream_V_data_V_U_vld_out),
    .ack_out(outStream_TREADY),
    .apdone_blk(regslice_both_outStream_V_data_V_U_apdone_blk)
);

doGain_regslice_both #(
    .DataWidth( 4 ))
regslice_both_outStream_V_keep_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(tmp_keep_V_reg_211_pp0_iter1_reg),
    .vld_in(outStream_TVALID_int_regslice),
    .ack_in(regslice_both_outStream_V_keep_V_U_ack_in_dummy),
    .data_out(outStream_TKEEP),
    .vld_out(regslice_both_outStream_V_keep_V_U_vld_out),
    .ack_out(outStream_TREADY),
    .apdone_blk(regslice_both_outStream_V_keep_V_U_apdone_blk)
);

doGain_regslice_both #(
    .DataWidth( 4 ))
regslice_both_outStream_V_strb_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(tmp_strb_V_reg_216_pp0_iter1_reg),
    .vld_in(outStream_TVALID_int_regslice),
    .ack_in(regslice_both_outStream_V_strb_V_U_ack_in_dummy),
    .data_out(outStream_TSTRB),
    .vld_out(regslice_both_outStream_V_strb_V_U_vld_out),
    .ack_out(outStream_TREADY),
    .apdone_blk(regslice_both_outStream_V_strb_V_U_apdone_blk)
);

doGain_regslice_both #(
    .DataWidth( 2 ))
regslice_both_outStream_V_user_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(tmp_user_V_reg_221_pp0_iter1_reg),
    .vld_in(outStream_TVALID_int_regslice),
    .ack_in(regslice_both_outStream_V_user_V_U_ack_in_dummy),
    .data_out(outStream_TUSER),
    .vld_out(regslice_both_outStream_V_user_V_U_vld_out),
    .ack_out(outStream_TREADY),
    .apdone_blk(regslice_both_outStream_V_user_V_U_apdone_blk)
);

doGain_regslice_both #(
    .DataWidth( 1 ))
regslice_both_outStream_V_last_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(tmp_last_V_reg_226_pp0_iter1_reg),
    .vld_in(outStream_TVALID_int_regslice),
    .ack_in(regslice_both_outStream_V_last_V_U_ack_in_dummy),
    .data_out(outStream_TLAST),
    .vld_out(regslice_both_outStream_V_last_V_U_vld_out),
    .ack_out(outStream_TREADY),
    .apdone_blk(regslice_both_outStream_V_last_V_U_apdone_blk)
);

doGain_regslice_both #(
    .DataWidth( 5 ))
regslice_both_outStream_V_id_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(tmp_id_V_reg_231_pp0_iter1_reg),
    .vld_in(outStream_TVALID_int_regslice),
    .ack_in(regslice_both_outStream_V_id_V_U_ack_in_dummy),
    .data_out(outStream_TID),
    .vld_out(regslice_both_outStream_V_id_V_U_vld_out),
    .ack_out(outStream_TREADY),
    .apdone_blk(regslice_both_outStream_V_id_V_U_apdone_blk)
);

doGain_regslice_both #(
    .DataWidth( 6 ))
regslice_both_outStream_V_dest_V_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .data_in(tmp_dest_V_reg_236_pp0_iter1_reg),
    .vld_in(outStream_TVALID_int_regslice),
    .ack_in(regslice_both_outStream_V_dest_V_U_ack_in_dummy),
    .data_out(outStream_TDEST),
    .vld_out(regslice_both_outStream_V_dest_V_U_vld_out),
    .ack_out(outStream_TREADY),
    .apdone_blk(regslice_both_outStream_V_dest_V_U_apdone_blk)
);

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_enable_reg_pp0_iter0 <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b1 == ap_condition_pp0_exit_iter0_state2) & (1'b0 == ap_block_pp0_stage0_subdone))) begin
            ap_enable_reg_pp0_iter0 <= 1'b0;
        end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
            ap_enable_reg_pp0_iter0 <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if ((1'b0 == ap_block_pp0_stage0_subdone)) begin
            if ((1'b1 == ap_condition_pp0_exit_iter0_state2)) begin
                ap_enable_reg_pp0_iter1 <= (1'b1 ^ ap_condition_pp0_exit_iter0_state2);
            end else if ((1'b1 == 1'b1)) begin
                ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
            end
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_enable_reg_pp0_iter2 <= 1'b0;
    end else begin
        if ((1'b0 == ap_block_pp0_stage0_subdone)) begin
            ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_enable_reg_pp0_iter3 <= 1'b0;
    end else begin
        if ((1'b0 == ap_block_pp0_stage0_subdone)) begin
            ap_enable_reg_pp0_iter3 <= ap_enable_reg_pp0_iter2;
        end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
            ap_enable_reg_pp0_iter3 <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        idx_fu_80 <= 10'd0;
    end else if (((icmp_ln14_fu_141_p2 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        idx_fu_80 <= idx_2_fu_147_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state1)) begin
        gain_read_reg_198 <= gain;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln14_fu_141_p2 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        tmp_data_V_reg_206 <= inStream_TDATA_int_regslice;
        tmp_dest_V_reg_236 <= inStream_TDEST_int_regslice;
        tmp_id_V_reg_231 <= inStream_TID_int_regslice;
        tmp_keep_V_reg_211 <= inStream_TKEEP_int_regslice;
        tmp_last_V_reg_226 <= inStream_TLAST_int_regslice;
        tmp_strb_V_reg_216 <= inStream_TSTRB_int_regslice;
        tmp_user_V_reg_221 <= inStream_TUSER_int_regslice;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        tmp_dest_V_reg_236_pp0_iter1_reg <= tmp_dest_V_reg_236;
        tmp_id_V_reg_231_pp0_iter1_reg <= tmp_id_V_reg_231;
        tmp_keep_V_reg_211_pp0_iter1_reg <= tmp_keep_V_reg_211;
        tmp_last_V_reg_226_pp0_iter1_reg <= tmp_last_V_reg_226;
        tmp_strb_V_reg_216_pp0_iter1_reg <= tmp_strb_V_reg_216;
        tmp_user_V_reg_221_pp0_iter1_reg <= tmp_user_V_reg_221;
    end
end

always @ (*) begin
    if ((ap_start == 1'b0)) begin
        ap_ST_fsm_state1_blk = 1'b1;
    end else begin
        ap_ST_fsm_state1_blk = 1'b0;
    end
end

always @ (*) begin
    if ((regslice_both_outStream_V_data_V_U_apdone_blk == 1'b1)) begin
        ap_ST_fsm_state6_blk = 1'b1;
    end else begin
        ap_ST_fsm_state6_blk = 1'b0;
    end
end

always @ (*) begin
    if ((icmp_ln14_fu_141_p2 == 1'd1)) begin
        ap_condition_pp0_exit_iter0_state2 = 1'b1;
    end else begin
        ap_condition_pp0_exit_iter0_state2 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state6) & (regslice_both_outStream_V_data_V_U_apdone_blk == 1'b0))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter3 == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state6) & (regslice_both_outStream_V_data_V_U_apdone_blk == 1'b0))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        grp_fu_186_ce = 1'b1;
    end else begin
        grp_fu_186_ce = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln14_fu_141_p2 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        inStream_TDATA_blk_n = inStream_TVALID_int_regslice;
    end else begin
        inStream_TDATA_blk_n = 1'b1;
    end
end

always @ (*) begin
    if (((icmp_ln14_fu_141_p2 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        inStream_TREADY_int_regslice = 1'b1;
    end else begin
        inStream_TREADY_int_regslice = 1'b0;
    end
end

always @ (*) begin
    if ((((ap_enable_reg_pp0_iter3 == 1'b1) & (1'b0 == ap_block_pp0_stage0)) | ((ap_enable_reg_pp0_iter2 == 1'b1) & (1'b0 == ap_block_pp0_stage0)))) begin
        outStream_TDATA_blk_n = outStream_TREADY_int_regslice;
    end else begin
        outStream_TDATA_blk_n = 1'b1;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter2 == 1'b1) & (1'b0 == ap_block_pp0_stage0_11001))) begin
        outStream_TVALID_int_regslice = 1'b1;
    end else begin
        outStream_TVALID_int_regslice = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_pp0_stage0 : begin
            if ((~((icmp_ln14_fu_141_p2 == 1'd1) & (1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (ap_enable_reg_pp0_iter1 == 1'b0)) & ~((ap_enable_reg_pp0_iter3 == 1'b1) & (ap_enable_reg_pp0_iter2 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone)))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else if ((((ap_enable_reg_pp0_iter3 == 1'b1) & (ap_enable_reg_pp0_iter2 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone)) | ((icmp_ln14_fu_141_p2 == 1'd1) & (1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (ap_enable_reg_pp0_iter1 == 1'b0)))) begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end
        end
        ap_ST_fsm_state6 : begin
            if (((1'b1 == ap_CS_fsm_state6) & (regslice_both_outStream_V_data_V_U_apdone_blk == 1'b0))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state6;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state6 = ap_CS_fsm[32'd2];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_pp0_stage0_01001 = (((ap_enable_reg_pp0_iter3 == 1'b1) & (outStream_TREADY_int_regslice == 1'b0)) | ((ap_enable_reg_pp0_iter2 == 1'b1) & (outStream_TREADY_int_regslice == 1'b0)) | ((icmp_ln14_fu_141_p2 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (inStream_TVALID_int_regslice == 1'b0)));
end

always @ (*) begin
    ap_block_pp0_stage0_11001 = (((ap_enable_reg_pp0_iter3 == 1'b1) & (outStream_TREADY_int_regslice == 1'b0)) | ((ap_enable_reg_pp0_iter2 == 1'b1) & (outStream_TREADY_int_regslice == 1'b0)) | ((icmp_ln14_fu_141_p2 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (inStream_TVALID_int_regslice == 1'b0)));
end

always @ (*) begin
    ap_block_pp0_stage0_subdone = (((ap_enable_reg_pp0_iter3 == 1'b1) & (outStream_TREADY_int_regslice == 1'b0)) | ((ap_enable_reg_pp0_iter2 == 1'b1) & (outStream_TREADY_int_regslice == 1'b0)) | ((icmp_ln14_fu_141_p2 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1) & (inStream_TVALID_int_regslice == 1'b0)));
end

always @ (*) begin
    ap_block_state2_pp0_stage0_iter0 = ((icmp_ln14_fu_141_p2 == 1'd0) & (inStream_TVALID_int_regslice == 1'b0));
end

assign ap_block_state3_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_state4_pp0_stage0_iter2 = (outStream_TREADY_int_regslice == 1'b0);
end

always @ (*) begin
    ap_block_state5_pp0_stage0_iter3 = (outStream_TREADY_int_regslice == 1'b0);
end

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);


assign ap_local_deadlock = 1'd0;

always @ (*) begin
    ap_rst_n_inv = ~ap_rst_n;
end

assign icmp_ln14_fu_141_p2 = ((idx_fu_80 == 10'd1000) ? 1'b1 : 1'b0);

assign idx_2_fu_147_p2 = (idx_fu_80 + 10'd1);

assign inStream_TREADY = regslice_both_inStream_V_data_V_U_ack_in;

assign outStream_TVALID = regslice_both_outStream_V_data_V_U_vld_out;


reg find_kernel_block = 0;
assign ap_local_block = find_kernel_block;
// synthesis translate_off
`include "doGain_hls_deadlock_kernel_monitor_top.vh"
// synthesis translate_on

endmodule //doGain

