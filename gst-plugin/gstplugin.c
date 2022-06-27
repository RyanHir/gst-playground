#include <config.h>
#include <gst/gst.h>

#include "gstfakefilter.h"
#include "gstfakevideofilter.h"

static gboolean plugin_init(GstPlugin* plugin) {
    gst_element_register(plugin,
                         "fake_filter",
                         GST_RANK_NONE,
                         GST_TYPE_FAKE_FILTER);
    gst_element_register(plugin,
                         "fake_video_filter",
                         GST_RANK_NONE,
                         GST_TYPE_FAKE_VIDEO_FILTER);
    return TRUE;
}

GST_PLUGIN_DEFINE(GST_VERSION_MAJOR,
                  GST_VERSION_MINOR,
                  fakeplugin,
                  "Test Video Suite",
                  plugin_init,
                  GST_PACKAGE_VERSION,
                  GST_PACKAGE_LICENSE,
                  GST_PACKAGE_NAME,
                  GST_PACKAGE_ORIGIN);
