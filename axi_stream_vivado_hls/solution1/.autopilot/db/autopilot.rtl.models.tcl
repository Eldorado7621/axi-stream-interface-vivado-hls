set SynModuleInfo {
  {SRCNAME doGain MODELNAME doGain RTLNAME doGain IS_TOP 1
    SUBMODULES {
      {MODELNAME doGain_mul_32s_32s_32_2_1 RTLNAME doGain_mul_32s_32s_32_2_1 BINDTYPE op TYPE mul IMPL auto LATENCY 1 ALLOW_PRAGMA 1}
      {MODELNAME doGain_CRTL_BUS_s_axi RTLNAME doGain_CRTL_BUS_s_axi BINDTYPE interface TYPE interface_s_axilite}
      {MODELNAME doGain_regslice_both RTLNAME doGain_regslice_both BINDTYPE interface TYPE interface_regslice INSTNAME doGain_regslice_both_U}
    }
  }
}
