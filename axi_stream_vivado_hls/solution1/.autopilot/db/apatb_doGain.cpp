#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_inStream_V_data_V "../tv/cdatafile/c.doGain.autotvin_inStream_V_data_V.dat"
#define AUTOTB_TVOUT_inStream_V_data_V "../tv/cdatafile/c.doGain.autotvout_inStream_V_data_V.dat"
#define AUTOTB_TVIN_inStream_V_keep_V "../tv/cdatafile/c.doGain.autotvin_inStream_V_keep_V.dat"
#define AUTOTB_TVOUT_inStream_V_keep_V "../tv/cdatafile/c.doGain.autotvout_inStream_V_keep_V.dat"
#define AUTOTB_TVIN_inStream_V_strb_V "../tv/cdatafile/c.doGain.autotvin_inStream_V_strb_V.dat"
#define AUTOTB_TVOUT_inStream_V_strb_V "../tv/cdatafile/c.doGain.autotvout_inStream_V_strb_V.dat"
#define AUTOTB_TVIN_inStream_V_user_V "../tv/cdatafile/c.doGain.autotvin_inStream_V_user_V.dat"
#define AUTOTB_TVOUT_inStream_V_user_V "../tv/cdatafile/c.doGain.autotvout_inStream_V_user_V.dat"
#define AUTOTB_TVIN_inStream_V_last_V "../tv/cdatafile/c.doGain.autotvin_inStream_V_last_V.dat"
#define AUTOTB_TVOUT_inStream_V_last_V "../tv/cdatafile/c.doGain.autotvout_inStream_V_last_V.dat"
#define AUTOTB_TVIN_inStream_V_id_V "../tv/cdatafile/c.doGain.autotvin_inStream_V_id_V.dat"
#define AUTOTB_TVOUT_inStream_V_id_V "../tv/cdatafile/c.doGain.autotvout_inStream_V_id_V.dat"
#define AUTOTB_TVIN_inStream_V_dest_V "../tv/cdatafile/c.doGain.autotvin_inStream_V_dest_V.dat"
#define AUTOTB_TVOUT_inStream_V_dest_V "../tv/cdatafile/c.doGain.autotvout_inStream_V_dest_V.dat"
#define WRAPC_STREAM_SIZE_IN_inStream_V_data_V "../tv/stream_size/stream_size_in_inStream_V_data_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_inStream_V_data_V "../tv/stream_size/stream_ingress_status_inStream_V_data_V.dat"
#define WRAPC_STREAM_SIZE_IN_inStream_V_keep_V "../tv/stream_size/stream_size_in_inStream_V_keep_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_inStream_V_keep_V "../tv/stream_size/stream_ingress_status_inStream_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_IN_inStream_V_strb_V "../tv/stream_size/stream_size_in_inStream_V_strb_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_inStream_V_strb_V "../tv/stream_size/stream_ingress_status_inStream_V_strb_V.dat"
#define WRAPC_STREAM_SIZE_IN_inStream_V_user_V "../tv/stream_size/stream_size_in_inStream_V_user_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_inStream_V_user_V "../tv/stream_size/stream_ingress_status_inStream_V_user_V.dat"
#define WRAPC_STREAM_SIZE_IN_inStream_V_last_V "../tv/stream_size/stream_size_in_inStream_V_last_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_inStream_V_last_V "../tv/stream_size/stream_ingress_status_inStream_V_last_V.dat"
#define WRAPC_STREAM_SIZE_IN_inStream_V_id_V "../tv/stream_size/stream_size_in_inStream_V_id_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_inStream_V_id_V "../tv/stream_size/stream_ingress_status_inStream_V_id_V.dat"
#define WRAPC_STREAM_SIZE_IN_inStream_V_dest_V "../tv/stream_size/stream_size_in_inStream_V_dest_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_inStream_V_dest_V "../tv/stream_size/stream_ingress_status_inStream_V_dest_V.dat"
// wrapc file define:
#define AUTOTB_TVIN_outStream_V_data_V "../tv/cdatafile/c.doGain.autotvin_outStream_V_data_V.dat"
#define AUTOTB_TVOUT_outStream_V_data_V "../tv/cdatafile/c.doGain.autotvout_outStream_V_data_V.dat"
#define AUTOTB_TVIN_outStream_V_keep_V "../tv/cdatafile/c.doGain.autotvin_outStream_V_keep_V.dat"
#define AUTOTB_TVOUT_outStream_V_keep_V "../tv/cdatafile/c.doGain.autotvout_outStream_V_keep_V.dat"
#define AUTOTB_TVIN_outStream_V_strb_V "../tv/cdatafile/c.doGain.autotvin_outStream_V_strb_V.dat"
#define AUTOTB_TVOUT_outStream_V_strb_V "../tv/cdatafile/c.doGain.autotvout_outStream_V_strb_V.dat"
#define AUTOTB_TVIN_outStream_V_user_V "../tv/cdatafile/c.doGain.autotvin_outStream_V_user_V.dat"
#define AUTOTB_TVOUT_outStream_V_user_V "../tv/cdatafile/c.doGain.autotvout_outStream_V_user_V.dat"
#define AUTOTB_TVIN_outStream_V_last_V "../tv/cdatafile/c.doGain.autotvin_outStream_V_last_V.dat"
#define AUTOTB_TVOUT_outStream_V_last_V "../tv/cdatafile/c.doGain.autotvout_outStream_V_last_V.dat"
#define AUTOTB_TVIN_outStream_V_id_V "../tv/cdatafile/c.doGain.autotvin_outStream_V_id_V.dat"
#define AUTOTB_TVOUT_outStream_V_id_V "../tv/cdatafile/c.doGain.autotvout_outStream_V_id_V.dat"
#define AUTOTB_TVIN_outStream_V_dest_V "../tv/cdatafile/c.doGain.autotvin_outStream_V_dest_V.dat"
#define AUTOTB_TVOUT_outStream_V_dest_V "../tv/cdatafile/c.doGain.autotvout_outStream_V_dest_V.dat"
#define WRAPC_STREAM_SIZE_OUT_outStream_V_data_V "../tv/stream_size/stream_size_out_outStream_V_data_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_outStream_V_data_V "../tv/stream_size/stream_egress_status_outStream_V_data_V.dat"
#define WRAPC_STREAM_SIZE_OUT_outStream_V_keep_V "../tv/stream_size/stream_size_out_outStream_V_keep_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_outStream_V_keep_V "../tv/stream_size/stream_egress_status_outStream_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_OUT_outStream_V_strb_V "../tv/stream_size/stream_size_out_outStream_V_strb_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_outStream_V_strb_V "../tv/stream_size/stream_egress_status_outStream_V_strb_V.dat"
#define WRAPC_STREAM_SIZE_OUT_outStream_V_user_V "../tv/stream_size/stream_size_out_outStream_V_user_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_outStream_V_user_V "../tv/stream_size/stream_egress_status_outStream_V_user_V.dat"
#define WRAPC_STREAM_SIZE_OUT_outStream_V_last_V "../tv/stream_size/stream_size_out_outStream_V_last_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_outStream_V_last_V "../tv/stream_size/stream_egress_status_outStream_V_last_V.dat"
#define WRAPC_STREAM_SIZE_OUT_outStream_V_id_V "../tv/stream_size/stream_size_out_outStream_V_id_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_outStream_V_id_V "../tv/stream_size/stream_egress_status_outStream_V_id_V.dat"
#define WRAPC_STREAM_SIZE_OUT_outStream_V_dest_V "../tv/stream_size/stream_size_out_outStream_V_dest_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_outStream_V_dest_V "../tv/stream_size/stream_egress_status_outStream_V_dest_V.dat"
// wrapc file define:
#define AUTOTB_TVIN_gain "../tv/cdatafile/c.doGain.autotvin_gain.dat"
#define AUTOTB_TVOUT_gain "../tv/cdatafile/c.doGain.autotvout_gain.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_inStream_V_data_V "../tv/rtldatafile/rtl.doGain.autotvout_inStream_V_data_V.dat"
#define AUTOTB_TVOUT_PC_inStream_V_keep_V "../tv/rtldatafile/rtl.doGain.autotvout_inStream_V_keep_V.dat"
#define AUTOTB_TVOUT_PC_inStream_V_strb_V "../tv/rtldatafile/rtl.doGain.autotvout_inStream_V_strb_V.dat"
#define AUTOTB_TVOUT_PC_inStream_V_user_V "../tv/rtldatafile/rtl.doGain.autotvout_inStream_V_user_V.dat"
#define AUTOTB_TVOUT_PC_inStream_V_last_V "../tv/rtldatafile/rtl.doGain.autotvout_inStream_V_last_V.dat"
#define AUTOTB_TVOUT_PC_inStream_V_id_V "../tv/rtldatafile/rtl.doGain.autotvout_inStream_V_id_V.dat"
#define AUTOTB_TVOUT_PC_inStream_V_dest_V "../tv/rtldatafile/rtl.doGain.autotvout_inStream_V_dest_V.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_outStream_V_data_V "../tv/rtldatafile/rtl.doGain.autotvout_outStream_V_data_V.dat"
#define AUTOTB_TVOUT_PC_outStream_V_keep_V "../tv/rtldatafile/rtl.doGain.autotvout_outStream_V_keep_V.dat"
#define AUTOTB_TVOUT_PC_outStream_V_strb_V "../tv/rtldatafile/rtl.doGain.autotvout_outStream_V_strb_V.dat"
#define AUTOTB_TVOUT_PC_outStream_V_user_V "../tv/rtldatafile/rtl.doGain.autotvout_outStream_V_user_V.dat"
#define AUTOTB_TVOUT_PC_outStream_V_last_V "../tv/rtldatafile/rtl.doGain.autotvout_outStream_V_last_V.dat"
#define AUTOTB_TVOUT_PC_outStream_V_id_V "../tv/rtldatafile/rtl.doGain.autotvout_outStream_V_id_V.dat"
#define AUTOTB_TVOUT_PC_outStream_V_dest_V "../tv/rtldatafile/rtl.doGain.autotvout_outStream_V_dest_V.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_gain "../tv/rtldatafile/rtl.doGain.autotvout_gain.dat"


inline void rev_endian(char* p, size_t nbytes)
{
  std::reverse(p, p+nbytes);
}

template<size_t bit_width>
struct transaction {
  typedef uint64_t depth_t;
  static const size_t wbytes = (bit_width+7)>>3;
  static const size_t dbytes = sizeof(depth_t);
  const depth_t depth;
  const size_t vbytes;
  const size_t tbytes;
  char * const p;
  typedef char (*p_dat)[wbytes];
  p_dat vp;

  void reorder() {
    rev_endian(p, dbytes);
    p_dat vp = (p_dat) (p+dbytes);
    for (depth_t i = 0; i < depth; ++i) {
      rev_endian(vp[i], wbytes);
    }
  }

  transaction(depth_t depth)
    : depth(depth), vbytes(wbytes*depth), tbytes(dbytes+vbytes),
      p(new char[tbytes]) {
    *(depth_t*)p = depth;
    vp = (p_dat) (p+dbytes);
  }

  template<size_t psize>
  void import(char* param, depth_t num, int64_t offset) {
    param -= offset*psize;
    for (depth_t i = 0; i < num; ++i) {
      memcpy(vp[i], param, wbytes);
      param += psize;
    }
    vp += num;
  }

  template<size_t psize>
  void send(char* param, depth_t num) {
    for (depth_t i = 0; i < num; ++i) {
      memcpy(param, vp[i], wbytes);
      param += psize;
    }
    vp += num;
  }

  template<size_t psize>
  void send(char* param, depth_t num, int64_t skip) {
    for (depth_t i = 0; i < num; ++i) {
      memcpy(param, vp[skip+i], wbytes);
      param += psize;
    }
  }

  ~transaction() { if (p) { delete[] p; } }
};
      

inline const std::string begin_str(int num)
{
  return std::string("[[transaction]] ")
         .append(std::to_string(num))
         .append("\n");
}

inline const std::string end_str()
{
  return std::string("[[/transaction]] \n");
}
      
class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  inStream_V_data_V_depth = 0;
  inStream_V_keep_V_depth = 0;
  inStream_V_strb_V_depth = 0;
  inStream_V_user_V_depth = 0;
  inStream_V_last_V_depth = 0;
  inStream_V_id_V_depth = 0;
  inStream_V_dest_V_depth = 0;
  outStream_V_data_V_depth = 0;
  outStream_V_keep_V_depth = 0;
  outStream_V_strb_V_depth = 0;
  outStream_V_user_V_depth = 0;
  outStream_V_last_V_depth = 0;
  outStream_V_id_V_depth = 0;
  outStream_V_dest_V_depth = 0;
  gain_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{inStream_V_data_V " << inStream_V_data_V_depth << "}\n";
  total_list << "{inStream_V_keep_V " << inStream_V_keep_V_depth << "}\n";
  total_list << "{inStream_V_strb_V " << inStream_V_strb_V_depth << "}\n";
  total_list << "{inStream_V_user_V " << inStream_V_user_V_depth << "}\n";
  total_list << "{inStream_V_last_V " << inStream_V_last_V_depth << "}\n";
  total_list << "{inStream_V_id_V " << inStream_V_id_V_depth << "}\n";
  total_list << "{inStream_V_dest_V " << inStream_V_dest_V_depth << "}\n";
  total_list << "{outStream_V_data_V " << outStream_V_data_V_depth << "}\n";
  total_list << "{outStream_V_keep_V " << outStream_V_keep_V_depth << "}\n";
  total_list << "{outStream_V_strb_V " << outStream_V_strb_V_depth << "}\n";
  total_list << "{outStream_V_user_V " << outStream_V_user_V_depth << "}\n";
  total_list << "{outStream_V_last_V " << outStream_V_last_V_depth << "}\n";
  total_list << "{outStream_V_id_V " << outStream_V_id_V_depth << "}\n";
  total_list << "{outStream_V_dest_V " << outStream_V_dest_V_depth << "}\n";
  total_list << "{gain " << gain_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int inStream_V_data_V_depth;
    int inStream_V_keep_V_depth;
    int inStream_V_strb_V_depth;
    int inStream_V_user_V_depth;
    int inStream_V_last_V_depth;
    int inStream_V_id_V_depth;
    int inStream_V_dest_V_depth;
    int outStream_V_data_V_depth;
    int outStream_V_keep_V_depth;
    int outStream_V_strb_V_depth;
    int outStream_V_user_V_depth;
    int outStream_V_last_V_depth;
    int outStream_V_id_V_depth;
    int outStream_V_dest_V_depth;
    int gain_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static bool RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool err = false;
  size_t x_found;

  // search and replace 'X' with '0' from the 3rd char of token
  while ((x_found = AESL_token.find('X', 0)) != string::npos)
    err = true, AESL_token.replace(x_found, 1, "0");
  
  // search and replace 'x' with '0' from the 3rd char of token
  while ((x_found = AESL_token.find('x', 2)) != string::npos)
    err = true, AESL_token.replace(x_found, 1, "0");
  
  return err;}
extern "C" void doGain_hw_stub_wrapper(volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, int);

extern "C" void apatb_doGain_hw(volatile void * __xlx_apatb_param_inStream_V_data_V, volatile void * __xlx_apatb_param_inStream_V_keep_V, volatile void * __xlx_apatb_param_inStream_V_strb_V, volatile void * __xlx_apatb_param_inStream_V_user_V, volatile void * __xlx_apatb_param_inStream_V_last_V, volatile void * __xlx_apatb_param_inStream_V_id_V, volatile void * __xlx_apatb_param_inStream_V_dest_V, volatile void * __xlx_apatb_param_outStream_V_data_V, volatile void * __xlx_apatb_param_outStream_V_keep_V, volatile void * __xlx_apatb_param_outStream_V_strb_V, volatile void * __xlx_apatb_param_outStream_V_user_V, volatile void * __xlx_apatb_param_outStream_V_last_V, volatile void * __xlx_apatb_param_outStream_V_id_V, volatile void * __xlx_apatb_param_outStream_V_dest_V, int __xlx_apatb_param_gain) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
static AESL_FILE_HANDLER aesl_fh;
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;
long __xlx_apatb_param_inStream_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_inStream_V_data_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_inStream_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_inStream_stream_buf_final_size; ++i) {
((hls::stream<int>*)__xlx_apatb_param_inStream_V_data_V)->read();
((hls::stream<char>*)__xlx_apatb_param_inStream_V_keep_V)->read();
((hls::stream<char>*)__xlx_apatb_param_inStream_V_strb_V)->read();
((hls::stream<char>*)__xlx_apatb_param_inStream_V_user_V)->read();
((hls::stream<char>*)__xlx_apatb_param_inStream_V_last_V)->read();
((hls::stream<char>*)__xlx_apatb_param_inStream_V_id_V)->read();
((hls::stream<char>*)__xlx_apatb_param_inStream_V_dest_V)->read();
}
{unsigned xlx_stream_outStream_size = 0;

          std::vector<sc_bv<32> > outStream_V_data_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_outStream_V_data_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > outStream_V_data_V_pc_buffer;
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "outStream");
  
            // push token into output port buffer
            if (AESL_token != "") {
              outStream_V_data_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "outStream" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {xlx_stream_outStream_size=outStream_V_data_V_pc_buffer.size();
outStream_V_data_V_pc_buffer_Copy=outStream_V_data_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<32> > outStream_V_keep_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_outStream_V_keep_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > outStream_V_keep_V_pc_buffer;
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "outStream");
  
            // push token into output port buffer
            if (AESL_token != "") {
              outStream_V_keep_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "outStream" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {xlx_stream_outStream_size=outStream_V_keep_V_pc_buffer.size();
outStream_V_keep_V_pc_buffer_Copy=outStream_V_keep_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<32> > outStream_V_strb_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_outStream_V_strb_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > outStream_V_strb_V_pc_buffer;
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "outStream");
  
            // push token into output port buffer
            if (AESL_token != "") {
              outStream_V_strb_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "outStream" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {xlx_stream_outStream_size=outStream_V_strb_V_pc_buffer.size();
outStream_V_strb_V_pc_buffer_Copy=outStream_V_strb_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<32> > outStream_V_user_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_outStream_V_user_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > outStream_V_user_V_pc_buffer;
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "outStream");
  
            // push token into output port buffer
            if (AESL_token != "") {
              outStream_V_user_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "outStream" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {xlx_stream_outStream_size=outStream_V_user_V_pc_buffer.size();
outStream_V_user_V_pc_buffer_Copy=outStream_V_user_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<32> > outStream_V_last_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_outStream_V_last_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > outStream_V_last_V_pc_buffer;
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "outStream");
  
            // push token into output port buffer
            if (AESL_token != "") {
              outStream_V_last_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "outStream" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {xlx_stream_outStream_size=outStream_V_last_V_pc_buffer.size();
outStream_V_last_V_pc_buffer_Copy=outStream_V_last_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<32> > outStream_V_id_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_outStream_V_id_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > outStream_V_id_V_pc_buffer;
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "outStream");
  
            // push token into output port buffer
            if (AESL_token != "") {
              outStream_V_id_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "outStream" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {xlx_stream_outStream_size=outStream_V_id_V_pc_buffer.size();
outStream_V_id_V_pc_buffer_Copy=outStream_V_id_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
          std::vector<sc_bv<32> > outStream_V_dest_V_pc_buffer_Copy;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_outStream_V_dest_V);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > outStream_V_dest_V_pc_buffer;
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token, "outStream");
  
            // push token into output port buffer
            if (AESL_token != "") {
              outStream_V_dest_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "outStream" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {xlx_stream_outStream_size=outStream_V_dest_V_pc_buffer.size();
outStream_V_dest_V_pc_buffer_Copy=outStream_V_dest_V_pc_buffer;
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (int j = 0, e = xlx_stream_outStream_size; j != e; ++j) {
int xlx_stream_elt_data;
((int*)&xlx_stream_elt_data)[0] = outStream_V_data_V_pc_buffer_Copy[j].to_int64();
((hls::stream<int>*)__xlx_apatb_param_outStream_V_data_V)->write(xlx_stream_elt_data);
char xlx_stream_elt_keep;
((char*)&xlx_stream_elt_keep)[0] = outStream_V_keep_V_pc_buffer_Copy[j].to_int64();
((hls::stream<char>*)__xlx_apatb_param_outStream_V_keep_V)->write(xlx_stream_elt_keep);
char xlx_stream_elt_strb;
((char*)&xlx_stream_elt_strb)[0] = outStream_V_strb_V_pc_buffer_Copy[j].to_int64();
((hls::stream<char>*)__xlx_apatb_param_outStream_V_strb_V)->write(xlx_stream_elt_strb);
char xlx_stream_elt_user;
((char*)&xlx_stream_elt_user)[0] = outStream_V_user_V_pc_buffer_Copy[j].to_int64();
((hls::stream<char>*)__xlx_apatb_param_outStream_V_user_V)->write(xlx_stream_elt_user);
char xlx_stream_elt_last;
((char*)&xlx_stream_elt_last)[0] = outStream_V_last_V_pc_buffer_Copy[j].to_uint64();
((hls::stream<char>*)__xlx_apatb_param_outStream_V_last_V)->write(xlx_stream_elt_last);
char xlx_stream_elt_id;
((char*)&xlx_stream_elt_id)[0] = outStream_V_id_V_pc_buffer_Copy[j].to_int64();
((hls::stream<char>*)__xlx_apatb_param_outStream_V_id_V)->write(xlx_stream_elt_id);
char xlx_stream_elt_dest;
((char*)&xlx_stream_elt_dest)[0] = outStream_V_dest_V_pc_buffer_Copy[j].to_int64();
((hls::stream<char>*)__xlx_apatb_param_outStream_V_dest_V)->write(xlx_stream_elt_dest);
}}
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_inStream_V_data_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_inStream_V_data_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_inStream_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_inStream_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_inStream_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_inStream_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_inStream_V_user_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_inStream_V_user_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_inStream_V_last_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_inStream_V_last_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_inStream_V_id_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_inStream_V_id_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_inStream_V_dest_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_inStream_V_dest_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_outStream_V_data_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_outStream_V_data_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_outStream_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_outStream_V_keep_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_outStream_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_outStream_V_strb_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_outStream_V_user_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_outStream_V_user_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_outStream_V_last_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_outStream_V_last_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_outStream_V_id_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_outStream_V_id_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_outStream_V_dest_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_outStream_V_dest_V);
CodeState = DUMP_INPUTS;
// data
std::vector<int> __xlx_apatb_param_inStream_V_data_V_stream_buf;
{
  while (!((hls::stream<int>*)__xlx_apatb_param_inStream_V_data_V)->empty())
    __xlx_apatb_param_inStream_V_data_V_stream_buf.push_back(((hls::stream<int>*)__xlx_apatb_param_inStream_V_data_V)->read());
  for (int i = 0; i < __xlx_apatb_param_inStream_V_data_V_stream_buf.size(); ++i)
    ((hls::stream<int>*)__xlx_apatb_param_inStream_V_data_V)->write(__xlx_apatb_param_inStream_V_data_V_stream_buf[i]);
  }
long __xlx_apatb_param_inStream_stream_buf_size = ((hls::stream<int>*)__xlx_apatb_param_inStream_V_data_V)->size();
// keep
std::vector<char> __xlx_apatb_param_inStream_V_keep_V_stream_buf;
{
  while (!((hls::stream<char>*)__xlx_apatb_param_inStream_V_keep_V)->empty())
    __xlx_apatb_param_inStream_V_keep_V_stream_buf.push_back(((hls::stream<char>*)__xlx_apatb_param_inStream_V_keep_V)->read());
  for (int i = 0; i < __xlx_apatb_param_inStream_V_keep_V_stream_buf.size(); ++i)
    ((hls::stream<char>*)__xlx_apatb_param_inStream_V_keep_V)->write(__xlx_apatb_param_inStream_V_keep_V_stream_buf[i]);
  }
// strb
std::vector<char> __xlx_apatb_param_inStream_V_strb_V_stream_buf;
{
  while (!((hls::stream<char>*)__xlx_apatb_param_inStream_V_strb_V)->empty())
    __xlx_apatb_param_inStream_V_strb_V_stream_buf.push_back(((hls::stream<char>*)__xlx_apatb_param_inStream_V_strb_V)->read());
  for (int i = 0; i < __xlx_apatb_param_inStream_V_strb_V_stream_buf.size(); ++i)
    ((hls::stream<char>*)__xlx_apatb_param_inStream_V_strb_V)->write(__xlx_apatb_param_inStream_V_strb_V_stream_buf[i]);
  }
// user
std::vector<char> __xlx_apatb_param_inStream_V_user_V_stream_buf;
{
  while (!((hls::stream<char>*)__xlx_apatb_param_inStream_V_user_V)->empty())
    __xlx_apatb_param_inStream_V_user_V_stream_buf.push_back(((hls::stream<char>*)__xlx_apatb_param_inStream_V_user_V)->read());
  for (int i = 0; i < __xlx_apatb_param_inStream_V_user_V_stream_buf.size(); ++i)
    ((hls::stream<char>*)__xlx_apatb_param_inStream_V_user_V)->write(__xlx_apatb_param_inStream_V_user_V_stream_buf[i]);
  }
// last
std::vector<char> __xlx_apatb_param_inStream_V_last_V_stream_buf;
{
  while (!((hls::stream<char>*)__xlx_apatb_param_inStream_V_last_V)->empty())
    __xlx_apatb_param_inStream_V_last_V_stream_buf.push_back(((hls::stream<char>*)__xlx_apatb_param_inStream_V_last_V)->read());
  for (int i = 0; i < __xlx_apatb_param_inStream_V_last_V_stream_buf.size(); ++i)
    ((hls::stream<char>*)__xlx_apatb_param_inStream_V_last_V)->write(__xlx_apatb_param_inStream_V_last_V_stream_buf[i]);
  }
// id
std::vector<char> __xlx_apatb_param_inStream_V_id_V_stream_buf;
{
  while (!((hls::stream<char>*)__xlx_apatb_param_inStream_V_id_V)->empty())
    __xlx_apatb_param_inStream_V_id_V_stream_buf.push_back(((hls::stream<char>*)__xlx_apatb_param_inStream_V_id_V)->read());
  for (int i = 0; i < __xlx_apatb_param_inStream_V_id_V_stream_buf.size(); ++i)
    ((hls::stream<char>*)__xlx_apatb_param_inStream_V_id_V)->write(__xlx_apatb_param_inStream_V_id_V_stream_buf[i]);
  }
// dest
std::vector<char> __xlx_apatb_param_inStream_V_dest_V_stream_buf;
{
  while (!((hls::stream<char>*)__xlx_apatb_param_inStream_V_dest_V)->empty())
    __xlx_apatb_param_inStream_V_dest_V_stream_buf.push_back(((hls::stream<char>*)__xlx_apatb_param_inStream_V_dest_V)->read());
  for (int i = 0; i < __xlx_apatb_param_inStream_V_dest_V_stream_buf.size(); ++i)
    ((hls::stream<char>*)__xlx_apatb_param_inStream_V_dest_V)->write(__xlx_apatb_param_inStream_V_dest_V_stream_buf[i]);
  }
// data
std::vector<int> __xlx_apatb_param_outStream_V_data_V_stream_buf;
long __xlx_apatb_param_outStream_stream_buf_size = ((hls::stream<int>*)__xlx_apatb_param_outStream_V_data_V)->size();
// keep
std::vector<char> __xlx_apatb_param_outStream_V_keep_V_stream_buf;
// strb
std::vector<char> __xlx_apatb_param_outStream_V_strb_V_stream_buf;
// user
std::vector<char> __xlx_apatb_param_outStream_V_user_V_stream_buf;
// last
std::vector<char> __xlx_apatb_param_outStream_V_last_V_stream_buf;
// id
std::vector<char> __xlx_apatb_param_outStream_V_id_V_stream_buf;
// dest
std::vector<char> __xlx_apatb_param_outStream_V_dest_V_stream_buf;
// print gain Transactions
{
aesl_fh.write(AUTOTB_TVIN_gain, begin_str(AESL_transaction));
{
    sc_bv<32> __xlx_tmp_lv = *((int*)&__xlx_apatb_param_gain);
aesl_fh.write(AUTOTB_TVIN_gain, __xlx_tmp_lv.to_string(SC_HEX)+string("\n"));
}
  tcl_file.set_num(1, &tcl_file.gain_depth);
aesl_fh.write(AUTOTB_TVIN_gain, end_str());
}

CodeState = CALL_C_DUT;
doGain_hw_stub_wrapper(__xlx_apatb_param_inStream_V_data_V, __xlx_apatb_param_inStream_V_keep_V, __xlx_apatb_param_inStream_V_strb_V, __xlx_apatb_param_inStream_V_user_V, __xlx_apatb_param_inStream_V_last_V, __xlx_apatb_param_inStream_V_id_V, __xlx_apatb_param_inStream_V_dest_V, __xlx_apatb_param_outStream_V_data_V, __xlx_apatb_param_outStream_V_keep_V, __xlx_apatb_param_outStream_V_strb_V, __xlx_apatb_param_outStream_V_user_V, __xlx_apatb_param_outStream_V_last_V, __xlx_apatb_param_outStream_V_id_V, __xlx_apatb_param_outStream_V_dest_V, __xlx_apatb_param_gain);
CodeState = DUMP_OUTPUTS;
long __xlx_apatb_param_inStream_stream_buf_final_size = __xlx_apatb_param_inStream_stream_buf_size - ((hls::stream<int>*)__xlx_apatb_param_inStream_V_data_V)->size();
aesl_fh.write(AUTOTB_TVIN_inStream_V_data_V, begin_str(AESL_transaction));
aesl_fh.write(AUTOTB_TVIN_inStream_V_keep_V, begin_str(AESL_transaction));
aesl_fh.write(AUTOTB_TVIN_inStream_V_strb_V, begin_str(AESL_transaction));
aesl_fh.write(AUTOTB_TVIN_inStream_V_user_V, begin_str(AESL_transaction));
aesl_fh.write(AUTOTB_TVIN_inStream_V_last_V, begin_str(AESL_transaction));
aesl_fh.write(AUTOTB_TVIN_inStream_V_id_V, begin_str(AESL_transaction));
aesl_fh.write(AUTOTB_TVIN_inStream_V_dest_V, begin_str(AESL_transaction));
for (int j = 0, e = __xlx_apatb_param_inStream_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_0_lv = ((int*)&__xlx_apatb_param_inStream_V_data_V_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_0_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_inStream_V_data_V, __xlx_sprintf_buffer.data());
sc_bv<4> __xlx_tmp_1_lv = ((char*)&__xlx_apatb_param_inStream_V_keep_V_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_1_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_inStream_V_keep_V, __xlx_sprintf_buffer.data());
sc_bv<4> __xlx_tmp_2_lv = ((char*)&__xlx_apatb_param_inStream_V_strb_V_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_2_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_inStream_V_strb_V, __xlx_sprintf_buffer.data());
sc_bv<2> __xlx_tmp_3_lv = ((char*)&__xlx_apatb_param_inStream_V_user_V_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_3_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_inStream_V_user_V, __xlx_sprintf_buffer.data());
sc_bv<1> __xlx_tmp_4_lv = ((char*)&__xlx_apatb_param_inStream_V_last_V_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_4_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_inStream_V_last_V, __xlx_sprintf_buffer.data());
sc_bv<5> __xlx_tmp_5_lv = ((char*)&__xlx_apatb_param_inStream_V_id_V_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_5_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_inStream_V_id_V, __xlx_sprintf_buffer.data());
sc_bv<6> __xlx_tmp_6_lv = ((char*)&__xlx_apatb_param_inStream_V_dest_V_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_6_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_inStream_V_dest_V, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_inStream_stream_buf_final_size, &tcl_file.inStream_V_data_V_depth);
aesl_fh.write(AUTOTB_TVIN_inStream_V_data_V, end_str());
tcl_file.set_num(__xlx_apatb_param_inStream_stream_buf_final_size, &tcl_file.inStream_V_keep_V_depth);
aesl_fh.write(AUTOTB_TVIN_inStream_V_keep_V, end_str());
tcl_file.set_num(__xlx_apatb_param_inStream_stream_buf_final_size, &tcl_file.inStream_V_strb_V_depth);
aesl_fh.write(AUTOTB_TVIN_inStream_V_strb_V, end_str());
tcl_file.set_num(__xlx_apatb_param_inStream_stream_buf_final_size, &tcl_file.inStream_V_user_V_depth);
aesl_fh.write(AUTOTB_TVIN_inStream_V_user_V, end_str());
tcl_file.set_num(__xlx_apatb_param_inStream_stream_buf_final_size, &tcl_file.inStream_V_last_V_depth);
aesl_fh.write(AUTOTB_TVIN_inStream_V_last_V, end_str());
tcl_file.set_num(__xlx_apatb_param_inStream_stream_buf_final_size, &tcl_file.inStream_V_id_V_depth);
aesl_fh.write(AUTOTB_TVIN_inStream_V_id_V, end_str());
tcl_file.set_num(__xlx_apatb_param_inStream_stream_buf_final_size, &tcl_file.inStream_V_dest_V_depth);
aesl_fh.write(AUTOTB_TVIN_inStream_V_dest_V, end_str());

// dump stream ingress status to file

// dump stream ingress status to file
{
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_data_V, begin_str(AESL_transaction));
if (__xlx_apatb_param_inStream_stream_buf_final_size > 0) {
  long inStream_V_data_V_stream_ingress_size = __xlx_apatb_param_inStream_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_data_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_inStream_stream_buf_final_size; j != e; j++) {
    inStream_V_data_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_data_V, __xlx_sprintf_buffer.data());
  }
} else {
  long inStream_V_data_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_data_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_data_V, __xlx_sprintf_buffer.data());
}
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_data_V, end_str());
}

// dump stream ingress status to file
{
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_keep_V, begin_str(AESL_transaction));
if (__xlx_apatb_param_inStream_stream_buf_final_size > 0) {
  long inStream_V_keep_V_stream_ingress_size = __xlx_apatb_param_inStream_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_keep_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_inStream_stream_buf_final_size; j != e; j++) {
    inStream_V_keep_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_keep_V, __xlx_sprintf_buffer.data());
  }
} else {
  long inStream_V_keep_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_keep_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_keep_V, __xlx_sprintf_buffer.data());
}
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_keep_V, end_str());
}

// dump stream ingress status to file
{
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_strb_V, begin_str(AESL_transaction));
if (__xlx_apatb_param_inStream_stream_buf_final_size > 0) {
  long inStream_V_strb_V_stream_ingress_size = __xlx_apatb_param_inStream_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_strb_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_inStream_stream_buf_final_size; j != e; j++) {
    inStream_V_strb_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_strb_V, __xlx_sprintf_buffer.data());
  }
} else {
  long inStream_V_strb_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_strb_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_strb_V, __xlx_sprintf_buffer.data());
}
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_strb_V, end_str());
}

// dump stream ingress status to file
{
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_user_V, begin_str(AESL_transaction));
if (__xlx_apatb_param_inStream_stream_buf_final_size > 0) {
  long inStream_V_user_V_stream_ingress_size = __xlx_apatb_param_inStream_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_user_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_user_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_inStream_stream_buf_final_size; j != e; j++) {
    inStream_V_user_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_user_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_user_V, __xlx_sprintf_buffer.data());
  }
} else {
  long inStream_V_user_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_user_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_user_V, __xlx_sprintf_buffer.data());
}
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_user_V, end_str());
}

// dump stream ingress status to file
{
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_last_V, begin_str(AESL_transaction));
if (__xlx_apatb_param_inStream_stream_buf_final_size > 0) {
  long inStream_V_last_V_stream_ingress_size = __xlx_apatb_param_inStream_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_last_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_inStream_stream_buf_final_size; j != e; j++) {
    inStream_V_last_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_last_V, __xlx_sprintf_buffer.data());
  }
} else {
  long inStream_V_last_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_last_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_last_V, __xlx_sprintf_buffer.data());
}
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_last_V, end_str());
}

// dump stream ingress status to file
{
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_id_V, begin_str(AESL_transaction));
if (__xlx_apatb_param_inStream_stream_buf_final_size > 0) {
  long inStream_V_id_V_stream_ingress_size = __xlx_apatb_param_inStream_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_id_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_id_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_inStream_stream_buf_final_size; j != e; j++) {
    inStream_V_id_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_id_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_id_V, __xlx_sprintf_buffer.data());
  }
} else {
  long inStream_V_id_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_id_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_id_V, __xlx_sprintf_buffer.data());
}
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_id_V, end_str());
}

// dump stream ingress status to file
{
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_dest_V, begin_str(AESL_transaction));
if (__xlx_apatb_param_inStream_stream_buf_final_size > 0) {
  long inStream_V_dest_V_stream_ingress_size = __xlx_apatb_param_inStream_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_dest_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_dest_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_inStream_stream_buf_final_size; j != e; j++) {
    inStream_V_dest_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_dest_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_dest_V, __xlx_sprintf_buffer.data());
  }
} else {
  long inStream_V_dest_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", inStream_V_dest_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_dest_V, __xlx_sprintf_buffer.data());
}
aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_inStream_V_dest_V, end_str());
}
{
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_data_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_inStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_data_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_data_V, end_str());
}
{
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_keep_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_inStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_keep_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_keep_V, end_str());
}
{
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_strb_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_inStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_strb_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_strb_V, end_str());
}
{
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_user_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_inStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_user_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_user_V, end_str());
}
{
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_last_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_inStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_last_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_last_V, end_str());
}
{
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_id_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_inStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_id_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_id_V, end_str());
}
{
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_dest_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_inStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_dest_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_IN_inStream_V_dest_V, end_str());
}

//********************** dump C output stream *******************
long __xlx_apatb_param_outStream_stream_buf_final_size = ((hls::stream<int>*)__xlx_apatb_param_outStream_V_data_V)->size() - __xlx_apatb_param_outStream_stream_buf_size;
{
  while (!((hls::stream<int>*)__xlx_apatb_param_outStream_V_data_V)->empty())
    __xlx_apatb_param_outStream_V_data_V_stream_buf.push_back(((hls::stream<int>*)__xlx_apatb_param_outStream_V_data_V)->read());
  for (int i = 0; i < __xlx_apatb_param_outStream_V_data_V_stream_buf.size(); ++i)
    ((hls::stream<int>*)__xlx_apatb_param_outStream_V_data_V)->write(__xlx_apatb_param_outStream_V_data_V_stream_buf[i]);
  }
{
  while (!((hls::stream<char>*)__xlx_apatb_param_outStream_V_keep_V)->empty())
    __xlx_apatb_param_outStream_V_keep_V_stream_buf.push_back(((hls::stream<char>*)__xlx_apatb_param_outStream_V_keep_V)->read());
  for (int i = 0; i < __xlx_apatb_param_outStream_V_keep_V_stream_buf.size(); ++i)
    ((hls::stream<char>*)__xlx_apatb_param_outStream_V_keep_V)->write(__xlx_apatb_param_outStream_V_keep_V_stream_buf[i]);
  }
{
  while (!((hls::stream<char>*)__xlx_apatb_param_outStream_V_strb_V)->empty())
    __xlx_apatb_param_outStream_V_strb_V_stream_buf.push_back(((hls::stream<char>*)__xlx_apatb_param_outStream_V_strb_V)->read());
  for (int i = 0; i < __xlx_apatb_param_outStream_V_strb_V_stream_buf.size(); ++i)
    ((hls::stream<char>*)__xlx_apatb_param_outStream_V_strb_V)->write(__xlx_apatb_param_outStream_V_strb_V_stream_buf[i]);
  }
{
  while (!((hls::stream<char>*)__xlx_apatb_param_outStream_V_user_V)->empty())
    __xlx_apatb_param_outStream_V_user_V_stream_buf.push_back(((hls::stream<char>*)__xlx_apatb_param_outStream_V_user_V)->read());
  for (int i = 0; i < __xlx_apatb_param_outStream_V_user_V_stream_buf.size(); ++i)
    ((hls::stream<char>*)__xlx_apatb_param_outStream_V_user_V)->write(__xlx_apatb_param_outStream_V_user_V_stream_buf[i]);
  }
{
  while (!((hls::stream<char>*)__xlx_apatb_param_outStream_V_last_V)->empty())
    __xlx_apatb_param_outStream_V_last_V_stream_buf.push_back(((hls::stream<char>*)__xlx_apatb_param_outStream_V_last_V)->read());
  for (int i = 0; i < __xlx_apatb_param_outStream_V_last_V_stream_buf.size(); ++i)
    ((hls::stream<char>*)__xlx_apatb_param_outStream_V_last_V)->write(__xlx_apatb_param_outStream_V_last_V_stream_buf[i]);
  }
{
  while (!((hls::stream<char>*)__xlx_apatb_param_outStream_V_id_V)->empty())
    __xlx_apatb_param_outStream_V_id_V_stream_buf.push_back(((hls::stream<char>*)__xlx_apatb_param_outStream_V_id_V)->read());
  for (int i = 0; i < __xlx_apatb_param_outStream_V_id_V_stream_buf.size(); ++i)
    ((hls::stream<char>*)__xlx_apatb_param_outStream_V_id_V)->write(__xlx_apatb_param_outStream_V_id_V_stream_buf[i]);
  }
{
  while (!((hls::stream<char>*)__xlx_apatb_param_outStream_V_dest_V)->empty())
    __xlx_apatb_param_outStream_V_dest_V_stream_buf.push_back(((hls::stream<char>*)__xlx_apatb_param_outStream_V_dest_V)->read());
  for (int i = 0; i < __xlx_apatb_param_outStream_V_dest_V_stream_buf.size(); ++i)
    ((hls::stream<char>*)__xlx_apatb_param_outStream_V_dest_V)->write(__xlx_apatb_param_outStream_V_dest_V_stream_buf[i]);
  }
aesl_fh.write(AUTOTB_TVOUT_outStream_V_data_V, begin_str(AESL_transaction));
aesl_fh.write(AUTOTB_TVOUT_outStream_V_keep_V, begin_str(AESL_transaction));
aesl_fh.write(AUTOTB_TVOUT_outStream_V_strb_V, begin_str(AESL_transaction));
aesl_fh.write(AUTOTB_TVOUT_outStream_V_user_V, begin_str(AESL_transaction));
aesl_fh.write(AUTOTB_TVOUT_outStream_V_last_V, begin_str(AESL_transaction));
aesl_fh.write(AUTOTB_TVOUT_outStream_V_id_V, begin_str(AESL_transaction));
aesl_fh.write(AUTOTB_TVOUT_outStream_V_dest_V, begin_str(AESL_transaction));
for (int j = 0, e = __xlx_apatb_param_outStream_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_0_lv = ((int*)&__xlx_apatb_param_outStream_V_data_V_stream_buf[__xlx_apatb_param_outStream_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_0_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_outStream_V_data_V, __xlx_sprintf_buffer.data());
sc_bv<4> __xlx_tmp_1_lv = ((char*)&__xlx_apatb_param_outStream_V_keep_V_stream_buf[__xlx_apatb_param_outStream_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_1_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_outStream_V_keep_V, __xlx_sprintf_buffer.data());
sc_bv<4> __xlx_tmp_2_lv = ((char*)&__xlx_apatb_param_outStream_V_strb_V_stream_buf[__xlx_apatb_param_outStream_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_2_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_outStream_V_strb_V, __xlx_sprintf_buffer.data());
sc_bv<2> __xlx_tmp_3_lv = ((char*)&__xlx_apatb_param_outStream_V_user_V_stream_buf[__xlx_apatb_param_outStream_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_3_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_outStream_V_user_V, __xlx_sprintf_buffer.data());
sc_bv<1> __xlx_tmp_4_lv = ((char*)&__xlx_apatb_param_outStream_V_last_V_stream_buf[__xlx_apatb_param_outStream_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_4_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_outStream_V_last_V, __xlx_sprintf_buffer.data());
sc_bv<5> __xlx_tmp_5_lv = ((char*)&__xlx_apatb_param_outStream_V_id_V_stream_buf[__xlx_apatb_param_outStream_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_5_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_outStream_V_id_V, __xlx_sprintf_buffer.data());
sc_bv<6> __xlx_tmp_6_lv = ((char*)&__xlx_apatb_param_outStream_V_dest_V_stream_buf[__xlx_apatb_param_outStream_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_6_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_outStream_V_dest_V, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_outStream_stream_buf_final_size, &tcl_file.outStream_V_data_V_depth);
aesl_fh.write(AUTOTB_TVOUT_outStream_V_data_V, end_str());
tcl_file.set_num(__xlx_apatb_param_outStream_stream_buf_final_size, &tcl_file.outStream_V_keep_V_depth);
aesl_fh.write(AUTOTB_TVOUT_outStream_V_keep_V, end_str());
tcl_file.set_num(__xlx_apatb_param_outStream_stream_buf_final_size, &tcl_file.outStream_V_strb_V_depth);
aesl_fh.write(AUTOTB_TVOUT_outStream_V_strb_V, end_str());
tcl_file.set_num(__xlx_apatb_param_outStream_stream_buf_final_size, &tcl_file.outStream_V_user_V_depth);
aesl_fh.write(AUTOTB_TVOUT_outStream_V_user_V, end_str());
tcl_file.set_num(__xlx_apatb_param_outStream_stream_buf_final_size, &tcl_file.outStream_V_last_V_depth);
aesl_fh.write(AUTOTB_TVOUT_outStream_V_last_V, end_str());
tcl_file.set_num(__xlx_apatb_param_outStream_stream_buf_final_size, &tcl_file.outStream_V_id_V_depth);
aesl_fh.write(AUTOTB_TVOUT_outStream_V_id_V, end_str());
tcl_file.set_num(__xlx_apatb_param_outStream_stream_buf_final_size, &tcl_file.outStream_V_dest_V_depth);
aesl_fh.write(AUTOTB_TVOUT_outStream_V_dest_V, end_str());
{
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_data_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_outStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_data_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_data_V, end_str());
}
{
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_keep_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_outStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_keep_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_keep_V, end_str());
}
{
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_strb_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_outStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_strb_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_strb_V, end_str());
}
{
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_user_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_outStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_user_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_user_V, end_str());
}
{
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_last_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_outStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_last_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_last_V, end_str());
}
{
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_id_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_outStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_id_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_id_V, end_str());
}
{
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_dest_V, begin_str(AESL_transaction));
sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_outStream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_dest_V, __xlx_sprintf_buffer.data());
aesl_fh.write(WRAPC_STREAM_SIZE_OUT_outStream_V_dest_V, end_str());
}
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
