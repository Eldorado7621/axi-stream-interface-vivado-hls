#include <hls_stream.h>
#include <ap_axi_sdata.h>

//declare 32-bit integer with side channel
typedef ap_axis<32,2,5,6> intSdCh;

void doGain(hls::stream<intSdCh> &inStream,hls::stream<intSdCh> &outStream, int gain)
{
#pragma HLS INTERFACE axis port=outStream
#pragma HLS INTERFACE axis port=inStream
#pragma HLS INTERFACE s_axilite port=gain bundle=CRTL_BUS
#pragma HLS INTERFACE s_axilite port=return bundle=CRTL_BUS

	for (int idx=0;idx<(1000); idx++)
	{
#pragma HLS PIPELINE
		//Read and cache (Block here if FIFO sender is empty)
		intSdCh valIn=inStream.read();
		intSdCh valOut;

		valOut.data=valIn.data *gain;

		// Just copy from the input the other side-channels (keep, strobe, id,dest,last)
		valOut.keep=valIn.keep;
		valOut.strb=valIn.strb;
		valOut.user=valIn.user;
		valOut.last=valIn.last;
		valOut.id=valIn.id;
		valOut.dest=valIn.dest;

		// send to the stream (Block if the FIFO receiver if full)

		outStream.write(valOut);


	}


}
