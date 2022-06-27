#include "gstfakevideofilter.h"
#include "gst/video/gstvideofilter.h"
#include "gst/video/video-frame.h"

static gboolean gst_fake_video_filter_start(GstBaseTransform* base);
static gboolean gst_fake_video_filter_stop(GstBaseTransform* base);
static GstFlowReturn gst_fake_video_filter_transform_frame_ip(
    GstVideoFilter* base,
    GstVideoFrame* outbuf);

static GstStaticPadTemplate sink_factory =
    GST_STATIC_PAD_TEMPLATE("sink",
                            GST_PAD_SINK,
                            GST_PAD_ALWAYS,
                            GST_STATIC_CAPS("ANY"));

static GstStaticPadTemplate src_factory =
    GST_STATIC_PAD_TEMPLATE("src",
                            GST_PAD_SRC,
                            GST_PAD_ALWAYS,
                            GST_STATIC_CAPS("ANY"));

G_DEFINE_TYPE(GstFakeVideoFilter, gst_fake_video_filter, GST_TYPE_VIDEO_FILTER);

static void gst_fake_video_filter_class_init(GstFakeVideoFilterClass* klass) {
    GstElementClass* element_class = GST_ELEMENT_CLASS(klass);
    GstBaseTransformClass* btransform_class = GST_BASE_TRANSFORM_CLASS(klass);
    GstVideoFilterClass* vfilter_class = GST_VIDEO_FILTER_CLASS(klass);

    gst_element_class_add_pad_template(
        element_class,
        gst_static_pad_template_get(&src_factory));
    gst_element_class_add_pad_template(
        element_class,
        gst_static_pad_template_get(&sink_factory));

    gst_element_class_set_static_metadata(element_class,
                                          "Identity Plugin",
                                          "FIXME:Generic",
                                          "FIXME:Generic Element",
                                          "No Contact");

    btransform_class->start = gst_fake_video_filter_start;
    btransform_class->stop = gst_fake_video_filter_stop;
    vfilter_class->transform_frame_ip =
        gst_fake_video_filter_transform_frame_ip;
}
static void gst_fake_video_filter_init(GstFakeVideoFilter* filter) {}

static gboolean gst_fake_video_filter_start(GstBaseTransform* base) {
    // Allocate here
    return TRUE;
}

static gboolean gst_fake_video_filter_stop(GstBaseTransform* base) {
    // Cleanup here
    return TRUE;
}

static GstFlowReturn gst_fake_video_filter_transform_frame_ip(
    GstVideoFilter* base,
    GstVideoFrame* outbuf) {
    GstFakeVideoFilter* filter = GST_FAKE_VIDEO_FILTER(base);

    return GST_FLOW_OK;
}
