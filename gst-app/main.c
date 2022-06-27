#include <stdio.h>
#include <stdlib.h>

#include <gst/gst.h>
#include <unistd.h>

#define PIPELINE_LAUNCH_FAKE "videotestsrc ! queue ! fake_filter ! fakesink"
#define PIPELINE_LAUNCH_XORG "videotestsrc ! queue ! fake_filter ! xvimagesink"

static GstElement* pipeline = NULL;

int main(int argc, char** argv) {
    gst_init(&argc, &argv);

    GError* error = NULL;
    if (getenv("DISPLAY")) {
        pipeline = gst_parse_launch(PIPELINE_LAUNCH_XORG, &error);
    } else {
        pipeline = gst_parse_launch(PIPELINE_LAUNCH_FAKE, &error);
    }
    if (error != NULL) {
        printf("gst_parse_launch error: %s\n", error->message);
        return EXIT_FAILURE;
    }
    g_assert(pipeline && GST_IS_PIPELINE(pipeline));

    GstStateChangeReturn ret;
    ret = gst_element_set_state(GST_ELEMENT(pipeline), GST_STATE_PLAYING);
    g_assert(ret != GST_STATE_CHANGE_FAILURE);
    sleep(1);
    ret = gst_element_set_state(GST_ELEMENT(pipeline), GST_STATE_NULL);
    g_assert(ret != GST_STATE_CHANGE_FAILURE);

    // test shutdown
    gst_object_unref(G_OBJECT(pipeline));
    gst_deinit();
    return EXIT_SUCCESS;
}
