#include "gstfakefilter.h"

static GstFlowReturn gst_fake_filter_chain(GstPad* pad,
                                           GstObject* parent,
                                           GstBuffer* buf);

static gboolean gst_fake_filter_sink_event(GstPad* pad,
                                           GstObject* parent,
                                           GstEvent* event);

static gboolean gst_fake_filter_src_query(GstPad* pad,
                                          GstObject* parent,
                                          GstQuery* query);

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

G_DEFINE_TYPE(GstFakeFilter, gst_fake_filter, GST_TYPE_ELEMENT);

static void gst_fake_filter_class_init(GstFakeFilterClass* klass) {
    GstElementClass* element_class = GST_ELEMENT_CLASS(klass);

    gst_element_class_set_static_metadata(
        element_class,
        "Identity Plugin",
        "FIXME:Generic",
        "FIXME:Generic Element",
        "No Contact");

    gst_element_class_add_pad_template(
        element_class,
        gst_static_pad_template_get(&src_factory));
    gst_element_class_add_pad_template(
        element_class,
        gst_static_pad_template_get(&sink_factory));
}
static void gst_fake_filter_init(GstFakeFilter* filter) {
    /* pad through which data comes in to the element */
    filter->sinkpad = gst_pad_new_from_static_template(&sink_factory, "sink");
    gst_pad_set_chain_function(filter->sinkpad, gst_fake_filter_chain);
    gst_pad_set_event_function(filter->sinkpad, gst_fake_filter_sink_event);
    gst_element_add_pad(GST_ELEMENT(filter), filter->sinkpad);

    /* pad through which data goes out of the element */
    filter->srcpad = gst_pad_new_from_static_template(&src_factory, "src");
    gst_pad_set_query_function(filter->srcpad, gst_fake_filter_src_query);
    gst_element_add_pad(GST_ELEMENT(filter), filter->srcpad);
}

static GstFlowReturn gst_fake_filter_chain(GstPad* pad,
                                           GstObject* parent,
                                           GstBuffer* buf) {
    GstFakeFilter* filter = GST_FAKE_FILTER(parent);

    g_print("Have data of size %" G_GSIZE_FORMAT " bytes!\n",
            gst_buffer_get_size(buf));

    return gst_pad_push(filter->srcpad, buf);
}

static gboolean gst_fake_filter_sink_event(GstPad* pad,
                                           GstObject* parent,
                                           GstEvent* event) {
    return gst_pad_event_default(pad, parent, event);
}

static gboolean gst_fake_filter_src_query(GstPad* pad,
                                          GstObject* parent,
                                          GstQuery* query) {
    return gst_pad_query_default(pad, parent, query);
}