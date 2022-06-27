#pragma once

#include <gst/gst.h>

G_BEGIN_DECLS

GType gst_fake_filter_get_type();
#define GST_TYPE_FAKE_FILTER (gst_fake_filter_get_type())
G_DECLARE_FINAL_TYPE(GstFakeFilter,
                     gst_fake_filter,
                     GST,
                     FAKE_FILTER,
                     GstElement);

typedef struct _GstFakeFilter {
    GstElement element;
    GstPad* sinkpad;
    GstPad* srcpad;
} GstFakeFilter;

G_END_DECLS
