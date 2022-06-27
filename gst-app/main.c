#include <stdio.h>
#include <stdlib.h>

#include <gst/gst.h>

#define PIPELINE_LAUNCH "fakesrc ! fake_filter ! fakesink"

static GstElement* pipeline = NULL;

int main(int argc, char** argv) {
    gst_init(&argc, &argv);

    GError* error = NULL;
    pipeline = gst_parse_launch(PIPELINE_LAUNCH, &error);
    if (error != NULL) {
        printf("gst_parse_launch error: %s\n", error->message);
        return EXIT_FAILURE;
    }
    g_assert(GST_IS_PIPELINE(pipeline));

    // test shutdown
    gst_object_unref(G_OBJECT(pipeline));
    gst_deinit();
    return EXIT_SUCCESS;
}
