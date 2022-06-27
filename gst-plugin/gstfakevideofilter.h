#pragma once

#include <gst/gst.h>
#include <gst/video/gstvideofilter.h>

G_BEGIN_DECLS

GType gst_fake_video_filter_get_type();
#define GST_TYPE_FAKE_VIDEO_FILTER (gst_fake_video_filter_get_type())
G_DECLARE_FINAL_TYPE(GstFakeVideoFilter,
                     gst_fake_video_filter,
                     GST,
                     FAKE_VIDEO_FILTER,
                     GstVideoFilter);

typedef struct _GstFakeVideoFilter {
    GstVideoFilter parent;
} GstFakeVideoFilter;

G_END_DECLS
