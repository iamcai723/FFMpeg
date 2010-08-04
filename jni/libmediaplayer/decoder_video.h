#ifndef FFMPEG_DECODER_VIDEO_H
#define FFMPEG_DECODER_VIDEO_H

#include "decoder.h"
#include "renderer.h"

class DecoderVideo : public IDecoder
{
public:
    DecoderVideo(Renderer* renderer);
    ~DecoderVideo();

private:
	AVFrame*					mFrame;
	AVFrame*					mTempFrame;
	struct SwsContext*			mConvertCtx;
	double						mVideoClock;

    bool                        prepare();
    double 						synchronize(AVFrame *src_frame, double pts);
    bool                        decode(void* ptr);
    bool                        process(AVPacket *packet);
    static int					getBuffer(struct AVCodecContext *c, AVFrame *pic);
    static void					releaseBuffer(struct AVCodecContext *c, AVFrame *pic);
};

#endif //FFMPEG_DECODER_AUDIO_H
