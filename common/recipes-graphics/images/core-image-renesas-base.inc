# common
IMAGE_INSTALL_append = " \
	alsa-utils alsa-tools \
	libdrm-tests \
	libdrm-kms \
	bash \
"

# For GStreamer 
# need commercial plugins
def map_gst_commercial(d):
    install_list = ""
    if base_contains('LICENSE_FLAGS_WHITELIST', 'commercial', "1", "0", d) == "1":
        if base_contains('USE_GSTREAMER_0_10', '1', "1", "0", d) == "1":
            install_list += " gst-plugins-ugly gst-plugins-ugly-asf gst-openmax"
        if base_contains('USE_GSTREAMER_1_00', '1', "1", "0", d) == "1":
            install_list += " gstreamer1.0-plugins-ugly-asf gstreamer1.0-omx"
    return install_list

IMAGE_INSTALL_append = "${@map_gst_commercial(d)}"

# gstreamer 0.10 plugins
IMAGE_INSTALL_append = ' ${@base_contains("USE_GSTREAMER_0_10", "1", " \
	gst-plugins-base-videorate \
	gst-plugins-base-videotestsrc \
	gst-plugins-good \
	gst-plugins-good-video4linux2 \
	gst-plugins-good-videocrop \
	gst-plugins-bad \
	gst-plugins-bad-fbdevsink \
	gst-plugins-bad-h264parse \
	gst-plugins-bad-videoparsersbad \
	", "", d)}'

# gstreamer 1.0 plugins
IMAGE_INSTALL_append = ' ${@base_contains("USE_GSTREAMER_1_00", "1", " \
	gstreamer1.0-plugins-base-videorate \
	gstreamer1.0-plugins-base-videotestsrc \
	gstreamer1.0-plugins-base-audiotestsrc \
	gstreamer1.0-plugins-base-alsa \
	gstreamer1.0-plugins-good-autodetect \
	gstreamer1.0-plugins-good-video4linux2 \
	gstreamer1.0-plugins-good-videocrop \
	gstreamer1.0-plugins-bad-fbdevsink \
	gstreamer1.0-plugins-bad-videoparsersbad \
	", "", d)}'

# for Middle software
CHECK_OMXIL_SH_MW = "${USE_RENESAS_MW_VCP1}"
CHECK_OMXIL_SH_MW += "${USE_RENESAS_MW_VPU5}"
IMAGE_INSTALL_append_armadillo800eva = ' ${@base_contains("CHECK_OMXIL_SH_MW", "1", "omxil-sh", "", d)} \
	gst-plugins-bad-dfbvideosink \	
	v4l-utils \
	libshvio \
	libshmeram \
' 
